# Information Theory

$$
\newcommand{\X}{\mathcal X}
\newcommand{\Y}{\mathcal Y}
$$



### 1. Information Entropy

##### 1.1 Information Quantity

信源发出的消息(事件)具有随机性. 发生概率大的消息含的信息量小. 发生概率小的消息含的信息量大. 如果两个消息是毫无关联的, 即发生的概率是相互独立的, 那么通过这两个消息获得的信息量应当是两个消息各自信息量的和. 因此随机事件的自信息量 $I\left(x_{i}\right)$ 是该事件发生概率 $p\left(x_{i}\right)$ 的函数, 并且 $I\left(x_{i}\right)$ 应该满足以下公理化条件

1. $I\left(x_{i}\right)$ 是 $p\left(x_{i}\right)$ 的严格递减函数. 当 $p\left(x_{1}\right)<p\left(x_{2}\right)$ 时 $I\left(x_{1}\right)>I\left(x_{2}\right)$, 概率越小, 事件发生的不确定性越大, 事件发生以后所包含的自信息量越大.
2. 极限情况下, 当 $p\left(x_{i}\right)=0$ 时, $I\left(x_{i}\right) \rightarrow \infty$; 当 $p\left(x_{i}\right)=1$ 时, $I\left(x_{i}\right)=0$ .
3. 从直观概念上讲, 由两个相对独立的不同的消息所提供的信息量应等于它们分别提供的信息量之和, 即自信息量满足可加性.

可以证明, 满足以上公理化条件的函数形式是对数形式. 因此我们定义随机事件的自信息量为该事件发生概率的对数的负值. 设事件 $x_{i}$ 的概率为 $P\left(x_{i}\right)$, 则它的自信息量定义为
$$
I\left(x_{i}\right)=-\log p\left(x_{i}\right)=\log \dfrac{1}{p\left(x_{i}\right)}
$$
$I\left(x_{i}\right)$ 代表在事件 $x_{i}$ 发生以后, 表示事件 $x_{i}$ 所含有或所能提供的信息量.



##### 1.2 Information Entropy

For the random variable $X$ with its probability density function $p(x)$, we define the **information entropy** of $X$ as

$$
H(X) = -\sum_x p(x)\log_b p(x)
$$

The base $b$ defines the unit of information entropy, we use $a=2$ for computer science in practice, where the unit is **bit**. Academically we use $b=\mathrm{e}$, where the unit is **nat**. The physical significance of information entropy is the average uncertainty of the random variable.



##### 1.3 Mutual Information

事件 $y_{j}$ 所给出关于事件 $x_{i}$ 的信息定义为互信息$I\left(x_{i} ; y_{j}\right)$ 
$$
I\left(x_{i} ; y_{j}\right)=I\left(x_{i}\right)-I\left(x_{i} \mid y_{j}\right)=\log \dfrac{p\left(x_{i} \mid y_{j}\right)}{p\left(x_{i}\right)}
$$

互信息 $I\left(x_{i} ; y_{j}\right)$ 是事件 $y_{j}$ 所包含的关于事件 $x_{i}$ 的信息量, 它等于事件 $x_{i}$ 本身的信息量 $I\left(x_{i}\right)$ 减去已知事件 $y_{j}$ 后对 $x_{i}$ 仍然存在的信息量 $I\left(x_{i} \mid y_{j}\right)$ .

The **mutual information** or **transinformation** on random variables $X, Y$ measures mutual dependence between two random variables.  It measures the average mutual information in the joint proability space $(X, Y)$.

$$
\begin{align}
I(X;Y) &= \sum_{y\in\Y}\sum_{x\in\X} p_{(X, Y)}(x, y) \log \left( \frac{p_{X, Y}(x, y)}{p_X(x)p_Y(y)} \right) \\
       &= I(X ; Y)=\displaystyle\sum_{x_{i}} \displaystyle\sum_{y_{j}} p\left(x_{i}, y_{j}\right) I\left(x_{i} ; y_{j}\right)
\end{align}
$$

where the $p_{(X, Y)}$ is the joint probability mass function of $X$ and $Y$, and $p_X$ and $p_Y$ are the marginal probability mass functions of $X$ and $Y$ respectively.

随机变量的互信息和熵的关系同独立事件的关系保持一致.

$$
\begin{align}
I(X; Y)
&= \sum_{x,y} p(x, y)\log\frac{p(x, y)}{p(x)p(y)} \\
&= \sum p(x, y)\log \frac{p(x|y)}{p(x)} \\
&= -\sum p(x, y)\log p(x) + \sum p(x, y)\log p(x|y) \\
&= -\sum p(x)\log p(x) - \left(-\sum_{x,y}p(x, y)\log p(x|y)\right) \\
&= H(X) - H(X|Y)
\end{align}
$$

互信息有非负性$I(X;Y)\ge0$和对称性$I(X;Y)=I(Y;X)$. 对称性表明, 从Y中获得的关于X的信息量等于从X中获得的关于Y的信息量. 

