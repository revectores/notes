# Subspace of Matrix

##### 1.1 Definition of Four Foundamental Subspace

对于矩阵我们定义四个基本子空间

1. 列空间:  $\operatorname{Col}(\boldsymbol{A})$
2. 行空间:  $\operatorname{Row}(\boldsymbol{A})=\operatorname{Col}\left(\boldsymbol{A}^{\mathrm{T}}\right)$
3. 零空间:  $\operatorname{Null}(\boldsymbol{A})$
4. 左零空间: Null( $\left.\boldsymbol{A}^{\mathrm{T}}\right)$

为便于表示, 对于矩阵 $\boldsymbol{A} \in \mathbb{R}^{m \times n}$ , 其$m$个行向量记作
$$
\begin{aligned}
\boldsymbol{r}_{1} & =\left[\begin{array}{llll}
a_{11} & a_{12} & \ldots & a_{1 n}
\end{array}\right]^{\mathrm{T}} \\
\boldsymbol{r}_{2} & =\left[\begin{array}{llll}
a_{21} & a_{22} & \ldots & a_{2 n}
\end{array}\right]^{\mathrm{T}} \\
& \ldots \\
\boldsymbol{r}_{m} & =\left[\begin{array}{llll}
a_{m 1} & a_{m 2} & \ldots & a_{m n}
\end{array}\right]^{\mathrm{T}}
\end{aligned}
$$
其 $n$ 个列向量记作
$$
\boldsymbol{a}_{1}=\left[\begin{array}{c}
a_{11} \\
a_{21} \\
\vdots \\
a_{m 1}
\end{array}\right], \boldsymbol{a}_{2}=\left[\begin{array}{c}
a_{12} \\
a_{22} \\
\vdots \\
a_{m 2}
\end{array}\right], \cdots, \boldsymbol{a}_{n}=\left[\begin{array}{c}
a_{1 n} \\
a_{2 n} \\
\vdots \\
a_{m n}
\end{array}\right]
$$

即 $\boldsymbol{A}=\left[\begin{array}{llll}\boldsymbol{r}_{1} & \boldsymbol{r}_{2} & \ldots & \boldsymbol{r}_{m}\end{array}\right]^{\mathrm{T}}=\left[\begin{array}{llll}\boldsymbol{a}_{1} & \boldsymbol{a}_{2} & \ldots & \boldsymbol{a}_{n}\end{array}\right]$ .

列空间是其列向量 $\left\{\boldsymbol{a}_{1}, \boldsymbol{a}_{2}, \cdots, \boldsymbol{a}_{n}\right\}$ 的所有线性组合的集合, 它是 $\mathbb{R}^{m}$ 的一个子空间, 用符号 $\operatorname{Col}(\boldsymbol{A})$ 表示, 即
$$
\operatorname{Col}(\boldsymbol{A})=\left\{\boldsymbol{y} \in \mathbb{R}^{m} \mid \boldsymbol{y}=\displaystyle\sum_{j=1}^{n} \alpha_{j} \boldsymbol{a}_{j}, \alpha_{j} \in \mathbb{R}\right\}=\operatorname{span}\left\{\boldsymbol{a}_{1}, \boldsymbol{a}_{2} \cdots \boldsymbol{a}_{n}\right\}
$$

行空间是其行向量 $\left\{\boldsymbol{r}_{1}, \boldsymbol{r}_{2}, \cdots, \boldsymbol{r}_{m}\right\}$ 的所有线性组合的集合, 它是 $\mathbb{R}^{n}$ 的一个子空间, 用符号 $\operatorname{Row}(\boldsymbol{A})$ 表示, 也可以用 $\operatorname{Col}\left(\boldsymbol{A}^{\mathrm{T}}\right)$ 表示, 即
$$
\operatorname{Row}(\boldsymbol{A})=\operatorname{Col}\left(\boldsymbol{A}^{\mathrm{T}}\right)=\left\{\boldsymbol{y} \in \mathbb{R}^{n} \mid \boldsymbol{y}=\displaystyle\sum_{i=1}^{m} \beta_{i} \boldsymbol{r}_{i}, \beta_{i} \in \mathbb{R}\right\}=\boldsymbol{\operatorname { span }}\left\{\boldsymbol{r}_{1}, \boldsymbol{r}_{2} \cdots \boldsymbol{r}_{m}\right\}
$$

