"""
>>> lru = LRU(3)
>>> lru[0] = 0; lru[1] = 1; lru[2] = 2
>>> print(lru[0], lru[1])
0 1
>>> lru[3] = 3
>>> print(lru[2])
Traceback (most recent call last):
KeyError: 2
"""

from collections import OrderedDict


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


if __name__ == '__main__':
  import doctest
  doctest.testmod()
