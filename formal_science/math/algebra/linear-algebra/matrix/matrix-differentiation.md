# 矩阵微分

### 1. 矩阵梯度

若 $\boldsymbol{A} \in \mathbb{R}^{n \times m}, f(\boldsymbol{A}): \mathbb{R}^{n \times m} \rightarrow \mathbb{R}$ 是一实值函数, 其中 $\boldsymbol{A}=\left[\begin{array}{cccc}a_{11} & a_{12} & \ldots & a_{1 m} \\ a_{21} & a_{22} & \ldots & a_{2 m} \\ \vdots & \vdots & & \vdots \\ a_{n 1} & a_{n 2} & \ldots & a_{n m}\end{array}\right]$,
则定义矩阵函数的梯度为
$$
\dfrac{\partial}{\partial \boldsymbol{A}} f=\left[\begin{array}{cccc}
\dfrac{\partial f}{\partial a_{11}} & \dfrac{\partial f}{\partial a_{12}} & \cdots & \dfrac{\partial f}{\partial a_{1 m}} \\
\dfrac{\partial f}{\partial a_{21}} & \dfrac{\partial f}{\partial a_{22}} & & \dfrac{\partial f}{\partial a_{2 n}} \\
\vdots & \vdots & & \vdots \\
\dfrac{\partial f}{\partial a_{n 1}} & \dfrac{\partial f}{\partial a_{n 2}} & \cdots & \dfrac{\partial f}{\partial a_{n m}}
\end{array}\right]
$$

> 例. 令 $f: \mathbb{R}^{n \times m} \rightarrow \mathbb{R}, f(\boldsymbol{A})=\sum_{i, j} a_{i j}$, 其中 $a_{i j}$ 为矩阵 $\boldsymbol{A}$ 的第 $i$ 行 $j$ 列个元素, 求 $\dfrac{\partial f}{\partial A}$.
>
> 解. 我们对每一分量进行求导可得
> $$
> \dfrac{\partial f}{\partial a_{i j}}=1
> $$
>
> 从而
> $$
> \dfrac{\partial f}{\partial \boldsymbol{A}}=\left[\begin{array}{cccc}
> 1 & 1 & \ldots & 1 \\
> 1 & 1 & \ldots & 1 \\
> \vdots & \vdots & & \vdots \\
> 1 & 1 & \ldots & 1
> \end{array}\right]
> $$
>

若 $\boldsymbol{x} \in \mathbb{R}^{n}, f(\boldsymbol{x}): \mathbb{R}^{n} \rightarrow \mathbb{R}$ 是一实值函数, 则有
$$
\dfrac{\partial}{\partial \boldsymbol{x}^{\mathrm{T}}} f=\left(\frac{\partial}{\partial \boldsymbol{x}} f\right)^{\mathrm{T}}
$$

实值函数相对于矩阵变元的梯度具有以下性质.
- 线性法则: 若 $f(\boldsymbol{A})$ 和 $g(\boldsymbol{A})$ 分别是矩阵 $\boldsymbol{A}$ 的实值函数, $c_{1}$ 和 $c_{2}$ 为实常数, 则
$$
\dfrac{\partial\left[c_{1} f(\boldsymbol{A})+c_{2} g(\boldsymbol{A})\right]}{\partial \boldsymbol{A}}=c_{1} \frac{\partial f(\boldsymbol{A})}{\partial \boldsymbol{A}}+c_{2} \frac{\partial g(\boldsymbol{A})}{\partial \boldsymbol{A}}
$$
- 乘积法则: 若 $f(\boldsymbol{A})$ 和 $g(\boldsymbol{A})$ 分别是矩阵 $\boldsymbol{A}$ 的实值函数, 则
$$
\dfrac{\partial f(\boldsymbol{A}) g(\boldsymbol{A})}{\partial \boldsymbol{A}}=g(\boldsymbol{A}) \frac{\partial f(\boldsymbol{A})}{\partial \boldsymbol{A}}+f(\boldsymbol{A}) \frac{\partial g(\boldsymbol{A})}{\partial \boldsymbol{A}}
$$
- 商法则: 若 $g(\boldsymbol{A}) \neq 0$, 则

$$
\dfrac{\partial f(\boldsymbol{A}) / g(\boldsymbol{A})}{\partial \boldsymbol{A}}=\frac{1}{g^{2}(\boldsymbol{A})}\left[g(\boldsymbol{A}) \frac{\partial f(\boldsymbol{A})}{\partial \boldsymbol{A}}-f(\boldsymbol{A}) \frac{\partial g(\boldsymbol{A})}{\partial \boldsymbol{A}}\right]
$$



### 2. 标量值函数对矩阵微分

##### 2.1 矩阵微分定义

尽管大多数时候我们想要的是矩阵导数, 但是因为微分形式不变性, 将问题转化为求矩阵 微分会更容易求解.

