# BladeCDC - An Introduction

> Notes: To focus on the primary architecture, most codes referred in this document is simplied by removing irrelevant parts and nonsignificant error handling/logging codes. Do a global definition search yourself for the complete implementation of those referred functions.



### 1. Architecture

A CDC cluster are constructed by multiple `server`, each has a bound `capture`. An specical `capture` called `owner` will be elected at set intervals to be the manager among `capture`.

- A `changefeed` is decomposed into multiple `task`s and dispatched by the `owner` into different `capture` by the `owner`.
- A `capture` is contructed by multiple `processors`, for each processor a `task` can be assigned to it then it will pull binlog from BladeKV servers based on the task content.

The granularity of dispatching is **physical table** (that is, is each **partition** if the table is a partition table). That is, the synchronization task of a table (theorectically whether it is partitioned is transparent to user) may be dispatched into multiple `capture`, while the physical table must not be divided.







### 2. Server

##### # `ServerCmd`

BladeCDC server starts by executing `server` command of program `cdc` (`kubectl describe` to confirm):

```shell
/bin/sh -c /cdc server --addr=0.0.0.0:8301 --advertise-addr=${POD_NAME}.${HEADLESS_SERVICE_NAME}.${NAMESPACE}.svc:8301 --gc-ttl=86400 --log-file=/dev/stderr --log-level=info --pd=http://inf-blade-cdctest-pd:2379
```

if you are curious about the default environment variables:

```shell
POD_NAME:               inf-blade-cdctest-ticdc-0 (v1:metadata.name)
NAMESPACE:              binlog (v1:metadata.namespace)
HEADLESS_SERVICE_NAME:  inf-blade-cdctest-ticdc-peer
```

The command line interface is implemented based on `cobra`. Function `runEServer` is assigned to command `server`.

```go
serverCmd = &cobra.Command{
  Use:   "server",
  Short: "Start a TiCDC capture server",
  RunE:  runEServer,
}
```

`runEServer` are mainly constructed by `NewServer`, `Server.Run` and `Server.Close`, which initialize, run and close the server respectively:

```go
func runEServer(cmd *cobra.Command, args []string) error {
	server, err := cdc.NewServer(opts...)
	err = server.Run(defaultContext)
	server.Close()
  return nil
}
```

Options configured in command line interface given by user will be packed as `opts` and used to initialize CDC server.



##### # `Server.Run` and `Server.run`

In `Server.Run`, we create pd clients and starts the HTTP server to handle HTTP requests to CDC's HTTP interface. Then a self-recovered `Server.run` loop is started.

```go
func (s *Server) Run(ctx context.Context) error {
	s.pdEndpoints = strings.Split(s.opts.pdEndpoints, ",")
	pdClient, err := pd.NewClient(s.pdEndpoints, s.opts.credential.PDSecurityOption())
	s.pdClient = pdClient
	s.startStatusHTTP()

	for {
		if err := s.run(ctx); cerror.ErrCaptureSuicide.NotEqual(err) {
			return err
		}
	}
}
```

`Server.run` do the following works:

- Register some information into context:
  - Server's advertise address, since in current architecture only one `capture` is bound to one `server`, that is the bound capture's advertise address.
  - Time zone info.
  - KvStore client.
- Creates a capture and bound it to current server.
- Starts two go routines:
  - `campaignOwnerLoop` for trying to be an owner, an unique special capture which hanldes task management among all the captures. Refer to [Owner](Owner) for details.
  - `capture.Run` for runing the capture main working loop.

```go
func (s *Server) run(ctx context.Context) (err error) {
   ctx = util.PutCaptureAddrInCtx(ctx, s.opts.advertiseAddr)
   ctx = util.PutTimezoneInCtx(ctx, s.opts.timezone)
   kvStore, err := kv.CreateTiStore(strings.Join(s.pdEndpoints, ","), s.opts.credential)
   defer func() {
      err := kvStore.Close()
   }()
   ctx = util.PutKVStorageInCtx(ctx, kvStore)

   procOpts := &processorOpts{flushCheckpointInterval: s.opts.processorFlushInterval}
   capture, err := NewCapture(ctx, s.pdEndpoints, s.opts.credential, s.opts.advertiseAddr, procOpts)

   s.capture = capture
   ctx, cancel := context.WithCancel(ctx)
   defer cancel()

   wg, cctx := errgroup.WithContext(ctx)

   wg.Go(func() error {
      return s.campaignOwnerLoop(cctx)
   })

   wg.Go(func() error {
      return s.capture.Run(cctx)
   })

   return wg.Wait()
}
```







