"""
>>> List(1)
1
>>> List([1, 2, 3])
1 2 3
>>> List(int)
<class 'int'>
"""


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
        self.head = ListNode(vals)

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

    def __repr__(self):
        vals = []
        node = self.head
        while node:
            vals.append(node.val)
            node = node.next
        return ' '.join(map(str, vals))



if __name__ == '__main__':
    import doctest
    doctest.testmod()
