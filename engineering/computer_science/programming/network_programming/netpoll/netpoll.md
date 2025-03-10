

# netpoll源码分析(1)

[netpoll](https://github.com/cloudwego/netpoll)是字节跳动自研网络库, 被作为自研RPC框架[KiteX](https://github.com/cloudwego/kitex)的网络通信层. 这里我们分模块对其代码作一简要分析. 本分析基于[cdac6f0c9014d7f8da1fb91e101969b623e89871](https://github.com/cloudwego/netpoll/tree/cdac6f0c9014d7f8da1fb91e101969b623e89871).

本篇分析其核心执行链路.



### 1. Echo Server Example

首先观测一个简单的echo server:

```go
package main

import (
	"context"
	"time"

	"github.com/cloudwego/netpoll"
)

func main() {
	network, address := "tcp", ":8080"
	listener, _ := netpoll.CreateListener(network, address)

	eventLoop, _ := netpoll.NewEventLoop(
		handle,
		netpoll.WithOnPrepare(prepare),
		netpoll.WithReadTimeout(time.Second),
	)
	eventLoop.Serve(listener)
}

var _ netpoll.OnPrepare = prepare
var _ netpoll.OnRequest = handle

func prepare(connection netpoll.Connection) context.Context {
	return context.Background()
}

func handle(ctx context.Context, connection netpoll.Connection) error {
	reader := connection.Reader()
  writer := connection.Writer()
	defer reader.Release()
	msg, _ := reader.ReadString(reader.Len())
  writer.WriteString(msg)
	writer.Flush()
	println(msg)
	return nil
}
```

初始化接口

```go
func NewEventLoop(onRequest OnRequest, ops ...Option) (EventLoop, error)
func CreateListener(network, addr string) (l Listener, err error)
```

分别用于创建一个**事件循环**(eventloop)和**监听器**(listener)对象, `listener`作为参数参与事件循环的服务启动调用. 注意这里的`listener`也可以直接用原生的`net.Listener`.

```go
func (evl *eventLoop) Serve(ln net.Listener) error
```

这里的事件循环实质就是通常理解的Server对象, 采用eventLoop的名称可以比较清晰地体现其底层epoller的本质. eventLoop对象创建时的必选参数`onRequest`用于指定处理请求的handler. 其函数签名为

```go
type OnRequest func(ctx context.Context, connection Connection) error
```

其传递一个表征网络连接的Connection对象用于读写单个连接实例, 其最重要的接口方法是通过`Reader()`和`Writer()`以暴露出底层读写操作.

```go
type Connection interface {
	net.Conn
	Reader() Reader
	Writer() Writer
	// ...
}
```

在上述echo server的例子中, 我们通过

```go
Reader.ReadString(n int) (s string, err error)
Writer.WriteString(s string) (n int, err error)
```

方法对连接执行读写.

以上, 本节介绍了一个简单的echo server的组分, 涉及构建服务器的核心对象`Eventloop`, `Listener`, 及连接管理和读写相关装置`Connection`, `Reader`, `Writer`.







### 2. `epoll_wait`循环的创建

我们已经知道, `eventLoop.Serve`方法实现了服务启动, 我们可以由此出发观测netpoll的核心调用链路. 为了能够顺利理解服务启动的过程, 我们在做一些准备工作: 2.1先讨论模块初始化, 2.2讨论netpoll中一个重要的抽象`FDOperator`.

##### 2.1 Init

在模块`init()`时, netpoll就创建了一个`pollmanager`对象管理`poll`池:

```go
func init() {
	var loops = runtime.GOMAXPROCS(0)/20 + 1
	pollmanager = &manager{}
	pollmanager.SetLoadBalance(RoundRobin)
	pollmanager.SetNumLoops(loops)

	setLoggerOutput(os.Stderr)
}
```

netpoll开发者通过实验发现单个`epoller`最高能够负载20Core, 因此在初始化时将`poll`预先设定为CoreNum/20. 但`manager.SetNumLoops`也提供了运行时动态修改`poll`的能力:

```go
// SetNumLoops will return error when set numLoops < 1
func (m *manager) SetNumLoops(numLoops int) error {
	if numLoops < 1 {
		return fmt.Errorf("set invalid numLoops[%d]", numLoops)
	}
	if numLoops < m.NumLoops {
		// if less than, close the redundant pollers
		var polls = make([]Poll, numLoops)
		for idx := 0; idx < m.NumLoops; idx++ {
			if idx < numLoops {
				polls[idx] = m.polls[idx]
			} else {
				if err := m.polls[idx].Close(); err != nil {
					logger.Printf("NETPOLL: poller close failed: %v\n", err)
				}
			}
		}
		m.NumLoops = numLoops
		m.polls = polls
		m.balance.Rebalance(m.polls)
		return nil
	}

	m.NumLoops = numLoops
	return m.Run()
}
```

注意`SetNumLoops`实际上只是设定了poll数量并创建了存储空间, 之后`manager.Run()`以:

- `openPoll()`创建实际的`poll`对象.

- `poll.Wait()`启动核心`epollWait`循环.

```go
// Run all pollers.
func (m *manager) Run() error {
	// new poll to fill delta.
	for idx := len(m.polls); idx < m.NumLoops; idx++ {
		var poll = openPoll()
		m.polls = append(m.polls, poll)
		go poll.Wait()
	}
	// LoadBalance must be set before calling Run, otherwise it will panic.
	m.balance.Rebalance(m.polls)
	return nil
}
```

`openPoll()`内部的关键行为是:

- 调用`EPOLL_CREATE`创建epoll fd.
- 为`poll`本身创建一个[eventfd](https://man7.org/linux/man-pages/man2/eventfd.2.html)并绑定到自身(此时还没有真正启动epoll循环), 从而能够响应:
  - 用户对事件循环的主动触发`poll.Trigger()`
  - poll关闭事件`poll.Close()`

`defaultPoll.Wait()`, 服务器的核心epoll循环:

```go
// Wait implements Poll.
func (p *defaultPoll) Wait() (err error) {
	// init
	var caps, msec, n = barriercap, -1, 0
	p.Reset(128, caps)
	// wait
	for {
		if n == p.size && p.size < 128*1024 {
			p.Reset(p.size<<1, caps)
		}
		n, err = EpollWait(p.fd, p.events, msec)
		if err != nil && err != syscall.EINTR {
			return err
		}
		if n <= 0 {
			msec = -1
			runtime.Gosched()
			continue
		}
		msec = 0
		if p.Handler(p.events[:n]) {
			return nil
		}
		// we can make sure that there is no op remaining if Handler finished
		p.opcache.free()
	}
}
```

该方法为了性能做了一些不太容易理解超时设定工作(在之后的分析中再详细讨论), 不过核心在于`EpollWait()`和并且在有可用事件时执行`p.Handler()`来对具体事件作出响应.

因此, 真正意义上的epoll循环(reactor)早在`init`阶段(`import netpoll`)就已经执行完毕了, 而实际的`eventLoop.Serve`方法,  则只不过是将Listener的文件描述符绑定到某一个poll的过程.





##### 2.2 FDOpeartor

`FDOperator`(file descriptor operator)抽象了netpoll中的`Server`, `Connection`, 甚至`Poll`对象本身的文件描述符管理, 三者均通过FDOpeartor建立FD和poll之间的关联.

```go
// FDOperator is a collection of operations on file descriptors.
type FDOperator struct {
	FD int
  poll Poll
  // ...
}

```

FDOperator最重要的方法`Control`将指定的poll事件`PollEvent`绑定到poll

```go
func (op *FDOperator) Control(event PollEvent) error {
	return op.poll.Control(op, event)
}
```

最终调用的绑定过程即`syscall.SYS_EPOLL_CTL`:

```go
// Control implements Poll.
func (p *defaultPoll) Control(operator *FDOperator, event PollEvent) error {
	var op int
	var evt epollevent
	p.setOperator(unsafe.Pointer(&evt.data), operator)
	switch event {
	case PollReadable: // server accept a new connection and wait read
		operator.inuse()
		op, evt.events = syscall.EPOLL_CTL_ADD, syscall.EPOLLIN|syscall.EPOLLRDHUP|syscall.EPOLLERR
	case PollWritable: // client create a new connection and wait connect finished
		operator.inuse()
		op, evt.events = syscall.EPOLL_CTL_ADD, EPOLLET|syscall.EPOLLOUT|syscall.EPOLLRDHUP|syscall.EPOLLERR
	}
	return EpollCtl(p.fd, op, operator.FD, &evt)
}
```

```go
// EpollCtl implements epoll_ctl.
func EpollCtl(epfd int, op int, fd int, event *epollevent) (err error) {
	_, _, err = syscall.RawSyscall6(syscall.SYS_EPOLL_CTL, uintptr(epfd), uintptr(op), uintptr(fd), uintptr(unsafe.Pointer(event)), 0, 0)
	if err == syscall.Errno(0) {
		err = nil
	}
	return err
}
```







### 3.新建连接事件的监听和响应

##### 3.1 `eventLoop.Serve`

`Serve`中通过`newServer`创建一个`Server`对象存储Listener和用户指定的options:

```go
// Serve implements EventLoop.
func (evl *eventLoop) Serve(ln net.Listener) error {
	npln, err := ConvertListener(ln)
	if err != nil {
		return err
	}
	evl.Lock()
	evl.svr = newServer(npln, evl.opts, evl.quit)
	evl.svr.Run()
	evl.Unlock()

	err = evl.waitQuit()
	// ensure evl will not be finalized until Serve returns
	runtime.SetFinalizer(evl, nil)
	return err
}
```

`Server`随即`Run()`启动——本质上是调用`pollmanager.Pick()`方法绑定到一个`poll`上, 并通过FDOperator.Control为Listener对应的文件描述符绑定Readable事件监听.

```go
// Run this server.
func (s *server) Run() (err error) {
	s.operator = FDOperator{
		FD:     s.ln.Fd(),
		OnRead: s.OnRead,
		OnHup:  s.OnHup,
	}
	s.operator.poll = pollmanager.Pick()
	err = s.operator.Control(PollReadable)
	if err != nil {
		s.onQuit(err)
	}
	return err
}
```

新连接建立事件所对应的handler分支为

```go
// for non-connection
operator.OnRead(p)
```

其中创建了一个新的`connection`对象

```go
func (s *server) OnRead(p Poll) error {
	// accept socket
	conn, err := s.ln.Accept()
	if err != nil {
		// shut down
		if strings.Contains(err.Error(), "closed") {
			s.operator.Control(PollDetach)
			s.onQuit(err)
			return err
		}
		logger.Println("NETPOLL: accept conn failed:", err.Error())
		return err
	}
	if conn == nil {
		return nil
	}
	// store & register connection
	var connection = &connection{}
	connection.init(conn.(Conn), s.opts)
	if !connection.IsActive() {
		return nil
	}
	var fd = conn.(Conn).Fd()
	connection.AddCloseCallback(func(connection Connection) error {
		s.connections.Delete(fd)
		return nil
	})
	s.connections.Store(fd, connection)

	// trigger onConnect asynchronously
	connection.onConnect()
	return nil
}

```

其中的关键调用是通过`connection.init()`初始化连接对象, 并以监听该连接上发生的读写事件(见下节).







### 4. 连接读写事件的监听和响应

`connection.init()`时, 初始化FDOperator, 并通过`connection.onPrepare()`触发`connection.register()`:

```go
// init initialize the connection with options
func (c *connection) init(conn Conn, opts *options) (err error) {
	// init buffer, barrier, finalizer
	c.readTrigger = make(chan struct{}, 1)
	c.writeTrigger = make(chan error, 1)
	c.bookSize, c.maxSize = block1k/2, pagesize
	c.inputBuffer, c.outputBuffer = NewLinkBuffer(pagesize), NewLinkBuffer()
	c.inputBarrier, c.outputBarrier = barrierPool.Get().(*barrier), barrierPool.Get().(*barrier)

	c.initNetFD(conn) // conn must be *netFD{}
	c.initFDOperator()
	c.initFinalizer()

	syscall.SetNonblock(c.fd, true)
	// enable TCP_NODELAY by default
	switch c.network {
	case "tcp", "tcp4", "tcp6":
		setTCPNoDelay(c.fd, true)
	}
	// check zero-copy
	if setZeroCopy(c.fd) == nil && setBlockZeroCopySend(c.fd, defaultZeroCopyTimeoutSec, 0) == nil {
		c.supportZeroCopy = true
	}

	// connection initialized and prepare options
	return c.onPrepare(opts)
}
```

在`connection.register()`中则最终进行了连接对应文件描述符的事件绑定:

```go
// register only use for connection register into poll.
func (c *connection) register() (err error) {
	if c.operator.isUnused() {
		// operator is not registered
		err = c.operator.Control(PollReadable)
	} else {
		// operator is already registered
		// change event to wait read new data
		err = c.operator.Control(PollModReadable)
	}
	if err != nil {
		logger.Printf("NETPOLL: connection register failed: %v", err)
		c.Close()
		return Exception(ErrConnClosed, err.Error())
	}
	return nil
}

```

连接读写事件所对应的handler分支为

```go
// for connection
var bs = operator.Inputs(p.barriers[i].bs)
if len(bs) > 0 {
  var n, err = ioread(operator.FD, bs, p.barriers[i].ivs)
  operator.InputAck(n)
  if err != nil {
    p.appendHup(operator)
    continue
  }
}
```

- `operator.Input`方法为读缓冲区分配内存.
- `ioread`底层调用`SYS_READV`进行实际的读操作.
- `operator.InputAck`确认读操作完成以释放缓冲区.

写事件也是类似的过程:

```go
// for connection
var bs, supportZeroCopy = operator.Outputs(p.barriers[i].bs)
if len(bs) > 0 {
  // TODO: Let the upper layer pass in whether to use ZeroCopy.
  var n, err = iosend(operator.FD, bs, p.barriers[i].ivs, false && supportZeroCopy)
  operator.OutputAck(n)
  if err != nil {
    p.appendHup(operator)
    continue
  }
}
```

至此我们完成了对netpoll整体核心调用链路的一个跟踪.