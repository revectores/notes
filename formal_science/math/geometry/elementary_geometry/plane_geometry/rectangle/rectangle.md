# Rectangle

$$
\newcommand{\v}{\overrightarrow}
$$

For the rectangle $ABCD$ and any point $P$, we have $PA^2 + PC^2 = PB^2+ PD^2$.

> **Proof**. $\v{PA} + \v{PC} = 2\v{PO}, \v{PA} - \v{PC} = \v{CA}$, hence
> $$
> PA^2 + PC^2 = 4PO^2 + CA^2 = 4PO^2 + DB^2 = PB^2 + PD^2
> $$

**Remark**. Since the proof is purely the algebraic computation, the position of $P$ could be at anywhere in the space, not limited on the plane $ABCD$.

> **Example**. For $Rt\triangle ABC$ where $\angle C = \pi/2$, if some point $P$ in the plane fits $\v{PA} + \v{PB} + \lambda\v{PC} = \v 0$, denoted
> $$
> m = \dfrac{PA^2 + PB^2}{PC^2}
> $$
> (i) When $\lambda = 1$, find $m$.
>
> (ii) Find the minimum value of $m$.
>
> **Solution**. (i) For $\lambda = 1$, we have $\v{PA} + \v{PB}+ \v{PC} = 1$, in this case $P$ is the center of gravity for $\triangle ABC$, $P$ located on the middle on $AB$.
>
> (ii) Construct a rectangle $ACBE$, we have
> $$
> \frac{PA^2 + PB^2}{PC^2}
> = \frac{PC^2 + PE^2}{PC^2}
> = 1 + \frac{PE^2}{PC^2}
> $$
> Hence the $m$ is minimal iff $PE^2/PC^2$ is minimal, that is, $P=E$ and $m_\min = 1$.

