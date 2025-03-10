# Convex Set and Convex Function

### 1. Affine Set

如果通过集合 $\mathbb{C} \subseteq \mathbb{R}^{n}$ 中任意两点的直线仍然在集合 $\mathbb{C}$ 中, 则称 $\mathbb{C}$ 为仿射集. 即
$$
\boldsymbol{x}_{1}, \boldsymbol{x}_{2} \in \mathbb{C} \Rightarrow \theta \boldsymbol{x}_{1}+(1-\theta) \boldsymbol{x}_{2} \in \mathbb{C}, \forall \theta \in \mathbb{R}
$$

可以归纳得出: 一个仿射集包含其中任意点的仿射组合. 如果 $\mathbb{C}$ 是一个仿射集并且 $\boldsymbol{x}_{0} \in \mathbb{C}$,则集合
$$
\mathbb{V}=\mathbb{C}-\boldsymbol{x}_{0}=\left\{\boldsymbol{x}-\boldsymbol{x}_{0} \mid \boldsymbol{x} \in \mathbb{C}\right\}
$$

是一个子空间, 即关于加法和数乘是封闭的. 因此, 仿射集 $\mathbb{C}$ 可以表为
$$
\mathbb{C}=\mathbb{V}+\boldsymbol{x}_{0}=\left\{\boldsymbol{v}+\boldsymbol{x}_{0} \mid \boldsymbol{v} \in \mathbb{V}\right\}
$$

即一个子空间加上一个偏移. 与仿射集 $\mathbb{C}$ 相关联的子空间 $\mathbb{V}$ 与 $x_{0}$ 的选取无关, 所以 $x_{0}$ 可以是 $\mathbb{C}$ 中的任意一点. 我们定义仿射集 $\mathbb{C}$ 的维数为子空间 $\mathbb{V}=\mathbb{C}=\boldsymbol{x}_{0}$ 的维数, 其中 $\boldsymbol{x}_{0}$ 是 $\mathbb{C}$ 中的任意元素.

> 例. 线性方程组的解集 $\mathbb{C}=\{\boldsymbol{x} \mid \boldsymbol{A} \boldsymbol{x}=\boldsymbol{b}\}$ 是一个仿射集合, 其中 $\boldsymbol{A} \in \mathbb{R}^{m \times n}, \boldsymbol{b} \in \mathbb{R}^{m}$ . 这是因为对任意$\boldsymbol{x}_{1}, \boldsymbol{x}_{2} \in \mathbb{C}$, 有$\boldsymbol{A} \boldsymbol{x}_{1}=\boldsymbol{b}, \boldsymbol{A} \boldsymbol{x}_{2}=\boldsymbol{b}$ . 对于任意 $\theta$有
> $$
> \boldsymbol{A}\left(\theta \boldsymbol{x}_{1}+(1-\theta) \boldsymbol{x}_{2}\right)=\theta \boldsymbol{A} \boldsymbol{x}_{1}+(1-\theta) \boldsymbol{A} \boldsymbol{x}_{2}=\theta \boldsymbol{b}+(1-\theta) \boldsymbol{b}=\boldsymbol{b}
> $$
> 这表明任意的仿射组合 $\theta \boldsymbol{x}_{1}+(1-\theta) \boldsymbol{x}_{2}$ 也在仿射集合 $\mathbb{C}$ 中.


我们称由集合 $\mathbb{C} \subseteq \mathbb{R}^{n}$ 中的点的所有仿射组合组成的集合为 $\mathbb{C}$ 的仿射包, 记为 $\bold{aff} \mathbb{C}$ :
$$
\bold{a f f} \mathbb{C}=\left\{\theta_{1} \boldsymbol{x}_{1}+\cdots+\theta_{k} \boldsymbol{x}_{k} \mid x_{1}, \cdots, \boldsymbol{x}_{k} \in \mathbb{C}, \theta_{1}+\cdots+\theta_{k}=1\right\}
$$

仿射包是包含 $\mathbb{C}$ 的最小的仿射集合, 也就是说: 如果 $\mathbb{S}$ 是满足 $\mathbb{C} \subseteq \mathbb{S}$ 的仿射集合, 那么 $\operatorname{aff} \mathbb{C} \subseteq \mathbb{S}$ . 例如下图展示了 $\mathbb{R}^{3}$ 中圆盘 $\mathbb{S}$ 的仿射包, 为一个平面.

