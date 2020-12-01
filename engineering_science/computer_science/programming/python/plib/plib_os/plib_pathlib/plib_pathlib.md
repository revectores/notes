# Python Library pathlib

### `pathlib` Introduction

`pathlib` is a object-oriented interface to manipulate paths of operating system. Refer to [os.path]() module for The underling low-level operation on paths based on string. `pathlib` is not designed for recursive directory operation such as directory copying or deleting, refer to [shutil]() for these recursive directory operations.

`pathlib` construct two level hierarchy of path, the pure path and concrete path, the difference is that pure path does not aware of on the actual filesystem but only the abstract string-operating provided, and the concrete path inherit from pure path equipped with file operation support. For each type, the path under Windows and POSIX are also distinguished (but you can also leave it up to Python to decide), hence there are four classes of Path: `PurePath`, `PurePosixPath`, `PureWindowsPath`, and `Path`, `PosixPath`, `WindowsPath`.

For the most common usage, just use `Path` by which you could manipulate the file system. For some special cases if you intend to avoid the actual filesystem accessing, or you want to manipulate `Windowspath` in Unix system, use pure path instead.

Creating the path object of current working directory is as simple as invoking the constructor, note that when creating `PurePath` or `Path` it will be automatically converted to the corresponding specific type based on operating system.

```python
>>> from pathlib import PurePath, Path
>>> PurePath('.')
PosixPurePath(',')
>>> Path('.')
PosixPath('.')
```



### `pathlib.PurePath`

The `PurePath` class provides symbolic operation on path:

- `PurePath.name()`: the final path component.
- `PurePath.suffix()`: the last file extension of the final component.
- `PurePath.suffixes()`: list the file extensions of the final component.
- `PurePath.stem()`: final path component without suffix.
- `PurePath.parent()`: the logical parent of path.
- `PurePath.parents()`: the list of logical ancestors of the path.

	```python
	>>> p = PurePath('/first/second/third')
	>>> list(p.parents)
	[PurePosixPath('/first/second'), PurePosixPath('/first'), PurePosixPath('/')]
	```

Note that since `PurePath` is unaware of the real filesytem, these operation are pure logical operation, for example,

```python
>>> PurePosixPath('foo/..').parent
PurePosixPath('foo')
```

to walk an arbitary path with multiple special notation included, it is recommended to first call `Path.resolve()` so as to resolve symlinks and eliminate `..` components.

Refer to [`pure_path_asserts.py`]() for examples about `PurePath` properties.







### `pathlib.Path`

As mentioned, `Path` inherits `PurePath` and equipped with actual filesystem.

##### `pathlib.Path` File Inforamtion Retriving

Checking of seven types of Unix file type are encapsulated as dependent functions:

- `Path.is_file()`: return `True` if the path points to a [regular file]() or a [symbolic link]() pointing to a regular file. return `False` if the path points to another kind of file, or the is a broken symlink, or doesn't exist.
- `Path.is_symlink()`
- `Path.is_dir()`
- `Path.is_fifo()`
- `Path.is_char_device()`
- `Path.is_block_device()`
- `Path.is_socket()`

All the seven checking functions also return `False` if the path does not exist at all. Other errors such as permission errors are propagated.

Refer to [unix_file_intro]() for the details about the file of Unix.

Besides the file type checking, there are other functions that check the properties of a path:

- `Path.exists()`: whether the path points to an existing file or directory.
- `Path.is_mount()`: return `True` if the path is a [mount point](): a point in a file system where a different file system has been mounted. On POSIX, the function checks whether `path/..` is on a different device than `path`, or whether `path/..` and `path` points to the same i-node on the same device. This is not implemented on Windows.


- `Path.stat()`. Return a `os.stat_result` object containing information about this path, like `os.stat()`.

- `Path.expanduser()`. Return a new path with expanded `~` and `~user` constructs, as returned by `os.path.expanduser()`.



##### `pathlib.Path` Directory Iteration

There are several ways to iterate the directory:

- `Path.iterdir()`. When the path points to a directory, yield path objects of the directory contents. The chilren are yielded in arbitary order, and the special entries `.` and `..` are not included. If a file is removed from or added to the directory after creating the iterator, whether an path object for that file be included is unspecified.
- `Path.glob(pattern)`. Glob the given relative `pattern` in the directory represented by this path, yielding all matching files of any kind. Use `**` to iterate the directory recursively.







