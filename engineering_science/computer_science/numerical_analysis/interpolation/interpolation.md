# Interpolation

For the continous function $f(x)$ defined in $[a,b]$, points $x_0, x_1, \ldots , x_n$ are $n+1$ different points in $[a,b]$, $\varPhi$ is some function class, if $\phi(x)\in\varPhi$ meets
$$
\phi(x_i) = f(x_i), ~~~~i=0,1,\ldots, n
$$
we say $\phi(x)$ is the **interpolation function** of $f(x)$ in $\varPhi$ about $x_0, x_1, \ldots, x_n$. 

Polynomial function is smooth infinitely, the derivative and integral are easy to compute, hence we usually use the polynomial as the interpolation function.



### 1. Lagrange Interpolation






$$
\left\{\begin{array}{ll}
a_0 + a_1x_0 + a_2x_0^2 + \cdots + a_nx_0^n = f(x_0) & \\
a_0 + a_1x_1 + a_2x_1^2 + \cdots + a_nx_1^n = f(x_1) & \\
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\cdots \\
a_0 + a_1x_n + a_2x_n^2 + \cdots + a_nx_n^n = f(x_n)
\end{array}\right.
$$
The coefficient determinant
$$
V(x_0, x_1, \ldots, x_n) =

\begin{vmatrix}
1 & x_0 & x_0^2 & \cdots & x_0^n \\
1 & x_1 & x_1^2 & \cdots & x_1^n \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
1 & x_n & x_n^2 & \cdots & x_n^n \\
\end{vmatrix}

= \prod_{0\le k\le i\le n}(x_i - x_j)
$$
For different $x_i, 0\le i\le n$, the value of determinant $\prod_{0\le k\le i\le n}(x_i - x_j) \neq 0$, hence there's one and only one solution.
$$
l_i(x)
= \prod_{j=0\\j\neq i}^n \frac{x-x_j}{x_i-x_j}
= \frac{(x-x_0)\cdots(x-x_{i-1})(x-x_{i+1})\cdots(x-x_n)}{(x_i-x_0)\cdots(x_i-x_{i-1})(x_i-x_{i+1})\cdots(x_i-x_n)}
$$

$$
L_n(x)
= \sum_{i=0}^n l_i(x)f(x_i)
= \sum_{i=0}^n \prod_{j=0\\j\neq i}^n \frac{x-x_j}{x_i-x_j}f(x_i)
$$
The primary function are orthogonal,
$$
l_i(x_j) = \delta_{ij} =
\left\{\begin{array}{ll}
1,& i=j & \\
0,& i\neq j&
\end{array}\right.
$$


For the linear Lagrange interpolation,
$$
R(x) = f(x) - L_1(x) = \frac{f''(\xi)}{2!}(x-x_0)(x-x_1), ~~~~ \xi\in[a,b]
$$

> **Proof.** For $R(x) = f(x) - L_1(x)$, since $f(x_0) = L_1(x_0), f(x_1) = L_1(x_1)$, we have $R(x_0) = R(x_1) = 0$. Let
> $$
> R(x) = k(x)(x-x_0)(x-x_1)
> $$
> Construct the difference
> $$
> \Psi(t) = f(t) - L_1(t) - k(x)(t-x_0)(t-x_1)
> $$
> we have $\Psi(x_0) = \Psi(x_1) = \Phi(x) = 0$, without loss of generality, assume $x_0<x<x_1$, applying Rolle's theorem in section $[x_0, x]$ and $[x, x_1]$, we have $\Psi(\xi_1) = \Psi(\xi_2) = 0$, where $\xi_1\in[x_0, x], \xi_2\in[x, x_1]$. Applying Rolle's theorem to $\Psi'(t)$ in section $[\xi_1, \xi_2]$, we have $\Psi''(\xi)=0$, where $\xi\in[\xi_1,\xi_2]$.
>
> Substitute $t$ with $\xi$,
> $$
> \begin{align}
> f''(t) - 2!k(x) &= \Psi''(t) \\
> f''(t) - 2!k(x) &= 0 \\
> k(x) &= \frac{f''(\xi)}{2!}
> \end{align}
> $$
> That is,
> $$
> R(x) = f(x) - L_1(x) = \frac{f''(\xi)}{2!}(x-x_0)(x-x_1)
> $$

For the quadratic Lagrange interpolation,
$$
R(x) = f(x) - L_1(x) = \frac{f^{(3)}(\xi)}{3!}(x-x_0)(x-x_1)(x-x_2),~~~~ \xi\in[a,b]
$$
Generally,
$$
R_n(x) = f(x) - L_n(x) = \frac{f^{(n+1)}(\xi)}{(n+1)!}\prod_{i=0}^n(x-x_i),~~~~\xi\in[a, b]
$$


> 
> $$
> \begin{align}
> |R(x)|
> &= \left| \frac{f''(\xi)}{2!}(x-x_{i-1})(x-x_i) \right| \\
> &= \left| \frac{\sin(\xi)}{2}(x-x_{i-1})(x-x_i) \right| \\
> &\le \frac{1}{2} |(x-x_{i-1})(x-x_i)| \\
> &\le \frac{1}{2} \left|\left( \frac{x_{i-1}+x_i}{2}-x_{i-1}\right) \left( \frac{x_{i-1}+x_i}{2}-x_i\right) \right| \\
> &= \frac{1}{8}|(x_{i-1}-x_i)(x_i-x_{i-1})| \\
> &= \frac{h^2}{8} \le \frac{1}{2}\times 10^{-4}
> \end{align}
> $$
> Hence $h\le 0.02$





### 2. Newton's Interpolation

##### # Difference Quotient

$$
f[x_0, x_1] = \frac{f(x_1)-f(x_0)}{x_1-x_0}
$$





