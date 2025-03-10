gRPC

> Notes: To focus on the primary architecture, most codes are simplified by removing irrelevant parts and nonsignificant error handling/logging codes. Do a global definition search yourself for the complete implementation of those referred functions.

A `steam.Send` call is a wapper of `***serverStream.SendMsg***`, where `prepareMsg` and `ServerTransport.Write` are called sequentically:

```
func (ss *serverStream) SendMsg(m interface{}) (err error) {
	hdr, payload, data, err := prepareMsg(m, ss.codec, ss.cp, ss.comp)
	ss.t.Write(ss.s, hdr, payload, &transport.Options{Last: false})
}
```

Interface `ServerTransport` is the server-side transport implementation. There are two implementations provided in gRPC:

- http2Server. Implement HTTP/2. This is the implementation chosen when use `Serve` to create gRPC service.
- serverHandlerTransport. Use net/http.Handler interface.

```go
func (t *http2Server) Write(s *Stream, hdr []byte, data []byte, opts *Options) error {
	data = data[emptyLen:]
	df := &dataFrame{
		streamID:    s.id,
		h:           hdr,
		d:           data,
		onEachWrite: t.setResetPingStrikes,
	}
	s.wq.get(int32(len(hdr) + len(data)))
	return t.controlBuf.put(df)
}
```

Here the essential part is `t.controlBuf.put(df)`, a wrapper of `controlBuffer.executeAndPut`:

```go
func (c *controlBuffer) put(it cbItem) error {
	_, err := c.executeAndPut(nil, it)
	return err
}
```

`executeAndPut` Enqueues `it` to controlBuffer double linked list and send the signal to channel to wake up the `controlBuffer.get` loop.

```go
func (c *controlBuffer) executeAndPut(f func(it interface{}) bool, it cbItem) (bool, error) {
	var wakeUp bool
	c.mu.Lock()
	if c.err != nil {
		c.mu.Unlock()
		return false, c.err
	}
	if f != nil {
		if !f(it) { // f wasn't successful
			c.mu.Unlock()
			return false, nil
		}
	}
	if c.consumerWaiting {
		wakeUp = true
		c.consumerWaiting = false
	}
	c.list.enqueue(it)
	c.mu.Unlock()
	if wakeUp {
		select {
		case c.ch <- struct{}{}:
		default:
		}
	}
	return true, nil
}
```

controlBuffer.get

```go
func (c *controlBuffer) get(block bool) (interface{}, error) {
	for {
		c.mu.Lock()
		if c.err != nil {
			c.mu.Unlock()
			return nil, c.err
		}
		if !c.list.isEmpty() {
			h := c.list.dequeue().(cbItem)
			if h.isTransportResponseFrame() {
				if c.transportResponseFrames == maxQueuedTransportResponseFrames {
					// We are removing the frame that put us over the
					// threshold; close and clear the throttling channel.
					ch := c.trfChan.Load().(*chan struct{})
					close(*ch)
					c.trfChan.Store((*chan struct{})(nil))
				}
				c.transportResponseFrames--
			}
			c.mu.Unlock()
			return h, nil
		}
		if !block {
			c.mu.Unlock()
			return nil, nil
		}
		c.consumerWaiting = true
		c.mu.Unlock()
		select {
		case <-c.ch:
		case <-c.done:
			c.finish()
			return nil, ErrConnClosing
		}
	}
}
```