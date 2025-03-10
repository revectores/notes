# Vandermonde determinant

范德蒙德行列式定义为如下形式的行列式, 其值有特殊形式

$$
D_{n}=\left|\begin{array}{cccc}
1 & 1 & \ldots & 1 \\
x_{1} & x_{2} & \ldots & x_{n} \\
x_{1}^{2} & x_{2}^{2} & \ldots & x_{n}^{2} \\
\ldots & \ldots & \ldots & \ldots \\
x_{1}^{n-1} & x_{2}^{n-1} & \ldots & x_{n}^{n-1}
\end{array}\right|=\prod_{1 \leq i<j \leq n}\left(x_{i}-x_{j}\right)
$$

证明. 考虑数学归纳法. 对于

$$
D_{2}=\left|\begin{array}{cc}
1 & 1 \\
x_{1} & x_{2}
\end{array}\right|=x_{2}-x_{1}
$$

成立. 因此当二阶的情况下命题成立. 假设对于 $n-1$ 阶的情况成立，设法将 n 阶时的情况降阶到 $n-1$ 阶

$$
D_{n}=\left|\begin{array}{cccc}
1 & 1 & \ldots & 1 \\
0 & x_{2}-x_{1} & \ldots & x_{n}-x_{1} \\
0 & x_{2}\left(x_{2}-x_{1}\right) & \ldots & x_{n}\left(x_{n}-x_{1}\right) \\
\ldots & \ldots & \ldots & \ldots \\
0 & x_{2}^{n-2}\left(x_{2}-x_{1}\right) & \ldots & x_{n}^{n-2}\left(x_{n}-x_{1}\right)
\end{array}\right|
$$

按第一列展开并提出每列的公因子 $x_{i}-x_{1}$

$$
D_{n}=\prod_{1<i \leq n}\left(x_{i}-x_{1}\right)\left|\begin{array}{cccc}
1 & 1 & \ldots & 1 \\
x_{2} & x_{3} & \ldots & x_{n} \\
\ldots & \ldots & \ldots & \ldots \\
x_{2}^{n-2} & x_{3}^{n-2} & \ldots & x_{n}^{n-2}
\end{array}\right| \stackrel{\text { 归纳假设 }}{\Longrightarrow} \prod_{1 \leq i<j \leq n}\left(x_{i}-x_{j}\right)
$$

