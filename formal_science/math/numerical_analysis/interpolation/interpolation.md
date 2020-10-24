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
The base function are orthogonal,
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

Define the $k$-th difference quotient as
$$
f[x_0, x_1, \ldots, x_k] = \frac{f[x_1, x_2, \ldots, x_k] - f[x_0, x_1, \ldots, x_{k-1}]}{x_k - x_0}
$$
Specially, the 1st, 2nd and 3rd difference quotients are
$$
f[x_0] = f(x_0)
$$

$$
f[x_0, x_1] = \frac{f(x_1)-f(x_0)}{x_1-x_0}
$$

$$
f[x_0, x_1, x_2] = \frac{f[x_1, x_2] - f[x_0, x_1]}{x_2 - x_0}
$$



##### # Property of Difference Quotient

Property 1. The $k-$th difference quotient is the linear combination of function value $f(x_0), f(x_1), \ldots, f(x_k)$.
$$
f[x_0, x_1, \ldots, x_k] = \sum_{i=0}^k \frac{1}{(x_i-x_0)\cdots(x_i-x_{i-1})(x_i-x_i)\cdots(x_i-x_k)}f(x_i)
$$
Property 2. For any permutations $i_0, i_1, \ldots, i_k$ of $0,1,\ldots, k$, we have
$$
f[x_0, x_1, \ldots, x_k] = f[x_{i_0}, x_{i_1}, \ldots, x_{i_k}]
$$
Property 3. If $f(x)$ has the $(n-1)$-th continous derivative and $f^{(n)}(x)$ exists,
$$
f[x_0, x_1, \ldots, x_k] = \frac{f^{(n)}(\xi)}{n!}
$$

> Example. Compute $f[1,2,3,4]$ and $f[1,2,3,4,5]$ for the function $f(x) = 10x^3 - 100x + 1$.
> $$
> f[x_0, x_1, x_2, x_3] = \frac{f^{(3)}(\xi)}{3!} = 10 \\
> f[x_0, x_1, x_2, x_3, x_4] = \frac{f^{(4)}(\xi)}{4!} = 0
> $$

Difference quotient table:

|   $i$    |  $x_i$   | $f(x_i)$ | $f[x_{i-1}, x_i]$ | $f[x_{i-2}, x_{i-1}, x_i]$ | $f[x_{i-3}, x_{i-2}, x_{i-1}, x_i]$ |
| :------: | :------: | :------: | :---------------: | :------------------------: | :---------------------------------: |
|   $0$    |  $x_0$   | $f(x_0)$ |                   |                            |                                     |
|    1     |  $x_1$   | $f(x_1)$ |   $f[x_0, x_1]$   |                            |                                     |
|    2     |  $x_2$   | $f(x_2)$ |   $f[x_1, x_2]$   |     $f[x_0, x_1, x_2]$     |                                     |
|    3     |  $x_3$   | $f(x_3)$ |   $f[x_2, x_3]$   |     $f[x_1, x_2, x_3]$     |       $f[x_0, x_1, x_2, x_3]$       |
| $\vdots$ | $\vdots$ | $\vdots$ |     $\vdots$      |          $\vdots$          |              $\vdots$               |
|   $n$    |  $x_n$   | $f(x_n)$ | $f[x_{n-1}, x_n]$ | $f[x_{n-2}, x_{n-1}, x_n]$ | $f[x_{n-3}, x_{n-2}, x_{n-1}, x_n]$ |



##### # Newton's Interpolation

The $n$-th newton's interpolation.
$$
\begin{align}
N_n(x) =
& f(x_0) + \sum_{k=1}^n f[x_0, x_1, \ldots, x_k]\prod_{i=0}^{k-1}(x-x_i)
\\
=& f[x_0] + f[x_0, x_1](x-x_0) + f[x_0, x_1, x_2](x-x_0)(x-x_1) + \cdots \\
&+ f[x_0, x_1, \ldots , x_n](x-x_0)(x-x_1)\cdots(x-x_{n-1})
\end{align}
$$
Reminder term
$$
R_n(x) = (x-x_0)(x-x_1)\cdots(x-x_n)f[x, x_0, x_1, \ldots, x_n]
$$







### 3. Hermite Interpolation

If the interpolation requires not only the the function value itself but also its derivatives (for some points and orders), it's called **Hermite interpolation**. 
$$
\begin{align}
H_3(x) =& \left( 1 + 2\frac{x-x_0}{x_1-x_0} \right)\left( \frac{x - x_1}{x_0 - x_1} \right)^2 y_0 + \left( 1 + 2\frac{x-x_1}{x_0-x_1} \right)\left( \frac{x - x_0}{x_1 - x_0} \right)^2 y_1
\\
&+ (x-x_0)\left(\frac{x-x_1}{x_0-x_1}\right)m_0 + (x-x_1)\left( \frac{x-x_0}{x_1-x_0} \right)m_1
\end{align}
$$



