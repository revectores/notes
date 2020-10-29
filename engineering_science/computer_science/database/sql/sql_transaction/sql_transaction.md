# SQL Transaction

The start of transaction is implicit, use `commit` or `rollback` to submit/cancel a transaction.

Each SQL statement is a transaction by default, and will be committed automatically. We can close the automatic commit.

`begin atomic ... end`.

