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
$$

# Double Integral

### 1. Double Integral

##### # Definition

For the function bounded within closed area $D$, devide D into arbitrary $n$ closed area $\{\Delta\sigma_i | 1\le i\le n\}$, and pick arbitrary point $(\xi_i, \eta_i)\in\Delta\sigma_i$, define the double integral of function $D$
$$
\iint_D f(x, y)\d\sigma = \lim_{\lambda\rightarrow 0}\sum_{i=1}^nf(\xi_i, \eta_i)\Delta\sigma_i
$$
if the limit exists for all the methods of devision. The $f(x, y)$ is called **integrand**, $f(x, y)\d\delta$ is the integral expression, $\d\sigma$ is the **area element**, $D$ is the **integral area**. the sum $\displaystyle \sum_{i=1}^nf(\xi_i, \eta_i)\Delta\sigma_i$ is named **integral sum**.

Specially, in the rectangular coordinates, the area element can be denoted as $\d\sigma = \dx\dy$, and the notion and defintion can be expressed as
$$
\iint_D f(x, y)\dx\dy = \lim_{(x, y)\rightarrow(0,0)}\sum_{i=1}^n f(\xi_i, \eta_i)\Delta x_j\Delta y_k
$$
where the $\dx\dy$ is called the area element in the rectangular coordinates.



##### # Physical Significance

Two physical significances are introduced for double integral:

- The volume under curve $f(x, y)$
    $$
    V = \iint f(x, y)\d\sigma
    $$

- The mass of a slice, with density distribution $\rho(x, y)$: 
    $$
    m = \iint \rho(x, y)\d\sigma
    $$
    

##### # Property of Double Integral

The property of double integral is similar to the single variable case:

**1. Linearity.** For the constant $\alpha, \beta$
$$
\iint_D[\alpha f(x, y) + \beta g(x ,y )]\d\sigma = \alpha \iint f(x, y)\d\sigma + \beta\iint g(x, y)\d\sigma
$$
**2. Additivity**. For $D = D_1 \cup D_2$, we have
$$
\iint_D f(x, y)\d\sigma = \iint_{D_1} f(x, y)\d\sigma + \iint_{D_2}f(x, y)\d\sigma
$$
**3. Keep Inequality.** If $f(x, y)\le g(x, y)$ in $D$, then
$$
\iint_D f(x, y)\d\sigma \le \iint_D g(x, y)\d\sigma
$$
Specially, notice that $-|f(x, y)|\le f(x, y)\le |f(x, y)|$, hence
$$
\left\lvert \iint_D f(x, y)\d\sigma \right\rvert \le \iint_D |f(x, y)|\d\sigma
$$
Besides, if $M, m$ are the maximum and minimum of closed area $D$, and $\|D\| = \sigma'$, we have
$$
m\sigma' \le \iint_D f(x, y)\d\sigma \le M\sigma'
$$
This can be regarded as the estimation method of integral.

**4. Mean Value Theorem.** For the unction $f(x, y)$ that is continous in closed area $D$, and $\|D\| = \sigma'$, there must be at least one point $(\xi, \eta)$ which makes
$$
\iint_D f(x, y)\d\sigma = f(\xi, \eta)\cdot \sigma'
$$
which can be easily proved by the estimation property listed in property (3).



##### # Computation of Double Integral

If the integral area $D$ is the X-type area, that is, $D$ can be expressed by inequality $a\le x\le b, \varphi_1(x) \le y \le \varphi_2(x)$, where the function $\varphi_1(x), \varphi_2(x)$ is continous at interval $[a, b]$, we can prove that
$$
\iint_D f(x, y)\dx\dy = \int_a^b \left[ \int_{\varphi_1(x)}^{\varphi_2(x)} f(x, y)\dy \right] \dx
$$
For convenience, we also denoted this expression as
$$
\int_a^b \dx \int_{\varphi_1(x)}^{\varphi_2(x)} f(x, y)\dy
$$
Similarly, there also has the conversion for the Y-type area $D$, which can be expressed by $a\le y\le b, \varphi_1(x) \le x \le \varphi_2(x)$.
$$
\iint_D f(x, y)\dx\dy
= \int_a^b \left[ \int_{\varphi_1(y)}^{\varphi_2(y)} f(x, y)\dx \right] \dy
= \int_a^b \dy \int_{\varphi_1(y)}^{\varphi_2(y)} f(x, y)\dx
$$
For the complex area, we can always devide it into several X-type or Y-type areas, and using the adding property of integral listed in the last node.

Several examples for the computation of double integral are provided in [examples_for_double_integral_computation](examples_for_double_integral_computation.md).

We can also convert the integral in the rectangular coordinates into polar coordinates:
$$
\iint_D f(x, y)\dx\dy = \iint_D f(\rho\cos\theta, \rho\sin\theta)\rho~\d\rho\d\theta
$$
where the $\rho\d\rho\d\theta$ is the area element.



##### # Examples

> Compute the double integral $\displaystyle\iint_D \frac{\sin}{x}\dx\dy$ in $D = \{(x, y) | 0\le x\le \pi, 0\le y\le x \}$.

This is a classical example when the sequence of integral cannot be chosen arbitrarily.

==TODO: Adding the counterpart==
$$
\iint_D \frac{\sin}{x}\dx\dy
= \int_{0}^{\pi}\dx \int_{0}^{x}\frac{\sin x}{x}\dy
= \int_{0}^{\pi}\sin x \dx
= 2
$$
On the contrary, if we consider it as the X-type area:
$$
\iint_D \frac{\sin}{x}\dx\dy
= \int_{0}^{\pi}\dx \int_{0}^{x}\frac{\sin x}{x}\dy
= \int_{0}^{\pi}\sin x \dx
= 2
$$


> Compute the double integral $\displaystyle\iint_D x\ln(y + \sqrt{1+y^2})\dx\dy$ where $D$ is constructed by the surrounding of curves $y = 4-x^2, y = -3x, x = 1$.

This is a classical example to use the symmetry of area.
$$
\begin{align}
\iint_D x\ln(y + \sqrt{1+y^2})\dx\dy
= \int_{-1}^{1}\dx \int_{-3x}^{4-x^2} x\ln(y + \sqrt{1+y^2})\dy
\end{align}
$$
which is quite complex and hard to find the primitive function. The same complexity will arise if we reconsider it as the Y-type area. 

We notice that $D = D_1 \cup D_2$, where $D_1, D_2$ are symmetric about the $y$ and $x$ axis respectively, combining the parity of integrand $x\ln(y+\sqrt{1+y^2})$, we have
$$
\iint_D x\ln(y + \sqrt{1+y^2})\dx\dy
= \iint_{D_1} x\ln(y + \sqrt{1+y^2})\dx\dy + \iint_{D_2} x\ln(y + \sqrt{1+y^2})\dx\dy = 0
$$
**Comment.** 

==TODO: Add the comment to take care of the property of the integral area itself.==



> Compute $\displaystyle\iint_D \euler^{-x^2-y^2}\dx\dy$, where $D: x^2 + y^2 \le a^2$.

$$
\displaystyle\iint_D \euler^{-x^2-y^2}\dx\dy
= \displaystyle\iint_D \euler^{-r^2}r\dr\d\theta
$$



> Find the volume that sphere $x^2 + y^2 + z^2 \le 4a^2$ be cut by $x^2+y^2 = 2ax$.

$$
V = 4\iint_D \sqrt{4a^2 - r^2}\cdot r\dr\d\theta
$$



##### # 

$$
T: 
J(u, v) = \frac{\p(x, y)}{\p(u, v)}
$$








