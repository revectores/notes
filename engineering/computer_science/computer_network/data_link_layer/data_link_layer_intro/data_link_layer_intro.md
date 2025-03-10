# Data Link Layer

### 1. Basic Concepts

##### # Responsibility

As the sender in trasmission, data link layer receive the package from [network layer](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/computer_network/network_layer/network_layer_intro/network_layer_intro.md) and framming it than pass it into the [physical layer](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/computer_network/physical_layer/physical_layer.md). As the receiver in transmission, data link layer receive the physical signals froms physical layer and pass it into network layer.



##### # Terminology: Physical Link and Logical Link

**Link** or **physical link** is a physical concept referring wireline that connects two device directly. The communication link between two far away devides usually contains multiple continous physical links. **Logical link** or **data link** is a logic concept, its the combination of physical link and the protocols with its hardware and software implementation. Those hardware and software are usually integreted into the **network adaptor**.



##### # Types of Channel

There are two kinds of channel in data link layer: **point-to-point channel** and the **broadcast channel**. The protocols **Point-to-point protocol (PPP)** and **Carrier-sense multiple access/collision detection (CSMA/CD)** are designed for the communication in the two types of channel correspondingly.



##### # Framming

**Frame** - The PDU of data link layer - is constructed by the control part and the data part of a frame, the IP packet from network layer is the data part of frame, and different from the protocol of upper layer, control part contains both the head and tail. The length limit of the data is **maximum transfer unit(MTU)**, which is specified by the data link layer.



##### # Transfer Error and Checking Mechanism

The error-checking mechanism used in PPP is usually [Cyclic Redundancy Check](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/computer_network/error_detection/cyclic_redundancy_check/cyclic_redundancy_check.md), notice that CRC can only handle the bit-error, hence PPP does not provide the reliable transport. **High-level data link control(HDLC)** is chosen in the decade when errors occur in physical channel frequently.

