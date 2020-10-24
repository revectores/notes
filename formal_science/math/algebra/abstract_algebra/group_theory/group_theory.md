$$
\newcommand{\GL}{\text{GL}}
$$

# Group Theory

### 1. Group

##### Definition

A non-empty set $S$ with its **combinative** binary operation called **SemiGroup**. If there's identical element in semigroup, it's a **Monoid**. Monoid with all the elements reversible is a **Group**.

The subset $M^{\times}$ which contains all the reversible elements of a monoid $M$ construct a group, which is defined as the **Unit Group** of $M$.

Formally, a group, with binary operation $\cdot$, is restricted by four conditions:

1. For any element $x, y\in G$, $x\cdot y\in G$.
2. For any element $x, y, z\in G$, $(x\cdot y)\cdot z = x\cdot (y\cdot z)$.
3. There exists an **identical element** $e\in G$ which makes $e\cdot x = x$ for all $x\in G$.
4. There exists an **reverse element** $x^{-1}\in G$ which makes $x^{-1}\cdot x = e$ for all $x\in G$

Notice that by definition the identical $e$ and reverse element is left-operated with element $x$ traditionally, though we'll prove that the opposite side is equivlent for group.

Furthermore, if the operation equiped is also commutative, the group is called **additive** or **Abelian**, and **additive notation** is proposed if the context is proper:

1. The operation is denoted as $+$ instead of $\times$.
2. The identical element is denoted as $0$ instead of $1$.
3. The reverse element is denoted as $-x$ instead of $x^{-1}$.

Particularly in the study of ring, the one operation that is commutative almos t always use the additive notation. 



##### Property

With the four restrictions listed above, a group is such a well-structed structure with nice properties:

1. **Left Elimination Property** of left operation. If $x\cdot a = x\cdot b$ , then $a = b$.

	> Proof. Left multiple $x^{-1}$ for both sides.
	> $$
    > \begin{align}
    > x\cdot a &= x\cdot b \\
    > x^{-1}\cdot x \cdot a &= x^{-1}\cdot x\cdot b \\
    > (x^{-1}\cdot x) \cdot a &= (x^{-1}\cdot x)\cdot b \\
    > e\cdot a &= e\cdot b \\
    > a &= b
    > \end{align}
    > $$

   As noticed, this is not a simple property, the proof uses all of the restrictions of a group to make the simple elimination possible, hence the elimination law is not held for the general monoid.
   
   

2. If $x\cdot x = x$, then $x = e$. This is the specical case of the elimination property, you can multiple $x^{-1}$ to prove it.

    This property gives an important rule to tell if an element is the identical: just simply square it, and check if the result is still itself. No more element involved.



3. **Symmetric reverse element**: If $x^{-1}$ is the reversed element of $x$, so $x$ is the reverse of $x^{-1}$, which indicates $x^{-1}\cdot x = x\cdot x^{-1} = e$

	> Proof. To prove that something is an element, we try to use property(2), that is, square it and check if it returns the input.
	>
	> $$
	> (x\cdot x^{-1})\cdot(x\cdot x^{-1}) = x\cdot (x^{-1}\cdot x)\cdot x^{-1} = x\cdot x^{-1}
	> $$
	> 
	> Hence we have $x\cdot x^{-1} = e$

	By definition, if we consider $x^{-1}$ as the "original element", $x\cdot x^{-1}$ indicates that $x$ is exactly the reverse elementof $ x^{-1} $, hence $ (x^{-1})^{-1} = x$.

	Since the reverse can be multiply either to the left side or right side, the elimination property now can be generalized to the right multiple case:

	$$
	a\cdot x = b\cdot x \Rightarrow a = b
	$$



4. Identical element commutativity. $x\cdot e = e\cdot x = x$

	> Proof.
	> 
	> $$
	> x\cdot e = x\cdot ( x^{-1} \cdot x) = (x\cdot x^{-1})\cdot x = e\cdot x = x
	> $$



5. There's only one reverse element of any $x\in G$.

	> Proof. Assume there's another reverse element $x'$ for $x$.
	>
	> $$
	> \begin{align}
	> x'\cdot x = e &= x^{-1}\cdot x \\
	> x'\cdot x\cdot x^{-1} &= x^{-1}\cdot x \cdot x^{-1} \\
	> x'\cdot (x\cdot x^{-1}) &= x^{-1}\cdot (x \cdot x^{-1}) \\
	> x'\cdot e &= x^{-1}\cdot e \\
	> x' &= x^{-1}
	> \end{align} \\
	> $$



6. There's only one identical element of any $x\in G$.

	> Proof. Assume there's another identical element notes as $e'$ that statifies
	> 
	> $$
	> e'\cdot x = e\cdot x
	> $$
	>
	> Simply use the right-version elimination law, $e' = e$.
	>



7. $ (a\cdot b)^{-1} = b^{-1} \cdot  a^{-1}$.

	> Proof.
	>
	> $$
	> (a\cdot b)\cdot (b^{-1}\cdot a^{-1}) = a\cdot (b\cdot b^{-1})\cdot a^{-1} = a \cdot  a^{-1} = e
	> $$

	Generally, for any $n$ elements in the group:

	$$
	\left( \prod_{i=1}^{n} a_i \right)^{-1} = \prod_{i=n}^{1} a_{i}^{-1}
	$$



