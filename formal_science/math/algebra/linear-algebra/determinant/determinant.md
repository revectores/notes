# Determinant

### 1. Definition of Determinant

把 n 个不同的元素排成一行，称为这 n 个元素的一个全排列，简称排列. n 个不同元素所有可能排列的种数记作 $\boldsymbol{P}_{\boldsymbol{n}}$ ，显然有 $P_{n}=n$ !

对于 n 个不同的元素，如果预先规定一个标准的排列顺序（例如对于自然数元素，规定自小到大为标准排列），则在这 n 个元素的任一排列中，当某两个元素的先后次序与标准次序不同时，就说存在 1 个逆序，一个排列中所有逆序的总数称为这个排列的逆序数。逆序数为奇数的排列称为奇排列，逆序数为偶数的排列称为偶排列。

不妨设 n 个元素为 $1 \sim \mathrm{n}$ 这 n 个自然数，并规定由小到大为标准次序，设 $p_{1} p_{2} \ldots p_{n}$ 为这 n个自然数的一个排列，考虑元素 $p_{i}(i=1,2, \ldots, n)$ ，如果比 $p_{i}$ 大且排在 $p_{i}$ 前面的元素有 $t_{i}$ 个，则称 $p_{i}$ 这个元素的逆序数为 $t_{i}$ ，全体元素的逆序数之和

$$
t=\sum t_{i}
$$

称为这个排列的逆序数。
E.G. 计算 32514（标准排列 12345）的逆序数

从 3 开始， 3 前面没有元素，逆序数为 0,2 前面有 3 ，逆序数为 1,5 和前面的数不存在逆序，逆序数为 0,1 前面有 325 ，逆序数为 3,4 前面有 5 ，逆序数为 1 ，因此我们得到 32514的逆序数为 $0+1+0+3+1=5$
对换
在排列中将任意两个元素对调，其他元素不动，从而得到一个新排列的变换称为对换。对相邻两个元素进行的对换称为相邻对换。

对换的基本性质：对换操作会改变排列的奇偶性。
Prov. 不妨设 n 元素为 $1 \sim \mathrm{n}$ 这 n 个自然数，以从小到大为标准次序，先考虑相邻对换的情形。考虑某一序列中相邻两个元素...ab...，相邻对换不改变其他元素的逆序数，当 $a<b$ 时，对换后 $a$ 的逆序数增加 1 而 $b$ 的逆序数保持不变；当 $a>b$ 时，对换后 $a$ 的逆序数不变而 $b$ 的逆序数减少 1. 因此相邻对换后排列的奇偶性会发生改变。

考虑一般对换，假设 $a, b$ 之间间隔着 $k$ 个自然数，则需要交换二者的位置必须经过 $2 k+1$次相邻对换，因此对换前后两个排列的奇偶性相反。

由此可以得到一个简单推论：奇排列对换成标准排列的对换次数为奇数，偶排列对换成标准排列的兄换次数为偶数。

设有 n 阶方阵

$$
\left(\begin{array}{cccc}
a_{11} & a_{12} & \ldots & a_{1 n} \\
a_{21} & a_{22} & \ldots & a_{2 n} \\
\ldots . & \ldots & \ldots & \ldots \\
a_{n 1} & a_{n 2} & \ldots & a_{n n}
\end{array}\right)
$$

记

$$
\operatorname{det}\left(a_{i j}\right)=\left|\begin{array}{cccc}
a_{11} & a_{12} & \ldots & a_{1 n} \\
a_{21} & a_{22} & \ldots & a_{2 n} \\
\ldots . & \ldots . & \ldots & \ldots \\
a_{n 1} & a_{n 2} & \ldots & a_{n n}
\end{array}\right|=\sum(-1)^{t} a_{1 p_{1}} a_{2 p_{2}} \ldots a_{n p_{n}}
$$

