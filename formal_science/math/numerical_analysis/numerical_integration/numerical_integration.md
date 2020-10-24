# Numerical Integration

$$
\newcommand{\d}{\text{d}}
\newcommand{\dx}{\d x}
\newcommand{\ddx}{\dfrac{\d}{\d x}}
$$

### 1. Basic Concepts

$$
I(f) = \int_a^b f(x)\dx
$$


$$
I_n(f) = \sum_{i=0}^n \alpha_i f(x_i)
$$
where $x_i$ is **integral point**, and $\alpha_i$ is **integral coffieient**,

if $I_n(f)$ obeys
$$
E_n(x^k) = I(x^k) - 
$$






### 2. Numerical Integration by Interpolation


$$
\int_a^b f(x)\dx
\approx \int_a^b L_n(x)\dx
= \int_a^b \sum_{i=0}^nl_i(x)f(x_i)\dx
= \sum_{i=0}^n \left(\int_a^b l_i(x)\dx \right) f(x_i)
$$

Denotes $\alpha_i = \displaystyle \int_a^b l_i(x)\dx$
$$
I_n(f) = \int_a^b L_n(x)\dx = \sum_{i=0}^n \alpha_i f(x_i)
$$


> Example. Construct the numerical integration formula $I_2(f)$ for $\displaystyle\int_0^2 f(x)\dx$ by points $x_0=0, x_1=0.5, x_2=2$.
> $$
> I_2(f)
> = \int_0^2 L_2(x)\dx
> = \int_0^2 (l_0(x)f(x_0) + l_1(x)f(x_1) + l_2f(x_2))\dx
> $$
> 


$$
\int_0^{3h} f(x)\dx = \frac{3}{8}h[f(0)+3f(h)+3f(2h)+f(3h)]
$$






### 3. Newton-Cote's Integration

Devide the integration interval $[a, b]$ into $n$ equal intervals. Denote $h=\dfrac{b-a}{n}$.





##### # Trapezoid Integration

Linear interpolation:
$$
\int_a^b f(x)\dx
\approx \int_a^b L_1(x)\dx
$$
One 
$$
T(f) = \frac{b-a}{2}(f(a)+f(b))
= (b-a)\left( \frac{f(a)}{2} + \frac{f(b)}{2} \right)
$$


Truncatation error:
$$
f(x) = L_1(x) + \frac{f''(\xi)}{2!}(x-a)(x-b), a\le\xi\le b
$$



###### # SimpSon Integration

Quadratic interpolation:
$$
\int_a^b f(x)\dx
\approx \int_a^b L_2(x)\dx
$$

$$
S(f) = \frac{b-a}{6}\left(f(a) + 4f\left(\frac{a+b}{2}\right) + f(b)\right)
$$





##### # General Newton-Cote's Integration

$$
\alpha_i = \int_a^b l_i(x)\dx =
$$



Let $x=a+th, ~x_i = a + ih$, we have
$$
\alpha_i = \int_0^n \frac{}{i!(n-i)!(-1)^{n-i}}h\d t
$$

$$
c_i^{(n)} = (-1)^{n-i}\frac{1}{i!(n-i)n}\int_0^n t(t-1)\cdots(t-i+1)(t-i-1)\cdots(t-n)\d t
$$
Notice that $c_i^{(n)}$ only relavent to $n$ but the $x_i$, we call it the Newton-Cote's coefficient.

|      |        |       |        |        |       |        |      |
| ---- | ------ | ----- | ------ | ------ | ----- | ------ | ---- |
| 1    | 1/2    | 1/2   |        |        |       |        |      |
| 2    | 1/6    | 4/6   | 1/6    |        |       |        |      |
| 3    | 1/8    | 3/8   | 3/8    | 1/8    |       |        |      |
| 4    | 7/90   | 16/45 | 2/15   | 16/45  | 7/90  |        |      |
| 5    | 19/288 | 25/96 | 25/144 | 25/144 | 25/96 | 19/288 |      |
| 6    | 41/840 |       |        |        |       |        |      |

