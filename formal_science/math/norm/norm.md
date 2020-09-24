# Norm

$$
\newcommand{\norm}[1]{\left\lVert#1\right\rVert}
$$

### 1. Vector Norm

##### # Definition of Matrix Norm

**Vector norm** is such a function meets

1. For any $X\in R^n, \norm{X}\ge0$, and $\norm X = 0$ iff $X=0$. (Non-negative)
2. For any $X\in R^n, \alpha\in R$, $\norm{\alpha X} = |\alpha|\norm{X}$. (Homogeneity)
3. For any $X, Y\in R^n$, $\norm{X+Y} \le \norm{X} + \norm{Y}$ (Triangle Inequality)

The common norm, $L_p$-norm of vector $X=(x_1, x_2, \ldots, x_n)^T$ is defined as
$$
\norm{X}_p = \left( \sum_{i=1}^{n}|x_i|^p \right)^{1/p}, ~~~~ 1\le p \le +\infin
$$
And the most useful includes 1-norm, 2-norm, $\infin$-norm:
$$
\begin{align}
&\norm{X}_1 = \sum_{k=1}^{n} |x_k| \\
&\norm{X}_2 = \sqrt{\sum_{k=1}^n x_k^2} \\
&\norm{X}_{\infin} = \max_{1\le k \le n}\{|x_k|\}
\end{align}
$$


##### # Relation of Different Vector Norms

For the two different norm $R_1(X), R_2(X)$ in $R^n$, there must exist $0<m<M<\infin$ for any vector
$$
mR_2(X) \le R_1(X) \le MR_2(X)
$$
or
$$
m\le \frac{R_1(X)}{R_2(X)} \le M
$$






### 2. Matrix Norm

##### # Definition of Matrix Norm

The definition of matrix norm is based on the vector norm,
$$
\norm{A}_p = \sup_{X\neq 0} \frac{\norm{AX}_p}{\norm{X}_p} = \sup_{\norm{X}_p=1} \norm{AX}_p
$$
Common norm of matrix includes 1-norm, 2-norm, $\infin$-norm and Frobenius norm:
$$
\norm{A}_1
= \sup_{X\neq 0} \frac{\norm{AX}_1}{\norm{X}_1}
= \sup_{\norm{X}_1=1} \norm{AX}_1
= \max_{1\le j \le n }\sum_{i=1}^n|a_{ij}|
$$
$\norm{A}_1$ is the max of sum of columns.
$$
\norm{A}_\infin
= \sup_{X\neq 0} \frac{\norm{AX}_\infin}{\norm{X}_\infin}
= \sup_{\norm{X}_1=\infin} \norm{AX}_\infin
= \max_{1\le i \le n }\sum_{j=1}^n|a_{ij}|
$$
$\norm{A}_\infin$ is the max of sum of rows.
$$
\norm{A}_2 = \sup_{\norm{X}_2 = 1} \norm{AX}_2 = \sqrt{\lambda_1}
$$
where $\lambda_1$ is the max characteristic value of $A^TA$.
$$
\norm{A}_F = \sqrt{\sum_{i=1}^n\sum_{j=1}^n |a_{ij}|^2}
$$
which is the square root of the square sum of all elements.



##### # Relation of Different Matrix Norms

for the characteristic value $\lambda$ we have $AX = \lambda X$, 
$$
|\lambda|\norm{X} = \norm{\lambda X} = \norm{AX} \le \norm A \norm X
$$
that is, the characteristic value of matrix is less than **any** norm of matrix.



##### # Spectral Radius

**spectral radius** $\rho(A) = \max_{1\le i \le n}\{|\lambda_i|\}$, where the $\lambda_i, 1\le i\le n$ are the characteristic value of matrix $A$.
$$
\rho(A)\le \norm{A}, \norm{A}_2=\sqrt{\rho(A^TA)}
$$




