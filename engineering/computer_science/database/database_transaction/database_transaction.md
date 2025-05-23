# Transaction

### 1. Definition

The traditional isolation levels include

- **Read uncommited**. Record modifitions can be read even if the transaction has not been committed.
- **Read committed**. Record modificitions can be read after the transaction has committed.
- **Repeatable read**. The record a transaction read keep unmodified since the beginning of the transaction.
- **Serializable**. Two transaction act as if they are executed in serially. This is implemented by read-lock and write lock for corresponding read and write operation.

For instance, consider two transactions

|   Transaction A   |   Transaction B   |
| :---------------: | :---------------: |
| Start Transaction | Start Transaction |
|  Query A, get 1   |                   |
|                   |  Query A, get 1   |
|                   |   Update A = 2    |
|  Query A, get V1  |                   |
|                   |      Commit       |
|  Query A, get V2  |                   |
|      Commit       |                   |
|  Query A, get V3  |                   |

Consider the values of V1, V2, V3 in four isolation levels (it's trivial to induct based on definition of isolation levels):

|      | Read uncommitted | Read Committed | Repeatable Read | Serializable |
| :--: | :--------------: | :------------: | :-------------: | :----------: |
|  V1  |        2         |       1        |        1        |      1       |
|  V2  |        2         |       2        |        1        |      1       |
|  V3  |        2         |       2        |        2        |      2       |

Note that the default isolation level varies between database, for instance, the default isolation level for Oracle is "Read Committed", while the default isolation level for MySQL is "Repeatable Read". Hence special treats must be given when migrating application between different databases.







### 2. Implementation

##### # Repeatable Read

For Innodb, a `read-view` is generated whenever a transaction starts. Database plays the undo logs on the current value until the record gets the correct `read-view`. Specifically, a `read-view` is implemented by generating a unique auto incrementing transaction id for each transaction, and maintaining the corresponding **transaction id** `trx_id` for each version of record (row) and **the list of active transactions when a transaction starts** (denoted as `L`), to determine which version of record is valid under the requirement of repeatable read, all the database have to do is to check `trx_id` and `L`:

- If `trx_id` belongs to `L`: the version of record is generated by uncommitted transaction (when the current transaction starts) - which should be imperceptible.
- If `trx_id` does not belong to `L`:
  - If `trx_id < max(L)`: This version must be generated by committed transaction, perceptible.
  - If `trx_id > max(L)`: This version is generated by "future" transaction (that is, transaction starts after the current transaction), imperceptible.

Note that the repeatable read rule only applies to read query: For update rule the read is **current read**, that is, reads the newest value, otherwise the updates done by other transaction may be lost.

Consider the scenario under the isolation level of repeatable read below:

| TRansaction A                                 | Transaction B                                                | Transaction C                          |
| --------------------------------------------- | ------------------------------------------------------------ | -------------------------------------- |
| `start transaction with consistent snapshot;` |                                                              |                                        |
|                                               | `start transaction with consistent snapshot;`                |                                        |
|                                               |                                                              | `update t set k = k + 1 where id = 1;` |
|                                               | `update t set k = k + 1 where id = 1; ` `select k from t where id = 1;` |                                        |
| `select k from t where id = 1;` `commit;`     |                                                              |                                        |
|                                               | `commit;`                                                    |                                        |

For transaction A `k = 1`, while for transaction B `k = 3` due to the **current read** requirement of update operation.

The `undo log` will not be deleted until there is no earlier `read-view`. That is why long transaction should be avoided otherwise there will be ancient `read-view` which makes the undo log unacceptable large. In addition, long transaction takes lock for a long time, which blocks other SQL requests.

To avoid long transactions, the advices given in [How to Avoid Long transactions]() are considerable.







### References

[4 03 | 事务隔离：为什么你改了我还看不见？](https://km.sankuai.com/page/461718615)

[9 08 | 事务到底是隔离的还是不隔离的？](https://km.sankuai.com/page/461539685)
