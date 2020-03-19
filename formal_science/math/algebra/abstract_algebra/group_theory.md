$$
\newcommand{\GL}{\text{GL}}
$$

# Group Theory

### 1. Group

##### # Definition

A non-empty set $S$ with its **combinative** binary operation called **SemiGroup**. If there's identical element in semigroup, it's a **Monoid**. Monoid with all the elements reversible is a **Group**.

The subset $M^{\times}$ which contains all the reversible elements of a monoid $M$ construct a group, which is defined as the **Unit Group** of $M$.

Formally, a group, with binary operation $\cdot$, is restricted by four conditions:

1. For any element $x, y\in G$, $x\cdot y\in G$.
2. For any element $x, y, z\in G$, $(x\cdot y)\cdot z = x\cdot (y\cdot z)$.
3. There exists an identical element $e\in G$ which makes $e\cdot x = x$ for all $x\in G$.
4. There exists an reverse element $x^{-1}\in G$ which makes $x^{-1}\cdot x = e$ for all $x\in G$

Notice that by definition the identical $e$ and reverse element is left-operated with element $x$.



##### # Property

With the listed four conditions, a group is a well-structed set that with fine properties:



1. **Elimination Property** of left operation. If $x\cdot a = x\cdot b$ , then $a = b$.

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

    As noticed, this is not a simple property, the proof uses all of the restrictions of a group to make the simple elimination possible.



2. If $x\cdot x = x$, then $x = e$. This is the specical case of the elimination property, you can multiple $x^{-1}$ to prove it.



3. Symmetric reverse element: If $x^{-1}$ is the reversed element of $x$, so $x$ is the reverse of $x^{-1}$, which indicates $x^{-1}\cdot x = x\cdot x^{-1} = e$

> Proof. Consider use the property (2) above, we try to prove that $(x\cdot x^{-1})(x\cdot x^{-1}) = (x\cdot x^{-1})$.
>
> $$
> (x\cdot x^{-1})\cdot(x\cdot x^{-1}) = x\cdot (x^{-1}\cdot x)\cdot x^{-1} = x\cdot x^{-1}
> $$
> 
> Hence we have $x\cdot x^{-1} = e$



4. Identical element commutative. $x\cdot e = e\cdot x = x$

> 0-is Proof.
> 
> $$
> x\cdot e = x\cdot ( x^{-1} \cdot x) = (x\cdot x^{-1})\cdot x = e\cdot x = x
> $$



5. There's only one reverse element of $x$.

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



6. 





##### # Examples

###### General Linear Group

Define $M_n(\R)$ as the set of all $n\times n$ real matrix, and $\GL(n, \R)$ is a subset of $M_n(\R)$ which contains the reversible parts. Here $M_n(R)$ with matrix multiplication is a monoid, and $\GL(n,\R)$ with matrix multiplication is a group. $\GL(n,\R)$ is the unit group of $M_n(\R)$.

Generally, we can define $M_n(F)$ and $\GL(n, F)$ for any domain $F$. $\GL(n, F)$ is named as **General Linear Group** upon domain $F$. 



