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