设 $\boldsymbol{A} \in \mathbb{R}^{m \times n}$, 矩阵 $\boldsymbol{A}$ 的微分定义为
$$
\mathrm{d} \boldsymbol{A}=\left[\begin{array}{cccc}
\mathrm{d} a_{11} & \mathrm{~d} a_{12} & \ldots & \mathrm{~d} a_{1 n} \\
\mathrm{~d} a_{21} & \mathrm{~d} a_{22} & \ldots & \mathrm{~d} a_{2 n} \\
\vdots & \vdots & \ddots & \vdots \\
\mathrm{~d} a_{m 1} & \mathrm{~d} a_{m 2} & \ldots & \mathrm{~d} a_{m n}
\end{array}\right]
$$

设 $\boldsymbol{x} \in \mathbb{R}^{n}$, 向量 $\boldsymbol{x}$ 的微分定义为
$$
\mathrm{d} \boldsymbol{x}=\left[\begin{array}{c}
\mathrm{d} x_{1} \\
\mathrm{~d} x_{2} \\
\vdots \\
\mathrm{~d} x_{n}
\end{array}\right] ; \mathrm{d} \boldsymbol{x}^{\mathrm{T}}=\left[\begin{array}{llll}
\mathrm{d} x_{1} & \mathrm{~d} x_{2} & \ldots & \mathrm{~d} x_{n}
\end{array}\right]
$$

矩阵微分有如下性质
(1) $\mathrm{d}(c \boldsymbol{A})=c \mathrm{~d} \boldsymbol{A}$, 其中 $\boldsymbol{A} \in \mathbb{R}^{n \times m}$
(2) $\mathrm{d}(\boldsymbol{A}+\boldsymbol{B})=\mathrm{d} \boldsymbol{A}+\mathrm{d} \boldsymbol{B}$, 其中 $\boldsymbol{A}, \boldsymbol{B} \in \mathbb{R}^{n \times m}$
(3) $\mathrm{d}(\boldsymbol{A} \boldsymbol{B})=\mathrm{d} \boldsymbol{A} \boldsymbol{B}+\boldsymbol{A} \mathrm{d} \boldsymbol{B}$, 其中 $\boldsymbol{A} \in \mathbb{R}^{n \times m}, \boldsymbol{B} \in \mathbb{R}^{m \times k}$
(4) $\mathrm{d} \boldsymbol{A}^{\mathrm{T}}=(\mathrm{d} \boldsymbol{A})^{\mathrm{T}}$, 其中 $\boldsymbol{A} \in \mathbb{R}^{n \times m}$

> 这些性质都能通过矩阵微分的定义自然推出, 例如对于(3), 注意等式成立需要两边每一个对应元素都相等, 我们考虑两边的第 $i$ 行 $j$ 列的元素, 并记 $\boldsymbol{A}, \boldsymbol{B}$ 对应的元素分别为 $a_{i j}, b_{i j}$ 。
> $$
> \begin{array}{l}
> \text { 左边 }_{i j}=\mathrm{d}\left(\sum_{k} a_{i k} b_{k j}\right) \quad=\sum_{k}\left(\mathrm{~d} a_{i k} b_{k j}+a_{i k} \mathrm{~d} b_{k j}\right) \\
> \text { 右边 }_{i j}=(\mathrm{d} \boldsymbol{A} \boldsymbol{B})_{i j}+(\boldsymbol{A} \mathrm{d} \boldsymbol{B})_{i j}=\sum_{k} \mathrm{~d} a_{i k} b_{k j}+\sum_{k} a_{i k} \mathrm{~d} b_{k j}=\text { 左边 }_{i j}
> \end{array}
> $$
>

微分运算和迹运算可交换, 即设 $\boldsymbol{A} \in \mathbb{R}^{n \times n}$, 则
$$
\mathrm{d} \operatorname{Tr}(\boldsymbol{A})=\operatorname{Tr}(\mathrm{d} \boldsymbol{A})
$$

> 证明.
> $$
> \begin{array}{c}
> \text { 左边 }=\mathrm{d}\left(\sum_{i} a_{i i}\right)=\sum_{i} \mathrm{~d} a_{i i} \\
> \text { 右边 }=\operatorname{Tr}\left[\begin{array}{cccc}
> \mathrm{d} a_{11} & \mathrm{~d} a_{12} & \ldots & \mathrm{~d} a_{1 n} \\
> \mathrm{~d} a_{21} & \mathrm{~d} a_{22} & \ldots & \mathrm{~d} a_{2 n} \\
> \vdots & \vdots & \ddots & \vdots \\
> \mathrm{~d} a_{n 1} & \mathrm{~d} a_{n 2} & \cdots & \mathrm{~d} a_{n n}
> \end{array}\right]=\sum_{i} \mathrm{~d} a_{i i}=\text { 左边 }
> \end{array}
> $$



