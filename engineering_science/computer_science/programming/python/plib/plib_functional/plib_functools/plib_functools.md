# Python Library `functools`

The `functools` module is for higher-order functions.

Note that since singledispatch, specifically `@functools.singledispatch` and `@functools.singledispatchmethod`, is such an significant feature that extends Python's expressiveness, we left them to [python_generic_function](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/engineering_science/computer_science/programming/python/python_core/python_function/python_generic_function/python_generic_function.md).



##### # `@functools.cache`

Built-in unbounded memo. This is absolutely the killer decorator for [dynamic programming]().

This creates a thin wrapper around a dictionary lookup for the function argument.

```python
@cache
def factorial(n):
    return n * factorial(n - 1) if n else 1

factorial(10)		# 11 recursive calls.
factorial(5)		# no calls.
factorial(12)		# 2 extra calls.
```



##### # `@functools.lru_cache()`

Built-in LRU cache. `@lru_cache(maxsize=None)`  will produce the same result as `@cache`



##### # `@functools.total_ordering`

Given a class defining one or more rich comparison ordering methods, decorator `@functools.total_ordering` supplies the rest. This simplifies the effort involved in specifying all of the possible rish comparison operations.

The class must define `__eq__()`, and one of `__lt__()`, `__le__()`, `__gt__()`, `__ge__()`.

Note that this reduces performance.

