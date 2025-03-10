# Transport Control Protocol: Introduction

**Transport control protocol(TCP)** is a **reliable** transport-layer protocol equipped with **traffic control** and **congestion control mechanism**.



### 1. TCP Segment

As usual, A TCP segment is constructed by header (required part + optional part) and body. Since the options are merely used nowadays, the typical TCP header length is 20 Bytes.

```
0                   1                   2                   3
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|          Source Port          |       Destination Port        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                        Sequence Number                        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Acknowledgment Number                      |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|  Data |           |U|A|P|R|S|F|                               |
| Offset| Reserved  |R|C|S|S|Y|I|            Window             |
|       |           |G|K|H|T|N|N|                               |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|           Checksum            |         Urgent Pointer        |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                    Options                    |    Padding    |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                             data                              |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
```

**Source port (16 Bytes)** and **destination port (16 Bytes)** is the transport layer - application layer multiplexing/demultiplexing mechanism. Transport layer utilize this number to determine which process it should deliver the segment.

**Sequence number (32 Bytes)** and **acknowledgement number (32 Bytes)** are designed to implement **[acknowledgement mechanism]()** - the heart of TCP, which will be introduced below.

**Data offset (4 Bytes)** (the unit is 32-bit word) is used to indicate where the body starts, i.e. this is the length of header. Since it is 4 Bytes, the theoretical maximum header length should be 60 Bytes.

**URG, ACK, PSH, RST, SYN, FIN** are flags with particular meanings, which will be treated specially by receiver.

**Window** implements **[traffic control]()** mechanism: it tells the other side how many space is free in buffer, to avoid the segment loss caused by buffer overflow.

**Checksum** is used to check whether there is bit error (undetected is possible).

If flag URG is set, **Urgent Pointer** is used to point out the offset of urgent data in body field, and which should be processed by the upper layer in a higher priority. URG is merely used in practice.

**Options** are those optional headers (merely used) and padding is used to fill the size of header into multiples of 32-bit word.



