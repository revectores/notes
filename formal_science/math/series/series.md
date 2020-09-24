# Series

### 1. Basic Concept for General Series

##### # Definition

Given the sequence $u_1, u_2, \ldots, u_n, \ldots$, the sum $u_1 + u_2 + \cdots + u_n + \cdots$ is called the **infinite series** or **series**, denoted by  $\displaystyle \sum_{i=1}^{\infin} u_n$, where the $u_n$ is called the **general term** of the series.

We define the sum of infinite series by its **partial sum sequence**:

If the partial sum sequence $\{s_n\}, s_n := \displaystyle \sum_{i=1}^{n}u_i $ of series $\displaystyle \sum_{i=1}^{\infin} u_n$ has limit $s = \displaystyle \lim_{n\rightarrow\infin} s_n$, then we say the series **converges**, and the limit $s$ is defined as the **sum** of the series, otherwise we say the series **diverges**.

The difference between the limit and the partial sum is called the **remainder terms** $r_n$:
$$
r_n = s - s_n = \sum_{i=n+1}^{\infin} u_i
$$
If we use partial sum $s_n$ to estimate the sum of series $s$, then the error will be absolute value of remainder $|r_n|$.



##### # Basic Property

1. **Linearity**. If series $\displaystyle \sum_{i=1}^{\infin} u_n, \sum_{i=1}^{\infin} v_n$ converges to $s, \sigma$ respectively, then the series $\displaystyle \sum_{i=1}^{\infin} (k_1u_n \pm k_2v_n)$ converges to $k_1s + k_2\sigma$. This can be inferred by the linearity of the limit of sequence immediately.

2. Adding or removing finite term will not change the convergene of series.

3. Adding arbitrary parentheses to the series will not change the convergence of series.

    **Corollary**. If the series with parentheses added is divergent, then the primitive series is also divergent.

    > **Example**. Prove the harmonic series $\displaystyle \sum_{i=1}^{\infin} \frac{1}{i}$ is divergent.
    >
    > **Proof**.
    > $$
    > \begin{align}
    > \sum_{i=1}^{\infin} \frac{1}{i}
    > &= 1 + \frac{1}{2} + \frac{1}{3} + \cdots + \frac{1}{n} \\
    > &= 1 + \frac{1}{2} + \left( \frac{1}{3} + \frac{1}{4} \right) + \left( \frac{1}{5} + \frac{1}{6} + \frac{1}{7} + \frac{1}{8} \right) + \cdots\\
    > &\ge 1 + \frac{1}{2} + 2\times\frac{1}{4} + 4\times \frac{1}{8} + \cdots \\
    > &\rightarrow \infin
    > \end{align}
    > $$
    > hence the harmonic series is also divergent.



##### # Necessarity Condition

If the series $\displaystyle \sum_{i=1}^{\infin} u_n$ is convergent, then its general term $u_n$ approaches zero, that is, $\displaystyle \lim_{n\rightarrow\infin} u_n = 0$.

> **Proof**. Denotes the partial sum of convergent sereis $\displaystyle \sum_{i=1}^{\infin} u_n$ as $s_n$, we haves
> $$
> \displaystyle \lim_{n\rightarrow\infin} u_n = \lim_{n\rightarrow\infin} (s_n -s_{n-1}) = \lim_{n\rightarrow\infin} s_n - \lim_{n\rightarrow\infin} s_{n-1} = s - s = 0
> $$

**Corollary**. If the general term of series not approaches zero, then the series must be divergent.

**Remark**. The general term approaches zero is not the sufficient condition of convergent, the harmonic series $\displaystyle \sum_{i=1}^{\infin} \frac{1}{i}$ is a typical example.



##### # Cauchy Convergence Test

The series $\displaystyle \sum_{i=1}^{\infin} u_n$ converge, if any only if, for any given positive number $\varepsilon$, there always exists an positive number $N$ that gurantees $|u_{n+1} + u_{n+2} + \cdots + u_{n+p}| < \varepsilon$ for any $p\in \Z^+$ when $n>N$.







### 2. Convergence Test for Positive Series

##### # Bound for Partial Sum Sequence

As it named, **positive series** is the series with all its item are non-negative. In this case, the partial sum sequence $\{s_n\}$ will be an increasing sequence.

Since $\{s_n\}$ is monotone, based on the property of limit of sequence, the limit of $\{s_n\}$ exists if and only if the $\{s_n\}$ is bounded. That is, The series is convergent, if and only if its partial sum sequence $\{s_n\}$ is bounded.



##### # Direct Comparison Test

The **Direct comparison test** can be introduced based on the bound theorem. For two positive item series, if there exsits $N\in \Z^+$ which gurantees for any $n>N$, $u_n\le v_n$, then

- if $\displaystyle \sum_{i=1}^{\infin} v_n$ is convergent, then $\displaystyle \sum_{i=1}^{\infin} u_n$ is convergent.

- if $\displaystyle \sum_{i=1}^{\infin} u_n$ is divergent, then $\displaystyle \sum_{i=1}^{\infin} v_n$ is divergent.

and this can be extended to an limit form, named as **limit comparison test**:

For two positive item series $\displaystyle \sum_{i=1}^{\infin} u_n, \sum_{i=1}^{\infin} v_n$, compute the limit of the ratio $L = \displaystyle \lim_{n\rightarrow\infin} \dfrac{u_n}{v_n}$, then

