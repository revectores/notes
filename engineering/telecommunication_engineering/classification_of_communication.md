##### # Classification of Communication

Based on whether the sender and receiver shares the same clock, the communication can be classified as

- **Asynchronous communication**. In asynchronous communication, the sender and receiver does not use the public reference clock but keep different clock (but the [Baud rate]() must keep the same). [UART]() is device for asynchronous communication. In asynchronous communication, error will accumulate as time passed, hence sync process must be applied periodicly.
- **Synchronous communication**. In synchronous communication, sender and receiver share the same clock (in one of them).

Based on the property of communication channel, the communication can be classfied as

- Simplex communication.
- Half-duplex communication.
- Full-duplex communication.


