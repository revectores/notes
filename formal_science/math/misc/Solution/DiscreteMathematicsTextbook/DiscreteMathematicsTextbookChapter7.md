### Chapter 7

##### # Exercise 4.

Assume that the degree of all the nodes of graph $G$ are not larger then 2, the sum of drgree

$$
\sum_{v\in V} d(v) \leq 2n
$$

on the other side, based on the handshaking lemma, the drgree

$$
\sum_{v\in V} d(v) = 2|E| = 2|n+1|
$$

which is contradicts to the assumption, so there must be at least one node's degree is larger or equal than 3.



##### # Exercise 6.

$C_3$ is the circle graph with 3 vertex. We classify the subgraphs into three types based on the vertex number. Notice that in the defintion of graph the vertex set is declared as non-empty, so any graph must contain at least one vertex.

1. With one vertex. No edges can be included. Three different vertex, 3 cases.

2. With two vertexes.

	- With no edge included. There're $C_3^2 = 3$ cases.
	- With one edge connected. This can be generated from the no-edge case, by simply connect a line between two nodes, 3 cases.

3. With three vertexes.
	
	- With no edge. 1 case.
	- With one edge. The edge can connected in any two nodes. 3 cases.
	- With two edges. It can be considered as the reverse of one-edge case. 3 cases.
	- With three edges. 1 case.

In summary, the total possible subgraphs are $3 + (3+3) + (1+3)*2 = 17$.

Notice that in this exercise, we consider the 3 vertexes as different. In exercise26 of this chapter, where we classify the isomorphism as the same, the result will be very different.



##### # Exercise 7.

Notice that the undirected graph is contrained as simple graph, so none of the vertexes can hold a degree equal or larger than the number of vertexes, otherwise it must connect to some nodes twice or more, or has circle to itself. So the only choice is the $n$ vertexes have $0, 1, 2, ..., n-1$ degrees repectively.

Assume this is true, the vertex got $n-1$ degree must connect to every other vertexes, in this case, it's impossible to exist a vertex with degree $0$, this concludes that that kind of graph is impossible.



##### # Exercise 8.

Based on the definition of bigraph, a node can only be connected to the nodes in the other part, assume two parts of $G=(V,E)$ contains $V_{1}$ and $V_{2}$ vertexes respectively, the maxium number of edges can be expressed by

$$
E_{m} = V_{1} \times V_{2} \leq \cfrac{(V_{1}+V_{2})^2}{4} = \cfrac{V^2}{4}
$$






















