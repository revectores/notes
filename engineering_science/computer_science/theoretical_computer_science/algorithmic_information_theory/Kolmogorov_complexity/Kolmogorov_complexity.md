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