##### 2.2 矩阵微分和偏导数的关系

回忆多元函数的微分和偏导具有如下关系
$$
\mathrm{d} f\left(x_{1}, x_{2}, \ldots, x_{n}\right)=\dfrac{\partial f}{\partial x_{1}} \mathrm{~d} x_{1}+\frac{\partial f}{\partial x_{2}} \mathrm{~d} x_{2}+\cdots+\frac{\partial f}{\partial x_{n}} \mathrm{~d} x_{n}
$$

这里 $\mathrm{d} f$ 是一个标量, 从分量的角度来看, $\mathrm{d} f$ 就是将 $\dfrac{\partial f}{\partial \boldsymbol{x}}$ 与 $\mathrm{d} \boldsymbol{x}$ 相同位置的元素相乘后再求和, 对于矩阵微分与偏导数有类似的形式

对于实值函数 $f: \mathbb{R}^{n \times m} \rightarrow \mathbb{R}$ 和 $\boldsymbol{A} \in \mathbb{R}^{n \times m}$ 有
$$
\mathrm{d} f=\operatorname{Tr}\left(\left(\dfrac{\partial f}{\partial \boldsymbol{A}}\right)^{\mathrm{T}} \mathrm{~d} \boldsymbol{A}\right)
$$
> 证明.
> $$
> \begin{array}{l}\text { 左边 }=\mathrm{d} f=\displaystyle\sum_{i j} \dfrac{\partial f}{\partial x_{i j}} \mathrm{~d} x_{i j} \\ \text { 右边 }=\operatorname{Tr}\left(\left(\dfrac{\partial f}{\partial \boldsymbol{A}}\right)^{\mathrm{T}} \mathrm{d} \boldsymbol{A}\right)=\displaystyle\sum_{i j}\left(\dfrac{\partial f}{\partial \boldsymbol{A}}\right)_{i j}(\mathrm{~d} \boldsymbol{A})_{i j}=\displaystyle\sum_{i j} \dfrac{\partial f}{\partial x_{i j}} \mathrm{~d} x_{i j}=\text { 左边 }\end{array}
> $$
>



##### 2.3 逆矩阵的微分

由单位矩阵的微分出发, 有$\boldsymbol{O}=\mathrm{d} \boldsymbol{I}=\mathrm{d}\left(\boldsymbol{X} \boldsymbol{X}^{-1}\right)=\mathrm{d} \boldsymbol{X} \boldsymbol{X}^{-1}$, 从而$\mathrm{~d}\left(\boldsymbol{X}^{-1}\right)=-\boldsymbol{X}^{-1} \mathrm{~d}\boldsymbol{X} \boldsymbol{X}^{-1}$.



##### 2.4 行列式的微分

设矩阵 $\boldsymbol{A} \in \mathbb{R}^{n \times n}$ 则有
$$
\dfrac{\partial|\boldsymbol{A}|}{\partial \boldsymbol{A}}
=\left(\boldsymbol{A}^{*}\right)^{\mathrm{T}}
$$

> 证明. 为了计算 $\dfrac{\partial|A|}{\partial A}$, 我们利用定义 5.4.7逐元素进行求导。根据行列式的展开式, 易求得对第 $i$行第 $j$ 列元素 $a_{i j}$ 的偏导数有
> $$
> \dfrac{\partial|\boldsymbol{A}|}{\partial a_{i j}}=\dfrac{\partial\left(\displaystyle\sum_{j} a_{i j} A_{i j}\right)}{\partial a_{i j}}=A_{i j}
> $$
>
> 使用定义 5.4.7来组织元素就有 $\dfrac{\partial|\boldsymbol{A}|}{\partial \boldsymbol{A}}=\left(\boldsymbol{A}^{*}\right)^{\mathrm{T}}$ .

设矩阵 $\boldsymbol{A} \in \mathbb{R}^{n \times n}$ 则有 $\mathrm{d}|\boldsymbol{A}|=\operatorname{Tr}\left(\boldsymbol{A}^{*} \mathrm{~d} \boldsymbol{A}\right)$ 。 当 $\boldsymbol{A}$ 可逆时有 $\mathrm{d}|\boldsymbol{A}|=\operatorname{Tr}\left(|\boldsymbol{A}| \boldsymbol{A}^{-1} \mathrm{~d} \boldsymbol{A}\right)$ .

> 证明.
> $$
> \mathrm{d}|\boldsymbol{A}|=\operatorname{Tr}\left(\left(\dfrac{\partial|\boldsymbol{A}|}{\partial \boldsymbol{A}}\right)^{\mathrm{T}} \mathrm{~d} \boldsymbol{A}\right)=\operatorname{Tr}\left(\boldsymbol{A}^{*} \mathrm{~d} \boldsymbol{A}\right)
> $$
>
> 当 $\boldsymbol{A}$ 可逆时有
> $$
> \mathrm{d}|\boldsymbol{A}|=\operatorname{Tr}\left(\boldsymbol{A}^{*} \mathrm{~d} \boldsymbol{A}\right)=\operatorname{Tr}\left(|\boldsymbol{A}| \boldsymbol{A}^{-1} \mathrm{~d} \boldsymbol{A}\right)
> $$
>