零空间是所有满足齐次线性方程组 $\boldsymbol{A} \boldsymbol{x}=\mathbf{0}$ 的解向量集合, 它是 $\mathbb{R}^{n}$ 的一个子空间, 用符号 $\operatorname{Null}(\boldsymbol{A})$ 表示, 即
$$
\operatorname{Null}(\boldsymbol{A})=\left\{\boldsymbol{x} \in \mathbb{R}^{n} \mid \boldsymbol{A x}=\mathbf{0}\right\}
$$

左零空间是所有满足齐次线性方程组 $\boldsymbol{A}^{\mathrm{T}} \boldsymbol{y}=\mathbf{0}$ 的解向量集合, 它是 $\mathbb{R}^{n}$ 的一个子空间, 用符号 $\operatorname{Null}\left(\boldsymbol{A}^{\mathrm{T}}\right)$ 表示, 即
$$
\operatorname{Null}\left(\boldsymbol{A}^{\mathrm{T}}\right)=\left\{\boldsymbol{y} \in \mathbb{R}^{n} \mid \boldsymbol{A}^{\mathrm{T}} \boldsymbol{y}=\mathbf{0}\right\}
$$

子空间与其对应的矩阵变换具有不变性, 基于不变性, 可以通过行列变换, 求解空间的简化表示.

1. 初等行变换不改变矩阵的行空间和零空间.
2. 初等列变换不改变矩阵的列空间和左零空间.

> 证明. 对于初等行变换和行空间的关系, 我们有
>
> (1) 对于 I 型初等行变换(用非零常数乘某一行), 有
> $$
> \boldsymbol{\operatorname { span }}\left\{\boldsymbol{r}_{1}, \cdots, \boldsymbol{r}_{i}, \cdots, \boldsymbol{r}_{m}\right\}=\boldsymbol{\operatorname { span }}\left\{\boldsymbol{r}_{1}, \cdots, c \boldsymbol{r}_{i}, \cdots, \boldsymbol{r}_{m}\right\}
> $$
> (2) 对于 II 型初等行变换(某一行的 $c$ 倍加到另一行)有
> $$
> \boldsymbol{\operatorname { s p a n }}\left\{\boldsymbol{r}_{1}, \cdots, \boldsymbol{r}_{i}+c \boldsymbol{r}_{j}, \cdots, \boldsymbol{r}_{j}, \cdots, \boldsymbol{r}_{m}\right\}=\boldsymbol{\operatorname { p p a n }}\left\{\boldsymbol{r}_{1}, \cdots, \boldsymbol{r}_{i}, \cdots, \boldsymbol{r}_{j}, \cdots, \boldsymbol{r}_{m}\right\}
> $$
>
> 对任意 $\boldsymbol{y} \in \boldsymbol{\operatorname { s p a n }}\left\{\boldsymbol{r}_{1}, \cdots, \boldsymbol{r}_{i}, \cdots, \boldsymbol{r}_{j}, \cdots, \boldsymbol{r}_{m}\right\}$ 存在 $\beta_{1}, \cdots, \beta_{m}$ , 使得
> $$
> \begin{aligned}
> \boldsymbol{y} & =\beta_{1} \boldsymbol{r}_{1}+\cdots+\beta_{i} \boldsymbol{r}_{i}+\cdots+\beta_{j} \boldsymbol{r}_{j}+\cdots+\beta_{m} \boldsymbol{m} \\
> & =\beta_{1} \boldsymbol{r}_{1}+\cdots+\beta_{i}\left(\boldsymbol{r}_{i}+c \boldsymbol{r}_{j}\right)+\cdots+\left(\beta_{j}-c \beta_{i}\right) \boldsymbol{r}_{j}+\cdots+\beta_{m} \boldsymbol{m}
> \end{aligned}
> $$
>
> 可以推出 $\boldsymbol{y} \in \mathbf{\operatorname { s p a n }}\left\{\boldsymbol{r}_{1}, \cdots, \boldsymbol{r}_{i}+c \boldsymbol{r}_{j}, \cdots, \boldsymbol{r}_{j}, \cdots, \boldsymbol{r}_{m}\right\}$
>
> (3) 对于 III 型初等行变换(互换矩阵中两行的位置), 有
> $$
> \boldsymbol{\operatorname { s p a n }}\left\{\boldsymbol{r}_{1}, \cdots, \boldsymbol{r}_{i}, \cdots, \boldsymbol{r}_{j}, \cdots, \boldsymbol{r}_{m}\right\}=\boldsymbol{\operatorname { s p a n }}\left\{\boldsymbol{r}_{1}, \cdots, \boldsymbol{r}_{j}, \cdots, \boldsymbol{r}_{i}, \cdots, \boldsymbol{r}_{m}\right\}
> $$
>
> 对于初等行变换和零空间的关系, 令 $\boldsymbol{E}_{i}$ 是对应于矩阵 $\boldsymbol{A}$ 的第 $i$ 次初等行变换的初等矩阵. 由初等行变换可逆. 于是, 
> $$
> \boldsymbol{B x}=\left(\boldsymbol{E}_{k} \boldsymbol{E}_{k-1} \cdots \boldsymbol{E}_{1} \boldsymbol{A}\right) \boldsymbol{x}=\mathbf{0} \Leftrightarrow \boldsymbol{A} \boldsymbol{x}=\mathbf{0}
> $$
>
> 即齐次线性方程 $\boldsymbol{B} \boldsymbol{x}=\mathbf{0}$ 与 $\boldsymbol{A} \boldsymbol{x}=\mathbf{0}$ 具有相同的解向量, 从而 $\boldsymbol{A}$ 经过若干次初等行变换后得到的矩阵 $\boldsymbol{B}$ 与 $\boldsymbol{A}$ 具有相同的零空间. 对初等列变化也可以类似地证明.