> 证明. 对于非负性, 注意到$\log$作为凹函数有
> $$
> \begin{aligned}
> -I(X ; Y) & =\displaystyle\sum_{i=1}^{n} \displaystyle\sum_{j=1}^{m} p\left(x_{i}, y_{j}\right) \log _{2} \dfrac{p\left(x_{i}\right) p\left(y_{j}\right)}{p\left(x_{i}, y_{j}\right)} \\
> & \leqslant \log _{2} \displaystyle\sum_{i=1}^{n} \displaystyle\sum_{j=1}^{m} p\left(x_{i}, y_{j}\right) \dfrac{p\left(x_{i}\right) p\left(y_{j}\right)}{p\left(x_{i}, y_{j}\right)} \\
> & =\log _{2} \displaystyle\sum_{i=1}^{n} \displaystyle\sum_{j=1}^{m} p\left(x_{i}\right) p\left(y_{j}\right)=0
> \end{aligned}
> $$
> 从而$I(X ; Y) \geq 0$. 当且仅当 $p(x, y)=p(x) p(y)$即$X$与$Y$独立时, 互信息为 0.
>
> 对于对称性, 直接应用条件概率定义
> $$
> \begin{aligned}
> I(X ; Y) & =\displaystyle\sum_{i=1}^{n} \displaystyle\sum_{j=1}^{m} p\left(x_{i}, y_{j}\right) \log _{2} \dfrac{p\left(x_{i} \mid y_{j}\right)}{p\left(x_{i}\right)} \\
> & =\displaystyle\sum_{i=1}^{n} \displaystyle\sum_{j=1}^{m} p\left(x_{i}, y_{j}\right) \log _{2} \dfrac{p\left(x_{i}, y_{i}\right)}{p\left(x_{i}\right) p\left(y_{j}\right)} \\
> & =\displaystyle\sum_{i=1}^{n} \displaystyle\sum_{j=1}^{m} p\left(x_{i}, y_{j}\right) \log _{2} \dfrac{p\left(y_{j} \mid x_{i}\right)}{p\left(y_{j}\right)} \\
> & =I(Y ; X)
> \end{aligned}
> $$




平均互信息是非负的，说明给定随机变量 $Y$ 后，一般来说总能消除一部分关于 $X$ 的不确定性

相对熵
相对熵是两个随机分布之间距离的度量。统计学上对应于对数似然比的期望。
定义 6.1.7. 定义同一个随机变量 $X$ 的两个概率密度函数 $p(x)$ 和 $q(x)$ 间的相对熵为:
$$
D(p \| q)=E_{x \sim p}\left[\log \dfrac{p(x)}{q(x)}\right]=E_{x \sim p}[\log p(x)-\log q(x)]
$$

在机器学习中, 相对摘更常用的名称是 KL 散度 (Kullback-Leibler Divergence), 记做 $D_{K L}(p \| q)$ 。
KL 散度有很多有用的性质，首先 KL 散度是非负的并且可以度量两个分布之间的差异。但需要注意的是，它并不是距离，因为它不是对称的。其次，当且仅当在离散型变量的情况下是相同的分布, 或者在连续型变量的情况下 "几乎处处" 相同时, KL 散度才为 0 。此外, 联合分布 $p(X, Y)$ 和 $p(X) p(Y)$ 之间的 KL 散度可以作为 X 和 Y 的互信息的另一种定义:
$$
I(X ; Y):=D_{K L}(p(X, Y) \| p(X) p(Y))=\displaystyle\sum_{x} \displaystyle\sum_{y} p(x, y) \log \dfrac{p(x, y)}{p(x) p(y)}
$$

性质6.1.13. （互信息和摘的关系）
$$
I(X ; Y)=H(X)-H(X \mid Y)=H(Y)-H(Y \mid X)=H(X)+H(Y)-H(X, Y)
$$

当 $X, Y$ 统计独立时, $I(X ; Y)=0$.
性质 6.1.14. $H(X)=I(X ; X)$.








$$
I(X;Y) = I(Y;X) = H(X)-H(X|Y) = H(Y) - H(Y|X) = H(X) + H(Y) - H(X, Y) \\
I(X;X) = H(X)
$$



$$
\begin{align}
H(X_1, X_2, \cdots, X_n)
&= -\sum p(x1, x_2, \cdots, x_n)\log p(x_1, x_2, \cdots, x_n) \\
&= -\sum p(x1, x_2, \cdots, x_n)\log \prod_{i=1}^n p(x_i | x_{i-1}, \cdots, x_1)
\end{align}
$$



$$
D(p(x, y) \| q(x, y)) = D(p(x)\| q(x)) + D(p(y|x) \| q(y|x))
$$




$$
\begin{align}
D(p(x, y) \| q(x, y))
&= \sum_x\sum_y p(x, y)\log \frac{p(x,y)}{q(x, y)} \\
&= \sum_x\sum_y p(x, y)\log \frac{p(x)p(y|x)}{q(x)q(y|x)} \\
&= \sum_x\sum_y p(x, y)\log \frac{p(x)}{q(x)} + \sum_x\sum_yp(x, y)\log \frac{p(y|x)}{q(y|x)} \\
&= D(p(x)\| q(x)) + D(p(y|x) \| q(y|x))
\end{align}
$$











也称为互信息。
互信息有以下性质：
性质 6.1.11. （对称性）
$$
I(X ; Y)=I(Y ; X)
$$

证明.
$$

$$

证毕。
