[TOC]

# Peewee

### 1. Basic Operations

##### # Connent to Database

Peewee supports multiple types of Databases. We'll use `MySQL` as the example in this document.

```python
# Connnect to MySQL DataBase:
test_db = peewee.MySQLDataBase('test_db', user='root', passwd='', host='localhost', port=3306)
```

If you connect to the `localhost` with default port `3306`, the `host` and `port` parameter can be omitted. Notice that the port parameter should be `int` instead of `str`.

This method return an instance of `peewee.MySQLDatabase`, which will be used when we build class to model tables inside it. Until now we just create a model for the database, next we use `connect` method to estabilish the connection:

```python
test_db.connect()
```

In fact this step is not necessary, the when we need to do the query `peewee` will help us to estabilish it automatically, but it's still a good convension to call `connect` explicitly, by which we could recognize the potential problems about connections immediately instead of delaying it until the query. Anyway, explict is better than implicit XD.



##### # Modeling Table

As we know the traditional way of `CREATE TABLE` looks like

```mysql
CREATE TABLE person (
	id		INTEGER NOT NULL AUTO_INCREMENT,
	name	VARCHAR(30) NOT NULL,
    age		INTEGER NOT NULL,
);
```

When we model a table, we also provide these infomation but in an OOP and more concise way:

```python
class User(peewee.Model):
	id   = IntegerField()
	name = CharField()
    age  = IntegerField()
    
    class Meta:
        database = test_db
```

As shown we use `IntegerField()` method to specify `INTEGER` field and `CharField` method to specify `VARCHAR` field. The complete field congurent realtionship could be referred in [peewee field types table](http://docs.peewee-orm.com/en/latest/peewee/models.html#field-types-table).

Be aware aboumet the information omission:

- There's an keyword argument `null` to specify whether `NULL` value is allowed, the default value is `False`, so you don't need to declare `NOT NULL` in each case.
- `peewee` will automatically add the `PRIMARY_KEY` and `AUTO_INCREMENT` property to the field named `id`. You can specify the `primary_key` keyword argument to another field name, but there's no `auto_increment` argument.

The correspondant desgin can be inferred from this example:

|     Object     |      Correspondant      |
| :------------: | :---------------------: |
|  Model Class   |     Database Table      |
| Field Instance |    Column on a Table    |
| Model Instance | Row in a database Table |

More details about the construction of table model will be discussed in [4. Modeling Table]() in next section we'll insert data into the database table via class instantiation.



##### # Instance Creation and Insertion

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

Here we create an instance of `User` model then `save` it to the table, since the record `robert` and `john` is new, this operation will be implement by an `INSERT` command in the SQL-level. `save` command returns the number of rows modified, that is, returns `1` in this case. 

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

The method returns the created instance.

If there're lots of columns in a table, which is common for industrial database, you might want to store the columns data in a `dict` and use the dictionary unpack to pass the arguments:

```python
user_dict = {
    'username': 'username',
    'password': 'password',
}
user = User.create(**user_dict)
```



##### # Record Retrieve and Edit

```python

```








$$
f(n) = \left\{
\begin{array}{ll}
\frac{2}{n}\\
n+1\\
\end{array}
\right.
$$




