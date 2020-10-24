# Limit Theorem

$$
\newcommand{\e}{\text{e}}
\newcommand{\d}{\text{d}}
\newcommand{\o}{\overline}
\newcommand{\oX}{\o X}
\newcommand{\oY}{\o Y}
\newcommand{\oth}{\text{otherwise}}
\newcommand{\sgn}{\text{sgn}}
\newcommand{\dx}{\d x}
\newcommand{\dy}{\d y}
\newcommand{\dxy}{\dx\dy}
\newcommand{\E}{\text{E}}
\newcommand{\EX}{\E X}
\newcommand{\EY}{\E Y}
\newcommand{\Var}{\text{Var}}
\newcommand{\Corr}{\text{Corr}}
\newcommand{\Cov}{\text{Cov}}
$$



### 1. Central Limit Theorem

We say the random variable list $\{X_n, n\ge 1\}$ obys the central limit theorem, if the $S_n$ approaches the normal distribution when $n\rightarrow\infty$. That is, the cumulative distribution function $F_n(x)$ of distribution the standardized $S_n$ meets
$$
\displaystyle \lim_{n\rightarrow\infty}  \dfrac{S_n - \E S_n}{\sqrt{\Var S_n}} = \Phi(x)
$$
where $\Phi(x)$ is the cumulative distribution function of the standard normal distribution.

For the IID $\{X_n, n\ge 1\}$, 









### 2. Law of Large Number

Suppose the random variable $X, X_1, X_2, ...$ defined at the same probability space $(\Omega, \mathcal{F}, P)$, if we have
$$
\lim_{n\rightarrow\infty} P(|X_n-X|\ge \epsilon) = 0
$$
for any $\epsilon > 0$, we say the random variable list $\{X_n, n\ge1\}$ **converges in probability**, denoted as $X_n \xrightarrow[]{P} X$.

We say the random variable list $\{X_n, n\ge 1\}$ obeys the law of large numbers, if
$$
\frac{S_n - \E S_n}{n}\xrightarrow[]{P} 0
$$
where $\displaystyle S_n = \sum_{k=1}^{n} X_k$.