定义为该方阵所确定的 $\mathbf{n}$ 阶行列式。式中的 $p_{1} p_{2} \ldots p_{n}$ 是自然数 $1,2, \ldots, \mathrm{n}$ 的一个排列， t是（以从小到大为标准排列时）这个排列的逆序数。由于 $n$ 个数的排列有 $n!$ 个，故上式右边

一共有 n !项。数 $a_{i j}$ 称为行列式的元素或元。第一个下标 i 称为行标，表明元素位于第 i 行；第二个下标 j 称为列标，表明元素位于第 j 列。位于第 i 行第 j 列的元素 $a_{i j}$ 称为行列式的 $(i, j)$元。

把从 $a_{11}$ 到 $a_{n n}$ 的连线称为主对角线，从 $a_{1 n}$ 到 $a_{n 1}$ 的连线称为副对角线。
特别地，当 $\mathrm{n}=1$ 时，一阶行列式 $|a|=a$ 。
当 $n=2$ 时,
$$
\left|\begin{array}{ll}
a_{11} & a_{12} \\
a_{21} & a_{22}
\end{array}\right|=a_{11} a_{22}-a_{12} a_{21}
$$

因此二阶行列式的值可以形象地理解为：主对角线上两元素的积减去副对角线上两元素的积。

当 $n=3$ 时

$$
=a_{11} a_{22} a_{33}+a_{12} a_{23} a_{31}+a_{13} a_{21} a_{32}-a_{11} a_{23} a_{32}-a_{12} \quad a_{13} a_{21} a_{33}-a_{13} a_{22} a_{31}
$$

三条平行于主对角线（含主对角线）的线上的元素之积的和减去三条平行于副对角线的线上的元素之积的和，得到的就是三阶行列式的值。

值得注意的是，当 $n>=4$ 以后，就无法使用主对角线和副对角线的方式来考虑行列式的值了。好在 $n=3$ 正是我们所处的空间维数，在许多实际情形下的行列式计算都不至于太过复杂。



### 2. Property of Determinant

将行列式 $D$ 的行、列互换以后得到的行列式称为 $D$ 的转置行列式，记作 $D^{T}$ ，即对于

$$
D=\left|\begin{array}{cccc}
a_{11} & a_{12} & \ldots & a_{1 n} \\
a_{21} & a_{22} & \ldots & a_{2 n} \\
\ldots . & \ldots . & \ldots & \ldots \\
a_{n 1} & a_{n 2} & \ldots & a_{n n}
\end{array}\right|
$$

其转置

$$
D^{T}=\left|\begin{array}{cccc}
a_{11} & a_{21} & \ldots & a_{n 1} \\
a_{12} & a_{22} & \ldots & a_{n 2} \\
\ldots . & \ldots & \ldots . & \ldots \\
a_{1 n} & a_{2 n} & \ldots & a_{n n}
\end{array}\right|
$$

注意到行列式转置过后主对角线上的元素保持不变。本质上转置可以视为作了一个沿主对角线的翻折变换。

性质1（转置不变性/行列等价性） 转置不改变行列式的值。因此在行列式中行、列的地位是等价的。因而一切适用于行的性质都可以适用于列，反之亦然。

性质2（对换性质）对换行列式的两行，行列式变号。由此可以得到推论 1：如果行列式有两行完全相同，则这个行列式等于零。证明只需要把两行对换，则前后的值互为相反数且相等，因此值必然只能是 0 。

性质3（数乘规则）行列式的某一行所有元素乘一个系数 k，等于用数 k 乘此行列式. 反过来，行列式中某一行元素的公因子可以提到行列式的记号外面。

结合性质2和性质3，可知推论 2：只需要行列式两行成比例（并不必须相等）即可判定其为零。这是因为在 0 面前任何系数都无所谓。

性质4（拆分操作）可以把某一行的元素分别拆成两数之和并将加数分配到两个新的行列式中，且行列式的其他元素保持不变：

