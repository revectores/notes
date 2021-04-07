# C++ Associative Container

### 1. C++ Associative Container Introduction

##### # Classification

There are 8 associative containers:

- `map`
- `set`
- `multimap`
- `multiset`
- `unordered_map`
- `unordered_set`
- `unordered_multimap`
- `unordered_multiset`

`map` is set of key-value pairs (counterpart: Python `dict` or Java `HashMap`) and `set` are set of keys.

Prefix `multi` indicates that keys are allowed to be repeated, prefix `unordered` indicates that the container are not sorted.

For ordered containers `map`, `multimap`, `set`, and `multiset`, `operator<` must be defined for type of key. By default, `operator<` are used to construct a partial order. If `!(key1 < key2) && !(key2 < key1)`, they are recognized as equivalence. That is, only one of them can be used as the key in one associative container.

The type of comparison operation (function pointer) is a part of type of that associative container:

```c++
bool compare(const int &n1, const int &n2) {
    return n1 < n2;
}

multiset<int, decltype(compare)>() nums;
```

There are there types for associative container: `key_type`, `value_type`, and `mapped_type`. For `map`, the `key_type` and `mapped_type` are type of key/value respectively, and `value_type` is `pair<key_type, mapped_type>`.



##### # Implementation

The traditional implementation of ordered ssociative containers (`map`, `set`, `multimap`, `multiset`) are [red-black tree]() while their unordered version are [hash table](). Ideally, the average searching time complexity for red-black tree and hash table are `O(\lg n)` and `O(1)` respectively, (note that the worst time complexity for hash table can be `O(n)` when the hash table is degenerated to a linked-list while rb-tree ensure the worst case is `O(\lg n)`), while the hash table takes more memory than rb-tree.







### 2. `pair`

Operations on `pair`:

1. Initialization.
`pair<T1, T2> p`: initialize pair `p`, value initializtion are applied for two members.
`pair<T1, T2> p(v1, v2)` or `pair<T1, T2> p = {v1, v2}`: initialize pair by given values.
`make_pair(v1, v2)`: the type of pair are inferred from values.

2. Member access.
    `p.first` and `p.second`: return first or second members of `p`.
3. Order operators.
    `p1 [op] p2`: defined as lexicographical order.

