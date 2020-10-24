# Inequality

### 1. Definition

$\mathbb{R}$ equipped with total order:

$$
\left\{\begin{array}{ll}
a < b, ~~~~ &\text{if} ~ a - b ~ \text{is negative} \\
a = b, ~~~~ &\text{if} ~ a - b = 0 \\
a > b, ~~~~ &\text{if} ~ a - b ~ \text{is positive}
\end{array}\right.
$$

That is, the comparison between real numbers should be done by subtraction.

> **Example**. Which one is larger: $(x+3)(x+7)$ or $(x+4)(x+6)$
> 
> Do Subtraction: 
>
> $$
> (x+3)(x+7) - (x+4)(x+6) = (x^2+10x+21)-(x^2+10x+24) = -3 < 0
> $$
> 
> which shows that $(x+3)(x+7) < (x+4)(x+6)$.
>
> As a shortcut to see this result at a glance, we notice the given polynomial fits the form as formula of square difference
>
> $$
> (x+\Delta x)(x-\Delta x) = x^2 - (\Delta x)^2 > x^2
> $$
> 
> This implies that as the offset $\Delta x$ increased, the result will be smaller.







### 2. Basic Property

The properties of inequality are listed following without prove, since it's easy to give the proof based on the definition:

1. $a < b \Leftrightarrow b > a$.

2. Transitivity. $a < b, b < c \Rightarrow a < c$.

3. First-order operation. $a < b \Rightarrow a+c < b+c$.

	Furthermore, use this property and the transitivity, we can prove that, $a > b, c > d \Rightarrow a + c > b + d$, which described as "The inequality with the same direction can be added together."
	
	In another perspective, it can be also regarded as $a > b, d < c \Rightarrow a - d > b - d$, described as "The inequality with the different direction can be subtracted."

	These two asserts is useful thought-shortcut during comparison.

4. Second-order operation. If $a < b$, and $c$ is a positive number, then $ac > bc$. Otherwise, if $c$ is a negative number, then $ac < bc$.

	This is a property that strongly different with the equation. The negative number multiplication changes the direction of inequality.

	Multiple the inequality $a < b$ by itself $n-1$ times, we got $a^n < b^n ~~ (n\in\mathbb{N}^+)$. With the contradiction proof technique applied, we can also prove that $\sqrt[n]{a} < \sqrt[n]{b} ~~ (n\in\mathbb{N}^+)$.







### 3. Utility Inequality

##### # Syrup Inequality

The experience tells us that, if you added sugar into the syrup, it will be sweeter, which indicates that

$$
a > b \Rightarrow \cfrac{a+m}{b+m} > \cfrac{a}{b}, ~~~~ m > 0
$$

This can be easily proved by subtraction:

$$
\cfrac{a+m}{b+m} - \cfrac{a}{b} = \cfrac{b(a+m)-a(b+m)}{b(b+m)} = \cfrac{m}{b(b+m)}(b-a) > 0
$$

which can be described as "Add the same positive number to the denominator and numerator in the proper fraction, the value of fraction will be larger."

Besides, if $a > b$, which means the fraction is an improper fraction, then

$$
a < b \Rightarrow \cfrac{a+m}{b+m} < \cfrac{a}{b}, ~~~~ m > 0
$$

The application of syrup inequality is gathered in [Application of Syrup Inequality](ApplicationOFSyrupInequality.md).



##### # Square Sum Inequality

The square sum inequality based on the non-negative property of square:

$$
(a-b)^2 \ge 0 \Rightarrow a^2 + b^2 \ge 2ab
$$

Both sides are equal if and only if $a = b$. This inequality can be regarded as a various (or the proof middle result) of the famous AM-GM inequality.