##### 2.5 迹微分法

对于标量函数$\mathrm{d}f = \mathrm{d}(\Tr{f}) = \Tr (\mathrm{d}f)$, 结合矩阵微分和偏导数的关系$\mathrm{d} f=\operatorname{Tr}\left(\left(\dfrac{\partial f}{\partial \boldsymbol{A}}\right)^{\mathrm{T}} \mathrm{~d} \boldsymbol{A}\right)$, 可计算微分并变换成$\operatorname{Tr}(\boldsymbol{X}\mathrm{d}\boldsymbol{A})$的形式求解导数$\dfrac{\partial f}{\partial \boldsymbol{A}} = \boldsymbol{X}^T$.

> 例1. 对$f(\boldsymbol{A})=\operatorname{Tr}(\boldsymbol{A} \boldsymbol{B})$求$\dfrac{\partial f}{\partial \boldsymbol{A}}$.
> $$
> \begin{aligned}
> \mathrm{d} f = \mathrm{d} \operatorname{Tr}\left(AB\right)
> = \operatorname{Tr}\left(B\mathrm{d}A\right)
> \end{aligned}
> $$
> 从而$\dfrac{\partial f}{\partial \boldsymbol{A}} = B^T$.
>
> 
>
> 例2. 给定函数 $f(\boldsymbol{x})=\boldsymbol{x}^{\mathrm{T}} \boldsymbol{A} \boldsymbol{x}$, 其中 $\boldsymbol{A}$ 是一方阵, $\boldsymbol{x}$ 是一列向量, 求$\dfrac{\partial f}{\partial \boldsymbol{x}}$.
> $$
> \begin{aligned}
> \mathrm{d} f & =\mathrm{d} \operatorname{Tr}\left(\boldsymbol{x}^{\mathrm{T}} \boldsymbol{A} \boldsymbol{x}\right) \\
> & =\operatorname{Tr}\left(\mathrm{d}\left(\boldsymbol{x}^{\mathrm{T}} \boldsymbol{A} \boldsymbol{x}\right)\right) \\
> & =\operatorname{Tr}\left(\mathrm{d}\left(\boldsymbol{x}^{\mathrm{T}}\right) \boldsymbol{A} \boldsymbol{x}+\boldsymbol{x}^{\mathrm{T}} \mathrm{~d}(\boldsymbol{A} \boldsymbol{x})\right) \\
> & =\operatorname{Tr}\left(\left(\boldsymbol{x}^{\mathrm{T}} \boldsymbol{A}^{\mathrm{T}}+\boldsymbol{x}^{\mathrm{T}} \boldsymbol{A}\right) \mathrm{d} \boldsymbol{x}\right)
> \end{aligned}
> $$
>
> 从而 $\dfrac{\partial f}{\partial \boldsymbol{x}}=\left(\boldsymbol{x}^{\mathrm{T}} \boldsymbol{A}^{\mathrm{T}}+\boldsymbol{x}^{\mathrm{T}} \boldsymbol{A}\right)^{\mathrm{T}}=\boldsymbol{A} \boldsymbol{x}+\boldsymbol{A}^{\mathrm{T}} \boldsymbol{x}$ .
> 如果 $\boldsymbol{A}$ 是对称矩阵，我们还可以将其简化为 $\dfrac{\partial f}{\partial x}=2 \boldsymbol{A x}$ .
> 令 $\boldsymbol{A}=\boldsymbol{I}$ 我们则有 $\dfrac{\partial\left(\boldsymbol{x}^{\mathrm{T}} \boldsymbol{x}\right)}{\partial \boldsymbol{x}}=2 \boldsymbol{x}$ .
>
> 
>
> 例3. 在 $P C A$ 中, 我们需要求解优化问题
> $$
> \begin{aligned}
> \min _{\boldsymbol{W}} & -\mathrm{Tr}\left(\boldsymbol{W}^{\mathrm{T}} \boldsymbol{X} \boldsymbol{X}^{\mathrm{T}} \boldsymbol{W}\right) \\
> \text { s.t. } & \boldsymbol{W}^{\mathrm{T}} \boldsymbol{W}=\boldsymbol{I}
> \end{aligned}
> $$
>
> 我们现在考虑求梯度 $\nabla_{\boldsymbol{W}}-\operatorname{Tr}\left(\boldsymbol{W}^{\mathrm{T}} \boldsymbol{X} \boldsymbol{X}^{\mathrm{T}} \boldsymbol{W}\right)$ .
> 解. 利用迹微分法有
> $$
> \begin{aligned}
> \mathrm{d}\left(-\operatorname{Tr}\left(\boldsymbol{W}^{\mathrm{T}} \boldsymbol{X} \boldsymbol{X}^{\mathrm{T}} \boldsymbol{W}\right)\right) & =-\operatorname{Tr}\left(\mathrm{d}\left(\boldsymbol{W}^{\mathrm{T}} \boldsymbol{X} \boldsymbol{X}^{\mathrm{T}} \boldsymbol{W}\right)\right) \\
> & =-2 \operatorname{Tr}\left(\boldsymbol{W}^{\mathrm{T}} \boldsymbol{X} \boldsymbol{X}^{\mathrm{T}} \mathrm{~d} \boldsymbol{V}\right)
> \end{aligned}
> $$
>
> 所以 $\nabla_{\boldsymbol{W}}-\operatorname{Tr}\left(\boldsymbol{W}^{\mathrm{T}} \boldsymbol{X} \boldsymbol{X}^{\mathrm{T}} \boldsymbol{W}\right)=-2 \boldsymbol{X} \boldsymbol{X}^{\mathrm{T}} \boldsymbol{W}$ .
>
> 
>
> 例4. 设矩阵 $\boldsymbol{A} \in \mathbb{R}^{n \times n}$ 是一可逆矩阵。求
> $$
> \dfrac{\partial\left|\boldsymbol{A}^{-1}\right|}{\partial \boldsymbol{A}}
> $$
>
> 解.
> $$
> \mathrm{d}\left|\boldsymbol{A}^{-1}\right|=\operatorname{Tr}\left(\left|\boldsymbol{A}^{-1}\right| \boldsymbol{A} \mathrm{d} \boldsymbol{A}^{-1}\right)=\operatorname{Tr}\left(-\left|\boldsymbol{A}^{-1}\right| \boldsymbol{A} \boldsymbol{A}^{-1} \mathrm{~d} \boldsymbol{A} \boldsymbol{A}^{-1}\right)=\operatorname{Tr}\left(-\left|\boldsymbol{A}^{-1}\right| \boldsymbol{A}^{-1} \mathrm{~d} \boldsymbol{A}\right)
> $$
>
> 故
> $$
> \dfrac{\partial\left|\boldsymbol{A}^{-1}\right|}{\partial \boldsymbol{A}}
> =-\left|\boldsymbol{A}^{-1}\right| \boldsymbol{A}^{-\mathrm{T}}=-|\boldsymbol{A}|^{-1} \boldsymbol{A}^{-\mathrm{T}}
> $$