For the given $(x_i, f(x_i), f'(x_i)), i = 0, 1, \ldots, n$, define the sequence
$$
z_0 = x_0, z_1 = x_0, z_2 = x_1, z_3 = x_1
$$

$$
H_{2n+1}(x) = f[x_0] + \sum_{k=1}^{2n+1}f[z_0, z_1, \ldots, z_k](x-z_0)\cdots(x-z_{k-1})
$$

> Example. Given $f(x_0), f(x_1), f(x_0)$, construct quadratic interpolation polynomial $H(x)$.

| $i$  |   $z_i$   | $f(z_i)$ |      $f[z_{i-1}, z_i]$      |                  $f[z_{i-2}, z_{i-1}, z_i]$                  |
| :--: | :-------: | :------: | :-------------------------: | :----------------------------------------------------------: |
|  0   | $z_0=x_0$ | $f(z_0)$ |                             |                                                              |
|  1   | $z_1=x_0$ | $f(z_1)$ |   $f[z_0, z_1] = f'(x_0)$   |                                                              |
|  2   | $z_2=x_1$ | $f(z_2)$ | $f[z_1, z_2] = f[x_0, x_1]$ | $f[z_0, z_1, z_2] = \dfrac{f[x_0, x_1] - f'(x_0)}{x_1 - x_0}$ |

$$
\begin{align}
& H(x) = f(x_0) + (x-x_0)f'(x_0) + \frac{f[x_0, x_1] - f'(x_0)}{x_1-x_0}(x-x_0)^2 \\
& R(x) = \frac{f'''(\xi)}{3!}(x-x_0)^2(x-x_1), ~~~~\xi\in[x_0, x_1]
\end{align}
$$







### 4. Subsection Interpolation









### 5. Cubic Spline Function

Given the $n+1$ points 
$$
f(x_i) = y_i, 0\le i\le n
$$
Construct cubic polynomial
$$
S(x) = a_ix^3 + b_ix^2 + c_ix + d_i,~ i= 0, 1,\ldots, n-1
$$


and we enforce the zero, first, and second derivatives of adjacent interval continuous:
$$
\left\{\begin{array}{ll}
S_{i-1}(x_i) = S_i(x_i)  \\
S'_{i-1}(x_i) = S'_i(x_i)  \\
S''_{i-1}(x_i) = S''_i(x_i)
\end{array}\right.
$$


##### # M Relation

Denote $M_i = f''()$
$$
S''(x) =
$$


Finally we have
$$
\mu_i M_{i-1} + 2M_i + \lambda_i M_{i+1} = d_i, ~~i=1,2,\ldots, n-1
$$
where
$$
\left\{\begin{array}{ll}
h_i = x_{i+1} - x_i \\
\lambda = \dfrac{h_i}{h_i + h_{i-1}} \\
\mu_i = 1 - \lambda_i \\
d_i = 6y[x_{i-1}, x_i, x_{i+1}]
\end{array}\right.
$$


> Example. Given the points
>
> |  $x$   |  1.1   |  1.2   |  1.4   |  1.5   |
> | :----: | :----: | :----: | :----: | :----: |
> | $f(x)$ | 0.4000 | 0.8000 | 1.6500 | 1.8000 |
>
> Let $M_0=M3$, construct the $M$ Relationship of cubic spline function and compute $f(1.25)$.
> $$
> \begin{align}
> & h_0 = x_1 - x_0 =  \\
> & h_1 = x_2 - x_1 =  \\
> & h_2 = x_3 - x_2 =  \\
> & \lambda_1 = \frac{h_1}{h_1+h_0} = \\ 
> & \lambda_2 = \frac{h_2}{h_2+h_1} = \\
> & \mu_1 = 1-\lambda_1 \\
> & d_1 =  \\
> & d_2 =  \\
>\end{align}
> $$
> 
> Since $M_0 = M_3$
> $$
> \begin{bmatrix}
> 2 & 0.6667 \\
> 0.6667 & 2
> \end{bmatrix}
> \begin{bmatrix}
> M1 \\
> M2
> \end{bmatrix}
> =
> \begin{bmatrix}
> 5 \\
> -55
> \end{bmatrix}
> $$
>
> The solution $M_1=13.125, M_2=-31.875$,
>
> $$
> S(x) =
> $$
>
> 
>
> 










Advantage: The second derivatives are continuous, and human cannot notice the discontinuity of third level derivative.















