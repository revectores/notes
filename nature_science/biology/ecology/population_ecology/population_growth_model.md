# Population Growth Model

$$
\newcommand{\euler}{\mathrm{e}}
\newcommand{\d}{\text d}
\newcommand{\dt}{\d t}
\newcommand{\dN}{\d N}
\newcommand{\dP}{\d P}
$$

##### # Density Irrelevant Model

密度无关的种群增长模型有差分方程和微分方程两类形式. 差分形式写作
$$
N_{t+T} = \lambda N_t
~~\Rightarrow~~
N_t = N_0\lambda^{t/T}
~~\Rightarrow~~
\lg N_t = \lg N_0 + \frac{t}{T}\lg\lambda
$$

式中$\lambda$为种群的**周限增长率**, 有时也写成$R_0$, $T$为**世代时间**, 上述方程描述种群数量关于时间的函数. 有时也记$t:=t/T$以$t$表示**世代数**, 此时差分方程写作
$$
N_{t+1} = \lambda N_t
~~\Rightarrow~~
N_t = N_0\lambda^{t}
~~\Rightarrow~~
\lg N_t = \lg N_0 + t\lg\lambda
$$
密度无关的种群增长模型的微分形式写作
$$
\frac{\dN}{\dt} = rN
~~\Rightarrow~~
N(t) = N_0\euler^{rt}
$$
式中$r$为种群的瞬时增长率(内禀增长率).

对比微分方程和差分方程的形式得$\lambda = \euler^{rT}$, 对数形式为$r = \dfrac{\ln\lambda}{T}$.

根据参数的实际意义知:

|          | $\lambda$ | $r$ |
| :------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
| 种群增长 | >1                                                           | >0                                                           |
| 种群稳定 | 1                                                           | 0                                                           |
| 种群下降 | (0,1)                                                        | <0                                                           |
| 种群灭绝 | 0                                                           | →-∞                                                          |



##### # Density Relevant Model: Logistic Equation

$$
\frac{\dN}{\dt} = rN\left( 1 - \frac{N}{K} \right)
$$

式中$\left(1-\dfrac{N}{K}\right)$的物理意义为种群的剩余空间.
