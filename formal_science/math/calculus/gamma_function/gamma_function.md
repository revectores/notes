# Gamma Function

$$
\newcommand{\d}{\text{d}}
\newcommand{\dx}{\d x}
\newcommand{\dy}{\d y}
\newcommand{\dt}{\d t}
\newcommand{\dr}{\d r}
\newcommand{\euler}{\text{e}}
$$

##### # Definition

$$
\Gamma(\alpha) = \int_{0}^{\infty} x^{\alpha-1}\euler^{-x} \dx
$$

##### # Properity

1. $\Gamma(1) = 1$.
2. $\Gamma(\alpha+1) = \alpha\Gamma(\alpha)$
3. $B(a, b) = \displaystyle \int_{0}^{1} t^{a-1}(1-t)^{b-1} = \dfrac{\Gamma(a)\Gamma(b)}{\Gamma(a+b)} $

Properity 1 and 2 gurantees that for positive integer $n$, $\Gamma(n) = n!$.

Furthermore, the value of Gamma function at $\alpha = \dfrac{1}{2}$ plays important rules in multiple possiblity distribution, especially the normal distribution, so we list it as the fourth property here:

4. $\Gamma\left( \dfrac{1}{2} \right) = \sqrt{\pi}$



**Proof**.

1. $\Gamma(1) = \displaystyle\int_{0}^{\infty} \euler^{-x}\dx = 1$

2. $\Gamma(\alpha+1)
= \displaystyle\int_{0}^{\infty} x^{\alpha}\euler^{-x}\dx
= -\displaystyle\int_{0}^{\infty} x^{\alpha} \d(\euler^{-x})
= \displaystyle\int_{0}^{\infty} \euler^{-x} \d x^{\alpha}
= \alpha\Gamma(\alpha)$

3. ==TODO: Finish the proof.==

$$
\Gamma(a)\Gamma(b) = 
$$

4. Consider the integral $I = \displaystyle \int_{0}^{\infty} \euler^{-t} \dt$:

$$
\begin{align}
I^2
&= \left(\int_{0}^{\infty} \euler^{-t} \dt \right)^2 \\
&= \int_{0}^{\infty} \euler^{-x^2} \dx \int_{0}^{\infty} \euler^{-y^2} \dy \\
&= \int_{0}^{\infty}\int_{0}^{\infty} \euler^{-(x^2 + y^2)} \dx\dy \\
&= \int_{0}^{ \frac{\pi}{2}}\int_{0}^{\infty} \euler^{-r^2} r ~ \dr\d\theta \\
&= \frac{\pi}{4}
\end{align}
$$

Hence $I = \dfrac{\sqrt{\pi}}{2}$. Now we have

$$
\Gamma\left( \frac{1}{2} \right)
= \int_{0}^{\infty} x^{-1/2}e^{-x}\dx
= \int_{0}^{\infty} t^{-1}e^{-t^2}\d t^2
= 2I
= \sqrt{\pi}
$$


