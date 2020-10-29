# SQL Constraint

### 1. SQL Constraint Introduction

SQL provide abundant syntax supports about **constraint**, which aims to avoid those operations that result in invalidating the relation schema in database. There are amounts of illogical relation instance that can be considered as a invalidation:

- The name or student ID of a student is `null` in student table. This should not occur, storing the information of a unkown student is meaningless.
- The department a student belongs to is not exist in school.
- The sum of credits of a student is not equal to the total credits.

As we will see, the SQL constraint system provides a far more powerful relation-checking system than the type system in programming language.

There are 3 types of integrity constrains:

- **Entity integrity constrain**.
- **Referential integrity constrain**.
- User-defined (domain/semantic) integrity constrain.







### 2. Constraint on Single Relation

##### # Constraint on Single Relation Summary

There are four types of constraint for single relation:

- `primary key` constraint.
- `not null` constraint.
- `unique` constraint.
- `check(P)` constraint.

The constraint to single relation can be added within `create table`, or `alter` after the table is created:

```sql
alter table <table> add <constraint>
```

 

##### # `primary key` constraint

The keyword `primary key` can be added right after the field name or as a independent declaration:

```sql
create table user (
	id int primary key
);
```

```sql
create table user (
	id int,
    primary key(id)
)
```

when using multiple columns as the primary key, use the latter form.



##### # `not null` constraint

```sql
name varchar(20) not null
budget numeric(12, 2) not null
```

`not null` constraint simply declare that the value in the field cannot be `null`.



##### # `unique` constraint

```sql
unique(A1, A2, ..., Am)
```

The unique declaration points that $A_1, A_2, \ldots, A_m$ constructs **superkey**. That is, none of the arbitary two records share the same unique fields.



##### # `check(P)` constraint

`check(P)` contrains the satisfaction of predicate $P$. For example, here in the `section` table we create a $P$ that saying `semester` can only be one of the four values:

```sql
create table section (
	course_id	varchar(8),
    sec_id		varchar(8),
    semester	varchar(6),
	-- ...
	check (semester in ('Fall', 'Winter', 'Spring', 'Summer'))
);
```

The SQL standard states that **any** predicates can be used in $P$, including nested subquery:

```sql
check (time_slot_id in (select time_slot_id from time_solt))
```

If the `time_slot_id` is the primary key of `time_solt`, we can use the foreign key restraint directly, but here it's not.

The cost can be large hence each insert query invokes the check process, hence is not supported by most of the DBMS, while we can utilize [trigger](https://en.wikipedia.org/wiki/Database_trigger) to implement the same function.







### 3. Referential Integrity

##### # Referential Integrity Definition

Definition of referential integrity: Denote $R_1, R_2$ as the properties set in relation $r_1, r_2$, and $K_1\subset R_1, K_2\subset R_2$, If we require that for any tuple $t_2\in r_2$, there always exists $t_1$ that satifies $t_1.K_1 = t_2.K_2$. We say the attribute set $K_2$ in relation $r_2$ **references** the attribute set $K_1$ in $r_1$.



##### # Cascade Operation

When the referenced value is deleted/updated, to avoid violation, a `cascade` reaction can be triggered:

```sql
create table course (
	dept_name varchar(20),
    foreign key (dept_name) references department
    	on delete cascade
    	on update cascade
);
```

Some other cascade operations: replace `cascade` by `set null`, `set default`, which empty or set default value when the referential target is deleted.



##### # Integrity Constraint Violation During Transaction

Consider about a person table that references itself:

```sql
create table person (
	ID		char(10),
    name	char(40),
    spouse	char(10),
    primary key(ID),
    foreign key (spouse) references person(ID)
);
```

How to insert a tuple in this case?

- Set the spouse into `null` at first, and latter update it until the corresponding spouse record is inserted.

- Defer the integrity condition until the transaction is committed:

    - Add `initially deferred` after the constraint declaration.

    - Add `set constraints <constraint-list> deferred`.







### 4. Assertion

Assertion is the predicate $P$ that should be satified in anytime in database. Property domain contraints and the referential constraint are both the special case of assertion. Syntax to craete assertion:

```sql
create assertion <assertion_name> check <predicate>
```

Same as the subquery in `check`, `create assertion` does not supported by any of the widely used database system, but trigger can also be used to implement the same function.

