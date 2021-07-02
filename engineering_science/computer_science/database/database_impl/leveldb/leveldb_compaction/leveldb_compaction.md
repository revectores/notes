# leveldb Compaction

### 1. Class Definition

##### # `Version`

To avoid disabling data access incidentially caused by compaction (i.e. during an iteration), version system is designed and embedded to the compaction module.

A `Version` is a snapshot of database maintaining list of files' metadata in `files[config::kNumLevels]`:

`Version` object, as well as `FileMetaData`, use reference conuting to track whether itself (version/file) is active. `sstable` delection caused by compaction is deferred until the reference counting of the corresponding `FileMetaData` decreases to 0, this become true iff all versions points to it become inactive.

In addition to the file metadata and reference counting there are some other types of member, summarized below:

|                            Member                            |                        Interpretation                        |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
|                           `files_`                           |               `sstable` list for that version                |
|                           `refs_`                            |                      reference counting                      |
|                  `vset_`, `next_`, `prev_`                   |            `VersionSet` doubly-link list support             |
| `file_to_compact_`, `file_to_comapct_level`, `compaction_score`, `compaction_level_` | Score and pointer used for size compaction and seek compaction |

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

A new `Version` can be constructed from a `VersionSet`, and it will regard itself as the only version in the `VersionSet` (`next_(this)`, `prev_(this)`):

```c++
  explicit Version(VersionSet* vset)
      : vset_(vset),
        next_(this),
        prev_(this),
        refs_(0),
        file_to_compact_(nullptr),
        file_to_compact_level_(-1),
        compaction_score_(-1),
        compaction_level_(-1) {}
```

but this is only an temporary illusion: there may be other existed doubly-link list, and usually the new version will be added to that list later by `VersionSet::AppendVersion(Version* v)`:

```c++
void VersionSet::AppendVersion(Version* v) {
  // Make "v" current
  assert(v->refs_ == 0);
  assert(v != current_);
  if (current_ != nullptr) {
    current_->Unref();
  }
  current_ = v;
  v->Ref();

  // Append to linked list
  v->prev_ = dummy_versions_.prev_;
  v->next_ = &dummy_versions_;
  v->prev_->next_ = v;
  v->next_->prev_ = v;
}
```



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



##### # `VersionEdit`

`VersionEdit` is the entity modeling `diff` bewteen `Version`. When applying a compaction, a `VersionEdit` object is built at first and applied to current `Version` to get the new version after compaction:

|                       Member Variables                       |                        Interpretation                        |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
|      `compact_pointers`, `deleted_files_`, `new_files_`      | modifications on current version, computed by consuming `Compaction` object. |
| `comparator_`, `log_number_`, `prev_log_number_`, `next_file_number`, `last_sequence_` |                  version state information                   |
| `has_comparator_`, `has_log_number_`, `has_prev_log_number_`, `has_next_file_number_`, `has_last_sequence_` |    flags to indicate whether the state information valid     |