$$
\left|\begin{array}{cccc}
a_{11} & a_{12} & \ldots & a_{1 n} \\
\ldots & \ldots & \ldots & \ldots \\
a_{i 1}+a_{i 1}{ }^{\prime} & a_{i 2}+a_{i 2}^{\prime} & \ldots & a_{i n}+a_{i n}^{\prime} \\
\ldots & \ldots & \ldots & \ldots \\
a_{n 1} & a_{n 2} & \ldots & a_{n n}
\end{array}\right|=\left|\begin{array}{cccc}
a_{11} & a_{12} & \ldots & a_{1 n} \\
\ldots & \ldots & \ldots & \ldots \\
a_{i 1} & a_{i 2} & \ldots & a_{i n} \\
\ldots & \ldots & \ldots & \ldots \\
a_{n 1} & a_{n 2} & \ldots & a_{n n}
\end{array}\right|+\left|\begin{array}{cccc}
a_{11} & a_{12} & \ldots & a_{1 n} \\
\ldots & \ldots & \ldots & \ldots \\
a_{i 1}{ }^{\prime} & a_{i 2}{ }^{\prime} & \ldots & a_{i n}^{\prime} \\
\ldots & \ldots & \ldots & \ldots \\
a_{n 1} & a_{n 2} & \ldots & a_{n n}
\end{array}\right|
$$

性质5.（初等行变换）把行列式的某一行的各个元素同乘一数加到另一行对应的元素上去，行列式不变。证明只需要把新的行列式按照性质4所述操作按照加法拆成原行列式 + 加数行列式，加数行列式中两行对应成比例故为零，因此和原行列式相等。

