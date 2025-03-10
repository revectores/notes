# Blade Introduction

> Notes: The primary reference of this document [1] is last updated on 2019-04-01, some contents may be out of date and require more supportive material for confirmation.



### 1. Motivation

We absolutely need a distributed SQL database in the 2020s, with high performance, scalability, and storage consistency. Luckily, we have TiDB since 2017, while there are multiple performance defects due to its architecture:

1. **Optimistic concurrency control**, which leads to severe performance instability when the transaction competition is heavy. Refer to [TiDB Optimistic Transaction Model](https://docs.pingcap.com/tidb/stable/optimistic-transaction) for the details of TiDB's OCC.

2. **Version number-based MVCC management**.

    - Each data modification writes the entire row into LSM-Tree, and the row lock is stored in independent LSM-Tree. Sequential read performance is severely impacted by this design.
    - The garbage collection of historical versions wastes system resources (IO, memory, etc.).
    - The percolator-based transaction model leads to bad performance.
    - MVCC mechanism cannot utilize the advantage of hosts with large memory.

3. **Storage layer writes amplification**. RocksDB is used to store both redo log and data, the write amplification is doubled (compared to primitive LSM-tree).

4. **Problems associated with LSM-Tree**: Compaction leads to the latency jitter.

5. **Lack of physical region isolation**. We have to tag each row as deleted when deleting the database or index, which leads to extra IO and CPU cost. ==TODO: What if we have physical region isolation?==

6. **Lack of operator pushdown**. Simple insert/update operation on one row or a small range is not pushed down to the storage level, which increases the communication costs and concurrency conflicts window.

7. **The complexity of CDC architecture**. TiDB generates CDC data in the computation layer, which leads to a dilemma between consistency and availability. ==TODO: why?==







### 2. Architecture

Since Blade aims to be compatible with TiDB, the main components are also similar:

|               Responsibility                | Blade Component | TiDB Equivalent |
| :-----------------------------------------: | :-------------: | :-------------: |
|        distributed key-value storage        |   `blade-kv`    |     `tikv`      |
| SQL parsing, distributed execution plan gen |   `blade-sql`   |  `tidb-server`  |
|              region placement               |  `blade-root`   |      `pd`       |

In addition, there are some supportive components:

- `blade-test`: The integration test tool.
- `blade-random`:  long-term test tool.

At the storage level Blade also divides key space into multiple regions, each of them is the unit of duplication, and all the replicas construct a Raft group.

Refer to [TiDB Architecture](https://docs.pingcap.com/tidb/stable/tidb-architecture) for more details about the responsibility of each component in TiDB-similar database design.

Now the improvements that are introduced (or will be introduced? ==TODO: Code review and document research required!)== by Blade:

- Use coroutine framework: Reduce performance impaction caused by multi-threads and simplify development.
- Use **pessimistic concurrency control** transaction model. Support ANSI isolation levels. ==TODO: What are ANSI isolation levels?==
- Develop MVCC transaction engine: Improve performance and reduce garbage collection costs.
- Develop SSTable storage engine: Reduce compaction influence.
- Develop distributed transaction protocol: Reduce the consensus cost, support self-recover.
- Develop integration test tool `blade-test` and long-term test tool `blade-random`.







### 3. MVCC

##### # `MemTable`

Instead of writing the entire row even if we only update one column (motivation-2), we only save the updated column data to `memTable`, and the updated columns are maintained as a reversed linked list.

Instead of saving the row lock in independent LSM-Tree, we maintain row lock inside the row header. ==TODO: Where, and how the row encoding modified, specificially?==

For amounts of application scenarios we actually do not need ancient snapshots. To avoid the performance impaction casued by too many versions (motivation-2), in Blade instead of saving all the versions (which are still alive) to external storage, the multi-verison key will only be maintained in `memtable`, and **drop all the historial versions when compaction**, that is, the [key-version] is unique and is most updated in external storage.

To avoid accessing to external disk frequently and dropping versions too early under this design, we configure the size of `memTable` to `10M ~ 100G` based on the business requirements (the ideal circumstance is all the data operations are in-memory), which utilizes the ability of large memory (motivation-2).



##### # Transaction Context

We maintain the transaction context inside `Blade-KV`. We writes data to `MemTable` during transaction, the commit operation is simplified to push the transaction version to `MemTable` ==TODO: This requires further clearification==. If the transaction is rolled back, the uncommited data is removed from the linked-list (remember the column data updating is maintained in the reversed linked-list?).



##### # Write-ahead Logging

WAL synchronization is maintained by [mraft](https://km.sankuai.com/page/351822654), which is a improved Raft implementation based on [braft](https://github.com/baidu/braft).

Braft learner subscribes to WAL and exports CDC data.







### 4. LSM-Tree Engine

The traditional LSM-Tree maintains multiple levels of `sstable` (for instance, the default level number of leveldb is 7 up to 2021-07-08), instead, in Blade, **we only maintain level-0 and level-1**, and in specific circumstances the `imm` table can directly compact with level-0 without compacted to level-0 `sstable` (==TODO: similar "jumping" rule is also designed in leveldb, and the default max level to jump is 2, is there other differences in Blade's "jumping" rule?==).

Level-1 is configured as **2MB** (configurable) `sstable` (this is the same as leveldb's configuration), and only those `sstable` overlapped with the compacted one (`imm` table or level-0 `sstable`) are compacted.

We **delay the file deletion** after compaction of level-1, **moving the traffic from the old level-1 to new level-1 increasingly**.







### 5. Refined Two Phase Commit

==TODO==







### 6. Infrastructure

1. **Refined memory management**. We manage most of the memory by Blade-KV ourselves. Arena, object pool, various-length memory allocator, thread-local storage are supported. Optimization requires recoding: In addition we construct data structure level memory usage counting.

2. **Lock-free data structures for high concurrency**:  LRU-Cache, fixed-length queue, objects pool, coroutine scheduler, etc.

3. **Coroutine scheduler**: Synchronized programming model. Use coroutine scheduler to do blocked operations including lock waiting, semaphore waiting, Raft synchronization, and local I/O. The number of threads can be reduced to number of CPU core to reduce the cost of thread scheduling and context switching.







### 7. Testing Mechanism

We construct component-oriented test & integration test framework `blade-test` and long-term test framework `blade-random`.

For `blade-test`, we have components below:

- Stress testing on MVCC, `memtable`, `sstable`.
- Stress testing on `mraft`, `LRU Cach`.
- Multiple compaction test in extreme environemnts: Region split & movement, leader & follower switching.
- `blade-sql` fault-tolerant when the KV layer throws errors.

`blade-random` tests are executed based on k8s in Cloud Native environment. We have components below:

- Stress testing `RowCheck`: Validating row & table & transaction correctness.
- Stress testing on DDL (schema switching) during continous read/write.
- `OnDup`: Simple transaction validating and "mild" continous read/write stress test.







### 8. Further Improvements

Maintainability:

- Stoage-level based CDC export (motivation-7). Point-in-time recovery supporting based on heterogeneous backup.
- Online by-path data impor & export.
- Real parallel indexing based on mapReduce shuffle-like workflow.
- Make parameter configuration, metadata query and cluster status query internal table operation.

Performance improvements:

- Reduce performance impaction caused by compaction.
- Distributed deadlock detection.
- One-RPC cost distributed commit protocol.
- Lock-free B+Tree `memtable`. ==TODO: Why not skiplist?==

Long-term research:

- AEP-adapted LSM-Tree based storage engine.







### References

[1] [1.0 Blade核心规划与总体设计](https://km.sankuai.com/page/133577704)

[2] [Tech Salon 053：04 美团分布式关系数据库 ](https://www.bilibili.com/video/BV1Ez411z7wS)

[3] [Blade全流程](https://km.sankuai.com/page/388297586)

[4] [TiDB Optimistic Transaction Model](https://docs.pingcap.com/tidb/stable/optimistic-transaction) 

[5] [TiDB Architecture](https://docs.pingcap.com/tidb/stable/tidb-architecture)

[6] [mraft 整体架构介绍](https://km.sankuai.com/page/209342100)

