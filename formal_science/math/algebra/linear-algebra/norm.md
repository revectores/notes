# Norm

$$
\newcommand{\matr}[1]{\mathbf{#1}}
\newcommand{\A}{\matr{A}}
\newcommand{\B}{\matr{B}}
\newcommand\abs[1]{\lvert#1\rvert}
\newcommand\norm[1]{\lVert#1\rVert}
\newcommand\angle[1]{\langle#1\rangle}
\newcommand\dcos[2]{\angle{#1,#2}}
\newcommand{\argmin}{\mathop{\mathrm{argmin}}}
\newcommand{\argmax}{\mathop{\mathrm{argmax}}}
\newcommand{\sgn}{\mathop{\mathrm{sgn}}}
\newcommand{\tr}{\mathop{\mathrm{tr}}}
$$

### 1. Vector Norm

##### # Definition of Vector Norm

**Vector norm** is such a function meets

1. For any $x\in R^n, \norm{x}\ge0$, and $\norm x = 0$ iff $x=0$. (Non-negative)
2. For any $x\in R^n, \alpha\in R$, $\norm{\alpha x} = |\alpha|\norm{x}$. (Homogeneity)
3. For any $x, y\in R^n$, $\norm{x+y} \le \norm{x} + \norm{y}$ (Triangle Inequality)



##### # Lp-norm of Vector

The common norm, $L_p$-norm of vector $x=(x_1, x_2, \ldots, x_n)^T$ is defined as
$$
\norm{x}_p = \left( \sum_{i=1}^{n}|x_i|^p \right)^{\frac{1}{p}}, ~~~~ 1\le p \le +\infty
$$
And the most useful includes 1-norm, 2-norm, $\infty$-norm:
$$
\begin{align}
&\norm{x}_1 = \sum_{k=1}^{n} |x_k| \\
&\norm{x}_2 = \sqrt{\sum_{k=1}^n x_k^2} \\
&\norm{x}_{\infty} = \max_{1\le k \le n}\{|x_k|\}
\end{align}
$$



##### # Relation of Different Vector Norms

For the two different norm $R_1(x), R_2(x)$ in $R^n$, there must exist $0<m<M<\infty$ for any vector $x$ that holds
$$
mR_2(x) \le R_1(x) \le MR_2(x)
$$
or
$$
m\le \frac{R_1(x)}{R_2(x)} \le M
$$








### 2. Matrix Norm

##### # Definition of Matrix Norm

For any $A, B\in \R^{m\times n}, c\in\R$, if the function $\norm{\cdot}: \R^{m\times n}\rightarrow\R$ holds

1. $\norm A \ge 0$, and $\norm{A} = 0$ if and only if $A = O$. (Non-negative)
2. $\norm{cA} = \abs{c}\norm{A}$. (Homogeneity)
3. $\norm{A+B}\le\norm{A}+\norm{B}$. (Triangle Inequality)

then $\norm{\cdot}$  is a matrix norm on $\R^{m\times n}$.

Besides the three definitive properties above, matrix norm can be more useful if they are also **sub-multiplicative**.

4. $\norm{AB}\le\norm{A}\norm{B}$



##### # Operator p-norm of Matrix

The definition of matrix norm is based on the vector norm,
$$
\norm{A}_p = \sup_{x\neq 0} \frac{\norm{Ax}_p}{\norm{x}_p} = \sup_{\norm{x}_p=1} \norm{Ax}_p
$$
Common norm of matrix includes 1-norm, 2-norm (**spectral norm**), $\infty$-norm and **Frobenius norm**, which can be reduced to some closed forms without $\sup$ operator.

- $\norm{A}_1$ is the max of sum of columns:

$$
\norm{A}_1
= \sup_{x\neq 0} \frac{\norm{Ax}_1}{\norm{x}_1}
= \sup_{\norm{x}_1=1} \norm{Ax}_1
= \max_{1\le j \le n }\sum_{i=1}^m|a_{ij}|
$$
- $\norm{A}_\infty$ is the max of sum of rows:

$$
\norm{A}_\infty
= \sup_{x\neq 0} \frac{\norm{Ax}_\infty}{\norm{x}_\infty}
= \sup_{\norm{x}_1=\infty} \norm{Ax}_\infty
= \max_{1\le i \le m}\sum_{j=1}^n|a_{ij}|
$$
- $\norm{A}_2$  is the maximal singular value, that is, maximal square root of $x_1$, the maximal eigenvalue of $A^HA$:

$$
\norm{A}_2 = \sup_{\norm{x}_2 = 1} \norm{Ax}_2 = \sigma_1 = \sqrt{x_{\mathrm{max}}(AA^H)}
$$
> **Proof.** $\norm{A}_1$ is the max of sum of columns.
>
> For $\norm{A}_1$, consider $\norm x_1 = 1$, where $\displaystyle\sum_{i=1}^n\abs{x_i} = 1$. The definition of 1-norm shows
> $$
> \norm{Ax}_1 = \sup_{\norm{x}_p = 1}\sum_{i=1}^m\abs{\sum_{j=1}^nx_j a_{ij}}
> $$
> Let $j'$ be the index of the column that has maximal sum, that is,
> $$
> j' = \argmax_{j} \sum_{i=1}^m\abs{a_{ij}}
> $$
> then we have
> $$
> \sum_{i=1}^m\abs{\sum_{j=1}^nx_j a_{ij}}
> \leq \sum_{i=1}^m\abs{\sum_{j=1}^nx_j a_{ij'}}
> = \sum_{i=1}^m\abs{a_{ij'}\sum_{j=1}^nx_j}
> \leq \sum_{i=1}^m\left( \abs{a_{ij'}}\sum_{j=1}^n\abs{x_j} \right)
> = \sum_{i=1}^m \abs{a_{ij'}}
> $$
> the equality holds if and only if $x_{j'} = 1, x_j = 0 \ \mathrm{for} \ j \neq j' $

> **Proof.** $\norm{A}_\infty$ is the max of sum of rows.
>
> For $\norm{x}_\infty = 1$, it holds $\displaystyle\max_{1\leq i\leq n} \abs{x_i} = 1$, the definition of infinite norm shows
> $$
> \norm{Ax}_\infty = \sup_{x_j \le 1}\max_{1\leq i\leq n}\abs{\sum_{j=1}^nx_j a_{ij}}
> $$
> since $\abs{x_j}\le1$ we have
> $$
> \max_{1\leq i\leq n}\abs{\sum_{j=1}^nx_j a_{ij}}
> \le \max_{1\leq i\leq n}{\sum_{j=1}^n \abs{a_{ij}}}
> $$
> where the equality holds if any only if $x_j = \sgn{a_{ij'}}$, where $j' = \displaystyle\argmax_j \sum_{i=1}^n\abs{a_{ij}}$. Hence
> $$
> \norm A_{\infty} = \max_{1\leq i\leq m}\sum_{j=1}^n\abs{a_{ij}}
> $$

> **Proof.** 



##### # Element-wise Matrix Norms


$$
{\displaystyle \|A\|_{p,p}=\|\mathrm {vec} (A)\|_{p}=\left(\sum _{i=1}^{m}\sum _{j=1}^{n}|a_{ij}|^{p}\right)^{1/p}}
$$

For $p = 2$ it also called Frobenius norm $\norm{A}_F$, also equals to the square root of trace of $A^HA$.
$$
\norm{A}_F
= \sqrt{\sum_{i=1}^m\sum_{j=1}^n |a_{ij}|^2}
= \sqrt{\tr(A^HA)}
= \sqrt{\sum_{i=0}^{\min\{m,n\}}\sigma_i^2(A)}
$$
An important feature of F-norm is that, unitary matrix does not change the F-norm.
$$
\norm{UA}
= \sqrt{\tr((UA)^HUA)}
= \sqrt{\tr((UA)^H)}
$$

For F-norm and 2-norm we always have $\norm{A}_2\le\norm{A}_F$.

> **Proof**. 要证明 $\|A\|_{2} \leq\|A\|_{F}$, 根据 $\|A\|_{2}$ 的定义, 等价于证明对任意满足 $\|x\|_{2}=1$ 的向量 $x$, 都有
> $$
> \|A x\|_{2} \leq\|A\|_{F}
> $$
>
> 从而取上确界可得
> $$
> \sup _{\|x\|_{2}=1}\|A x\|_{2} \leq\|A\|_{F}
> $$
> 展开 $\|A x\|_{2}^{2}$, 对单个元素使用 Cauchy-Schwarz 不等式
>$$
> \left(\displaystyle\sum_{j=1}^{n} a_{i j} x_{j}\right)^{2} \leq\left(\displaystyle\sum_{j=1}^{n} a_{i j}^{2}\right)\left(\displaystyle\sum_{j=1}^{n} x_{j}^{2}\right)
> $$
> 
> 由于 $\|x\|_{2}=1$, 即 $\displaystyle\sum_{j=1}^{n} x_{j}^{2}=1$, 所以
> $$
>\left(\displaystyle\sum_{j=1}^{n} a_{i j} x_{j}\right)^{2} \leq \displaystyle\sum_{j=1}^{n} a_{i j}^{2}
> $$
> 对所有行求和
> 
> 将上式对 $i$ 从 1 到 $m$ 求和, 得到
>$$
> \|A x\|_{2}^{2}=\displaystyle\sum_{i=1}^{m}\left(\displaystyle\sum_{j=1}^{n} a_{i j} x_{j}\right)^{2} \leq \displaystyle\sum_{i=1}^{m} \displaystyle\sum_{j=1}^{n} a_{i j}^{2}=\|A\|_{F}^{2}
> $$
> 
> 因此
> $$
>\|A x\|_{2}=\sqrt{\|A x\|_{2}^{2}} \leq \sqrt{\|A\|_{F}^{2}}=\|A\|_{F}
> $$
> 
> 由于该结论对任意 $\|x\|_{2}=1$ 都成立, 故取上确界得到
> $$
>\|A\|_{2}=\sup _{\|x\|_{2}=1}\|A x\|_{2} \leq\|A\|_{F}
> $$
> 

此外, 从SVD分解的视角, 2范数等于$A^TA$的最大奇异值, 而F范数等于$A^TA$的所有奇异值之和, 因此有前者小于后者成立.




##### # Relation Between Matrix Norms

For the eigenvalue $x$ we have $Ax = x x$,
$$
|x|\norm{x} = \norm{x x} = \norm{Ax} \le \norm A \norm x
$$
that is, the eigenvalue of matrix is less than **any** norms of the matrix. 



##### # Spectral Radius

**spectral radius** $\rho(A) = \max_{1\le i \le n}\{|x_i|\}$, where the $x_i, 1\le i\le n$ are the eigenvalue of matrix $A$.
$$
\rho(A)\le \norm{A}, \norm{A}_2=\sqrt{\rho(A^TA)}
$$

