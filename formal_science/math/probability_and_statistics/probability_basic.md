# Probability Basic

$$
\newcommand{\F}{\mathcal{F}}
$$

### Axiomatization

##### Event Domain

Let $\Omega$ be the **sample space**, if $\F\sub\Omega$ meets

1. $\Omega\in\F$.
2. For any $A\in\F$, $\overline A\in\F$.
3. For $A_i\in\F, i\lt n$, $\displaystyle\bigcup_{n=1}^{\infin}A_n\in\F$.

Then we defined $\F$ as **event domain** in the sample space $\Omega$.



##### Probability Space

Let $P$ be the real function in event domain $\F$, it is defined as **probability measure** or **probability** if holds

1. Non-negative. $P(A)\ge0$.
2. Regularity. $P(\Omega) = 1$. ==TODO: this translation needs further evidences to support==
3. Countable Additivity. For the incompatible event list $A_{i}$, $P\left(\displaystyle\sum_{i=1}^{\infin}{A_i}\right) = \displaystyle\sum_{i=1}^{\infin}P(A_i)$.

The triple $(\Omega, \F, P)$ called **probability space**, where $\Omega$ is sample space, $\F$ is the event domain, and $P$ is the probability measure.

Notice that in the definition, the countable additivity is the infinity form, while we'll proved the finite form based on it in the next section as the property of probability.



##### Basic Property

Several Properties can be inferred from the axiomationzation of probability:

1. The probability of impossible event is 0. i.e. $P(\varnothing)=0$ 

> Proof. Let $A_{1} = \Omega$, $A_{i} = \varnothing$ for $i\ge2$, notice that $\Omega \cap \varnothing = \varnothing \cap \varnothing = \varnothing$, hence, this is an incompatible event list, based on the conutable addivity,
> 
> $$
> P\left(\Omega + \sum_{i=2}^{\infin} \varnothing\right)
> = P(\Omega) + P(\varnothing)\sum_{i=2}^{\infin} 1
> = 1 + P(\varnothing)\sum_{i=2}^{\infin} 1\le 1
> $$
> 
> Hence $P(\varnothing) = 0$.

2. The countable additivity can be reduced to the finite form.

> Proof. For finite event $A_i, i\le n$, we expand the subscript $A_i = \varnothing$ for $i\gt n$, notice that $A_i\cap \varnothing = \varnothing$ for any event $A_{i}$, which guranteed $A_i$ is an incompatible event list, thus
> 
> $$
> P\left(\sum_{i=1}^{n} A_i \right)
> = P\left(\sum_{i=1}^{n} A_i + \sum_{i=n+1}^{\infin} \varnothing\right)
> = P\left(\sum_{i=1}^{n} A_i \right) + P \left( \sum_{i=n+1}^{\infin} \varnothing \right)
> = P\left(\sum_{i=1}^{n} A_i \right)
> $$


3. $P(\overline A) + P(A) = 1$

4. For $B\sub A$, $P(A-B) = P(A) - P(B)$. Generally, $P(A\backslash B) = P(A) - P(AB)$.

    **Corollary**. For $B\sub A$, $P(B)\le P(A)$

6. $0\le P(A)\le1$.

6. $P(A\cup B) = P(A) + P(B) - P(AB)$.

    **Corollary**. $P(A\cup B) \le P(A) + P(B)$.




### Possiblity Model

The **classical probability** and **geometric probability** are two model of probability that represents the discrete and continous case respectively.

More precisely, in the study of classical probability, there are some typical patterns that arised in many different problems, i.e. the (put back or not) sampling model, box model, pair model.




### Conditional Probability

##### Definition

Given probability space $(\Omega, \F, P)$, and $B\in\F, P(B)>0$, for any $A\in\F$, we define

$$
P(A|B) := \frac{P(AB)}{P(B)}
$$

as the **conditional probability** of $A$ if $B$ is known occured.

One basic but important fact is, the conditional probability is a type of probability, aka. it complies with the axiomatization of probability:

1. Non-negative. Since $P(AB), P(B)\ge0$, the conditional probability $P(A|B) = \cfrac{P(AB)}{P(B)}\ge0$

2. Normal. $P(\Omega|B) = \cfrac{P(\Omega B)}{P(B)} = \cfrac{P(B)}{P(B)} = 1$.

3. Countable addivitity. For the incompatible event list $A_{i}$, $A_{i}B$ is also an incompatible event list.

$$
P\left(\left.\sum_{i=1}^{\infin}{A_i} \right\vert B\right)
= \cfrac{P\left(\displaystyle\sum_{i=1}^{\infin} A_iB\right)}{P(B)}
= \cfrac{\displaystyle\sum_{i=1}^{\infin} P\left(A_iB\right)}{P(B)}
= \sum_{i=1}^{\infin} \cfrac{P\left(A_iB\right)}{P(B)}
= \sum_{i=1}^{\infin}P(A_i|B)
$$

By illustrating the three properties above, we proved that the conditional probability is definitely probability.



##### Property

As we proved above, the conditional probability is probability, which means it shares all the properties of the general probability, besides, there are some special properties that only for conditional probability, here list some trivial examples:

- $P(B|B) = 1$.
- If $P(B) = 1$, $P(A|B) = P(A)$.
- If $AB = \varnothing$.
- If $A\sub B$, $P(A|B) = \cfrac{P(A)}{P(B)}$

And there important features:

1. **Formula of Multiplication**

For the given probability space $(\Omega, \F, P), A_1, A_2, ..., A_n\in\F$, and $P(A_{1}A_{2}...A_{n}) > 0$, we have

$$
P(A_{1}A_{2}...A_{n}) = P(A_{1})P(A_{2}|A_{1})...P(A_{n}|A_{1}A_{2}...A_{n-1})
$$

and for the two event special case:

$$
P(AB) = P(A)P(B|A) = P(B)P(A|B)
$$

> **Proof**. Induction on $n$:
> 
> **Basis**. $n=2$ case is guranteed by the definition of conditional:
> 
> $$
> P(A_1|A_2) = \cfrac{P(A_1A_2)}{P(A_2)} ~~~~\Rightarrow ~~~~ P(A_1A_2) = P(A_1)P(A_1|A_2)
> $$
> 
> **Induction**. Assume the $n=k$ case is correct, for $n=k+1$, notice that
> 
> $$
> P(A_{1}A_{2}...A_{k}) = P(A_{1}A_{2}...A_{k-1})P(A_{k}|A_{1}A_{2}...A_{k-1})
> $$
> 
> that concludes the formula of multiplication for any $n\ge2$ is correct.

2. **Total Probability Formula**

Let $E_{1}, E_{2}, ..., E_{n}$ be a partition of sample space $\Omega$, and for each part $P(E_{i})\gt 0$, for any event $A\in\F$,

$$
P(A) = \sum_{k=1}^{n}P(E_k)P(A|E_k)
$$

3. **Bayes Formula**

Let $E_{1}, E_{2}, ..., E_{n}$ be a partition of sample space $\Omega$, and for each part $P(E_{i})\gt 0$, then for any event $A$ and the part $E_i$,


$$
P(E_i|A) = \cfrac{P(AE_{i})}{P(A)} = \cfrac{P(E_i)P(A|E_i)}{\displaystyle\sum_{k=1}^{n}P(E_k)P(A|E_k)}
$$





### Independency







