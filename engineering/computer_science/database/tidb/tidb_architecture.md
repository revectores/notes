# TiDB Architecture

### 1. Introduction

As a distributed SQL database, TiDB consists of three core components:

- **TiDB Server** for SQL parsing and distributed execution plan generation.
- **PD (Placement Driver) Server** for replica placement.
- Storage engine includes **TiKV** and **TiFlash**, provides row/column storage for OLTP/OLAP task respectively.







### 2. TiKV Server

The tikv storage system can be considered as a large-scale distributed `ordered_map`, where the key and value are both bytes array, and the comparator can be user-defined.

The key space is divided into multiple **regions**, each region stores a continuous key range `[StartKey, EndKey)`. Region is the unit for data duplication, each copy is named **replica**. The placement of replica in tikv nodes is managed by placement driver. **Raft** protocol is applied for consensus algorithm. Hence only the replica selected as leader processes read and write operation (and then send logs to follower replica to keep them updated).

Similar to leveldb, tikv supports MVCC by adding the version number after key. For one key the different versions of it are sorted in reverse (newest version in the front), by which we always access the updated version first. `Seek` operation is supported to locate value of key in historical snapshot `Version` by `Seek(Key-Version)`.

tikv uses **Percolator** transaction model equipped with multiple optimizations. **Optimistic concurrency control** is applied hence the performance is better when the competition is light while is worse when the competition is heavy comparing with pessimistic concurrency control.

tikv saves data to RocksDB and let it handle the interaction with physical storage medium.







### 3. TiDB Server

TiDB Server translates user SQL query operation to operators of tikv.

The first problem is how to store the SQL relational database inside key-value system tikv. There are three types of data to store for a table:

- Row
- Index
- Metadata

TiKV uses row storage. Each row, unique index, and non-unique index are encoded as

```
Key:   t{tableID}_r{rowID}
Value: [col1, col2, ...]

Key:   t{tableID}_i{indexID}_indexedColumnsValue
Value: rowID

Key:   t{tableID}_i{indexID}_indexedColumnsValue_rowID
Value: null
```

For instance, consider a table with a non-unique index on the fourth row

```
1, "TiDB", "SQL Layer", 10
2, "TiKV", "KV Engine", 20
3, "PD",   "Manager",   30
```

The row data and index will be mapped to

```
t10_r1 -> ["TiDB", "SQL Layer", 10]
t10_r2 -> ["TiKV", "KV Engine", 20]
t10_r3 -> ["PD",   "Manager",   30]

t10_i1_10_1 -> null
t10_i1_20_2 -> null
t10_i1_30_3 -> null
```

The metadata is stored after serialization in some keys like `m_{tableID}`, `m_{databaseID}`. The current schema version information is also stored by special key-value item. Online schema change algorithm proposed by Google F1 is used to track whether the schema that TiKV stores has changed.

Based on the encoding above we are able to construct the mapping from SQL query to KV operator, for instance, consider

```sql
SELECT count(*) FROM user WHERE name="TiDB";
```

We can translate it to the operations on KV below:

- Construct key range of `[StartKey, EndKey)` based on encoding rules of key.
- Iterate the key range to read each row of data.
- Compute expression `name="TiDB"` to determine whether to process this line or drop.
- Increment counter for each filtered row.

Apparently there are lots of pointless computation and multiple optimizations to be done in this scheme.







### 4. Placement Driver Server

Each TiKV node and each leader of Raft group reports the status about TiKV node and region periodically so the PD server are able to determine the best placement strategy to balance the distribution of replicas based on these information. Specifically, the PD server apply the three operations

- Add a replica
- Delete a replica
- Transfer the leader role between different replicas inside a Raft group.

to guarantee some configuration constraints:

- The region's replica number is correct.
- Multiple replicas are not in the same position inside a Raft group.
- Replicas, Leaders, and access hotspots are distributed uniformly among stores (TiKV nodes).







### Reference

[^1]: [TiDB 整体架构](https://docs.pingcap.com/zh/tidb/stable/tidb-architecture)

[^2]: [三篇文章了解 TiDB 技术内幕 - 说存储](https://pingcap.com/blog-cn/tidb-internal-1/)

[^3]: [三篇文章了解 TiDB 技术内幕 - 说计算](https://pingcap.com/blog-cn/tidb-internal-2/)

[^4]: [三篇文章了解 TiDB 技术内幕 - 谈调度](https://pingcap.com/blog-cn/tidb-internal-3/)
