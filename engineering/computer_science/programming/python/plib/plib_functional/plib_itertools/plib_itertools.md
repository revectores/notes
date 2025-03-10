# Python Generator Functions

##### # Filter Generator Functions

<u>Introduce filter generator functions:</u>

```python
filter(predicate, it)
itertools.filterfalse(predicate, it)

itertools.compress(it, selector_it)

itertools.takewhile(predicate, it)
itertools.dropwhile(predicate, it)

itertools.isslice(it, start, stop, step=1)
itertools.isslice(it, stop)
```

<u>where the function `filter` is designed as the built-in function due to its power while others are in the `itertools` package.</u> 

`filter(predicate, it)` yield each truthy item under `predicate`. `filterflase` does the opposite.

`itertools.compress(it, selector_it)` yields items from `it` whenever the corresponding item in `selector_it` is truthy.

Note the difference between `filter`, which applies predicate to one iterator and `compress`, which uses the truthy of another parallel independent iterator to decide whether an item should be yielded.

`itertools.takewhile(predicate, it)` yields item from `it` if it's truthy for `predicate`, then stops at the first fasly value for `predicate`. On the contrary, `itertools.dropwhile(predicate, it)` drops item while `predicate` compute truthy, then yields every remaining item when the first falsy value is met (no further checks are made):

```python
>>> itertools.takewhile(operator.truth, [1, 1, 0, 1, 0])
[1, 1]
>>> itertools.dropwhile(operator.truth, [1, 1, 0, 1, 0])
[0, 1, 0]
```

`itertools.islice(it, start, stop, step=1)` yields iterms from a slice of `it`, similar to `s[start:stop:step]` except it an be any iterable (and the operation is lazy).



##### # Mapping Generator Functions

```python
enumerate(iterable, start=0)

itertools.accumulate(it, [func])

map(func, it1, [it2, ..., itN])
itertools.starmap(func, it)
```

`accumulate(it, [func])` yields accumulated sums (prefix sums) by default (that is, `func=operator.add`). You can also provided some other function that takes two parameters.

For instance, to compute the factorial series, we use `operator.mul`:

```python
itertools.accumulate(range(1, 11), operator.mul)
# [1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800]
```

`map` return an iterator that applies `func` to every item of iterable, yielding the results. If addition arguments are passed, `func` msut take that many arguments and is applied to the items from all iterables in parallel. With multiple iterables, the iterator stops when the shortest iterable is exhausted.

For cases where the function inputs are already arranged into arugment tuples (pre-zipped), use `itertools.starmap()`:

```python
# equiv:
map(operator.add, [1, 2, 3], [4, 5, 6])
itertools.starmap(operator.add, [(1, 4), (2, 5), (3, 6)]
```



##### # Merge Multiple Iterables to Single Iterable

<u>introduce functions that used to merge multiple iterables to single iterable:</u>

```python
zip(*iterables)
itertools.zip_longest(*iterables, fillvalue=None)

itertools.chain(*iterables)
itertools.chain.from_iterable(iterable)

itertools.product(*iterables, repeat=1)
```

`zip(*iterables)` yields N-tuple built by taking the iterables in parallel, **silently stopping when the first iterable is exhausted**. To fill the short iterable, use `itertools.zip_longest` and specify the `fillvalue`.

`itertools.chain(*iterables)` yield all items from each iterable sequentially.

`itertools.product` creates Cartesian product.



##### # Expand Single Iterable to Multiple Iterables

```python
itertools.combinations(it, out_len)
itertools.combinations_with_replacement(it, out_len)
itertools.count(start=0, step=1)
itertools.cycle(it)
itertools.permutations(it, out_len=None)
itertools.repeat(item, [times])
```

