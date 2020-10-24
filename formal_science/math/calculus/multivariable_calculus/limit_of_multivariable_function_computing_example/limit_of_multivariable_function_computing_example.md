# Limit of Multivariable Function Computing Example

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
$$






##### # Computed by Definition

>  Example. Compute the limit
>
> $\displaystyle\lim_{(x, y)\rightarrow(0,0)}\frac{x^2y^2}{x^2+y^2}$

$$
\left| \frac{x^2y^2}{x^2+y^2} - 0 \right|
= \frac{x^2y^2}{x^2+y^2} < \frac{1}{4}\frac{(x^2+y^2)^2}{x^2+y^2}
= \frac{1}{4}(x^2+y^2) < \frac{1}{4}\varepsilon
$$

Hence $\forall \varepsilon > 0$, let $\delta = \dfrac{1}{4}\varepsilon$, then as $0 \lt \sqrt{(x-0)^2 + (y-0)^2} \lt \delta$, we have $|f(x, y) - 0|\lt \varepsilon$, which gives $\displaystyle\lim_{(x, y)\rightarrow(0,0)}\frac{x^2y^2}{x^2+y^2} = 0$.



##### # Computed by Property

>   Example. Compute the limit
>
>  $\displaystyle\lim_{(x, y)\rightarrow(0,a)}\frac{\sin(xy)}{xy}$

Notice that $\sin(xy) \sim xy$,

$$
\displaystyle\lim_{(x, y)\rightarrow(0,a)}\frac{\sin(xy)}{xy}
= \displaystyle\lim_{xy \rightarrow 0}{\frac{\sin(xy)}{xy}}
= \displaystyle\lim_{xy \rightarrow 0}\dfrac{xy}{xy}
= \displaystyle\lim_{xy \rightarrow 0} 1
= 1
$$



>  Example. Compute the limit
>  $$
>  \displaystyle\lim_{x\rightarrow0 \\ y\rightarrow0} \frac{\sqrt{xy + 1}-1}{xy}
>  $$

$$
\begin{align}
\lim_{x\rightarrow0 \\ y\rightarrow0} \frac{\sqrt{xy + 1}-1}{xy}
=& \lim_{x\rightarrow0 \\ y\rightarrow0} \frac{(\sqrt{xy + 1}-1)(\sqrt{xy + 1}+1)}{xy(\sqrt{xy + 1}-1)} \\
=& \lim_{x\rightarrow0 \\ y\rightarrow0} \frac{xy}{xy(\sqrt{xy+1}+1)} \\
=& \lim_{x\rightarrow0 \\ y\rightarrow0} \frac{1}{\sqrt{xy+1}+1} \\
=& \frac{1}{2}
\end{align}
$$

or we can apply the encapsulated infinitesimal transformation directly:
$$
\lim_{x\rightarrow0 \\ y\rightarrow0} \frac{\sqrt{xy + 1}-1}{xy}
= \lim_{xy \rightarrow 0} \dfrac{xy}{xy}
= 1
$$



>  Example. Compute the limit
>  $$
>  \lim_{x\rightarrow\infty, y\rightarrow1}\left(1+\frac{1}{x}\right)^{\frac{x^2}{x+y}}
>  $$

$$
\displaystyle\lim_{x\rightarrow\infty, y\rightarrow1}\left(1+\frac{1}{x}\right)^{\frac{x^2}{x+y}}
= \displaystyle\lim_{x\rightarrow\infty, y\rightarrow1}  \left[ \left(1+\frac{1}{x}\right)^x \right]^{\frac{x}{x+y}}
=   \left[ \displaystyle\lim_{x\rightarrow\infty, y\rightarrow1} \left(1+\frac{1}{x}\right)^x \right]^{\lim_{x\rightarrow\infty, y\rightarrow1}\frac{x}{x+y}}
= \euler^1 = \euler
$$



##### # Compute by Sqeeze Theorem

> Example. Compute the limit
> $$
> \lim_{(x, y)\rightarrow(0,0)}(x^2+y^2)^{x^2y^2}
> $$


$$
\displaystyle\lim_{(x, y)\rightarrow(0,0)}(x^2+y^2)^{x^2y^2}
= \lim_{(x, y)\rightarrow(0,0)} \euler^{x^2y^2\ln(x^2+y^2)}
= \exp\left[ \lim_{(x, y)\rightarrow(0,0)}x^2y^2\ln(x^2+y^2) \right]
$$

Now we compute the limit on the exponent:

$$
\displaystyle\lim_{(x, y)\rightarrow(0,0)}x^2y^2\ln(x^2+y^2)
= \lim_{r\rightarrow0} r^4\sin^2\theta\cos^2\theta \ln r^2
= \lim_{r\rightarrow0} \frac{1}{2}\sin^22\theta \cdot r^4\ln r = 0
$$

hence
$$
\displaystyle\lim_{(x, y)\rightarrow(0,0)}(x^2+y^2)^{x^2y^2} = \euler^0 = 1
$$




