# Unix File

### 1. Unix File Types

##### # Seven File Types in UNIX

There are 7 types of files in UNIX system. Most of the files are regular file or directory file in UNIX system.

1. **Regular file**. 

2. **Directory file**. A directory file is a file contains the names of other files and pointers on these files. Any process that has read permission for a directory file can read the contents, but only the kernel can write directly to a directory file.

    A device is, and must be, abstracted into one of the block special file or character special file.

3. **Block special file**.

4. **Character special file**.

5. **FIFO**. FIFO file, or pipe, is a type of file used for [IPC](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/operating_system/unix/unix_ipc/unix_ipc.md).

6. **Socket**. As introduced in [socket](https://en.wikipedia.org/wiki/Network_socket) in computer network, socket is the abstraction for the network communication between processes. A socket can also be used for non-network communication in a single host, in this case it degeneres to one way for the normal IPC.

7. **Symbolic link**. Symbolic link points to another file.



##### # Related Marcos

Correspondingly, seven macros are provided to read the type of a file:

|    MARCO     |      Type of file      |
| :----------: | :--------------------: |
| `S_ISREG()`  |      regular file      |
| `S_ISDIR()`  |     directory file     |
| `S_ISCHR()`  | character special file |
| `S_ISBLK()`  |   block special file   |
| `S_ISFIFO()` |      FIFO or pipe      |
| `S_ISSOCK()` |         socket         |
| `S_ISLNK()`  |     symbolic link      |

An example using these macros to determine the type of a file is given in [print_file_type.c](src__print_file_type/print_file_type.c). Use this to find all the types of files in system. Hint: the character and block specical files can be found in [`/dev`](https://tldp.org/LDP/Linux-Filesystem-Hierarchy/html/dev.html).



##### # File Descriptor

**File descriptor** is a non-negative integer used to referred a file by the system kernel. When we [`open`](#open) a new file, a file descriptor will be returned, and then we can use it in the `read/write` functions to refer the file.

Specifically, the file descriptor 0 is used to refer the standard input, 1 for standard output, and 2 for standard error. To improve the readibility, `include #<unistd.h>` to use the symbolic constants instead of the integers.

| File Descriptor | Symbolic Constant | File Object Constant |    Reference    |
| :-------------: | :---------------: | :------------------: | :-------------: |
|        0        |  `STDIN_FILENO`   |       `stdin`        | standard input  |
|        1        |  `STDOUT_FILENO`  |       `stdout`       | standard output |
|        2        |  `STDERR_FILENO`  |       `stderr`       | standard error  |

The range of file descriptors in modern Linux and Mac OS X is essentially infinite, bounded by the limit of other resources.

Notice that the file descriptor is process-related, that is, for two processes opening the same file, two file descriptors will be allocated to the two processes respectively.

The three files `stdin/stdout/stderr` will be open automatically as a process open.







### 2. File Operation System Call

<u>Introduce the common Unix file system calls: `open`, `close`, `read`, `write`, `lseek`. Historical `creat` is also included.</u>

##### # `open`

We open a file by the `open/openat` function.

```c
#include <fcntl.h>

int open(const char* path, int oflag, ... );
int openat(int fd, const char* path, int oflag, ... );
```

1. `path` specifies the path of file to open.

2. `oflag` parameter using pre-defined constants to specify the mode we open the file, joining by or `||` operator. The constants are defined at `<fcntl.h>`.

    |  Constant  |      Interpretation       |
    | :--------: | :-----------------------: |
    | `O_RDONLY` |         Read only         |
    | `O_WRONLY` |        Write only         |
    |  `O_RDWR`  |      Read and write       |
    |  `O_EXEC`  |       Execute only        |
    | `O_SEARCH` | Search only (directories) |

    **One and only one** of the listed constant must be specified. The complete table of `oflag`, including other optional constants, are listed in [file_oflag](file_oflag.md).

3. The last argument `...` is the ISO C style to specify arguments of uncertain types and numbers. These arguments will be used when a new file is being create.

Both of the functions return the file descriptor if OK, or -1 when failed (for example, permission denied). The returned file descriptor is guaranteed to be the **lowest available number**. Since the three special descriptors are automatically opened by system, the aforementioned rule gurantees the first opened file must be assigned 3 as the file descriptor:

```c
int main(int argc, char** argv){
    int fd = open("foo", O_RDONLY);
    printf("%d", fd);	// 3
    return 0;
}
```

The more interesting (and useful) fact is, if we close one of the special file and open a new file, the new file will take over the position of that closed one.

```c
int main(int argc, char** argv){
    close(0);
    int fd = open("foo", O_RDONLY);
    printf("%d", fd);	// 0
    return 0;
}
```

Believe it or not, try by yourself in [test_opened_file_descriptor.c](src__test_opened_file_descriptor/test_opened_file_descriptor.c).

Think of it. This operation provides a elaborate mechanism to control source/target of input/output, especially when we fork and exec a child process. Next time when the process read something from `STDIN_FILENO`, is it some other file instead of the read standard input.



##### # `creat`

We create a file by `creat` function

```c
#include <fcntl.h>

int creat(const char* path, mode_t mode);
```

`creat` returns file descriptor for write-only if OK, -1 on error.

`creat` function is equivlaent to

```c
open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);
```

> Historically, in early versions of the UNIX System, the second argument to open could be only `O_RDONLY`, `O_WRONLY`, or `O_RDWR`(0, 1, 2). There was no way to open a file that didn’t already exist. Therefore, a separate system call, `creat`, was needed to create new files. With the `O_CREAT` and `O_TRUNC` options now provided by open, a separate creat function is no longer needed.
>
> One deficiency with creat is that the file is opened only for writing. Before the new version of open was provided, if we were creating a temporary file that we wanted to write and then read back, we had to call creat, close, and then open. A better way is to use the open function, as in
>
> ```c
> open(path, O_RDWR | O_CREAT | O_TRUNC, mode);
> ```



##### # `close`

We close a file by `close` function

```c
#include <unistd.h>
int close(int fd);
```

`close` returns 0 if OK, -1 on error.

> When a process terminates, all of its open files are closed automatically by the kernel. Many programs take advantage of this fact and don’t explicitly close open files.



##### # `lseek`

During the processing of a file, the current file offset will be automatically handled as the `read/write` function called. By default, the offset is initialized to 0, or the length of file if the `O_APPEND` option is specified. The `read/write` function will increase the offset based on how many data have been read/write.

We can use `lseek` to set the current offset explicitly:

```c
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);
```

The interpretation of `offset` depends on the value of `whence`:

- `whence = SEEK_SET`, offset is added to the beginning of file.
- `whence = SEEK_CUR`, offset is added to the current offset, can be positive/negative.
- `whence = SEEK_END`, offset is added to the end of file, can be positive/negative.

`lseek` returns the new file offset if OK, -1 on error. As notice, `lseek` returns the new file offset, hence we're able to utilize `lseek` to find out the current offset by `lseek(fd, 0, SEEK_CUR)`. This technique can also be used to determined if a file is capable of seeking. If the descriptor refers to a pipe, FIFO, or socket, `lseek` sets `errno` to `ESPIPE` and returns 1. Refer [seekable_check.c](src__seekable_check/seekable_check.c) for implementation.

The infomation of current offset is stored within the kernel, no I/O operation is required to invoke `lseek` function.

The current offset of normal file must be non-negative, but not for all "files", since any object can be abstracted as file, some devices may allow negative offsets, which means the valid test of returned value of `lseek` must be `rv != -1` instead `rv < 0`.

The offset of a file might greater than the current size. For this case, the next `write` call will extend the file by adding bytes 0 til the new offset, and whether the "hole" filled by 0 takes the space of disk depends on the implementation of file system. Refer [file_with_hole.md](file_with_hole.md), which gives codes to craete a file with hole and comparing it with the no hole version to find out the difference on size. ==TODO: create and implement the file file_with_hole.==



##### # `read`

We use `read` function to read from a opened file:

```c
#include <unistd.h>

ssize_t read(int fd, void* buf, size_t nbytes);
```

`read` returns the number of bytes read, 0 if end of file, -1 on error. The performance is depends on the `buf` and the buffer size in the operating system level.



##### # `write`

We use `write` function to write to a opened file:

```c
#include <unistd.h>

ssize_t write(int fd, const void* buf, size_t nbytes);
```

`write` returns the number of bytes written if OK, -1 on error. Normally the return value if euqal to the `nbytes` argument.







### 3. Unix File Information

##### # `stat` Functions

<u>Introduce the file information function `stat`, `fstat`, `lstat`, `fstatat`, with their differences.</u>

```c
#include <sys/stat.h>
int stat(const char* restrict pathname,
         struct stat* restrict buf);

int fstat(int fd, struct stat* buf);

int lstat(const char* restrict pathname,
          struct stat* restrict buf);

int fstatat(int fd, const char* restrict pathname,
            struct stat* restrict buf, int flag);
```

All the four three functions return 0 if OK, -1 on error. The information is given by filling the `struct stat* buf`. Refer to [struct_stat](struct_stat.md) for the prototype of `struct stat`.

As noticed, the `fstat` use file descriptor `fd` as the parameter instead of the `pathname`. For the symbolic link, `lstat` list the inforamtion about the symbolic link itself instead of the file it points to.

Finally, the `fstatat` function provides a mechanism to retrive the file infomation by the `pathname` relative file `fd`. Two special cases are

- If `fd = AT_FDCWD`, the function will use the current directory as the base.
- If the pathname is an absolute pathname, then the parameter `fd` will be ignore.

In both case `fstat` works like when we providing the relative path or absolute path to system call `stat`.

Furthermore, the `flag` parameter specifies whether we use follows the symbolic link, depending on whether the flag `AT_SYMLINK_NOFOLLOW` is set.

`stat` is the basis of implementation of [`ls`](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/operating_system/unix/unix_command/cmd_ls/cmd_ls.md) command, who lists all the information about the files.



 



### 4. Working Directory

Use `chdir/fchdir` to change working directory by providing a pathname or a file descriptor.

```c
#include <unistd.h>
int chdir(const char* pathname);
int fchdir(int fd);
```

both functions return `0` if OK, `-1` on error.

# 

