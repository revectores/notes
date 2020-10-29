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

##### # Indicator of fitting

The distance(norm) between $\Phi(\b{x}), \by$ shall be minimum, that is $\min\norm{\Phi(\bx) - \by}$.

The norm can be defined by multiple ways:

If we use the 2-norm (square root of sum of squares) as the indicator, the gitting method is called **least squares method**:
$$
\min\sqrt{\sum_{i=1}^m(\varphi(x_i)-y_i)^2}
$$


##### # Linear Fitting

If we want to fit the data into the linear function:

$$
Q(a, b) = \sum_{i=1}^m(p(x_i)-y_i)^2 = \sum(a+bx_i-y_i)^2
$$

To achieve the minimal of $Q(a,b)$:

$$
\left\{\begin{array}{ll}
\displaystyle\pp{Q(a,b)}{a} = 0 \\
\displaystyle\pp{Q(a,b)}{b} = 0
\end{array}\right.
$$

Solve it, we have

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

> **Example**. Measure the height of a tree $m$ times, the values are $x_1, x_2, \ldots, x_m$, compute the hieght with least square error
>
> Let $x$ denote the height of tree, then the square error
> 
> $$
> R(x) = \displaystyle \sum_{i=1}^m (x-x_i)^2
> $$
> 
> The $\min R(x)$ requires
> 
> $$
> R'(x) = 2\sum_{i=1}^m(x-x_i) = 0
> $$
> 
> That is, $x = \displaystyle \frac{1}{m}\sum_{i=1}^m x_i$, which is the average of the $m$ times measurement.



##### # Square Fitting

If we want to fit the data into the quadratic function:
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



##### # Solving Overdetermined Equation

For the given data sequences $(x_i, y_i), i=1,2,\ldots, m$, if the line $p(x)=a_0+a_1x$ is required to pass through all the points, we have
$$
\begin{bmatrix}
1 & x_1 \\
1 & x_2 \\
\vdots & \vdots \\
1 & x_m \\
\end{bmatrix}
\begin{bmatrix}
a_0 \\
a_1
\end{bmatrix}
=
\begin{bmatrix}
y_1 \\
y_2 \\
\vdots \\
y_m \\
\end{bmatrix}
$$

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


We'll prove that the solution $A^{T}A\bx = A^{T}\b b$ is exactly the solution in 


$$
PA = \begin{bmatrix}
\o A_n \\
O_{m-n,n}
\end{bmatrix}
$$

$$
(PA)(PA)^{T} = \begin{bmatrix}
\o A_n \\
O_{m-n,n}
\end{bmatrix}
\begin{bmatrix}
\o A_n &
O_{m-n,n}
\end{bmatrix}
=
\begin{bmatrix}
\o A_n \o A^{T} & O \\
O & O
\end{bmatrix}
$$

and $(PA)(PA)^{T} = r(AA^T) = r(\o A {\o A}^{T}) = n$. Hence the solution of $(A^TA)\bx = A^T\bb$ must be exist and unique.

Assume the solution is $\bx$, for another value $\by = \bx + \b e$, then
$$
\begin{align}
\norm{A\by - \bb}_2^2
&= (A\bx - \bb + Ae)^T(A\bx - \bb + Ae) \\
&=  (A\bx - \bb)^T (A\bx - \bb) + 2(Ae)^T(A\bx - \bb) + (Ae)^T(Ae) \\
&= \norm{A\bx - \bb}_2^2 + \norm{Ae}_2^2 + 2e^T(A^TA\bx - A^T \bb) \\
&= \norm{A\bx - \bb}_2^2 + \norm{Ae}_2^2 \\
&\ge \norm{A\bx - \bb}_2^2
\end{align}
$$
which indicates that $\bx$ is exactly the value 

That is, it is equivalent to find the $\min\norm{A\bx-\bb}_2^2$ and solve the overdetermined equation
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
> Solve it, we have
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

