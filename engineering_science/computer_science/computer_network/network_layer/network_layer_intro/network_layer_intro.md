# Network Layer

\1. 网络层的建构思路

到了网络层, 就已经不仅仅是一个网络(如以太网)、一条链路上的通信了, 而是不同网络之间的网络互连, 这一任务由**路由器**(router)来实现.

当年的前辈们在设计网络层协议时, 曾经对网络层提供**面向连接**还是**无连接**的服务产生过争议: 我们知道, 传统的电话网络是面向连接的, 两台终端在通信之前, 必须先建立一条物理链路, 并且在通话过程中始终占有这条链路, 直到通信结束后才将其释放, 链路关闭, 同时, 面向连接的服务也保证了通信的准确性. 

但他们选择了另外一条道路, 因为传统电话网络和计算机网络不同, 电话网络的终端(即电话), 是非常简单的结构, 不具备计算能力, 但计算机网络的终端是具有智能的计算机, 具备差错处理能力, 因此我们没有必要让链路来保证传输的准确性, 而是让端系统, 即让传输层用TCP保证正确传输. 这样, 在网络层的设备(路由器)的结构就可以被简化, 大大节省了Internet的建构成本. 基于上述理由, 网络层不面向连接, 而是采取分组交换策略, **各个IP数据报独立地选择路由**. 



\2. 协议栈

**Internet protocol** is the core of network, even the core of the complete Internet. IP works with the other four protocol on network layer:

Be invoked by IP:

- **Address Resolution Protocol(ARP)**
- **Reverse Address Resolution Protocol(RARP)**

Invoke IP:

- **Internet Control Message Protocol(ICMP)**
- **Internet Group Management Protocol(IGMP)**



\3. IP的作用和虚拟IP网的概念

IP将世界上众多异构的网络联结在一起, 屏蔽了它们在网络层之下的异构性, 使它们在网络层上就好像一个单一的虚拟互联网络(internet)一样, 这个虚拟的单一网络被称为虚拟IP网. 





