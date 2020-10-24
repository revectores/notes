

# Congruence

##### # Definition of Congruence

Given $m\ge0$, for two integer $a$ and $b$, if $m\mid(a-b)$, we say $a$ and $b$ are congruence modulo $m$, notes as $a\equiv b \pmod m$.

Usually the **modulus** $m\ge2$. If $m=0$, $0~|~(a-b)$ if any only if $a = b$. If $m=1$, $1~|~(a-b)$ is always true. Both cases are so trivial to discuss.

Congruence can be regarded as a generalization of parity (odd or even), parity is the congruence when $m=2$.



##### # Properties of Modular Arithmetic

The operations on the congruence equation are named as modular arithmetic.

- Congruence as equivlance relation

    1. For any integer $a$ and any modulo $m$, $a\equiv a\pmod m$.
    2. If $a \equiv b \pmod m$, then $b\equiv a \pmod m$.
    3. If $a\equiv b \pmod m,\ \ b\equiv c\pmod m$, then $a\equiv c \pmod m$.

    This concludes that congruence relation on $\mathbb{Z}$ is an **equivalence relation**. 

- Equation's Property:
    $$
    \begin{align}
    & a \equiv b \pmod m \Rightarrow a+c \equiv b+c \pmod m \\
    & a \equiv b \pmod m \Rightarrow ac \equiv bc \pmod m
    \end{align}
    $$

    > Proof. Based on the definition of congruence:
    > $$
    > \begin{align}
    > & m~|~(a-b) \Rightarrow m~|~\left((a+c)-(b+c)\right) \\
    > & m~|~(a-b) \Rightarrow m~|~(a-b)c \Rightarrow m~|~(ac-bc)
> \end{align}
    > $$
    
    > Tricks: This two attribute can be proved by consider we're processing numbers on base $m$​.
    >
    > **Lemma**. $a\equiv b \pmod m$, if and only if $a$ and $b$ **share the same last digit** based on $m$.
    >
    > **Proof**. Express $a$ and $b$ on base $m$, the lemma guaranteed that $a$ and $b$ share the same last digit. Based on the rule of arithmetic operation, $a+b$ and $b+c$, as well as $ac$ and $bc$, will also share the same last digit, so they are also congruence modulo $m$.

>**Remark**. This proof seems like a memory hack more than a formal proof, since the last digit of $a$ based on $m$ is exactly the value of $a \bmod m$, which seems like a circular reasoning.

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



