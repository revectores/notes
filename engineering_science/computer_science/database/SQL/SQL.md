

# Structured Query Language

### 1. Naming Convention

##### # Should I use the SQL keyword uppercase?

It might be an historial convenience when the editor doesn't support syntax highlighting to make the SQL more readable, while it seems to be less readable to make it SHOUT nowadays, so we'll keep it lowercase unless there's good reasons to captialize it.



##### # Should I use plural or singualr to name my table?

There's a huge divergence between programmers still. We prefer singular. The most important reason is that, although it seems more logic to name a table that stores more than one user as `users`, but as far as we concerned the name should be considered as an abstraction model or set instead of the real-world object container. The advantage of this perspective is shown more clear in the query process, where the property of record is introduced: 

```sql
select user.id, user.name from user where user.wealth > 1000;
select users.id, users.name from users where users.wealth > 1000;
```

Comparing the two query above, there's no doubt that it looks more naturally that we access the property of an singular like `user.name` instead of `users.name`(what is that?).

Besides the perspective how we consider about the table, it also reduce the code length, which contributes to the simplity, and provides more readibility because the plural might be complex in some cases.  

> You can refer the further disscussion in the link [https://stackoverflow.com/questions/338156/table-naming-dilemma-singular-vuus-plural-names](https://stackoverflow.com/questions/338156/table-naming-dilemma-singular-vuus-plural-names), which provides detailed examples and reasons.

> And we strongly recommend the answer [https://stackoverflow.com/questions/338156/table-naming-dilemma-singular-vs-plural-names#3894235](https://stackoverflow.com/questions/338156/table-naming-dilemma-singular-vs-plural-names#3894235) which introduce the uninflected idea which is pretty convictive.



##### # Should I use the underscore or camelcase to name the table or column?

There's also a huge divergence. For now in practics we use the underscore style in both cases. 






### 2. Table

##### # `CREATE TABLE`

To illustrate the syntax details of create a new table, here we exam a example about modeling a person by the table:

```sql
CREATE TABLE person (
	id INTEGER PRIMARY KEY AUTO_INCREMENT,
    name TEXT NOT NULL,
	age INTEGER NOT NULL,
    wealth NUMERIC NOT NULL DEFAULT 0;
);
```

Here we create a table named `person` with three columns: `id`, `name`, `birthday`, and `wealth`with the **DATATYPE** `INTEGER`, `TEXT`, `INTEGER`, and `NUMERIC` respectively.

Specially, `id` is specified as the `PRIMARY KEY` of this table, and it is set to `AUTO_INCREMENT`, by doing this, we're free to control this column manually when inserting new record, but let the database increase `1` for the `id` field each time we insert new record automatically.

Normally, when we insert a new record, if some of the columns are not assigned, it will be set as the default value, if no default value given, it will be set as `NULL`. If one column is declared as `NOT NULL`, when you try to assign it as `NULL`, the database will raise an error. Notice that since the primary key of table must not be null obviously, so there's no necessary to specify `NOT NULL` to `id` field.

If the name of table already exists, this expression will raise an error about `Table 'table_name' already exists` . To create table only if it has not been created, use `CREATE TABLE IF NOT EXISTS`, the syntax is the same as simple `CERATE TABLE`.

```sql
CREATE TABLE IF NOT EXISTS person ();
```



##### # `DROP` and `TRUNCATE`

Use `DROP TABLE table_name` command to delete a table: 

If the table doesn't exists the `Unknown table` error will raise, you can use the `DROP TABLE IF EXISTS` to avoid this.

`TRUNCATE TABLE` command delete all the records but not delete the table and its structures ifself.







### 3. Data Retrieve

##### # `SELECT`

`SELECT` use to select records, usually combined with some filter or control commands like `WHERE` and `ORDER`. The simplist example is to select the specify columns of all the records:

```sql
SELECT id, name FROM person;
```

Use the asterisk to select all the columns:

```sql
SELECT * FROM person;
```

Notice that this approach is NOT recommend because of the implicity and the query cost.



##### # `WHERE`

`WHERE` is used to filter the records which fits specific condition, most of the operators are supported by SQL in the comparison including `=`, `>`, `<`, `>=`, `<=` and `<>`(`!=`). The equality comparison only require SINGLE equal sign. Notice that the expression of unequal comparison operator differs in different Database System. 

SQL supports lots of Logical Operators, includes the common `AND`, `OR` and `NOT`, notice that the operator `&`, `|` are used for the bitwise AND/OR(there's no bitwise NOT but bitwise XOR ^ provided, you can use the XOR to implement NOT manually). 

For example:

```sql
SELECT id, name, age FROM person WHERE person.age = 18;
SELECT id, name, age FROM person WHERE person.age > 18 AND person.wealth > 1000.0; 
```

Notice that we append the table name before the where condition in the example above. The table name can be omiited in this one-table query case, because there can't be any conflicts, while if we're going to join multiple tables and they share the same column names an error will raise. 

==todo: Full table of the logic expression of SQL==







### 4. Records Modification

##### # `INSERT`

Use `INSERT` query to insert new record into the database:

```sql
INSERT INTO person(name, age, wealth)
VALUES ('Robert', 20, 1000.0), (Lewis, 15, 50.0);
-- Notice that this syntax is not supported by all databases, as we know for now this is supported by MySQL and SQLite3.
-- For those don't support this you might need UNION.
```



##### # `DELETE`

```sql
DELETE FROM user WHERE username='hello';
```



##### # Existence Check

```sql
SELECT COUNT(1) FROM user WHERE username='hello';
-- return 1 if the record exists else 0.
-- same COUNT(*)
```

`COUNT` function works as followed: it executes for every record, and if the return value is not `NULL`, the result adds 1. A single `1` may be a little tricky, it just means that for all filtered records by `WHERE`, it always return 1, which is not `NULL`, as the result the return value will be the number of records.



##### # Calculation Function

```sql
SELECT SUM(Price) FROM Products;
SELECT AVG(Price) FROM Products;
```


