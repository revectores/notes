#### Part II Problems

##### Problem 1

(a) Assumed that the change rate in a year (by a fixed $x$ during the year) is constant:
$$
\dot x\Delta t = Ix\Delta t - q\Delta t \\
\dot x = Ix - q
$$
(b) Convert it into the standard form:
$$
x' - Ix = -q
$$
To apply the integrating factor technique, let $p(t) = -I, e^{\int p(t)} = e^{-It}$,
$$
(xe^{-It})' = -qe^{-It} \\
x = \cfrac{q}{I} + Ce^{It}
$$

(c) To maintain a constant balance, which requires that $\dot x = Ix-q =  0$

which requires
$$
x = \frac{q}{I} = 2.4\times10^5
$$
(d) To run out all of the money in twenty years, which means
$$
x(20) = 2\times10^4 + Ce = 0 \\
C = -2\times10^4 \\
x(0) = \frac{q}{I} + C = 2\times10^4\left(1-\frac{1}{e}\right)
$$



##### Problem 2

(a) As $t\rightarrow\infin$, $x$ and $y$ approaches to $0$ and $z$ approaches $x(0)=1$.

(b)
$$
\dot x = -\sigma x \\
\dot y = \cfrac{\sigma}{2}x - \mu{y} \\
\dot z = \cfrac{\sigma}{2} x + \mu y
$$

Check:
$$
\dot x + \dot y + \dot z = 0
$$
is correct.

Based on the definition of half-life, when $x(t) = \cfrac{1}{2}x_0$, $t$ shows the half-life, in order to calculate this, we needs to solve the original ODE.

By seperating the variables,
$$
\cfrac{\mathrm{d}x}{x} = -\sigma\mathrm{d}t \\
\ln x = -\sigma t + C_1 \\
x = Ce^{-\sigma t}
$$

Since $x(0) = 1, C=1$. 

$$
x = e^{-\sigma t}
$$
and when $x = \cfrac{1}{2}, \ x_0 = \cfrac{1}{2}$,
$$
\cfrac{1}{2} = e^{-\sigma t_S} \\
\sigma = \cfrac{\ln2}{t_S}
$$
With similar processes, we can also find the value of $\mu = \cfrac{\ln2}{t_M}$.

(c) Based on (b) we got that
$$
x = e^{-\sigma t}
$$
As a result,
$$
\begin{align}
\dot y + \mu y &= \cfrac{\sigma}{2}e^{-\sigma t} \\
e^{\mu t}\dot y + \mu e^{\mu t }y &= \cfrac{\sigma}{2}e^{(\mu-\sigma)t} \\
(e^{\mu t}y)' &= \cfrac{\sigma}{2}e^{(\mu-\sigma)t} \\
e^{\mu t}y &= \cfrac{\sigma}{2(\mu-\sigma)}e^{(\mu-\sigma)t} + C \\
y &= \cfrac{\sigma}{2(\mu-\sigma)}e^{-\sigma t} + Ce^{-\mu t}
\end{align}
$$

With $y(0) = 0$ applied,
$$
\cfrac{\sigma}{2(\mu-\sigma)} + C = 0 \\
y = \cfrac{\sigma}{2(\mu-\sigma)}(e^{-\sigma t}-e^{-\mu t})
$$

Since $x+y+z = 1$ is constant,
$$
z = 1 - x - y
= 1 - e^{\sigma t} - \cfrac{\sigma}{2(\mu-\sigma)}(e^{-\sigma t}-e^{-\mu t})
$$
(d)
$$
\begin{align}
\dot y &= 0 \\
\cfrac{\sigma}{2(\mu-\sigma)}(\mu e^{-\mu t}-\sigma e^{-\sigma t}) &= 0 \\
e^{(\mu-\sigma)t} &= \cfrac{\mu}{\sigma} \\
t &= \cfrac{\ln\mu - \ln\sigma}{\mu-\sigma}
\end{align}
$$

(e) When $x(0) = 2$,
$$
x = 2e^{-\sigma t}
$$
And 
$$
y = \cfrac{\sigma}{\mu-\sigma}(e^{-\sigma t}-e^{-\mu t})
$$
then
$$
z = 1 - x - y = 2 - 2e^{-\sigma t} - \cfrac{\sigma}{\mu-\sigma}(e^{-\sigma t}-e^{-\mu t})
$$
(f) $x = e^t, \dot x = e^t$, so
$$
q(t) = te^t + 2e^t = (t+2)e^t
$$
The general solution of an inhomogeneous ODE is the sum of an specific solution and its corresponeding homogeneous ODE's general solution. According to this statement, since the general solution of equation
$$
t\dot x + 2x = 0
$$
can be simply solved by the variables seperation technic,
$$
\begin{align}
\cfrac{\mathrm{d}x}{x} &= -\cfrac{2}{t}\mathrm{d}t \\
\ln x &= -2\ln t + C_1 \\
x &= Ct^{-2}
\end{align}
$$

As the result, the general solution of original ODE is
$$
x = e^t + Ct^{-2}
$$
