### DataBase Operations

##### # Table Object Select

The table is modeled as an object, the table name is converted to camel-case automatically. E.G. `user_base` is modeled as `UserBase`. You can also get the table object from method of `Db` module, by using the `table` method  `Db::table('table_name')`. This is somehow a functional approach.



##### # Record Access

Three parameters style are suppoted in the `get` method of table object database:

```php
// By Primary Key
$user = User::get(1);

// By Condition
$user = User::get(['name': 'admin']);

// Closure style supported more operation than array, which only considered the array as a where condition.
$user = User::get(function($query){
    $query->where('name', 'admin');
    	  ->order_by('name');
});
```

ThinkPHP construction the dynamic query method for each column:

```php
// Dynamic query only support single data query.
$user = User::getByName('admin');
```

`get` and `getByColumn` query returns as a object, subscripting approach is also supported.

```php
$user->id;  // same as $user['id'];
```





Using alternatives inside the model implementation:

```php
$this->getAttr('name');  // processed by ACCESSOR.
$this->getData('name');  // raw data
```





Using `all` method, correspondent to `get`.

```php
// By Primary Key
$users = User::all([1,2,3]); // or string '1,2,3'

// By Condition
$users = User::all(['status'=>1]);
$users = User::all(function($query) {
    $query->where('status', 1)->limit(3)->order('id', 'asc');
});
```

Using where statement(see next section).

Multiple data query returns an array of object.

```php
foreach ($users as $user){
    echo $user->name;
}
```



##### # Where

##### Simple Equal Condition Case

```php
// Single field
$User::where('id', 10)->select();
$User::where(['id'=>10])->select();

// Multi field combined with `and` logic.
$where['id'] = $id;
$where['username'] = $username;
$User::where($where)->select();
```



##### tp5: Chain Style

```php
$User::
```









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

