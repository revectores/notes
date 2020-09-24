# RSA Public-Key Cryptosystem

The three main cryptosystem 

Case 1. $m, n$ are coprime,
$$
m^{ed} = m^{1+k\varphi(n)} \equiv m \pmod n
$$
Case 2. $\gcd(m,n) = p \neq 1$. Notice that $p$ must be one of the two prime factors of $n$. Let $m \equiv r\cdot p^{\varepsilon}$, the first step is prove that $m^{\varphi(n)} = 1$, to make it fit the Euler's Theorem to **behave like** $\gcd(m,n) = 1$:
$$
m^{\varphi(n)} = r^{\varphi(n)}\cdot p^{\varepsilon(p-1)(q-1)}
= 1\cdot(p^{q-1})^{\varepsilon(p-1)} = 1 \pmod q
$$
Second Step:
$$
m^{1+k\varphi(n)} = m\cdot(1+k'q)^k = m\cdot(1+qL) \equiv m \pmod {pq}
$$

