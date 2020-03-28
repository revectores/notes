## SQLite3 with Python

In order to execute SQL commands to a database, you must connect to it first, we can use `connect` method to get the `Connection` object and use this as a context (so after everything is done it's closed automatically) then get the `Cursor` object to it.

```python
import sqlite3
conn = sqlite3.connect('/Users/rex/test.db')
# The database will be created if it's not exist. Actually that's the way we create it.
# If you just need to create it in memeory but persistence, use
# sqlite.connect(':memory:')
with conn:
	cur = conn.curser()
```

Then the SQL commands execute through the `cursor`:

```python
with conn:
  cur = conn.cursor()
  sql = '''CREATE TABLE "person"(
  	"name" TEXT,
  	"age" INTEGER
  )
  '''
 	cur.execute(sql)
  print(cur.lastrowid)
```

That's all you need. The SQL commands will take you further.



## SQLite3 with Flask

##### An universal Database achieve process

```python
import sqlite3
from flask import g

DATABASE = ''

def get_db():
  db = getattr(g, '_database', None)
  if db is None:
    db = g._database = sqlite3.connect(DATABASE)
  return db
```

Basically `g` a object which lived through the whole `request`, and the `_database` indicates the database of this request. If the database has been properly created, that's it, otherwise we have to access the original database to make it fine.

When the application context is teared down, we need to close it:

```python
@app.teardown_appcontext
def close_connection(exception):
  db = getattr(g, '_database', None)
  if db is not None:
    db.close()
```



