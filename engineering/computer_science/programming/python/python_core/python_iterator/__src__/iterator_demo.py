"""
>>> run_iterator()
1
2
3
4
stop!
"""


class TestIterator:
    def __init__(self, L):
        self.L = L
        self.cur = 0

    def __next__(self):
        if self.cur < len(self.L) - 1:
            self.cur += 1
            return self.L[self.cur]
        else:
            raise StopIteration


def run_iterator():
    test_iter = TestIterator([0, 1, 2, 3, 4])
    try:
        while True:
            print(next(test_iter))
    except StopIteration:
        print('stop!')


if __name__ == '__main__':
    import doctest
    doctest.testmod()
