# Fourier Series

$$
\newcommand{\euler}{\text{e}}
\newcommand{\p}{\part}
\newcommand{\px}{\p x}
\newcommand{\py}{\p y}
\newcommand{\pz}{\p z}
\newcommand{\pf}{\p f}
\newcommand{\pu}{\p u}
\newcommand{\pv}{\p v}
\newcommand{\pl}{\p \boldsymbol{l}}

\newcommand{\d}{\text{d}}
\newcommand{\dt}{\d t}
\newcommand{\dx}{\d x}
\newcommand{\dy}{\d y}
\newcommand{\dr}{\d r}
\newcommand{\dv}{\d v}
\newcommand{\dz}{\d z}
\newcommand{\du}{\d u}
\newcommand{\ds}{\d s}
\newcommand{\dS}{\d S}
\newcommand{\pp}[2]{\frac{\part #1}{\part #2}}
\newcommand{\dxy}{\dx\dy}
\newcommand{\dyz}{\dy\dz}
\newcommand{\dzx}{\dz\dx}
$$

##### # Orthogonality of Trigonometric Functions

$$
y = A\sin(\omega t + \varphi)
$$

$$
y = A_0 + \sum_{n=1}^\infin A_n\sin(n\omega t + \varphi_n)
= A_n\sin\varphi_n \cos n\omega t + A_n \cos\varphi_n\sin n\omega t
$$

Let $a_0/2 = A_0, a_n = A_n\sin\varphi_n, b_n = A_n\cos\varphi_n$, we have the function term series
$$
\frac{a_0}{2} + \sum_{k=1}^\infin(a_n\cos nx + b_n\sin nx)
$$
The trigonometric function list
$$
1, \cos x, \sin x, \cos 2x, \sin 2x, \ldots, \cos nx, \sin nx, \ldots
$$
are **orthogonal** on $[-\pi, \pi]$, that is, the integral of multiplication of any of the two functions equal zero.
$$
\int_{-\pi}^\pi \sin{k_1x}\cos{k_2x}\dx = 0 \\
\int_{-\pi}^\pi \sin{k_1x}\sin{k_2x}\dx = 0 ~~~~ (k_1\neq k_2)\\
\int_{-\pi}^\pi \cos{k_1x}\cos{k_2x}\dx = 0 ~~~~ (k_1\neq k_2)\\
$$
These expressions can be easily proved by product-to-sum formula of trigonometric fucntionsq

> Proof.
> $$
> \begin{align}
> \int_{-\pi}^{\pi}\sin k_1x \cos k_2x
> &= \frac{1}{2}\int_{-\pi}^\pi [\sin(k_1+k_2)x + \sin(k_1-k_2)x]\dx \\
> &= \frac{1}{2} \left.\left[-\frac{\cos(k_1+k_2)x}{k_1+k_2} -\frac{\cos(k_1-k_2)x}{k_1-k_2}\right]\right|_{-\pi}^{\pi} \\
> &= 0
> \end{align}
> $$

The other two expressions can be proved similarly.

On the contrary, 



##### # Fourier Series

Assume the function with period $2\pi$ can be expanded into trigonometric series or **Fouries series**
$$
f(x) = \frac{a_0}{2} + \sum_{k=1}^\infin(a_k\cos kx + b_k\sin kx)
$$
The **Fourier coefficients** $a_k, b_k$ are
$$
a_n = \frac{1}{\pi}\int_{-\pi}^{\pi}f(x)\cos nx \dx \\
b_n = \frac{1}{\pi}\int_{-\pi}^{\pi}f(x)\sin nx \dx
$$

> 



> Example. Expand $f(x)$ with period $2\pi$ into its Fouries series, the expression on $[-\pi, \pi]$ is
> $$
> f(x) =
> \left\{\begin{array}{ll}\begin{align}
> &-1, ~~~~ && -\pi \le x \lt 0 \\
> &1, ~~~~ && 0 \le x \lt \pi 
> \end{align}\end{array}\right.
> $$

$$
a_n = \frac{1}{\pi}\int_{-\pi}^{\pi}f(x)\cos nx \dx
= 
$$

