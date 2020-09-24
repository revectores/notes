# Function Series

$$
\newcommand{\d}{\text{d}}
\newcommand{\dt}{\d t}
\newcommand{\dx}{\d x}
\newcommand{\dy}{\d y}
$$



### 1. Basic Concepts

##### # Definition

A series with all its terms are functions defined on interval $I$ called **function series** $\displaystyle \sum_{n=1}^{\infin} u_n(x)$, for every given specific $x_0\in I$, the function series constructs a constant term series $\displaystyle \sum_{n=1}^{\infin} u_n(x_0)$. If the series converges at $x_0$, we name $x_0$ as the **converge point**, otherwise its the **diverge point**. All the converge points construct the **interval of convergence**. All the diverge points construct the **interval of divergence**.







### 2. Power Series

The power series is the series with form
$$
\sum_{n=0}^{\infin} a_nx^n = a_0 + a_1x + a_2x^2 + \cdots + a_nx^n+ \cdots
$$
where the constant $a_0, a_1, a_2, \ldots, a_n, \ldots$ are called the **coefficients of power series**. 



##### # Abel Theorem for Power Series

If the power series $\displaystyle \sum_{n=1}^{\infin} a_nx^n$ is convergent at $x=x_0$, then the power series converges for all $|x|<x_0$. If the power series is divergent at $x=x_0$, then the power series diverges for all $|x|>x_0$



**Theorem**. If the cofficients of power series $\displaystyle \sum_{n=1}^{\infin} a_nx^n$ meet $\displaystyle \lim_{n\rightarrow\infin} \left| \frac{a_{n+1}}{a_n} \right| = \rho$, then the converge radius $R = \rho^{-1}$. Specially, we consider the $0$ and $+\infin$ are reciprocal to each other.

> **Proof**. $\displaystyle \lim_{n\rightarrow\infin} \frac{a_{n+1}x^{n+1}}{a_n x^n} = \lim_{n\rightarrow\infin} \left| \frac{a_{n+1}}{a_n} \right||x| = \rho|x|$, based on the Direct comparison test, we have
>
> - If $\rho|x| < 1$, that is, $|x| \lt p^{-1}$, the series converges.
> - If $\rho|x| > 1$, that is, $|x| \gt \rho^{-1}$, the series diverges.
>
> By the definition of converge radius $R$, it is exactly $\rho^{-1}$.



##### # Property of Power Series

For the power series with converge radius $R>0$, then its sum function is continous in the interval of convergence, and can term-wise derivation and integration, that is,


$$
\displaystyle S'(x) = \sum_{n=0}^{\infin} (a_nx^n)' = \sum_{n=1}^{\infin} na_nx^{n-1}
$$

$$
\int_0^x S(x)\dx = \sum_{n=0}^{\infin} a_n\int_0^x x^n\dx
$$

The convergence will be kept during







