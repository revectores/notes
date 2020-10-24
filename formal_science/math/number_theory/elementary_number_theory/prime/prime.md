# Prime

### 1. Basic Concept

##### # Definition

The integer with only 2 factors is called **prime**. The integar with more than 2 factors are **composite**. 1 is neither prime nor composite.







### 2. Related Theorem

##### # Infinity of Primes

There are infinite primes. The most classical proof is given by Euclid based on the division algorithm.

> Proof. Assume that only finite primes there are, notes them as $p_i, i=0, 1, ..., n$, Construct a number
> $$
> p' = \prod p_i + 1
> $$
> Now based on the division with remainder, for any $p_k$,
> $$
> p' = p_k\prod_{i\neq k} p_i + 1
> $$
> where $\prod_{i\neq k}p_i\in\mathbb{Z}$, which shows that any $p_k$ is not the divisor of $p'$, which makes $p'$ a new prime, leads to contradication.

Except the Euclid's approach, there're plenty of methods show the infinity of primes, we collect and introduce them in [proofs_of_infinity_of_primes](proofs_of_infinity_of_primes).



##### # Fundamental Theorem of Arithmetic

any $n\in\mathbb{N}, n>1$ can be divided into the only form of products of prime factors. That is,
$$
n = \prod p_i
$$

> Proof.

If we combining the same factors we have
$$
n = \prod p_i^{\alpha_i}
$$
This is the standard factoring form of $n$.

divisibility 



##### # Euler's Theorem

Euler Function $\varphi(n)$ represents the count of positive number less than $n$ those **coprime with** $n$.
$$
\varphi(n) = n\prod\left(1-\cfrac{1}{p_i}\right)
$$

> Prov. Applied Eratosthenes Sieve Method using $n$ as the limit, and with the help with inclusive-exclusive prinpicle.

The order of $a$ to mod $n$ is the least number $r$ which makes $a^r \equiv 1 \pmod m$.

Euler Theorem: If $\gcd(a,\ m) = 1$, 
$$
a^{\varphi(m)} \equiv 1 \pmod m
$$
If the $m=p$ is a prime number, then the coprime condition $\gcd(a,p) = 1$ must hold, and $\varphi(p) =p-1$. This gives the **Fermat's Little Theorem**:
$$
a^{p-1} \equiv 1 \pmod p
$$







### 3. Special Prime

There are some primes with special forms that worth studying.



##### # Fermat Prime

Fermat guesses that $F_n = 2^{2^n} + 1$[^1] is prime for all $n\in\mathbb{N}$ by observing $F_n = 3, 5, 17, 257, 65537$ for $0\le n \le 4$, hence the form $F_n$ is called **Fermat number**, and the prime in Fermat number is called **Fermat prime**. Ironically we've not found any prime $F_n$ for $n\ge 5$.



##### # Mersenne Prime

The form $M_p = 2^p -1$[^2] where $p$ is a prime called **Mersenne number**, the prime in Mersenne number is called **Mersenne prime**. As of July 2020, 51 Mersenne primes are known. The largest known prime number, $2^{82589933} − 1$, is a Mersenne prime. Since 1997, all newly found Mersenne primes have been discovered by the [Great Internet Mersenne Prime Search](https://www.mersenne.org/), a distributed computing project.





### 4. Primality Test

1. Eratosthenes Sieve Method

    This Sieve Method based on a simple fact:

    

2. Wilson's Theorem

    For any positive $n\in\mathbb{N}$, $n$ is a prime if any only if $(n-1)! \equiv -1 \pmod n$.

    > Proof. Consider the polynomial with order $p-2$
    > $$
    > f(x) = (x-1)(x-2)\cdots(x-(p-1)) - (x^{p-1}-1)
    > $$
    > The Fermat's Little Theorem tells $x=1, 2, \ldots, p-1$ are all the solutions of equation $f(x)\equiv 0$. That is, the polynomial with order $p-2$ generates $p-1$ roots, which contradicts to Lagrange Theorem, which means the $p(x)$ can only be a zero-polynomial mod $p$, which indicates each cofficient could be divided by $p$. Hence
    > $$
    > \begin{align}
    > f(p) = (p-1)! - (p^{p-1}-1) &\equiv 0 \pmod p \\
    > (p-1)! &\equiv -1 \pmod p
    > \end{align}
    > $$

3. 



3. Rabin-Miller Primality Test

    **Quadratic Test Theorem**: If $p$ is a prime, the Quadratic Congruence Equation $x^2 \equiv 1 \pmod p$ can only be $x=1$ or $x = p -1$.

    > Prov.
    > $$
    > x^2\equiv 1 \pmod p
    > 
    > \quad\rightarrow\quad
    > 
    > (x+1)(x-1) \equiv 0 \pmod p
    > 
    > \quad \rightarrow \quad 
    > 
    > x_1 \equiv 1,\ x_2\equiv p-1
    > $$

    ==Implement the RMPT==







[^1]: https://oeis.org/A000215
[^2]: https://oeis.org/A000668

