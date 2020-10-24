# AM-GM Inequality

### 1. Two Variable Case

The AM-GM inequality shows the relation between arithmetic mean $\cfrac{a+b}{2}$ and the geometric mean $\sqrt{ab}$.

$$
\cfrac{a+b}{2} \ge \sqrt{ab} ~~~~ (a, b > 0)
$$

> **Proof**.
> $$
> a+b = (\sqrt a)^2 + (\sqrt b)^2 \ge 2\sqrt{ab} ~\Rightarrow~ \cfrac{a+b}{2} \ge \sqrt{ab}
> $$

Some geometric interpretations of this inequality:

- In the right triangle, the middle line of hypotenuse is longer than the height of the hypotenuse.

- Diameter is the longest chord.







### 2. General Case

##### # Form and Interpretation

The general form of AM-GM inequality is

$$
\cfrac{1}{n} \sum{x_i} \ge \prod{x_i^{\frac{1}{n}}}
$$

Denote $A_n$ as the arithmetic mean of $n$ variables, and $G_n$ as geometric mean of $n$ variables, the AM-GM inequality can be formally written as

$$
A_{n} \ge G_{n}
$$

and $A_n = G_n$ iff all $x_i$ are identical. That is,

- If the sum of numbers are constant, we got the maximal product when the numbers are the same.

- If the product of numbers are constant, we got the minimal sum when the numbers are the same.

These two results are very useful in practice. For example, to fence the maximum rectangle area with constant length of fence, we make it a square.



##### # Proofs

The most simple and intrinsic proof method is using **Jensen's inequality**, with logarithm function $f(x) = \log x$.

> Proof 1. 
> $$
> \log \left( {\cfrac{1}{n} \sum x_{i}} \right)
> \ge \cfrac{1}{n} \sum{\log x_{i}}
> = \cfrac{1}{n} \log \left( \prod x_{i} \right)
> = \log \left( \prod x_{i}^{\frac{1}{n}} \right)
> $$

This prove shows that the essence of AM-GM inequality is: the logarithm function is concave function.

Most of the other approaches of proofs are not as simple as Jensen's inequality. Here we list the represents to illustrate the methods.

> Proof 2. (Cauchy forward-backward induction)
> 
> The core idea of this approach is, prove the $n = 2^k$ cases first (since this is much simpler by grouping), then we inducting it backward, from $n = k$ to $n = k - 1$.
>
>
> Assume the $n = k$ case is correct, then, for the $n = 2k$ case,
>
> $$
> A_{2k}
> = \cfrac{1}{2k} \left( \sum_{i=1}^k {x_i} + \sum_{i=k+1}^{2k} {x_i} \right)
> = \cfrac{1}{2} \left( \cfrac{1}{k} \left( \sum_{i=1}^k {x_i} \right) + \cfrac{1}{k} \left( \sum_{i=k+1}^{2k} {x_i} \right) \right)
> \ge \cfrac{1}{2} \left( \left( \prod_{i=1}^{k} {x_i^{\frac{1}{k}}} \right) + \left( \prod_{i=k}^{2k} {x_i^{\frac{1}{k}}} \right)  \right)
> \ge G_{2k}
> $$
>
> Since the $n=2$ case has been proved before, by which we proved any $n = 2^k, k\in\mathbb{Z}$ cases. 
>
> Assume that $n = k$ case is correct,
>
> $$
> \cfrac{1}{k} \left( \sum_{i=1}^{k-1}{x_{i}} + A_{k-1} \right) \ge \left( A_{k-1}\prod_{i=1}^{k-1}x_i \right)^{\frac{1}{k}}
> $$
>
> which implies that
>
> $$
> \begin{align}
> \cfrac{1}{k} \left( (k-1)A_{k-1} + A_{k-1} \right) & \ge \left( A_{k-1}G_{k-1}^{k-1} \right)^{\frac{1}{k}} \\
> A_{k-1}^{k} & \ge A_{k}G_{k-1}^{k-1} \\
> A_{k-1} & \ge G_{k-1}
> \end{align}
> $$
> 
> by which we proved that if $n = k$ case is correct, it ensures the $n = k-1$ case is correct. Since we've proved the $n = 2^k$ cases, for any given number $n$, we can always find a larger number and trace backward to the given $n$. So we've proved it successfully for any number $n\in\mathbb{Z}$.

With the binomial theorem applied, we can directly use the forward induction, instead of the indirect way in proof 2.

> Proof 3. (normal induction, with the binomial theorem applied)
>
> $$
> A_{n+1}^{n+1} = \left(A_n + \cfrac{x_{n+1}-A_{n}}{n+1} \right)^{n+1}
> \ge A_{n}^{n+1} + (n+1)A_n \cfrac{x_{n+1}-A_{n}}{n+1}
> = A_{n}x_{n+1}
> \ge G_{n}x_{n+1}
> = G_{n+1}^{n+1}
> $$









### 3. Generalization

##### # Weighted Form

If we adjust the weight for each variables, we got the weighted AM-GM inequality:

$$
\cfrac{1}{w} \sum{w_{i}x_{i}}  \ge  \left( \prod x_i^{w_{i}} \right)^{w^{-1}}, ~~~~ \text{where} ~~ w = \sum w_{i}
$$

This can be proved by the Jensen's inequality similarly. Note that this not only generalize the weights, but also generalize the sum of them into any real number.






