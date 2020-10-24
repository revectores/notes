



# Ordinary Differential Equation

$$
\newcommand{\euler}{\text{e}}
\newcommand{\d}{\text{d}}
\newcommand{\dt}{\d t}
\newcommand{\dx}{\d x}
\newcommand{\dy}{\d y}
\newcommand{\dr}{\d r}
\newcommand{\dv}{\d v}
\newcommand{\dz}{\d z}
\newcommand{\du}{\d u}
\newcommand{\dd}[2]{\dfrac{\d #1}{\d #2}}
\newcommand{\pp}[2]{\frac{\partial #1}{\partial #2}}
$$

### 1. Basic Concept

##### # Definition

**Ordinary Differential Equations(ODE)** is the differential equation which has only one independent and one dependent variable. We define the **order** of an differential equation by its highest derivative.

If the number of arbitrary constants in the solution is the same as the order of differential equation, then the solution is **general solution**. The solution without any arbitrary constant is a **special solution**. The graph of a special solution is **integral curve**.







## 2. Separation of Variables 

If the two variables(one independent and on dependent) with its derivatives could be separated to both sides of the equations, we can do that and then simply integral both sides to get the solution.

> Proof. For the equation $g(y)\dy = f(x)\dx$, 
>
> 

> Example.
>
> 











##### # Lost Solution

**Lost Solution**: Similar to the lost root in the fractional equation, some root can be hidden since there is fraction process existed in the separation process, generally, equation such like
$$
\begin{align}
\dd y x &= 2y + 1 \\
\frac{\dy}{2y+1} &= 1 \dx \\
\ln|2y+1| + C &= 2x \dx \\
2y+1 &= \euler^{2x} \\
\end{align}
$$
**Isocline**: a line that connect the same slop at the deritative field.







### 3. First Order Ordinary Differential Equation









### 4. Total Differential Equation

If there exists $u(x,y)$ which makes $\du(x, y) = P(x,y)\dx + Q(x,y)\dy$, we call the equation
$$
P(x,y)\dx + Q(x,y)\dy = 0
$$
**the total differential equation.** Notice that $\du=0$ hence the general solution is $u(x,y)=C$. The primitive function can be 





A differential equation is total differential equation if and only if $\displaystyle \pp Py = \pp Qx$.













