# Probability Basic

$$
\newcommand{\F}{\mathcal{F}}
\newcommand{\o}{\overline}
$$

### 2. Axiomatization

##### # Event Domain

Let $\Omega$ be the **sample space**, if $\F\sub\Omega$ meets

1. $\Omega\in\F$.
2. For any $A\in\F$, $\overline A\in\F$.
3. For $A_i\in\F, i\lt n$, $\displaystyle\bigcup_{n=1}^{\infin}A_n\in\F$.

Then we defined $\F$ as **event domain** in the sample space $\Omega$.



##### # Probability Space

Let $P$ be the real function in event domain $\F$, it is defined as **probability measure** or **probability** if holds

1. Non-negative. $P(A)\ge0$.
2. Regularity. $P(\Omega) = 1$. ==TODO: this translation needs further evidences to support==
3. Countable Additivity. For the incompatible event list $A_{i}$, $P\left(\displaystyle\sum_{i=1}^{\infin}{A_i}\right) = \displaystyle\sum_{i=1}^{\infin}P(A_i)$.

The triple $(\Omega, \F, P)$ called **probability space**, where $\Omega$ is sample space, $\F$ is the event domain, and $P$ is the probability measure.

Notice that in the definition, the countable additivity is the infinity form, while we'll proved the finite form based on it in the next section as the property of probability.



##### # Basic Property

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








### 3. Possiblity Model

The **classical probability** and **geometric probability** are two model of probability that represents the discrete and continous case respectively.

More precisely, in the study of classical probability, there are some typical patterns that arised in many different problems, i.e. the (put back or not) sampling model, box model, pair model.

==TODO: Add illustrations to common possibility models into this section.==








### 4. Conditional Probability

##### # Definition

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



##### # Property

As proved above, the conditional probability is probability, which means it shares all the properties of the general probability, besides, there are some special properties that only for conditional probability, here list some trivial examples:

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

and for the case of two events:

$$
P(AB) = P(A)P(B|A) = P(B)P(A|B)
$$

> **Proof**. Induction on $n$:
> 
> **Basis**. $n=2$ case is guranteed by the definition of conditional probability:
> $$
> P(A_1|A_2) = \cfrac{P(A_1A_2)}{P(A_2)} ~~~~\Rightarrow ~~~~ P(A_1A_2) = P(A_1)P(A_1|A_2)
> $$
> 
> **Induction**. Assume the $n=k$ case is correct, for $n=k+1$.
> $$
> P(A_{1}A_{2}...A_{k}) = P(A_{1}A_{2}...A_{k-1})P(A_{k}|A_{1}A_{2}...A_{k-1})
> $$
> 
> Notice that $P(A_1A_2...A_n) > 0$ gives $P(A_1) \ge P(A_1A_2) \ge \cdots \ge P(A_1A_2...A_n) > 0$, which gurantees the validity of all the expression of conditional probability. That concludes the formula of multiplication for any $n\ge2$ is correct.



2. **Total Probability Formula**

Let $E_{1}, E_{2}, ..., E_{n}$ be a partition of sample space $\Omega$, and for each part $P(E_{i})\gt 0$, for any event $A\in\F$,

$$
P(A) = \sum_{k=1}^{n}P(E_k)P(A|E_k)
$$

and for the case of two events:
$$
P(A) = P(A|B)P(B) + P(A|\o B)P(\o B)
$$

> **Proof**. This can be proved simply by the additivity and formula of multiplication:
> $$
> P(A)
> = P(A\Omega)
> = P\left(A\sum_{k=1}^n{E_k}\right)
> = \sum_{k=1}^n P\left( AE_k \right)
> = \sum_{k=1}^n P(E_k)P(A|E_k)
> $$



3. **Bayes Formula**

Let $E_{1}, E_{2}, ..., E_{n}$ be a partition of sample space $\Omega$, and for each part $P(E_{i})\gt 0$, then for any event $A$ and the part $E_i$,


$$
P(E_i|A) = \cfrac{P(AE_{i})}{P(A)} = \cfrac{P(E_i)P(A|E_i)}{\displaystyle\sum_{k=1}^{n}P(E_k)P(A|E_k)}
$$

The Bayes formula is the synthesization of definition of conditional probability, formula of multiplication and total probability formula. Physically, we use the prior knowledge, which is the prior probability $P(E_k)$ of reasons as the basis, trying find out the probability of reason $P(E_i|A)$ by introducing the new knowledge $P(A|E_k)$.

Actually, Bayes formula is quite a quantification of the common sense in belief updating, hence it has been applied in a wide range of domains nowadays.

