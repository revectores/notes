# leveldb Operation Processing

### 1. Get Operation

##### # `DBImpl::Get`

`DBImpl::Get` operation is processed as following steps:

- Create a snapshot of current state, this includes:
  - Define a `SequenceNumber snapshot`. The sequence number can be provided by user, if not, use the current sequence number `versions_->LastSequence`.
  - Save the current memtable `mem`, `imm` and version `current`.
- Try to find key in order:
  - memtable `mem ` and immutable memtable `imm`. Done by `Memtable::Get()`.
  - `sstable`. Done by `Version::Get()`. Note that searching key in `sstable` requires file seeking, which leads to a `Version::UpdateStats()` operation, and may raise seek compaction eventually.

```c++
Status DBImpl::Get(const ReadOptions& options, const Slice& key,
                   std::string* value) {
  Status s;
  MutexLock l(&mutex_);
  SequenceNumber snapshot;
  if (options.snapshot != nullptr) {
    snapshot =
        static_cast<const SnapshotImpl*>(options.snapshot)->sequence_number();
  } else {
    snapshot = versions_->LastSequence();
  }

  MemTable* mem = mem_;
  MemTable* imm = imm_;
  Version* current = versions_->current();
  mem->Ref();
  if (imm != nullptr) imm->Ref();
  current->Ref();

  bool have_stat_update = false;
  Version::GetStats stats;

  // Unlock while reading from files and memtables
  {
    mutex_.Unlock();
    // First look in the memtable, then in the immutable memtable (if any).
    LookupKey lkey(key, snapshot);
    if (mem->Get(lkey, value, &s)) {
      // Done
    } else if (imm != nullptr && imm->Get(lkey, value, &s)) {
      // Done
    } else {
      s = current->Get(options, lkey, value, &stats);
      have_stat_update = true;
    }
    mutex_.Lock();
  }

  if (have_stat_update && current->UpdateStats(stats)) {
    MaybeScheduleCompaction();
  }
  mem->Unref();
  if (imm != nullptr) imm->Unref();
  current->Unref();
  return s;
}
```



##### # `MemTable::Get`

`MemTable::Get` gets key from memtable. The searching work is done by `Table::Iterator::Seek()`, which is a `skiplist` operation. The main work it is done is validating whether the retrived key is indeed the key user provided, and then make proper action based on the `tag` of entry:

- Set `value` for `kTypeValue`.
- Set status to `NotFound` for `kTypeDeletion`.

In detail, since the length of key and value are encoded in [`varint`](), utils such as `GetVarint32Ptr` is invoked (`GetlengthPrefixedSlice` is a simple wrapper of `GetVarint32Ptr`).

```c++
bool MemTable::Get(const LookupKey& key, std::string* value, Status* s) {
  Slice memkey = key.memtable_key();
  Table::Iterator iter(&table_);
  iter.Seek(memkey.data());
  if (iter.Valid()) {
    // entry format is:
    //    klength  varint32
    //    userkey  char[klength]
    //    tag      uint64
    //    vlength  varint32
    //    value    char[vlength]
    // Check that it belongs to same user key.  We do not check the
    // sequence number since the Seek() call above should have skipped
    // all entries with overly large sequence numbers.
    const char* entry = iter.key();
    uint32_t key_length;
    const char* key_ptr = GetVarint32Ptr(entry, entry + 5, &key_length);
    if (comparator_.comparator.user_comparator()->Compare(
            Slice(key_ptr, key_length - 8), key.user_key()) == 0) {
      // Correct user key
      const uint64_t tag = DecodeFixed64(key_ptr + key_length - 8);
      switch (static_cast<ValueType>(tag & 0xff)) {
        case kTypeValue: {
          Slice v = GetLengthPrefixedSlice(key_ptr + key_length);
          value->assign(v.data(), v.size());
          return true;
        }
        case kTypeDeletion:
          *s = Status::NotFound(Slice());
          return true;
      }
    }
  }
  return false;
}
```



##### # `Version::Get`

`Version::Get` is basically a container of `struct State` definition. The core work is done in `ForEachOverlapping()` and `TableCache::Get()` inside callback function `State::Match`:

- `ForEachOverlapping(Slice user_key, Slice internal_key, void* arg, bool (*func)(void*, int, FileMetaData*))` calls `func(arg, level, f)` for every file that overlaps `user_key` in order from newest to oldest. If an invocation of `func` returns false, makes no more calls.

- `TableCache::Get(const ReadOptions& options, uint64_t file_number, uint64_t file_size, const Slice& k, void* arg, void (*handle_result)(void*, const Slice&, const Slice&))` calls `(*handle_result)(arg, found_key, found_value)` if a seek to internal key `k` in specified file finds an entry. File reading is exectued in this phase (in the subroutine `FindTable()`, to be specific).

  Specifically, here the callback function `SaveValue(void* arg, const Slice& ikey, const Slice& v)` receives the `struct Saver` as `arg` to fill the `key/value` pair to `state`.

