# Linux Command `ps`

### 1. `ps` Introduction

`ps` displays information about a selection of the active processes. Use `top(1)` instead if you want a repetitive update of the selection and the displayed information.

`ps` accepts several kinds of options:

1. Unix options, which may be grouped and must be preceded by a dash.
2. BSD options, which may be grouped and must not be used with a dahsh.
3. GNU long options, which aer preceded by two dashes.



##### # `ps` Default Output

By default, `ps` selects all processes with

- The same effective user ID as the current user (euid = $EUID).
- The same terminal as the invoker.

and display four fields:

| Field   | Interpretation                       |
| ------- | ------------------------------------ |
| `pid`   | process ID                           |
| `tname` | terminal associated with the process |
| `time`  | cumulated CPU time                   |
| `ucmd`  | executable name                      |

The output is unsorted by default.







### 2. `ps` Options

##### # `ps` Process Selection Options

| OPtion  | Interpretation                                               |
| ------- | ------------------------------------------------------------ |
| `-e/-A` | Select all processes.                                        |
| `-a`    | Select all processes except both session leaders and processes not associated with a terminal. |
|         |                                                              |



##### # `ps` Output Format Options

| Option | Interpretation                                               |
| ------ | ------------------------------------------------------------ |
| `-o`   | user-defined format.                                         |
| `-O`   | like `-o` but preloaded with some default columns.           |
| `-f`   | full-format listing, includes: UID, PID, PPID, C, STIME, TTY, TIME, CMD |
| `-F`   | extra full format. includes all fields in `-f` and SZ, RSS, PSR. |







### 3. Standard Format Specifiers

##### # `ps` Fields: Environment

| Code               | Header  | Interpretation                             |
| ------------------ | ------- | ------------------------------------------ |
| args, cmd, command | COMMAND | command with all its argument as a string. |
| tname, tt, tty     | TTY     | controlling tty (terminal)                 |
|                    |         |                                            |



##### # `ps` Fields: Identifiers

| Code               | Header | Interpretation    |
| ------------------ | ------ | ----------------- |
| pid, tgid          | PID    | process ID        |
| ppid               | PPID   | parent process ID |
| uid, euid          | UID    |                   |
| user, euser, uname | USER   |                   |
|                    |        |                   |



##### # `ps` Fields: Timing

| Code                                       | Header  | Interpretation                                               |
| ------------------------------------------ | ------- | ------------------------------------------------------------ |
| start, lstart, start_time, stime, bsdstart | STARTED | time the command started. The format depends on the code you use. For `start`, if the process was started less than 24 hours ago, the output format is "HH:MM:SS", else it is "  Mmm dd". |
| etime                                      | ELAPSED | elapsed time since the process was started in the form `[[DD-]hh:]mm:ss` |
| etimes                                     | ELAPSED | elapsed time since the process was started in seconds.       |



##### # `ps` Fields: CPU Usage

| Code          | Header | Interpretation                                               |
| ------------- | ------ | ------------------------------------------------------------ |
| %cpu, pcpu    | %CPU   | CPU utilization of the process in "##.#" format. CPU time used devided by the time of the process has been running. |
| cputime, time | TIME   | cumulative CPU time. "[DD-]hh:mm:ss" format                  |
| psr           | PSR    | processor that process is currently assigned to              |



##### # `ps` Fields: Memory Usage

| Code       | Header | Interpretation                                               |
| ---------- | ------ | ------------------------------------------------------------ |
| %mem, pmem | %MEM   | ratio of the process's resident set size to the physical memory on the machine. |
| sz         | SZ     | size in physical pages of the core image of the process. This includes text, data, and stack space. Device mappings are currenly excluded. This is subject to change. |
| vsize, vsz | VSZ    | virtual memory size of the process in KiB. Device mappings are currently excluded. This is subject to change. |
| maj_flt    | MAJFLT | the number of major page faults that have occured with this process. |
| min_flt    | MINFLT | the number of minor page faults that have occured with this process. |
| trs        | TRS    | Text resident set size, the amount of physical memory devoted to executable code. |
| drs        | DRS    | Data resident set size, the amount of physical memory devoted to other than executable code. |
| size       | SIZE   | approximate amount of swap space that would be required if the process were to dirty all writable pages and then be swapped out. |



##### # `ps` Fields: Pointer

| Code | Header | Interpretation      |
| ---- | ------ | ------------------- |
| eip  | EIP    | instruction pointer |
| esp  | ESP    | stack pointer       |



##### # `ps` Fields: Process Scheduing

| Code               | Header | Interpretation                                               |
| ------------------ | ------ | ------------------------------------------------------------ |
| ni, nice           | NI     | nice value, ranges from 19 (nicest) to -20 (not nice to others) |
| class, cls, policy | CLS    | scheduling class of the process.                             |

The list of scheduling class supported by Linux:

| Code | Scheduling policy |
| ---- | ----------------- |
| TS   | SCHED_OTHER       |
| FF   | SCHED_FIFO        |
| RR   | SCHED_RR          |

Refer to [linux_scheduling_policy]() for details.



##### # `ps` Fields: Signals

| Code                         | HeadeR  | Interpretation                                               |
| ---------------------------- | ------- | ------------------------------------------------------------ |
| blocked, sig_block, sigmask  | BLOCKED | mask of the blocked signals. 32-bits or 64-bit mask in hexadecimal format. |
| caught, sig_caught, sigcatch | CAUGHT  | mask of the caught singals.                                  |



##### # `ps` Fields: Multithreading

| Code          | Header | Interpretation                           |
| ------------- | ------ | ---------------------------------------- |
| nlwp, thcount | NLWP   | number of lwps (threads) in the process. |