==MODEL_CONNECTION: Due to the significant rule of Bayes formula in the movement conducting system, we've introduce the parse **Bayes' Ghost** to represent the event $A$ in $P(E_i|A)$, who helps us update the prediction of probability of success $P(E_i)$. We use the parse "introduce/expel Bayes' Ghost" to represent "execute/avoid $A$"==.

Finally, since the conditional probability is probability, the conditional version of can be included formally.





### 5. Independency

##### # Definition

Two events $A, B$ are **independent** if
$$
P(AB) = P(A)P(B)
$$
The "independency" or "not relavent" of the two events can be comprehended more easily from the conditional probability form:
$$
P(AB) = P(A)P(B) \Rightarrow
\left\{
\begin{array}{ll}
\begin{align}
&P(A) = \frac{P(AB)}{P(B)} = P(A|B) \\
&P(B) = \frac{P(AB)}{P(A)} = P(B|A) \\
\end{align}
\end{array}
\right.
$$
That is, the conditional probability is the same as the unconditional one, this can be regarded as another form of the definition of independency.

Specially, the zero-probability event (including impossible event $\varnothing$) is independent to any event. This can be derived from the monotonicity of probability.



##### # Independency in Multiple Events

For multiple events $A_i (1\le i\le n)$, $A_i$ are **pairwise(2-wise) independent**, if for any $1\le i,j \le n$,
$$
P(A_iA_j) = P(A_i)P(A_j)
$$
Generally, the **k-wise independence** (where $k<n$) are defined as for any $k$ events $1\le i_1, i_2, ... i_k \le n$,
$$
P\left( \bigcap_{j=1}^{k} A_{i_j} \right) = \prod_{j=1}^{k}A_{i_j}
$$
One should notice that the there are no determined relations between different k-wise independency, i.e. you cannot derive 2-wise dependency from 3-wise dependency, or vice versa.

Multiple events $A_i, 1\le i\le n$ are defined as **independent**, if and only if the $n$ events are k-wise independent for all $2\le k\le n$.

Consider about the special case about 3-events $A, B, C$ are independent, that indicates the following restrictions:
$$
P(AB) = P(A)P(B),~~~~ P(AC)=P(A)P(C),~~~~ P(BC)=P(B)P(C),~~~~ P(ABC)=P(A)P(B)P(C)
$$
Generally, for the n-events independent, $\displaystyle\sum_{i=2}^n {n\choose i} = 2^n - n -1 $ restrictions will be introduced.



##### # Property

1. If event $A$ is independent with itself, then either $P(A)=0$ or $P(A)=1$.

    > Proof. Based on the definition of independency, we have
    > $$
    > P(A) = [P(A)]^2
    > $$
    > Hence $P(A) = 0$ or $P(A) = 1$.

2. If the event list $A_i, 1\le i\le n$ are independent, then $A_1,~...~, \overline{A_i}, ~...~ , A_n$ are also independent. That is, you can reverse any event of an independent events list but keep the independency still. Specially, the reversed list $\overline{A_i}, 1\le i \le n$ are independent still.

    > This property can be comprehended by the meaning of "independency", if one event is "indenpendent", then the occurance, or the not orccurance, are both not relavent with the others, hence we can replace it with its opposite event.
    >
    > We'll prove this for the 2-event cases: If $A$ and $B$ are independent, then $A$ and $\overline B$ are also independent.
    >
    > **Proof**.
    > $$
    > P(A\o B) = P(A - AB) = P(A) - P(AB) = P(A) - P(A)P(B) = P(A)(1-P(B)) = P(A)P(\o B)
    > $$

3. For the independent events $A_1, ..., A_n (n\ge 2)$, the Poincaré formula, the addition formula of events, can be simplified as
    $$
    P\left( \bigcup_{k=1}^n A_k \right) = 1 - \prod_{k=1}^n(1-P(A_k))
    $$

    > **Proof**.
    > $$
    > P\left( \bigcup_{k=1}^n A_k \right)
    > = 1 - P\left( \o{\bigcup_{k=1}^n A_k} \right)
    > = 1 - P\left( \bigcap_{k=1}^n \o{A_k} \right)
    > = 1 - \prod_{k=1}^n P(\o{A_k})
    > = 1 - \prod_{k=1}^n(1-P(A_k))
    > $$

    This implies that, for any events $A_1, A_2, ..., A_n$ with same $P(A_i) = \delta$, no matter how small the probability one event is, the probability of at least one success will finally approaches $1$ with enough experiments.