- if $L\in [0, +\infin)$, then if $\displaystyle \sum_{i=1}^{\infin} v_n$ is convergent, $\displaystyle \sum_{i=1}^{\infin} u_n$ is convergent.
- if $L\in(0, +\infin]$, then if $\displaystyle \sum_{i=1}^{\infin} v_n$ is divergent, $\displaystyle \sum_{i=1}^{\infin} u_n$ is divergent.

**Remark**. This indicates that for $L\in(0, +\infin)$, the two series share the same convergence.

> Example. Discuss whether the series $\displaystyle \sum_{i=1}^{\infin}  \sin \dfrac{1}{n}$ converge.

$$
\lim_{n\rightarrow \infin} \frac{\sin \dfrac{1}{n}}{\dfrac{1}{n}} = 1
$$

and we've already known the harmonic series is divergent, hence the series $\displaystyle \sum_{i=1}^{\infin} \sin \dfrac{1}{n}$ is also divergent.

> Example. Discuss whether the series $\displaystyle \sum_{i=1}^{\infin} \ln\left(1+\frac{1}{n^2}\right)$ converge.

$$
\lim_{n\rightarrow \infin} \frac{\ln\left(1+\dfrac{1}{n^2}\right)}{\dfrac{1}{n^2}} = 1
$$

and we've already known the series $\displaystyle \sum_{i=1}^{\infin} \frac{1}{n^2}$ is convergent, hence the given series is also convergent.



##### # d'Alembert Test

For the positive term series $\displaystyle \sum_{i=1}^{\infin} u_n$, compute $\rho = \displaystyle \lim_{n\rightarrow\infin} \dfrac{u_{n+1}}{u_n}$.

- if $\rho<1$, the series is convergent.
- if $\rho>1$, the series is disvergent.
- if $\rho = 1$, the series might convergent or disvergent.



##### # Cauchy Test

For the positive term series $\displaystyle \sum_{i=1}^{\infin} u_n$, compute $\rho = \displaystyle \lim_{n\rightarrow\infin} \sqrt[n]{n}$.

- if $\rho<1$, the series is convergent.
- if $\rho>1$, the series is disvergent.
- if $\rho = 1$, the series might convergent or disvergent.









> Example. determine whether the following series converge or diverge.
>
> (1) $\displaystyle \sum \frac{e^nn!}{n^n}$

$$
\frac{u_{n+1}}{u_n} = \frac{e}{\left(1+\dfrac{1}{n}\right)^n} > 1
$$

that is, $u_n>u_{n-1} > \cdots > u_1 = e$, hence $\displaystyle \lim_{n\rightarrow\infin} u_n\neq 0$.



> (2) $\displaystyle \sum \frac{1}{n^3+3n^2+2n}$

$$
\sum \frac{1}{n^3+3n^2+2n} = \frac{1}{n(n+1)(n+2)}
$$



> (3) $\displaystyle \sum \frac{2n-1}{2^n}$

$$
S_n = 3 - \frac{1}{2^{n-2}} - \frac{2n-1}{2^n}
$$

hence $\displaystyle \lim_{n\rightarrow \infin} u_n =3$.








Theorem. The $\displaystyle \sum_{i=1}^{\infin} u_n$ converge if any only if $S_n$ is bounded.





> Example. Discuss whether the series $1 + \dfrac{1}{2^p} + \dfrac{1}{3^p} + \cdots + \dfrac{1}{n^p} + \cdots$ converge











### 3. Convergence Test For Alternating Series

##### # Defintion of Alternating Series

The alternating series is the series in the form $\displaystyle \sum_{n=1}^{\infin} (-1)^{n-1}u_n$ or $\displaystyle \sum_{n=1}^{\infin} (-1)^{n}u_n$. That is, the series with alternating positive number and negative number.



##### # Leibniz Convergence Test

For the alternating series $\displaystyle \sum_{n=1}^{\infin} (-1)^{n-1}u_n$, if $\displaystyle u_ n\ge u_{n+1}, \lim_{n\rightarrow\infin} u_n=0$, then the series converges, and the absolute value of remainder $|r_n|\le u_{n+1}$.

> **Proof**. 

> Example. The alternating harmonic series $\displaystyle \sum_{n=1}^{\infin} (-1)^{n-1}\frac{1}{n}$ converges, since $\dfrac{1}{n}\ge \dfrac{1}{n+1}$ and $\displaystyle \lim_{n\rightarrow\infin} \dfrac{1}{n} = 0$.







### 4. Absolutely Convergence

For the series $\displaystyle \sum_{i=1}^{\infin} u_n$, if the positive term series $\displaystyle \sum_{i=1}^{\infin} |u_n|$ converges, then we say the series $\displaystyle \sum_{i=1}^{\infin} u_n$ is **converges absolutely**. If the series $\displaystyle \sum_{i=1}^{\infin} u_n$ converges but the positive term series $\displaystyle \sum_{i=1}^{\infin} |u_n|$ disverges, then we say the series $\displaystyle \sum_{i=1}^{\infin} u_n$**converges conditionally**. For example, the series $\displaystyle \sum_{n=1}^{\infin} (-1)^{n-1}\frac{1}{n^2}$ converges absoluately, while the series $\displaystyle \sum_{n=1}^{\infin} (-1)^{n-1}\frac{1}{n}$ converges conditionally.



