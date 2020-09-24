# Triple Integral

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
$$



### 1. Definition

For the function bounded within closed area $\Omega$, devide $\Omega$ into arbitrary $n$ closed area $\{\Delta\sigma_i | 1\le i\le n\}$, and pick arbitrary point $(\xi_i, \eta_i)\in\Delta\sigma_i$, define the double integral of function $D$
$$
\iint_D f(x, y)\d\sigma = \lim_{\lambda\rightarrow 0}\sum_{i=1}^nf(\xi_i, \eta_i)\Delta\sigma_i
$$
if the limit exists for all the methods of devision. The $f(x, y)$ is called **integrand**, $f(x, y)\d\delta$ is the integral expression, $\d\sigma$ is the **area element**, $D$ is the **integral area**. the sum $\displaystyle \sum_{i=1}^nf(\xi_i, \eta_i)\Delta\sigma_i$ is named **integral sum**.





### 2. Computation

We can reduce the one triple integral into one double integral and one single integral by two ways:



$$
T = \iiint_\Omega = \int_0^d \dz \int_0^{2\pi}\d\theta \int_0^r f(r\cos\theta r\sin\theta, z)r\dr
$$

$$
\left\{\begin{array}{ll}
x = r\sin\varphi \cos\theta  \\
y = r\sin\varphi \sin\theta  \\
z = r\cos\varphi
\end{array}\right.
\\
\dv = \rho^2 \sin\varphi ~ \d\rho\d\theta\d\varphi
$$



$$
(x^2+y^2+z^2)^2 = a^3z (a>0) \\
\rho^4 = a^3 \rho \cos\varphi
$$
