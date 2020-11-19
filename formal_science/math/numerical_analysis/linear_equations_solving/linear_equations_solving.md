# Linear Equations Solving

$$
\newcommand{\norm}[1]{\left\lVert#1\right\rVert}
\newcommand{\b}{\boldsymbol}
\newcommand{\bx}{\b x}
\newcommand{\by}{\b y}
\newcommand{\bb}{\b b}
\newcommand{\pp}[2]{\frac{\partial #1}{\partial #2}}
\newcommand{\o}{\overline}
$$

$$
\left\{\begin{array}{ll}
a_{11}x_1 + a_{12}x_2 + \cdots + a_{1n}x_n = b_1  \\
a_{21}x_1 + a_{22}x_2 + \cdots + a_{2n}x_n = b_2  \\
\cdots \\
a_{n1}x_1 + a_{n2}x_2 + \cdots + a_{nn}x_n = b_n  \\
\end{array}\right.
$$

The matrix form $A\bx = \bb$
$$
\begin{bmatrix}
a_{11} & a_{12} &\cdots& a_{1n}  \\
a_{21} & a_{22} &\cdots& a_{2n}  \\
\vdots & \vdots &\ddots & \vdots \\
a_{n1} & a_{n2} &\cdots& a_{nn}
\end{bmatrix}
\begin{bmatrix}
x_1 \\
x_2 \\
\vdots \\
x_n
\end{bmatrix}
=
\begin{bmatrix}
b_1 \\
b_2 \\
\vdots \\
b_n \\
\end{bmatrix}
$$

$$
x_i = \frac{D_i}{D}, \quad i = 1, 2, \ldots, n
$$



For the diagonal equations
$$
\begin{bmatrix}
a_{11}    \\
& a_{22}  \\
&& \ddots \\
&&& a_{nn}
\end{bmatrix}
\begin{bmatrix}
x_1 \\
x_2 \\
\vdots \\
x_n
\end{bmatrix}
=
\begin{bmatrix}
b_1 \\
b_2 \\
\vdots \\
b_n \\
\end{bmatrix}
$$

$$
x_i = \frac{b_i}{a_{ii}}, \quad i = 1, 2, \ldots, n
$$

the time complexity is $O(n)$.

For the triangle equations
$$
\begin{bmatrix}
a_{11} \\
a_{21} & a_{22}  \\
\vdots & \vdots &\ddots \\
a_{n1} & a_{n2} &\cdots& a_{nn}
\end{bmatrix}
\begin{bmatrix}
x_1 \\
x_2 \\
\vdots \\
x_n
\end{bmatrix}
=
\begin{bmatrix}
b_1 \\
b_2 \\
\vdots \\
b_n \\
\end{bmatrix}
$$
The solution can be achieved from the following steps:

> Steps.
>
> (1) Solve the first equation, we have $x_1 = \dfrac{b_1}{l_{11}}$.
>
> (2) Substitute $x_1$ into the second equation, we have $x_2 = \dfrac{b_2 - l_{21}x_1}{l_{22}}$
>
> ......
>
> ($i$) Substitute $x_1, x_2, \ldots, x_{i-1}$ into $i$-th equation, we have
> $$
> x_i = \dfrac{ b_i - \displaystyle \sum_{j=1}^{i-1}l_{ij}x_j }{l_{ii}}
> $$
> ......



The time complexity is $O(n^2)$.



##### # solvability

The Gauss elimination requires
$$
\Delta_k =
\begin{bmatrix}
a_{11} & a_{12} &\cdots& a_{1k}  \\
a_{21} & a_{22} &\cdots& a_{2k}  \\
\vdots & \vdots &\ddots & \vdots \\
a_{k1} & a_{k2} &\cdots& a_{kk}
\end{bmatrix}
\neq 0
$$
for any $k<n$.

If $a_{kk}^{(k-1)}$ is small, the round-off error increases if some of the coffieients are small. 





##### # Gauss-Jordan Elimination









### 2. Direct Matrix Decomposition

##### # Linear Transformation and Matrix Decomposition

$$
TA = U
$$

Multiple $L = T^{-1}$ on both sides:
$$
A = LU
$$
with
$$
L = T^{-1} =
\begin{bmatrix}
1 \\
l_{21} & 1  \\
\vdots & \vdots &\ddots \\
l_{n1} & l_{n2} & \cdots & 1
\end{bmatrix}
$$
That is, we devide the matrix $A$ into the multiplication of two matrixes $L$, $U$. where $L$ and $U$ are lower and upper triangular matrix respectively. Equivalently, we can also decompose by $A=UL$.

For form $A=LU$, if $L$ is contrainted as the unit lower triangle matrix, this is called **Doolittle decomposition**, while for form $A = UL$, and the $U$ is contrainted as the unit upper

This composition process is not relavent to $\bb$, hence if there are multiple equations with same $A$ but different $\bb$, the composition method reduce the time complexity by cancelling the repetative processing of $A$.


$$
A = \begin{bmatrix}
a_{11} & a_{12} &\cdots& a_{1n}  \\
a_{21} & a_{22} &\cdots& a_{2n}  \\
\vdots & \vdots &\ddots & \vdots \\
a_{n1} & a_{n2} &\cdots& a_{nn}
\end{bmatrix}
=
\begin{bmatrix}
1 \\
l_{21} & 1  \\
\vdots & \vdots &\ddots \\
l_{n1} & l_{n2} & \cdots & 1
\end{bmatrix}
\begin{bmatrix}
u_{11} & u_{12} &\cdots & u_{1n}  \\
       & u_{22} &\cdots & u_{2n}  \\
	   &        &\ddots & \vdots \\
       &        &       & u_{nn}
\end{bmatrix}
$$

$$
a_{11} = \sum_{r=1}^n l_{1r}u_{r1} =
\begin{bmatrix}
1 & 0 & \cdots & 0 \\
\end{bmatrix}
\begin{bmatrix}
u_{11} \\
0 \\
\vdots \\
0
\end{bmatrix}
= \sum_{r=1}^1 l_{1r}u_{r1} = u_{11}
$$

$$
a_{1j} = \sum_{r=1}^n l_{1r}u_{rj} =
\begin{bmatrix}
1 & 0 & \cdots & 0 \\
\end{bmatrix}
\begin{bmatrix}
u_{1j} \\
u_{2j} \\
\vdots \\
0
\end{bmatrix}
= \sum_{r=1}^1 l_{1r}u_{rj} = u_{1j}
$$
Hence $a_{ij} = u_{1j}$, $j=1,2, \dots, n$.


$$
\begin{align}
a_{kj}
&= \sum_{r=1}^n l_{kr}u_{rj} =
\begin{bmatrix}
l_{k1} & l_{k2} & \cdots & l_{k,k-1} & 1 & 0 & \cdots & 0 \\
\end{bmatrix}
\begin{bmatrix}
u_{1j} \\
\vdots \\
u_{jj} \\
0 \\
\vdots \\
0
\end{bmatrix} \\
&= \sum_{r=1}^n l_{kr}u_{rj}
= \sum_{r=1}^{k-1} l_{kr}u_{rj} + u_{kj}
\end{align}
$$




For Crout decomposition,







##### # Decomposition of Positiv Definite Matrix

For the positive definitive matrix, there exists lower triangle matrix $U$ which satisifies $A = UU^T$, this is called the square root method, since this computation process involves the computation about square root, in practice we often decompose as form $A = LDL^T$ instaed.



We first apply Doolittle decomposition to matrix and extract the diagonal line of $U$:
$$
\begin{align}
A = LU
&= \begin{bmatrix}
1 \\
l_{21} & 1  \\
\vdots & \vdots &\ddots \\
l_{n1} & l_{n2} & \cdots & 1
\end{bmatrix}
\begin{bmatrix}
u_{11} & u_{12} &\cdots & u_{1n}  \\
       & u_{22} &\cdots & u_{2n}  \\
	   &        &\ddots & \vdots \\
       &        &       & u_{nn}
\end{bmatrix} \\
&=
\begin{bmatrix}
1 \\
l_{21} & 1  \\
\vdots & \vdots &\ddots \\
l_{n1} & l_{n2} & \cdots & 1
\end{bmatrix}
\begin{bmatrix}
u_{11} & 		&  		&  \\
       & u_{22} &		& \\
	   &        &\ddots & \\
       &        &       & u_{nn}
\end{bmatrix}
\begin{bmatrix}
\o u_{11} & \o u_{12} &\cdots & \o u_{1n}  \\
       & \o u_{22} &\cdots & \o u_{2n}  \\
	   &        &\ddots & \vdots \\
       &        &       & \o u_{nn}
\end{bmatrix}
\end{align}
$$
 Since $A$ is symmetric positive definite matrix, we have $u_{ii}>0$. We can prove $L = \o U$ since
$$
A = LU = LD\o U^T = A^T = \o U(DL^T)
$$
That is, 
$$
\begin{align}
A = LDL^T
= \begin{bmatrix}
1 \\
l_{21} & 1  \\
\vdots & \vdots &\ddots \\
l_{n1} & l_{n2} & \cdots & 1
\end{bmatrix}
\begin{bmatrix}
u_{11} & 		&  		&  \\
       & u_{22} &		& \\
	   &        &\ddots & \\
       &        &       & u_{nn}
\end{bmatrix}
\begin{bmatrix}
1 	   & l_{21} &\cdots & l_{n1}  \\
       & 1 		&\cdots & l_{n2}  \\
	   &        &\ddots & \vdots \\
       &        &       & 1
\end{bmatrix}
\end{align}
$$

Now we have to apply three steps:

1) Solve $LZ = B$, where $Z = DL^TX$
$$
z_i = b_i - \sum_{k=1}^{i-1}l_{ij}z_j, \quad i = 1, 2, \ldots, n
$$

$$
y_i = 
$$



> **Example**. Solve the equation
> $$
> \begin{bmatrix}
> 1 & -1 & 1 \\
> -1 & 3 & -2 \\
> 1 & -2 & 4.5
> \end{bmatrix}
> \begin{bmatrix}
> x_1 \\
> x_2 \\
> x_3
> \end{bmatrix}
> =
> \begin{bmatrix}
> 4 \\
> -8 \\
> 12
> \end{bmatrix}
> $$
> by $LDL^T$ decomposition.
>
> 



##### # Condition Number of Matrix

For the non-singular matrix $A$, we define
$$
\kappa_p(A) = \norm{A}_p \norm{A^{-1}}_p
$$
as the **condition number** of matrix $A$. Although there are multiple norm numbers 
$$
\frac{\norm {\delta x}}{\norm x} \le \frac{\kappa_A \dfrac{\norm{\delta A}}{\norm A}}{1 - \kappa_A\dfrac{\norm{\delta A}}{\norm A}}
$$
We call the matrix with large $\kappa_A$ ill-conditioned, that is, the small error causes the solution 








