# Python Library `psutil`

`psutil` (python system and process utilities) is a cross-platform library for retrieving information on running processes and system utilization (CPU, memory, disks, network, sensors) in Python.



### 1. Process

##### # `psutil.Process` Class

`psutil.Process(pid=None)` represents an OS process with given `pid`. If `pid` is omitted, the current process `pid` is used. Raise `NoSuchProcess` if `pid` does not exist.

Note that since the class is bound to a process via `PID`, which can be reused if the process has already terminates. That is, there is a risk that you interact with some other process. However the process identiy is preemptively checked (via PID + creation time) for some methods.

Multiple process attributes can be accessed by class methods, for instance, `ppid()`, `name()`, `exe()`, `environ()`, `create_time()`,  etc. The supported attributes depend on operating system.

Internally, different process info may be fetched by the same system call, hence `oneshot()` context manager is introduced to cached the potentially useful result:

```python
p = psutil.Process()
with p.oneshot():
    p.name()
    p.cpu_times()
    p.cpu_percent()
    p.create_time()
    p.ppid()
    p.status()
```

Another approach is to use `as_dict(attrs=None, ad_value=None)`, which retrieves multiple process information specified by `attrs` as a dictionary and use `oneshot()` internally. With `attrs=None`, all public read-only attributes are assumed. `ad_value` specifies the default value assigned to key if `AccessDenied` or `ZombieProcess` exception is raised.



##### # Process Iteration

`psutil.pids()` return sorted list of running pids.

`psutil.process_iter(attrs=None, ad_value=None)` return an iterator yielding a `Process` class instance for all running processes sorted by pid. This should be perferred over `psutil.pids()` to iterate over processes as it's safe from race condition.

`attrs` and `ad_value` have the same meaning as in `Process.as_dict()`. If `attrs` is specified, `Process.as_dict()` result will be stored as a `info` attribute attached to the returned `Process` instances. To retrieve all process info, set `attrs=[]`.

```python
for proc in psutil.process_iter(['pid', 'name', 'username']):
	print(proc.info)
```


