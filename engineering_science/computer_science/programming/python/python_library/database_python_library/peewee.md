[TOC]

# Peewee

### 1. Basic Operations

##### # Connent to Database

Peewee supports multiple types of Databases. We'll use `MySQL` as the example in this document.

```python
# Connnect to MySQL Database:
test_db = peewee.MySQLDatabase('test_db', user='root', passwd='', host='localhost', port=3306)
```

If you connect to the `localhost` with default port `3306`, the `host` and `port` parameter can be omitted. Notice that the port parameter should be `int` instead of `str`.

This database connection method returns an instance of `peewee.MySQLDatabase`, which will be used when we build class to model tables.

Until now we just create a model for the database, we must use `connect` method to estabilish the connection actually:

```python
test_db.connect()
```

This step can be omitted as well since peewee will help us to estabilish it automatically when we need to execute the query, but it's still a good convension to call `connect` explicitly, by which we could recognize the potential problems about connections immediately, instead of delaying it until the query. Anyway, **explict is better than implicit**.

> If the following error raised
>
> ```
> peewee.ImproperlyConfigured: MySQL driver not installed!
> ```
>
> Install `PyMySQL` module to give a MySQL driver.



##### # Modeling Table

As we know the traditional way to `CREATE TABLE` in SQL looks like

```mysql
CREATE TABLE person (
	id		INTEGER NOT NULL AUTO_INCREMENT,
	name	VARCHAR(30) NOT NULL,
    age		INTEGER NOT NULL,
);
```

The corresponding modeling, notice the class should inherit the `peewee.Model` prototype:

```python
class User(peewee.Model):
	id   = IntegerField()
	name = CharField()
    age  = IntegerField()
    
    class Meta:
        database = test_db
```

As shown we use `IntegerField()` method to specify `INTEGER` field and `CharField` method to specify `VARCHAR` field. The complete field mapping could be found in [peewee field types table](http://docs.peewee-orm.com/en/latest/peewee/models.html#field-types-table).

Be aware aboumet the information omission:

- There's an keyword argument `null=False` to specify whether `NULL` value is allowed. Notice that the default value is `False`, that's why we don't need to declare `NOT NULL` in each case.
- peewee will automatically add the `PRIMARY_KEY` and `AUTO_INCREMENT` property to the field named `id`. You can specify the `primary_key` keyword argument to another field name, but there's no `auto_increment` keyword argument.

The correspondant desgin can be inferred from this example:

|     Object     |      Correspondant      |
| :------------: | :---------------------: |
|  Model Class   |     Database Table      |
| Field Instance |    Column on a Table    |
| Model Instance | Row in a database Table |

More details about the construction of table model will be discussed in [Modeling Table](). In next section we'll insert data into the database table via class instantiation.



##### # Instance Construction

```python
# Assign values when instantiation.
robert = Person(name='Robert', age=20)
robert.save()

# Create an empty instance and assign later.
john = Person()
john.name = 'John'
john.age = 25
john.save()
```

Here we create an instance of `User` model then `save` it to the table, since the record `robert` and `john` is new, this operation will be implemented by an `INSERT` command in the SQL-level. `save` command returns the number of rows modified, that is, returns `1` in this case.

Notice that since the `id` column is auto-increment, we don't need to specify, so it leaves as `None` before `save` operation, and it will be auto-updated after the `save` method finished its job.

```python
lewis = Person(name='Lewis', age=15)
print(lewis.id)		# None
lewis.save()
print(lewis.id)		# 3
```

`create` method is provided as a shortcut for initialization and insertion:

```python
user = User.create(username='username', password='password')
```

This method returns the created instance.

If there are lots of columns in a table, which is common in industry, you might want to store the columns data in a dictionary and use the dictionary unpack mechanism to pass the arguments:

```python
user_dict = {
    'username': 'username',
    'password': 'password',
}
user = User.create(**user_dict)
```



##### # Record Retrieve and Modification

```python

```











### 2. Playhouse Helper

##### # Conversion between Model and Dictionary