##### Example

All permutations on a set, equiped with the permutation composition, construct a **symmetric** group.

The set $\mathbb{Z}, \mathbb{Q}, \mathbb{R}, \mathbb{C}$ equiped with addition operation constructs abelian group.

To make the ring equiped with multiplication operation also constructs group we need to substract $0$ from them: $\mathbb{Q}^{\times}=\mathbb{Q}-\{0\}, \mathbb{R}^{\times}=\mathbb{R}-\{0\}, \mathbb{C}^{\times}=\mathbb{C}-\{0\}$. Notice that $\mathbb{Z}^{\times}=\mathbb{Z} - \{0\}$ still cannot constructs group since the reverse of those $n\neq\pm1$ does not hold.

It's obvious that to the general $m\times n$ dimensional vector/matrix equiped with the normal entry-wise addition operation above any group also constructs a group.

Define $M_n(\mathbb{R})$ as the set of all $n\times n$ real matrix, and $\GL(n, \mathbb{R})$ is a subset of $M_n(\mathbb{R})$ which contains the reversible parts.

As mentioned above, the $M_n(\mathbb{R})$ with the matrix addition constructs a group. Besides, $M_n(\mathbb{R})$ with matrix multiplication is a monoid, and $\GL(n,\mathbb{R})$ with matrix multiplication is a group. $\GL(n,\mathbb{R})$ is the unit group of $M_n(\mathbb{R})$. Generally, we can define $M_n(F)$ and $\GL(n, F)$ for any domain $F$. $\GL(n, F)$ is named as **General Linear Group** upon domain $F$. 



##### Power of Element

We define the $n\in\mathbb{Z}$ exponent of element $x\in G$ recursively:

$$
x^n =  \left\{
\begin{array}{ll}
\begin{align}

&1, &n = 0  \\
&x^{n-1}\cdot x, &n\ge 1 \\
&(x^{-1})^{-n}, &n\lt 0 

\end{align}
\end{array}
\right.
$$

Here're some simple properties about the exponent:

1. $(a^n)^m = a^{nm}$

2. $a^n\cdot a^m = a^{n+m}$

3. if $a, b$ commutes, then $(ab)^n = a^n b^n$

If there's one $k\ge1$ that makes $a^k = 1$, the smallest $k$ is defined as the **order** of $a$. otherwise we say $a$ has **infinite order**. It's easy to prove that, any $n$ satisifies that $a^n = 1$ must be the multiple of order $k$.

> Proof. If it is not, let $n = qk + r$ where $r\neq0$, $e = a^n = a^{qk+r} = a^{qk}a^r = a^r$, since $0<r<k$, this infers that we've found a smaller number $r$ which makes $a^r = 1$, which is contradict with the defintion of $k$.



##### Generated Group



### 2. Subgroup

##### Definition

If the subset $H\subset G$ meets

1. $1\in H$.

2. H is closed under the operation $\cdot$ of group $G$.

3. for any $x\in H$, $x^{-1}\in H$.

We define the subset $H$ is a **subgroup** of $G$. Here we don't mention about the associvity since it is ensured by the group $G$. Notice that the condition (1) is necessary to avoid $H=\varnothing$.

The **proper subgroup** is those $H\neq G$, and **nontrivial group** is those $H\neq\{1\}$.

As a shortcut for proving the subgroup, we assert that $H$ is a subgroup **iff** it's nonempty and for any $x, y\in H$, $xy^{-1}\in H$.

> Proof. ($\Rightarrow$) If $H$ is a subgroup, it's obvious that $y^{-1}\in H$, hence $xy^{-1}\in H$.
>
> ($\Leftarrow$) We're required to prove the three conditions of subgroup.
>
> (1) Let $y = x$, $xy^{-1} = xx^{-1} = 1$, so $1\in H$.
>
> (3) Based on (1), let $x = 1$, $xy^{-1} = y^{-1}\in G$.
>
> (2) Based on (3), let $y = y^{-1}$, $xy^{-1} = x(y^{-1})^{-1} = xy\in G$.
>
> This concludes that $H$ is the subgroup of $G$.

Although its tedious and hard to prove the subgroup in general group, while for finite group $G$, the subset $H\subset G$ is only required **closed** to be a subgroup, due to its **finity **, which makes there must be at least one element whose exponent will eventually "falls into itself".

> Proof. Since $H\neq \varnothing$, assume that $a\in H$, hence $a^n\in H$ for all the $n\ge0$ according to the closed conditionof $H$.
>
> In the sequence of exponent of $a$, there must be at least two integer $i<j$ which makes $a^j = a^i$, since the element number of $H\subset G$ is finite.
>
> This results in $a^{j-i} = a^{i-i} = a^0 = 1 \in H$, which ensures that the identical element is in $H$.
>
> Besides, since $j>i$, $j-i-1\ge0$, $a^{-1} = a^{j-i-1}\in H$.
>
> Hence the set $H$ is the subgroup of $G$.



##### Coset







### 3. Cyclic Group




