> 例. 求 $3 \times 3$ 矩阵
> $$
> \boldsymbol{A}=\left[\begin{array}{ccc}
> 1 & 2 & 1 \\
> 1 & 1 & -1 \\
> 1 & 4 & 5
> \end{array}\right]
> $$
>
> 的行空间, 列空间, 零空间和左零空间.
>
> 解. 依次进行初等列变换, 得到列简约阶梯型矩阵
> $$
> \left[\begin{array}{ccr}
> 1 & 2 & 1 \\
> -1 & -1 & 1 \\
> 1 & 4 & 5
> \end{array}\right] \xrightarrow[C_{3}-C_{1}]{C_{2}-2 C_{1}}\left[\begin{array}{ccc}
> 1 & 0 & 0 \\
> -1 & 1 & 2 \\
> 1 & 2 & 4
> \end{array}\right] \xrightarrow[C_{3}-2 C_{2}]{C_{1}+C_{2}} \boldsymbol{A}_{C}=\left[\begin{array}{lll}
> 1 & 0 & 0 \\
> 0 & 1 & 0 \\
> 3 & 2 & 0
> \end{array}\right]
> $$
>
> 由此得到两个线性无关的列向量 $\boldsymbol{c}_{1}=(1,0,3), \boldsymbol{c}_{2}=(0,1,2)$ , 它们是列空间 $\operatorname{Col}(\boldsymbol{A})$ 的基
> $$
> \operatorname{Col}(\boldsymbol{A})=\boldsymbol{\operatorname { s p a n }}\{(1,0,3),(0,1,2)\}
> $$
>
> 由于一系列初等列变换不改变左零空间, 根据 $\boldsymbol{A}_{C}$ , 知 $-3 \boldsymbol{r}_{1}-2 \boldsymbol{r}_{2}+\boldsymbol{r}_{3}=\mathbf{0}$
>
> 那么我们就可以根据 $\boldsymbol{A}_{C}$ 的主元位置, 矩阵 $\boldsymbol{A}$ 的主元行是第 1 行和第 2 行, 即行空间 $\operatorname{Col}\left(\boldsymbol{A}^{\mathrm{T}}\right)$可以写作
> $$
> \operatorname{Col}\left(\boldsymbol{A}^{\mathrm{T}}\right)=\boldsymbol{\operatorname { s p a n }}\{(1,2,1),(-1,-1,1)\}
> $$
>
> 对 $A$ 进行初等行变换
> $$
> \left[\begin{array}{ccc}
> 1 & 2 & 1 \\
> -1 & -1 & 1 \\
> 1 & 4 & 5
> \end{array}\right] \xrightarrow[R_{2}+R_{1}]{R_{3}-R_{1}}\left[\begin{array}{ccc}
> 1 & 2 & 1 \\
> 0 & 1 & 2 \\
> 0 & 2 & 4
> \end{array}\right] \xrightarrow[R_{1}-2 R_{2}]{R_{3}-2 R_{2}} \boldsymbol{A}_{R}=\left[\begin{array}{ccc}
> 1 & 0 & -3 \\
> 0 & 1 & 2 \\
> 0 & 0 & 0
> \end{array}\right]
> $$
>
> $\boldsymbol{A}$ 的秩为 2 . 解方程组 $\boldsymbol{A}_{R} \boldsymbol{x}=\mathbf{0}$ 得到 $\boldsymbol{x}=k(3,-2,1)$
> $$
> \operatorname{Null}(\boldsymbol{A})=\boldsymbol{\operatorname { s p a n }}\{(3,-2,1)\}
> $$
>
> 所以零空间维数为1.
>
> 类似地, 我们求解 $\boldsymbol{A}_{C}^{\mathrm{T}} \boldsymbol{x}=\mathbf{0}$ 得到 $\boldsymbol{x}=k(3,2,-1)$ 所以
> $$
> \operatorname{Null}\left(\boldsymbol{A}^{\mathrm{T}}\right)=\boldsymbol{\operatorname { s p a n }}\{(3,2,-1)\}
> $$
>
> 左零空间的维数也是1. 



