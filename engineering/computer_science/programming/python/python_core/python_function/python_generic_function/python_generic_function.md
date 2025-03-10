# Python Generic Function

##### # `@functools.singledispatch`

Decorator `@functools.singledispatch` transform a function into a **single-dispatch generic function**, that is, a function composed of multiple functions implementating the same operation for different types, dispatching based on the type of a single argument. This is a weaker form of function overloading (and requires more annotations) compared to C++.

For instance, consider a function that computes the average of iterable, and handling the special case of single number:

```python
from functools import singledispatch
from collections.abc import Iterable
from numbers import Number

@singledispatch
def avg(nums):
    return NotImplemented

@avg.register
def _(nums: Number):
    return float(nums)

@avg.register
def _(nums: Iterable):
    return sum(nums) / len(nums)
```

`arg: Iterable[Number]` annotation can not be used here since `singledispatch` invokes `issubclass()` internally, and there is `TypeError: issubclass() argument 2 cannot be a parameterized generic`.

It will finally fall back to the primitive function if the argument type does not fit in any registers, which leads to an `NotImplementation` in this case.



##### # `@functools.singledispatchmethod`

For class method, we use `@functools.singledispatchmethod`

For instance, consider to create a overloadable constructor that support both a single value or a iterator to create a linked list:

```python
from functools import singledispatchmethod
from collections.abc import Iterable
from numbers import Number

class ListNode:
      def __init__(self, val, next_=None):
            self.val = val
            self.next = next_

class List:
      @singledispatchmethod
      def __init__(self, vals):
            return NotImplemented

      @__init__.register
      def _(self, vals: Number):
            self.head = ListNode(vals)

      @__init__.register
      def _(self, vals: Iterable):
            if not vals:
                  self.head = None
                  return

            self.head = ListNode(vals[0])
            prev = self.head
            for val in vals[1:]:
                  node = ListNode(val)
                  prev.next = node
                  prev = node
```

