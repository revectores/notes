# SQL Data Type

### 1. SQL Fundamental Type

##### # SQL Fundamental Type Overview

The basic data type supported by SQL:

| Type name                            | Description                                                  |
| ------------------------------------ | ------------------------------------------------------------ |
| `char(n)`, `character(n)`            | Fixed-length string with user-specified length $n$.          |
| `varchar(n)`, `character varying(n)` | variable-length string with user-specified max length.       |
| `int`, `integer`                     | An integer (the range is machine dependent).                 |
| `smallint`                           | Small integer (the range is also machine dependent).         |
| `numeric(p, d)`                      | A fixed-point number with user-specified precision. The number consists of $p$ digits in total, and $d$ of the $p$ digits are to the right of the decimal point. |
| `real`                               | Floating-point, ==range is machine dependent(not specified by IEEE 754?)== |
| `double precision`                   | Double-precision floating-point.==range is machine dependent(not specified by IEEE 754?)== |
| `float(n)`                           | A floating-point number with precision of **at least** $n$ digits. |



##### # `char` vs `varchar`

Conceptually, the `char` is fixed-sized string while `vachar` is variable sized. Refer to the [ MySQL 5.7 Reference Manual  /  Data Types  /  String Data Types  /  The CHAR and VARCHAR Types ](https://dev.mysql.com/doc/refman/5.7/en/char.html) For details about comparison between `char` and `varchar` in MySQL.







### 2. SQL Datetime Type

##### # SQL Datetime Type Overview

| Type Name   | Example                              | Description                                                  |
| ----------- | ------------------------------------ | ------------------------------------------------------------ |
| `date`      | `date '2020-10-24'`                  | A calendar date containing a four-digit year, month, and day. |
| `time`      | `time '09:00:00.50'`                 | The time of day in hours, minutes and seconds. `time(p)` can be used to specify the number of fractional digits for seconds (the default being 0). |
| `timestamp` | `timestamp '2020-10-24 09:00:00.50'` | The combination of date and time.                            |
| `interval`  | `interval '1' day`                   |                                                              |

Comparison and arithmetic operation is supported for these types. interval is interpreted as the difference of date/time/datetime.

The timezone information can be also stored in the `time` or `timestamp` fields with `time with timezone` and `timestamp with timezone` specified.



##### # SQL Datetime Part Extraction

Extract some parts (`year`,` month`, `day`, `hour`, `minute`, `second`, `timezone_hour`, `timezone_minute`) from `date` or `time` is supported by

```sql
extract (<part-name> from <field-name>)
```



##### # SQL Datetime Functions

Functions to retrive the current time (with or without timezone) is supported:

| Function            | Description                                |
| ------------------- | ------------------------------------------ |
| `current_date`      | Return current date.                       |
| `current_time`      | Return current time.                       |
| `localtime`         | Return current time without timezone.      |
| `current_timestamp` | Return current timestamp.                  |
| `localtimestamp`    | Return current timestamp without timezone. |







### 3. SQL Large Object Type

| Type Name | Description                                                  |
| --------- | ------------------------------------------------------------ |
| `blob`    | binary big object. The binary object is not interpreted.     |
| `clob`    | character big object. The object is recognized as the collection of characters. |

When the SQL query returns a big object, a **locator** instead the larget object is returned normally, then the locator is used to retrive the large object incrementally. This process works like returns a [file descriptor](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/operating_system/unix/unix_file/unix_file_intro/unix_file_intro.md#file-descriptor) and retrieve its content with [`read()`](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/operating_system/unix/unix_file/unix_file_intro/unix_file_intro.md#read) system call incrementally.

The pros and cons to use the large object type:

- Pros: There is no need to assign length to the large object, convient to use.

- Cons: Normally the target table need to be split into multiple tables, influence the profermance of database.







### 4. SQL Type conversion

Explicit conversion can be done by `cast (<field> as <target-type>)`. For example, to sort the `id` with type `varchar(5)`, the default behaviour will be sort lexicographically, which cause '11111' < '9'.

```sql
select id from users order by id;
```

To compare them as integers, we can cast them into numeric type:

```sql
select cast(id as numeric(5)) as int_id from users order by int_id;
```

Operate the sqlite3 database [`type_cast_demo.db`](src__type_cast_demo/type_cast_demo.db) to check the cast operation works in this example.







### 5. SQL User Defined Type

Use the following syntax to create the user-defined type based basic type:

```sql
create type [typename] as [basic-type] final;
```

Some implementation of SQL support the `final` to be ignored.

The user-define type provides a mechanism for strict type system even stronger than modern programmning language. For exmaple, we define the type `Dollars` and type `Pounds` to indicate different currency unit in department table and person table:

```sql
create type Dollars as numeric(12, 2) final;
create type Pounds as numeric(12, 2) final;
create table department (
    dept_id		int primary key,
    budget		Dollars
);
create table person (
	id			int,
    dept_id		int,
    asset		Pounds
);
```

Both the `Dollars` and `Pounds` use `numeric(12, 2)` as basis type, but since they different user-defined types , the following query will raise a type error:

```sql
select department.budget + sum(person.asset)
from department join person
group by dept_id;
```

Use `drop type [typename]` to delete and `alter type [typename] ...` to alter the user defined type.







### 6. SQL User Defined Domain

Constraint and default value can be applied to domain, like `not null` or create the `check` clause on it.

```sql
create domain degree_level varchar(10)
	constraint degree_level_test
	check(value in('Bachelors', 'Masters', 'Doctorate'));
```

Domain is not the strong type. If the base type is compatible, values in different domains can be assigned to each other.

Note that both user-defined type and user-defined domain are not supported either MySQL or SQLite3, hence not validation codes are provided here for these two topics.


