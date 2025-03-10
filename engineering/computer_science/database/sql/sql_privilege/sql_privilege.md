# SQL Privilege

##### # `grant`

Use `grant` to give privileges based on users or roles:

```sql
grant <privileges>
on <relation/view>
to <users/roles>
[with grant option];
```

- `<privileges>`: Each kind of query is a type of privilege: for instance `select`, `insert`,  `update`, `delete` are privileges, and `all` for all types of privileges. We can specify the columns in privilege `insert` and `update`. The executor of `grant` must already has those privileges.
- `<relation/view>`: The grant on view is not grant on underground relation.
- `<users/roles>` can be the id of user, role, or `public`, which represents all users (present and future).
- `[with grant option]` permits the grant privileges to be granted to other users.



##### # `revoke`

Use `revoke` to revoke the privileges:

```sql
revoke <privileges>
on <relation/view>
from <users/roles>
[restrict | casecade];
```

- When the `<users/roles>` are set to `public`, privileges will revoke from all the users **except** DBA or the relation creator.
- The default revoke mode is `cascade`, which revoke the privilege recursively, `restrict` ==?==

Specially, the `grant option` can also be revoked by `revoke grant option for <privileges>`.

If some privileges are based on the revoked privileges, they will be revoked also.



##### # Role

We can create roles to classify users:

```sql
create role <role-name>
```

The role can be `grant` to user, or to another role:

```sql
grant <role> to <user>
grant <role1> to <role2>
```

As mentioned beforehand, the privilege can be granted to role.

```sql
--- grant ...
--- ...
granted by <role>
```



##### # Schema Privilege

Only the schema onwer is able to modify schema.

`references` is also a privilege, since the reference will construct constraints to table. 





