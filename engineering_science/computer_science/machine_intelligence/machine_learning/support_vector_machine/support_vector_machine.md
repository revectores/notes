# Support Vector Machine

$$
\newcommand{\b}{\boldsymbol}
\newcommand{\bw}{\b w}
\newcommand{\bx}{\b x}
\newcommand{\d}{\text{d}}
\newcommand{\dx}{\d x}
\newcommand{\dy}{\d y}
\newcommand{\T}{\text{T}}
\newcommand{\norm}[1]{\left\lVert #1 \right\rVert}
$$

### 1.

For the training set $D = \{ (\b x_1, y_1), (\b x_2, y_2), ..., (\b x_m, y_m)  \}, y_i = \pm 1$, the primitive idea of SVM is to find the hyperplane that seperate all the points in both sides, and the hyperplane should be place in the "middle" of all points. That is, maximize the distances from the line to the closest two points in both types. By doing this we wish to maximzie the generalization performance.

The hyperplane is denoted by $(\bw, b)$, where:
$$
\bw^\T \bx + b = 0
$$
For any point $\bx_0$ in sample space, the distance from $\bx_0$ to $(\bw, b)$ can be calculated as
$$
r = \frac{\bw^T\bx + b}{\norm \bw}
$$










empirical risk minimization.
$$
R_{emp}(\theta) = \frac{1}{N}\sum_{i=1}^N L(y_i, f(x_i;\theta))
$$
Loss function:

- quadratic $L(y,x,\theta) = \dfrac{1}{2}(y-f(x;\theta))^2$
- linear $L(y,x,\theta) = |y-f(x;\theta)|$
- binary $$

true risk function
$$
R(\theta) = E_P\{L(x, y, \theta)\} = \int_{X\times Y}P(x,y)L(x,y,\theta)\dx\dy\in[0,1]
$$
true risk is different with the empirical risk, since its impossible to sample infinitely (which is required by the true risk function).

maximize the margin as the best linear classifiers, to

- 

the linear classifier attached the "margin points" is named as "support vector"

- classification hyperplane
    $$
    w^Tx - b = 0
    $$

- positive margin hyperplane

- negative margin hyperplane

- margin between $H+$ adn $H-$: $\frac{}{}$



dual problem of the SVM
$$
f(x:\vec\alpha) = \sum_i^N \alpha_i y_i 
$$


Langrange method, form conversion:
$$
L_p = \frac{1}{2}\|w\|^2 - \sum_i \alpha_i[y_i(w^T x_i+b)-1] \\
w = \sum_i \alpha_i y_i x_i
$$

$$
\max_\alpha \alpha_i - \frac{1}
$$

primal problem: solving a variable $w\in\R^d$. dual problem: solving a variable $\alpha\in\R^N$. sometimes $N\ll d$, by dualing we can simplify the computation.

$\alpha$ is often sparse with few non-zero elements.





### Linearly Inseparable SVM

$$
y_i(x_i - b) \ge 1 - \
$$



### Nonlinear SVM: Kernelization

mapping the data to higher-dimensional space. the linear inseparable in lower-dimensional can be linear separable in higher dimensional.

quadratic polynomial
$$
\varphi:
\begin{bmatrix}
x_1 \\ x_2
\end{bmatrix}
\rightarrow
\begin{bmatrix}
x_1^2 \\ x_2^2 \\ \sqrt{2}x_1x_2
\end{bmatrix}
$$




kernel function

Define the $\mathcal{X}$ is the input space, and $\kappa(\cdot, \cdot)$ is the symmetric function defined at $\mathcal {X}\times\mathcal{X}$, $\kappa$ is the kernel function if for arbitrary data $D=\{x_1, x_2, ..., x_m\}$, the **kernel matrix** $K$ is always positive semidefinite:
$$
K =
\begin{bmatrix}
\kappa(x_1, x_1) & \cdots & \kappa(x_1, x_j) & \cdots & \kappa(x_1, x_m) \\
\vdots & \ddots & \vdots & \ddots & \vdots \\
\kappa(x_i, x_1) & \cdots & \kappa(x_i, x_j) & \cdots & \kappa(x_i, x_m) \\
\vdots & \ddots & \vdots & \ddots & \vdots \\
\kappa(x_m, x_1) & \cdots & \kappa(x_m, x_j) & \cdots & \kappa(x_m, x_m) \\
\end{bmatrix}
$$



$$
k(x, y) = \varphi(x)^T \varphi(y) = (x^Ty)^2
$$
linear kernel
$$
k(x,y) = x^Ty
$$
Radial Basis Function











http://vision.stanford.edu/teaching/cs231n-demos/linear-classify/
$$
L = \frac{1}{N}\sum_i\sum_{j\neq y_i} \max(0, f_j-f_{y_i}+1) + \lambda\sum_k\sum_l W^2_{k,l}
$$
the first item is data loss, and the second item is the regularization loss.









<!-->Non-zero elements correspond to support ve<-->



