# Remote Procedure Calls

1. Client calls client `stub` (params on stack).
2. Stub **marshals** params to network message. Marshalling: put parameters in a form suitable for transmission over a network (serizalized).
3. Network message sent to server.
4. Receive message and sent it to server `stub`.
5. Unmarshal parameters, call server function.

The next 5 steps are symmetrical to the last 5.

The RPC is in layer 5 session layer and layer 6 presentation layer.



issues:

- Parameter passing: pass by value or reference? pointerless representation.
- Service binding.
- Transport protocol.
- Error Handling.

