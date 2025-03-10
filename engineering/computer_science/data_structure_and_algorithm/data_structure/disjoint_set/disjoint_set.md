# Disjoint Set

$$
\newcommand{\S}{\mathcal{S}}
$$

##### # Definition

A disjoint-set data structure maintains a collection $\S = \{S_1, S_2, \ldots, S_k\}$ of dis-joint dynamic sets. We identify each set by some member called **representative**.

A disjoint set should support three operations:

- `MAKE-SET(x)` creates a new set whose only member (and thus  representative) is `x`.
- `UNION(x, y)` unites the dynamic sets that contain `x` and `y` into a new set.
- `FIND-SET(x)` returns the representative of the set containing `x`.

To analyse the complex complexity, let $n$ denotes the number of `MAKE-SET(x)` operations, and $m$ denotes the total number of all three operations. Apparently we have $m\ge n$, and we can call `UNION` operation at most $n-1$ time.



##### # Implementation

A forest consisting of rooted trees, embedded with "union by rank" and "path compression" heuristics, is the most efficient representation of disjoint set.

- **Union by rank**. For each node, we maintain a **rank**, which is an upper bound on the height of the node. We make the root with smaller rank point to the root with larger rank during a `UNION` operation.
- **Path compression**. During `FIND-SET` operation we make each node on the find path point directly to the root. This does not change any ranks.

Now the Python code:

```python
def make_set(x):
    x.p = x
    x.rank = 0

def union(x, y):
    link(find_set(x), find_set(y))

def link(x, y):
    if x.rank > y.rank:
        y.p = x
    else:
        x.p = y
        if x.rank == y.rank:
            y.rank += 1

def find_set(x):
    if x != x.p
        x.p = find_set(x, p)
    return x.p
```

