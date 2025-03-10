# Optimization Problem

### 1.1 General Form of Optimization Problem

优化问题的一般形式表示为
$$
\begin{array}{ll}
\min & f_{0}(\boldsymbol{x}) \\
\text { s.t. } & f_{i}(\boldsymbol{x}) \leq 0, i=1, \cdots, m \\
& h_{j}(\boldsymbol{x})=0, j=1, \cdots, p
\end{array}
$$

其中, 向量 $\boldsymbol{x}=\left(x_{1}, \cdots, x_{n}\right)^{\mathrm{T}}$ 称为问题的优化变量, 函数 $f_{0}: \mathbb{R}^{n} \rightarrow \mathbb{R}$ 称为目标函数, 在机器学习中常为损失函数. 函数 $f_{i}: \mathbb{R}^{n} \rightarrow \mathbb{R}$, 被称为不等式约束函数, $f_{i}(\boldsymbol{x}) \leq 0, i=1, \cdots, m$ 称为不等式约束, 函数 $h_{j}: \mathbb{R}^{n} \rightarrow \mathbb{R}$ , 被称为等式约束函数,  $h_{j}(\boldsymbol{x})=0, j=1, \cdots, p$ 称为等式约束.

这一标准形式总是可以得到的. 按照惯例, 不等式和等式约束的右端非零时, 可以通过对任何非零右端进行移项得到. 类似地, 我们将 $f_{i}(\boldsymbol{x}) \geq 0$ 表示为 $-f_{i}(\boldsymbol{x}) \leq 0$ .

另外, 对于如下极大化问题
$$
\begin{array}{cl}
\max & f_{0}(\boldsymbol{x}) \\
\text { s.t. } & f_{i}(\boldsymbol{x}) \leq 0, i=1, \cdots, m \\
& h_{j}(\boldsymbol{x})=0, j=1, \cdots, p
\end{array}
$$

可以通过在同样的约束下极小化 $-f_{0}$ 得到求解.

目标函数和约束函数所有有定义点的集合
$$
\mathcal{D}=\bigcap_{i=0}^{m} \operatorname{dom} f_{i} \cap \bigcap_{j=1}^{p} \operatorname{dom} h_{j}
$$

称满足所有约束条件的向量 $\boldsymbol{x} \in \mathcal{D}$ 为可行解或可行点, 全体可行点的集合称为可行集, 记为 $\mathcal{F}$,其表示为:
$$
\mathcal{F}=\left\{\boldsymbol{x} \in \mathcal{D} \mid f_{i}(\boldsymbol{x}) \leq 0, i=1, \cdots, m_{,} h_{j}(\boldsymbol{x})=0, j=1, \cdots, p\right\}
$$

若 $f_{i}(\boldsymbol{x})$ 和 $h_{j}(\boldsymbol{x})$ 是连续函数, 则 $\mathcal{F}$ 是闭集. 在可行集中找一点 $\boldsymbol{x}^{*}$ , 使目标函数 $f_{0}(\boldsymbol{x})$ 在该点取最小值, 则称 $x^{*}$ 为问题的最优点或最优解, $f_{0}\left(\boldsymbol{x}^{*}\right)$ 称为最优值, 记为 $p^{*}$ :
$$
p^{*}=\inf \left\{f_{0}(\boldsymbol{x}) \mid f_{i}(\boldsymbol{x}) \leq 0, i=1, \cdots, m, h_{j}(\boldsymbol{x})=0, j=1, \cdots, p\right\}
$$

- $p^{*}=\infty$, 如果问题不可行 (没有 $\boldsymbol{x}$ 满足约束)
- $p^{*}=-\infty$, 问题无下界

优化问题可以看成在向量空间 $\mathbb{R}^{n}$ 的备选解集中选择最好的解. 用 $\boldsymbol{x}$ 表示备选解,  $f_{i}(\boldsymbol{x}) \leq$ $b_{i}$ 和 $h_{j}(\boldsymbol{x})=0$ 表示 $\boldsymbol{x}$ 必须满足的条件, 目标函数 $f_{0}(\boldsymbol{x})$ 表示选择 $\boldsymbol{x}$ 的成本(同理也可以认为 $-f_{0}(\boldsymbol{x})$ 表示选择 $\boldsymbol{x}$ 的效益或者效用). 优化问题的解即为满足约束条件的所有备选解中成本最小(或者效用最大)的解.



### 1.2 Classification of Optimization Problem

**连续优化与离散优化**. 决策变量定义域为离散集合的优化问题为离散优化(discrete optimization), 为连续集合的的优化问题为连续优化(continuous optimization). 也存在混合情况, 即一部分决策变量定义域为离散集合, 另一部分变量定义域为连续区间.

常见的离散优化研究领域例如整数规划和组合优化. **整数规划**(Integer Programming)是一类常见的离散优化问题, 输入变量 $\boldsymbol{x} \in \mathbb{Z}^{d}$ 为整数向量. 常见的整数规划问题通常为整数线性规划(Integer Linear Programming, ILP). **组合优化**(Combinatorial Optimization)是从一个有限集合中找出使得目标函数最优的元素.

离散优化问题的求解一般都比较困难, 优化算法的复杂度都比较高. 在连续优化问题中, 基于决策变量取值空间以及约束和目标函数的连续性, 可根据某点邻域内的取值信息来判断该点是否最优. 离散优化问题不具备该性质. 因此通常将离散优化问题转化为一系列连续优化问题来求解.

**无约束优化和约束优化**. 根据是否有变量的约束条件, 可以将优化问题分为无约束优化问题和约束优化问题. 无约束优化问题 (Unconstrained Optimization)的决策变量没有约束条件限制, 即可行域为整个实数域 $\mathbb{R}^{d}$ . 在优化问题的定义中, 如果不存在任何不等式约束 $f_{i}(\boldsymbol{x}) \leq b_{i}$ 和等式约束 $h_{j}(\boldsymbol{x})=0$, 即为无约束优化问题, 否则是约束优化问题.

**随机优化和确定性优化**. 随机优化问题(Stochastic Optimization)是指目标或约束函数中涉及随机变量, 只能知道参数的某些估计, 而带有不确定性的问题. 确定性优化问题(Deterministic Optimization)是指目标和约束函数都是确定的优化问题. 许多确定性优化算法都有相应的随机版本, 使得在特定问题上具有更低的计算复杂度和更好的收敛性质.

**线性规划和非线性规划**. 若目标函数和所有的约束函数都为线性函数, 则该问题为线性规划问题(Linear Programming). 线性规划问题在约束优化问题中具有较为简单的形式, 最流行的两类求解方法为单纯形法和内点法. 如果目标函数或任何一个约束函数为非线性函数, 为非线性规划问题(Nonlinear Programming).

**凸优化与非凸优化**. 凸优化问题是一种特殊的约束优化问题, 需满足: (1)目标函数为凸函数, (2)等式约束函数为线性函数, (3)不等式约束函数为凸函数. 在凸优化问题中, 任意局部最优解都是全局最优解, 因此算法设计和理论分析上比非凸优化问题简单很多. 