以上性质存在如下逻辑链条：
〈初等行变换 $\left\{\begin{array}{c}\text { 行成比例为零 } \leftarrow\left\{\begin{array}{c}\text { 行相同为零 } \leftarrow \text { 对换变号性质 } \\ \text { 数乘规则 }\end{array} \text { 〉转置不变性 }\right. \\ \text { 拆分操作合法性 }\end{array}\right.$
转置不变性统领以上的各个性质，使得一切对行能够进行的操作对列也能够进行。



### 3. Determinant of Special Matrix

上下三角行列式的值就等于对角线上的元素之积

$$
D=\left|\begin{array}{cccc}
a_{11} & 0 & \ldots & 0 \\
a_{21} & a_{22} & \ldots & \ldots \\
\ldots & \ldots & \ldots & 0 \\
a_{n 1} & a_{n 2} & \ldots & a_{n n}
\end{array}\right|=\left|\begin{array}{cccc}
a_{11} & \ldots & \ldots & a_{1 n} \\
0 & a_{22} & \ldots & \ldots \\
\ldots & \ldots & \ldots & \ldots \\
0 & \ldots & 0 & a_{n n}
\end{array}\right|=\left|\begin{array}{cccc}
a_{11} & 0 & \ldots & 0 \\
0 & a_{22} & \ldots & \ldots \\
\ldots & \ldots & \ldots & 0 \\
0 & \ldots & 0 & a_{n n}
\end{array}\right|=a_{11} a_{22} \ldots a_{n n}
$$

对于副上下三角型的行列式

$$
D=\left|\begin{array}{cccc}
0 & \ldots & 0 & a_{1 n} \\
\ldots & \ldots & a_{2, n-1} & a_{2 n} \\
0 & \ldots & \ldots & \ldots \\
a_{n 1} & a_{n 2} & \ldots & a_{n n}
\end{array}\right|
= (-1)^{\frac{1}{2} n(n-1)} \Pi
$$

其中$\Pi$为副对角线上元素之积. 这是因为$D$可以通过行对换转换成上下三角的形式, 考虑通过冒泡排序的方式逐行上移, 则总的对换次数为

$$
(n-1)+(n-2)+\cdots+1=\frac{1}{2} n(n-1)
$$



### 4. Compute Determinant By Partitioning

设

$$
D=\left|\begin{array}{cccccc}
a_{11} & \ldots & a_{1 k} & 0 & 0 & 0 \\
\ldots & \ldots . & \ldots & 0 & 0 & 0 \\
a_{n 1} & \ldots & a_{k k} & 0 & 0 & 0 \\
c_{11} & \ldots & c_{1 k} & b_{11} & \ldots & b_{1 n} \\
\ldots & \ldots & \ldots & \ldots & \ldots & \ldots \\
c_{n 1} & \ldots & c_{n k} & b_{n 1} & \ldots & b_{n n}
\end{array}\right|
$$

记

$$
D_{1}=\left|\begin{array}{ccc}
a_{11} & \ldots & a_{1 k} \\
\ldots & \ldots & \ldots \\
a_{n 1} & \ldots & a_{k k}
\end{array}\right|, \quad D_{2}=\left|\begin{array}{ccc}
b_{11} & \ldots & b_{1 n} \\
\ldots & \ldots & \ldots \\
b_{n 1} & \ldots & b_{n n}
\end{array}\right|
$$

则有 $D=D_{1} D_{2}$.
证明: 我们对 $D_{1}$ 和 $D_{2}$ 分别执行初等行变换和列变换使它们都变成下三角行列式，然后在 $D$ 中对 $a, b$ 所在的行（列）作同样的变换，由于 $a$ 所在的行右侧全为 0 ，行变换不会对它们产生任何影响，对 b 同理，因此最后可以把 $D$ 转变成一个对角线上元素相当于 $D_{1}, D_{2}$ 拼接起来的下三角行列式，从而 $D=D_{1} D_{2}$.

证明过程中全 0 元素块的存在使得随意进行行列变换称为可能，因此分块操作无法适用于没有全零元素的情况。

4. 行列式按行（列）展开

低阶行列式的计算显然要比高阶行列式简单许多，我们考虑如何将一个高阶的行列式降阶从而便于进行计算处理。先定义代数余子式。

在 n 阶行列式中，把 $(i, j)$ 元 $a_{i j}$ 所在的第 $i$ 行第 j 列划去以后，留下的 $\mathrm{n}-1$ 阶行列式叫做 $a_{i j}$的余子式, 记作 $M_{i j}$ ，赋以由坐标确定的符号元 $(-1)^{i+j}$ 后得到的 $A_{i j}=(-1)^{i+j} M_{i j}$ 称为 $a_{i j}$ 的代数余子式。

我们有如下的行列式按照行 (列) 的展开法则：行列式等于它的任一行的各元素与其代数余子式的乘积之和，即

$$
D=\sum_{k=1}^{n} a_{i k} A_{i k}
$$

Prov. 先考虑第 $i$ 行上除了 $a_{i j}$ 其余的元都为零的情形，此时表达式退化为简单的

$$
D=a_{i j} A_{i j}
$$

当 $a_{i j}=a_{11}$ 位于左上角时, 根据行列式分块的性质立刻可知结论成立, 若不然, 则将元素通过对换移到左上角, 显然对换次数为 $i+j-2$, 因此需要赋予一个符号 $(-1)^{i+j-2}=$ $(-1)^{i+j}$ ，这正是代数余子式符号的功能。

对于一般情况，只需要根据拆分操作将一行的每一个元素拆分都成 n 个数的和，另外 $\mathrm{n}-1$ 个数均为零，则拆分后的每一个行列式退化为上面考虑的简单情况，加和后原命题证毕。

结合"行相同为零"定理可知: 行列式某一行的元素与另一行的对应元素的代数余子式乘积之和等于零。故一般地有

$$
D=\sum_{k=1}^{n} a_{i k} A_{j k}= \begin{cases}D, & \text { 当 } i=j \\ 0, & \text { 当 } i \neq j\end{cases}
$$



