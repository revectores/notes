"""
>>> avg(1)
1.0
>>> avg([1, 2, 3])
2.0
>>> avg(avg)
NotImplemented
"""

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


if __name__ == '__main__':
	import doctest
	doctest.testmod()
