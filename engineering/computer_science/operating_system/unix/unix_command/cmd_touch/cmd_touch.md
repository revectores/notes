# Linux Command `touch`

##### # Usage

`touch` sets the modification time and access time of files use `-m`/`-a` flags to set only one of the time individually. That is, it update the fields `struct timespec st_atim` and `struct timespec st_mtim` in [`struct stat`](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/operating_system/unix/unix_file/unix_file_intro/struct_stat.md) of a file.

By default, If any file (in the given file list) does not exist, it is created with default permissions (ironically this is the most common usage of `touch`). Use `-c` to disable the creation if it does not exist.

To specify the time manually instead of the current time, use `-t ` to give the absoluate time or `-A` to give the relatvie time to the original one.

