# Numerical Integration

$$
\newcommand{\d}{\text{d}}
\newcommand{\dx}{\d x}
\newcommand{\dy}{\d y}
\newcommand{\dt}{\d t}
\newcommand{\ddx}{\dfrac{\d}{\d x}}
\newcommand{\e}{\text{e}}
$$

### 1. Numerical Integration Introduction

##### # Numerical Integration General Form

Recall [Newton-Leibniz theorem](), based on which we compute the integral of continuous function from the primitive function:
$$
\int_a^b f(x)\dx = F(b) - F(a)
$$
However this approach could be unrealistic if the integrand is not primary elementary function, and it is even not possbile if the function is given by points.

By definition, the integral is defined as the limit of Riemann sum:
$$
\int_a^b f(x)\dx = \lim_{\Delta x_i\rightarrow0}\sum_{i=0}^{n-1}f(x_i)\Delta x_i
$$
Hence we can use the sum of finite terms to approxmiate the limit. Denote
$$
\begin{align}
& I(f) = \int_a^b f(x)\dx \\
& I_n(f) = \sum_{i=0}^n \alpha_i f(x_i)
\end{align}
$$

where $I(f)$ is the precise value of integral, and $I_n(f)$ is the approximation of $I(f)$, $x_i$ is **integral point**, and $\alpha_i$ is **integral coffieient**. The subscript $n$ represents that there are $n+1$ points. We compute the $I_n(f)$ by finding those $\alpha_i(0\le i\le n)$.



##### # Algebraic Precision

if $I_n(f)$ meets
$$
\begin{align}
& E_n(x^k) = I(x^k) - I_n(x^k) = 0,~~~~ k = 0, 1, \ldots, m \\
& E_n(x^{m+1}) = I(x^{m+1}) - I_n(x^{m+1}) \neq 0
\end{align}
$$

then we say $I_n(f)$ has $m$-degree **algebraic precision**.

> **Example**. Validate this numerical intergration formula has 3-degree algebraic precision.
> $$
> \int_0^{3h} f(x)\dx = \frac{3}{8}h[f(0)+3f(h)+3f(2h)+f(3h)]
> $$
> Let $f(x) = 1, x, x^2, x^3, x^4$ respectively:
>
> For $f(x) = 1$,
> $$
> \begin{align}
> & I(1) = \int_0^{3h} \dx = 3h  \\
> & I_3(1) = \frac{3h}{8}(1+3+3+1) = 3h
> \end{align}
> $$
> For $f(x) = x$,
> $$
> \begin{align}
> & I(x) = \int_0^{3h} x\dx = \frac{9}{2}h^2  \\
> & I_3(x) = \frac{3h}{8}(0+3h+6h+3h) = \frac{9}{2}h^2
> \end{align}
> $$
> For $f(x) = x^2$,
> $$
> \begin{align}
> & I(x^2) = \int_0^{3h} x^2\dx = 9h^3  \\
> & I_3(x^2) = \frac{3h}{8}(0 + 3h^2 + 12h^2 + 9h^2) = 9h^3
> \end{align}
> $$
> For $f(x) = x^3$,
> $$
> \begin{align}
> &I(x^3) = \int_0^{3h} x^3\dx = \frac{81}{4}h^4 \\
> &I_3(x^3) = \frac{3h}{8}(0 + 3h^4 + 24h^3 + 27h^3) = \frac{81}{4}h^4
> \end{align}
> $$
>
> For $f(x) = x^4$, 
> $$
> \begin{align}
> &I(x^4) = \int_0^{3h} x^4\dx = \frac{243}{5}h^5 \\
> &I_3(x^4) = \frac{3h}{8}(0 + 3h^4 + 48h^4 + 81h^4) = \frac{99}{2}h^5
> \end{align}
> $$
> That is, we have $I(x^k) = I_3(x^k)$ for all $k\le 3$ but $I(x^4)\neq I_3(x^4)$, hence the given intergration formula has 3-degree algebraic precision.







### 2. Numerical Integration by Interpolation

Similar to the numerical differentiation, we can interpolate the points by polynomial funtion, and use the intergal of the polynomial as the approximation $I_n(f)$.

$$
\begin{align}
\int_a^b f(x)\dx
&\approx \int_a^b L_n(x)\dx \\
&= \int_a^b \sum_{i=0}^nl_i(x)f(x_i)\dx \\
&= \sum_{i=0}^n \left(\int_a^b l_i(x)\dx \right) f(x_i)
\end{align}
$$

