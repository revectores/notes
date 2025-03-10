import os
import psutil
from timeit import timeit
from functools import partial

from relation import Relation, dependency_generater


complete_attrs = set(list('ABCDEFGHI'))
dep_pairs = [('A', 'B'), ('A', 'C'), ('CG', 'H'), ('CG', 'I'), ('B', 'H')]
deps = dependency_generater(dep_pairs)

r = Relation(attrs=complete_attrs, deps=deps)

attrs = set(['A', 'G'])
expect_closure = set(['A', 'B', 'C', 'G', 'H', 'I'])
closure = r.get_attrs_closure(attrs)

time_cost = timeit(partial(r.get_attrs_closure, attrs), number=100000)
process = psutil.Process(os.getpid())
print(time_cost)
# print(process.memory_info().rss / 2**20)

