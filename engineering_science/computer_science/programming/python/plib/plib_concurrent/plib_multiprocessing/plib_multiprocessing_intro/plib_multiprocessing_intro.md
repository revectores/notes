# Python Library `multiprocessing`

### `multiprocessing` Introduction

The `multiprocessing` offers both local and remote concurreny, effectively side-stepping the global interpreter lock by using subprocesses instead of threads, which allows the programmer to fully leverage multiple processors on modern computer.







### `multiprocessing.Process`

##### Create a process by `Process` instantiation

A process is spawned by creating a `Process` object and then invoking its `start()` method.

```python
from multiprocessing import Process

def f(name):
	print('hello', name)

if __name__ == '__main__':
	p = Process(target=f, args=('Robert',))
	p.start()
	p.join()
```

We can use the `os` module to check the `pid` and `ppid` of created process:

```python
from multiprocessing import Process
import os

def info(title):
	print(title)
	print('module name:', __name__)
	print('ppid:', os.getppid())
	print('pid: ', os.getpid())
	print()

def f(name):
	info('function f')
	print('hello', name)

if __name__ == '__main__':
	info('main line')
	p = Process(target=f, args=('Robert',))
	p.start()
	p.join()
```

Source codes are given in [multiprocessing_demo.py](__src__multiprocessing_demo/multiprocessing_demo.py) and [multiprocessing_demo_expanded.py](__src__multiprocessing_demo_expanded/multiprocessing_demo_expanded.py)

Note that the `if __name__ == '__main__'` must be given when using multiproessing. We'll explain the reason soon after introducing the .



##### Start methods of `Process`

There ways to start a process are supported by `multiprocesing`:

- `spawn`. The parent starts a fresh Python interpreter process. Unnecessary resources (file descriptors and handles) from the parent will not be inherited.

Available on Unix and Windows. The default on Windows(since ) and macOS(since Python 3.8).

- `fork`. The parent process uses `os.fork()` to fork the Python interpreter. All resources of the parent sare inherited by the child process.

Available on Unix only. The default on Unix.

- `forkserver`. When the program starts and selects the `forkserver` as start method, a server process is started. From then on, whenever a new process is needed, the parent process connects to the server and requests that it fork a new process.

The fork server is single threaded so it is safe for it to use `os.fork()`. Unnecessary resources are not inherited.

Avaliable on Unix which support passing file descriptors over pipes.
