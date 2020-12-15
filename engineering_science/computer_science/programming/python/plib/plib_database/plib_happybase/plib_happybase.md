# Python Library HappyBase

`HappyBase` is a user-friendly interface to [HBase]() which utilizes the [Thrift]() gateway.

To interact with HBase, we first connect to the `NameNode` server:

```python
import happybase
connection = happybase.Connection('hostname', port=9090)
```

where the port `9090` is the default port for Thrift service.



Now we can create table:

```python
connect.create_table(
    'person',
    {
        'cf1': dict(max_versions=10),
        'cf2': dict(max_versions=1, block_cache_enabled=False),
        'cf3': dict()
    }
)
```

connect to table:

```python
test_table = connection.table('test')
```

put data:

```python
test_table.put(
	'row_1',
    {
        'cf1: name': 'Robert',
        'cf1: age':  '20'
    }
)
```

Note that the keys and values of the data dictionary can only be `str` or `bytes`.

