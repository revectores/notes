### Triangle Half Tangent Equality

$$
\sum \tan\frac{A}{2}\tan\frac{B}{2} = 1
$$

Denotes $(x, y, z) = (A/2, B/2, C/2)$, we can convert the expressoin about the angles inside triangle into the algebraic problem with limit $\displaystyle \sum xy = 1$

> Example. Prove in $\triangle ABC$
> $$
> \displaystyle \sum \sin\frac{A}{2}\le \frac{3}{2}
> $$
> **Proof**.
> $$
> \begin{align}
> \sin\frac{A}{2}
> &= \frac{\sqrt{\sin^2\dfrac{A}{2}}}{\sin^2\dfrac{A}{2} + \cos^2\dfrac{A}{2}} \\
> &= \frac{\sqrt{\tan^2\dfrac{A}{2}}}{\tan^2\dfrac{A}{2} + 1} \\
> &= \sqrt{\frac{x^2}{x^2+xy+yz+zx}} \\
> &= \sqrt{\frac{x}{x+y}}\sqrt{\frac{x}{x+z}} \\
> \end{align}
> $$
> Hence
> $$
> \displaystyle \sum \sin\frac{A}{2}
> = \sqrt{\frac{x}{x+y}}\sqrt{\frac{x}{x+z}}
> \le \frac{1}{2}\sum \left( \frac{x}{x+y} + \frac{x}{x+z}\right)
> = \frac{3}{2}
> $$



> Example. Prove in $\triangle ABC$
> $$
> \sum \tan\frac{A}{2} \prod\tan\frac{A}{2} \le \frac{1}{3}
> $$
> **Proof**.
> $$
> \begin{align}
> \sum \tan\frac{A}{2} \prod\tan\frac{A}{2}
> &= \sum(xy+yz) \\
> &\le \frac{1}{3}\sum(x^2y^2+2xy\cdot yz) \\
> &= \frac{1}{3} \left(\sum xy \right)^2 = \frac{1}{3}
> \end{align}
> $$