```c++
class VersionEdit {
private:
  typedef std::set<std::pair<int, uint64_t>> DeletedFileSet;

  std::string comparator_;
  uint64_t log_number_;
  uint64_t prev_log_number_;
  uint64_t next_file_number_;
  SequenceNumber last_sequence_;
  bool has_comparator_;
  bool has_log_number_;
  bool has_prev_log_number_;
  bool has_next_file_number_;
  bool has_last_sequence_;

  std::vector<std::pair<int, InternalKey>> compact_pointers_;
  DeletedFileSet deleted_files_;
  std::vector<std::pair<int, FileMetaData>> new_files_;
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

- If the compaction is manually invoked, use `CompactRange()` to search for those `sstable` based on `level`, `begin`, `end` provided by user. Refer to [5. Search Tables in Given Range](#5. Search Tables in Given Range) for details of `CompactRange()`.
- If the compaction is automatically inovked, use `PickCompaction()` to search for the best level to compact. Refer to [6. Pick Tables to Compact](#6. Pick Tables to Compact) for details of `PickCompaction()`.

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

The magic part is `DoCompactionWork()`: It merge all `sstable` in `inputs_[2]` based on merge sort. Refer to [7. Merge Tables](#7. Merge Tables) for details of `DoCompactionWork()`. Inside it `InstallCompactionResults()` is invoked where `LogAndApply()` is finally to executed to apply the `VersionEdit` to current `version`. Refer to [8. Apply and Log VersionEdit](#8. Apply and Log VersionEdit) for details.







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

Now we can finally translate `v->compaction_score_ >= 1` to human language:

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

which keeps the `file_to_compact_` and `file_to_compact_level_` up-to-date.







### 4. Minor Compaction

Minor compaction is done by method `CompactMemTable()`. Here the two invocation `WriteLevel0Table()` and `LogAndApply()` are the core:

- `WriteLevel0Table()` **write** `sstable` file and returns `VersionEdit` object.
- `LogAndApply()` apply the `VersionEdit` object to current version. This function is also called during major compaction. Refer to [8. Apply and Log VersionEdit](#8. Apply and Log VersionEdit) for details.

Note that the `LogAndApply()` does NOT interact with external stroage at all: it only apply those abstract objects `VersionEdit` and `Version`.

In addition some cleaning stuff will be done in `RemoveObsoleteFiles()`. This function is also called during major compaction.

```c++
void DBImpl::CompactMemTable() {
  VersionEdit edit;
  Version* base = versions_->current();
	WriteLevel0Table(imm_, &edit, base);
  versions_->LogAndApply(&edit, &mutex_);
  RemoveObsoleteFiles();
}
```

`WriteLevel0Table()` build a `Iterator` and pass it to `BuildTable()`, which iterates key-value pair to write a `sstable` file (some information that helps to build `edit` is also collected inside).

Different from the theoretical LSM-tree design, leveldb try to upgrade the newly generated `sstable` to higher level. Which level the new table should be placed is determined by `PickLevelForMemTableOutput()`.

Final work is to make up the `edit` based on level and collected metadata to feed to caller `CompactMemTable()`.

```c++
Status DBImpl::WriteLevel0Table(MemTable* mem, VersionEdit* edit, Version* base){
	Iterator* iter = mem->NewIterator();
	BuildTable(dbname_, env_, options_, table_cache_, iter, &meta);
	level = base->PickLevelForMemTableOutput(min_user_key, max_user_key);
	edit->AddFile(level, meta.number, meta.file_size, meta.smallest, meta.largest);
}
```

The core of `BuildTable()` is building the `builder` by iterating `iter` to emit key-value pairs:

```c++
TableBuilder* builder = new TableBuilder(options, file);
for (; iter->Valid(); iter->Next()) {
  key = iter->key();
  builder->Add(key, iter->value());
}
s = builder->Finish();
```

Writing stuff is done inside `build->Finish()`.







### 5. Search Tables in Given Range

When the compaction is inovked manually, `CompactRange` searches those `sstable` in given level which are overlapped with range `[begin, end]` by three steps:

1. `GetOverlappingInputs` to get the set of `sstable` which are overlapped with range `[begin, end]`, store them in `std::vector<FileMetaData*> inputs`.
2. Reduce number of file to compact for levels ≥ 1. The limit is set to `max_file_size = 2 * 1024 * 1024`, which is configurable.
3. Search for those `sstables` which are overlapped with `inputs_[0]` in the upper level, this make up `inputs_[1]`.

```c++
Compaction* VersionSet::CompactRange(int level, const InternalKey* begin,
                                     const InternalKey* end) {
  std::vector<FileMetaData*> inputs;
  current_->GetOverlappingInputs(level, begin, end, &inputs);
  if (inputs.empty()) {
    return nullptr;
  }

  // Avoid compacting too much in one shot in case the range is large.
  // But we cannot do this for level-0 since level-0 files can overlap
  // and we must not pick one file and drop another older file if the
  // two files overlap.
  if (level > 0) {
    const uint64_t limit = MaxFileSizeForLevel(options_, level);
    uint64_t total = 0;
    for (size_t i = 0; i < inputs.size(); i++) {
      uint64_t s = inputs[i]->file_size;
      total += s;
      if (total >= limit) {
        inputs.resize(i + 1);
        break;
      }
    }
  }

  Compaction* c = new Compaction(options_, level);
  c->input_version_ = current_;
  c->input_version_->Ref();
  c->inputs_[0] = inputs;
  SetupOtherInputs(c);
  return c;
}
```







### 6. Pick Tables to Compact

When the compaction is invoked automatically, `PickCompaction` is called to determine which level and which file should be compact in the highest priority:

As we've quantified in [3. Preconditions of Compaction](#3. Preconditions of Compaction), there are two trigger of compaction:

- **Size Compaction**, when the total size of level (for level ≥ 1) or the total file number of level (for level-0) overflows.
- **Seek Compaction**, when the seek quota of a file run outs.

Between this two kinds of compaction `size_compaction` has the higher priority.

Note that the compaction in specific level is **rotating**: `compact_pointer_[level]` memorizes the key where the range of last compaction ends, which is used as the start of this compaction.

The implementation of level-0 compaction is different what the `doc/impl.md` file declare:

```markdown
When the number of young files exceeds a certain threshold (currently four), all of the young files are merged together with all of the overlapping level-1 files to produce a sequence of new level-1 files (we create a new level-1 file for every 2MB of data.)
```

Actually not all the young files are merged, but those overlapped with the rotating picked one.

```c++
Compaction* VersionSet::PickCompaction() {
  Compaction* c;
  int level;

  // We prefer compactions triggered by too much data in a level over
  // the compactions triggered by seeks.
  const bool size_compaction = (current_->compaction_score_ >= 1);
  const bool seek_compaction = (current_->file_to_compact_ != nullptr);
  if (size_compaction) {
    level = current_->compaction_level_;
    assert(level >= 0);
    assert(level + 1 < config::kNumLevels);
    c = new Compaction(options_, level);

    // Pick the first file that comes after compact_pointer_[level]
    for (size_t i = 0; i < current_->files_[level].size(); i++) {
      FileMetaData* f = current_->files_[level][i];
      if (compact_pointer_[level].empty() ||
          icmp_.Compare(f->largest.Encode(), compact_pointer_[level]) > 0) {
        c->inputs_[0].push_back(f);
        break;
      }
    }
    if (c->inputs_[0].empty()) {
      // Wrap-around to the beginning of the key space
      c->inputs_[0].push_back(current_->files_[level][0]);
    }
  } else if (seek_compaction) {
    level = current_->file_to_compact_level_;
    c = new Compaction(options_, level);
    c->inputs_[0].push_back(current_->file_to_compact_);
  } else {
    return nullptr;
  }

  c->input_version_ = current_;
  c->input_version_->Ref();

  // Files in level 0 may overlap each other, so pick up all overlapping ones
  if (level == 0) {
    InternalKey smallest, largest;
    GetRange(c->inputs_[0], &smallest, &largest);
    // Note that the next call will discard the file we placed in
    // c->inputs_[0] earlier and replace it with an overlapping set
    // which will include the picked file.
    current_->GetOverlappingInputs(0, &smallest, &largest, &c->inputs_[0]);
    assert(!c->inputs_[0].empty());
  }

  SetupOtherInputs(c);

  return c;
}
```







### 7. Merge Tables

`DoCompactionWork` do the following works:

- Construct an iterator `input` from `FileMetaData*` in `Compaction` object.

- Iterate the key value pair in `input` to build the `compact->builder`.

  Note that some old and deleted data could be dropped.

- Call `FinishCompactionOutputFile()` to write `sstable` file when the iteration is completed or key value buffers inside `compact->build` reaches one of the two thresholds:

  - The file size reaches the limit `MaxOutputFileSize`.
  - The overlap bytes with grandparent level reaches the limit `MaxGrandParentOverlapBytes`. This checking is done inside `compact->compaction->ShouldStopBefore(key)`.

  The physical file writing work is done by invoking `compact->build->Finish()` inside `FinishCompactionOutputFile()`.

- Call `InstallCompactionResults()` to call `LogAndApply()` to apply `compact->compaction->edit()` to current version. Refer to [8. Apply and Log VersionEdit](#8. Apply and Log VersionEdit) for details.

```c++
Status DBImpl::DoCompactionWork(CompactionState* compact) {
  Iterator* input = versions_->MakeInputIterator(compact->compaction);
  input->SeekToFirst();

  ParsedInternalKey ikey;
  std::string current_user_key;
  bool has_current_user_key = false;
  SequenceNumber last_sequence_for_key = kMaxSequenceNumber;

  while (input->Valid()) {
    if (imm_ != nullptr) CompactMemTable();
    Slice key = input->key();
    if (compact->compaction->ShouldStopBefore(key) &&
        compact->builder != nullptr) {
      FinishCompactionOuuputFile(compact, input);
    }

    // Handle key/value, add to state, etc.
    bool drop = false;
    ParseInternalKey(key, &ikey)
    if (!has_current_user_key ||
        user_comparator()->Compare(ikey.user_key, Slice(current_user_key)) != 0) {
      // First occurrence of this user key
      current_user_key.assign(ikey.user_key.data(), ikey.user_key.size());
      has_current_user_key = true;
      last_sequence_for_key = kMaxSequenceNumber;
    }

    if (last_sequence_for_key <= compact->smallest_snapshot) {
      // Hidden by an newer entry for same user key
      drop = true;  // (A)
    } else if (ikey.type == kTypeDeletion &&
               ikey.sequence <= compact->smallest_snapshot &&
               compact->compaction->IsBaseLevelForKey(ikey.user_key)) {
      // For this user key:
      // (1) there is no data in higher levels
      // (2) data in lower levels will have larger sequence numbers
      // (3) data in layers that are being compacted here and have
      //     smaller sequence numbers will be dropped in the next
      //     few iterations of this loop (by rule (A) above).
      // Therefore this deletion marker is obsolete and can be dropped.
      drop = true;
    }

    last_sequence_for_key = ikey.sequence;

    if (!drop) {
      // Open output file if necessary
      if (compact->builder == nullptr) {
        OpenCompactionOutputFile(compact);
      }
      if (compact->builder->NumEntries() == 0) {
        compact->current_output()->smallest.DecodeFrom(key);
      }
      compact->current_output()->largest.DecodeFrom(key);
      compact->builder->Add(key, input->value());

      // Close output file if it is big enough
      if (compact->builder->FileSize() >= compact->compaction->MaxOutputFileSize()) {
        FinishCompactionOutputFile(compact, input);
      }
    }
    input->Next();
  }

	FinishCompactionOutputFile(compact, input);
  InstallCompactionResults(compact);
}
```







### 8. Apply and Log VersionEdit

##### # `VersionSet::LogAndApply`

Two responsibility of `VersionSert::LogAndApply`:

- Create a new version by applying `VersionEdit` to current version.
- Append records to `MANIFEST`.

The `VersionEdit` applying is done with the help of `VersionSet::Builder`:

```c++
Version* v = new Version(this);
{
	Builder builder(this, current_);
	builder.Apply(edit);
	builder.SaveTo(v);
}
Finalize(v);
```

where

- `VersionSet::Builder::Apply` consumes information provided in `edit` to make up necessary member variables of `Builder`. No interaction with the base version `base_`.
- `VersionSet::Builder::SaveTo` actually "apply" consumed information to base version `base_` and made the new version `v`.
- `VersionSet::Finalize` compute `compaction_level_` and `compaction_score_` for the next compaction.



##### # `VersionSet::Builder:Apply`

`VersionSet::Builder::Apply` convert paired-structured information provided in `VersionEdit` into level-indexed information in `Version::Builder`. Specifically:

|                      `VersionEdit` data                      |                `Version::Builder` data                |
| :----------------------------------------------------------: | :---------------------------------------------------: |
| `std::vector<std::pair<int, InternalKey>> compact_pointers_` |   `std::string compact_pointer[config::kNumLevels]`   |
|     `std::set<std::pair<int, uint64_t>> deleted_files_`      |          `std::set<uint64_t> deleted_files`           |
|    `std::vector<std::pair<int, FileMetaData>> new_files_`    | `std::set<FileMetaData*, BySmallestKey>* added_files` |

Convertion of `compact_pointer(s)` and `deleted_files` are trivial (and maybe optimizable). Creating new `FileMetaData` when converting `new_files_` to `add_files` seems to be a waste but not so much since `FileMetaData` is a simple `struct` (with two `InternalKey` though).

```c++
void Apply(VersionEdit* edit) {
  // Update compaction pointers
  for (size_t i = 0; i < edit->compact_pointers_.size(); i++) {
    const int level = edit->compact_pointers_[i].first;
    vset_->compact_pointer_[level] =
      edit->compact_pointers_[i].second.Encode().ToString();
  }

  // Delete files
  for (const auto& deleted_file_set_kvp : edit->deleted_files_) {
    const int level = deleted_file_set_kvp.first;
    const uint64_t number = deleted_file_set_kvp.second;
    levels_[level].deleted_files.insert(number);
  }

  // Add new files
  for (size_t i = 0; i < edit->new_files_.size(); i++) {
    const int level = edit->new_files_[i].first;
    FileMetaData* f = new FileMetaData(edit->new_files_[i].second);
    f->refs = 1;

    // We arrange to automatically compact this file after
    // a certain number of seeks.  Let's assume:
    //   (1) One seek costs 10ms
    //   (2) Writing or reading 1MB costs 10ms (100MB/s)
    //   (3) A compaction of 1MB does 25MB of IO:
    //         1MB read from this level
    //         10-12MB read from next level (boundaries may be misaligned)
    //         10-12MB written to next level
    // This implies that 25 seeks cost the same as the compaction
    // of 1MB of data.  I.e., one seek costs approximately the
    // same as the compaction of 40KB of data.  We are a little
    // conservative and allow approximately one seek for every 16KB
    // of data before triggering a compaction.
    f->allowed_seeks = static_cast<int>((f->file_size / 16384U));
    if (f->allowed_seeks < 100) f->allowed_seeks = 100;

    levels_[level].deleted_files.erase(f->number);
    levels_[level].added_files->insert(f);
  }
}
```

The design and quantization of `allowed_seeks` is provided in the comments above.



##### # `VersionSet::Builder::SaveTo`

Now the real solid work: `Version` construction! The core idea is simple: iterate `base_files` and `added_files` to collect all `FileMetaData` which are not `deleted` (that is, not shown in `deleted_files`). The implementation is a bit more confusing since each level in `std::vector<FileMetaData*> files_[config::kNumLevels]` in `Version` is required to be ordered.

```c++
void SaveTo(Version* v) {
  BySmallestKey cmp;
  cmp.internal_comparator = &vset_->icmp_;
  for (int level = 0; level < config::kNumLevels; level++) {
    // Merge the set of added files with the set of pre-existing files.
    // Drop any deleted files.  Store the result in *v.
    const std::vector<FileMetaData*>& base_files = base_->files_[level];
    std::vector<FileMetaData*>::const_iterator base_iter = base_files.begin();
    std::vector<FileMetaData*>::const_iterator base_end = base_files.end();
    const FileSet* added_files = levels_[level].added_files;
    v->files_[level].reserve(base_files.size() + added_files->size());
    for (const auto& added_file : *added_files) {
      // Add all smaller files listed in base_
      for (std::vector<FileMetaData*>::const_iterator bpos =
           std::upper_bound(base_iter, base_end, added_file, cmp);
           base_iter != bpos; ++base_iter) {
        MaybeAddFile(v, level, *base_iter);
      }

      MaybeAddFile(v, level, added_file);
    }

    // Add remaining base files
    for (; base_iter != base_end; ++base_iter) {
      MaybeAddFile(v, level, *base_iter);
    }
  }
}

