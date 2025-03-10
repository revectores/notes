# Linear Space

### 1. Linear Space

##### 1.1 Linear Space Definition

设非空集合 $V$ 和数域 $K$ ，在 $V$ 中定义一个加法运算使得对于任意的 $\boldsymbol{x}, \boldsymbol{y} \in V$ 时有唯一的和 $\boldsymbol{x}+\boldsymbol{y} \in V$ ，并且加法运算满足以下四条运算律

1. 交换律 $\boldsymbol{x}+\boldsymbol{y}=\boldsymbol{y}+\boldsymbol{x}$
2. 结合律 $\boldsymbol{x}+(\boldsymbol{y}+\mathbf{z})=(\boldsymbol{x}+\boldsymbol{y})+\boldsymbol{z}$
3. 存在零元素 $0 \in V$ 使得 $\boldsymbol{x}+\mathbf{0}=\boldsymbol{x}$
4. 存在负元素。即对于任意 $\boldsymbol{x} \in V$ 存在 $\boldsymbol{y} \in V$ 使得 $\boldsymbol{x}+\boldsymbol{y}=\mathbf{0}$ 。此时 $\boldsymbol{y}$ 称为 $\boldsymbol{x}$ 的负元素，记作 $-x$ 。因此有 $\boldsymbol{x}+(-\boldsymbol{x})=0$

在 $V$ 中定义数乘运算（数和向量的乘法，数即数域 $K$ 中的元素，向量即向量集合 $V$ 中的元素），对任意的 $\boldsymbol{x} \in V, k \in K$ ，有唯一的 $k \boldsymbol{x} \in V$ 并满足以下运算性质：

5. 数因子分配律 $k(\boldsymbol{x}+\boldsymbol{y})=k \boldsymbol{x}+k \boldsymbol{y}$
6. 分配律 $(k+l) \boldsymbol{x}=k \boldsymbol{x}+l \boldsymbol{x}$
7. 结合律 $k(l \boldsymbol{x})=(k l)$
8. 存在单位元使得 $1 \boldsymbol{x}=\boldsymbol{x}$

则称 $V$ 为数域 $K$ 上的线性空间或向量空间。在不致产生混淆时省略说明数域 $K$ ，简称为线性空间. $V$ 中的元素称为向量. $V$ 中所定义的加法和数乘运算统称为 $V$ 的线性运算.

不论 $V$ 的元素如何，当 $K=\mathbf{R}$ 时称 $V$ 为实线性空间；当 $K=\mathbf{C}$ 时称 $V$ 为复线性空间。
几个线性空间的实例：
EG1. 次数不超过 n 的多项式的全体对通常的多项式加法、数乘多项式的乘法在实数域上构成线性空间。

值得注意的是， n 次多项式的全体在实数域上并不能构成向量空间。例如以 0 作为数乘的因子时，所得的结果次数立刻降为 0 ，因而对数乘运算不封闭。又或者两个最高次 $(n)$ 互为相反数的向量相加所得结果次数会降到（ $n-1$ ），因而对通常的加法运算也不封闭。为了构成线性空间，必须能够容忍降次的风险。
EG2. 正弦函数的集合 $S=\{s=A \sin (x+B) \mid A, B \in R\}$ 对于通常的函数加法和数乘函数的乘法构成线性空间。
EG3. 常系数二阶齐次线性微分方程 $y^{\prime \prime}-3 y^{\prime}+2 y$ 的解集对函数加法和数乘函数的乘法构成线性空间。
EG4. 所有 n 阶实矩阵的集合 $\mathbf{R}^{n \times n}$ 对于矩阵加法和数乘矩阵的乘法构成线性空间。
EG5. 所有 n 阶复矩阵的集合 $\mathbf{C}^{n \times n}$ 对于矩阵加法和数乘矩阵的乘法在 $\mathbf{C}$ 上构成线性空间。

##### 1.2. Linear Space Property

性质1. 零向量是唯一的
Prov. 假设线性空间中有两个零向量 $\mathbf{0}_{\mathbf{1}}, \mathbf{0}_{2}$ ，由零元素的定义和交换律的成立有

$$
0_{1}=0_{1}+0_{2}=0_{2}+0_{1}=0_{2}
$$

因此 $\mathbf{0}_{1}=\mathbf{0}_{2}$. 即零向量是唯一的

性质2. 任意向量的负向量是唯一的
Prov. 假设向量 $\boldsymbol{x}$ 有两个负向量 $\boldsymbol{x}_{1}, \boldsymbol{x}_{2}$ ，有

$$
x+x_{1}=\mathbf{0}, \quad x+x_{2}=\mathbf{0}
$$

由分配律

$$
x_{1}=x_{1}+0=x_{1}+\left(x+x_{2}\right)=\left(x_{1}+x\right)+x_{2}=x_{2}
$$

从而 $x_{1}=x_{2}$, 因此 $x$ 的负向量是唯一的.

性质 3. $0 \boldsymbol{x}=\mathbf{0},(-1) \boldsymbol{x}=-\boldsymbol{x}, k \mathbf{0}=\mathbf{0}$