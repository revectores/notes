# Weitzenberk Inequality

**外森比克不等式(Weitzenberk inequation)**描述了三角形三边长和面积的关系
$$
\sum a^2 \ge 4\sqrt3 S
$$

当且仅当三角形为正三角形时等号成立.

> **Proof 1**.
> $$
> \begin{align}
> a^2 + b^2 + c^2 - 4\sqrt3 S
> &= a^2 + b^2 + a^2 + b^2 - 2ab\cos C - 2\sqrt3 ab\sin C \\
> &= 2[a^2+b^2-2ab\sin(C+\frac{\pi}{6})] \\
> &\ge 2(a^2+b^2-2ab) \ge 0 \\
> \end{align}
> $$
> 因此原不等式得证, 当且仅当$C=\pi/3$且$a=b$, 即为正三角形时等号成立. 
>

> **Proof 2**.
>
> 想到海伦公式应当是一件非常自然的事情, 因为海伦公式描述的也是三角形三边同面积的关系, 而且还和Weitzenberk不等式一样是一个三边的轮换对称式. 因此利用海伦公式理应可以很自然地导出Weitzenberk不等式:
> $$
> \begin{align}
> 4S
> &= \sqrt{p(p-a)(p-b)(p-c)} \\
> &= \sqrt{(a+b+c)(b+c-c)(a+c-b)(a+b-c)} \\
> &\le \sqrt{(a+b+c)\left(\frac{a+b+c}{3}\right)^3} \\
> &= \frac{(a+b+c)^2}{3\sqrt3} \\
> &= \frac{3(a^2+b^2+c^2)-(a-b)^2-(b-c)^2-(c-a)^2}{3\sqrt{3}} \\
> &\le \frac{a^2+b^2+c^2}{\sqrt{3}}
> \end{align}
> $$
> 从而原不等式得证. 当且仅当$b+c-a=a+c-b=a+b-c$且$a=b=c$, 即三角形是等边三角形时等号成立. (这里很特别, 因为前后两个条件是等效的, 当然出于对称性的缘故其实并不难以理解)
>
> 其实这里中间还可以得到一个三边和与面积的关系: 
>
> $$
> (a+b+c)^2 \ge 12\sqrt 3 S
> $$
> 这个证明过程中的关键步骤之一(另外一个关键步骤是应用立方形式的均值不等式)是将和的平方转化为平方和: 
>
> $$
> (a+b+c)^2 + (a-b)^2 + (b-c)^2 + (c-a)^2 = 3(a^2+b^2+c^2)
> $$
> 这个恒等式的形式值得记住. 
>
> 从海伦法证明过程中很容易给到W不等式的一个加强:
> $$
> \sum a^2 \ge 4\sqrt3 S + \sum (a-b)^2
> $$
> 这个加强被称为Finsler-Hadwiger不等式.


