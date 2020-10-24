# Divisibility

##### # Division Algorithm

For integer $a,b$ with $b\neq0$, there only exists two integer $q,r$ which satisified
$$
a = b \times q + r, \quad 0\leq r < b
$$
where $q$ is **quotient** and $r$ is **remainder**. $q$ also named as **partial quotient** if $r\neq0$.

> Proof. First we prove the case when $a, b > 0$.
>
> (Existence) Let $R = \{r ~|~ r = a-qb \ge 0, ~ q\in\mathbb{Z} \} \subset \mathbb{N}$, since $a, b>0$, there must be at least one element that $r = a - 0\times b = a > 0$, which inferred that $R$ is a non-empty set of $\mathbb{N}$, hence there must be a minimum number $r \ge 0$.
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
> b(q-q') = r-r' < b \Rightarrow q - q' < 1
> $$
>
> Since $q, q'$ are both integer, this inequation implies that $q=q'$ thus $r=r'$, which concludes the uniqueness of pair $(p, r)$.



##### # Definition

For integer $a, b\neq0$, if there exits an integer $q$ which satisfies
$$
a = bq
$$
We say that $a$ **divides** $b$, and $a$ is a **divisor** or **factor** or $b$, and $b$ is a **multiple** of $a$, denotes as $a \ | \ b$.



##### # Property

- Trivial Divisibility

    For any integer $a\neq0$,
    $$
    1\ | \ a, \qquad a \ | \ 0
    $$

- Partial Relation's Requirement

    1. For any integer $a\neq0$, $a\ | \ a$, and $a \ | \ (-a)$.
    2. For $a, b> 0$, if $a \ | \ b$ and $b \ | \ a$, then $a=b$.
    3. If $a\ | \ b$ and $b \ | \ c$, then $a \ | \ c$.

    This concludes that the divisibility relation on $\mathbb{N}$ is **partial order relation**, while the definition domain can not be extended into $\mathbb{Z}-\{0\}$, since the negatives would broke the anti-transtive rule.

- **Calcellation Law**
    $$
    \textrm{If}\ \ \gcd(a,\ c) = 1, \quad a \ | \ (b\cdot c) \Rightarrow a \ | \ b \qquad (1)
    $$

- If $p$ is prime and $p|ab$, then $p|a$ or $p|b$.

    > **Proof**. Since $p$ is a prime, $(p, a) = 1$ or $(p, a)=p$. If $(p, a)=p$ then $p|a$, if $(p, a)=1$ the 



