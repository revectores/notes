##### # Exercise 9.

(1) Notice that based on the definition of relation, $f\circ g(x) = g(f(x))$, which means the left operator is first applied. Notice that the inner function, which is $f$, must be one-to-one, otherwise once two values mapped to the same result, the wrapper function $g$ will no doubt repoints the same value as its input to the same result, formally, if $f(a) = f(b)$:

$$
g(f(a)) = g(f(b)) = g(t) = y
$$

which contradicts to the requirement to make $f\circ g (x)$ to be one-to-one.

On the contrary, it donen't matter if the wapper function $g$ is one-to-one, this is because of the "domain-narrowing effect", the result of function $f$ even might not be in the domain of $g$, which makes those variables pointed to the same values simply rejected by $g$, for example:

$$
\begin{align}
D(f) = \{1,2,3\}, ~~~~& f = \{ (1,1),~ (2,1), ~(3,2)\} \\
D(g) = \{2,3\},   ~~~~& g = \{ (2,2),~ (3,4)\} \\
D(f\circ g) = \{2\}, ~~~~& f\circ g = \{ (3,2) \}
\end{align}
$$

Since the precedent 1 even not shown up in the domain of $g$, the pair $(1,1), (2,1)$ doesn't break the rules.




##### # Exercise 16.

According to the definition of function, for any given $x_i\in X$, there will be a correspondent $y_i\in Y$ as the function value. Assume that we place all the possible $x_i$ in order, i.e., $(x_1, x_2, x_3, ..., x_n)$, there will be a determined tuple of dependent variable $y$: $(y_1, y_2, y_3, ..., y_n)$, and this also specifies a function. As a result, a function can be modeled by the n-tuple, which is, we create a bijection between all the possible n-tuple and the all possible functions, this shows $F\sim P(X)$.



##### # Exercise 18.

First, we devide the subsets based on its elements number:

$$
P(S) = \bigcup \  A_i \\
A_i = \{M \ \big| \ |M|=i,\ M\subset P(S),\ i\in N\}
$$

Notice that we devided the $P(S)$ into the union of countable number of sets. Based on the theorem, the union of countable number of countable sets is also countable. Now we need to prove that every set $A_i$ is countable.

Apparently, $A_0$ and $A_1$ is countable, and for any $A_n$ it can be considered as a subset of $A_{n-1}\times A_1$, since the Cartesian product is order-relavant but the set is not. As shown before, the Cartesian product of countable sets are still countable, and the subset of countable set is still countable.

Combining this features, we could say that if $A_{n}$ is countable, then $A_{n+1}$ is also countable. This concludes that for all natual number $i$, $A_{i}$ is countable, as a result, the union of them, which is, $P(S)$, is countable.




##### # Exercise 19.

To create a narrowing mapping, we need to find place for the extra number in the new set and make the original palceholder moves. Since there's only to element to place: $0$ and $1$, a simple approach is finding a natural sequence to do the movement. Fortunately, there's one:

$$
\cfrac{1}{2},\ \cfrac{1}{3},\ \cfrac{1}{4},\ ...,\ \cfrac{1}{n}
$$

So we decide place $0$ to $\cfrac{1}{2}$ and $1$ to $\cfrac{1}{3}$, and let all the elemenets in the sequence move 2 steps forward. Other elements which not in the list simply maps to themselves. Formally, we construct a function $F(x)$:

$$
F(x) = \left\{

\begin{array}{ll}
\cfrac{1}{2}, ~~~~ ~~~~~~~~ x=0 \\
\cfrac{1}{3}, ~~~~ ~~~~~~~~ x=1 \\
\cfrac{1}{n+2}, ~~~~ x=\cfrac{1}{n},~ n\in\Z,~ n\ge2 \\
x, ~~~~ \text{for other}~x
\end{array}

\right.
$$

Apparently this is a bijection since the reverse function can be found trivially, by which we proved that $[0,1]\sim(0,1)$.



##### # Exercise 20.

As mentioned in the notes of computability, all the valid C program $C$ is a subset of the finite string set $\Sigma^{*}$ above $\Sigma$, which means $C$ is countable. To prove there exists a function $f$ that cannot be calculated by any C program, we need to prove $F$ is uncountable. 

Assume that $F$ is countable, so we'll be able to list it by

$$
F = \{ f_{1},~ f_{2},~ f_{3},~ ... \}
$$

Now we construct a function $f\in F$, which satisfied:

$$
f(x) = \left\{

\begin{array}{ll}
2, ~~~~f_n(n)\neq2 \\
4, ~~~~f_n(n) = 2
\end{array}

\right.
$$

By doing this, we construct a function $f\in F$, but different from any function in the listed $F$, which implies that $F$ is not countable in fact.

This technique is similiar to that applied to prove $\R$ is not countable, where we construct a number making any digit of it is different of those listed ones.






