which gives the integral coffieients $\alpha_i = \displaystyle \int_a^b l_i(x)\dx$.

The error of integration by interpolation is the integral of the remainder term:
$$
E_n(f) = \int_a^b R_n(x)\dx = \int_a^b \frac{f^{(n+1)}(\xi(x))}{(n+1)!}\prod_{i=0}^n(x-x_i)\dx
$$
For the polynomial with degree less than $n$, $E_n(f) = 0$, hence the integral of interpolation polynomial with $n$-degree has at least $n$-degree algebraic precision.


> **Example**. Construct the numerical integration formula $I_2(f)$ for $\displaystyle\int_0^2 f(x)\dx$ by points $x_0=0, x_1=0.5, x_2=2$.
> $$
> I_2(f)
> = \int_0^2 L_2(x)\dx
> = \int_0^2 (l_0(x)f(x_0) + l_1(x)f(x_1) + l_2f(x_2))\dx
> $$
>
> $$
> \begin{align}
> & \alpha_0 = \int_0^2 l_0(x)\dx = -\frac{1}{3} \\
> & \alpha_1 = \int_0^2 l_1(x)\dx = \frac{16}{9} \\
> & \alpha_2 = \int_0^2 l_2(x)\dx = \frac{5}{9} \\
> \end{align}
> $$
>
> Hence
> $$
> I_2(f) = \frac{1}{9}[-3f(0) + 16f(0.5) + 5f(2)]
> $$







### 3. Newton-Cotes Integration

##### # General Form of Netwon-Cotes Integration

Devide the integration interval $[a, b]$ into $n$ equal intervals, each has length $h=\dfrac{b-a}{n}$. Use each interval edge $x_i = a + ih, i=0,1,\ldots, n$ to construct Lagrange polynomial:
$$
\begin{align}
\int_a^b f(x)\dx \approx \int_a^b L_n(x)\dx  = \sum_{i=0}^n \alpha_i f(x_i)
\end{align}
$$
where
$$
\alpha_i = \int_a^b l_i(x)\dx = \int_a^b \prod_{j=0\\j\neq i}^n \frac{x-x_j}{x_i-x_j}\dx
$$
To compute cofficients, Let $x = a + th, x_i = a +ih$, we have
$$
\frac{x-x_j}{x_i-x_j} = \frac{a+th-(a+jh)}{a+ih-(a+jh)}= \frac{t-j}{i-j}
$$
Hence
$$
\begin{align}
\alpha_i
&= \int_0^n \frac{t(t-1)\cdots(t-i+1)(t-i-1)\cdots(t-n)}{i!(n-i)!(-1)^{n-1}}h\dt \\
&= \frac{b-a}{n}\frac{(-1)^{n-1}}{i!(n-i)!}\int_0^nt(t-1)(t-i+1)(t-i-1)(t-n)\dt
\end{align}
$$
Denote
$$
c_i^{(n)} = \frac{(-1)^{n-1}}{i!(n-i)!n}\int_0^nt(t-1)(t-i+1)(t-i-1)(t-n)\dt
$$
then $\alpha = (b-a)c_i^{(n)}$ only depends on $n$ regardless of $x_i$. The cofficients $c_i^{(n)}$ is called the **Newton-Cotes cofficient**. The Newton-Cotes cofficients with $n=0, 1, \ldots, 6$ are given in the following list.

| $n$  | $c_0^{n}$ | $c_1^{n}$ | $c_2^{n}$ | $c_3^{n}$ | $c_4^{n}$ | $c_5^{n}$ | $c_6^{n}$ |
| ---- | --------- | --------- | --------- | --------- | --------- | --------- | --------- |
| 1    | 1/2       | 1/2       |           |           |           |           |           |
| 2    | 1/6       | 4/6       | 1/6       |           |           |           |           |
| 3    | 1/8       | 3/8       | 3/8       | 1/8       |           |           |           |
| 4    | 7/90      | 16/45     | 2/15      | 16/45     | 7/90      |           |           |
| 5    | 19/288    | 25/96     | 25/144    | 25/144    | 25/96     | 19/288    |           |
| 6    | 41/840    | 9/35      | 9/280     | 34/105    | 9/280     | 9/35      | 41/840    |

Note that we have $c_i^{(n)}> 0$ for $n\le7$, hence the approximation of integral is stable, while $c_i^{(n)}$ can be negative for $n > 8$, the approximate could be unstable.



