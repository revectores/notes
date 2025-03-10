# Kolmogorov Complexity

$$
\newcommand{\B}{\mathcal{B}}
\newcommand{\C}{\mathcal{C}}
\newcommand{\pair}[2]{\left<#1, #2\right>}
$$

### 1. Fundamental Concepts

##### # Complexity

Denote the set of objects by $S$, and assume some standard enumeration of objects $x$ by natural numbers $n(x)$. However, $n(x)$ may not be the most economical way to specify $x$. To compare methods of specification, we view such a method as a partial function $f$ over the nonnegative integers $p$ defined by $n = f(p)$.

The map constructed by lexicographic ordering of $\B^* = \{0, 1\}^*$

$$
(\epsilon, 0), (0, 1), (1, 2), (00, 3), (01, 4), (10, 5), (11, 6), \ldots
$$

is used to define the length of $p$, denoted as $l(p)$. For instance we have $l(4) = \text{len}(01) = 2$.

For each object $x$ in $S$, the **complexity** of object $x$ with respect to the specifying method $f$ is defined as

$$
C_f(x) = \min\{l(p): f(p) = n(x)\}
$$

and $C_f(x) = \infty$ if there are no such $p$.

In computer science terminology, we would say that $p$ is a **program** and $f$ is a **computer**, so that $C_f(x)$ is the minimal length of a program for $f$ to compute output $x$ without additional input.



##### # Additively Optimal

Consider distinct methods $f_1, f_2, \ldots, f_r$ of specifying the objects of $S$, we can construct such a method $f$ which makes

$$
C_f(x) \le \min\{C_{f_i}(x)\} + c, \quad i = 1, 2, \ldots, r
$$

where $c \le \log r$, by reserve the first $\log r$ bits of $p$ to identify the method $f_i$ that should be followed, using as a program the remaining bits of $p$.

We say that a method $f$ **(additively) minorizes** a method $g$ if there is a constant $c$ such that for all $x$

$$
C_f(x) \le C_g(x) + c
$$

Two methods $f$ and $g$ are called **equivalent** if each of them minorizes the other.

Let $\C$ be a subclass of the partial functions over the nonnegative integers. A function $f$ is **additively optimal** for $\C$ if it belongs to $\C$ and if for every function $g\in\C$ there is a constant $c_{f, g}$ such that $C_f(x)\le C_g(x) + c_{f, g}$ for all $x$.

All additively optimal methods $f, g$ of specifying objects in $S$ are equivalent iff

$$
|C_f(x) - C_g(x)| \le c_{f, g}
$$

for all $x$.

Consider the class of description methods consisting of all partial functions over the nonnegative integers. Every additively optimal function $f$ for this class must be unbounded.

> **Proof**. Take an infinite sequence $x_1, x_2, \ldots$ such that $C_f(x_i) \ge i$. Define the function $g$ by $g(i) = x_i$, we have
> 
> $$
> C_g(x_i) = \log i + O(1) \ll C_f(x_i)
> $$
> 
> Therefore, $f$ cannot be additively optimal. Thus, there is no additively optimal partial function, and the hierarchy of complexities with respect to the partial functions does not have any minimal element.







### 2. The Invariance Theorem

##### # The Invariance Theorem: Unconditional Form

The development of the theory of Kolmogorov complexity is made possible by the remarkable fact that, the class of [partial recursive functions]() possesses a universal element that is additively optimal. This is quite a natural restriction of description methods, since the partial recursive functions are precisely the functions that can be computed by [Turing machines]().

> **The Invariance Theorem: Unconditional Form**. There is an additively optimal universal partial recursive function.
>
> **Proof**. Let $\phi_0$ be the function computed by a universal Turing machine $U$, which expects inputs of the format
> 
> $$
> \pair n p = 1^{l(n)}0n~p
> $$
> 
> The interpretation is that the total program $\left< n, p \right>$ is a two-part code of which the first part $1^{l(n)}0n$ consists of a self-delimiting encoding of $T_n$, and the second part $p$ is the literally rendered program $p$. In this way, $U$ can first parse the binary input to the $T_n$-part and the $p$-part, and subsequently **simulate** the computation of $T_n$ started with program $p$ as its input. That is,
> 
> $$
> \phi_0(\pair n p) = \phi_n(p)
> $$
> 
> Specially, we set $U = T_0$ to deal with $\left<n, p\right> = 0p$ case. Now if $T_n$ computes the partial recursive function $\phi_n$, then
> 
> $$
> C_{\phi_0}(x) \le C_{\phi_n}(x) + c_{\phi_n}
> $$
> 
> where $c_{\phi_n}$ can be set to $2l(n) + 1$.



##### # The Invariance Theorem: Conditional Form

Generally, the complexity $C_\phi$ of $x$ **conditional to** $y$ is defined by

$$
C_\phi(x|y) = \min\{l(p): \phi \pair y p = x\}
$$

and $C_\phi(x|y) = \infty$ if there are no such $p$. We call $p$ a program to compute $x$ by $\phi$, given $y$.

> **The Invariance Theorem: Conditional Form**. There is an additively optimal universal partial recursive function $\phi_0$ for the class of partical recursive functions to compute $x$ given $y$. Therefore,
> 
> $$
> C_{\phi}(x|y) \le C_\phi(x|y) + c_\phi
> $$
> 
> for all partical recursive functions $\phi$ nad all $x$ and $y$.
>
> **Proof**. Let $\phi_0$ be the function computed by a universal Turing machine $U$ such that $U$ started on input $\pair{y}{\pair n p}$ simulates $T_n$ on input $\pair y p$. That is, if $T_n$ computes the partial recursive function $\phi_n$, then
> 
> $$
> \phi_0(\pair{y}{\pair n p}) = \phi_n(\pair y p)
> $$
> 
> Hence, for all $n$
> 
> $$
> C_{\phi_0}(x|y) \le C_{\phi_n}(x|y) + c_{\phi_n}
> $$
> 
> where $c_{\phi_n} = 2l(n) + 1$.

The key point is not that the universal description method necessarily gives the shortest description in each case, but that **no other description method can improve on it infinitely by more than a fixed constant**.

For every pair $\psi, \psi'$ of additively optimal functions, there is a fixed constant $c_{\psi, \psi'}$, depending only on $\psi$ and $\psi'$, such that for all $x, y$ we have

$$
\left|C_{\psi}(x|y) - C_{\psi'}(x|y) \right| \le c_{\psi, \psi'}
$$

The proof can be easily given by substitute $\phi_0 = \psi, \phi = \psi'$ then substitute $\phi = \psi, \phi_0 = \psi'$. While the complexities according to $\psi$ and $\psi'$ are not exactly, they are **equal up to a fixed constant** for all $x$ and $y$.



##### # Kolmogorov Complexity

Now we define the **conditional Kolmogorov complexity** $C(\cdot|\cdot)$ by fixing an additively optimal universal $\phi_0$

$$
C(x|y) = C_{\phi_0}(x|y)
$$

This particualr $\phi_0$ is called the **reference function** for $C$.

The **unconditional Kolmogorov complexity** $C(\cdot)$ can be considered as a special case

$$
C(x) = C(x|\epsilon)
$$
