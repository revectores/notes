# Python Library `os.path`

### `os.path` Introduction

`os.path` implements some useful functions on pathnames represented by [string]() or [bytes](). The reason to support both string and bytes object is that, some names on Unix cannot be represented by Unicode string, vice versa, some names on Windows cannot be represented by bytes.

Refer to [`pathlib`]() for the high-level object-oriented interface of file object. Since `pathlib` provides a more friendly OOP interface, in common one should use it instead of `os.path`.



##### Path-like Object

Since Python 3.6, almost all of the methods of `os.path` accepts a path-like object. A **path-like** object is an object representating a file system path, which can be

- A `str` or `bytes` object representing a path.
- An object implementating the `os.PathLike` protocol.

An object that supports the `os.PathLike` protocol can be converted to a `str` or `bytes` file system path by calling the `os.fspath()` function. `os.fsdecode()` and `os.fsencode()` can be used to guarantee a `str` or `bytes` instead, respectively. This is introduced by `PEP519`.

All kinds of `Path` classes implemented in `pathlib` support `os.Pathlike` protocol hence are path-like objects. That is, they can be used as the parameters feeding to `os.path`





### `os.path` Utility Methods

##### File Examining

Note that the `os.path` module only support type checking whether a file is a regular file, a directory, and a link:

- `os.path.isfile(path)`
- `os.path.isdir(path)`
- `os.path.islink(path)`

Note that the `isfile()` and `isdir()` methods both follow symbolic links, so both `isfile()` and `islink()` can be `True`, or both `isdir()` and `islink()` can be `True`.

Use methods in [`pathlib`]() to check whether is a block/character device, a socket, or a fifo.



##### File Information Retriving

Get the last access time, last modification time, ctime(time of the last metadata change for Unix, and the creation time for Windows).

- `os.path.getatime(path)`
- `os.path.getmtime(path)`
- `os.path.getctime(path)`

All the returned values of the three functions are timestamp in seconds.


