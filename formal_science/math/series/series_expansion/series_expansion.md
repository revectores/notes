# Series Expansion

$$
\newcommand{\e}{\text{e}}
$$



Taylor Series for $f(x)$ at $x_0$
$$
f(x) = \sum_{n=0}^{\infty}\frac{f^{(n)}(x_0)}{n!}(x-x_0)^n
=  f(x_0) + f'(x_0)(x-x_0) + \frac{f''(x_0)}{2!}(x-x_0)^2 + \cdots
$$
when $x_0=0$, the taylor series is also named as **MacLaurin series**:
$$
f(x) = \sum_{n=0}^{\infty}\frac{f^{(n)}(0)}{n!}x^n = f(0) + f'(0)x + \frac{f''(0)}{2!}x^2 + \cdots
$$


If the function $f(x)$ has infinite level of derivatives, it can be expanded into Taylor series if and only if $\displaystyle \lim_{n\rightarrow\infty} R_n(x)=0$

> **Proof**. Let $f(x) = S_{n+1}(x) + R_n(x)$
> $$
> \lim_{n\rightarrow\infty} R_n(x) = \lim_{n\rightarrow\infty}[f(x)-S_{n+1}(x)] = 0
> $$

If $f(x)$ can be expanded into power series, the expansion is unique, and it's the same as its MacLaurin series.

> **Proof**. Assume the $f(x)$ can be expanded into power series
> $$
> f(x) = a_0 + a_1x + a_2x^2 + \cdots + a_nx^n + \cdots
> $$
> Then we have
> $$
> \begin{align}
> & f'(x) = a_1 + 2a_2x + \cdots + na_nx^{n-1} + \cdots \\
> & f''(x) = 2!a_2 + \cdots + n(n-1)a_nx^{n-2} + \cdots \\
> & f^{(n)}(x) = n!a_n
> \end{align}
> $$
>



Two methods to expand a function into power series:

1. Applying Taylor series.
2. Applying the known function power series expansion.

> **Example**. Expand $\e^x$ into power series.
> $$
> \e^x = 1 + x + \frac{1}{2!}x^2 + \frac{1}{3!}x^3 + \cdots + \frac{1}{n!}x^n + \cdots
> $$
> To find the radius of convergence, we compute the limit
> $$
> \displaystyle \rho = \lim_{n\rightarrow\infty} \frac{n!}{(n+1)!} = \lim_{n\rightarrow\infty} \frac{1}{n+1} = 0
> $$
> Hence the radius of convergence $R = \infty$.
>
> For any number $x$, the remainder
> $$
> \lim_{n\rightarrow\infty} |R_n(x)|
> = \lim_{n\rightarrow\infty}\left|  \frac{\e^\xi}{(x+1)!}x^{n+1} \right|
> < \lim_{n\rightarrow\infty}\e^{|x|} \frac{|x|^{n+1}}{(n+1)!} = 0
> $$

Hence $\displaystyle \e^x = 1 + x + \frac{1}{2!}x^2 + \frac{1}{3!}x^3 + \cdots + \frac{1}{n!}x^n + \cdots~~(x\in\mathbb{R})$





> **Example**. Expand $\sin x$ into power series.
> $$
> f^{(n)}(0) =
> \left\{\begin{array}{ll}\begin{align}
> &0, && n = 2k \\
> &(-1)^k, && n = 2k+1
> \end{align}\end{array}\right.
> $$
> 
> $$
> \sin x
> = \sum_{n=0}^\infty \frac{(-1)^nx^{2n+1}}{(2n+1)!}
> = x - \frac{x^3}{3!} + \frac{x^3}{5!} - \frac{x^7}{7!} + \cdots
> $$
> The radius of convergence $R = \infty$. For any $x$, the remainder
> $$
> \lim_{n\rightarrow\infty}  |R_n(x)|
> = \lim_{n\rightarrow\infty} \left| \frac{\sin\left(\xi + (n+1)\dfrac{\pi}{2}\right)}{(n+1)!}  \right|
> < \lim_{n\rightarrow\infty}  \frac{|x|^{n+1}}{(n+1)!} = 0
> $$
> 


$$
(1+x)^m = 1 + mx + \frac{m(m-1)}{2!}x^2 + \cdots + \frac{m(m-1)(m-n+1)}{n!}x^n + \cdots (-1<x<1)
$$
$m = 1/2$,
$$
\sqrt{1+x} = 1 + \frac{1}{2}x + \frac{1}{2\times4}x^2 + \frac{1\times3}{2\times4\times6}x^3 + \cdots
$$

$$
\frac{1}{\sqrt{1+x}} = 1 + \frac{1}{2}x + \frac{1\times3}{2\times4}x^2 + \cdots
$$


$$
\frac{1}{1+x} = 1 -x +x^2 -x^3 +\cdots+(-1)^nx^n +\cdots (-1<x<1)
$$

$$
\frac{1}{1-x} = 1 +x +x^2 +x^3 + \cdots
$$





Applying the known function power series expansion:

> Example. Expand $\dfrac{1}{1+x^2}$
> $$
> \frac{1}{1+x^2} =
> $$
> 



> Example. Expand $\ln(1+x)$ into the power series of $x$
>
> $\displaystyle \ln(1+x) = \sum_{n=1}^{\infty}(-1)^n \int_0^x x^n = \sum_{n=1}^{\infty} \frac{(-1)^n}{n+1}x^{n+1}$

$$
\ln 2 = 1 - \frac{1}{2} + \frac{1}{3} - \frac{1}{4} + \cdots
$$



> Example. Expand $\sin x$ into power series of $\left(x-\dfrac{\pi}{4}\right)$.















