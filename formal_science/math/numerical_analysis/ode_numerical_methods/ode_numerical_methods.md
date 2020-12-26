# Numerical Methods for Ordinary Differential Equation

$$
\newcommand{\d}{\text d}
\newcommand{\dx}{\d x}
\newcommand{\dy}{\d y}
\newcommand{\dt}{\d t}
\newcommand{\dd}[2]{\dfrac{\d #1}{\d #2}}
\newcommand{\dyx}{\dd{y}{x}}
$$

Forward Euler method:
$$
y_{n+1} = y_n + hf(x_n, y_n)
$$
Backward Euler method:
$$
y_{n+1} = y_n + hf(x_{n+1}, y_{n+1})
$$

$$
y_{n+1} = y_n + \frac{h}{2}(f(x_n, y_n) + f(x_{n+1}, y_{n+1}))
$$

$$
\left\{\begin{array}{ll}
\overline{y}_{n+1} = y_n + hf(x_n, y_n) \\
y_{n+1} = y_n + \dfrac{h}{2}(f(x_n, y_n) + f(x_{n+1}, \overline{y}_{n+1}))
\end{array}\right.
\quad
$$


Expand the $y(x+h)$ by Taylor formula at point $x$:
$$
y(x+h) = y(x) + hy'(x) + \frac{h^2}{2!}y''(x) + \cdots +
$$
For $p = 1$, we have
$$
y(x_{n+1}) = y(x_n) + hf(x_n, y(x_n))
$$
For $p=2$, we have
$$
y(x_{n+1})
= y(x_n) + hy'(x_n) + \frac{h^2}{2!}y''(x_n)
$$
where
$$
y''(x_n) = f_x(x_n, y(x_n)) + f_y(x_n, y(x_n))f(x_n, y(x_n))
$$
to avoid the computation of partial derivatives, we try to use the linear combination of $$



We have
$$
\left\{\begin{array}{ll}
c_1 + c_1 = 1 \\
2c_2a = 1 \\
2c_2b = 1
\end{array}\right.
$$
Let $c_1 = \dfrac{1}{2}, c_2 = \dfrac{1}{2}, a = 1, b =1$, we get a familiar form of 2nd order Runge-Kutta formula:
$$
\left\{\begin{array}{ll}
y_{n+1} = y_n + \dfrac{h}{2}(k_1 + k_2) \\
k_1 = f(x_n, y_n) \\
k_2 = f(x_n + h, y_n + hf(x_n, y_n))
\end{array}\right.
$$
which form is the same as the refined Euler formula.

Another coffecients combination $c_1 = 0, c_2 = 0, a = \dfrac{1}{2}, b = \dfrac{1}{2}$ is called the middle point formula:

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


4th-order
$$
\left\{\begin{array}{ll}
y_{n+1} = y_n + \dfrac{h}{6}(k_1 + 2k_2 + 2k_3 + k_4) \\
k_1 = f(x_n, y_n) \\
k_2 = f\left(x_n + \dfrac{1}{2}h, y_n + \dfrac{1}{2}hk_1\right) \\
k_3 = f\left(x_n + \dfrac{1}{2}h, y_n + \dfrac{1}{2}hk_2\right) \\
k_4 = f(x_n + h, y_n + hk_3)
\end{array}\right.
$$




### 3. Linear Multistep Method

The initial problem $\dyx = f(x, y)$ is equivalent to the integral
$$
y(x) = y(x^*) + \int_{x^*}^x y'(t)\dt
$$

$$
y(x_{n+1}) = y(x_{n-p}) + \int_{x_{n-p}}^{x_{n+1}}y'(t)\dt
$$


Use points $x_n, x_{n-1}, \ldots, x_{n-q}$ to construct the interpolation formula to approximate $y'(x)$, we have the **explicit formula** of linear multistep method.

Use points $x_{n+1}, x_n, \ldots, x_{n+1-q}$ to construct the interpolation formula to approximate $y'(x)$, we have the **implicit formula** of linear multistep method.



Let $p=0, q = 0$ in explicit form, we have the 1st-order explicit Adams formula
$$
y(x_{n+1}) = y(x_n) + \int_{x_n}^{x_{n+1}}y'(t)\dt
$$
Let $p = 0, q = 1$ in explicit form, we have the 2nd-order explicit Adams formula
$$
y_{n+1} = y_n + \frac{h}{2}[3f(x_n, y_n) - f(x_{n-1}, y_{n-1})]
$$
Let $p=0, q = 2$ in explicit form, we have the 3rd-order explicit Adams formula
$$
y_{n+1} = y_n + \frac{h}{12}(23f(x_n, y_n) - 16f(x_{n-1}, y_{n-1}) + 5f(x_{n-2}, y_{n-2}))
$$


Let $p = 1, q = 2$ in explicit form, we have
$$
y_{n+1} = y_{n-1} + \frac{h}{3}[7f(x_n, y_n) - 2f(x_{n-1}, y_{n-1}) + f(x_{n-2}, y_{n-2})]
$$
The truncation error $R(x)$
$$
R(x) = \frac{1}{6}\int_{x_{n-1}}^{x_{n+1}} y^{(4)}(\eta(x))(x - x_n)(x - x_{n-1})(x - x_{n-2})\dx
$$





The iteration steps are required for the implicit form.

The 2nd-order implicit Adams formula is the trapz formula
$$
y_{n+1} = y_n + \frac{h}{2}(f(x_n, y_n) + f(x_{n+1}, y_{n+1}))
$$
The 4-order implicit Adams formula is
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
All the methods of single ODE can be applied to the vector form directly.



Applying forward Euler formula to $\dyx  = \lambda y$, we have
$$
y_{n+1} = y_n + \lambda hy_n
$$
The corresponding characteristic equation
$$
\rho(\xi) = \xi - (1 + \lambda h ) = 0
$$
the characteristic root $\xi = 1 + \lambda h $. When $\lambda h$ located in the unit circle centered at $(-1, 0)$, $|\xi| < 1$, hence the Euler method is absolute stable.

Applying backward Euler formula $y_{n+1} = y_n + hf(x_{n+1}, y_{n+1})$ to $\dyx = \lambda y$, we have
$$
y_{n+1} = y_n + \lambda h y_{n+1}
$$
The corresponding character equation
$$
\rho(\xi) = (1 - \lambda h)\xi - 1 = 0
$$
The characteristic root $\xi = \dfrac{1}{1 - \lambda h}$, when $\Re()$










