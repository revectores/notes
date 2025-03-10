T1. （同济线性代数 C1T6）证明：
$$
\left|\begin{array}{ccc}
a^{2} & a b & b^{2} \\
2 a & a+b & 2 b \\
1 & 1 & 1
\end{array}\right|=(a-b)^{3}
$$
$$
\left|\begin{array}{lll}
a x+b y & a y+b z & a z+b x \\
a y+b z & a z+b x & a x+b y \\
a z+b x & a x+b y & a y+b z
\end{array}\right|=\left(a^{3}+b^{3}\right)\left|\begin{array}{lll}
x & y & z \\
y & z & x \\
z & x & y
\end{array}\right|
$$
(3)
$$
\left|\begin{array}{cccc}
a^{2} & (a+1)^{2} & (a+2)^{2} & (a+3)^{2} \\
b^{2} & (b+1)^{2} & (b+2)^{2} & (b+3)^{2} \\
c^{2} & (c+1)^{2} & (c+2)^{2} & (c+3)^{2} \\
d^{2} & (d+1)^{2} & (d+2)^{2} & (d+3)^{2}
\end{array}\right|=0
$$

证 考虑降次，分别将 2,3,4 列减去第一列得到
$$
r_{1}=\left(a^{2}, 2 a+1,4 a+4,6 a+9\right)
$$

继续作减法试图构造出相同或成比例的两列：
$$
r_{1}=\left(a^{2}, 2 a+1,2 a+3,6 a+9\right)
$$

到这一步我们已经发现 3,4 两列成比例，即证。
(4)
$$
\left|\begin{array}{cccc}
1 & 1 & 1 & 1 \\
a & b & c & d \\
a^{2} & b^{2} & c^{2} & d^{2} \\
a^{4} & b^{4} & c^{4} & d^{4}
\end{array}\right|=(a-b)(a-c)(a-d)(b-c)(b-d)(c-d)(a+b+c+d)
$$

证 注意到右边是四阶范德蒙德行列式乘一个系数 $(a+b+c+d)$ 的形式，因此只需要尝试证明
$$
\left|\begin{array}{cccc}
1 & 1 & 1 & 1 \\
a & b & c & d \\
a^{2} & b^{2} & c^{2} & d^{2} \\
a^{4} & b^{4} & c^{4} & d^{4}
\end{array}\right|=(a+b+c+d)\left|\begin{array}{cccc}
1 & 1 & 1 & 1 \\
a & b & c & d \\
a^{2} & b^{2} & c^{2} & d^{2} \\
a^{3} & b^{3} & c^{3} & d^{3}
\end{array}\right|
$$

为了构造出四次项，考虑将系数乘到最后一行中：
$$
r_{4}=a^{4}+a^{3}(b+c+d)
$$

但这一操作带来了额外的三次项，为对称地消去它们，考虑以在第三行的基础上乘上轮换对称的二次式 $p=a b+a c+a d+b c+b d+c d$ 作为减数执行消去操作。
$$
r_{4}=a^{4}-a^{2}(b c+b d+c d)
$$

继续用轮换对称的 $a(b c d+a c d+a b d+a b c)$ 处理：
$$
r_{4}=a^{4}+a b c d=a^{4}
$$

即证。






$$
\left|\begin{array}{cccc}
x & -1 & 0 & 0 \\
0 & x & -1 & 0 \\
0 & 0 & x & -1 \\
a_{0} & a_{1} & a_{2} & a_{3}
\end{array}\right|=a_{3} x^{3}+a_{2} x^{2}+a_{1} x+a_{0}
$$









T2. 设 $n$ 阶行列式 $D=\operatorname{det}\left(a_{i j}\right)$ ，把 $D$ 上下翻转、或逆时针旋转 $90^{\circ}$ 、或依副对角线翻转，依次得
$$
D_{1}=\left|\begin{array}{ccc}
a_{n i} & \ldots & a_{n n} \\
\ldots & & \ldots \\
a_{11} & \ldots & a_{1 n}
\end{array}\right|, \quad D_{2}=\left|\begin{array}{ccc}
a_{1 n} & \ldots & a_{n n} \\
\ldots & & \ldots \\
a_{11} & \ldots & a_{n 1}
\end{array}\right|, \quad D_{3}=\left|\begin{array}{ccc}
a_{n n} & \ldots & a_{1 n} \\
\ldots & & \ldots \\
a_{n 1} & \ldots & a_{11}
\end{array}\right|
$$

证明: $D_{1}=D_{2}=(-1)^{\frac{\mathrm{n}(\mathrm{n}-1)}{2}}, D_{3}=D$
T3.
T4.
T5.
T6.
T7.
18.

T9.
T10. 是