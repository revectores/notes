# Distributed Hash Table

A **distributed hash table (DHT)** is a distributed key-value querying system. The same as all other distributed systems, a DHT characteristically emphasize properties listed such as autonomy, decentralization, Fault Tolerance, and scalability.

The key technique to build a efficient DHT is **consistent hashing**. By definition, a consistent hashing only requires $\#key/\#bucket$ keys to be remapped instead all of them, which is essential for distributed system to reduce the network traffic and improve avaliablity.

The typical topology design to implement consistent hashing is organize nodes as a (logical) circle. Each node is assigned as a hash value. When new value arrived, the hash $h$ is computed, and the node with least hash value larger than $h$ is designated to store the value. When a node failure occurs, only those keys in failure node need to be transferred to the next node in the circle. Simliar steps can be applied to newly added node.

