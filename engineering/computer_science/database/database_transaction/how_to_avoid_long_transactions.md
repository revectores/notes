# How to Avoid Long Transactions

From the application's perspective:

- Make sure `set autocommit=1`
- Search and remove uncessary read-only transactions. Some bad-design framework encapsulates arbitary query inside `begin/commit`.
- `SET MAX_EXECUTION_TIME` to control the time limit of query.

From the database's perspective:

- Monitor `information_schema.Innodb_trx.` Warn or kill if a transaction reaches the threshold. `pt-kill` in `Percona` is a tool to kill specific query matching given conditions, which can be used to implement this requirement.

- Print all `general_log` when testing (this is not acceptable in production due to its impaction on performance, but we can still sample `general_log` for a short period, 1 hour, for instance).

- Set `innodb_undo_tablespaces = 2`. Undo logs are stored in **system tablespace** by default (that is, `innodb_undo_tablespaces = 0`), by can be stored in one or more **undo tablespaces** instead by reconfiguring this option. For truncation to occur (`innodb_undo_log_truncate = ON`, which marks those tablespaces that exceed the threshold value defined by `innodb_max_undo_log_size` for truncation), we must have `innodb_undo_tablespaces >= 2 `, which ensures that that one undo tablespace remains active while the other is taken offline to be truncated.

  Note: The `innodb_undo_tablespace` option is now deprecated in MySQL 5.7, and no longer configurable as of MySQL 8.0.14. In MySQL 8.0 the undo tablespace should be added by `CREATE UNDO TABLESPACE` keyword:

  ```mysql
  CREATE UNDO TABLESPACE tablespace_name ADD DATAFILE 'file_name.ibu'
  ```





### References

[4 03 | 事务隔离：为什么你改了我还看不见？](https://km.sankuai.com/page/461718615)

[5 04 | 深入浅出索引（上）](https://km.sankuai.com/page/461569594)

[MySQL 5.7 Reference Manual  /  The InnoDB Storage Engine  /  InnoDB On-Disk Structures  /  Tablespaces  /  Undo Tablespaces](https://dev.mysql.com/doc/refman/5.7/en/innodb-undo-tablespaces.html#truncate-undo-tablespace)

[MySQL 8.0 Reference Manual  /  The InnoDB Storage Engine  /  InnoDB On-Disk Structures  /  Tablespaces  /  Undo Tablespaces](https://dev.mysql.com/doc/refman/8.0/en/innodb-undo-tablespaces.html)

