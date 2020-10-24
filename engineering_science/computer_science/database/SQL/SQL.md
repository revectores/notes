

# Structured Query Language

### 1. Naming Convention

##### # Keyword Case

It might be an historial convenience when the editor doesn't support syntax highlighting to make the SQL more readable, while it seems to be less readable to make it SHOUT nowadays, so we'll keep it lowercase, as the modern Homo sapiens.



##### # Table Name Form

There's a huge divergence between programmers still. We prefer singular. The most important reason is that, although it seems more logic to name a table that stores more than one user as `users`, but as far as we concerned the name should be considered as an abstraction model or set instead of the "objects container". The advantage of this perspective is shown more clear in the query process, where we try to get the property of record:

```sql
select user.id, user.name from user where user.wealth > 1000;
select users.id, users.name from users where users.wealth > 1000;
```

Comparing the two query above, there's no doubt that it looks more naturally that we access the property of object like `user.name` instead of `users.name`.

Besides the perspective how we consider about the table, it also reduce the code length, which contributes to the simplity, and provides more readibility since the plural might be complex in some cases.  

> You can refer the further disscussion in the link [https://stackoverflow.com/questions/338156/table-naming-dilemma-singular-vuus-plural-names](https://stackoverflow.com/questions/338156/table-naming-dilemma-singular-vuus-plural-names), which provides detailed examples and reasons.
>
> And we strongly recommend the answer [https://stackoverflow.com/questions/338156/table-naming-dilemma-singular-vs-plural-names#3894235](https://stackoverflow.com/questions/338156/table-naming-dilemma-singular-vs-plural-names#3894235) which introduce the uninflected idea which is pretty convictive.



##### # under_score or camelCase

There's a huge divergence. For now we use the underscore style in both cases in practice.








### 2. Table Operation

##### # `CREATE TABLE`

To illustrate the syntax details of create a new table, here we exam a example about modeling a person by the table:

```sql
create table person (
	id integer PRIMARY KEY AUTO_INCREMENT,
    name text not null,
	age text not null,
    wealth numeric not null default 0;
);
```

Here we create a table named `person` with three columns: `id`, `name`, `birthday`, and `wealth` with **data type** `INTEGER`, `TEXT`, `INTEGER`, and `NUMERIC` respectively.

Specially, `id` is specified as the `PRIMARY KEY` of this table, and it is set to `AUTO_INCREMENT`, by doing this, we're free to control this column manually when inserting new record, but let the database increase `1` for the `id` field each time we insert new record automatically.

Normally, when we insert a new record, if some of the columns are not assigned, it will be set as the default value, if no default value given, it will be set as `NULL`. If one column is declared as `NOT NULL`, when you try to assign it as `NULL`, the database will raise an error. Notice that since the primary key of table must not be null obviously, so there's no necessary to specify `NOT NULL` to `id` field.

If the name of table already exists, this expression will raise an error about `Table 'table_name' already exists` . To create table only if it has not been created, use

```sql
create table if not exists person (...);
```



##### # `drop` and `truncate`

Use `drop table [table_name]` command to delete a table: 

If the table doesn't exists the `Unknown table` error will raise, you can use the `drop table if exists` to avoid this.

`truncate [table_name]` command delete all the records but not delete the table and its structures ifself.







### 3. Query

##### # `select`

We use `select` to select records, usually combined with some filter or control commands like `where` and `order`. The simplist example is to select the specify columns of all the records:

```sql
select id, name from person;
```

Use `*` to select all fields:

```sql
select * from person;
```

This usage is **NOT** recommended due to its implicit and the query cost. Always write the name of fields explicitly during the programming.

Operations and functions on fields are supported:

```sql
select ID, name, salary/12, 10
from instructor;
```





##### # `where`

`where` is used to filter the records that meet specific condition, most of the comparison and logic operators are supported by SQL including `=`, `>`, `<`, `>=`, `<=`,  `<>`(`!=`) and `and`, `or`, `not`. The operator `&`, `|` are used for the bitwise AND/OR (there's no bitwise NOT but bitwise XOR `^` provided, you can use the XOR to implement NOT manually).

Notice that the expression of unequal comparison operator differs in different database system.

For example,

```sql
select id, name, age from person where person.age = 18;
select id, name, age from person where person.age > 18 and person.wealth > 1000.0; 
```

Notice that we append the table name before the where condition in the example above. The table name can be omiited in this one-table query case, because there can't be any conflicts, while if we're going to join multiple tables and they share the same column names an error will raise.



##### # `distinct`

The results can be repeated by default, to remove the repeated items, add the `distinct` after `select` keyword:

```sql
select distinct dept_name
from instructor;
```

Use `all` to allow the repeats explicitly:

```sql
select all dept_name
from instructor;
```



##### # `from` clause

The `from` clause constructs Cartesian product. The following example generates each possible pair of instructor-teaches.

```sql
select *
from instructor, teaches;
```

where clause is usually used to get the meaningful results.

```sql
select name, course_id
from instructor, teaches
where instructor.id = teaches.id;
```

which is equivalent to

```sql
select name, course_id
from instructor natural join teaches;
```



##### # Rename

Rename operation is supported by keyword `as`:

```sql
select ID, name, salary/12 as monthly_salary
from instructor;
```

```sql

```







### 4. Join



```sql
select *
from instructor natural join teaches;
```





### 5. Group







### 4. Records Modification

##### # `insert`

Use `insert` query to insert new record into the database:

```sql
insert into person(name, age, wealth)
values ('Robert', 20, 1000.0), (Lewis, 15, 50.0);
-- Notice that this syntax is not supported by all databases, as we know for now this is supported by MySQL and SQLite3.
-- For those don't support this you might need UNION.
```



##### # `delete`

```sql
delete from user where username='hello';
```



##### # Existence Check

```sql
SELECT COUNT(1) FROM user WHERE username='hello';
-- return 1 if the record exists else 0.
-- same COUNT(*)
```

`COUNT` function works as followed: it executes for every record, and if the return value is not `NULL`, the result adds 1. A single `1` may be a little tricky, it just means that for all filtered records by `WHERE`, it always return 1, which is not `NULL`, as the result the return value will be the number of records.

$$

$$




### 5. Function

```sql
select sum(Price) from Products;
select avg(Price) from Products;
```







##### # `group by`



##### # `having`

As known, `where` is the filter condition for the tuple, while `having` clause is the filter condition for group.

```sql
select dept_name, avg(salary)
from instructor
group by dept_name
having avg(salary) > 42000;
```

When combining the `where` and `group by`, `where` should be applied before the grouping process, while `having` clause executes after the grouping has finished, hence the cluster function can be applid in the clause.

Any 



##### # `null` in Cluster Function

All the cluster function ignores `null` from input except `count(*)`, for example, 

```sql
select sum(salary) from instructor
# The `null` value in salary will be omitted.
```

Specially, if all the inputs are `null`, cluster function returns `null` while `count` function returns `0`.






##### # `with`

Find the department with maximum budget:

```sql
with max budget(value) as (
	select max(budget) from department
)
select budget, department.dept_name
from department, max_budget
where department.budget = max_budget.value 
```





### SQL Join

Join operation:

- join type
- join 


There are four types of join operations:

- Inner join only keeps the matched tuples.
- The left outer join also keeps the tuple (even unmatched) on the left table.
- The right outer join also keeps the tuple (even unmatched) on the right table.
- The full outer join keeps all the tuples on both table.

Natural join automatically detect the same columns to match, while `on` and `using` can be applied to tell which columns to match manually. The difference is: `using`, same as natural, removes duplicates while `on` keeps them.



```sql
select * from course inner join prereq on
course.course_id = prereq.course_id;
```





### Perspective






```sql
select dept_name, count(*) as instructor_count
from department left outer join instructor
using department.dept_name = instructor.dept_name
group by dept_name


```


We can create view to added abstraction level to real tables:

```sql
create view view_name[(<column_name1>, <column_name2>, ...)]
as <query_expression>
[with check option];
```

