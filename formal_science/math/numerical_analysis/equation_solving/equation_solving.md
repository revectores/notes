# Equation Solving

### 1. Equation Solving by Bisection

Recall the intermediate value theorem, the continuous function $f(x)$ in $[a, b]$ with $f(a)f(b) < 0$ indicates there is at least one zero point in interval $[a, b]$. To find the zero point between, all we have to do is to squeeze (normally halving for each step) the size of interval until the length of interval is less then precision requirement, since we can use any point in that interval as the solution.







### 2. Equation Solving by Iteration

##### # Iteration Method Definition

Transform $f(x)$ by the form $x=\varphi(x)$. Construct the iteration sequences $x_{k+1} = \varphi(x_k), k=1,2,\cdots$ based on $x_0$, if the iteration converges, that is,
$$
\lim_{k\to \infty} x_{k+1} = \lim_{k\to\infty} \varphi(x_k) = \alpha
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



##### # Converges Condition of Iteration Method

**Theorem**. If $\varphi(x) \in [a, b]$ satisfies

1. $a\le \varphi(x) \le b$ for all $x\in[a, b]$.
2. $\varphi(x)$ is differentiable in $[a,b]$, and there exists $0<L<1$, $\left| \varphi'(x) \right| \le L$ for all $x\in [a, b]$.

Then there exists unique one $x^*$ that satifies $x^* = \varphi(x^*)$, $x^*$ is the **fixed point**. The interation $x_{k+1} = \varphi(x_k)$ for any initial value $x_0\in[a, b]$ converges to $x^*$, and
$$
|x^* - x_k| \le \frac{L^k}{1-L}|x_1 - x_0|
$$

> **Proof**. **Existency**. Let $\psi(x) = x - \varphi(x)$, we have
> $$
> \begin{align}
> \psi(a) = a - \varphi(a) \le 0 \\
> \psi(b) = b - \varphi(b) \ge 0 \\
> \end{align}
> $$
> The intermediate value theorem gives, for some $a\le x^* \le b$, we have $\psi(x^*) = x^* - \varphi(x^*) = 0$.
>
> **Uniqueness**. If there exists another $x^{**}$ which makes $x^{**} = \varphi(x^{**})$, then we check their difference
> $$
> |x^{*} - x^{**}|
> = |\varphi(x^*) - \varphi(x^{**})| 
> = |\varphi'(\xi)(x^* - x^{**})|
> \le L|x^* - x^{**}|
> $$
> Since $L < 1$, we have $x^* = x^{**}$. That is, the fixed point is unique.
>
> **Convergence**. When $x_0\in [a, b]$, differential mean value theorem gives
> $$
> x_{k+1} - x^* = \varphi(x_k) - \varphi(x^*) = \varphi'(\xi_k)(x_k - x^*), \quad\xi_k \in [a,b]
> $$
> Note that $|\varphi'(x)| \le L$,
> $$
> \begin{align}
> |x_{k-1} - x^*|
> &= |\varphi(x_k) - \varphi(x^*)| \\
> &\le L|x_k - x^*| \\
> &\le L^2|x_{k-1}-x^*| \\
> &\le \ldots \\
> &\le L^{k+1}|x_0 - x^*|
> \end{align}
> $$
> Since $L < 1$, we have $L^{k+1}\rightarrow 0, x_{k+1}\rightarrow x^*$. That is, the iteration form $x_{k+1} = \varphi(x_k)$ converges.
>
> **Error Estimation**. $|x_{k-1} - x^*| \le L^{k+1}|x_0 - x^*|$, with fixed $k$, for any positive integer $p$ we have
> $$
> \begin{align}
> |x_{k+p} - x_k|
> &= |x_{k+p} - x_{k+p-1} + x_{k+p-1} - x_{k+p-2} + \cdots + x_{k+1} - x_k | \\
> &\le |x_{k+p} - x_{k+p-1}| + |x_{k+p} - x_{k+p-1}| + \cdots + |x_{k+1} - x_{k}| \\
> &\le (L^{k+p-1} + L^{k+p-2} + \cdots + L^k)|x_1-x_0| \\
> &= \frac{L^k(1-L^p)}{1-L}|x_1-x_0|
> \end{align}
> $$
>



##### # Order of Interation Method

If the iteration form $x_{k+1} = \varphi(x_k)$ converges, $\alpha$ is the root, if
$$
\lim_{k\rightarrow\infty}\frac{|x_{k+1}-\alpha|}{|x_k - \alpha|^n} = M
$$
then we define the order of the interation method as $n$.







### 3. Equation Solving by Newton's Method

As shown in previous section, there are multiple iteration form $x_{k+1} = \varphi(x_k)$ for an equation $f(x) = 0$. The Newton's iteration utilize Taylor series:
$$
f(x) = f(x_0) + f'(x_0)(x-x_0) + \frac{f''(x_0)}{2!}(x-x_0)^2 + \cdots
$$

Use the linear part as the approximation of $f(x)$:
$$
f(x_0) + f'(x_0)(x-x_0) \approx 0
$$

if $f'(x_0) \neq 0$,
$$
x = x_0 - \frac{f(x_0)}{f'(x_0)}
$$
The Newton iteration is defined as form
$$
x_{k+1} = x_k - \frac{f(x_k)}{f'(x_k)}
$$

the corresponding equation
$$
x = \varphi(x) = x - \frac{f(x)}{f'(x)}
$$

$$
\varphi'(x) = 1 - \left( \frac{f'(x)}{f'(x)} - \frac{f(x)f''(x)}{(f'(x))^2}  \right) = \frac{f(x)f''(x)}{(f'(x))^2}
$$

If the root $\alpha$ is single root, $f(\alpha) = 0, f'(\alpha)\neq 0$, we have $|\varphi'(\alpha)| = 0$, if the distance of initial value $x_0$ and $\alpha$ is small enough, there must be $\varphi'(x) < 1$, that is, the Newton iteration converges in the neighbourhood of root.

We can prove that if the root $\alpha$ is single root, Newton's interation is second-order, and if $\alpha$ is multiple root, the iteration converges but it degenerates to first-order, but if we modify the iteration form to
$$
x_{k+1} = x_k - p\frac{f(x_k)}{f'(x_k)}
$$
this is a second-order method again.

The geometry interpretation of Newton's method is update using the intersection of the tangent line $l$ of function $f(x)$ at point $x_0$ with x-axis, where
$$
l: y - f(x_0) = f'(x_0)(x - x_0)
$$
The essence of the Newton's method is using line to approximate the non-liner curve by applying Taylor series.







### 4. Equation Solving by Secant Method

In Newton's interation form $x_{k+1} = x_k - \dfrac{f(x_k)}{f'(x_k)}$, if we use the difference $f[x_{k-1}, x_k] = \dfrac{f(x_k) - f(x_{k-1})}{x_k - x_{k-1}}$ to approximate the derivative $f'(x_k)$, we have
$$
x_{k+1} = x_k - \frac{(x_k-x_{k-1})f(x_k)}{f(x_k) - f(x_{k-1})}
$$
This iteration form is called **chord method**. The geometry interpretation of chord method is updating $x$ using the intersection of the secant line determined by $(x_k, f(x_k)), (x_{k+1}, f(x_{k+1}))$ and $x$-axis.

The order of chord method is 1.618, hence the converge speed of chord method is less than Newton's method.


