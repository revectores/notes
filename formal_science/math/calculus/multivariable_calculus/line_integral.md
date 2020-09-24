# Line Integral

$$
\newcommand{\euler}{\text{e}}
\newcommand{\p}{\part}
\newcommand{\px}{\p x}
\newcommand{\py}{\p y}
\newcommand{\pz}{\p z}
\newcommand{\pf}{\p f}
\newcommand{\pu}{\p u}
\newcommand{\pv}{\p v}
\newcommand{\pl}{\p \boldsymbol{l}}

\newcommand{\d}{\text{d}}
\newcommand{\dt}{\d t}
\newcommand{\dx}{\d x}
\newcommand{\dy}{\d y}
\newcommand{\dr}{\d r}
\newcommand{\dv}{\d v}
\newcommand{\dz}{\d z}
\newcommand{\du}{\d u}
\newcommand{\ds}{\d s}
\newcommand{\pp}[2]{\frac{\part #1}{\part #2}}
\newcommand{\dxy}{\dx\dy}
$$

##### # Scalar Line Integral

$$
\int_L f(x ,y)\ds = \int_\alpha^\beta f[\varphi(t), \psi(t)]\sqrt{\varphi'^2(t)+\psi(t)'^2}\dt~~~~(\alpha < \beta)
$$

That is, when computing the scalar line integral, we're required to

Specially, if we consider the $x$ or $y$ as the parameters, we have
$$
\int_L f(x ,y)\ds = \int_a^b f(x, y(x))\sqrt{1+y'^2(x)}\dt~~~~(a<b)
$$
or
$$
\int_L f(x ,y)\ds = \int_a^b f(y, x(y))\sqrt{x'^2(y)+1}\dt~~~~(a<b)
$$

>Compute $\displaystyle\int_L \sqrt y \ds$, where $L$ is from $(0, 0)$ to $(1,1)$ through $y=x^2$.

$$
\int_L \sqrt y = \int_0^1 \sqrt{x^2}\sqrt{1+(x^2)'^2}\dx = \int_0^1 x\sqrt{1+4x^2}\dx = \frac{1}{12}(5\sqrt5-1)
$$





##### # Vector Line Integral

Curve Integral
$$
\int_L P(x, y)\dx + Q(x, y)\dy
= \int_\alpha^\beta [P(\varphi(t), \psi(t))\varphi'(t) + Q(\varphi(t), \psi(t))\psi'(t)]\dt
$$
That is, when computing the vector line integral, we're required to 

Specially, if we consider the $x$ or $y$ as the parameters, we have
$$
\int_L P(x, y)\dx + Q(x, y)\dy
= \int_a^b [P(x, \psi(x)) + Q(x, \psi(x))\psi'(x) ]\dx
$$

or
$$
\int_L P(x, y)\dx + Q(x, y)\dy
= \int_a^b [P(\varphi(y), y)\varphi'(y) + Q(\varphi(y), y) ]\dy
$$

> Compute $\displaystyle \int_\Gamma(z-y)\dx + (x-z)\dy + (x-y)\dz$, where
> $$
> \Gamma:
> \left\{\begin{array}{ll}
> x^2 + y^2 = 1 \\
> x - y + z = 2
> \end{array}\right.
> $$
>
> The direction is clockwise from the perspective of $z$-axis.

$$
\left\{\begin{array}{ll}
x = \cos t \\
y = \sin t \\
z = 2 - \cos t + \sin t
\end{array}\right.
~~~~ t:2\pi\rightarrow 0
$$



##### # Relation Between Two Types of Line Integrals


$$
\int_L P\dx + Q\dy = \int_L \left( P\cos\alpha + Q\cos\beta \right)\ds
$$





##### # Green Formula

Types of domain: simply connected region, multiple connected region, unconnected region.

Define the direction of edge line $L$ of region $D$ as: the region $D$ must always on the left of $L$.

$$
\iint_D\left( \frac{\p Q}{\px} - \frac{\p P}{\py} \right)\dx\dy = \oint_L P\dx + Qdy
$$

> Proof. (1) If $D$ is both the X-type and Y-type
> $$
> \iint_D \pp Qx \dxy = \int_c^d\dy\int_{\psi_1(y)}^{\psi_2(y)}\pp Qx \dx
> $$
> That is,
> $$
> \iint_D \pp Qx \dxy = \oint_L Q(x,y)\dy
> $$
> Similarly,
> $$
> \iint_D -\pp Py \dxy = \oint_L P(x,y)\dx
> $$
> (2) If $D$ is not the X-type nor Y-type, we could divide $D$ into multiple regions that fits (1).
>
> 

**Application**. Compute the area of region using the vector line integral.
$$
2\iint_D\dx\dy = \oint_L x\dy - y\dx
$$

$$
A = \frac{1}{2}\oint_L x\dy - y\dx
$$

> Compute the area surrounded by $x=a\cos\theta, y=b\sin\theta$.
> $$
> A
> = \frac{1}{2}\oint x\dy - y\dx
> = \frac{1}{2}\int_0^{2\pi} (ab\cos^2\theta + ab\sin^2\theta)\d\theta
> = \pi ab
> $$



> If $L$ is the closed smooth curve, prove
> $$
> \oint_L 2xy\dx + x^2\dy = 0
> $$

Here $P = 2xy, Q = x^2$, based on the green formula, we have
$$
\oint_L 2xy\dx + x^2\dy = \iint_D (2x - 2x)\dxy = 0
$$



> Compute $\displaystyle \oint_L \frac{x\dy - y\dx}{x^2+y^2},$ where $L$ is the continous smooth closed curve with no repeated point, which does not pass $(0, 0)$. The direction of $L$ is counterclockwise.

Here $P = -\dfrac{x}{x^2+y^2},~~Q = \dfrac{x}{x^2+y^2}$, hence when $x^2+y^2\neq 0$, we have
$$
\pp Qx = \frac{y^2-x^2}{(x^2+y^2)^2} = \pp Py
$$
if $(0,0)\notin D$, we have
$$
\oint_L \frac{x\dy - y\dx}{x^2+y^2} = 0
$$
if $(0,0)\in D$, we construct a small circle $l: x^2+y^2=r^2$ with $r>0$, use the counterclockwise as the direction of $l$, we have
$$
\oint_{L\bigcup l^-} \frac{x\dy - y\dx}{x^2+y^2} + \oint_{l} \frac{x\dy - y\dx}{x^2+y^2}
= \int_0^{2\pi} \frac{r^2\cos^2\theta + r^2\sin^2\theta}{r^2}\d\theta = 2\pi
$$
**Remark**. This example reminds the condition of green function: the constructed $P(x), Q(y)$ must have first-order continous partial derivative on the entire region $D$, if the condition is not complyed, we can exclude those points by constructing new regions.



> Compute $\displaystyle \iint_D \euler^{-y^2}\dx\dy$, where $D$ is the triangle with vertex $O(0,0), A(1,1), B(0,1)$.

Let $P=0,~ Q= x\euler^{-y^2}$, we have
$$
\iint_D \euler^{-y^2}\dx\dy = \int_{OA+AB+BO} x\euler^{-y^2}\dy = \int_0^1 x\euler^{-x^2}\dx = \frac{1}{2}(1-\euler^{-1})
$$




##### # Condition of Line Integral is Path Irrelevant


$$
\frac{\p P}{\py} = \pp Q x
$$