For $n\le7$, $$





### 4. Composite Integration

##### # Composite Trapezoid Integration

$$
h = \frac{b-a}{n}
$$

$$
x_i = a + ih, ~ i = 0,1,\ldots, n
$$

$$
\int_{x_i}^{x_{i+1}}f(x)\dx = \frac{h}{2}(f(x_i) + f(x_{i+1})) - f''(\xi_i)\frac{h^3}{12}
$$



|      | $x_0$ | $x_1$ | $x_2$ | $x_3$ |      |      |      |
| ---- | ----- | ----- | ----- | ----- | ---- | ---- | ---- |
| $h$  | 1/2   | 1/2   |       |       |      |      |      |
|      |       | 1/2   | 1/2   |       |      |      |      |
|      |       |       | 1/2   | 1/2   |      |      |      |
|      | 1/2   | 1     | 1     | 1/2   |      |      |      |
|      |       |       |       |       |      |      |      |


$$
I(f) = \sum_{i=0}^{n-1}
$$



$$
T(h) = T_n(f) = h\left[ \frac{1}{2}f(a) + \sum_{i=1}^{n-1} f(x_i) + \frac{1}{2}f(b) \right]
$$

$$
E_n(f) = -\frac{h^3}{12}\sum_{i=0}^{n-1}f''(\xi_i) 
$$



> **Proof**.
> $$
> E_n(f) = I(f) - T_n(f) =
> $$
> Denote
> $$
> M_2 = \max_{a\le x\le b} |f''(x)|
> $$
> then we have
> $$
> |E_n(f)| \le \frac{(b-a)^3}{12n^2}(b-a)M_2 = O\left(\frac{1}{n^2}\right)
> $$
> If $N_2$ is known, for any error control $\varepsilon > 0$, we have
> $$
> |E_n(f)| = < \varepsilon
> $$
> 



##### # Composite SimpSon Integration

$$
S_n(f) = \frac{h}{3}\left[ f(a) + 4\sum_{i=0}^{m-1}f(x_{2i+1}) + 2\sum_{i=1}^{n-1}f(x_{2i}) + f(b) \right]
$$



|       | $x_0$ | $x_1$ | $x_2$ | $x_3$ | $x_4$ | $x_5$ | $x_6$ | $x_7$ | $x_8$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| $h/6$ |   1   |   4   |   1   |       |       |       |       |       |       |
|       |       |       |   1   |   4   |   1   |       |       |       |       |
|       |       |       |       |       |   1   |   4   |   1   |       |       |
|       |       |       |       |       |       |       |   1   |   4   |   1   |
| $h/6$ |   1   |   4   |   2   |   4   |   2   |   4   |   2   |   4   |   1   |


$$
-\frac{(2h)^5}{2880}f^{(4)}(\xi_i), ~ x_{2i}\le\zeta_i\le x_{2i+2}
$$


> Example. Compute $\displaystyle \int_0^1 \e^x\dx$ to 5 decimal percision, how many points should be computed?



> Compute $\displaystyle \int_0^{1.2}\sin x^2\dx$ based on Newton-Cote's formula, composite trapezoid integration, and composite Simpson integration.





##### # Automatic Precision Control

Compute integral using Romberg algorithm:



##### # Romberg Integration

$$
\begin{align}
& I(f) - T_n(f) = -\frac{1}{12}f''(\xi)h^2 = ch^2 \\
& I(f) - T_{2n}(f) = -\frac{1}{12}f''(\xi)\left(\frac{h}{2}\right)^2 = ch^2
\end{align}
$$




$$
R_{k,j} = R_{k, j-1} + \frac{R_{k, j-1}-R_{k-1,j-1}}{4^{j-1}-1}, ~~~~ k = 2, 3, \ldots
$$
Compute until the $|R_{k,k}-R_{k-1,k-1}|$ is less than given precision.







### 6. Multiple Integral

Compute double integral $\displaystyle \int_0^1\int_0^2 \sin(x^2+y)\d y\dx$.

















