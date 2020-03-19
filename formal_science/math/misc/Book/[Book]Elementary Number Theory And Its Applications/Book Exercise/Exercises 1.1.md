# Exercises 1.1

### Exercise 1.

##### Solution

Let's review the definition of well-order first, if we say a set is well-ordered, then any subset of it exists a minimum element. At present we know the set of positive number $\N$ is well-ordered.

1. a) and b) are obvious well-ordered. As we konw, the subset relation is transitive, so any subset of subset of $S$ is also the direct subset of $S$, since a) is the subset of $\N$, any subset of a) will also be the subset of $\N$, which implies that any subset of a) has a minimum element, so a), b), and any none-empty subset of $\N$ are well-ordered.

2. d) is well-ordered, consider a subset of d) is picked, say $B = \{b_1,\ b_2,\ ..., b_n\}$, we multiple every elements by 2, which constructs a new set $2B = \{2b_1,\ 2b_2, ..., 2b_n\} \sub \N$, since this is a subset of $\N$, there must be an minimum element $2b_m\leq 2b_i, \ \ 1\leq i \leq n$, thus  $b_m\leq b_i, \ \ 1\leq i \leq n$, this is the equivlance to say $b_m$ is the minimum number of $B$.
3. c) and e) are not well-ordered. Take any left-open interval in $\Q$: $I = \{q \ | q\in(a,b),\ q\in\Q \}$ , assume there's an minimum number $m$, we can always constucts a new number $m' = \cfrac{a+m}{2}\in I, \ \ m' < m$, this implies the set of rational number $\Q$ and any **"INTERVAL"** derived from $\Q$ are not well-ordered.

29'27''



##### Summary

To prove well-order property, we must use $\N$, convert the subset of a new set into the subset of $\N$. Proof 1 uses the property of subset, and Proof 2 uses the property of equation.

To prove none well-order set, use "infinite descent". Here the descent works because of the denseness of rational numbers.

06'29''





### Exercise 2.

##### Solution

Construct a subset of $\N$
$$
R = \{ r\in\N \ \ |\ \ r = a-bk, \quad a,\ b\in\N, \ k\in\Z\}
$$
obviously this must be none-empty (consider $k$ as variable, a linear function always got the parts above $x$-axis), so there exists an minimum element in this set.

4'23''





### Exercise 5.

##### Solution

The solution is almost the same as the Theorem1.1 in the textbook.

Assume that $\sqrt{3} = \cfrac{p}{q}$ is rational, construct a subset of $\N$:
$$
S = \{\sqrt{3}k \ | \ k,\sqrt{3}k \in \N \}
$$
This is non-empty beacuse of at least one tuple from the assumption $(p,\ q)\in S$, so there exists an number $m=\sqrt{3}n$ as the minimum number.

Consider a number
$$
\begin{align}
p =& \sqrt3m - m \\
  =& \ (\sqrt3 -1)m & < m \\
  =& \ 3n - m & \in \N \\
  =& \ \sqrt3(m-n)
  
\end{align}
$$
Notice that $m, n\in\N,\ (m-n)\in\N$, this implies that $(m-n)$ can be consider as $k$, so $\sqrt3(m-n)<m$ is also an element of $S$. This is contradict with the assumption saying $m$ is the minimal number in $S$. So $\sqrt3$ must be irrational.

48'09''



