# File `oflag`

Compulsory one and only one from the five:

|  Constant  |      Interpretation       |
| :--------: | :-----------------------: |
| `O_RDONLY` |         Read only         |
| `O_WRONLY` |        Write only         |
|  `O_RDWR`  |      Read and write       |
|  `O_EXEC`  |       Execute only        |
| `O_SEARCH` | Search only (directories) |

Optional:

|  Constant   |                        Interpretation                        |
| :---------: | :----------------------------------------------------------: |
|  `O_CREAT`  | Create the file if it doesn't exist. This requires an additional parameter `mode` to specify the permission bits. |
|  `O_EXCL`   | Generate an error if `O_CREAT` is also specified and the file already exists. The test for whether the file already exists and the creation of the file if it doesn't is an [atomic operation](). |
|  `O_TRUNC`  | If the file exists and if it is successfully opened for write-only/read-write, truncate its length to 0. |
| `O_APPEND`  |                  Append to the end of file.                  |
| `O_CLOEXEC` |          Set the `FD_CLOEXEC` file descriptor flag.          |
|             |                                                              |
|             |                                                              |

