# Database Lock

##### # Two Approaches

There are two ways to lock the entire database (make it read-only):

- FTWRL `flush tables with read lock`.
- `set global readonly=true`

The FTWRL approach is recommended since

- `set global readonly=true` may have side-effect. Some condition depends on the value of `readonly` - for instance some system use this value to determine whether a database is master or slave.
- Exception handling is differs for two approaches:
  - For FTWRL, if the connection breaks, MySQL release the global database lock automatically.
  - For setting global `readonly`, the database keeps `readonly ` even if the connection has broken.



##### # Application Senario

This is a typical usage when to lock the entire database when constructing backups. Making the entire database read-only significantly impacts the performance while is necessary for consistency.

The other way is to utilize MVCC: `mysqldump` create a transaction (in repeatable read) if `-single-transaction` option is set. While this is only possible when the database supports the repeatable read isolation level.







### References

[7 06 | 全局锁和表锁 ：给表加个字段怎么有这么多阻碍？](https://km.sankuai.com/page/461743400)