某些情况需要通过变换以生成迹的形式, 例如含$F$范数或向量2范数的函数.

> 例1. 设 $\boldsymbol{A} \in \mathbb{R}^{n \times m}$, 求 $\dfrac{\partial\|\boldsymbol{A}\|_{F}^{2}}{\partial \boldsymbol{A}}$, 其中 $\|\boldsymbol{A}\|_{F}=\sqrt{\displaystyle\sum_{i=1}^{n} \displaystyle\sum_{j=1}^{m} a_{i j}^{2}}$
> 解.
> $$
> \mathrm{d}\|\boldsymbol{A}\|_{F}^{2}=\mathrm{d} \operatorname{Tr}\left(\boldsymbol{A}^{\mathrm{T}} \boldsymbol{A}\right)=\operatorname{Tr}\left((\mathrm{d} \boldsymbol{A})^{\mathrm{T}} \boldsymbol{A}\right)+\operatorname{Tr}\left(\boldsymbol{A}^{\mathrm{T}} \mathrm{~d} \boldsymbol{A}\right)=\operatorname{Tr}\left(2 \boldsymbol{A}^{\mathrm{T}} \mathrm{~d} \boldsymbol{A}\right)
> $$
>
> 故
> $$
> \dfrac{\partial\|\boldsymbol{A}\|_{F}^{2}}{\partial \boldsymbol{A}}=2 \boldsymbol{A}
> $$
>
> 例2. 在机器学习中, 经常需要计算模型的预测值与真实值的误差, 常用向量的 $l_{2}$ 范数度量, 然后通过梯度下降进行优化. 现得到如下误差函数, 求其对应的梯度。
> (1) $f(\boldsymbol{A})=\dfrac{1}{2}\|\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b}-\boldsymbol{y}\|_{2}^{2}$, 求 $\dfrac{\partial f}{\partial \boldsymbol{A}}$.
>
> (2) $f(\boldsymbol{x})=\dfrac{1}{2}\|\boldsymbol{A x}+\boldsymbol{b}-\boldsymbol{y}\|_{2}^{2}$, 求 $\dfrac{\partial f}{\partial \boldsymbol{x}}$.



##### 2.6 链式法则

