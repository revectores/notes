# Population Growth Model

$$
\newcommand{\euler}{\mathrm{e}}
\newcommand{\d}{\text d}
\newcommand{\dt}{\d t}
\newcommand{\dN}{\d N}
\newcommand{\dP}{\d P}
$$

##### # Density Irrelevant Model

There are difference equation form and differential equation form. The difference form is 
$$
N_{t+T} = \lambda N_t
~~\Rightarrow~~
N_t = N_0\lambda^{t/T}
~~\Rightarrow~~
\lg N_t = \lg N_0 + \frac{t}{T}\lg\lambda
$$

where $\lambda$, also denoted as $R_0$ is the **finite rate of increase** of population, $T$ is the generation time. if we denote $n:=t/T$ where $n$ is the number of generation, the formula becomes
$$
N_t = N_0\lambda^n \Rightarrow \lg N_t = \lg N_0 + n\lg \lambda
$$
The differential form is
$$
\frac{\dN}{\dt} = rN
~~\Rightarrow~~
N(t) = N_0\euler^{rt}
$$
where $r$ is the instant growth rate.

Comparing the two form we have $\lambda = \euler^{rT}$, or $r = \dfrac{\ln \lambda}{T}$.

Physical interpretation of parameters $\lambda ,r$:

|          | $\lambda$ | $r$ |
| :------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
| Population increase | $>1$                                                         | $>0$                                                         |
| Population stable | $1$                                                         | $0$                                                         |
| Population decrease | $(0,1)$                                                      | $<0$                                                         |
| Population extinct | $0$                                                         | $\rightarrow -\infty$                                     |



##### # Density Relevant Model: Logistic Equation

$$
\frac{\dN}{\dt} = rN\left( 1 - \frac{N}{K} \right)
$$

The physical interpretation of $\left(1-\dfrac{N}{K}\right)$ is the left living space of population.
