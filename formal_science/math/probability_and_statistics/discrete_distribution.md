# Discrete Distribution

$$
\newcommand{\e}{\text{e}}
$$



### 1. Binomial Distribution

Let $X$ represents the total counts of success in $n$-times Bernoulli exprements, we have
$$
P(X=k) = {n\choose k}p^k(1-p)^{n-k}, ~~~~ k = 0, 1, ..., n
$$
define $X$ complies the **binomial distribution** with parameter $(n, p)$, denoted as $X\sim b(n, p)$. Specially, when $n=1$, we call $b(1, p)$ as **two points distribution**, **0-1 distribution**, or **Bernoulli distribution**.





### 2. Geometric Distribution

Let $X$ represents the total experiment counts when first success in Bernoulli exprement, we have
$$
P(X=k) = p(1-p)^{k-1}, ~~~~k = 1, 2, ...
$$
define $X$ complies the geometric distribution with parameter $p$, denoted as $X\sim Ge(p)$.

We say the geometric distribution is **memoryless**, since $P(X>m+n|X>m) = P(x>n)$. Moreover, we can prove that, a **memoryless** discrete distribution must be the geometric distribution.

The memoryless tells us, the probability of success in the next experiments will not be affected by the unsuccessful expriements before in Bernoulli experiments. Well in a Bayes' perspective which might infer that we should update the prior belief of the success rate $p$.



### 3. Negative Binomial Distribution

Let $X$ represents the total dexperiment counts at $r$-times of success, we have
$$
P(X=k) = {{k-1}\choose{r-1}}p^r(1-p)^{k-r}, ~~~~ k = r, r+1, ...
$$
define $X$ complies the **negative binomial distribution** or **Pascal distribution** with parameters $(r, p)$, denoted as $X\sim Nb(r, p)$.



### 4. Poisson Distribution

$$
P(X=k) = \frac{\lambda^k}{k!}\e^{-\lambda}, ~~~~ k = 0, 1, 2, ...
$$

define $X$ comlies the Poisson distribution with parameter $\lambda$, denoted as $X\sim P(\lambda)$.



### 5. Hypergeometric Distribution

The hypergeometric distribution is modelled based on the $M$ 