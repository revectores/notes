# Collections

### 1. `NamedTuple`



### 2. `Counter`



### 3. `OrderedDict`

`OrderedDict` is a subclass of `dict` that has methods specialized for rearranging dictionary order. To be more specific, method `popitem(last=True)` and `move_to_end(key, last=True)` are supported.

A typical usage is to implement LRU:

[ordereddict_based_LRU](__src__/ordereddict_based_LRU.py)

```python
class LRU(OrderedDict):
  def __init__(self, maxsize=128, /, *args, **kwds):
    self.maxsize = maxsize
    super().__init__(*args, **kwds)

  def __getitem__(self, key):
    value = super().__getitem__(key)
    self.move_to_end(key)
    return value

  def __setitem__(self, key, value):
    if key in self:
      self.move_to_end(key)
    super().__setitem__(key, value)
    if len(self) > self.maxsize:
      oldest = next(iter(self))
      del self[oldest]
```


