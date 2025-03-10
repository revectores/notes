# leveldb Implemetation

Each database is represented by a set of files stored in a directory. There are several different types of files:

- `.log`
- `.ldb`
- Supporting Files
  - `MANIFEST`
  - `CURRENT`
  - `LOG` and `LOG.old`
  - Other supporting files



### 1. Log Files

A **log file(.log)** stores a sequence of recent updates. Each updates is appended to the current log file. When the log file reaches a pre-determined size (approximately 4MB by default), it is converted to a sorted table(.ldb) and a new log file is created for future updates, this process is called **minor compaction**.

A copy of the current log file is kept in an in-memory structure (i.e. `memtable`).







### 2. Sorted Tables

A **sorted table(.ldb)** stores a sequence of entries sorted by key. Each entry is either a value or a delete marker for the key.

The set of sorted tables are organized into a sequence of levels, named level-0, level-1, ..., level-L respectively. Only files in level-0 are permitted to contain overlapping keys.

The sorted table generated from a log file is placed in level-0. **Major compaction** is executed under specific condition:

- For level-0, when the number of level-0 files exceeds a certain threshold (currently, four), **all** of the young files are merged together with all of the overlapping level-1 files to produce a sequence of new level-1 files (2MB for each file).
- For upper level-L where L ≥ 1, when the total size of level-L exceeds $10^L$ MB, **one** of the file in level-L and all of the overlapping level-(L+1) files are merged to form a set of new files for level-(L+1) (2MB for each file).

In addition to reaching 2MB limit, we also switch to a new output file when the key range of the current output file has grown enough to overlap more than **10** level-(L+2) files (You can imagine what kinds of information must be maintain to achieve this purpose). This rule ensures that a later compaction of level-(L+1) file will not pick up too much data from level-(L+2).

Compaction for a particular level **rotate** through the key space: Specifically, the ending key of the last compaction is maintained, and the next compaction for level-L will pick the first file that starts after this key.

Compation drops overwritten values. Delection markers are droped, if there are no higher numbered levels that contain a file whose range overlaps the current key.







### 3. Supporting Files

##### # `MANIFEST`

`MANIFEST` lists the set of sorted tables that make up each level, the corresponding key ranges, and other important metadata. A new `MANIFEST` file is created (with a new number embedded in the file name) whenever the database is reopened.

`MANIFEST` file is formatted as a log, that is, changes made to the serving state are appended to the log.



##### # `CURRENT`

`CURRENT` is a simple text file that contains the name of the latest `MANIFEST` file.



##### # Info Logs

Informational messages are printed to files named `LOG` and `LOG.old`.



##### # Other Supporting Files

Other files used for miscellaneous purposes may also be present (`LOCK`, `*.dbtmp`).
