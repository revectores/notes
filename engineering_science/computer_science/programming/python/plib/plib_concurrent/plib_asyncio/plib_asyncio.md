# Python Library `asyncio`

### `asyncio` Introduction

`asyncio` is a library to write concurrent code using `async/await` syntax. 

`asyncio` provides a set of high-level APIs to:

- run Python coroutines concurrently and have full control over their execution.
- perform network IO and IPC.
- control subprocess.
- distribute tasks via queues.
- synchronize concurrent code.

Additionally, there are low-level APIs for library and framework developers to:

- create and manage event loops, which provide asynchronous APIs for networking, runnign subprocesses, handling OS signals, etc.
- implement efficient protocols using transports.
- bridge callback-based library and code with async/await syntax.








### `coroutine`

We create `coroutine` by adding `async` before `def` of function:

```python
import asyncio

async def main():
	print('hello')
	await asyncio.sleep(1)
	print('world')

asyncio.run(main())
```

Note that the coroutine will not be executed if you simply call `main()`, same as `asyncio.sleep(1)`, which is also a coroutine.

Three main mechanism are introduced by `asyncio` to run a coroutine (we've demonstrated two of them in the example above):

- `asyncio.run()` function to run the **top-level** coroutine entry point.

- `await`. This can only be used **inside** the coroutine to execute another coroutine, where the `asyncio.run()` cannot be applied.

Note that the two methods above both run the coroutine **sequentially**.

- `asyncio.create_task()` to run coroutine concurrently as asyncio `Tasks`.

Consider two examples that run the coroutine sequentially(by `await`) and concurrently(by `create_task`) respectively:

```python
import asyncio
import time

async def say_after(delay, what):
	await asyncio.sleep(delay)
	print(what)

async def main():
	print(f"started at {time.strftime('%X')}")
	await say_after(1, 'hello')
	await say_after(2, 'world')
	print(f"finished at {time.strftime('%X')}")

asyncio.run(main())
```

```python
import asyncio
import time


async def say_after(delay, what):
	await asyncio.sleep(delay)
	print(what)

async def main():
	task1 = asyncio.create_task(say_after(1, 'hello'))
	task2 = asyncio.create_task(say_after(2, 'world'))

	print(f"started at {time.strftime('%X')}")
	await task1
	await task2
	print(f"finished at {time.strftime('%X')}")

asyncio.run(main())
```

Source codes are presented in [async_await_demo.py](__src__async_await_demo/async_await_demo.py) and [async_task_demo.py](__src__async_task_demo/async_task_demo.py)

The time elapsed are 3 seconds for the sequential program while 2 seconds for the concurrent program.
