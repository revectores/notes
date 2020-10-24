$$
\newcommand{\o}{\overline}
$$

# Set Theory

### 1. Basic Concepts

##### # Definition and Expressions

##### # Relation between set and element

A 

In relation's persepective, **subset relation** between sets is dreflective, anti-symmetric, and transtive.



##### # Classification of Set

A set is a **Family of Sets** if its elements are all sets.

 

##### #  Operation of Set

###### - Binary Operator

**Cartesian Product** $A\times B = \{(x, y) \ | \ x \in A, y \in B\}$. $n$-tuple case can be defined simliarly. The element number $|A\times B| = |A|\times |B|$.



###### - Unary Operator

**Power Set** $\mathcal{P} (A)$, or notes as $2^A$, represents all subsets of set $A$. The element number $|\mathcal P(A)| = 2^{|A|}$

An interesting example: $\mathcal P(\varnothing) = {\{\varnothing\}}$. $\mathcal P(\{\varnothing\})$

An recursion algorithm for calculating the power set: let $B = A -\{a\}$, then $\mathcal P(A) = \mathcal P(B) \cup \{X\cup \{a\}| X \in \mathcal P(B)\}$. The implements store in `dm/set.py/power_set()`, `dm/set.m/power_set()`.

```python
def power_set(A):
    if not A: return {frozenset()}
    a = A.pop()
    B = power(A)
    return B.union([b.union([a]) for b in B])

print(power({1,2,3}))
```

###### - Inifinte Operator

**Generalized union/intersection** The union/intersection of all elements of elements of set $A$.

Empty Set Special Case: $\bigcup \varnothing = \varnothing$,  $\bigcap \varnothing = U$.

Prov. According to the definition, $\bigcap \varnothing = \{x \in U |X\in \varnothing, x \in X\}$, since there is no element in $\varnothing$, the condition is always true, as the result,  $\bigcap \varnothing = U$.

Ex. $A_n = \Big\{ x| 0 < x < 1 + \cfrac{1}{n}, n\in\mathbb N \Big\}$, $\bigcap\limits_{n\in\mathbb N} A_n = (0, 1]$. This shows how we achieve the closed interval(set) through open interval(set):

> Closed Set are closed under infinitely many unions and insections.



##### # The Attribute of Set Calculation

[Computer Auto Set Formula Proving] Assume all the sets in the formula are $A_1, A_2, ... A_n$, list $2^n$ possible combination of element-set belong relations, check them all about weather the two sides of formula are equal.



##### # Contradiction of Set Theory: **Russell Paradox**

Russell Paradox generated from the free of elements, a wide range of objects, whatever descriable, can be considered as the element of set.



### 2. Cardnials

##### # Definition

Def. If and only if there's a bijective between two sets $A$ and $B$, we say these two set got the same **Cardnial Number** or **Cardnials**, notes as $A\sim B$, Apparetly, finite sets are equinumerous if and only if they got the same number of elements. Obviously cardniality relation is an equivlance relation.

Some typical infinite sets cardniality examples:

- $(0, 1)\sim(a,b)\sim\mathbb{R}$

- $\mathbb{N}\sim m\mathbb{N}\sim\mathbb{Z}\sim n\mathbb{Z}, \quad m,n\in\mathbb{Z}$.

> E.G. To prove $(0, 1)\sim\mathbb{R}$, the only thing we have to do is to construct a bijective function
> $$
> f(x) = \tan\left(x-\cfrac{1}{2}\right)\pi
> $$
> This illustrates that $(0,1)\sim\mathbb{R}$.

To describe the cardnials of set by number and symbols, we define the cardnials of finite set as the number of elements, and cardnials of infinite set as symbol $\aleph_n$, where $n$ varies among different cardnials of set. The cardnial of set $A$ is noted as $|A|$.
##### # Countable Set

Set $A$ is **Countable** if there exists a linear series which contains all the elements of $A$ without repeat. It's easy to prove that all the finite sets and those sets sharing cardniality $\aleph_0$ are countable, otherwise it's uncountable.

The generalized union or join of countable number of countable set is also countable.

> E.G. All the strings $\Sigma^*$ generated from a finite alphabet $\Sigma$ is countable.
>
> Prove. Notices that $\Sigma^* = \bigcup_{i=0}^{n}\Sigma_n$, since $\mathbb{N}$ is the countable set, the result of the generalized union is also countable.

The proof of countable usually require some tricky manual contruction, here the proof of countability of $\mathbb{Q}$ shows one of the 

> E.G. Rational Number $\mathbb{Q}$ is countable.
>
> Prove. $\mathbb{Q} = \mathbb{Q}^- \cup \{0\} \cup \mathbb{Q}^+$. 

##### # Uncountable Set

> Proposition. $(0,1)$ is uncountable.
>
> Prove. (Base 2) Assume that $(0,1)$ is countable, let
> $$
> a_1 = 0.b_{11}b_{12}b_{13}... \\
> a_2 = 0.b_{21}b_{22}b_{23}... \\
> a_3 = 0.b_{31}b_{32}b_{33}... \\
> $$
> Construct $a = \o{b_{11}}\o{b_{22}}\o{b_{33}}...\notin\{a_1, a_2, a_3, ...\}$, which implies that there're always some elements $a\in(0,1)$ can not be counted in. This concludes that $(0,1)$ is uncountable.



For any set $A$, $|A| < |P(A)|$.

> Prove. Assume there's a bijective $f(x)$ between $A$ and $P(A)$, define set
> $$
> S = \{x\ |\ x\in A, x\notin S\}
> $$
> 

There exists the proper subset of infinite set which cardinal with the infinite set itself, while it's impossible for finite set. This property can be used to **DEFINE** infinite set.

> Prove. All the 





The sequence of all the possible cardinal is transinfinite:
$$
0,\ 1,\ 2,\ ...,\ n,\ ...,\ \aleph_0,\ \aleph_1,\ \aleph_2,\ ...,\ \aleph_n,\ ...
$$
where $\aleph_0$ is the **Smallest** infinite cardnials which represents the cardnials of $\mathbb{N}$.