```c++
Status Version::Get(const ReadOptions& options, const LookupKey& k,
                    std::string* value, GetStats* stats) {
  stats->seek_file = nullptr;
  stats->seek_file_level = -1;

  struct State {
    Saver saver;
    GetStats* stats;
    const ReadOptions* options;
    Slice ikey;
    FileMetaData* last_file_read;
    int last_file_read_level;

    VersionSet* vset;
    Status s;
    bool found;

    static bool Match(void* arg, int level, FileMetaData* f) {
      State* state = reinterpret_cast<State*>(arg);

      if (state->stats->seek_file == nullptr &&
          state->last_file_read != nullptr) {
        // We have had more than one seek for this read.  Charge the 1st file.
        state->stats->seek_file = state->last_file_read;
        state->stats->seek_file_level = state->last_file_read_level;
      }

      state->last_file_read = f;
      state->last_file_read_level = level;

      state->s = state->vset->table_cache_->Get(*state->options, f->number,
                                                f->file_size, state->ikey,
                                                &state->saver, SaveValue);
      if (!state->s.ok()) {
        state->found = true;
        return false;
      }
      switch (state->saver.state) {
        case kNotFound:
          return true;  // Keep searching in other files
        case kFound:
          state->found = true;
          return false;
        case kDeleted:
          return false;
        case kCorrupt:
          state->s =
              Status::Corruption("corrupted key for ", state->saver.user_key);
          state->found = true;
          return false;
      }

      // Not reached. Added to avoid false compilation warnings of
      // "control reaches end of non-void function".
      return false;
    }
  };

  State state;
  state.found = false;
  state.stats = stats;
  state.last_file_read = nullptr;
  state.last_file_read_level = -1;

  state.options = &options;
  state.ikey = k.internal_key();
  state.vset = vset_;

  state.saver.state = kNotFound;
  state.saver.ucmp = vset_->icmp_.user_comparator();
  state.saver.user_key = k.user_key();
  state.saver.value = value;

  ForEachOverlapping(state.saver.user_key, state.ikey, &state, &State::Match);

  return state.found ? state.s : Status::NotFound(Slice());
}
```







### 2. Write Operation

##### # Write Wrappers

`DBImpl::Put()` and `DBImpl::Delete()` operations are simple wrapper of `DBImpl::Write()`:

```c++
Status DBImpl::Put(const WriteOptions& o, const Slice& key, const Slice& val) {
  return DB::Put(o, key, val);
}

Status DBImpl::Delete(const WriteOptions& options, const Slice& key) {
  return DB::Delete(options, key);
}
```

```c++
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

That is, any single `Put` and `Delete` operation is packed as a `WriteBatch` internally.







##### # `DBImpl::Write`

Each write operation to leveldb will be added into a `std::deque<Writer*> writers_`, and all of (except premature break due to `sync` write or oversize of group) the writers in deque will be grouped to build a "batched batch" `WriteBatch* write_batch` to write until the previous batch group writing is done.

In detail, steps to execute `DBImpl::Write`:

- Construct a new `Writer` object that contains batch `updates` given by user.
- If the writer has not become the first element in the deque, wait. This state may be caused by
  - The previous group writing has not been done.
  - The previous group writing has been done, but current writer is not the first element of the current writer group.
- For the latter case, the `done` flag will be set by the front writer by `ready->done = true` and be weaken by `ready->cv.Signal()` and returned immediately. Otherwise, if the writer happens to be the front, do the works below.
- Do some preprocessing inside `MakeRoomForWrite()` to make sure the database is ready for new writes.
- Iterator writers in `writers_` to build a grouped batch `write_batch` inside `BuildBatchGroup()`.
- Write-ahead logging `Writer::AddRecord()`
- Insert `write_batch` to `mem_`. Implemented by `WriteBatchInternal::InsertInto(write_batch, mem_)`.
- Send notifications to writers in waiting.

```c++
Status DBImpl::Write(const WriteOptions& options, WriteBatch* updates) {
  Writer w(&mutex_);
  w.batch = updates;
  w.sync = options.sync;
  w.done = false;

  MutexLock l(&mutex_);
  writers_.push_back(&w);
  while (!w.done && &w != writers_.front()) {
    w.cv.Wait();
  }
  if (w.done) {
    return w.status;
  }

  // May temporarily unlock and wait.
  Status status = MakeRoomForWrite(updates == nullptr);
  uint64_t last_sequence = versions_->LastSequence();
  Writer* last_writer = &w;
  if (status.ok() && updates != nullptr) {  // nullptr batch is for compactions
    WriteBatch* write_batch = BuildBatchGroup(&last_writer);
    WriteBatchInternal::SetSequence(write_batch, last_sequence + 1);
    last_sequence += WriteBatchInternal::Count(write_batch);

    // Add to log and apply to memtable.  We can release the lock
    // during this phase since &w is currently responsible for logging
    // and protects against concurrent loggers and concurrent writes
    // into mem_.
    {
      mutex_.Unlock();
      status = log_->AddRecord(WriteBatchInternal::Contents(write_batch));
      bool sync_error = false;
      if (status.ok() && options.sync) {
        status = logfile_->Sync();
        if (!status.ok()) {
          sync_error = true;
        }
      }
      if (status.ok()) {
        status = WriteBatchInternal::InsertInto(write_batch, mem_);
      }
      mutex_.Lock();
      if (sync_error) {
        // The state of the log file is indeterminate: the log record we
        // just added may or may not show up when the DB is re-opened.
        // So we force the DB into a mode where all future writes fail.
        RecordBackgroundError(status);
      }
    }
    if (write_batch == tmp_batch_) tmp_batch_->Clear();

    versions_->SetLastSequence(last_sequence);
  }

  while (true) {
    Writer* ready = writers_.front();
    writers_.pop_front();
    if (ready != &w) {
      ready->status = status;
      ready->done = true;
      ready->cv.Signal();
    }
    if (ready == last_writer) break;
  }

  // Notify new head of write queue
  if (!writers_.empty()) {
    writers_.front()->cv.Signal();
  }

  return status;
}
```

