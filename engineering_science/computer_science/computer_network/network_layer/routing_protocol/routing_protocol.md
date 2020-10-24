# Routing Protocol

### Autonomous System

We've knwon that the router maintains a [routing table](), which stores the mapping from the target network to the next address. While when amounts of networks are connected to Internet, the routing table will be unacceptable large if each router has to maintain all the mapping information, even worse, the information interchange among routers will occupy all the bandwidth.[1]

To solve this problem, we devide the Internet into amounts of **autonomous system(AS)**, each AS will act as whole, the routing inside AS is decided by the AS itself. The routing inside the AS called **intradomain routing**, the protocol is **interior gateway protocol(IGP)**, and the routing between AS called **interdomain routing**, the protocol is **external gateway protocol(EGP)**. The interdomain routing is taken by the special routers, called **area border router(ABR)**.

Notice that, since the terminology "router" has not been proposed the early RFC, the routing protocol is named as "[gateway]() protocol", which works upper the fourth level. Some materials convert IGP and EGP as "IRP" and "ERP".

The common IGP are **router information protocol(RIP)** and **open shortest path first(OSPF)**. The common EGP is **Border Gateway Protocol(BGP)**. The earliest EGP also called EGP, but has been abandoned now.

Now we'll illustrate RIP, OSPF, BGP respectively.



### Router Information Protocol





### Open Shortest Path First





### Border Gateway Protocol


