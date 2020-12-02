$$
\newcommand{\E}{\text{E}}
\newcommand{\Var}{\text{Var}}
$$

**Moment Estimation Example 1.**

Suppose that $X_1, X_2, ..., X_n$  is the samples from uniform distribution $U(a, b)$, solve the moment estimation of parameters $a, b$.

**Solution.** We're going to use the 1st and 2nd origin moment to do the moment estimation. Notice that for the uniform distribution, $\E X = \dfrac{a + b}{2}$, $ \Var X = \dfrac{(b-a)^2}{12}$.


The first origin moment, which is exactly the expectation of $U(a,b)$, can be estimated by the average of samples, that is 
$$
EX = \overline X
$$

and the second origin moment is

$$
EX^2 = (EX^2) + \Var X = \overline X^2 + S_n^2
$$

Since we use the $\overline X$ to estimate $EX$, we can remove them from both side:
$$
\Var X = S_n^2
$$
That is, the equation listed for the estimation of second origin moment, also makes the second central moment the same. The essential reason is, $k$-th central moment is completely determined by the those $i$-origin moment that $i\le k$:
$$
\nu_k = \sum_{i=0}^{k}(-1)^{k-i}C_k^i\mu_i\mu_1^{k-i}
$$
Now we got the two equations
$$
\left\{\begin{array}{ll}\begin{align}
& \frac{a+b}{2} = \overline X \\
& \frac{(b-a)^2}{12} = S_n^2
\end{align}\end{array}\right.
$$

Hence, the moment estimation of $U(a, b)$ is
$$
\left\{\begin{array}{ll}\begin{align}
a = \overline X - \sqrt{3}S_n^2 \\
b = \overline X + \sqrt{3}S_n^2
\end{align}\end{array}\right.
$$

Where
$$
\overline X = \sum X_i, ~~~~ S_n^2 = \frac{1}{n} \sum(\overline X-X_i)^2
$$
The physical meaning of this is plain: we use the average of samples as the center, and extends the interval based on the variance of samples.

**Comment.** Similarly, for distribution that has only two parameters, such as normal distribution $N(\mu, \sigma^2)$, Gamma distribution $Ga(\alpha, \lambda)$, we can directly use the expectation and variance to solve the parameters.
