# Continuous Distribution

$$
\newcommand{\e}{\text{e}}
\newcommand{\d}{\text{d}}
\newcommand{\dx}{\d x}
$$

### 1. Normal Distribution

For the random variable with probability density function
$$
p(x) = \frac{1}{\sqrt{2\pi}\sigma}\exp \left\{ -\frac{(x-\mu)^2}{2\sigma^2} \right\}
$$
where $\mu, \sigma > 0$ are parameters, we define $X$ complies the **normal distribution** $X\sim N(\mu, \sigma^2)$.

> **Regularity Checking**.
>
> Let $\displaystyle x' = \frac{x - \mu}{\sigma}$,
> $$
> F(+\infin) = \int_{-\infin}^{\infin} p(x)\dx
> = \int_{-\infin}^{\infin} \frac{1}{\sqrt{2\pi}\sigma}\exp \left\{ -\frac{(x-\mu)^2}{2\sigma^2} \right\}\dx
> = \int_{-\infin}^{\infin} \varphi(x) = \frac{1}{\sqrt{2\pi}}\e^{-\frac{x'^2}{2}}
> $$
> Let $x' = \sqrt{2t}$,
> $$
> F(+\infin) = 
> $$
> 
>
> 

Specially, when $\mu=0, \sigma=1$, the normal distribution is called **standard normal distribution**, denoted as $X\sim N(0, 1)$. The probability density function of standard normal distribution is denoted as
$$
\varphi(x) = \frac{1}{\sqrt{2\pi}}\e^{-\frac{x^2}{2}}
$$
and its cumulative distribution function denoted as $\Phi(x)$. Notice that $\varphi(x)$ is even function hence $\Phi(x) + \Phi(-x) = 1$.

Any normal distribution $X\sim(\mu, \sigma^2)$ can be converted to the standard form by linear transformation:
$$
Y = \frac{X-\mu}{\sigma} \sim N(0, 1)
$$

> **Proof**. The cumulative distribution function of constructed random variable $Y$ is
> $$
> F_Y(y) = P \left( \frac{X-\mu}{\sigma} \le y \right)
> = P(X\le \sigma y + \mu)
> = \int_0^{\sigma y + \mu} \frac{1}{\sqrt{2\pi}\sigma}\exp\left\{ -\frac{(x-\mu)^2}{2\sigma^2} \right\}
> $$
> Let $x = \sigma y + \mu$, we have
> $$
> F_Y(y) = \int_0^{y} \frac{1}{\sqrt{2\pi}\sigma}\e^{-\frac{y^2}{2}}
> $$
> and the probability density function 
> $$
> p_Y(y)
> = \frac{\d{F_Y(y)}}{\d y}
> = \frac{\d\left( \displaystyle \int_0^{y} \frac{1}{\sqrt{2\pi}\sigma}\e^{-\frac{y^2}{2}} \right)}{\d y} = \frac{1}{\sqrt{2\pi}\sigma}\e^{-\frac{y^2}{2}} \sim N(0,1)
> $$

The most simple form of normal distribution is 



### 2. Uniform Distribution

The **uniform distribution** is random variable with probability density function
$$
p(x) =
\left\{\begin{array}{ll}
\cfrac{1}{b-a} & a\le x \le b\\
0, & x<a, x>b
\end{array}\right.
$$
denoted as $X\sim U(a, b)$. 



### 3. 