##### # Trapezoidal Rule

Specically, when $n=1$, that is, we use the linear interpolation to approximate the integral, we get the **trapezoidal rule**:
$$
\int_a^b f(x)\dx
\approx \int_a^b L_1(x)\dx
$$
$$
L_1(f) = T(f) = \frac{b-a}{2}(f(a)+f(b))
$$

The geometric interpretation of trapezoidal rule is using the trapezoid area under the edge points of function to approximate the area under curve.

Truncation error of trapezoidal rule:
$$
\begin{align}
E_1(f)
&= \int_a^b \frac{f''(\xi)}{2!}(x-a)(x-b) \\
&= \frac{f''(\xi)}{2!} \int_a^b (x-a)(x-b) \\
&= -\frac{f''(\xi)}{12}(b-a)^3, \quad a\le\xi\le b
\end{align}
$$



###### # Simpson's Rule

Specically, when $n=2$, that is, we use the quadratic interpolation to approximate the integral, by which we get the **Simpson's rule**:
$$
\int_a^b f(x)\dx
\approx \int_a^b L_2(x)\dx
$$

$$
L_2(f) = S(f) = \frac{b-a}{6}\left(f(a) + 4f\left(\frac{a+b}{2}\right) + f(b)\right)
$$

The geometric interpretation of Simpson's rule is using the quadratic function determined by three given points to approximate the area under curve.

Truncation error of Simpson's Rule:
$$
E_2(f) = -\frac{(b-a)^5}{2880}f^{(4)}(\eta), \quad a\le\eta\le b
$$






### 4. Composite Integration

##### # Composite Integration Introduction

