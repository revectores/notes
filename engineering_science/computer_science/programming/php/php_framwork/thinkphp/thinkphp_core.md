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