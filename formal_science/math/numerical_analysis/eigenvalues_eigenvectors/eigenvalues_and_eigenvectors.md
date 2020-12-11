# Eigenvalues and Eigenvectors

$$
\newcommand{\norm}[1]{\left\lVert#1\right\rVert}
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

Recall that for $n$-order matix with $A$, if we have $A\bv = \lambda \bv$, then $\lambda$ is the eigenvalue of $A$ and $\bv$ is the corresponding eigenvector.

To compute the eigenvalues and eigenvectors by definition, we need to solve the equations $|\lambda I - A| = 0$ with order $n$, where $n$ is the order of matrix.

For instance, to compute the eigenvalue of $A = \begin{bmatrix}
0 & 1 \\
1 & 1
\end{bmatrix}$, we must solve the euqation
$$
\begin{vmatrix}
\lambda & 1 \\
1 & \lambda - 1
\end{vmatrix} = \lambda(\lambda-1) - 1 = 0
$$
However, [Abel–Ruffini theorem]() states that there is no solution in radicals to general polynomial equations of degree five or higher with arbitrary coefficients, hence this is not the acceptable approach.



### 2. Power Method

##### # Power Method Introduction

For any initial vector $X^{(0)}$, which can be expressed by $n$ linear independent eigenvector of $A$,
$$
X^{(0)} = \alpha_1\bv_1 + \alpha_2 \bv_2 + \cdots + \alpha_n \bv_n
$$

construct iteration $X^{(k+1)} = AX^{(k)}$:
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
How $X^{(k)}$ change when executing the iteration depends on the distribution of eigenvalues.



##### # Two Cases when Applying Power Method

There are multiple cases when applying power method (depends on the distribution of eigenvalues), we discuss two simple cases here.

**Case 1**. If the ratio $\dfrac{x^{(k+1)}}{x^{(k)}}$ converges, the largest magnitude eigenvalue is unique and is simple root. The largest magnitude eigenvalue and the corresponding eigenvector can be computed by
$$
\left\{\begin{array}{ll}
\lambda_1 \approx \dfrac{x_i^{(k+1)}}{x_i^{(k)}}, \quad i = 1, 2, \ldots, n \\
\bv_1 \approx X^{(k)}
\end{array}\right.
$$

> **Proof**. For the unique largest magnitude eigenvalue $\lambda_1$,
> $$
> \begin{align}
> X^{(k)}
> &= \lambda_1^k\alpha_1 \bv_1 + \lambda_2^k\alpha_2 \bv_2 + \cdots + \lambda_n^k\alpha_n \bv_n \\
> &= \lambda_1^k\left[ \lambda_1^k\alpha_1 \bv_1 + \left(\frac{\lambda_2}{\lambda_1}\right)^k\alpha_2 \bv_2 + \cdots + \left(\frac{\lambda_n}{\lambda_1}\right)^k\alpha_n \bv_n \right]
> \end{align}
> $$
> For sufficiently large $k$, we have $\left| \left( \dfrac{\lambda_i}{\lambda_1} \right)^k \right| \rightarrow 0$ for $i \neq 1$ since $\lambda_1$ is the largest magnitude eigenvalue. Hence
> $$
> \begin{align}
> X^{(k)}   &\approx \lambda_1^k\alpha_1\bv_1 \\
> X^{(k+1)} &\approx \lambda_1^{k+1}\alpha_1\bv_1 = \lambda_1 \lambda^k\alpha_1\bv_1 = \lambda_1X^{(k)}
> \end{align}
> $$

**Case 2**. If the ratio $\dfrac{x^{(k+1)}}{x^{(k)}}$ does not converges but $\dfrac{x^{(2k+2)}}{x^{(2k)}}$ does, then largest magnitude eigenvalues are the real roots with different signs. The largest magnitude eigenvalue and the corresponding eigenvector can be computed by
$$
\left\{\begin{array}{ll}
\lambda_1 = \sqrt{\dfrac{x_1^{(k+2)}}{x_i^{(k)}}}, \quad i = 1, 2, \ldots, n \\
\bv_1 = X^{(k+1)} + \lambda_1 X^{(k)} \\
\bv_2 = X^{(k+1)} - \lambda_1 X^{(k)}
\end{array}\right.
$$

> **Proof**. For two largest mangnitude eigenvalues $\lambda_1, \lambda_2$ with $\lambda_1 = -\lambda_2$,
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

Those tendences that do not fit the two cases above require other methods.



##### # Normalized Computation of Power Method

If the largest magnitude eigenvalues is larger/smaller than $1$, some components of $X^{(k)}$ will increase/decrease continuously during the iteration, which will lead to the precision problem due to [IEEE754](). Hence we apply the normalization:
$$
X^{(k+1)} = \frac{AX^{(k)}}{\norm{AX^{(k)}}_{\infin}}
$$
The normalization process gurantees $\norm{X^{(k)}}_\infty = 1$, that is, the component with largest magnitude of $X^{(k)}$ will remain $\pm1$.

There are three cases after applying normalization process:

(1) If $\{X^{k}\}$ converges, then there is one unique largest magnitude eigenvalues of $A$,
$$
\left\{\begin{array}{ll}
\displaystyle \lambda_1 \approx \max_{1\le i \le n} |x_i^{(k)}| = |x_j^{(k)}| \\
\bv_1 \approx X^{(k)}
\end{array}\right.
$$

(2) If $\{X^{(2k)}\}, \{X^{(2k+1)}\}$ converges to vectors with different signs, there is still one unique largest magnitude eigenvalues of $A$.
$$
\left\{\begin{array}{ll}
\displaystyle \lambda_1 \approx - \max_{1\le i \le n} |x_i^{(k)}| = - |x_j^{(k)}| \\
\bv_1 \approx X^{(k)}
\end{array}\right.
$$
(3) If ${\{X^{(2k)}\}, \{X^{(2k+1)}\}}$ converges to two different vectors, there are two dfifferent vectors with inverse sign. For sufficiently large $k$, we exectue one more unnormalized operation $X^{(k+1)} = AX^{(k)} = A^2X^{(k-1)}$, then
$$
\left\{\begin{array}{ll}
\lambda_1 \approx \displaystyle\sqrt{\frac{x_i^{(k+1)}}{x_i^{(k-1)}}} \\
\lambda_2 = -\lambda_1 \\
\bv_1 = X^{(k+1)} + \lambda_1 X^{(k)} \\
\bv_2 = X^{(k+1)} - \lambda_1 X^{(k)}
\end{array}\right.
$$
(4) It requires special pocessing if $\{ X^{(k)} \}$ does not fit any cases mentioned above.



### 3. Inverse Power Method

**Inverse power method** is used to compute the smallest magnitude eigenvalue. For the equation $A\bv = \lambda\bv$, we multiple $A^{-1}$ on both sides then we have $A^{-1}\bv = \lambda^{-1}\bv$. Note that since the eigenvalues of $A$ and $A^{-1}$ are inverse also, the largest magnitude eigenvalue of $A^{-1}$ is exactly the smallest magnitude eigenvalue of $A$.

In practice, we do not compute $A^{-1}$ and exectue the iteration process, but solve the equation
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
We can normalize the inverse power method as well to avoid the precision problem:
$$
\left\{\begin{array}{ll}
AX^{(k+1)} = \displaystyle\frac{X^{(k)}}{\norm{X^{(k)}}_\infty } \\
\end{array}\right.
$$