The existence of [Runge Phenomenon](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/formal_science/math/numerical_analysis/interpolation/interpolation.md#runge-phenomenon) make it is not possible to gurantee the convergence of Netwon-Cotes formula with high order, and the compuation of Netwon-Cotes formula with high order is unstable (proof of both predicates are omitted). To avoid the Runge phenomenon, [segmented interpolation](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/formal_science/math/numerical_analysis/interpolation/interpolation.md#segmented-interpolation) shall be applied, and the integation in the entire interval are computed as the sum of integrals in each devided intervals. This approach is named the **composite integration**.



##### # Composite Trapezoid Integration

Devide the interval $[a, b]$ into equal intervals, $x_i = a + ih, ~ i = 0,1,\ldots, n$, $h = \dfrac{b-a}{n}$. For one of the small interval $[x_i, x_{i+1}]$, we have
$$
\int_{x_i}^{x_{i+1}}f(x)\dx = \frac{h}{2}(f(x_i) + f(x_{i+1})) - f''(\xi_i)\frac{h^3}{12}
$$

then
$$
I(f)
= \int_a^b f(x)\dx
= \sum_{i=0}^{n-1}\int_{x_i}^{x_{i+1}} f(x)\dx, \quad x\in[x_{i}, x_{i+1}]
$$
Sum up all the small intervals:
$$
\begin{align}
I(f) &= \sum_{i=0}^{n-1}\left[ \frac{h}{2}(f(x_i)+f(x_{i+1})) - f''(\xi_i)\frac{h^3}{12} \right] \\
&= h\left[ \frac{1}{2}f(a) + \sum_{i=1}^{n-1}f(x_i) + \frac{1}{2}f(b) \right] - \frac{h^3}{12}\sum_{i=1}^{n-1}f''(\xi_i)
\end{align}
$$
$I(f) = T(h) + E_n(f)$, contains the integral term and remainder term , where
$$
T(h) = T_n(f) = h\left[ \frac{1}{2}f(a) + \sum_{i=1}^{n-1} f(x_i) + \frac{1}{2}f(b) \right]
$$

$$
E_n(f) = -\frac{h^3}{12}\sum_{i=0}^{n-1}f''(\xi_i)
$$

We can also use a table to compute and memorize coefficients of composite trapezoid integration:

|      | $x_0$ | $x_1$ | $x_2$ | $x_3$ |
| :--: | :---: | :---: | :---: | :---: |
| $h$  |  1/2  |  1/2  |       |       |
|      |       |  1/2  |  1/2  |       |
|      |       |       |  1/2  |  1/2  |
|      |  1/2  |   1   |   1   |  1/2  |



##### # Composite SimpSon Integration

The formula and remainder term of composite SimpSon integration can be computed similarly:
$$
S_n(f) = \frac{h}{3}\left[ f(a) + 4\sum_{i=0}^{m-1}f(x_{2i+1}) + 2\sum_{i=1}^{n-1}f(x_{2i}) + f(b) \right]
$$

$$
E_n(f) = -\frac{(2h)^5}{2880}f^{(4)}(\xi_i), ~ x_{2i}\le\zeta_i\le x_{2i+2}
$$

We can also use a table to compute and memorize coefficients of composite Simpson integration:

|       | $x_0$ | $x_1$ | $x_2$ | $x_3$ | $x_4$ | $x_5$ | $x_6$ | $x_7$ | $x_8$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| $h/6$ |   1   |   4   |   1   |       |       |       |       |       |       |
|       |       |       |   1   |   4   |   1   |       |       |       |       |
|       |       |       |       |       |   1   |   4   |   1   |       |       |
|       |       |       |       |       |       |       |   1   |   4   |   1   |
| $h/6$ |   1   |   4   |   2   |   4   |   2   |   4   |   2   |   4   |   1   |




> **Example**. Compute $\displaystyle \int_0^1 \e^x\dx$ to 5 decimal percision, how many points should be computed?



> **Example**. Compute $\displaystyle \int_0^{1.2}\sin x^2\dx$ based on Newton-Cotes formula, composite trapezoid integration, and composite Simpson integration.



##### # Automatic Precision Control

The truncation error decreases as the number of divided intervals grows, to control the precision we must find the interval counts $n$.

In practice, we use $|T_{2n}(f) - T_n(f)|$ to approxiamte the current precision, the series $T_n(f), T_{2n}(f), \ldots$ is computed sequentially until for some $m$ which meets
$$
|T_{2m}(f) - T_m(f)| < \varepsilon
$$
or
$$
\left|\frac{T_{2m}(f) - T_m(f)}{T_{2m}(f)}\right| < \varepsilon
$$
and use the $T_{2m}(f)$ as the approximation of $I(f)$.



##### # Romberg Integration

The composite Newton-Cotes interpolation with higher order can be computed by those with lower order by adding the error term, for instance, the Simpson integration $S_n(f)$ can be comptued by the combination of trapezoidal $T_n(f), T_{2n}(f)$ by adding the error term.

To illustrate the principle, consider the error of $T_n(f)$ and $T_{2n}(f)$:
$$
\begin{align}
& I(f) - T_n(f) = -\frac{1}{12}f''(\xi)h^2 = ch^2 \\
& I(f) - T_{2n}(f) = -\frac{1}{12}f''(\xi)\left(\frac{h}{2}\right)^2 = c\left(\frac{h}{2}\right)^2
\end{align}
$$

Notice the differences above are approximately proportionate, we can use the difference between trapezoidal integration with different intervals to approximate the error to the precise value:
$$
3(I(f) - T_{2n}(f)) = T_{2n}(f) - T_n(f)
$$
If we use the difference $T_{2n}(f) - T_n(f)$ to "correct" $I(f)$:
$$
\begin{align}
I(f) &= T_{2n}(f) + \frac{1}{3}(T_{2n}(f) - T_n(f)) \\
&= \frac{4}{3}T_{2n} - \frac{1}{3}T_n = S_n
\end{align}
$$
This approach reduce the truncation error from $O(h^2)$ to $O(h^4)$ without extra computation complexity.

Generally, we can use this approach to reduce the truncation by correct with the error terms repeatedly, this is **Romberg method**:

| $R_{1,1}$  |            |           |          |           |
| :--------: | :--------: | :-------: | :------: | --------- |
| $R_{2,1}$  | $R_{2,2}$  |           |          |           |
| $R_{3,1}$  | $R_{3,2}$  | $R_{3,3}$ |          |           |
|  $\vdots$  |  $\vdots$  | $\vdots$  | $\ddots$ |           |
| $R_{m, 1}$ | $R_{m, 2}$ | $R_{m,3}$ | $\ldots$ | $R_{m,m}$ |

where

$$
\begin{align}
& R_{k, 1} = T\left(\frac{h}{2^{k-1}}\right) \\
& R_{k,j} = R_{k, j-1} + \frac{R_{k, j-1}-R_{k-1,j-1}}{4^{j-1}-1}, ~~~~ k \ge 2, j \ge 2 
\end{align}
$$
Compute repeatedly until the $|R_{k,k}-R_{k-1,k-1}|$ meets the required precision.

