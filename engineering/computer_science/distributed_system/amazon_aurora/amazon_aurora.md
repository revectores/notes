# Amazon Aurora

##### # Amazon Aurora Introduction

Goal: DBMS with transaction management.

Interface: Same as MySQL/Postgres

Consistency: strong consistency.



Initial attempt at DBMS on AWS: Just run an existing DBMS (e.g. MySQL) on cloud VMs, and use replicated disk storage

Problems:

- Elasticity
- Efficiency

**Write amplification**: each write at app level results in many writes to physical storage.

Implement replication at a higher level: only replicate the redo log (not disk blocks).

Enable elastic frontend and backend by decoupling API & storage servers.







### 