### Offset of Extrema

Definition: The (local) **Extreme Point** is the $x$-coordinate of the extreme value.

First we consider about the non-offset normal case, the perfect quadratic function $f(x)$, the only axis of symmetry passes the extreme value of the function, which makes the middle of two roots is located on the extreme point exactly: $x_1 + x_2 = 2a$. Generally, if two input $x_1, x_2$ share the same output $f(x_1) = f(x_2) = c$, there must be $x_1 + x_2 = 2a$.

<img src="symmetry_points_of_quadratic_function.png"/>

==TODO Scratch: symmetry points on the uadratic function==

For the function so-called extrema offseted, the middle of two roots may locate on the left or right of the extreme point, $x_1+x_2 > 2a \ \ \text{or}\ \  x_1+x_2<2a$.

Assume a specific function $f(x)$ is given, if we find 

我们要如何形式地证明这一点呢？

不妨只研究(1)，并且函数在极值点左边递增，右边递减，固定极值点为$x=1$(Fig.3), (*) 对于这个函数来说，为了证明(1)，想象作为一个登山者，(1)意味着从极值点出发，向右边走到达某一个高度（函数值）需要比向左边走到达同样的高度（函数值）走更远的距离（为什么？），这等效于：走相同的距离，向右边上升的高度更小，形式化地说，就是对于任意$t>0$,
$$
f(1-t)>f(1+t)
$$
换用通常的记号使用方式，对于位于同一高度（函数值相等）的两个点$x_1<1<x_2$, 不妨以左边的点为基准，需要证明
$$
f(x_1) > f(2-x_1)  ··· (2)
$$
这个问题通过构造函数$F(x) = f(x) - f(2-x)$是容易证明的.

根据上面的思想实验我们知道(2)一定蕴涵着(1), 而(2)是函数值的大小关系，(1)是自变量的大小关系. 而实现这二者转化的通常方式就是**借助单调性**.

注意到$2-x_1$与$x_2$都在极值点的右边，也就是落在同一个单调区间内，为此把左边的$f(x_1)$换成$f(x_2)$之后，就可以利用单调性去掉$f$.



1. For $f(x) = -xe^{-x}$, check if the function fit the condition (*), and prove (1).

2. Consider the electric showed in Fig.P2.

   1) Prove that the relationship between output power $P_O$ and external resistence $R$ fit

$$
P_O = \cfrac{E^2}{R+\cfrac{r^2}{R}+2r}
$$

​	(2) 说明如何证明对于使电源产生相同输出功率的两个外电阻值$R_1,R_2$.成立 $R_1+R_2>2r$（你可以假设所构造的函数具备所需要的单调性，不必求导计算，关键是理解证明的结构）

​	(3) 证明输出功率相同的两个外电阻值$R1, R_2$满足$R_1·R_2 = r^2$, 然后证明(2)