void MaybeAddFile(Version* v, int level, FileMetaData* f) {
  if (levels_[level].deleted_files.count(f->number) > 0) {
    // File is deleted: do nothing
  } else {
    std::vector<FileMetaData*>* files = &v->files_[level];
    if (level > 0 && !files->empty()) {
      // Must not overlap
      assert(vset_->icmp_.Compare((*files)[files->size() - 1]->largest,
                                  f->smallest) < 0);
    }
    f->refs++;
    files->push_back(f);
  }
}
```



##### # Append New Records to `MANIFEST`

After the version applying work, we write `VersionEdit` to `MANIFEST` (note that since `MANIFEST` file is formatted as a log, hence we write the incremental `VersionEdit` instead of entire `Version`). If the `MANIFEST` file `descriptor_log_` does not avaliable, we create one.

```c++
Status VersionSet::LogAndApply(VersionEdit* edit, port::Mutex* mu) {
	// [Apply VersionEdit to Version]

  // Initialize new descriptor log file if necessary by creating
  // a temporary file that contains a snapshot of the current version.
  std::string new_manifest_file;
  Status s;
  if (descriptor_log_ == nullptr) {
    // No reason to unlock *mu here since we only hit this path in the
    // first call to LogAndApply (when opening the database).
    new_manifest_file = DescriptorFileName(dbname_, manifest_file_number_);
    edit->SetNextFile(next_file_number_);
    env_->NewWritableFile(new_manifest_file, &descriptor_file_);
    descriptor_log_ = new log::Writer(descriptor_file_);
    WriteSnapshot(descriptor_log_);
  }

  {
    // Write new record to MANIFEST log
    std::string record;
    edit->EncodeTo(&record);
    descriptor_log_->AddRecord(record);
    descriptor_file_->Sync();

    // If we just created a new descriptor file, install it by writing a
    // new CURRENT file that points to it.
    if (!new_manifest_file.empty()) {
      s = SetCurrentFile(env_, dbname_, manifest_file_number_);
    }
  }

  // Install the new version
  AppendVersion(v);
  log_number_ = edit->log_number_;
  prev_log_number_ = edit->prev_log_number_;
}
```

