# Primes Infinity Proofs

Here we introduce five proofs from different domains.

1. Euclid's Approach. The most classical way.
2. Fermat Number.
3. Analysis Method.

### 1. Euclid's Approach

> Proof. Assume that there only finite primes, notes them as $p_i, i=0, 1, ..., n$, Construct a number
> $$
> p' = \prod p_i + 1
> $$
> Now based on the division with remainder, for any $p_k$,
> $$
> p' = p_k\prod_{i\neq k} p_i + 1
> $$
> where $\prod_{i\neq k}p_i\in\mathbb{Z}$, which shows that any $p_i$ is not the divisor of $p'$, which makes $p'$ a new prime, leads to contradication.



### 2. Fermat Number

>  Proof. The Fermat numbers $F_n = 2^{2^n} + 1$ can be expressed by a recursion way
> $$
> \prod_{i=0}^{n-1} F_{i} = F_{n} - 2 \qquad (n\ge1)
> $$
> which can be proved by the mathematical induction. For $n=1$, $F_0 = 3, F_1 = 5$, so we have $\prod_{i=0}^{0}F_i = F_0 = F_1 - 2$. Now with induction we conclude
> $$
> \begin{align}
> \prod_{i=0}^{n}F_i 	&= F_n\prod_{i=0}^{n-1}F_i = F_n(F_n-2) = F_n^2 - 2F_n \\
> 					&= \left( 2^{2^{n}} + 1 \right)\left( 2^{2^{n}} - 1 \right)
> 					 = 2^{2^{n+1}} - 1 = F_n - 2
> \end{align}
> $$
> Hence the recursion expression of Fermat number is correct. The expression implies that $(F_n, F_i) \le 2$ for any $i<n$, while all the Fermat number are odd, hence $(F_n, F_i) = 1$, which means all the Fermat numbers are relative prime with each other. Since there're infinte Fermat numbers, there must be infinite primes.



### 3. Analysis Method

This proof use a finite version of the famous conversion technique in number theory:
$$
\begin{equation}
\sum_{i=1}^{\infty} \frac{1}{i} = \prod_{i=1}^{\infty} \left(\sum_{j=1}^{\infty} \frac{1}{p_i^j} \right) \tag{1}
\end{equation}
$$
which is based on the fundamental theorem of arithmetic.

> Proof. We could notice the inequality from graph of $\cfrac{1}{t}$, for any $n < x < n+1$
> $$
> \int_1^x \frac{1}{t} ~\mathrm{d}t = \ln x \le \sum_{i=1}^n \frac{1}{i}
> $$
> In light of the conversion above, we managed to connect the RHS to primes. Fortunely there's a finite version of formula(1), which limits the RHS of (1) only contains the first $n$ primes.
> $$
> \prod_{i=0}^{n} \left( \sum_{j=0}^{\infty} \frac{1}{p_i^j} \right) = \sum_{F(m)\le p_n}\frac{1}{m}
> $$
>
> where the function $F(m)$ represents the largest prime factor of $m$, in other word, $m$ are those integers only contain $p_i, ~ i \le k$ as the prime factors.
>
> Hence, we have
>
> $$
> \ln x \le \sum_{i=1}^n \frac{1}{i} < \sum_{F(m)\le n} \frac{1}{m} = \prod_{i=0}^{k} \left( \sum_{j=0}^{\infty} \frac{1}{p_i^j} \right)
> = \prod_{i=0}^{k} \frac{p_i}{p_i-1} = \prod_{i=0}^{k} \left( 1+\frac{1}{p_i-1} \right)
> $$
>
> Here the $p_k$ should be the largest prime less than $n$, in other word, $k = \pi(n)$.
>
> For now, we construct an inequality chain that connect the natural logrithm $\ln x$ and the product of a determined expression. As we know $\ln x$ is not bounded, if there are only limited primes, the RHS of inequation will be a fixed number after all the primes are iterated, which concludes a contradiction.
>
> A more elaborate way to makes this even more clear, is trying to introduce the prime counting function $\pi(x)$ into the inequality.
> $$
> \prod_{i=0}^{k} \left( 1+\frac{1}{p_i-1} \right)
> \le \prod_{i=0}^{k} \left( 1+\frac{1}{i} \right)
> = \prod_{i=0}^{k} \left( \frac{1+i}{i} \right)
> = 
> $$
> 
>
> 































`
