# Lotka-Volterra Predation Model

$$
\newcommand{\d}{\text d}
\newcommand{\dt}{\d t}
\newcommand{\dN}{\d N}
\newcommand{\dP}{\d P}
$$

设猎物种群数量为$N$, 捕食者种群数量为$P$, 假设猎物种群在没有捕食者的存在下指数增长, 捕食者种群在没有猎物的条件下指数减少, 捕食者和猎物之间的相遇概率取决于二者种群数量之积, 则有**Lotka-Volterra捕食者-猎物模型(Lotka-Volterra predation model)**.

$$
\left\{\begin{array}{ll}\begin{align}
& \frac{\dN}{\dt} = r_1N - \varepsilon PN \\
& \frac{\dP}{\dt} = -r_2P + \theta PN
\end{align}\end{array}\right.
$$
式中$\varepsilon$为捕食者进攻效率, $\theta$为捕食者常数[^1]. 两式分别称为**猎物方程**和**捕食者方程**.





[^1]: 捕食者利用猎物而转变为更多捕食者的效率.

