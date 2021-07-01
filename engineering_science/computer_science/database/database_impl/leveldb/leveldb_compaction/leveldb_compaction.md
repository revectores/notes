# leveldb Versions and Compaction

### 1. Class Definition

##### # `Version`

To avoid incidential disabling data access (i.e. during an iteration) caused by compaction, version system is designed and embedded to the compaction module.

A `Version` snapshots database by maintaining list of files per level in `files[config::kNumLevels]`:

```{.c++ filename="db/version_set.h"}
class Version {
private:
  VersionSet* vset_;  // VersionSet to which this Version belongs
  Version* next_;     // Next version in linked list
  Version* prev_;     // Previous version in linked list
  int refs_;          // Number of live refs to this version

  // List of files per level
  std::vector<FileMetaData*> files_[config::kNumLevels];

  // Next file to compact based on seek stats.
  FileMetaData* file_to_compact_;
  int file_to_compact_level_;

  // Level that should be compacted next and its compaction score.
  // Score < 1 means compaction is not strictly needed.  These fields
  // are initialized by Finalize().
  double compaction_score_;
  int compaction_level_;
};
```

`Version` object, as well as `FileMetaData`, use reference conuting to track whether the object is active. `sstable` delection raised by compaction is deferred until the reference counting of the corresponding `FileMetaData` decreases to 0, this become true iff all versions points to it become inactive.



##### # `VersionSet`

`VersionSet` manages all active versions in a doubly-linked list, with current version `current_` in the end (`dummy_versions_.prev_`):

```{.c++ filename="db/version_set.h"}
class VersionSet {
private:
  Env* const env_;
  const std::string dbname_;
  const Options* const options_;
  TableCache* const table_cache_;
  const InternalKeyComparator icmp_;
  uint64_t next_file_number_;
  uint64_t manifest_file_number_;
  uint64_t last_sequence_;
  uint64_t log_number_;
  uint64_t prev_log_number_;  // 0 or backing store for memtable being compacted

  // Opened lazily
  WritableFile* descriptor_file_;
  log::Writer* descriptor_log_;
  Version dummy_versions_;  // Head of circular doubly-linked list of versions.
  Version* current_;        // == dummy_versions_.prev_

  // Per-level key at which the next compaction at that level should start.
  // Either an empty string, or a valid InternalKey.
  std::string compact_pointer_[config::kNumLevels];
};
```

In addition `VersionSet` manage multiple global information of the database, `next_file_number_`, `manifest_file_number_`, for instance.



##### # `Compaction`

Information about compation is encapsulated in `class Compaction`:

```{.c++ filename="db/version_set.h"}
class Compaction {
private:
  int level_;
  uint64_t max_output_file_size_;
  Version* input_version_;
  VersionEdit edit_;

  // Each compaction reads inputs from "level_" and "level_+1"
  std::vector<FileMetaData*> inputs_[2];  // The two sets of inputs

  // State used to check for number of overlapping grandparent files
  // (parent == level_ + 1, grandparent == level_ + 2)
  std::vector<FileMetaData*> grandparents_;
  size_t grandparent_index_;  // Index in grandparent_starts_
  bool seen_key_;             // Some output key has been seen
  int64_t overlapped_bytes_;  // Bytes of overlap between current output
                              // and grandparent files

  // State for implementing IsBaseLevelForKey

  // level_ptrs_ holds indices into input_version_->levels_: our state
  // is that we are positioned at one of the file ranges for each
  // higher level than the ones involved in this compaction (i.e. for
  // all L >= level_ + 2).
  size_t level_ptrs_[config::kNumLevels];
}
```







### 2. Compaction Implementation: An Overview

Any compaction starts from `DBImpl::MaybeScheduleCompaction`, with some checking.

```c++
void DBImpl::MaybeScheduleCompaction() {
  mutex_.AssertHeld();
  if (background_compaction_scheduled_) {
    // Already scheduled
  } else if (shutting_down_.load(std::memory_order_acquire)) {
    // DB is being deleted; no more background compactions
  } else if (!bg_error_.ok()) {
    // Already got an error; no more changes
  } else if (imm_ == nullptr && manual_compaction_ == nullptr &&
             !versions_->NeedsCompaction()) {
    // No work to be done
  } else {
    background_compaction_scheduled_ = true;
    env_->Schedule(&DBImpl::BGWork, this);
  }
}
```

