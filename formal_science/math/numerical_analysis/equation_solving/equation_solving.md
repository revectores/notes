# Equation Solving

### 1. Equation Solving by Bisection

Recall the intermediate value theorem, which says for the continuous function $f(x)$ in $[a, b]$ and $f(a)f(b) < 0$ indicates there is at least one zero point in interval $[a, b]$.

Algorithm description:

Input: initial interval $[a, b]$, precision $\varepsilon$.







### 2. Equation Solving by Iteration

Express the function $f(x)$ by the form $x=\varphi(x)$. Construct the iteration sequences $x_{k+1} = \varphi(x_k), k=1,2,\cdots$ based on $x_0$, if the iteration converges, that is,
$$
\lim_{k\to x_{k+1}} x_{k+1} = \lim_{k\to\infty} \varphi(x_k) = \alpha
$$
we have $\alpha = \varphi(\alpha)$, then $\alpha$ is the root of $f(x)$. When $|x_{k+1}-x_k|$ less than the given precision, we recognize $x_{k+1}$ as the root of function $f(x)$.

> **Example**. List the equivalent of function $x^3-2x-5=0$ and its iteration form.
> $$
> \begin{align}
> & x = \sqrt[3]{2x+5},~~ x_{k+1} = \sqrt[3]{2x_k + 5} \\
> & x = \frac{x^3-5}{2},~~ x_{k+1} = \frac{x_k^3-5}{2} \\
> & x = \frac{2x+5}{x^2},~~ x_{k+1} = \frac{2x_k+5}{x_k^2}
> \end{align}
> $$
> 

**Theorem**. If $\varphi(x) \in [a, b]$ satisfies







### 3. Equation Solving by Newton's Method

The Newton's method starts from guessing a point $x_0$, update using the intersection of the tangent line $l$ of function $f(x)$ at point $x_0$ with x-axis, where
$$
l: y - f(x_0) = f'(x_0)(x - x_0)
$$
Let $y=0$ we have the update







### 4. Equation Solving by Secant Method