# Flow Network

##### # Definition

A **flow network** $G = (V, E)$ is a directed graph in which edge $(u, v)\in E$ has a nonnegative **capacity** $u, v \ge 0$. Define $c(u, v) = 0$ if $(u, v)\notin E$ for convenience.

Some restrictions:

- If $E$ contains an edge $(u, v)$, then there is no edge $(v, u)$ in the reverse direction. If there is, split one of them into two edges with identical capacity (both identical to the original one) that go through one extra node.
- Only one source and one sink. If there are more than one, create a **supersource** or **supersink**.
- Each vertex lies on some path from the source to the sink. That is, for each vertex $v\in V$, the flow network contains a path $s\leadsto v \leadsto t$. The graph is therefore connected and $|E|\ge|V| - 1$.

A **flow** in $G$ is a real-valued function $f: V\times V\rightarrow\R$ that satisfies

**Capacity constraint**. For all $u, v\in V$, we have $0\le f(u, v)\le c(u, v)$.

**Flow conservation**. For all $u\in V - \{s, t\}$, we require

$$
\sum_{u\in V}f(v, u) = \sum_{v\in V}f(u, v)
$$

$f(u, v)$ is the flow from vertex $u$ to vertex $v$, and the **value** $|f|$ of a flow $f$ is

$$
|f| = \sum_{v\in V}f(s, v) - \sum_{v\in V}f(v, s)
$$

Typically, a flow network will not have any edges(also the flow) into the source, except in residual network.
