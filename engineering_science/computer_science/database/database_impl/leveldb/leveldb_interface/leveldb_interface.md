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



##### # Approximate Sizes

The `GetApproximateSizes` method can be used to get the number of bytes of file system space used by one or more key ranges:

```c++
leveldb::Range ranges[2];
ranges[0] = leveldb::Range("a", "c");
ranges[1] = leveldb::Range("x", "z");
uint64_t sizes[2];
db->GetApproximateSizes(ranges, 2, sizes);
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







### 4. Performance

Performance can be tuned by changing the default values of the types defined in `include/options.h`.

##### # Block Size

```{.c++ .numberLines startFrom="96" filename="include/options.h"}
// Approximate size of user data packed per block.  Note that the
// block size specified here corresponds to uncompressed data.  The
// actual size of the unit read from disk may be smaller if
// compression is enabled.  This parameter can be changed dynamically.
size_t block_size = 4 * 1024;
```

leveldb groups adjacent keys together into the same block and such a block is the unit of transfer to and from persistent storage. The deafult block size is **approximately** 4096 **uncompressed** bytes.

- Applications that mostly do bulk scans over the contents of the database may wish to increase the size.
- Applications that do a lot of point reads of small values may wish to switch to a smaller block size if performance measurements indicate an improvement. Compression will be more effective with larger block sizes.



##### # Compression

```{.c++ .numberLines startFrom="21" filename="include/options.h"}
// DB contents are stored in a set of blocks, each of which holds a
// sequence of key,value pairs.  Each block may be compressed before
// being stored in a file.  The following enum describes which
// compression method (if any) is used to compress a block.
enum CompressionType {
  // NOTE: do not change the values of existing entries, as these are
  // part of the persistent format on disk.
  kNoCompression = 0x0,
  kSnappyCompression = 0x1
};
```


```{.c++ .numberLines startFrom="117" filename="include/options.h"}
// Compress blocks using the specified compression algorithm.  This
// parameter can be changed dynamically.
//
// Default: kSnappyCompression, which gives lightweight but fast
// compression.
//
// Typical speeds of kSnappyCompression on an Intel(R) Core(TM)2 2.4GHz:
//    ~200-500MB/s compression
//    ~400-800MB/s decompression
// Note that these speeds are significantly faster than most
// persistent storage speeds, and therefore it is typically never
// worth switching to kNoCompression.  Even if the input data is
// incompressible, the kSnappyCompression implementation will
// efficiently detect that and will switch to uncompressed mode.
CompressionType compression = kSnappyCompression;
```

Each block is individually compressed before being written to persistent storage. Compression is on by default since [`Snappy`](https://en.wikipedia.org/wiki/Snappy_(compression)) algorithm is very fast, and is automatically disabled for uncompressible data.



##### # Cache


```{.c++ .numberLines startFrom="92" filename="include/options.h"}
// If non-null, use the specified cache for blocks.
// If null, leveldb will automatically create and use an 8MB internal cache.
Cache* block_cache = nullptr;
```

LRU Cache can be used to cache uncompressed block contents in memory (Caching of compressed blocks is left to the operation system buffer cache, or any custom `Env` implementation provided by client):

```c++
#include "leveldb/cache.h"
leveldb::Options options;
options.block_cache = leveldb::NewLRUCache(100 * 1048576);
// ...
```

Caching mechanism can be temporily disabled by turning `ReadOptions::fill_cache` off:

```{.c++ .numberLines startFrom="153" filename="include/options.h"}
// Should the data read for this iteration be cached in memory?
// Callers may wish to set this field to false for bulk scans.
bool fill_cache = true;
```

For instance, during iteration:

```c++
leveldb::ReadOptions options;
options.fill_cache = false;
leveldb::Iterator* it = db->NewIterator(options);
```



##### # Filter

```{.c++ .numberLines startFrom="139" filename="include/options.h"}
// If non-null, use the specified filter policy to reduce disk reads.
// Many applications will benefit from passing the result of
// NewBloomFilterPolicy() here.
const FilterPolicy* filter_policy = nullptr;
```

A filter detects whether a key is in the database without actually execute the database access hence reduce substantial disk reads. set `Options::filter_policy` to enable a filter:

```c++
options.filter_policy = NewBloomFilterPolicy(10);
```

If the equivalence class of keys are custom (for instance, ignores all the trailing space in keys), you should also provide a custom filter that apply the same policy instead using the built-in `NewBloomFilterPolicy()`.



##### # Key Layout

Adjacent keys will usaully be placed in the same block. Thus the performance can be improved by placing keys frequently accessed together near each other, which requires careful design of the keyspace.








### 5. Checking Mechanism

`Options::paranoid_checks` and `ReadOptions::verify_checksums` provides corruption detection when opening a dastabaes and reading the data respectively:

```{.c++ .numberLines startFrom="54" filename="include/options.h"}
// If true, the implementation will do aggressive checking of the
// data it is processing and will stop early if it detects any
// errors.  This may have unforeseen ramifications: for example, a
// corruption of one DB entry may cause a large number of entries to
// become unreadable or for the entire DB to become unopenable.
bool paranoid_checks = false;
```

```{.c++ .numberLines startFrom="149" filename="include/options.h"}
// If true, all data read from underlying storage will be
// verified against corresponding checksums.
bool verify_checksums = false;
```

`leveldb::RepairDB` function may be used to recover as much data as possible if the database is corrupted.
