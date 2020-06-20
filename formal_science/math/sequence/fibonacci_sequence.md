# Fibonacci Sequence

### Backgroud & Definition

##### Backgroud


##### Definition

**Fibonacci Sequence** is defined as

$$
u_{1} = u_{2} = 1, ~~~~  u_{n} = u_{n-1} + u_{n-2}
$$



##### Persepctive

The fibonacci sequence can be reiterated as the "stairs jumping" problem: suppose there are $n$ stairs and a person(or a monkey) is in the first (numbered as $1$) floor in the beginning, who can take 1 or jump 2 stair in one step. As a result, the total methods the person come to the $n$-th stair is exactly $u_{n}$.

In the algorithm's perspective, the fibonacci sequence modeled a typical problem which fits the condition of **dynamic programming**. The stair jumping problem is one of them.





### Simple Property

##### Sums

Here list four basic sum of fibonacci sequence, which are the sum of the terms, sum of the odd terms, sum of the even terms, and the square sum of terms respectively.

1. $\displaystyle\sum_{i=1}^{n} u_{i} = u_{n+2} - 1$

2. $\displaystyle\sum_{i=1}^{n} u_{2i-1} = u_{2n}$

3. $\displaystyle\sum_{i=1}^{n} u_{2i} = u_{2n+1} - 1$

4. $\displaystyle\sum_{i=1}^{n} u_{i}^2 = u_{n}u_{n+1}$

Since the fibonacci sequence is defined by induction, all of them can be easily proved by induction, which are quite boring to write them down formally. The interesting part is that various sum of fibonacci sequence can be reduced to the latter item in the sequence itself. 



##### Terms Relation

1. $u_{n+m}=u_{n-1}u_{m} + u_{n}u_{m+1}$




### General Term

##### General Term Format

It's well-known that fibonacci sequence is the typical (and the most simple) **Linear Homogeneous Recurrence Relations with Constant Coefficients**, the general term of it can be retrived by characteristic equation $x^2 = x + 1$, the two roots, often noted as $\alpha$ and $\beta$, which are 

$$
\alpha = \dfrac{1+\sqrt{5}}{2}, ~~~~ \beta = \dfrac{1-\sqrt{5}}{2}
$$

and the general term of fibonacci sequence is

$$
f_n = \dfrac{\alpha^n+\beta^n}{\sqrt{5}} = \dfrac{1}{\sqrt{5}} \left( \dfrac{1+\sqrt{5}}{2} \right)^n + \dfrac{1}{\sqrt{5}} \left( \dfrac{1-\sqrt{5}}{2} \right)^n
$$

Since they're both the roots of characteristic equation, we have $\alpha^2 = \alpha + 1$ and $\beta^2 = \beta + 1$.



##### Property of $\alpha, \beta$

1. $\alpha + \beta = 1, ~~~~ \alpha\beta = -1$.

2. $\alpha = \varphi = 1.618...$, where $\varphi$ is so-called **golden ratio**.

3. $u_{n}$ is the closest integer to $\dfrac{\alpha^n}{\sqrt{5}}$. This is obvious since the $\beta^n$ term approaches 0 as $n$ increase. This property can be also written as the limit form:

	$$
	\lim_{n\rightarrow\infin} \left| u_{n} - \dfrac{\alpha^n}{\sqrt{5}} \right| = 0
	$$

	This property tells us that the fibonacci sequence grows as fast as sequence $\alpha^n/\sqrt{5}$, the latter one is a simple geometric sequence, whose value can be evaluate easier.




