> 例1. 考虑线性回归中的优化问题: $\min _{\boldsymbol{\theta}} \displaystyle\sum_{i=1}^{n}\left(\boldsymbol{\theta}^{\mathrm{T}} \boldsymbol{x}_{i}-y_{i}\right)^{2}$ 。我们将其目标函数改写成 $\|\boldsymbol{X} \boldsymbol{\theta}-\boldsymbol{y}\|_{2}^{2}$ 并关于 $\boldsymbol{\theta}$ 求梯度, 其中
> $$
> \boldsymbol{X}=\left[\begin{array}{llll}\boldsymbol{x}_{1} & \boldsymbol{x}_{2} & \cdots & \boldsymbol{x}_{n}\end{array}\right]^{\mathrm{T}}, \boldsymbol{y}=\left(y_{1}, y_{2}, \ldots, y_{n}\right)
> $$
> 解. 由链式法则
> $$
> \begin{aligned}
> & \nabla_{\boldsymbol{\theta}}\|\boldsymbol{X} \boldsymbol{\theta}-\boldsymbol{y}\|_{2}^{2} \\
> = & \dfrac{\partial(\boldsymbol{X} \boldsymbol{\theta}-\boldsymbol{y})^{\mathrm{T}}}{\partial \boldsymbol{\theta}} \dfrac{\partial\|\boldsymbol{z}\|_{2}^{2}}{\partial \boldsymbol{z}}, \quad \text { 其中 } \boldsymbol{z}=\boldsymbol{X} \boldsymbol{\theta}-\boldsymbol{y} \\
> = & \boldsymbol{X}^{\mathrm{T}} \dfrac{\partial \boldsymbol{z}^{\mathrm{T}} \boldsymbol{z}}{\partial \boldsymbol{z}}= 2 \boldsymbol{X}^{\mathrm{T}} \boldsymbol{z}=2 \boldsymbol{X}^{\mathrm{T}} \boldsymbol{X} \boldsymbol{\theta}-\boldsymbol{X}^{\mathrm{T}} \boldsymbol{y}
> \end{aligned}
> $$
>
> 例2. 计算 $(\boldsymbol{x}-\boldsymbol{\mu})^{\mathrm{T}} \boldsymbol{\Sigma}^{-1}(\boldsymbol{x}-\boldsymbol{\mu})$ 关于 $\boldsymbol{\mu}$ 的导数，其中 $\boldsymbol{\Sigma}^{-1}$ 是对称矩阵.
>
> 解. 由链式法则
> $$
> \begin{aligned}
> & \dfrac{\partial\left((\boldsymbol{x}-\boldsymbol{\mu})^{\mathrm{T}} \boldsymbol{\Sigma}^{-1}(\boldsymbol{x}-\boldsymbol{\mu})\right)}{\partial \boldsymbol{\mu}} \\
> = & \dfrac{\partial\left[(\boldsymbol{x}-\boldsymbol{\mu})^{\mathrm{T}}\right]}{\partial \boldsymbol{\mu}} \dfrac{\partial\left((\boldsymbol{x}-\boldsymbol{\mu})^{\mathrm{T}} \boldsymbol{\Sigma}^{-1}(\boldsymbol{x}-\boldsymbol{\mu})\right)}{\partial[\boldsymbol{x}-\boldsymbol{\mu}]} \\
> = & -2 \boldsymbol{\Sigma}^{-1}(\boldsymbol{x}-\boldsymbol{\mu})
> \end{aligned}
> $$



##### 2.7 习题

> 在利用极大似然估计求解多元正态分布模型时, 通常需要对期望向量和协方差矩阵求梯度。现已知对数似然函数：
> $$
> L=-\frac{N d}{2} \ln (2 \pi)-\frac{N}{2} \ln |\boldsymbol{\Sigma}|-\frac{1}{2} \sum_{t}\left(\boldsymbol{x}_{t}-\boldsymbol{\mu}\right)^{\mathrm{T}} \boldsymbol{\Sigma}^{-1}\left(\boldsymbol{x}_{t}-\boldsymbol{\mu}\right)
> $$
>
> 其中 $N$ 为样本数, $d$ 为样本维数, $\boldsymbol{\Sigma} \in \mathbb{R}^{d \times d}$ 为协方差矩阵, $\boldsymbol{\mu} \in \mathbb{R}^{d}$ 为期望向量。
> (1) 求 $\dfrac{\partial L}{\partial \mu}$;
> (2) 当 $\boldsymbol{\mu}=\dfrac{1}{N} \displaystyle\sum_{t} \boldsymbol{x}_{t}$ 时, 求 $\dfrac{\partial L}{\partial \boldsymbol{\Sigma}}$ 。并求 $\boldsymbol{\Sigma}$ 使得 $\dfrac{\partial L}{\partial \boldsymbol{\Sigma}}=\boldsymbol{O}$ 。



