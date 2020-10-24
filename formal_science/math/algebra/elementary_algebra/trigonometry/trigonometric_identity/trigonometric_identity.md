# Trigonometric Identity

##### # Sum/Difference of Angles

The **sum formula** and **difference formula** for $\sin, \cos, \tan$:

$$
\begin{align}
&\cos(\alpha+\beta) = \cos\alpha \cos\beta - \sin\alpha \sin\beta \\
&\cos(\alpha-\beta) = \cos\alpha \cos\beta + \sin\alpha \sin\beta \\
&\sin(\alpha+\beta) = \sin\alpha \cos\beta + \cos\alpha \sin\beta \\
&\sin(\alpha-\beta) = \sin\alpha \cos\beta - \cos\alpha \sin\beta \\
&\tan(\alpha+\beta) = \dfrac{1+\tan\alpha\tan\beta}{\tan\alpha\tan\beta} \\
&\tan(\alpha-\beta) = \dfrac{1-\tan\alpha\tan\beta}{\tan\alpha\tan\beta}
\end{align}
$$

The difference formula for tangent inferred that, for the two line with slope $k_1, k_2$, the intersection angle can be computed by

$$
\tan\theta = \left| \frac{k_2-k_1}{1+k_1k_2} \right|
$$



##### # Multiple Angle Formula

Specially, let $\alpha = \beta$ in the sum formula we got the **double angle formual**
$$
\begin{align}
&\sin2\alpha = 2\sin\alpha\cos\alpha \\
&\cos2\alpha = \cos^2\alpha - \sin^2\alpha = 2\cos^2\alpha - 1 = 1 - 2\sin^2\alpha \\
&\tan2\alpha = \dfrac{2\tan\alpha}{1-\tan^2\alpha}
\end{align}
$$

With identical transformation this can be applied to remove exponent from the trigonometric function:
$$
\begin{align}
&\sin^2 \alpha = \frac{1}{2}(\cos2\alpha-1) \\
&\cos^2 \alpha = \frac{1}{2}(\cos2\alpha+1) \\
&\tan^2 \alpha = 1 - \frac{2\tan\alpha}{\tan 2\alpha}
\end{align}
$$
Furthermore we can get **triple angle formula**
$$
\begin{align}
\sin 3\alpha &= 3\sin\alpha - 4\sin^2\alpha \\
\cos 3\alpha &= -3\cos\alpha + 4\sin^2\alpha \\
\tan 3\alpha &= \frac{3\tan\alpha - \tan^3\alpha}{1-3\tan^2\alpha} = \tan\alpha \tan\left( \frac{\pi}{3} + \alpha \right) \tan\left( \frac{\pi}{3} - \alpha \right)
\end{align}
$$


##### # POS & SOP Formula

$$
\begin{align}
& \sin\alpha \cos\beta = \frac{\sin(\alpha+\beta) + \sin(\alpha-\beta)}{2} \\
& \cos\alpha \cos\beta = \frac{\cos(\alpha+\beta) + \cos(\alpha-\beta)}{2} \\
& \sin\alpha \sin\beta = \frac{-\cos(\alpha+\beta) + \cos(\alpha-\beta)}{2} \\
\end{align}
$$



$$
\begin{align}
& \sin\alpha + \sin\beta = 2\sin{\frac{\alpha+\beta}{2}} \cos{\frac{\alpha-\beta}{2}} \\
& \sin\alpha - \sin\beta = 2\cos{\frac{\alpha+\beta}{2}} \sin{\frac{\alpha-\beta}{2}} \\
& \cos\alpha + \cos\beta = 2\cos{\frac{\alpha+\beta}{2}} \cos{\frac{\alpha-\beta}{2}} \\
& \cos\alpha - \cos\beta = -2\sin{\frac{\alpha+\beta}{2}} \sin{\frac{\alpha-\beta}{2}} \\
\end{align}
$$



##### # Identity Inside Triangle

$$
\begin{align}
& \sin(A+B) = \sin C,~~~~ \cos(A+B) = -\cos C \\
& \sin\frac{A+B}{2} = \cos\frac{C}{2}, ~~~~ \cos\frac{A+B}{2} = \sin\frac{C}{2}
\end{align}
$$


$$
\begin{align}
& \sin A + \sin B + \sin C = 4\cos\frac{A}{2} \cos\frac{B}{2} \cos\frac{C}{2} \\
& \cos A + \cos B + \cos C = 1 + 4\sin\frac{A}{2} \sin\frac{B}{2} \sin\frac{C}{2} \\
& \tan A + \tan B + \tan C = \tan A \tan B \tan C
\end{align}
$$

> **Proof ** .
> $$
> \begin{align}
> \sin A + \sin B + \sin C
> &= 2\sin\frac{A+B}{2}\cos\frac{A-B}{2} + \sin(A+B) \\
> &= 2\sin\frac{A+B}{2}\cos\frac{A-B}{2} + 2\sin\frac{A+B}{2}\cos\frac{A+B}{2} \\
> &= 4\sin\frac{A+B}{2} \cos\frac{A}{2}\cos\frac{B}{2} \\
> &= 4\cos\frac{A}{2} \cos\frac{B}{2} \cos\frac{C}{2}
> \end{align}
> $$
> The property of sum of cosine can be proved similarly.
>
> For tangent, we have
> $$
> \tan C = \tan(A+B) = \frac{\tan A + \tan B}{1-\tan A \tan B}
> $$
> multiplying $1-\tan A\tan B$ on both sides:
> $$
> \tan C - \tan A\tan B\tan C = \tan A+\tan B
> $$
> which gives the formula above.

We can introduce amounts of properties from the equation of tangent, i.e. with the help of [AM-GM inequality]() we have
$$
\tan A \tan B \tan C \ge 3\sqrt3
$$
Both sides are equal if and only if its equilateral triangle.




