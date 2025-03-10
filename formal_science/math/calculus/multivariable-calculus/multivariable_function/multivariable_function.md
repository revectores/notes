# Multivariable Function

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
\newcommand{\dv}{\d v}
\newcommand{\dz}{\d z}
\newcommand{\du}{\d u}
$$

### 1. Double Limit

##### # Definition

For the function of two variables $f(P) = f(x, y)$ defined in domain $D$, and $P_0(x_0, y_0)$ is the cluster point.  If there exists a constant $A$, for any given positive number $\varepsilon$, there is always a positive $\delta$ which makes $\forall P(x, y)\in D\bigcap \dot U(P_0, \delta)$, $|f(x, y) - A| \lt\varepsilon$, we defined $A$ as the **double limit** of $f(x, y)$ as $(x, y)\rightarrow(x_0, y_0)$, denoted as
$$
\lim_{x\rightarrow0 \\ y\rightarrow0} f(x, y) = \lim_{(x, y)\rightarrow(0,0)} f(x, y) = A
$$
**Remark.** The existence of double limit requires the derivative from all directions, for example, if we try to find the limit of the following function at $(0,0)$:
$$
z = f(x, y) =
\left\{\begin{array}{ll}\begin{align}
& \frac{xy}{x^2+y^2}, ~~~~ && x^2+y^2\neq 0 \\
& 0, ~~~~ && x^2+y^2 = 0 \\
\end{align}\end{array}\right.
$$
Consider about approaching $(0,0)$ through the line $y=kx$ as route, we have
$$
\displaystyle\lim_{(x, y) \rightarrow (0,0) }\dfrac{xy}{x^2+y^2}
= \displaystyle\lim_{(x, y) \rightarrow (0,0) }\dfrac{kx^2}{x^2+k^2x^2}
= \dfrac{k}{1+k^2}
$$
The limit depends on the value of $k$ if we approach the origin through line $y = kx$, which is variational based on $k$, hence there limit does not exist for the function at $(0,0)$.

**Remark 2.** One should notice that the double limit is different from the [iterated limit](), which only approaching one variable at a time and consider the other as a constant.



##### # Generalization

Similarly, we could define the generalized limit for the function with multiple variables. Similar properties applied to the single variable function will also apply to function with double and multiple variables.



##### # Valuation

All the properties applied to the limit of single variable can be applied to the limit of the multiple variables, such as definition, using the two important limit, squeeze theorem, equivalent infinitesimal, and so on. The examples are shown in [limit_of_multivariable_function_computing_example](limit_of_multivariable_function_computing_example). Specially, some important and classical limit of multivariable function will be collected in [important_multivarible_function_limit](important_multivariable_function_limit).




Find the continuous domain of function $f(x, y) = \dfrac{\arcsin(3-x^2-y^2)}{\sqrt{x-y^2}}$.

All the combination of continuous function are continuous in definition domain. Hence, we're only required to get the defintion domain.
$$
\left\{\begin{array}{ll}
|3 - (x^2 + y^2)| \le 1 \\
x-y^2\ge 0
\end{array}\right.
\Rightarrow
\left\{\begin{array}{ll}
2 \le x^2+y^2 \le 1 \\
x\ge y^2
\end{array}\right.
$$





### 2. Continuity

For function of two variables $f(x, y)$ defined on $D$, $P(x_0, y_0)\in D$ is the limit point. We call the function $f(x, y)$ is continuous at point $(x_0, y_0)$ if
$$
\lim_{(x, y)\rightarrow(x_0, y_0)}f(x, y) = f(x_0, y_0)
$$
If the function is continuous in every points of interval $I$, we call $f(x, y)$ is continuous in $I$, and $f(x, y)$ is the continuous function on interval $I$.

If the function is not continuous at limit point $P(x_0, y_0)$, we call it as the discontinuity point.

Take an example, we've computed the limit at limit point $(0,0)$ of the function
$$
z = f(x, y) =
\left\{\begin{array}{ll}\begin{align}
& \frac{xy}{x^2+y^2}, ~~~~ && x^2+y^2\neq 0 \\
& 0, ~~~~ && x^2+y^2 = 0 \\
\end{align}\end{array}\right.
$$
which is not exist, hence $(0,0)$ is one of the discontinuity point of $f(x, y)$. Since the determination of continuity is no more than the computing of limit, we've merge the examples about continuity determination into [limit_of_multivariable_function_computing_example](limit_of_multivariable_function_computing_example).

Similar to the single variable case, the basic operations and compound of continuous function is still continuous. Specially, the basic elementary functions are all continuous in their domain.

Generally, we can also generalize the concept of continuity into multivariable case.





### 2. Partial Derivative

##### # Definition

The partial derivative of $f(x, y)$ to $x$ or $y$ are defined as

$$
\frac{\pf}{\px} \bigg\rvert_{x=x_0\\y=y_0} = \lim_{\Delta x\rightarrow 0} \frac{f(x_0+\Delta x, y_0) - f(x_0, y_0)}{\Delta x}
$$

$$
\frac{\pf}{\py} \bigg\rvert_{x=x_0\\y=y_0} = \lim_{\Delta y\rightarrow 0} \frac{f(x_0, y_0+\Delta y) - f(x_0, y_0)}{\Delta y}
$$

if the limit exists.



The examples about computing the partial derivative will be shown in [partial_derivative_computing_example](partial_derivative_computing_example). Specially, some important and classical limit of multivariable function will be collected in [important_partial_derivative](important_partial_derivative).





$z = x^y (x\gt 0, x\neq 1)$, prove

$$
\frac{x}{y}\frac{\p z}{\px} + \frac{1}{\ln x}\frac{\p z}{\py} = 2z
$$



Compute the partial derivative
$$
r = \sqrt{x^2 + y^2 + z^2}
$$





### 3. Direction Derivative

##### # Definition of Direction Derivative

Define the derivative in the direction of vector $\boldsymbol{l}$ with direction cosine vector $( \cos{\alpha}, \cos{\beta} )$ as

$$
\frac{\pf}{\pl} = \lim_{t \rightarrow 0^+} \frac{f(x_0+t\cos\alpha, y_0+t\cos\beta) - f(x_0, y_0)}{t}
$$

as defined, the direction derivative is a special direction derived from the total derivative, and we could compute the direction derivative from the partial derivative respect to $x$ and $y$ by the vector multiplication, if the total derivation exists:

$$
\frac{\pf}{\pl} = \left( \frac{\pf}{\px}, \dfrac{\pf}{\py} \right)\cdot(\cos\alpha, \cos\beta)
$$

**Remark.** The partial derivative $f_x$ is not the same as the derivative in the direction of $x$-axis, because of the direction derivative only requies the limit in one direction exists while the partial one requires both. That is, the partial derivative respect to $x$ exists, if and only if both the direction derivative of $\pm x$ exist and equal.

Similarly, we could define the direction derivative of the three variables, and multiple variables furthermore.



##### # Gradient

**Gradient** is the vector that with maximum direction derivative in its direction, that is, 

$$
\nabla f(x, y) = \left( \frac{\pf}{\px}, \dfrac{\pf}{\py} \right)(\boldsymbol i, \boldsymbol j) = \frac{\pf}{\px}\boldsymbol i + \dfrac{\pf}{\py}\boldsymbol j 
$$

where the operator $\nabla$ is named **vector operator** or **nabla operator**.





### 4. Extremum

##### # Definition of Local Extremum

Fors the function of two variable $z = f(x, y)$ with domain $D$, $P_0(x_0, y_0)$ is the interior point of $D$, if there exists one neighbourhood $U(P_0)\subset D$ which makes $f(x, y) < f(x_0, y_0)$ for all the $(x, y)\in U$ expect $P_0$, then we define the $P_0(x_0, y_0)$ as the **local maximum point** of function $z$, with the **local maximum** $f(x, y)$. Similarly, we could define the **local minimum point** and the **local minimum**. The local maxmium and local minimum are both **extremum**, with its point **extremum point**.



##### # Stationary Point

Define **stationary point** as the points with all its first partial derivatives equal to zero. For the two-variables function case, that is
$$
f_x(x_0, y_0) = f_y(x_0, y_0) = 0
$$
In the geometric perspective, this indicates the tangent plane at the stationary point
$$
z - z_0 = f_x(x_0, y_0)(x-x_0) + f_y(x_0,y_0)(y-y_0) = 0
$$
is parallel to the $xOy$ plane.

**Necessity Theroem.** All the extemum point $(x_0, y_0)$ must be **stationary point**. Hence, when trying to get the extermum, we usually first find the stationary points to narrow down the search space of extremum.



##### # Sufficient Theorem of Extremum

$z = f(x, y)$ continuous in some neigbourhood of $(x_0, y_0)$ with continuous first and second derivatives. For all the stationary points $(x_0, y_0)$, define $\Delta = f_{xx}(x_0, y_0)f_{yy}(x_0, y_0) - [f_{xy}(x_0, y_0)]^2$, there are 3 cases:

1. if $\Delta > 0$, the extremum exist. if $f_{xx}(x_0, y_0)>0$ it's local minimum, if $f_{xx}(x_0, y_0)<0$ it's local maximum. Notice that it is not possible to make $A = 0$ and $AC-B^2>0$. 
2. if $\Delta<0$, the extremum does not exist.
3. if $\Delta = 0$, whether the extremum exist requires further investigation.

Some examples that combine necessity theroem and the sufficient theorem of extremum are provided in [examples_for_double_variable_extremum](examples_for_double_variable_extremum.md).