### 3. Capture

A `capture` watches its task list stored in etcd and handle it in `Capture.handleTaskEvent`. Refer to [`TaskWatcher`]() for details of task watcher.

```go
func (c *Capture) Run(ctx context.Context) (err error) {
	taskWatcher := NewTaskWatcher(c, &TaskWatcherConfig{
		Prefix:      kv.TaskStatusKeyPrefix + "/" + c.info.ID,
		ChannelSize: 128,
	})
	var ev *TaskEvent
	wch := taskWatcher.Watch(ctx)
	for {
		select {
		case ev = <-wch:
			if ev == nil {
				return nil
			}
			if ev.Err != nil {
				return errors.Trace(ev.Err)
			}
			if err := c.handleTaskEvent(ctx, ev); err != nil {
				return errors.Trace(err)
			}
		}
	}
}
```

`Capture.handleTaskEvent` translates task event to modifications to `processors`. The task event can be `TaskOpCreate` or `TaskOpDelete`.

- For `TaskOpCreate` We create a new processor to bind the new task, if the task hasn't be registered in `Capture.processors`.
- For `TaskOpDelete` we run `Processor.Stop` and then delete it ffrom `Capture.processors`.

```go
func (c *Capture) handleTaskEvent(ctx context.Context, ev *TaskEvent) error {
	task := ev.Task
	if ev.Op == TaskOpCreate {
		if _, ok := c.processors[task.ChangeFeedID]; !ok {
			p, err := c.assignTask(ctx, task)
			if err != nil {
				return err
			}
			c.processors[task.ChangeFeedID] = p
		}
	} else if ev.Op == TaskOpDelete {
		if p, ok := c.processors[task.ChangeFeedID]; ok {
			if err := p.stop(ctx); err != nil {
				return errors.Trace(err)
			}
			delete(c.processors, task.ChangeFeedID)
		}
	}
	return nil
}
```







### 4. TaskWatcher

`TaskWatcher.Watch` is a wrapper of `TaskWatcher.watch`.

```go
func (w *TaskWatcher) Watch(ctx context.Context) <-chan *TaskEvent {
	c := make(chan *TaskEvent, w.cfg.ChannelSize)
	go w.watch(ctx, c)
	return c
}
```

`TaskWatcher.watch` gets and watches the capture id for events updates of current capture:

```go
func (w *TaskWatcher) watch(ctx context.Context, c chan *TaskEvent) {
	etcd := w.capture.etcdClient.Client

	send := func(ctx context.Context, ev *TaskEvent) error {
		select {
		case <-ctx.Done():
			close(c)
			return ctx.Err()
		case c <- ev:
		}
		return nil
	}
restart:
	// Load all the existed tasks
	events := make(map[string]*TaskEvent)
	resp, err := etcd.Get(ctx, w.cfg.Prefix, clientv3.WithPrefix())

	for _, kv := range resp.Kvs {
		ev, err := w.parseTaskEvent(ctx, kv.Key, kv.Value)
		events[ev.Task.ChangeFeedID] = ev
	}

	wch := etcd.Watch(ctx, w.cfg.Prefix,
		clientv3.WithPrefix(),
		clientv3.WithPrevKV(),
		clientv3.WithRev(resp.Header.Revision+1))
	for wresp := range wch {
		err := wresp.Err()
		if err != nil {
			goto restart
		}
		for _, ev := range wresp.Events {
			if ev.Type == clientv3.EventTypePut {
				ev, err := w.parseTaskEvent(ctx, ev.Kv.Key, ev.Kv.Value)
				w.events[ev.Task.ChangeFeedID] = ev
				send(ctx, ev);
			} else if ev.Type == clientv3.EventTypeDelete {
				task, err := w.parseTask(ctx, ev.PrevKv.Key, ev.PrevKv.Value)
				delete(w.events, task.ChangeFeedID)
				send(ctx, &TaskEvent{Op: TaskOpDelete, Task: task});
			}
		}
	}
	close(c)
}
```

where `parseTaskEvent` translates `AdminJob` to `TaskOp`:

