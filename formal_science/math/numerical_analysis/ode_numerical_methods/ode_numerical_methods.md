# Numerical Methods for Ordinary Differential Equation Initial Value Problem

$$
\newcommand{\d}{\text d}
\newcommand{\dx}{\d x}
\newcommand{\dy}{\d y}
\newcommand{\dt}{\d t}
\newcommand{\dd}[2]{\dfrac{\d #1}{\d #2}}
\newcommand{\dyx}{\dd{y}{x}}
$$

### 1. Introduction

##### # Numerical Methods for ODE IVP

Recall the general form of initial value problem(IVP) of ODE
$$
\left\{\begin{array}{ll}
\dyx = f(x, y) \\
y(a) = y_0
\end{array}\right.
\quad a\le x \le b
$$
For most of the IVPs, it is impossible to determine the analytical solution, where the numerical methods must be applied.

There are three primary numerical methods to solve ODE IVP:

- **Finite difference method(FDM)** aims to give approximations for specific points $\{(x_n, y(x_n)), n = 1, 2, \ldots, m \}$, which will be introduced in this document.
- Finite element method.
- Finite volume method.



##### # Order of Precision

When we estimate $y_{n+1}$ using $y_0$, the truncation error in each step (named **local truncation error**) will accumulate to **global truncation error**, which determines whether the method converges.

A method with local truncation error $T_{n+1} = O(h^{p+1})$ is **$p$-order**, since with $T_{n+1} = O(h^{p+1})$ the method will be accurate for all polynomial functions with order is $p$ at most.







### 2. Euler Method

Recall that derivative can be approximated by [difference quotient](), includes forward/backward/central difference quotients, which gives forward/backward/central Euler method respectively.

Equivalently, we can also integrate the differential equation
$$
\int_{x_n}^{x_{n+1}}y'(x)\dx = \int_{x_n}^{x_{n+1}}f(x, y)\dx
$$

$$
\begin{align}
y(x_{n+1}) &= y(x_n) + \int_{x_n}^{x_{n+1}}f(x, y)\dx \\
           &= y(x_n) + \int_{x_n}^{x_{n+1}}y'(t)\dt
\end{align}
$$

By using the left rectangle/right rectangle/trapezoid to estimate the integral, it gives forward Euler method/backward Euler method/trapezoid method respectively.



##### # Forward Euler Method

Use forward difference quotient to estimate derivative:
$$
f(x_n, y_n) = y'(x_n) = \frac{y(x_{n+1}) - y(x_n)}{h}
$$

$$
y_{n+1} = y_n + hf(x_n, y_n)
$$
The geometric interpretation of foward euler method is evident: It use the tangent line at $(x_n, y_n)$ to estimate the curve and compute $y_{n+1}$. Apparently, it can overestimate $y_n$ if $y'' < 0$, or underestimate the value if $y'' > 0$.

Since Euler method is simply the linear truncation of Taylor series, the local truncation error of Euler method is $O(h^2)$, that is, forward Euler method is first order method.



##### # Backward Euler Method

Use backaward difference quotient to estimate derivative:
$$
f(x_{n+1}, y_{n+1}) = y'(x_{n+1}) = \frac{y(x_{n+1}) - y(x_n)}{h}
$$

$$
y_{n+1} = y_n + hf(x_{n+1}, y_{n+1})
$$

Note that the backward Euler method is an **implicit method**, which requires $y_{n+1}$ to compute $y_{n+1}$. This paradox can be resolved by providing the initial value by one explicit method (for instance, forward Euler method) and iterate until the value converges. Formally, this is what we called **Picard iteration**:
$$
\left\{\begin{array}{ll}
y_{n+1}^{(0)} = y_n + hf(x_n, y_n) \\
y_{n+1}^{(k+1)} = y_n + hf(x_{n+1}, y_{n+1}^{(k)})
\end{array}\right.
\quad k \in \N
$$
It can be proved that for sufficiently small $h$ the iteration must converge, formally, for $\varphi(y) = y_n + hf(x_{n+1}, y)$, $\varphi'(h) = hf_y(x_n, y)$, and for sufficiently small $h$ we have $|hf_y(x_n, y)|\le hL < 1$, where $L$ is the Lipschitz constant.

In pratice, the result given by explicit method is close enough to actual value, and it's acceptable to apply simple **Predictor–corrector method**, which only executes the implicit method once:
$$
\left\{\begin{array}{ll}
\overline{y}_{n+1} = y_n + hf(x_n, y_n) \\
y_{n+1} = y_n + hf(x_{n+1}, \overline y_{n+1})
\end{array}\right.
$$



##### # Central Difference Form

Use central difference quotient to estimate derivative:
$$
f(x_n, y_n) = y'(x_n) = \frac{y(x_{n+1}) - y(x_{n-1})}{2h}
$$

$$
y_{n+1} = y_{n-1} + 2hf(x_n, y_n)
$$

as we'll introduced in [Stability of Numerical Methods](), the central difference form  is not stable and is not used in practice.



##### # Trapezoid Method and Refined Euler Method

Use trapezoid to estimate the integral:
$$
\begin{align}
\int_{x_n}^{x_{n+1}}y'(t)\dt
&= y(x_{n+1}) - y(x_n) \\
&= \frac{1}{2}(x_{n+1} - x_n)(y'(x_{n+1})  + y'(x_n)) \\
&= \frac{h}{2}(f(x_n, y(x_n)) + f(x_{n+1}, y(x_{n+1})))
\end{align}
$$
That is,
$$
y_{n+1} = y_n + \frac{h}{2}(f({x_n}, y_n) + f(x_{n+1}, y_{n+1}))
$$
Note that trapezoid method is implicit, by applying the explicit forward Euler as the first step, we have the **refined Euler method**:
$$
\left\{\begin{array}{ll}
\overline{y}_{n+1} = y_n + hf(x_n, y_n) \\
y_{n+1} = y_n + \dfrac{h}{2}(f(x_n, y_n) + f(x_{n+1}, \overline{y}_{n+1}))
\end{array}\right.
\quad
$$

or
$$
y_{n+1} = y_n + \frac{h}{2}(f(x_n, y_n) + f(x_{n+1}, y_n + hf(x_n, y_n))
$$






### 3. Runge-Kutta Method

Taylor expand $y(x+h)$ at $x$:
$$
\begin{align}
y(x+h)
&= y(x) + hy'(x) + \frac{h^2}{2!}y''(x) + \cdots + \frac{h^p}{p!}y^{(p)}(x) + \frac{h^{(p+1)}}{(p+1)!}y^{(p+1)}(x + \theta h) \\
&= y(x) + hy'(x) + \frac{h^2}{2!}y''(x) + \cdots + \frac{h^p}{p!}y^{(p)}(x) + T
\end{align}
$$
where $0\le \theta \le 1, T = O(h^{p+1})$.

Let $x = x_n$,
$$
y(x_{n+1}) = y(x_n) + hy'(x_n) + \frac{h^2}{2!}y''(x_n) + \cdots + \frac{h^p}{p!}y^{(p)}(x_n) + T_{n+1}
$$
For $p = 1$,
$$
y(x_{n+1}) = y(x_n) + hf(x_n, y(x_n)) + T_{n+1}
$$
which is the forward Euler formula.

For $p=2$,
$$
y(x_{n+1})
= y(x_n) + hy'(x_n) + \frac{h^2}{2!}y''(x_n) + T_{n+1}
$$
where
$$
y''(x_n) = f_x(x_n, y(x_n)) + f_y(x_n, y(x_n))f(x_n, y(x_n))
$$
to avoid the computation of partial derivatives, we try to use the linear combination
$$
c_1f(x_n, y(x_n)) + c_2f(x_n + ah, y(x_n) + bhf(x_n, y(x_n)))
$$
to approximate $y''(x_n)$.



We have
$$
\left\{\begin{array}{ll}
c_1 + c_1 = 1 \\
2c_2a = 1 \\
2c_2b = 1
\end{array}\right.
$$
Let $c_1 = \dfrac{1}{2}, c_2 = \dfrac{1}{2}, a = 1, b =1$, we get one of 2nd order Runge-Kutta formula:
$$
\left\{\begin{array}{ll}
y_{n+1} = y_n + \dfrac{h}{2}(k_1 + k_2) \\
k_1 = f(x_n, y_n) \\
k_2 = f(x_n + h, y_n + hf(x_n, y_n))
\end{array}\right.
$$
which form is the same as the **refined Euler formula**.

Another coffecients combination $c_1 = 0, c_2 = 0, a = \dfrac{1}{2}, b = \dfrac{1}{2}$ is called the **middle point formula**:

The truncation error of 2nd order Runge-Kutta formula is $O(h^3)$.
$$
\left\{\begin{array}{ll}
y_{n+1} = y_n + hk_2 \\
k_1 = f(x_n, y_n) \\
k_2 = f\left(x_n + \dfrac{h}{2}, y_n + \dfrac{h}{2}k_1\right)
\end{array}\right.
$$


Similarly, we have the 3rd-order and 4th-order Runge-Kutta formula:

3rd-order:
$$
\left\{\begin{array}{ll}
y_{n+1} = y_n + \dfrac{h}{6}(k_1 + 4k_2 + k_3) \\
k_1 = f(x_n, y_n) \\
k_2 = f\left(x_n + \dfrac{h}{2}, y_n + \dfrac{h}{2}k_1\right) \\
k_3 = f(x_n + h, y_n - hk_1 + 2hk_2)
\end{array}\right.
$$

$$
\left\{\begin{array}{ll}
y_{n+1} = y_n + \dfrac{h}{4}(k_1 + 3k_3) \\
k_1 = f(x_n, y_n) \\
k_2 = f\left(x_n + \dfrac{h}{3}, y_n + \dfrac{h}{3}k_1\right) \\
k_3 = f\left(x_n + \dfrac{2}{3}h, y_n + \dfrac{2}{3}hk_2\right)
\end{array}\right.
$$

$$
\left\{\begin{array}{ll}
y_{n+1} = y_n + \dfrac{h}{9}(2k_1 + 3k_2 + 4k_3) \\
k_1 = f(x_n, y_n) \\
k_2 = f\left(x_n + \dfrac{h}{2}, y_n + \dfrac{h}{2}k_1\right) \\
k_3 = f\left(x_n + \dfrac{3}{4}h, y_n + \dfrac{3}{4}hk_2\right)
\end{array}\right.
$$

4th-order:
$$
\left\{\begin{array}{ll}
y_{n+1} = y_n + \dfrac{h}{6}(k_1 + 2k_2 + 2k_3 + k_4) \\
k_1 = f(x_n, y_n) \\
k_2 = f\left(x_n + \dfrac{1}{2}h, y_n + \dfrac{1}{2}hk_1\right) \\
k_3 = f\left(x_n + \dfrac{1}{2}h, y_n + \dfrac{1}{2}hk_2\right) \\
k_4 = f(x_n + h, y_n + hk_3)
\end{array}\right.
$$

$$
\left\{\begin{array}{ll}
y_{n+1} = y_n + \dfrac{h}{8}(k_1 + 3k_2 + 3k_3 + k_4) \\
k_1 = f(x_n, y_n) \\
k_2 = f\left(x_n + \dfrac{1}{3}h, y_n + \dfrac{1}{3}hk_1\right) \\
k_3 = f\left(x_n + \dfrac{2}{3}h, y_n + \dfrac{1}{3}hk_1 + hk_2\right) \\
k_4 = f(x_n + h, y_n + hk_1 - hk_2 + hk_3)
\end{array}\right.
$$








### 3. Linear Multistp Method

The IVP $\dyx = f(x, y)$ is equivalent to compute integral
$$
y(x) = y(x^*) + \int_{x^*}^x f(x, y)\dx
$$

Specifically, in interval $[x_{n-p}, x_{n+1}]$ we have
$$
y(x_{n+1}) = y(x_{n-p}) + \int_{x_{n-p}}^{x_{n+1}}f(x, y)\dx
$$

Now we're able to solve the IVP by computing the integral with numerical methods. This is what we called **linear multistep method**. As shown, $p$ specifies the interval of integral, and we introduce $q$ to denote number of integral segment (that is, $q+1$ interpolation points):

- For **explicit form**, the interpolation pointers are
    $$
    \{x_n, x_{n-1}, \ldots, x_{n-q}\}
    $$

- For **implicit form**, the interpolation pointers are
    $$
    \{x_{n+1}, x_n, \ldots x_{n+1-q}\}
    $$

> **Example**. Construct the explicit form of linear multistep method with $p=1, q=2$.
>
> **Solution**. The integral interval is $[x_{n-1}, x_{n+1}]$, integral pointers are $\{x_n, x_{n-1}, x_{n-2}\}$.
> $$
> y_{n+1} = y_{n-1} + \int_{x_{n-1}}^{x_{n+1}}f(x, y)\dx
> $$
> where
> $$
> \begin{align}
> \int_{x_{n-1}}^{x_{n+1}}f(x, y)\dx
> &= \int_{x_{n-1}}^{x_{n+1}} \left[l_0(x) f(x_n, y_n) + l_1(x) f(x_{n-1}, y_{n-1}) + l_2(x) f(x_{n-2}, y_{n-2})\right] \dx \\
> &= \int_{x_{n-1}}^{x_{n+1}}l_0(x)f(x_n, y_n)\dx
>  + \int_{x_{n-1}}^{x_{n+1}}l_1(x)f(x_{n-1}, y_{n-1})\dx 
>  + \int_{x_{n-1}}^{x_{n+1}}l_2(x)f(x_{n-2}, y_{n-2})\dx 
> \end{align}
> $$
>
> Compute the cofficients:
> $$
> \begin{align}
> & \int_{x_{n-1}}^{x_{n+1}} l_0(x)\dx
> = \int_{x_{n-1}}^{x_{n+1}} \frac{(x-x_{n-2})(x-x_{n-1})}{(x_n - x_{n-2})(x_n - x_{n-1})}\dx
> = \frac{7}{3}h \\
> 
> & \int_{x_{n-1}}^{x_{n+1}} l_1(x)\dx
> = \int_{x_{n-1}}^{x_{n+1}} \frac{(x-x_{n})(x-x_{n-2})}{(x_{n-1} - x_{n})(x_{n-1} - x_{n-2})}\dx
> = -\frac{2}{3}h \\
> 
> & \int_{x_{n-1}}^{x_{n+1}} l_2(x)\dx
> = \int_{x_{n-1}}^{x_{n+1}} \frac{(x-x_{n})(x-x_{n-1})}{(x_{n-2} - x_{n})(x_{n-2} - x_{n-1})}\dx
> = \frac{1}{3}h \\
> \end{align}
> $$
>
> Hence the formula is
> $$
> y_{n+1} = y_{n-1} + \frac{h}{3}\left[7f(x_n, y_n) - 2f(x_{n-1}, y_{n-1}) + f(x_{n-2}, y_{n-2})\right]
> $$
> The truncation error $R(x)$
> $$
> R(x) = \frac{1}{6}\int_{x_{n-1}}^{x_{n+1}} y^{(4)}\eta(x)(x - x_n)(x - x_{n-1})(x - x_{n-2})\dx
> $$
>

The linear multistep method form with $p=0$ is called $(q+1)$-order (explicit/implicit) Adams formula. For instances:

Let $p = 0, q = 1$ in explicit form, we have 2nd-order explicit Adams formula
$$
y_{n+1} = y_n + \frac{h}{2}[3f(x_n, y_n) - f(x_{n-1}, y_{n-1})]
$$
Let $p=0, q = 2$ in explicit form, we have 3rd-order explicit Adams formula
$$
y_{n+1} = y_n + \frac{h}{12}(23f(x_n, y_n) - 16f(x_{n-1}, y_{n-1}) + 5f(x_{n-2}, y_{n-2}))
$$


Let $p = 0, q = 1$ in implicit form, we have 2nd-order implicit Adams formula

$$
y_{n+1} = y_n + \frac{h}{2}(f(x_n, y_n) + f(x_{n+1}, y_{n+1}))
$$
which is the trapezoid formula.

Let $p = 0, q=2$ in implicit form, we have 3rd-order implicit Adams formula
$$
y_{n+1} = y_n + \frac{h}{12}[5f(x_{n+1}, y_{n+1}) + 8f(x_n, y_n) - f(x_{n-1}, y_{n-1})]
$$
Let $p = 0, q = 3$ in implicit form, we have 4th-order implicit Adams formula
$$
y_{n+1} = y_n + \frac{h}{24}(9f(x_{n+1}, y_{n+1} + 19f(x_n, y_n) - 5f(x_{n-1}, y_{n-1}) + f(x_{n-2}, y_{n-2})))
$$








### 4. Numerical Methods for Ordinary Differential Euqations

The equations with multiple first-order ODEs
$$
\left\{\begin{array}{ll}
\dd{y_1}{x} = f_1(x, y_1, y_2, \ldots, y_m) \\
\dd{y_2}{x} = f_1(x, y_1, y_2, \ldots, y_m) \\
\ldots \\
\dd{y_m}{x} = f_1(x, y_1, y_2, \ldots, y_m) \\
y_1(a) = \eta_1 \\
y_2(a) = \eta_2 \\
\ldots \\
y_m(a) = \eta_m
\end{array}\right.
$$
can be written as vector form
$$
\left\{\begin{array}{ll}
\dd{Y}{X} = F(X, Y) \\
Y(A) = \eta
\end{array}\right.
$$
where
$$
Y(X) =
\begin{bmatrix}
y_1(x) \\
y_2(x) \\
\vdots \\
y_m(x)
\end{bmatrix}
,
F(X,Y) =
\begin{bmatrix}
f_1(x, y_1, y_2, \ldots, y_m) \\
f_2(x, y_1, y_2, \ldots, y_m) \\
\vdots \\
f_m(x, y_1, y_2, \ldots, y_m) \\
\end{bmatrix}
,
\eta =
\begin{bmatrix}
\eta_1 \\
\eta_2 \\
\vdots \\
\eta_m
\end{bmatrix}
$$
All the methods of single ODE can be applied to the vector form.







### 5. Stability of Numerical Methods

To determine the statbility of numerical methods, we apply the method to differential equation
$$
\left\{\begin{array}{ll}
\dyx = \lambda y \\
y(a) = y_0
\end{array}\right.
\quad x \in [a, b],~\mathcal{Re}(\lambda)< 0
$$
One method is stable, if and only if there exists an area $\Omega$ in left half plain which makes the root of character equation of difference equation less than 1 for any $\lambda h\in \Omega$.

> **Example**. Discuss the stability of forward Euler method, backward Euler method, and the central difference form.
>
> **Forward Euler method**. Apply forward Euler formula to ODE $\dyx  = \lambda y$, we have
> $$
> y_{n+1} = y_n + \lambda hy_n
> $$
> The corresponding characteristic equation
> $$
> \rho(\xi) = \xi - (1 + \lambda h ) = 0
> $$
> the characteristic root $\xi = 1 + \lambda h $. When $\lambda h$ located in the unit circle centered at $(-1, 0)$, $|\xi| < 1$. Hence the Euler method is absolutely stable.
>
> **Backward Euler method**. Apply backward Euler formula $y_{n+1} = y_n + hf(x_{n+1}, y_{n+1})$ to $\dyx = \lambda y$, we have
> $$
> y_{n+1} = y_n + \lambda h y_{n+1}
> $$
> The corresponding character equation
> $$
> \rho(\xi) = (1 - \lambda h)\xi - 1 = 0
> $$
> The characteristic root $\xi = \dfrac{1}{1 - \lambda h}$, when $\mathcal{Re}(\lambda) < 0$ we have $|xi| < 1$. Hence the Euler method is absolutely stable.
>
> **Central differencce form**. Apply central difference form $y_{n+1} = y_{n-1} + 2hf(x_n, y_n)$ to $\dyx = \lambda y$, we have
> $$
> y_{n+1} = y_{n-1} + 2\lambda h y_n
> $$
> The corresponding character equation
> $$
> \rho(\xi) = \xi^2 + 2\lambda h + 1 = 0
> $$
> The characteristic root
> $$
> \xi_1 = \lambda h + \sqrt{1 + \lambda^2h^2}, \quad \xi_2 = \lambda h - \sqrt{1 + \lambda^2h^2}
> $$
> and the general solution is
> $$
> \rho_n = a\xi_1^n + b\xi_2^n
> $$
> For all $\mathcal{Re}(\lambda) < 0$ we have $|\xi_2(\lambda h)| > 1$. Hence the central difference form is not stable.




