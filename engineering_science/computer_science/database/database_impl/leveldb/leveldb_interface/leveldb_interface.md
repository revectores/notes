# Leveldb Interface

The leveldb library provides a persistent key-value store. Keys and values are arbitrary byte arrays. The keys are ordered within the key value store according to a user-specified comparator function.



### 1. Fundamental Operations

##### # Opening and Closing Database

Use `DB::Open` to open a database on the given path:

```c++
#include "leveldb/db.h"

leveldb::DB* db;
leveldb::Options options;
options.create_if_missing = true;
leveldb::Status s = leveldb::DB::Open(options, "/tmp/testdb", &db);
assert(s.ok());
delete db;
```

set `options.error_if_exists = true` to raise an error when the database already exists.

`s.ok()` returns a boolean value telling if the command is executed successfully. Use `s.ToString()` method to get the message in `std::string`.



##### # CRUD

Use `leveldb::DB::Put` and `leveldb::DB::Get` to write and read kv from database:

```c++
std::string name_value;
leveldb::Status s = db->Put(leveldb::WriteOptions(), "best_lang", "PHP");
if (s.ok()) s = db->Get(leveldb::ReadOptions(), "best_lang", &name_value);
assert(name_value == "PHP");
if (s.ok()) s = db->Delete(leveldb::Delete(leveldb::WriteOptions()), "best_lang");
```



##### # Atmoic Operations

Use `WriteBatch` object to group multiple operations as one atomic operation. For instance, we wish to move value of key1 to key2:

```c++
#include "leveldb/write_batch.h"

std::string value;
leveldb::Status s = db->Get(leveldb::ReadOptions(), key1, &value);
if (s.ok()) {
  leveldb::WriteBatch batch;
  batch.Delete(key1);
  batch.Put(key2, value);
  s = db->Write(leveldb::WriteOptions(), &batch);
}
```

Internally even a single operation is packaged as a batch and transferred to DB::Write method:

```{.c++ .numberLines startFrom="1469"}
Status DB::Put(const WriteOptions& opt, const Slice& key, const Slice& value) {
  WriteBatch batch;
  batch.Put(key, value);
  return Write(opt, &batch);
}

Status DB::Delete(const WriteOptions& opt, const Slice& key) {
  WriteBatch batch;
  batch.Delete(key);
  return Write(opt, &batch);
}
```



##### # Synchronous Writes

By default, each write to leveldb is asynchronous: it returns after pushing the write from the process into the operating system. The transfer from operating system memory to the underlying persistent storage happens asynchronously. The `sync` flag can be turned on for a particular write to make the write opeartion not return until the data being written has been pushed all the way to persistent storage (implemented based on `fsync()` or `fdatasync()` or `msync(, MS_SYNC)` on POSIX systems):

```c++
leveldb::WriteOptions write_options;
write_options.sync = true;
db->Put(write_options, ...);
```



##### # Concurrency

Leveldb supports only one process with multiple threads opening a database at a time.