<img src="https://images-1258882488.cos.ap-shanghai.myqcloud.com/affine-hull.png" alt="affine-hull" style="zoom:20%;" />



### 2. Convex Set

如果连接集合 $\mathbb{C}$ 中任意两点的线段都在 $\mathbb{C}$ 内, 则称 $\mathbb{C}$ 为**凸集**, 即
$$
\boldsymbol{x}_{1}, \boldsymbol{x}_{2} \in \mathbb{C} \Rightarrow \theta \boldsymbol{x}_{1}+(1-\theta) \boldsymbol{x}_{2} \in \mathbb{C}, \forall 0 \leq \theta \leq 1
$$

仿射集是凸集.

<img src="https://images-1258882488.cos.ap-shanghai.myqcloud.com/convex-set-example.png" alt="convex-set-example" style="zoom:20%;" />

如图, 包含其边界的六边形是凸的, 中(中肾形集合不是凸的, 因为图中所示集合中两点间的线段不为集合所包含; (右)仅包含部分边界的正方形不是凸的.

形如
$$
\boldsymbol{x}=\theta_{1} \boldsymbol{x}_{1}+\cdots+\theta_{k} \boldsymbol{x}_{k}, 1=\theta_{1}+\theta_{2}+\cdots+\theta_{k}, \theta_{i} \geq 0, i=1,2, \cdots, k
$$

的点称为 $x_{1}, \cdots, x_{k}$ 的**凸组合**. 集合 $\mathbb{C}$ 中点所有可能的凸组合构成的集合称作 $\mathbb{C}$ 的凸包, 记作 $\operatorname{conv} \mathbb{C}$ .

点的凸组合可以看做是这些点的混合或加权平均,  $\theta_{i}$ 代表混合时 $\boldsymbol{x}_{i}$ 所占的份数. 凸包是包含 $\mathbb{C}$ 的最小的凸集. 即 $\operatorname{conv} \mathbb{C} \subseteq \mathbb{B}$.

如果对于任意 $\boldsymbol{x} \in \mathbb{C}$ 和 $\theta \geq 0$ 都有 $\theta \boldsymbol{x} \in \mathbb{C}$, 我们称集合 $\mathbb{C}$ 是锥. 形如 $\boldsymbol{x}=$ $\theta_{1} \boldsymbol{x}_{1}+\theta_{2} \boldsymbol{x}_{2} \in \mathbb{C}, \theta_{1} \geq 0, \theta_{2} \geq 0$ 的点称为点 $\boldsymbol{x}_{1}, \boldsymbol{x}_{2}$ 的锥组合. 若集合 $\mathbb{C}$ 中任意点的锥组合都在 $\mathbb{C}$中, 则称 $\mathbb{C}$ 为凸锥.




### 3. Examples of Convex Set

常见的凸集的实例如

- 空集, 任意一个点(即单点集) $\left\{\boldsymbol{x}_{0}\right\}$ 、全空间 $\mathbb{R}^{n}$ 都是 $\mathbb{R}^{n}$ 的仿射(自然也是凸的)子集.
- 任意直线是仿射的. 如果直线通过零点, 则是子空间, 因此, 也是凸锥.
- 一条线段是凸的, 但不是仿射的(除非退化为一个点).
- 一条射线, 即具有形式$\left\{\boldsymbol{x}_{0}+\theta \boldsymbol{v} \mid \theta \geq 0\right\}, \boldsymbol{v} \neq \mathbf{0}$ 的集合, 是凸的, 但不是仿射的. 如果射线的基点 $x_{0}$ 是 0 , 则它是凸锥.
- 任意子空间是仿射的, 也是凸的.
- 凸锥.
- 超平面与半空间. 任取非零向量 $\boldsymbol{a}$, 形如 $\left\{\boldsymbol{x} \mid \boldsymbol{a}^{\mathrm{T}} \boldsymbol{x}=b\right\}$ 的集合称为超平面, 形如 $\left\{\boldsymbol{x} \mid \boldsymbol{a}^{\mathrm{T}} \boldsymbol{x} \leq b\right\}$ 的集合称为半空间. 其中 $\boldsymbol{a} \in \mathbb{R}^{n}, \boldsymbol{a} \neq \mathbf{0}$ 是对应的超平面和半空间的法向量, 且 $b \in \mathbb{R}$ . 解析地, 超平面是关于 $\boldsymbol{x}$ 的非平凡线性方程的解空间(因此是一个仿射集合). 一个超平面将 $\mathbb{R}^{n}$ 分成两个半空间. 超平面是仿射集和凸集, 半空间是凸集但不是仿射集. 超平面的几何解释如图. 对于超平面上任意一点 $\boldsymbol{x}, \boldsymbol{x}-\boldsymbol{x}_{0}$ (如深色箭头所示)都垂直于 $\boldsymbol{a}$ . $\mathbb{R}^{2}$ 上由 $\boldsymbol{a}^{\mathrm{T}} \boldsymbol{x}=b$ 定义的超平面决定了两个半空间, 由 $\boldsymbol{a}^{\mathrm{T}} \boldsymbol{x} \geq b$ 决定的半空间是向 $\boldsymbol{a}$ 扩展的半空间, 由 $\boldsymbol{a}^{\mathrm{T}} \boldsymbol{x} \leq b$ 确定的半空间向 $-\boldsymbol{a}$ 方向扩展. 向量 $\boldsymbol{a}$ 是这个半空间向外的法向量.

<img src="https://images-1258882488.cos.ap-shanghai.myqcloud.com/hyperplane.png
" alt="hyperplane.png" style="zoom:50%;" />

- Euclid球、范数球、范数锥. 球是空间中到某个点距离(或两者差的范数)小于某个常数的点的集合$B\left(\boldsymbol{x}_{c}, r\right)=\left\{\boldsymbol{x} \mid\left\|\boldsymbol{x}-\boldsymbol{x}_{c}\right\|_{2} \leq r\right\}=\left\{\boldsymbol{x}_{c}+r \boldsymbol{u}\| \| \boldsymbol{u} \|_{2} \leq 1\right\}$. 一般地形如$\left\{\boldsymbol{x} \mid\left(\boldsymbol{x}-\boldsymbol{x}_{c}\right)^{\mathrm{T}} \boldsymbol{P}^{-1}\left(\boldsymbol{x}-\boldsymbol{x}_{c}\right) \leq 1\right\}$的椭球是凸集, 其中 $\boldsymbol{P} \in \mathcal{S}_{++}^{n}$ (即 $\boldsymbol{P}$ 对称正定). 椭球的另一种表示为$\left\{\boldsymbol{x}_{c}+\boldsymbol{A} \boldsymbol{u}\|\boldsymbol{u}\|_{2} \leq 1\right\}$, 其中 $\boldsymbol{A}$ 为非奇异的方阵. 除了可以推广到椭球外, Euclid球还可以推广到任意的范数球, 集合$\left\{\boldsymbol{x} \mid\left\|\boldsymbol{x}-\boldsymbol{x}_{c}\right\| \leq r\right\}$为以 $r$ 为半径,  $\boldsymbol{x}_{c}$ 为球心的范数球. 根据范数的三角不等式性质可知, 一般的范数球是一个凸集. 范数锥$\left\{(\boldsymbol{x}, t)\|\|\boldsymbol{x}\| \leq t\} \subseteq \mathbb{R}^{n+1}\right.$是一个凸雉.

- 多面体. 满足线性等式和不等式组的点的集合$\{\boldsymbol{x} \mid \boldsymbol{A x} \leq \boldsymbol{b}, \boldsymbol{C x}=\boldsymbol{d}\}$称为多面体, 其中 $\boldsymbol{A} \in \mathbb{R}^{m \times n}, \boldsymbol{C} \in \mathbb{R}^{p \times n}, \boldsymbol{x} \leq \boldsymbol{y}$ 表示向量 $\boldsymbol{x}$ 的每个分量均小于等于 $\boldsymbol{y}$ 的对应分量. 多面体是有限个半空间和超平面的交集. 仿射集合(例如子空间、超平面、直线)、射线、线段和半空间都是多面体. 显而易见, 多面体是凸集. 有界的多面体有时也称为多胞形, 但也有一些作者反过来使用这两个概念(即用多胞形表示具有上面形式的集合, 而当其有界时称为多面体).

  非负象限是一类特殊的多面体, 非负象限是具有非负分量的点的集合, 即$\mathbb{R}_{+}^{n}=\left\{\boldsymbol{x} \in \mathbb{R}^{n} \mid x_{i} \geq 0, i=1, \ldots, n\right\}=\left\{\boldsymbol{x} \in \mathbb{R}^{n} \mid \boldsymbol{x} \geq \mathbf{0}\right\}$. 因此 $\mathbb{R}_{+}$表示非负实数的集合, 即 $\mathbb{R}_{+}=\{x \in \mathbb{R} \mid x \geq 0\}$ . 非负象限既是多面体也是锥, 因此称为多面体锥. 

  单纯形是一类重要的多面体. 设 $k+1$ 个点 $\boldsymbol{v}_{0}, \cdots, \boldsymbol{v}_{k} \in \mathbb{R}^{n}$ 仿射独立, 则 $\boldsymbol{v}_{1}-\boldsymbol{v}_{0}, \cdots, \boldsymbol{v}_{k}-\boldsymbol{v}_{0}$线性独立. 那么, 这些点决定了一个单纯形, 如下所示: 
  $$
  \boldsymbol{\operatorname { c o n v }}\left\{\boldsymbol{v}_{0}, \cdots, \boldsymbol{v}_{k}\right\}=\left\{\theta_{0} \boldsymbol{v}_{0}+\cdots+\theta_{k} \boldsymbol{v}_{k} \mid \boldsymbol{\theta} \geq 0, \mathbf{1}^{\mathrm{T}} \boldsymbol{\theta}=1\right\}
  $$

  其中 $\bold 1$ 表示所有分量均为 1 的向量. 1维单纯形是一条线段; 2维单纯形是一个三角形(包含其内部);  3维单纯形是一个四面体. 单位单纯形是由零向量和单位向量, 即 $0, \boldsymbol{e}_{1}, \cdots, \boldsymbol{e}_{n} \in \mathbb{R}^{n}$ 决定的 $n$ 维单纯形. 它可以表示为满足下列条件的向量的集合
  $$
  \boldsymbol{x} \geq \mathbf{0}, \quad \mathbf{1}^{\mathrm{T}} \boldsymbol{x} \leq 1
  $$

  概率单纯形是由单位向量 $\boldsymbol{e}_{1}, \cdots, \boldsymbol{e}_{n} \in \mathbb{R}^{n}$ 决定的 $n-1$ 维单纯形. 它是满足下列条件的向量的集合, 
  $$
  \boldsymbol{x} \geq \mathbf{0}, \quad \mathbf{1}^{\mathrm{T}} \boldsymbol{x}=1
  $$

  概率单纯形中的向量对应于含有 $n$ 个元素的集合的概率分布, $x_{i}$ 可理解为第 $i$ 个元素的概率.

判断集合是否是凸集一方面可以从定义出发, 这有时比较困难, 另一方面可以通过判断集合能够由凸集通过保凸运算变换得到. 常见的保凸运算包括取交集、仿射变换、线性分式以及透视函数等.



### 4. Functions that Reserve Convexity

##### 4.1 保凸集合操作

交集运算是保凸的: 如果 $\mathbb{S}_{1}$ 和 $\mathbb{S}_{2}$ 是凸集, 那么 $\mathbb{S}_{1} \cap \mathbb{S}_{2}$ 也是凸集. 这个性质可以扩展到无穷个集合的交: 如果对于任意 $\alpha \in \mathcal{A}$ 都有 $\mathbb{S}_{\alpha}$ 是凸集, 那么, $\cap_{\alpha \in \mathcal{A}} \mathbb{S}_{\alpha}$ 也是凸集. (子空间和仿射集合对于任意交运算也是封闭的) 作为一个简单的例子, 多面体是半空间和超平面(它们都是凸集)的交集, 因而是凸的.

> 例. 半正定锥 $\mathcal{S}_{+}^{n}$ 可以表示为
> $$
> \cap_{\boldsymbol{z} \neq 0} \left\{\boldsymbol{X} \in \mathcal{S}^{n} \mid \boldsymbol{z}^{\mathrm{T}} \boldsymbol{X} \boldsymbol{z} \geq 0\right\}
> $$
> 对于任意 $\boldsymbol{z} \neq 0, \boldsymbol{z}^{\mathrm{T}} \boldsymbol{X} \boldsymbol{z}$ 是关于 $\boldsymbol{X}$ 的(不恒等于零的)线性函数, 因此集合
> $$
> \left\{\boldsymbol{X} \in \mathcal{S}^{n} \mid \boldsymbol{z}^{\mathrm{T}} \boldsymbol{X} \boldsymbol{z} \geq 0\right\}
> $$
>
> 实际上就是 $\mathcal{S}^{n}$ 的半空间. 由此可见, 半正定锥是无穷个半空间的交集, 因此是凸的.
>
> <img src="https://images-1258882488.cos.ap-shanghai.myqcloud.com/positive-semidefinite-cone.png
> " alt="positive-semidefinite-cone.png" style="zoom: 25%;" />



和运算. 两个集合的和可以定义为
$$
\mathbb{S}_{1}+\mathbb{S}_{2}=\left\{\boldsymbol{x}+\boldsymbol{y} \mid \boldsymbol{x} \in \mathbb{S}_{1}, \boldsymbol{y} \in \mathbb{S}_{2}\right\}
$$

如果 $\mathbb{S}_{1}$ 和 $\mathbb{S}_{2}$ 是凸集, 那么,  $\mathbb{S}_{1}+\mathbb{S}_{2}$ 是凸的.

我们也可以考虑 $\mathbb{S}_{1}, \mathbb{S}_{2} \in \mathbb{R}^{n} \times \mathbb{R}^{m}$ 的部分和, 定义为
$$
\mathbb{S}=\left\{\left(\boldsymbol{x}, \boldsymbol{y}_{1}+\boldsymbol{y}_{2}\right) \|\left(\boldsymbol{x}, \boldsymbol{y}_{1}\right) \in \mathbb{S}_{1},\left(\boldsymbol{x}, \boldsymbol{y}_{2}\right) \in \mathbb{S}_{2}\right\}
$$

其中 $\boldsymbol{x} \in \mathbb{R}^{n}, \boldsymbol{y}_{i} \in \mathbb{R}^{m}$ .  $m=0$ 时, 部分和给出了 $\mathbb{S}_{1}$ 和 $\mathbb{S}_{2}$ 的交集; $n=0$ , 部分和等于集合之和. 凸集的部分和仍然是凸集.

Cartesian 乘积. 如果 $\mathbb{S}_{1}$ 和 $\mathbb{S}_{2}$ 是凸的, 那么其直积或 Cartesian 乘积
$$
\mathbb{S}_{1} \times \mathbb{S}_{2}=\left\{\left(\boldsymbol{x}_{1}, \boldsymbol{x}_{2}\right) \mid \boldsymbol{x}_{1} \in \mathbb{S}_{1}, \boldsymbol{x}_{2} \in \mathbb{S}_{2}\right\}
$$

也是凸集.

集合投影. 一个凸集向它的某几个坐标的投影是凸的, 即: 如果 $\mathbb{S} \subseteq \mathbb{R}^{m} \times \mathbb{R}^{n}$ 是凸集, 那么
$$
\left\{\boldsymbol{x}_{1} \in \mathbb{R}^{m} \mid\left(\boldsymbol{x}_{1}, \boldsymbol{x}_{2}\right) \in \mathbb{S}, \text { 对于某些 } \boldsymbol{x}_{2} \in \mathbb{R}^{n}\right\}
$$

是凸集.



##### 4.2 保凸映射

仿射函数. 设 $f: \mathbb{R}^{n} \rightarrow \mathbb{R}^{m}$ 是仿射变换, 即 $f(\boldsymbol{x})=\boldsymbol{A} \boldsymbol{x}+\boldsymbol{b}, \boldsymbol{A} \in \mathbb{R}^{m \times n}, \boldsymbol{b} \in \mathbb{R}^{m}$ , 则

(1) 凸集在 $f$ 下的像是凸集.
$$
\mathbb{S} \subseteq \mathbb{R}^{n} \text { 为凸集 } \Rightarrow f(\mathbb{S}):=\{f(\boldsymbol{x}) \mid \boldsymbol{x} \in \mathbb{S}\} \text { 为凸集; }
$$
(2) 凸集在 $f$ 下的原像是凸集.
$$
\mathbb{C} \subseteq \mathbb{R}^{m} \text { 为凸集 } \Rightarrow f^{-1}(\mathbb{C}):=\left\{\boldsymbol{x} \in \mathbb{R}^{n} \mid f(\boldsymbol{x}) \in \mathbb{C}\right\} \text { 为凸集. }
$$

> 例. 伸缩和平移: 如果 $\mathbb{S} \subseteq \mathbb{R}^{n}$ 是凸集, $\alpha \in \mathbb{R}$ 并且 $\boldsymbol{a} \in \mathbb{R}^{n}$ , 那么, 集合 $\alpha \mathbb{S}$ 和 $\mathbb{S}+\boldsymbol{a}$是凸的, 其中
> $$
> \alpha \mathbb{S}=\{\alpha \boldsymbol{x} \mid \boldsymbol{x} \in \mathbb{S}\}, \quad \mathbb{S}+\boldsymbol{a}=\{\boldsymbol{x}+\boldsymbol{a} \mid \boldsymbol{x} \in \mathbb{S}\}
> $$
>
> 例. 集合投影: 一个凸集向它的某几个坐标的投影是凸的, 即: 如果 $\mathbb{S} \subseteq \mathbb{R}^{m} \times \mathbb{R}^{n}$ 是凸集, 那么
> $$
> \left\{\boldsymbol{x}_{1} \in \mathbb{R}^{m} \mid\left(\boldsymbol{x}_{1}, \boldsymbol{x}_{2}\right) \in \mathbb{S} \ \text {for some} \ \boldsymbol{x}_{2} \in \mathbb{R}^{n}\right\}
> $$
>
> 是凸集.
>
> 例. 利用仿射变换保凸的性质, 可以证明线性矩阵不等式的解集:
> $$
> \left\{\boldsymbol{x} \mid x_{1} \boldsymbol{A}_{1}+x_{2} \boldsymbol{A}_{2}+\cdots+x_{m} \boldsymbol{A}_{m} \preccurlyeq \boldsymbol{B}\right\}
> $$
>
> 是凸集, 其中 $\boldsymbol{A}_{i}, \boldsymbol{B} \in \mathcal{S}^{n}$ . 因为, 它可以看作是一个仿射变换的原像.
>
> 例. 双曲锥
> $$
> \left\{\boldsymbol{x} \mid \boldsymbol{x}^{\mathrm{T}} \boldsymbol{P} \boldsymbol{x} \leq\left(\boldsymbol{c}^{\mathrm{T}} \boldsymbol{x}\right)^{2}, \boldsymbol{c}^{\mathrm{T}} \boldsymbol{x} \geq 0\right\}
> $$
>
> 是凸集, 其中 $\boldsymbol{P} \in \mathcal{S}_{+}^{n}$ . 因为, 它可以看作是 $\boldsymbol{x} \mapsto\left(\boldsymbol{P}^{1 / 2} \boldsymbol{x}, \boldsymbol{c}^{\mathrm{T}} \boldsymbol{x}\right)$ 变换下的原像, 而值域是凸锥.
>

透视函数.

定义 $P: \mathbb{K} \rightarrow \mathbb{R}^{n}$ , 
$$
P(\boldsymbol{z}, t)=\boldsymbol{z} / t
$$

为透视函数, 其定义域为 $\operatorname{dom} f=\mathbb{K}=\mathbb{R}^{n} \times \mathbb{R}_{++}$. 透视函数对向量进行伸缩, 或称为规范化, 使得最后一维分量为 1 并舍弃之. 如果 $\mathbb{C} \subseteq \mathbb{K}$是凸集, 那么它的像
$$
P(\mathbb{C})=\{P(\boldsymbol{x}) \mid \boldsymbol{x} \in \mathbb{C}\}
$$

也是凸集. 这个结论的物理意义在于: 通过小孔观察一个凸的物体, 可以得到凸的像. 为解释这个事实, 下面我们将说明在透视函数作用下, 线段将被映射成线段.

假设 $\boldsymbol{x}=\left(\tilde{\boldsymbol{x}}, x_{n+1}\right), \boldsymbol{y}=\left(\tilde{\boldsymbol{y}}, y_{n+1}\right) \in \mathbb{R}^{n+1}$ 并且 $x_{n+1}>0, y_{n+1}>0$ . 那么, 对于 $0 \leq \theta \leq 1$ .
$$
P(\theta \boldsymbol{x}+(1-\theta) \boldsymbol{y})=\dfrac{\theta \tilde{\boldsymbol{x}}+(1-\theta) \tilde{\boldsymbol{y}}}{\theta x_{n+1}+(1-\theta) y_{n+1}}=\mu P(\boldsymbol{x})+(1-\mu) P(\boldsymbol{y})
$$











