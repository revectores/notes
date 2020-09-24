# Inode Number

##### Definition

> The inode (index node) is a data structure in a Unix-style file system that describes a file-system object such as a file or a directory. Each inode stores the attributes and disk block locations of the object's data. File-system object attributes may include metadata (times of last change, access, modification), as well as owner and permission data.
>
> Directories are lists of names assigned to inodes. A directory contains an entry for itself, its parent, and each of its children.

##### POSIX Inode Description

> An inode is denoted by the phrase "file serial number", defined as a per-file system unique identifier for a file. That file serial number, together with the device ID of the device containing the file, uniquely identify the file within the whole system.
>
> Within a POSIX system, a file has the attributes which may be retrieved by the [stat]() system call.