```go
func (w *TaskWatcher) parseTaskEvent(ctx context.Context, key, val []byte) (*TaskEvent, error) {
	task, err := w.parseTask(ctx, key, val)
	taskStatus := &model.TaskStatus{}
	taskStatus.Unmarshal(val);
  
	var op TaskEventOp
	switch taskStatus.AdminJobType {
	case model.AdminNone, model.AdminResume:
		op = TaskOpCreate
	case model.AdminStop, model.AdminRemove, model.AdminFinish:
		op = TaskOpDelete
	}
	return &TaskEvent{Op: op, Task: task}, nil
}
```







### 5. Owner

##### # Owner Campaign

A capture continues to try to be an owner by invoking `Capture.Campaign` until it does (otherwise it blocks if it fails in this period). The owner will `Resign` voluntarily after `ownerRunInterval`(by default it's 500ms) hence owner may swap frequently among captures.

```go
func (s *Server) campaignOwnerLoop(ctx context.Context) error {
	// In most failure cases, we don't return error directly, just run another
	// campaign loop. We treat campaign loop as a special background routine.

	rl := rate.NewLimiter(0.05, 2)
	for {
		rl.Wait(ctx)

		// Campaign to be an owner, it blocks until it becomes the owner
		if err := s.capture.Campaign(ctx); err != nil {
			switch errors.Cause(err) {
			case context.Canceled:
				return nil
			case mvcc.ErrCompacted:
				continue
			}
			continue
		}
    
		NewOwner(ctx, s.pdClient, s.opts.credential, s.capture.session, s.opts.gcTTL, s.opts.ownerFlushInterval)
		s.setOwner(owner)
		owner.Run(ctx, ownerRunInterval)
		s.capture.Resign(ctx)
		s.setOwner(nil)
	}
}
```

`Capture.Campaign` is a wrapper of `Campaign` method of `Capture.election *concurrency.Election`, which is implemented by etcd.

```go
func (c *Capture) Campaign(ctx context.Context) error {
	return cerror.WrapError(cerror.ErrCaptureCampaignOwner, c.election.Campaign(ctx, c.info.ID))
}
```

The information of owner will be put into etcd so other captures can be aware of the unique owner.







##### # Owner Working Loop

Once the capture campaign to be owner successfully it will run the owner main loop:

```go
func (o *Owner) run(ctx context.Context) error {
	o.l.Lock()
	defer o.l.Unlock()

	o.loadChangeFeeds(ctx)
	o.balanceTables(ctx)
  o.calcResolvedTs(ctx)
	o.handleDDL(ctx)
	o.handleSyncPoint(ctx)
  o.handleAdminJob(ctx)
	o.flushChangeFeedInfos(ctx)
	o.checkClusterHealth(ctx)
}
```

Eight methods are executed sequentially:

- `Owner.loadChangeFeeds` retrieves all the changefeeds and update the local copy `Owner.changeFeeds map[model.ChangeFeedID]*changeFeed`. It updates the changefeed if it already exists (this part is simple) otherwise creates a new one (this is complex since multiple corner cases must be properly handled during changefeed creation, the codes shown below are simplified).

  ```go
  func (o *Owner) loadChangeFeeds(ctx context.Context) error {
  	_, details, err := o.cfRWriter.GetChangeFeeds(ctx)
  
  	for changeFeedID, cfInfoRawValue := range details {
  		taskStatus, err    := o.cfRWriter.GetAllTaskStatus(ctx, changeFeedID)
  		taskPositions, err := o.cfRWriter.GetAllTaskPositions(ctx, changeFeedID)
  
  		if cf, exist := o.changeFeeds[changeFeedID]; exist {
  			cf.updateProcessorInfos(taskStatus, taskPositions)
        continue
  		}
  
  		// we find a new changefeed, init changefeed here.
  		cfInfo := &model.ChangeFeedInfo{}
  		cfInfo.Unmarshal(cfInfoRawValue.Value)
  		cfInfo.VerifyAndFix()
      
  		status, _, err := o.cfRWriter.GetChangeFeedStatus(ctx, changeFeedID)
  		checkpointTs := cfInfo.GetCheckpointTs(status)
  
  		newCf, err := o.newChangeFeed(ctx, changeFeedID, taskStatus, taskPositions, cfInfo, checkpointTs)
  		o.changeFeeds[changeFeedID] = newCf
  		delete(o.stoppedFeeds, changeFeedID)
  	}
  	return nil
  }
  ```

  If the state of changefeed is set to `Stopped` at the beginning, the changefeed will be 

- `Owner.balanceTables` 



