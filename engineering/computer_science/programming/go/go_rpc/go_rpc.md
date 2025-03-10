# Go RPC

The method must look schematically like

```go
func (t *T) MethodName(argType T1, replyType *T2) error
```

where the `T1` and `T2` can be marshaled by `encoding/gob`. Notice that these requirements apply even if a different codec is used.

The method's first argument represents the argument provided by the caller, and the second argument represents the result parameters to be returned parameters to be returned to the caller.



```go
package server

import "errors"

type Args struct {
    A, B int
}

type Quotient struct {
    Que, Rem int
}

type Arith int

func (t *Arith) Multiply(args *Args, reply *int) error {
    *reply = args.A * args.B
    return nil
}

func (t *Arith) Divide(args *Args, quo *Qutient) error {
    if args.B == 0 {
        return errors.New("divide by zero")
    }
    quo.Quo = args.A / args.B
    quo.Rem = args.A % args.B
    return nil
}
```

The server calls:

```go
arith := new(Arith)
rpc.Register(arith)
rpc.HandleHTTP()
l, e := net.Listen("tcp", ":1234")
if e != nil {
    log.Fatal("listen error:", e)
}
go http.Serve(l, nil)
```

At this point, clients can see a service "Arith" with methods "Arith.Multiply" and "Arith.Divide". To invoke one, a client first dials the server:

```go
client, 
```























