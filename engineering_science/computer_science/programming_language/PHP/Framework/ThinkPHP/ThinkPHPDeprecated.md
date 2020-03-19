#### 3. Where

##### tp3: Array Style

```php
// Single Condition Query
$where['id'] = array('lt', 100);

// Mutli Condition Query
$where['id'] = array(array('lt', 100), array('neq', 6));
$where['id'] = array(array('lt', 100), array('gt', 500), 'or');


// Multi Field (Complex Logic Relation) Query
$where['id'] = $id;
$where['username'] = $username;
$where['_logic'] = 'or';

// `_complex` is required if such complex relation which involves 3 or more fields is introduced.
$base_where['id'] = $id;
$base_where['username'] = $username;
$base_where['_logic'] = 'or';
$where['_complex'] = 
```

Supported Conditional List:

| Expression      | Meaning                        |
| --------------- | ------------------------------ |
| `eq`            | equal                          |
| `neq`           | not equal                      |
| `gt`            | greater than                   |
| `egt`           | greater then or equal          |
| `lt`            | less than                      |
| `elt`           | less than or equal             |
| `[not] between` | (not) in the interval          |
| `[not] in`      | (not )in the given list        |
| `like`          | fuzzy query                    |
| `exp`           | any valid SQL query expression |
|                 |                                |

Some Shortcuts Field

`_string`

```php
// Use `_string` to manually construct sql query
$where['id'] = array('lt', 100);
$where['_string'] = 'status=1 AND score>10';
// Equivalent to $where['_string'] = array('exp', 'status=1 AND score>10')
```

`_qeury`

```php
// Use `_query` to simulate passing url parameters
// As a result, only equal condition is supported
$where['id'] = array('lt', 100);
$where['_query'] = 'status=1&score=10&_logic=or';
```



##### Not Recommend: String Style

```php
// Pure String
$User::where('id=10001')->select();

// String Concatenation
$User::where('id=%d and username=%s', array($id, $username));
$Uesr::where('id=%d and username=%s', $id, $username);
```

