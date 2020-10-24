# Surface Integral

$$
\newcommand{\euler}{\text{e}}
\newcommand{\p}{\partial}
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
\newcommand{\dS}{\d S}
\newcommand{\pp}[2]{\frac{\partial #1}{\partial #2}}
\newcommand{\dd}[2]{\d #1 \d #2}
\newcommand{\dxy}{\dx\dy}
\newcommand{\dyz}{\dy\dz}
\newcommand{\dzx}{\dz\dx}
\newcommand{\b}{\boldsymbol}
$$

### 1. Scalar Surface Integral

$$
\iint_\Sigma f(x,y,z)\dS = \iint_{D_{xy}} f(x,y,z(x,y))\sqrt{1+z_x^2+z_y^2} \dxy
$$



### 2. Vector Surface Integral

$$
\iint_\Sigma R(x,y,z)\dxy = \iint_{D_{xy}} R[x,y,z(x,y)]\dxy
$$

where the $\Sigma$ is oriented surface using the "upper" surface as positive, the direction should be noticed during calculation.

> Example. Compute the surface integral
> $$
> \iint_\Sigma x^2\dyz + y^2\dzx + z^2\dxy
> $$
> where $\Sigma$ is the outside of cuboid $\Omega:\{(x,y,z)|0\le x\le a,~ 0\le y\le b,~ 0\le z\le c\}$.
>
> We devide the $\Sigma = \bigcup_{i=1}^6 \Sigma_i$ as the six plain surface, while the the projections of four of them in $xOy$ are 0, hence we only need to compute the upper surface $\Sigma_1: z=0~~(0\le x\le a, 0\le y\le b)$ and the bottom surface $\Sigma_2: z=c~~(0\le x\le a, 0\le y\le b)$ for part $z^2\dxy$.
> $$
> \iint_\Sigma z^2\dxy = \iint_{\Sigma_1} c^2\dxy - \iint_{\Sigma_2} 0\dxy = abc^2
> $$
> Similarly we have
> $$
> \iint_\Sigma x^2\dyz = \iint_{\Sigma_3} a^2\dyz - \iint_{\Sigma_4} 0\dyz = a^2bc
> $$
> and
> $$
> \iint_\Sigma y^2\dzx = \iint_{\Sigma_5} b^2\dzx - \iint_{\Sigma_6} 0\dyz = ab^2c
> $$
> hence
> $$
> \iint_\Sigma x^2\dyz + y^2\dzx + z^2\dxy = abc(a+b+c)
> $$



>Example. Compute the surface integral $\displaystyle \iint_\Sigma xyz\dxy$, where $\Sigma$ is the outside of sphere $x^2+y^2+z^2=1$ in the 1st and 8nd octant.

$$
\int_{\Sigma} xyz\dxy
= 2\iint_{\Sigma_1}xyz\dxy
= 2\iint_D xy\sqrt{1-x^2-y^2}\dxy
$$

Notice that although the integrated function $xyz$ is the odd function respect to $z$, the integral is double instead of 0 due to the surface integral is **oriented**.

> Example. Denoted $S$ as the outside of $x^2+y^2+z^2=1$, compute
> $$
> I = \iint_S \frac{2\dyz}{x\cos^2x} + \frac{\dzx}{\cos^2 y} - \frac{\dxy}{z\cos^2 z}
> $$
> Notice that
> $$
> \iint_S \frac{2\dyz}{x\cos^2x} = \iint\frac{2\dxy}{z\cos^2 z}
> $$
>
> $$
> I
> = \iint_S \frac{\dxy}{z\cos^2 z} = 2\iint_{x^2+y^2\le1} \frac{\dxy}{\sqrt{1-x^2-y^2}\cos^2\sqrt{1-x^2-y^2}}
> $$
>
> 





### 3. Relation Between Two Surface Integral

$$
\iint_\Sigma P\dd yz + Q\dd zx + R\dxy = \iint_\Sigma(P\cos\alpha+Q\cos\beta+R\cos\gamma)\dS
$$

where the $(\cos\alpha, \cos\beta, \cos\gamma)$ is the directional cosine of the normal vector of oriented surface $\Sigma$ at point $\b{n}=(x,y,z)$. Denoted $A=(P,Q,R)$, the equation can also been represented as
$$
\iint_\Sigma \b A\cdot \d\b S = \iint_\Sigma \b A\cdot \b n\dS = \iint_\Sigma A_n\dS
$$

where $\d\b S=\b n\dS$ is defined as the **element of oriented surface**, $A_n$ is the projection of vector $\b A$ in vector $\b n$.

> Proof
> $$
> \iint_\Sigma P\dd yz + Q\dd zx + R\dxy
> = \lim_{\lambda\rightarrow0}\sum_{i=1}^n\left[ P \right]
> $$
> 



Specially, projecting into the $xOy$ plane:
$$
\iint_\Sigma P\dd yz + Q\dd zx + R\dxy = \iint [P(-z_x) + Q(-z_y) + R]\dxy
$$
The integral can also be projected into $yOz$ and $zOx$ plane by similarly.





> Example. Compute the surface integral $\displaystyle \iint_\Sigma (z^2 + x)\dyz - z\dxy$, where $\Sigma$ is $z=\dfrac{1}{2}(x^2+y^2)$ between $z=0$ and $z=2$.

$$
\b n = (\cos\alpha, \cos\beta, \cos\gamma) = \frac{1}{\sqrt{x^2+y^2+1}}(x, y, -1)
$$


$$
\begin{align}
\iint_\Sigma (z^2+x)\dyz
&= \iint_\Sigma (z^2+x)\cos\alpha \dS \\
&= \iint_\Sigma (z^2+x)\frac{\cos\alpha}{\cos\gamma}\dxy \\
&= \iint_\Sigma (z^2+x)(-x)\dxy \\
&= -\iint_\Sigma (xz^2 + x^2)\dxy
\end{align}
$$
Intrinsically, we convert the $\dyz$ into $\dxy$ by multiplying $z_x$, that is,
$$
\dyz = (-z_x)\dxy = (-x)\dxy \\
\dzx = (-z_y)\dxy = (-y)\dxy 
$$
Similarly process can be applied for other conversion.





### 4. Gauss Formula

Gauss formula gives the relation between the triple integral in the closed region and the surface integral of the surface of the region.

$$
\iiint_\Omega \left( \pp Px + \pp Qy + \pp Rz \right)\dv = \oiint_\Sigma P\dd yz + Q\dd zx + R\dd xy = \oiint_\Sigma (P\cos\alpha + Q\cos\beta +R\cos\gamma)\dS
$$





### 5. Stokes Formula

Stokes formula is the extension of [Green formula](). Green formula gives the relation between the integral between line integral and the double integral on the coordinates plane, while Stokes formula extended the double integral into arbitrary suface $\Sigma$.

$$
\iint_{\Sigma} \left( \pp Ry - \pp Qz \right)\dd yz
+ \iint_{\Sigma} \left( \pp Pz - \pp Rx \right)\dd zx
+ \iint_{\Sigma} \left( \pp Qx - \pp Py \right)\dd xy = \oint_\Gamma P\dx + Q\dy + R\dz
$$

The Stokes formula can also be denoted as the determinant form:

$$
\begin{vmatrix}
\dd yz & \dd zx & \dd xy  \\
\dfrac{\p}{\p x} & \dfrac{\p}{\p y} & \dfrac{\p}{\p z} \\
P & Q & R
\end{vmatrix}
=\begin{vmatrix}
\cos\alpha & \cos\beta & \cos\gamma  \\
\dfrac{\p}{\p x} & \dfrac{\p}{\p y} & \dfrac{\p}{\p z} \\
P & Q & R
\end{vmatrix}

= \oint_\Gamma P\dx + Q\dy + R\dz
$$



































