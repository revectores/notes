# POSIX Character Class



| POSIX Character Class | Equivalence                                       |
| :-------------------: | ------------------------------------------------- |
|      `[:digit:]`      | `0-9`                                             |
|     `[:xdigit:]`      | `a-fA-F0-9`                                       |
|      `[:lower:]`      | `a-z`                                             |
|      `[:upper:]`      | `A-Z`                                             |
|      `[:alpha:]`      | `a-zA-z`                                          |
|      `[:alnum:]`      | `a-zA-Z0-9`                                       |
|      `[:blank:]`      | `\t`                                              |
|      `[:space:]`      | `^\f\n\r\t\v`                                     |
|      `[:cntrl:]`      | ASCII 0~31 + ASCII 127                            |
|      `[:print:]`      | Any printable character                           |
|      `[:graph:]`      | Any printable character but space                 |
|      `[:punct:]`      | Any character besides `[:alnum:]` and `[:cntrl:]` |

