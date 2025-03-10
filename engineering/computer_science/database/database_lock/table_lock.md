# Table Lock

There are two table-level locks:

- Table lock: `lock tables [table_name] read/write` ; `unlock tables [table_name]`. Note that the table lock not only limit the query from other threads but limit the thread holding the lock. For instance, consider thread A executes `lock tables t1 read, t2 write`, now the permitted operation matrix is:

  |                     |  T1  |  T2  |
  | :-----------------: | :--: | :--: |
  | Thread holding lock |  R   |  RW  |
  |    Other threads    |  R   |  /   |

- Metadata lock(MDL). Metadata is locked automatically whenever we access a table to gurantee the correctness of reads and writes. When CRUD on a table the database holds metadata read lock, while when modifying the database schema (applying DDL) the database holds metadata write lock, this means:

  - Multiple threads are permitted to operate CRUD on a single table.

  - When applying DDL, the write lock is held, hence the CRUD opeartion has to be blocked until it is done. This may have impact on the performance - consider the senario below

    |         session A          |         session B          |         session C          |         session D         |
    | :------------------------: | :------------------------: | :------------------------: | :-----------------------: |
    |           Begin            |                            |                            |                           |
    | `select * from t limit 1;` |                            |                            |                           |
    |                            | `select * from t limit 1;` |                            |                           |
    |                            |                            | `alter table t add f int;` |                           |
    |                            |                            |                            | `select * from t limit 1` |

    in this case not only session C but all DML opeartions that only requires read lock on MDL will be blocked. To solve this:

    - Avoid long transaction. Refer to [How to Avoid Long Transactions]() for details.

    - Set a timeout for DDL. This is supported in SQL syntax level now by AliSQL and MariaDB now:

      `ALTER TABLE [table_name] NOWAIT add column ...`

      `ALTER TABLE [table_name] WAIT N add column ...`







### References

[7 06 | 全局锁和表锁 ：给表加个字段怎么有这么多阻碍？](https://km.sankuai.com/page/461743400)

