# Python Library `shutil`

### `shutil` Directory Operation

`shutil` provides power to recursive opeartion on directory that `pathlib` does not support. We introduce the useful methods `copytree` and `rmtree` which copy and delete the directory respectively.

`shutil.copytree` recursively copy an entire directory tree rooted at `src` to a directory named `dst` and return the destination directory. The prototype of `shutil.copytree`:

```python
shutil.copytree(
	src,
	dst,
	symlinks=False,
	ignore=None,
	copy_function=copy2,
	ignore_dangling_symlinks=False,
	dirs_exist_ok=False
)
```

where `src` and `dst` specify the source and destinition in the file system. If `dirs_exist_ok` is not specify, the `dst` must not exist.

Python 3.8 introduces the keyword parameter `dirs_exist_ok` which dictates whether to raise an exception in case `dst` or any missing parent directory already exists.

`shutile rmtree` delete an entire directory tree. Prototype of method `shutil.rmtree`:

```python
shutil.rmtree(path, ignore_errors=False, onerror=None)
```




