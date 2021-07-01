# leveldb Interface

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

Internally even a single operation is packaged as a batch and transferred to `DB::Write` method:

```{.c++ .numberLines startFrom="1469" filename="db/db_impl.cc"}
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

By default, each write to leveldb is asynchronous: it returns after pushing the write from the process into the operating system. The transfer from operating system memory to the underlying persistent storage happens asynchronously. The `sync` flag can be turned on for a particular write to make the write opeartion not return until the data being written has been pushed all the way to persistent storage (implemented based on [`fsync()`]() or [`fdatasync()`]() or [`msync(..., MS_SYNC)`]() on POSIX systems):

```c++
leveldb::WriteOptions write_options;
write_options.sync = true;
db->Put(write_options, ...);
```



##### # Iteration

To iterate all keys in a database:

```c++
leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
for (it->SeekToFirst(); it->Valid(); it->Next()){
  printf("%s: %s\n", it->key().ToString(), it->value().ToString());
};
delete it;
```

Since keys are comparable we can limit the range when iteration by `lower < it < upper`.

Iterate backwards:

```c++
for (it->SeekToLast(); it->Valid(); it->Prev());
```



##### # Snapshots

Snapshots provide consistent read-only views over the entire state of key-value store. Set `ReadOptions::snapshot` to indicate which version of the database to read (if `ReadOptions::snapshot` is `NULL` the read will operate on an implicit snapshot of the current state):

```c++
leveldb::ReadOptions options;
options.snapshot = db->GetSnapshot();

leveldb::Iterator iter = db->NewIterator(options);
delete iter;
db->ReleaseSnapshot(options.snapshot);
```







### 2. Data Types

##### # Slice

During iteration the return value of `it->key()` and `it->value()` are both `leveldb::Slice`, which contains a length and a pointer to an external byte array:

```{.c++ .numberLines startFrom="88" filename="include/leveldb/slice.h"}
private:
  const char* data_;
  size_t size_;
```

Hence `ToString()` is implemented by

```{.c++ .numberLines startFrom="75" filename="include/leveldb/slice.h"}
std::string ToString() const { return std::string(data_, size_); }
```

Constructors building C++ strings and C-style strings are supported:

```{.c++ .numberLines startFrom="29" filename="include/leveldb/slice.h"}
// Create an empty slice.
Slice() : data_(""), size_(0) {}

// Create a slice that refers to d[0,n-1].
Slice(const char* d, size_t n) : data_(d), size_(n) {}

// Create a slice that refers to the contents of "s"
Slice(const std::string& s) : data_(s.data()), size_(s.size()) {}

// Create a slice that refers to s[0,strlen(s)-1]
Slice(const char* s) : data_(s), size_(strlen(s)) {}
```







### 3. Comparators

leveldb sorts keys lexicographically by default. User-defined comparator can be used as well:

```c++
// This comparator is the same as the default one, demonstrating the syntax.
class MyComparator : public leveldb::Comparator {
public:
  int Compare(const leveldb::Slice& key1, const leveldb::Slice& key2) const {
    if (key1 > key2) return  1;
	  if (key1 < key2) return -1;
    return 0;
  }

  const char* Name() const {return "MyComparator";}
  void FindShortestSeparator(std::string*, const leveldb::Slice&) const {}
  void FindShortSuccessor(std::string*) const {}
};
```

Create database using custom comparator:

```c++
MyComparator cmp;
leveldb::DB* db;
leveldb::Options options;
options.create_if_missing = true;
options.comparator = &cmp;
leveldb::Status s = leveldb::DB::Open(options, "/tmp/testdb", &db);
```

