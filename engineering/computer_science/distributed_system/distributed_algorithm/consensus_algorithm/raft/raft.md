# Raft

[Raft]() is an understandability-oriented consensus algorithm. It states that it is equivalent to [Paxos]() in fault-tolerance and performance.




## Protocol Overview

As many other consensus protocols, Raft models distributed system using [replicated state machine](). In short, we send inputs(logs) among state machines to keep them identical since a group of replicated machines given the same initial state and inputs(logs) will always produce the same output.

There are three roles in Raft: **leader**, **candidate** and **follower**. Raft is designed to have unique leader in each **term** (though this restriction might be disobeyed in specical cases without affecting correctness) who processes all the requests from clients (if some requests arrived at followers it will be transferred to the leader).

When received a request, leader will send log of corresponding operation to all followers then waits for response. One log is **committed** once the leader has been aware that a majority of the nodes (includes the leader itself) append the log to local logs. Once the log is committed, the leader start to apply it to local state machine and send request to permit the same operation can be executed by all followers.