##### 1.2 Base of Four Fundamental Subspace

设 $\boldsymbol{A} \in \mathbb{R}^{m \times n}$ , 则

1. $\operatorname{dim}(\operatorname{Col}(\boldsymbol{A}))=\operatorname{dim}(\operatorname{Row}(\boldsymbol{A}))=\operatorname{rank}(\boldsymbol{A})$. 即矩阵的行秩等于列秩.
2. $\operatorname{dim}(\operatorname{Null}(\boldsymbol{A}))=n-\operatorname{rank}(\boldsymbol{A})$. $\operatorname{dim}\left(\operatorname{Null}\left(\boldsymbol{A}^{\mathrm{T}}\right)\right)=m-\operatorname{rank}(\boldsymbol{A})$.

> 证明. 令 $r=\operatorname{rank}(\boldsymbol{A})$ , 根据定义 $\operatorname{Null}(\boldsymbol{A})=\left\{\boldsymbol{x} \in \mathbb{R}^{n} \mid \boldsymbol{A x}=\mathbf{0}\right\}$ , 对 $\boldsymbol{A}$ 做行初等变换并交换其中的一些列,  $\boldsymbol{A}$ 变换为
> $$
> \boldsymbol{A}^{\prime}=\left[\begin{array}{cc}
> \boldsymbol{\boldsymbol { I }} & \boldsymbol{B} \\
> \boldsymbol{O} & \boldsymbol{O}
> \end{array}\right]=\left[\begin{array}{ccccccc}
> 1 & & & & b_{11} & b_{12} & \ldots & b_{1, n-r} \\
>   & 1 & & & b_{21} & b_{22} & \ldots & b_{2, n-r} \\
>   &   & & \ddots & \vdots & \vdots & & \vdots \\
> & & & 1 & b_{r 1} & b_{r 2} & \ldots & b_{r, n-r} \\
> 0 & 0 & \ldots & 0 & 0 & 0 & \cdots & 0 \\
> \vdots & \vdots & \vdots & \vdots & \vdots & \vdots & \ldots & \vdots \\
> 0 & 0 & \ldots & 0 & 0 & 0 & \ldots & 0
> \end{array}\right]
> $$
> 显然 $\boldsymbol{A}^{\prime} \boldsymbol{x}=\mathbf{0}$ 有以下 $n-r$ 个解
> $$
> \boldsymbol{x}^{(1)}=\left[\begin{array}{c}
> b_{11} \\
> \vdots \\
> b_{r 1} \\
> -1 \\
> 0 \\
> \vdots \\
> 0
> \end{array}\right], \boldsymbol{x}^{(2)}=\left[\begin{array}{c}
> b_{12} \\
> \vdots \\
> b_{r 2} \\
> 0 \\
> -1 \\
> \vdots \\
> 0
> \end{array}\right],
> \ldots,
> \boldsymbol{x}^{(n-r)}=\left[\begin{array}{c}
> b_{1, n-r} \\
> \vdots \\
> b_{r, n-r} \\
> 0 \\
> 0 \\
> \vdots \\
> -1
> \end{array}\right]
> $$
> 并且容易看出向量组 $\left\{\boldsymbol{x}^{(1)}, \boldsymbol{x}^{(2)}, \ldots, \boldsymbol{x}^{(n-r)}\right\}$ 是一个极大线性无关组. 注意到, 如果 $\boldsymbol{x}$ 是方程 $\boldsymbol{A}^{\prime} \boldsymbol{x}=\mathbf{0}$ 的解, 那么当 $x_{r+1}, x_{r+2}, \ldots, x_{n}$ 取定时, 可以唯一确定 $\boldsymbol{x}$ . 换句话说 $\left\{\boldsymbol{x} \in \mathbb{R}^{n} \mid \boldsymbol{A}^{\prime} \boldsymbol{x}=\mathbf{0}\right\}$的维数最大为 $n-r$ .
>
> 综上 $\boldsymbol{A}^{\prime} \boldsymbol{x}=\mathbf{0}$ 解空间的维数为 $n-r$ , 即 $\boldsymbol{A} \boldsymbol{x}=\mathbf{0}$ 解空间的维数为 $n-r$ , 即
> $$
> \operatorname{dim}(\operatorname{Null}(\boldsymbol{A}))=n-r
> $$
>
> 由此同时可以得到推论$\operatorname{dim}\left(\operatorname{Null}\left(\boldsymbol{A}^{\mathrm{T}}\right)\right)=m-\operatorname{rank}(\boldsymbol{A})$.



