# SQL View

**View**, as the abstraction level upon logical table, provides mechanism to create virtual relation, which can be used to:

- See the database with different perspective without adding redundant data.
- Permission control. We can provide public view that contains only the non-sensitive fields but hide the true table.

The view is created and stored as query:

```sql
create view <view-name>
[<field-name1>, <field-name2>, ...]
as <query_expression>
[with check option];
```

When the `with check option` is given, SQL checks whether the inserted record satisifies the where clause in the perspective definition.

Since complex query might hidden under the view definition, the attempt to update data inside a view is usually simply rejected. The SQL persepctive is **updatable** if and only if the following four conditions satified:

- The from clause has only one database relation.
- The select clause contains only attribute names of the relation and does not have any expression, aggregates, or distinct specification.
- Any attribute not listed in the select clause can be set to `null`. That is, it does not have a not null constraint and is not part of a primary key.
- The query does not have a group by or having clause.