Refer to [3. Preconditions of Compaction](#3. Preconditions of Compaction) for the details of `versions_->NeedsCompaction()`.

If we pass all the checkings, `BGWork` will be scheduled, which is a wrapper of `BackgroundCall()`:

```c++
void DBImpl::BGWork(void* db) {
  reinterpret_cast<DBImpl*>(db)->BackgroundCall();
}
```

Since the background work may be delayed, some checking are repeated in `BackgroundCall()`, and then call `BackgroundCompaction()`.

```c++
void DBImpl::BackgroundCall() {
  MutexLock l(&mutex_);
  assert(background_compaction_scheduled_);
  if (shutting_down_.load(std::memory_order_acquire)) {
    // No more background work when shutting down.
  } else if (!bg_error_.ok()) {
    // No more background work after a background error.
  } else {
    BackgroundCompaction();
  }

  background_compaction_scheduled_ = false;

  // Previous compaction may have produced too many files in a level,
  // so reschedule another compaction if needed.
  MaybeScheduleCompaction();
  background_work_finished_signal_.SignalAll();
}
```

Hard-core work starts from `BackgroundCompaction()`. The minor compaction has the highest priority:

```c++
if (imm_ != nullptr) {
  CompactMemTable();
  return;
}
```

Refer to [4. Minor Compaction](#4. Minor Compaction) for details of `CompactMemTable()`.

otherwise we generate the compaction:

- If the compaction is manually invoked, use `CompactRange()` to search for those `sstable` based on `level`, `begin`, `end` provided by user. Refer to [5. Search Tables in Given Range](#5. Search Table in Given Range) for details of `CompactRange()`.
- If the compaction is automatically inovked, use `PickCompaction()` to search for the best level to compact. Refer to [6. Rules of Picking Compaction](#6. Rules of Picking Compaction) for details of `PickCompaction()`.

```c++
Compaction* c;
bool is_manual = (manual_compaction_ != nullptr);
InternalKey manual_end;
if (is_manual) {
  ManualCompaction* m = manual_compaction_;
  c = versions_->CompactRange(m->level, m->begin, m->end);
  m->done = (c == nullptr);
} else {
  c = versions_->PickCompaction();
}
```

After the `Compaction` object `c` is generated, we execute the compaction, note that a **trivial move** can be made as a shortcut if the result of compaction simply moves one file from level-L to level-(L+1):

```c++
bool Compaction::IsTrivialMove() const {
  const VersionSet* vset = input_version_->vset_;
  // Avoid a move if there is lots of overlapping grandparent data.
  // Otherwise, the move could create a parent file that will require
  // a very expensive merge later on.
  return (num_input_files(0) == 1 && num_input_files(1) == 0 &&
          TotalFileSize(grandparents_) <=
              MaxGrandParentOverlapBytes(vset->options_));
}
```

```c++
Status status;
if (c == nullptr) {
  // Nothing to do
} else if (!is_manual && c->IsTrivialMove()) {
  // Move file to next level
  assert(c->num_input_files(0) == 1);
  FileMetaData* f = c->input(0, 0);
  c->edit()->RemoveFile(c->level(), f->number);
  c->edit()->AddFile(c->level() + 1, f->number, f->file_size, f->smallest,
                     f->largest);
  status = versions_->LogAndApply(c->edit(), &mutex_);
  if (!status.ok()) {
    RecordBackgroundError(status);
  }
} else {
  CompactionState* compact = new CompactionState(c);
  status = DoCompactionWork(compact);
  if (!status.ok()) {
    RecordBackgroundError(status);
  }
  CleanupCompaction(compact);
  c->ReleaseInputs();
  RemoveObsoleteFiles();
}
```

The magic part is `DoCompactionWork()`: It merge all `sstable` in `inputs_[2]` based on merge sort. Inside `InstallCompactionResults()` is invoked where `LogAndApply()` is finally to executed to apply the `VersionEdit` to current version.







### 3. Preconditions of Compaction

Review our very beginning of compaction `MaybeScheduleCompaction`:

```c++
void DBImpl::MaybeScheduleCompaction() {
  mutex_.AssertHeld();
  if (background_compaction_scheduled_) {
    // Already scheduled
  } else if (shutting_down_.load(std::memory_order_acquire)) {
    // DB is being deleted; no more background compactions
  } else if (!bg_error_.ok()) {
    // Already got an error; no more changes
  } else if (imm_ == nullptr && manual_compaction_ == nullptr &&
             !versions_->NeedsCompaction()) {
    // No work to be done
  } else {
    background_compaction_scheduled_ = true;
    env_->Schedule(&DBImpl::BGWork, this);
  }
}
```

The most notable condition `versions_->NeedsCompaction()` checks whether one of the compaction condition is checked in the current version:

```c++
bool NeedsCompaction() const {
  Version* v = current_;
  return (v->compaction_score_ >= 1) || (v->file_to_compact_ != nullptr);
}
```

where the `compaction_score_` is initialized in `Finalize()` (which is invoked only in `LogAndApply` and `Recover`, that is, whether after the compaction or after recovering, these are the only chances to modify the files):

```c++
void VersionSet::Finalize(Version* v) {
  // Precomputed best level for next compaction
  int best_level = -1;
  double best_score = -1;

  for (int level = 0; level < config::kNumLevels - 1; level++) {
    double score;
    if (level == 0) {
      // We treat level-0 specially by bounding the number of files
      // instead of number of bytes for two reasons:
      //
      // (1) With larger write-buffer sizes, it is nice not to do too
      // many level-0 compactions.
      //
      // (2) The files in level-0 are merged on every read and
      // therefore we wish to avoid too many files when the individual
      // file size is small (perhaps because of a small write-buffer
      // setting, or very high compression ratios, or lots of
      // overwrites/deletions).
      score = v->files_[level].size() /
              static_cast<double>(config::kL0_CompactionTrigger);
    } else {
      // Compute the ratio of current size to size limit.
      const uint64_t level_bytes = TotalFileSize(v->files_[level]);
      score =
          static_cast<double>(level_bytes) / MaxBytesForLevel(options_, level);
    }

    if (score > best_score) {
      best_level = level;
      best_score = score;
    }
  }

  v->compaction_level_ = best_level;
  v->compaction_score_ = best_score;
}
```

By trancing into `VersionSet::Finalize()` we can finally translate `v->compaction_score_ >= 1` to human language:

- If the number of files in level-0 ≥ kL0_CompactionTrigger (4 by default).
- If the total size of files in level-L  ≥ MaxBytesForLevel ($10^L$ MB by default).

On the other side of `||`, `file_to_compact` is updated in each `DBImpl::Get()`:

```c++
bool Version::UpdateStats(const GetStats& stats) {
  FileMetaData* f = stats.seek_file;
  if (f != nullptr) {
    f->allowed_seeks--;
    if (f->allowed_seeks <= 0 && file_to_compact_ == nullptr) {
      file_to_compact_ = f;
      file_to_compact_level_ = stats.seek_file_level;
      return true;
    }
  }
  return false;
}
```

which keeps the `file_to_compact_` up-to-date.
