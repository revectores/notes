# Property of Random Variable

$$
\newcommand{\d}{\text{d}}
\newcommand{\dx}{\d x}
\newcommand{\dy}{\d y}
\newcommand{\dt}{\d t}
\newcommand{\comb}{\text{C}}

\newcommand{\E}{\text{E}}
\newcommand{\D}{\text{D}}
\newcommand{\Var}{\text{Var}}
\newcommand{\Cov}{\text{Cov}}

\newcommand{\euler}{\text{e}}
$$

### Mathematical Expectation

##### # Definition

For the discrete variable $X$ with distribution is $P(X=x_i) = p_i$, if the series $\displaystyle\sum |x_i|p_i$ absoluately converges, i.e. $\displaystyle\sum x_ip_i < \infin$, then we define the mathematical expectation of $X$ as

$$
\E X = \sum x_i p_i
$$

For the continuous variable $X$ with the probability density function $p(x)$, if the integral $\displaystyle\int_{-\infin}^{\infin} xp(x) \dx$  absolutely converges, i.e. $\displaystyle\int_{-\infin}^{\infin} |x| p(x)~\dx \lt \infin$, then we define the mathematical expection of $X$ as

$$
\E X = \int_{-\infin}^{\infin} xp(x) \dx
$$

Apparently, due to restriction of absolutely converge, not all the distributions have well-defined mathematical expectation, take an example, for the famous Cauchy Distribution $p(x) = \dfrac{1}{\pi(1+x^2)}$, whose expectation integral can be computed as

$$
\begin{align}
I = \int_{-\infin}^{\infin} \dfrac{|x|}{\pi(1+x^2)} \dx
= \dfrac{2}{\pi} \int_{0}^{\infin} \dfrac{|x|}{(1+x^2)} \dx
\ge \dfrac{2}{\pi} \int_{0}^{M} \dfrac{x}{(1+x^2)} \dx
= \dfrac{1}{\pi} \ln(1+M^2)
\end{align}
$$

That is, $I \rightarrow \infin$, which disobeys the condition of definition of expectation.



##### # Property

The most important property of expectation is linearity:

$$
\E(aX+bY) = a\E X + b\E Y
$$

which is obvious due to the linearity of integration itself. Specially, the expectation of constant function is the constant itself, i.e. $\E c = c$.

Based on this, the expectation combination of functions can be devide-and-conquer by the linear decomposition.



##### # Expectation for Variable Function

Variable $X$ with its distribution and function $Y=f(X)$, we don't have to compute the distribution of $Y$ but use the following formula to compute its expectation(the proof is omitted).

$$
EY = E(f(X)) =
\left\{\begin{array}{ll}\begin{align}
& \sum_{k=1}^{\infin}f(x_k)p_k \\
& \int_{-\infin}^{\infin}f(x_k)p_k\dx
\end{align}\end{array}\right.
$$


definition of expectation for two-dimension variable

Two-dimension variable function

$$
EY = E(f(X)) =
\left\{\begin{array}{ll}\begin{align}
& \sum_{i=1}^{\infin}\sum_{j=1}^{\infin}f(x_i, y_j)p_{ij} \\
& \int_{-\infin}^{\infin}\int_{-\infin}^{\infin}f(x_i, y_j)p_{ij}\dx\dy
\end{align}\end{array}\right.
$$





### Variance

##### # Definition

Define $\E(X-\E X)^2$ as the **variance** of variable $X$ if the expectation exists (converges), denoted as $\Var X$ or $\D X$. Define $\sigma_X = \sigma(X) = \sqrt{\D X}$ as the standard deviation of $X$.



##### # Property

1. $\D X \ge 0$

2. $\D c = 0$

3. $\D(aX+b) = a^2\D X$

4. $\D X = \E X^2 - (\E X)^2$

5. $\D(X\pm Y) = \D X + \D Y \pm \Cov(X, Y)$

    As we'll prove in the property of convariance, the convariance for two independant variables are zero, hence$\D(X\pm Y) = \D X \pm \D Y$ holds for independant variables $X, Y$.



The variance of standard normal distribution $N(0, 1)$:

$$
E(X^2) = x^2\varphi(x)\dx = 1
$$

The variance of $N(0, \sigma^2)$ is $\sigma^2$.

Standardization of random variable:

$$
Y = \frac{X-EX}{\sqrt{\Var{X}}}
$$

Now we have $\E Y = 0, \Var Y = 1$





### Property of Special Distribution

Here we compute the expectation and variance of several special distribution: binomial distribution, exponent distribution, and the standard normal distribution.

1. Binomial distribution $P(X=k) = \comb_{n}^{k} p^k(1-p)^{n-k}$

$$
\begin{align}
\E X
&= \sum k \comb_{n}^{k} p^k(1-p)^{n-k} \\
&= \sum k \cdot \dfrac{n!}{k!(n-k)!} p^k(1-p)^{n-k} \\
&= np\sum \dfrac{(n-1)!}{(k-1)!(n-1-(k-1))!} p^{k-1}(1-p)^{n-1-(k-1)} \\
&= np
\end{align}
$$

==TODO: Find out why the last equality can be reduced by the regularity of binomial distribution.==

2. Exponent distribution $Exp(\lambda)$.

$$
\E~Exp(\lambda) = \int_{0}^{\infin} x\lambda \euler^{\lambda x} \dx = \dfrac{1}{\lambda}
$$

3. Standard normal distribution

$$
\E \varphi(x) = \int_{-\infin}^{\infin} x\phi \dx = 0 
$$

Furthermore, with the linear property of expectation applied, for the general normal distribution, $\E X = \E(\sigma X' + \mu) = \sigma \E X + \mu = \mu$.

We list the result following for the future reference:

|                     distribution                      |        expectation        |          Variance           |
| :---------------------------------------------------: | :-----------------------: | :-------------------------: |
|         $b(n, p) = \comb_n^{k}p^k(1-p)^{n-k}$         |           $np$            |          $np(1-p)$          |
| $P(\lambda) = \dfrac{\lambda^k}{k!}\euler^{-\lambda}$ |         $\lambda$         |          $\lambda$          |
|                       $U(a, b)$                       |     $\dfrac{a+b}{2}$      |    $\dfrac{(b-a)^2}{12}$    |
|                  $N(\mu, \sigma^2)$                   |           $\mu$           |         $\sigma^2$          |
|                 $Ga(\alpha, \lambda)$                 | $\dfrac{\alpha}{\lambda}$ | $\dfrac{\alpha}{\lambda^2}$ |









### Property Related inequality

##### # Markov's Inequality

For any positive random variable $X>0$ and positive number $b>0$, we have
$$
P(X\ge a) \le \frac{\E X}{a}
$$

> Proof. based on the definition of expectation,
> $$
> \E X
> = \int_{-\infin}^{\infin} xp(x) \dx
> = \int_{0}^{\infin} xp(x) \dx
> \ge \int_{a}^{\infin} xp(x) \dx
> \ge \int_{a}^{\infin} ap(x) \dx
> = a\int_{a}^{\infin} p(x) \dx
> = a \Pr(X\ge a)
> $$

As an interpretation of Markov's inequation, we consider the distribution of income: assuming no income is negative, Markov's inequality shows that, no more than 1/5 of the population can have more than 5 times the average income. 



##### # Chebyshev's Inequality

Chebyshev's inequality shows the relationships between expectation and variance. In summary, it shows the facts: the variance limits the range of variation of $X$. For the smaller $\D X$, $X$ will keep closer to expectation $\E X$:
$$
P\{ |X-\E X| \ge b \} \le \frac{\D X}{b^2}
$$










### Moment











































































