$$
\newcommand\gcd{\textrm{gcd}}
\newcommand\lcm{\textrm{lcm}}
$$

# Elementary Number Theory

### 1. Divisibility

##### # Division Algorithm

For integer $a,b$ with $b\neq0$, there exists and **ONLY** two integer $q,r$ which satisified
$$
a = b \times q + r, \quad 0\leq r < b
$$
where $q$ is **Quotient** and $r$ is **Remainder**. $q$ also named as **Partial Quotient** if $r\neq0$.

> Proof. First we prove the case when $a, b > 0$.
>
> (Existence) Let $R = \{r ~|~ r = a-qb \ge 0, ~ q\in\Z \} \subset \N$, since $a, b>0$, there must be at least one element that $r = a - 0\times b = a > 0$, which inferred that $R$ is a non-empty set of $\N$, hence there must be a minimum number $r \ge 0$.
>
> Notice that the minimum $r$ must less than $b$. If not, we have $a-qb \ge b$, so $a-(q+1)b\ge 0\in R$, which contradicts to the statement that $r$ is minimal.
>
> (Uniqueness) Assume there's another pair $(p', r')$ which satisfies the same condition:
> 
> $$
> a = bq + r, \quad a = bq' + r', \qquad 0 \leq r,\ r' <b
> $$
> Thus,
> $$
>b(q-q') = r-r' < b
> $$
> 
> $$
> q - q' < 1
> $$
> 
> Since $q, q'$ are both integer, this inequation implies that $q=q'$ thus $r=r'$, which concludes the uniqueness of pair $(p, r)$.



##### # Definition of Divisibility

For integer $a, b$, if there exits an integer $q$ which satisfies
$$
a = bq
$$
We say that $a$ **Divides** $b$, and $a$ is a **Divisor** or **Factor** or $b$, and $b$ is a multiple of $a$, notes as $a \ | \ b$.



##### # Properties of Divisibility

- Trivial Divisibility

  For any integer $a\neq0$,
  $$
  1\ | \ a, \qquad a \ | \ 0
  $$

- Partial Relation's Requirement

  1. For any integer $a\neq0$, $a\ | \ a$, and $a \ | \ (-a)$.
  2. For $a, b> 0$, if $a \ | \ b$ and $b \ | \ a$, then $a=b$.
  3. If $a\ | \ b$ and $b \ | \ c$, then $a \ | \ c$.

  This concludes that the divisibility relation on $\N$ is **partial order relation**, while the definition domain can not be extended into $\Z-\{0\}$, since the negatives would broke the anti-transtive rule.

- **Calcellation Law**
  $$
  \textrm{If}\ \ \gcd(a,\ c) = 1, \quad a \ | \ (b\cdot c) \Rightarrow a \ | \ b \qquad (1)
  $$

- 





### 2. Congruence

##### # Definition of Congruence

Given $m\ge0$, for two integer $a$ and $b$, if $m \ | \ (a-b)$, we define $a$ and $b$ are congruence modulo $m$, notes as $a\equiv b \pmod m$.

Usually the **modulus** $m\ge2$. If $m=0$, $0~|~(a-b)$ if any only if $a = b$. If $m=1$, $1~|~(a-b)$ is always true. Both cases are so trivial to discuss.

Congruence can be regarded as a generalization of parity (odd or even), parity is the congruence when $m=2$.



##### # Properties of Modular Arithmetic

The operations on the congruence equation are named as modular arithmetic.

- Equivlance Relation's Requirement

  1. For any integer $a$ and any modulo $m$, $a\equiv a\pmod m$.
  2. If $a \equiv b \pmod m$, then $b\equiv a \pmod m$.
  3. If $a\equiv b \pmod m,\ \ b\equiv c\pmod m$, then $a\equiv c \pmod m$.

  This concludes that congruence relation on $\Z$ is an **equivalence relation**. 

- Equation's Property:
  $$
  \begin{align}
  a \equiv b \pmod m &\Rightarrow a+c \equiv b+c \pmod m \\
  a \equiv b \pmod m &\Rightarrow ac \equiv bc \pmod m
\end{align}
  $$
  
  > Proof. Based on the definition of congruence:
  > $$
  > m~|~(a-b) \Rightarrow m~|~\left((a+c)-(b+c)\right) \\
  > m~|~(a-b) \Rightarrow m~|~(a-b)c \Rightarrow m~|~(ac-bc)
  >$$
  > 

  > Tricks: This two attribute can be proved by consider we're processing numbers on base $m$​.
  >
  > **Lemma**. $a\equiv b \pmod m$, if and only if $a$ and $b$ **share the same last digit** based on $m$.
  >
  > **Proof**. Express $a$ and $b$ on base $m$, the lemma guaranteed that $a$ and $b$ share the same last digit. Based on the rule of arithmetic operation, $a+b$ and $b+c$, as well as $ac$ and $bc$, will also share the same last digit, so they are also congruence modulo $m$.
>
  > **Remark**. This proof seems like a memory hack more than a formal proof, since the last digit of $a$ based on $m$ is exactly the value of $a \bmod m$, which seems like a circular reasoning.

  Noticed that the form of division is special: the calcellation of factor in both sides will cause the change of modulo.
$$
ac \equiv bc \pmod m ~~~~\Rightarrow~~~~ a\equiv b \left( \textrm {mod}\ {\cfrac{m}{\textrm{gcd(c, m)}}}\right)
$$

  > The proof of division rule using the important property of divisibility Calcellation Law.

- Calculating Simplicating
  $$
  (x \oplus y) \bmod m = ((x \bmod m) \oplus (y \bmod m)) \bmod m
  $$
  The opeartor can be replaced by any normal operators. This property can be applied in the calculation in computer to reduce the value of operated number.







### 3. Greatest Common Divisor

##### # **Euclidean Algorithm**

Euclidean Algorithm shows the method of 

```python
def gcd(a, b):
  return a if b==0 else gcd(b, a%b)

def lcm(a, b):
  return a*b/gcd(a, b)
```

> Ex1. Prove $(n^2+n+4, n-1)|6$.
>
> Prov. Notices that $n+n+4 = (n-1)(n+2)+6$, as a result $(n^2+n+4, n-1) = (n-1, 6)$.



##### # Properties

- Any Common Divisor is the divisor of GCD; Any Common Multiple is the multiple of LCM.

- Arbitrariness of Combinition:
  $$
  \gcd(a_1,\ a_2,\ ...,\ a_{n-1}, \ a_n) = \gcd(\gcd(a_1,\ \ a_2,\ ...,a_{n-1}),  \ a_n)
  $$
  This can be applied in the recursion algorithm.

- Since anything can be considered as the factor of zero, $\gcd(0, \ a) = a$.

- Permission of Linear Conversion:
  $$
  \gcd(a_1,\ a_2,\ ...,\ a_n) = \gcd(a_1,\ \ a_2,\ ...,\ a_i,\ ..., \ 	a_j+a_i,\ ...,\ a_n)
  $$

  >  This is the direct result of Euclidean Algorithm.

  $$
  \gcd(ma_1,\ ma_2,\ ...,\ ma_n) = m\ \gcd(a_1,\ a_2,\ ...,\ a_n)
  $$

  

- **Bézout's Theorem**:
  $$
  \gcd(a_1, \ a_2,\ , ... ,\ a_n) = \sum k_ia_i, \quad k_i\in\Z
  $$
  Bézout's Lemma tells us the GCD of a series of number must can be expressed by the linear combination of numbers.

- FTA's Perspective:
  $$
  \gcd(a,\ b) = \sum p_i^{\min(e_i, f_i)},
  \qquad
  \lcm(a,\ b) = \sum p_i^{\max(e_i, f_i)}
  $$
  FTA's Perspective directly convert the abstract notation `gcd` into the algebra expression, so many attributes of GCD can be proved by consider it FTA's way.

- Relation between GCD and LCM:
  $$
  \gcd(a,\ b) \times \lcm(a, \ b) = a\times b
  $$

  > This can be proved with the help with the FTA's Perspective plus a simple fact:
  > $$
  > \min(a,\ b) + \max(a,\ b) =  a + b
  > $$
  > Noticed that this prove convert the second-progression operation into first-progression, by the nature of exponent.
  >
  > Plus, this is true only in the 2-number case.







### 4. Prime

##### # Definition



##### # Proof of Inifinity

There are infinite primes. The most classical proof is given by Euclid based on the division algorithm.

> Proof. Assume that only finite primes there are, notes them as $p_i, i=0, 1, ..., n$, Construct a number
> $$
> p' = \prod p_i + 1
> $$
> Now based on the division with remainder, for any $p_k$,
> $$
> p' = p_k\prod_{i\neq k} p_i + 1
> $$
> where $\prod_{i\neq k}p_i\in\Z$, which shows that any $p_k$ is not the divisor of $p'$, which makes $p'$ a new prime, leads to contradication.

Except the Euclid's approach, there're plenty of methods show the infinity of primes, we collect and introduce them in [Prime Infinity Proofs](prime_infinity_proofs.md).



##### # Fundamental Theorem of Arithmetic



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
If the $m$ itself is a prime number, then the coprime condition $\gcd(a,\ m) = 1$ is obvious, and $\phi(p) =p-1$. This gives the **Fermat's Little Theorem**:
$$
a^{p-1} \equiv 1 \pmod p
$$


##### # Primality Test

1. Eratosthenes Sieve Method

   This Sieve Method based on a simple fact:

   

2. Wilson's Theorem:

   For any positive $n\in\N$, $n$ is a prime if any only if

   
   $$
   (n-1)! \equiv -1 \pmod n
   $$
   
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







### Liner Congruence Equation





### RSA Public-Key Cryptosystem

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