##### 1.3 Orthogonality of Four Subspace

![Four Fundamental Subspaces - ML Wiki](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/workspace/note/note/formal_science/math/algebra/linear-algebra/matrix/fundamental-subspaces.svg)



两个子空间之间的关系由这两个子空间的元素(即向量)之间的关系刻画. 设 $\boldsymbol{A} \in \mathbb{R}^{m \times n}, \boldsymbol{A}$ 的四个基本子空间中,  $\operatorname{Col}(\boldsymbol{A}), \operatorname{Null}\left(\boldsymbol{A}^{\mathrm{T}}\right)$ 都是 $\mathbb{R}^{m}$ 的子空间, $\operatorname{Col}\left(\boldsymbol{A}^{\mathrm{T}}\right), \operatorname{Null}(\boldsymbol{A})$ 都是 $\mathbb{R}^{n}$ 的子空间, 两两之间的交集仅为零向量, 即
$$
\begin{array}{l}
\operatorname{Col}(\boldsymbol{A}) \cap \operatorname{Null}\left(\boldsymbol{A}^{\mathrm{T}}\right)=\{\mathbf{0}\} \\
\operatorname{Col}\left(\boldsymbol{A}^{\mathrm{T}}\right) \cap \operatorname{Null}(\boldsymbol{A})=\{\mathbf{0}\}
\end{array}
$$

证明. 设 $\boldsymbol{v} \in \operatorname{Col}\left(\boldsymbol{A}^{\mathrm{T}}\right) \cap \operatorname{Null}(\boldsymbol{A})$ , 即 $\boldsymbol{v}$ 在 $\boldsymbol{A}=\left[\begin{array}{llll}\mathbf{r}_{1} & \mathbf{r}_{2} & \ldots & \mathbf{r}_{\mathrm{m}}\end{array}\right]^{\mathrm{T}}$ 的行空间中且 $\boldsymbol{A} \boldsymbol{v}=\mathbf{0}$ . 设 $\boldsymbol{v}=a_{1} \boldsymbol{r}_{1}+a_{2} \boldsymbol{r}_{2}+\ldots+a_{m} \boldsymbol{r}_{m}$ , 则
$$
\boldsymbol{A} \boldsymbol{v}=\mathbf{0} \Longrightarrow \boldsymbol{r}_{1}^{\mathrm{T}} \boldsymbol{v}=0, \ldots, \boldsymbol{r}_{m}^{\mathrm{T}} \boldsymbol{v}=0 \Longrightarrow \boldsymbol{v}^{\mathrm{T}} \boldsymbol{v}=0 \Longrightarrow \boldsymbol{v}=\mathbf{0}
$$

即
$$
\operatorname{Col}\left(\boldsymbol{A}^{\mathrm{T}}\right) \cap \operatorname{Null}(\boldsymbol{A})=\{\mathbf{0}\} .
$$

同理 $\operatorname{Col}(\boldsymbol{A}) \cap \operatorname{Null}\left(\boldsymbol{A}^{\mathrm{T}}\right)=\{\mathbf{0}\}$ . 













