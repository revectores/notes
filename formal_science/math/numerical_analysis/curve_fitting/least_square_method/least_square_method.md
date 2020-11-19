# Least Squares Method

$$
\newcommand{\norm}[1]{\left\lVert#1\right\rVert}
\newcommand{\b}{\boldsymbol}
\newcommand{\bx}{\b x}
\newcommand{\by}{\b y}
\newcommand{\bb}{\b b}
\newcommand{\pp}[2]{\frac{\partial #1}{\partial #2}}
\newcommand{\o}{\overline}
$$

##### # Curve Fitting

Interpolation and fitting are two methods that utilizing known points to approximate the unknown function. If it is not possible to make all the points pass the given form of function, we can at least find that function with best approximation under some **indicator**.

Normally, the target is defined to minimize the distance(norm) between $\Phi(\b{x})$ and $\by$, that is, find $\displaystyle\text{argmin}_{f(x)\in \Phi(x)}\norm{\Phi(\bx) - \by}$.

If we use 1-norm, the indicator is
$$
R_1 = \sum_{i=1}^m |\varphi(x_i) - y_i|
$$
If we use infinite-norm, the indicator is
$$
R_{\infin} =  \max_{1\le i\le m}|\varphi(x_i) - y_i|
$$
If we use 2-norm, the indicator is
$$
R_2 = \sqrt{\sum_{i=1}^m (\varphi(x_i) - y_i)^2}
$$
To minimize $R_2$, it is equivalent to minimize the square of it:
$$
R = \sum_{i=1}^m (\varphi(x_i) - y_i)^2
$$
Method use $R$ as the indicator to implement curve fitting is **least squares method**.




##### # Fitting Linear Function

If we want to fit points into linear function:

$$
Q(a, b) = \sum_{i=1}^m(p(x_i)-y_i)^2 = \sum_{i=1}^m(a+bx_i-y_i)^2
$$

To achieve the minimal of $Q(a,b)$:

$$
\left\{\begin{array}{ll}
\displaystyle\pp{Q(a,b)}{a} = 0 \\
\displaystyle\pp{Q(a,b)}{b} = 0
\end{array}\right.
$$

Solve these equations, we have

$$
\left\{\begin{array}{ll}
\displaystyle a
= \frac{D_1}{D}
= \frac{1}{D}
\begin{vmatrix}
\displaystyle \sum_{i=1}^m y_i & \displaystyle \sum_{i=1}^mx_i \\
\displaystyle \sum_{i=1}^m x_iy_i & \displaystyle \sum_{i=1}^mx_i^2 \\
\end{vmatrix}
\\
\displaystyle b
= \frac{D_2}{D}
= \frac{1}{D}
\begin{vmatrix}
m & \displaystyle \sum_{i=1}^my_i \\
\displaystyle \sum_{i=1}^m x_i & \displaystyle \sum_{i=1}^mx_iy_i \\
\end{vmatrix}
\end{array}\right.
$$

> **Example**. Measure the height of a tree $m$ times, those approximate values are $x_1, x_2, \ldots, x_m$, compute the height of the tree with least square error.
>
> Let $x$ denote the height of tree, then the square error
> 
> $$
> R(x) = \displaystyle \sum_{i=1}^m (x-x_i)^2
> $$
> 
> To minimize $R(x)$,
> 
> $$
> R'(x) = 2\sum_{i=1}^m(x-x_i) = 0
> $$
> 
> That is, $x = \displaystyle \frac{1}{m}\sum_{i=1}^m x_i$, which is the average of the measurements.



##### # Fitting Quadratic Function

If we want to fit points into quadratic function:
$$
Q(a_0, a_1, a_2)
= \sum_{i=1}^m (p(x_i) - y_i)^2
= \sum_{i=1}^m (a_0 + a_1x_i + a_2x_i^2 - y_i)^2
$$

To achieve the minimal of $Q(a,b)$:

$$
\left\{\begin{array}{ll}
\displaystyle\pp{Q(a_0, a_1, a_2)}{a_0} = 0 \\
\displaystyle\pp{Q(a_0, a_1, a_2)}{a_1} = 0 \\
\displaystyle\pp{Q(a_0, a_1, a_2)}{a_2} = 0 \\
\end{array}\right.
$$

The normal equations:
$$
\begin{bmatrix}
m & \displaystyle \sum_{i=1}^m x_i & \displaystyle \sum_{i=1}^m x_i^2 \\
\displaystyle \sum_{i=1}^m x_i & \displaystyle \sum_{i=1}^m x_i^2 & \displaystyle \sum_{i=1}^m x_i^3 \\
\displaystyle \sum_{i=1}^m x_i^2 & \displaystyle \sum_{i=1}^m x_i^3 & \displaystyle \sum_{i=1}^m x_i^4 \\
\end{bmatrix}
\begin{bmatrix}
a_0 \\ a_1 \\ a_2
\end{bmatrix}
=
\begin{bmatrix}
\displaystyle \sum_{i=1}^m y_i \\
\displaystyle \sum_{i=1}^m x_iy_i \\
\displaystyle \sum_{i=1}^m x_i^2y_i
\end{bmatrix}
$$

> Example. Fit the following data into curve $f(x) = a + bx^2$:
>
> | $x_i$ | $2$  | $3$  | $5$  | $7$  | $8$  |
> | :---: | :--: | ---- | ---- | ---- | ---- |
> | $y_i$ | $1$  | $6$  | $22$ | $46$ | $61$ |
>
> 



##### # Solving Overdetermined Equations

For overdetermined equation $A\bx = \bb$
$$
\begin{bmatrix}
a_{11} & a_{12} &\cdots& a_{1n}  \\
a_{21} & a_{22} &\cdots& a_{2n}  \\
\vdots & \vdots &\ddots & \vdots \\
a_{m1} & a_{m2} &\cdots& a_{mn}
\end{bmatrix}
\begin{bmatrix}
x_1 \\
x_2 \\
\vdots \\
x_n
\end{bmatrix}
=
\begin{bmatrix}
y_1 \\
y_2 \\
\vdots \\
y_m \\
\end{bmatrix}
$$

with $r(A, \bb)\neq r(A)$, there is no solution, and this equation is **contradictory** or **overdetermined**. Although it is not possible to give a solution that meets all the conditions, we can still give a best solution under particular indicator. Minimizing the sum of square of errors is the most common target.

We'll prove that, the solution of normal equation $A^{T}A\bx = A^{T}\b b$ is exactly the solution which minimize sum of square of errors $R = \displaystyle \sum_{i=1}^m (y_i - y'_i)^2$.

> **Proof**. **Existence**. Apply primary transformation $P$ to $A$:
> $$
> PA = \begin{bmatrix}
> \o A_n \\
> O_{m-n,n}
> \end{bmatrix}
> $$
> then
> $$
> (PA)(PA)^{T} = \begin{bmatrix}
> \o A_n \\
> O_{m-n,n}
> \end{bmatrix}
> \begin{bmatrix}
> \o A_n &
> O_{m-n,n}
> \end{bmatrix}
> =
> \begin{bmatrix}
> \o A_n \o A^{T} & O \\
> O & O
> \end{bmatrix}
> $$
>
> $$
> r((PA)(PA)^T) = r(AA^T) = r(\o A\o A^T) = n
> $$
>
> which indicates that there is unique solution of equation $(A^TA)\bx = A^T\bb$.
>
> **Uniqueness**. Denote the solution as $\bx$, to that $\bx$ minimizes the 2-norm, consider another value $\by = \bx + \b e$, then
> $$
> \begin{align}
> \norm{A\by - \bb}_2^2
> &= (A\bx - \bb + Ae)^T(A\bx - \bb + Ae) \\
> &=  (A\bx - \bb)^T (A\bx - \bb) + 2(Ae)^T(A\bx - \bb) + (Ae)^T(Ae) \\
> &= \norm{A\bx - \bb}_2^2 + \norm{Ae}_2^2 + 2e^T(A^TA\bx - A^T \bb) \\
> &= \norm{A\bx - \bb}_2^2 + \norm{Ae}_2^2 \\
> &\ge \norm{A\bx - \bb}_2^2
> \end{align}
> $$
> which indicates that $\bx$ is exactly the value that minimize the 2-norm.
>

That is, it is equivalent to:

- Find $\min\norm{A\bx-\bb}_2^2$
- Solve overdetermined equation $A\bx = \bb$ by normal equation $A^{T}A\bx = A^{T}\b b$.


> **Example**. Construct the quadratic function from following data
>
> |  $x_i$   |   $4.0$   |   $5.2$   |   $6.1$   |   $7.3$   |   $8.6$   |
> | :------: | :-------: | :-------: | :-------: | :-------: | :-------: |
> | $f(x_i)$ | $2.64117$ | $7.21784$ | $9.83745$ | $10.9943$ | $12.0859$ |
>
> **Solution**. Let $\varphi(x) = a_0 + a_1x + a_2x^2$, we have the overdetermined equation $A\alpha = \by$
> $$
> \begin{bmatrix}
> 1 & x_1 & x_1^2 \\
> 1 & x_2 & x_2^2 \\
> \vdots & \vdots & \vdots \\
> 1 & x_5 & x_5^2
> \end{bmatrix}
> \begin{bmatrix}
> a_0 \\
> a_1 \\
> a_2
> \end{bmatrix}
> =
> \begin{bmatrix}
> y_1 \\
> y_2 \\
> \vdots \\
> y_5
> \end{bmatrix}
> $$
> The normal equations
> $$
> \begin{bmatrix}
> 1 & 1 & \cdots & 1   \\
> x_1 & x_2 & \cdots & x_5   \\
> x_1^2 & x_2^2 & \cdots & x_5^2   \\
> \end{bmatrix}
> \begin{bmatrix}
> 1 & x_1 & x_1^2 \\
> 1 & x_2 & x_2^2 \\
> \vdots & \vdots & \vdots \\
> 1 & x_5 & x_5^2
> \end{bmatrix}
> \begin{bmatrix}
> a_0 \\
> a_1 \\
> a_2
> \end{bmatrix}
> =
> \begin{bmatrix}
> 1 & 1 & \cdots & 1 \\
> x_1 & x_2& \cdots & x_5 \\
> x_1^2 & x_2^2 & \cdots & x_5^2 \\
> \end{bmatrix}
> \begin{bmatrix}
> y_1 \\
> y_2 \\
> \vdots \\
> y_5
> \end{bmatrix}
> $$
> That is,
> $$
> \begin{bmatrix}
> 5 & \displaystyle \sum_{i=1}^5 x_i & \displaystyle \sum_{i=1}^5 x_i^2 \\
> \displaystyle \sum_{i=1}^5 x_i & \displaystyle \sum_{i=1}^5 x_i^2 & \displaystyle \sum_{i=1}^5 x_i^3 \\
> \displaystyle \sum_{i=1}^5 x_i^2 & \displaystyle \sum_{i=1}^5 x_i^3 & \displaystyle \sum_{i=1}^5 x_i^4 \\
> \end{bmatrix}
> \begin{bmatrix}
> a_0 \\ a_1 \\ a_2
> \end{bmatrix}
> =
> \begin{bmatrix}
> \displaystyle \sum_{i=1}^5 y_i \\
> \displaystyle \sum_{i=1}^5 x_iy_i \\
> \displaystyle \sum_{i=1}^5 x_i^2y_i
> \end{bmatrix}
> $$
> Solve this, we get
> $$
> \varphi(x) = -22.2394 + 8.21909x - 0.493794x^2
> $$

> **Example**. Fit the data into form $a+bx^2$.
>
> | $x_i$ | $2$  | $3$  | $5$  | $7$  | $8$  |
> | :---: | :--: | :--: | :--: | :--: | :--: |
> | $y_i$ | $1$  | $6$  | $22$ | $46$ | $61$ |
>
>  Let $\varphi(x) = a + bx^2$, we have the overdetermined equation $A\alpha = \by$
> $$
> \begin{bmatrix}
> 1 & x_1^2 \\
> 1 & x_2^2 \\
> \vdots & \vdots \\
> 1 & x_5^2
> \end{bmatrix}
> \begin{bmatrix}
> a \\
> b \\
> \end{bmatrix}
> =
> \begin{bmatrix}
> y_1 \\
> y_2 \\
> \vdots \\
> y_5
> \end{bmatrix}
> $$
> The normal equation
> $$
> \begin{bmatrix}
> 1 & 1 & \cdots & 1 \\
> x_1^2 & x_2^2& \cdots & x_5^2 \\
> \end{bmatrix}
> \begin{bmatrix}
> 1 & x_1^2 \\
> 1 & x_2^2 \\
> \vdots & \vdots \\
> 1 & x_5^2
> \end{bmatrix}
> \begin{bmatrix}
> a \\
> b \\
> \end{bmatrix}
> =
> \begin{bmatrix}
> 1 & 1 & \cdots & 1 \\
> x_1^2 & x_2^2& \cdots & x_5^2 \\
> \end{bmatrix}
> \begin{bmatrix}
> y_1 \\
> y_2 \\
> \vdots \\
> y_5
> \end{bmatrix}
> $$
> That is,
> $$
> \begin{bmatrix}
> 5 & \displaystyle \sum_{i=1}^5 x_i^2 \\
> \displaystyle \sum_{i=1}^5 x_i^2 & \displaystyle \sum_{i=1}^5 x_i^4 \\
> \end{bmatrix}
> \begin{bmatrix}
> a \\
> b
> \end{bmatrix}
> =
> \begin{bmatrix}
> \displaystyle \sum_{i=1}^5 y_i \\
> \displaystyle \sum_{i=1}^5 x_i^2y_i
> \end{bmatrix}
> $$
> Hence $\varphi(x) = -3 + x^2$.