### 3. 向量值函数微分

对于函数 $\boldsymbol{f}: \mathbb{R}^{n} \rightarrow \mathbb{R}^{m}$ 和一个向量 $\boldsymbol{x}=\left(x_{1}, x_{2}, \ldots, x_{n}\right) \in \mathbb{R}^{n}$, 对应的函数值为
$$
\boldsymbol{f}(\boldsymbol{x})=\left(f_{1}(\boldsymbol{x}), \ldots, f_{m}(\boldsymbol{x})\right) \in \mathbb{R}^{m}
$$

一个向量值函数 $\boldsymbol{f}: \mathbb{R}^{n} \rightarrow \mathbb{R}^{m}$就相当于一个函数的向量 $\left(f_{1}, f_{2}, \ldots, f_{m}\right)$,其中 $f_{i}: \mathbb{R}^{n} \rightarrow \mathbb{R}$.

向量值函数 $\boldsymbol{f}$ 关于 $x_{i}$ 的偏导数
$$
\dfrac{\partial \boldsymbol{f}}{\partial x_{i}}=\left[\begin{array}{c}
\dfrac{\partial f_{1}}{\partial x_{i}} \\
\ldots \\
\dfrac{\partial f_{m}}{\partial x_{i}}
\end{array}\right]=\left[\begin{array}{c}
\lim _{h \rightarrow 0} \dfrac{f_{1}\left(x_{1}, \ldots, x_{i-1}, x_{i}+h, x_{i+1}, \ldots, x_{m}\right)-f_{1}(\boldsymbol{x})}{h} \\
\vdots \\
\lim _{h \rightarrow 0} \dfrac{f_{m}\left(x_{1}, \ldots, x_{i-1}, x_{i}+h, x_{i+1}, \ldots, x_{m}\right)-f_{m}(\boldsymbol{x})}{h}
\end{array}\right]
$$
在上式中, 每一个偏导都是一个列向量. 因此, 我们转置$x$从而将向量值函数 $\boldsymbol{f}(\boldsymbol{x}): \mathbb{R}^{n} \rightarrow \mathbb{R}^{m}$ 的所有一阶导数组成$m\times n$矩阵, 称为 Jacobian 矩阵
$$
\dfrac{\partial \boldsymbol{f}(\boldsymbol{x})}{\partial \boldsymbol{x}^{\mathrm{T}}}=\left[\begin{array}{lll}
\dfrac{\partial f(\boldsymbol{x})}{\partial x_{1}} & \ldots & \dfrac{\partial \boldsymbol{f}(\boldsymbol{x})}{\partial x_{n}}
\end{array}\right]=\left[\begin{array}{ccc}
\dfrac{\partial f_{1}(\boldsymbol{x})}{\partial x_{1}} & \ldots & \dfrac{\partial f_{1}(\boldsymbol{x})}{\partial x_{n}} \\
\vdots & & \vdots \\
\dfrac{\partial f_{m}(\boldsymbol{x})}{\partial x_{1}} & \ldots & \dfrac{\partial f_{m}(\boldsymbol{x})}{\partial x_{n}}
\end{array}\right]
$$

并且定义
$$
\dfrac{\partial \boldsymbol{f}(\boldsymbol{x})^{\mathrm{T}}}{\partial \boldsymbol{x}}=\boldsymbol{J}^{\mathrm{T}}=\left(\dfrac{\partial \boldsymbol{f}(\boldsymbol{x})}{\partial \boldsymbol{x}^{\mathrm{T}}}\right)^{\mathrm{T}}
$$

注意我们没有定义 $\dfrac{\partial f(x)}{\partial x}$ 以及 $\dfrac{\partial f(x)^{\mathrm{T}}}{\partial x^{T}}$ , 所以在后面的讨论中不会出现这两种情况. 在计算中也需要注意所计算的形式是否已经被定义.

求矩阵关于向量或其它矩阵的梯度, 通常会导致一个多维张量. 例如, 我们计算一个 $m \times n$矩阵关于 $p \times q$ 矩阵的梯度, 相应的 Jacobian 是 $(p \times q) \times(m \times n)$, 这是一个四维的张量. 为了直观理解, 我们可以将矩阵展成向量的形式考虑这一问题. 定义函数 $\mathrm{vec}: \mathbb{R}^{n \times m} \rightarrow \mathbb{R}^{n m}$ 将一个矩阵按列重排成一个列向量, 定义如下. 设 $\boldsymbol{A}=\left[\begin{array}{llll}\boldsymbol{a}_{1} & \boldsymbol{a}_{2} & \ldots & \boldsymbol{a}_{m}\end{array}\right] \in \mathbb{R}^{i \times m}$ 则

$$
\operatorname{vec}(\boldsymbol{A})=\left[\begin{array}{c}
\boldsymbol{a}_{1} \\
\boldsymbol{a}_{2} \\
\vdots \\
\boldsymbol{a}_{m}
\end{array}\right]
$$

