# Information Theory

$$
\newcommand{\X}{\mathcal X}
\newcommand{\Y}{\mathcal Y}
$$



##### # Information Entropy

For the random variable $X$ with its probability density function $p(x)$, we define the **information entropy** of $X$ as
$$
H(X) = -\sum_x p(x)\log_a p(x)
$$
The base $a$ defines the unit of information entropy, we use $a=2$ for computer science in practice, where the unit is **bit**, theoretically we use $a=\text{e}$, where the unit is **nat**. The physical significance of information entropy is the average uncertainty of the random variable.





##### # Mutual Information

The **mutual information(MI)** or **transinformation** is a measure of the mutual dependence between the two variables. More specifically, it quantifies the "amount of information" obtained about one random variable through observing the other random variable.

The mutual information of two jointly discrete random variables $X$ and $Y$ is calculated as a double sum:
$$
I(X;Y) = \sum_{y\in\Y}\sum_{x\in\X} p_{(X, Y)}(x, y) \log \left( \frac{p_{X, Y}(x, y)}{p_X(x)p_Y(y)} \right)
$$
where the $p_{(X, Y)}$ is the joint probability mass function of $X$ and $Y$, and $p_X$ and $p_Y$ are the marginal probability mass functions of $X$ and $Y$ respectively.



$$
\begin{align}
I(X; Y)
&= \sum_{x,y} p(x, y)\log\frac{p(x, y)}{p(x)p(y)} \\
&= \sum p(x, y)\log \frac{p(x|y)}{p(x)} \\
&= -\sum p(x, y)\log p(x) + \sum p(x, y)\log p(x|y) \\
&= -\sum p(x)\log p(x) - \left(-\sum_{x,y}p(x, y)\log p(x|y)\right) \\
&= H(X) - H(X|Y)
\end{align}
$$



$$
I(X;Y) = I(Y;X) = H(X)-H(X|Y) = H(Y) - H(Y|X) = H(X) + H(Y) - H(X, Y) \\
I(X;X) = H(X)
$$


$$
\begin{align}
H(X_1, X_2, \cdots, X_n)
&= -\sum p(x1, x_2, \cdots, x_n)\log p(x_1, x_2, \cdots, x_n) \\
&= -\sum p(x1, x_2, \cdots, x_n)\log \prod_{i=1}^n p(x_i | x_{i-1}, \cdots, x_1)
\end{align}
$$


$$
D(p(x, y) \| q(x, y)) = D(p(x)\| q(x)) + D(p(y|x) \| q(y|x))
$$

$$
\begin{align}
D(p(x, y) \| q(x, y))
&= \sum_x\sum_y p(x, y)\log \frac{p(x,y)}{q(x, y)} \\
&= \sum_x\sum_y p(x, y)\log \frac{p(x)p(y|x)}{q(x)q(y|x)} \\
&= \sum_x\sum_y p(x, y)\log \frac{p(x)}{q(x)} + \sum_x\sum_yp(x, y)\log \frac{p(y|x)}{q(y|x)} \\
&= D(p(x)\| q(x)) + D(p(y|x) \| q(y|x))
\end{align}
$$





