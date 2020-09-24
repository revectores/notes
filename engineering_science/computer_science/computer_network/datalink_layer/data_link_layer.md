# Data Link Layer

##### Types of Channel

Two types of channel are included in data link layer: **point-to-point channel** and the **broadcast channel**, **point-to-point protocol (PPP)** and **carrier-sense multiple access/collision detection (CSMA/CD)** are designed correspondingly.

链路(link), 又称为物理链路(physical link)是一个**物理概念**, 是指从一个节点到另一个结点的, 中间**没有任何交换结点**的线路, 这样保证了一条链路仅仅联系的是两台计算机. 在实际通信过程中, 由于线路常常会发生分支、交叉, 因此两台计算机之间的通信路径一般总是由许多段连续的链路构成, 每一条链路只是通信路径的一部分.

数据链路(data link), 又称为逻辑链路(logical link)是一个**逻辑概念**, 是链路+实现链路层协议的硬件和软件, 这些硬件和软件通常被集成到**网络适配器**(俗称为**网卡**, 如拨号上网使用的**拨号适配器**, 以及通过以太网上网使用e 的**局域网适配器**等)中.



\1. 数据链路层的任务



在点对点信道中进行通信时, 概括来说数据链路层所需执行的任务分为以下三个步骤: 

①结点A的数据链路层把网络层交下来的IP数据报添加首部和尾部封装成数据链路层的协议数据单元(PDU)——**帧**.

②结点A将封装好的帧发送给结点B的数据链路层. 

③结点B的数据链路层执行检查: 若收到的帧无差错, 则从中提取出IP数据报上交给网络层, 否则丢弃这个帧. 



\2. 封装成帧(framing)

##### Framming

**Frame** - The PDU of data link layer - is constructed by the control part and the data part of a frame, the IP packet from network layer is the data part of frame, and different from the protocol of upper layer, control part contains both the head and tail. The length limit of the data is **maximum transfer unit(MTU)**, which is specified by the data link layer.

一个“理论帧”的结构

在理论帧中, 帧的首部被称为的**帧开始符**(SOH,0x01), 尾部则是**帧结束符**(EOT,0x04), 如你所见, 它们的十六进制值都已经被固定下来了. 因此一个理论帧的结构为

| **SOH**   | **DATA(IP datagram)**                                  | **EOT**   |
| --------------- | ------------------------------------------------------------ | --------------- |
| **1Byte** |  | **1Byte** |

帧的界定符是否完整可以作为判定数据传输是否有差错的标准之一. 如果一个帧的界定符不完整, SOH和EOT其中之一缺失或二者均缺失, 则该帧显然发生了一些传输错误, 应当被丢弃.

如果在帧的数据部分中出现了SOH或EOT, 为了防止定界错误则必须对其进行转义, 一般采用的转义字符是ESC(0x1B), 这种转义方法被称为**字节填充**(**字符填充**), 对数据部分中**原有的ESC则同样需要执行转义**.

值得注意的是, 这种理论结构只是一个可用模型, 实践上并没有被广泛应用在PPP帧和以太网帧的建构中, 关于以上两种帧的结构请参见后面的有关内容. 



##### Transfer Error and Checking Mechanism

传输差错可以分为比特差错和非比特差错两类. 0变成1或1变成0的差错称为**比特差错**, 传输错误的比特占传输总比特数的比率称为**误码率**(**BER**). 非比特差错分为**帧丢失**、**帧重复**、**帧失序**三类.

The error-checking mechanism used in PPP is usually [CRC](), notice that CRC can only handle the bit-error, hence PPP does not provide the reliable transport. **High-level data link control(HDLC)** is chosen in the decade when errors occur in physical channel frequently.