有了这样一函数之后, 我们就可以定义矩阵关于矩阵梯度的 Jacobian 矩阵. 设矩阵函数 $\boldsymbol{F}(\boldsymbol{X}): \mathbb{R}^{n \times m} \rightarrow \mathbb{R}^{q \times p}$ 则其 Jacobian 矩阵定义为
$$
\boldsymbol{J}=\dfrac{\partial \operatorname{vec}(\boldsymbol{F}(\boldsymbol{X}))}{\partial \operatorname{vec}(\boldsymbol{X})^{\mathrm{T}}}=\left[\begin{array}{cccc}
\dfrac{\partial f_{11}}{\partial x_{11}} & \dfrac{\partial f_{11}}{\partial x_{12}} & \cdots & \dfrac{\partial f_{11}}{\partial x_{n m}} \\
\dfrac{\partial f_{12}}{\partial x_{11}} & \dfrac{\partial f_{12}}{\partial x_{12}} & \cdots & \dfrac{\partial f_{12}}{\partial x_{n m}} \\
\vdots & \vdots & & \vdots \\
\dfrac{\partial f_{p q}}{\partial x_{11}} & \dfrac{\partial f_{p q}}{\partial x_{12}} & \cdots & \dfrac{\partial f_{p q}}{\partial x_{n m}}
\end{array}\right]
$$

其行列式 $J=|\boldsymbol{J}|$ 称为 Jacobian 行列式.

对向量函数 $\boldsymbol{f}(\boldsymbol{x}): \mathbb{R}^{m} \rightarrow \mathbb{R}^{n}, \boldsymbol{x} \in \mathbb{R}^{m}$ , 同样存在向量微分和偏导数(Jacobian矩阵)的关系
$$
\mathrm{d} \boldsymbol{f}=\left(\dfrac{\partial \boldsymbol{f}^{T}}{\partial \boldsymbol{x}}\right)^{\mathrm{T}} \mathrm{d} \boldsymbol{x}=\boldsymbol{J} \mathrm{d} \boldsymbol{x}
$$
> 证明. 显然, $\mathrm{d} \boldsymbol{f}$ 有 $n$ 个分量, 所以我们从分量的角度来证明。考虑第 $j$ 个分量.
> $$
> \begin{array}{l}
> \text { 左边 }_{j}=\mathrm{d} f_{j}=\displaystyle\sum_{i=1}^{m} \dfrac{\partial f_{j}}{\partial x_{i}} \mathrm{~d} x_{i} \\
> \text { 右边 }_{j}=\left(\left(\dfrac{\partial \boldsymbol{f}}{\partial \boldsymbol{x}}\right)^{\mathrm{T}} \mathrm{~d} x\right)_{j}=\displaystyle\sum_{i=1}^{m}\left(\dfrac{\partial \boldsymbol{f}^{\mathrm{T}}}{\partial \boldsymbol{x}}\right)_{i j} \mathrm{~d} x_{i}=\displaystyle\sum_{i=1}^{m}\left(\dfrac{\partial f_{j}}{\partial x_{i}}\right) \mathrm{d} x_{i}=\text { 左边 }_{j}
> \end{array}
> $$
>
> 利用定理 5.7.1, 仿照求解实值函数梯度的步骤, 可以简化求解向量对向量的导数.

如果 $\boldsymbol{f}$ 和 $\boldsymbol{x}$ 维数相同，则 $\left(\dfrac{\partial f^{T}}{\partial x}\right)^{-1}=\dfrac{\partial x^{T}}{\partial f}$ .

> 证明.
> $$
> \mathrm{d} \boldsymbol{f}=\left(\dfrac{\partial \boldsymbol{f}^{\mathrm{T}}}{\partial \boldsymbol{x}}\right)^{\mathrm{T}} \mathrm{~d} \boldsymbol{x} \Longrightarrow\left(\left(\dfrac{\partial \boldsymbol{f}^{\mathrm{T}}}{\partial \boldsymbol{x}}\right)^{\mathrm{T}}\right)^{-1} \mathrm{~d} \boldsymbol{f}=\mathrm{d} \boldsymbol{x} \Longrightarrow \mathrm{~d} \boldsymbol{x}=\left(\left(\dfrac{\partial \boldsymbol{f}^{\mathrm{T}}}{\partial \boldsymbol{x}}\right)^{-1}\right)^{\mathrm{T}} \mathrm{~d} \boldsymbol{f}
> $$
>
> 所以, 我们就有 $\dfrac{\partial x^{\mathrm{T}}}{\partial f}=\left(\dfrac{\partial f^{T}}{\partial x}\right)^{-1}$ .
>
> 这个结果和标量导数是一致的. 这个结论对于变量替换很有用.

