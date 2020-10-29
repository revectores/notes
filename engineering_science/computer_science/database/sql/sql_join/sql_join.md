# SQL Join

##### # Inner Join with Conditions

The [Cartesian product]() of two tables with a where clause to filter by some equal fields are common case in practice:

```sql
select name, course_id
from student, takes
where student.ID = takes.ID
```

To [make the common case fast](https://www.elsevier.com/connect/8-great-ideas-in-computer-architecture), SQL use `natural join` as a shortcut for this:

```sql
select name, course_id
from student natural join takes
```

where the `natural join` will detect the fields with same names, and find out all the matching tuples in two tables in those fields. We call this default configuration **natural join**. `join` is a alias for `natural join`.

To specify which fields to match explicitly, a `using` method can be applied:

```sql
select name, course_id
from student, join takes using (ID)
```

Generally, use `on` keyword to specify **any predicates** when joining. For example, the query above is equivalent to

```sql
select name, course_id
from student, join takes
on student.ID = takes.ID
```

You may notice that this form is the same as the while condition with Cartesian product in the beginning, they work the same only in the case of inner join, we'll see for the outer join they behave different. Although, when specifying the condition of joining, you shall always use `on` to explicit express the semantics about specifying the predicate of join.



##### # Outer Join

The inner join lost records in both tables that does not match, to avoid the records loss, three types of outer joins are introduced:

2. The **left outer join** also keeps the tuple (even unmatched) on the left table.
3. The **right outer join** also keeps the tuple (even unmatched) on the right table.
4. The **full outer join** keeps all the tuples on both table.

When the outer join is applied, the `on` keyword in outer join kept those unmatched values while `where` clause will ignore them.

