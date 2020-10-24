# Numerical Differentiation

$$
\newcommand{\d}{\text{d}}
\newcommand{\dx}{\d x}
\newcommand{\ddx}{\dfrac{\d}{\d x}}
$$

### 1. Differentiation Approximation By Difference Quotient

As known, the derivative from right/left/both sides are defined as the limit of  forward/backward/central difference quotients:
$$
\begin{align}
& f'(x_0) = \lim_{h\rightarrow 0} \frac{f(x_0+h)-f(x_0)}{h} \\
& f'(x_0) = \lim_{h\rightarrow 0} \frac{f(x_0)-f(x_0-h)}{h} \\
& f'(x_0) = \lim_{h\rightarrow 0} \frac{f(x_0+h)-f(x_0-h)}{2h}
\end{align}
$$
respectively, and they are equivalent if the function $f(x)$ is derivative at $x_0$, hence we just use the difference quotients to approximate those derivatives:
$$
\begin{align}
& f'(x_0) \approx \frac{f(x_0+h)-f(x_o)}{h} \\
& f'(x_0) \approx \frac{f(x_0)-f(x_0-h)}{h} \\
& f'(x_0) \approx \frac{f(x_0+h)-f(x_0-h)}{2h}
\end{align}
$$
The truncation error of forward/backward difference is
$$
R(x) = f'(x_0) - \frac{f(x_0+h)-f(x_0)}{h} = -\frac{h}{2}f''(\xi) = O(h)
$$

> **Proof**. The [Taylor formula]() gives
> $$
> f(x_0 + h) = f(x_0) + hf'(x_0) + \frac{h^2}{2!}f''(\xi),~~~~\xi\in[x_0, x_0+h]
> $$
> Hence
> $$
> R(x) = f'(x_0) - \frac{f(x_0+h)-f(x_0)}{h} = -\frac{h}{2}f''(\xi)
> $$

and the truncation error of central difference quotient is
$$
R(x) = f'(x_0) - \frac{f(x_0+h)-f(x_0-h)}{2h} = -\frac{h^2}{6}f'''(\xi) = O(h^2), ~~~~ \xi\in[x_0-h, x_0+h]
$$

> **Proof**. The Taylor formula gives
> $$
> \begin{align}
> & f(x_0 + h) = f(x_0) + hf'(x_0) + \frac{h^2}{2!}f''(x_0) + \frac{h^3}{3!}f'''(\xi_1) \\
> & f(x_0 - h) = f(x_0) - hf'(x_0) + \frac{h^2}{2!}f''(x_0) - \frac{h^3}{3!}f'''(\xi_1)
> \end{align}
> $$
> Substract and devided by $2h$ we get
> $$
> \frac{f(x_0+h)-f(x_0-h)}{2h}
> = f'(x_0) + \frac{h^2}{2\cdot3!}f'''(\xi_1) + \frac{h^2}{2\cdot3!}f'''(\xi_2)
> $$
> Hence
> $$
> R(x)
> = f'(x_0) - \frac{f(x_0+h)-f(x_0-h)}{2h}
> = -\frac{h^2}{6}f'''(\xi) = O(h^2),
> ~~~~\xi\in[x_0-h, x_0+h]
> $$



### 2. Numerical Differentiation by Interpolation

For the given function values, construct Lagrange intropolation polynomials
$$
f(x) \approx L_n(x) = \sum_{i=0}^n l_i(x)f(x_i) \\
$$
The derivative
$$
f'(x) \approx L'_n(x) = \sum_{i=0}^n l'_i(x)f(x_i)
$$



$$
R(x) = \ddx \left( \frac{f^{(n+1)}(\xi)}{(n+1)!}\prod_{i=0}^n(x-x_i) \right)
$$

$$
R(x_j) = \prod_{i=0\\i\neq j}^n (x_j-x_i)\frac{f^{(n+1)}(\xi)}{(n+1)!}
$$

$$
\begin{align}
& f'(x_0) = \frac{1}{2h}(-3f(x_0) + 4f(x_1) - f(x_2)) \\
& f'(x_1) = \frac{1}{2h}(-f(x_0) + f(x_2)) \\
& f'(x_2) = \frac{1}{2h}(f(x_0) + -f(x_1) + 3f(x_2)) \\
\end{align}
$$












