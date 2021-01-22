# Eigenvalues and Eigenvectors

$$
\newcommand{\norm}[1]{\left\lVert#1\right\rVert}
\newcommand{\infnorm}[1]{\norm{#1}_{\infty}}
\newcommand{\b}{\boldsymbol}
\newcommand{\bx}{\b x}
\newcommand{\by}{\b y}
\newcommand{\bb}{\b b}
\newcommand{\bg}{\b g}
\newcommand{\bv}{\b v}
\newcommand{\w}{\widetilde}
\newcommand{\pp}[2]{\frac{\partial #1}{\partial #2}}
\newcommand{\o}{\overline}
$$

### 1. Introduction

Recall that for matix $A$, if $A\bv = \lambda \bv$, we define $\lambda$ is the **eigenvalue** and $\bv$ is the corresponding **eigenvector** of $A$.

To compute the eigenvalues and eigenvectors by definition, we need to solve equation $|\lambda I - A| = 0$ with order $n$, where $n$ is the order of matrix. For instance, to compute the eigenvalue of $A = \begin{bmatrix}
0 & 1 \\
1 & 1
\end{bmatrix}$, we must solve the euqation
$$
\begin{vmatrix}
\lambda & 1 \\
1 & \lambda - 1
\end{vmatrix} = \lambda(\lambda-1) - 1 = 0
$$
However, [Abel–Ruffini theorem](https://en.wikipedia.org/wiki/Abel%E2%80%93Ruffini_theorem) states that there is no solution in radicals to general polynomial equations of degree five or higher with arbitrary coefficients. Hence computing the eigenvalue/eigenvector by definition is not an universal approach.

The **dominant eigenvalue**, or **largest magnitude eigenvalue** of $A$ is an eigenvalue $\lambda$ whose magnitude is greater than all other eigenvalues. If it exists, an eigenvector associated to $\lambda$ is called a **dominant eigenvector**.

The dominant eigenvalues is much more significant than others in many practical problems. For instance, whether the iteration matrix convergence when  solving linear equations by applying iteration method depends on the spectral radius (a.k.a. dominant eigenvalue) of matix.

**Power method** is one of the numerical technique to compute dominant eigenvalue, and based on which we developed inverse power method to compute smallest magnitude eigenvalue.







### 2. Power Method

##### # Power Method Introduction

Any vector $X^{(0)}$ (as the initial vector) can be expressed by $n$ linear independent eigenvector of $A$
$$
X^{(0)} = \alpha_1\bv_1 + \alpha_2 \bv_2 + \cdots + \alpha_n \bv_n
$$

And the multiplication $AX^{(0)}$ can be expressed by
$$
\begin{align}
X^{(1)}
&= AX^{(0)} \\
&= A(\alpha_1 \bv_1 + \alpha_2 \bv_2 + \cdots + \alpha_n \bv_n) \\
&= A\alpha_1 \bv_1 + A\alpha_2 \bv_2 + \cdots + A\alpha_n \bv_n \\
&= \lambda_1\alpha_1 \bv_1 + \lambda_2\alpha_2 \bv_2 + \cdots + \lambda_n\alpha_n \bv_n
\end{align}
$$

Applying mathematical induction, we have
$$
X^{(k)}
= AX^{(k-1)}
= \lambda_1^k\alpha_1 \bv_1 + \lambda_2^k\alpha_2 \bv_2 + \cdots + \lambda_n^k\alpha_n \bv_n
$$
This expression indicates that how $X^{(k)}$ change when iterating depends on the distribution of eigenvalues. We'll discuss two simple cases when applying the iteration.



##### # Two Cases when Applying Power Method

**Case 1**. If the ratio $\dfrac{x^{(k+1)}}{x^{(k)}}$ converges, the largest magnitude eigenvalue is unique and is a simple root. The dominant eigenvalue and the dominant eigenvector can be computed by
$$
\left\{\begin{array}{ll}
\lambda_1 \approx \dfrac{x_i^{(k+1)}}{x_i^{(k)}}, \quad i = 1, 2, \ldots, n \\
\bv_1 \approx X^{(k)}
\end{array}\right.
$$

> **Proof**. For the unique dominant eigenvalue $\lambda_1$,
> $$
> \begin{align}
> X^{(k)}
> &= \lambda_1^k\alpha_1 \bv_1 + \lambda_2^k\alpha_2 \bv_2 + \cdots + \lambda_n^k\alpha_n \bv_n \\
> &= \lambda_1^k\left[ \lambda_1^k\alpha_1 \bv_1 + \left(\frac{\lambda_2}{\lambda_1}\right)^k\alpha_2 \bv_2 + \cdots + \left(\frac{\lambda_n}{\lambda_1}\right)^k\alpha_n \bv_n \right]
> \end{align}
> $$
> For sufficiently large $k$, we have $\left| \left( \dfrac{\lambda_i}{\lambda_1} \right)^k \right| \rightarrow 0$ for $i \neq 1$ since $\lambda_1$ is the dominant eigenvalue. Hence
> $$
> \begin{align}
> X^{(k)}   &\approx \lambda_1^k\alpha_1\bv_1 \\
> X^{(k+1)} &\approx \lambda_1^{k+1}\alpha_1\bv_1 = \lambda_1 \lambda^k\alpha_1\bv_1 = \lambda_1X^{(k)}
> \end{align}
> $$

**Case 2**. If the ratio $\dfrac{x^{(k+1)}}{x^{(k)}}$ does not converges but $\dfrac{x^{(2k+2)}}{x^{(2k)}}$ does, then dominant eigenvalues are the real roots with different signs. The dominant eigenvalue and eigenvector can be computed by
$$
\left\{\begin{array}{ll}
\lambda_1 = \sqrt{\dfrac{x_1^{(k+2)}}{x_i^{(k)}}}, \quad i = 1, 2, \ldots, n \\
\bv_1 = X^{(k+1)} + \lambda_1 X^{(k)} \\
\bv_2 = X^{(k+1)} - \lambda_1 X^{(k)}
\end{array}\right.
$$

> **Proof**. For two dominant eigenvalues $\lambda_1, \lambda_2$ and $\lambda_1 = -\lambda_2$
> $$
> \begin{align}
> X^{(k)}
> &= \lambda_1^k\alpha_1 \bv_1 + \lambda_2^k\alpha_2 \bv_2 + \cdots + \lambda_n^k\alpha_n \bv_n \\
> &=
> \lambda_1^k\left[ \lambda_1^k\alpha_1 \bv_1
> + (-1)^k\alpha_2 \bv_2
> + \left(\frac{\lambda_3}{\lambda_1}\right)^k\alpha_3 \bv_n
> + \cdots
> + \left(\frac{\lambda_n}{\lambda_1}\right)^k\alpha_n \bv_n \right]
> \end{align}
> $$
> For sufficiently large $k$, we have
> $$
> \begin{align}
> X^{(k)} &\approx \lambda_1^k(\alpha_1\bv_1 + (-1)^k\alpha_2\bv_2) \\
> X^{(k+1)} &\approx \lambda_1^{k+1}(\alpha_1\bv_1 + (-1)^{k+1}\alpha_2\bv_2) \\
> X^{(k+2)} &\approx \lambda_1^{k+2}(\alpha_1\bv_1 + (-1)^{k+2}\alpha_2\bv_2) \\
> \end{align}
> $$

Those trends that do not fit the two cases above require other methods.



##### # Normalized Computation of Power Method

If the dominant eigenvalue is larger or smaller than $1$, some components of $X^{(k)}$ will increase or decrease continuously when iterating, which leads to the precision problem due to [IEEE754](). Hence we apply normalization after each step:
$$
Y_0 = \frac{X^{(0)}}{\infnorm{X^{(0)}}} \\
\left\{\begin{array}{ll}
X^{(k+1)} = AY^{(k)} \\
Y^{(k+1)} = \dfrac{X^{(k+1)}}{\infnorm{X^{(k+1)}}}
\end{array}\right.
$$
The normalization process gurantees $\norm{Y^{(k)}}_\infty = 1$, that is, the component that represents dominant eigenvalue of $A$ will remain $\pm1$.

There are three cases for normalized power method:

(1) If $\{X^{k}\}$ converges, then there is unique **positive** dominant eigenvalues of $A$
$$
\left\{\begin{array}{ll}
\displaystyle \lambda_1 \approx \max_{1\le i \le n} |x_i^{(k)}| = |x_j^{(k)}| \\
\bv_1 \approx Y^{(k)}
\end{array}\right.
$$

(2) If $\{X^{(2k)}\}, \{X^{(2k+1)}\}$ converges to vectors with different signs, there is unique **negative** dominant eigenvalues of $A$
$$
\left\{\begin{array}{ll}
\displaystyle \lambda_1 \approx - \max_{1\le i \le n} |x_i^{(k)}| = - |x_j^{(k)}| \\
\bv_1 \approx Y^{(k)}
\end{array}\right.
$$
(3) If ${\{X^{(2k)}\}, \{X^{(2k+1)}\}}$ converges to two different vectors, there are two different dominant eigenvectors with inversed sign. For sufficiently large $k$, we exectue one more **unnormalized** operation $X^{(k+1)} = AX^{(k)} = A^2Y^{(k-1)}$, then
$$
\left\{\begin{array}{ll}
\lambda_1 \approx \displaystyle\sqrt{\frac{x_i^{(k+1)}}{y_i^{(k-1)}}} \\
\lambda_2 = -\lambda_1 \\
\bv_1 = X^{(k+1)} + \lambda_1 X^{(k)} \\
\bv_2 = X^{(k+1)} - \lambda_1 X^{(k)}
\end{array}\right.
$$
(4) It requires special pocessing if $\{ X^{(k)} \}$ does not fit any cases mentioned above.



### 3. Inverse Power Method

**Inverse power method** is used to compute the smallest magnitude eigenvalue.

In equation
$$
A\bv = \lambda\bv
$$
we multiple $A^{-1}$ on both sides:
$$
A^{-1}\bv = \lambda^{-1}\bv
$$
That is, the largest magnitude eigenvalue of $A^{-1}$ is exactly the inverse of smallest magnitude eigenvalue of $A$.

In practice, we do not compute $A^{-1}$ then iterating but keep solving equation
$$
AX^{(k+1)} = X^{(k)}
$$
[decomposition method]() is applied to decompose $A = LU$ first then we solve
$$
\left\{\begin{array}{ll}
LZ^{(k+1)} = X^{(k)} \\
UX^{(k+1)} = Z^{(k+1)}
\end{array}\right.
$$
We can also normalize the inverse power method as well to avoid the precision problem:
$$
\left\{\begin{array}{ll}
Y^{(k)} = \dfrac{X^{(k)}}{\infnorm{X^{(k)}}} \\
AX^{(k+1)} = Y^{(k)}\\
\end{array}\right.
$$

