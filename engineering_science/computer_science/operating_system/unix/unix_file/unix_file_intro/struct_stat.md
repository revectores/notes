```c
struct stat {
    mode_t		st_mode;	// file type & mode
    ino_t		st_ino;		// i-node number
    dev_t		st_dev;		// device number
    dev_t		st_rdev;	// device number for special file
    nlink_t		st_nlink;	// number of links
    uid_t		st_uid;		// user ID of owner
    gid_t		st_gid;		// group ID of owner
    off_t		st_size;	// size in bytes for regular files
    struct timespec st_atim;// time of last access
    struct timespec st_mtim;// time of last modification
    struct timespec st_ctim;// time of last file status change
    blksize_t	st_blksize;	// best I/O block size
    blkcnt_t	st_blocks;	// number of disk blocks allocated
}
```

The interpretation about the `st_ino` field can be found at [inode_number](inode_number.md).

