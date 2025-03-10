# Linear Programming

$$
\newcommand{\for}{\text{for}}
$$

## 1. Basic Concepts

##### # Definition and Concepts

Formally, a **linear-programming** problem is the problem of either minimizing or maximizing a **linear function** subject to a finite set of **linear constraints**. Linear constraints can be either linear equalities or linear inequalities. The function we wish to minimize/maximize is called **object function**.

If we are to minimize, then we call the linear program a minimization linear program, and if we are to maximize, then we call the linear program a maximization linear program.

Any setting of the variables that satifies all the constraints is a **feasible solution** to the linear program. The set set of feasible solutions constructs **feasible region**. It can be proved that any feasible region is a [convex region]() in $\R^n$ space.



##### # Standard Form of Linear Programming

Aim to maximize
$$
\sum_{j=1}^n c_jx_j
$$
subject to
$$
\begin{align}
\sum_{j=1}^n a_{ij}&x_j \le b_i &&\for~ i = 1, 2, \ldots, m \\
& x_j \ge 0 &&\for~ j = 1, 2, \ldots, n
\end{align}
$$
In standard form **non-negative constraints** are forced for all $n$ variables $x_j$.

To convert a non-standard program into standard form, four techniques may be useful:

- If the object function is a minimization rather than a maximization, or there is a $\ge$ instead of $\le$ in inequality constraint, we simply add a negative sign.
- If a variabe $x_j$ is not constrainted to be non-negative, we apply substitution $x_j = x_j' - x_j''$ and let $x_j', x_j''\ge 0$.
- If there is an equality constraint $f(x) = b$, we replace it with two inequality $f(x) \ge b, f(x) \le b$.



##### # Slack Form of Linear Programming

In **slack form** we force all inequality constraints to be simple non-negative constraints. This requires introducing new variables in the standard form to implement conversion:
$$
\begin{align}
x_{n + i} = b_i - \sum_{j = 1}^n a_{ij}x_{j}
\end{align}
$$
For instance, the standard form

maximize $2x_1 - 3x_2 + 3x_3$ subject to
$$
\begin{align}
x_1  + x_2 - x_3 &\le 7 \\
-x_1 - x_2 + x_3 &\le -7 \\
x_1  - 2x_2 + 2x_3 &\le 4 \\
x_1, x_2, x_3 &\ge 0
\end{align}
$$
can be expressed in slack form as
$$
\begin{align}
z   &= 2x_1 - 3x_2 + 3x_3   \\
x_4 &= 7 - x_1 - x_2 + x_3  \\
x_5 &= -7 + x_1 + x_2 - x_3 \\
x_6 &= 4 - x_1 + 2x_2 - 2x_3
\end{align}
$$


