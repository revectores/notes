# Linear Models

The following are a set of methods intended for regression in which the target value is expected to be a linear combination of the features. In mathematical notation, if $\hat y$ as the predicted value.
$$
\hat y(w,x) = w_0 + \sum_{i=1}^n w_i x_i = w_0 + w_1x_1 + \cdots + w_nx_n
$$
Across the module, we designate the vector $w=(w_1, \ldots, w_n)$  as `coef_` and $w_0$ as `intercept_`.



##### # Ordinary Least Squares

[`LinearRegression`](https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.LinearRegression.html#sklearn.linear_model.LinearRegression) fits a linear model with coefficients $w=(w_1, \ldots, w_p)$ to minimize the residual sum of squares between the observed targets in the dataset, and the targets predicted by the linear approximation. Mathematically it solves a problem of the form:
$$
\min_w \|Xw-y\|^2_2
$$
[`LinearRegression`](https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.LinearRegression.html#sklearn.linear_model.LinearRegression) will take in its `fit` method arrays X, y and will store the coefficients  of the linear model in its `coef_` member:

```python
from sklearn import linear_model
reg = linear_model.LinearRegression()
reg.fit([[0, 0], [1, 1], [2, 2]], [0, 1, 2])
print(type(reg.coef_), reg.coef_, reg.intercept_)
# <class 'numpy.ndarray'> [0.5 0.5] 1.1102230246251565e-16
```

Generally, the method `predict` could be applied.

```python
print(reg.predict([[0, 0], [5, 5]]))
# [1.11022302e-16 5.00000000e+00]
```

The coefficient estimates for Ordinary Least Squares rely on the independence of the features. When features are correlated and the columns of the design matrix $X$ have an approximate linear dependence, the design matrix becomes close to singular and as a result, the least-squares estimate becomes **highly sensitive to random errors** in the observed target, producing a large variance. This situation of [multicollinearity]() can arise, for example, when data are collected without an experimental design.

The least squares solution is computed using the singular value decomposition of $X$. If $X$ is a matrix of shape `(n_samples, n_features)`, this method has a cost of $O(n_{\text{samples}} n_{\text{features}}^2)$, assuming that $n_{\text{samples}} \geq n_{\text{features}}$.







##### # Ridge Regression and Classification

[`Ridge`](https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.Ridge.html#sklearn.linear_model.Ridge) regression addresses some of the problems of [Ordinary Least Squares](https://scikit-learn.org/stable/modules/linear_model.html#ordinary-least-squares) by imposing a penalty on the size of the coefficients. The ridge coefficients minimize a penalized residual sum of squares:
$$
\min_{w} || X w - y ||_2^2 + \alpha ||w||_2^2
$$
The complexity parameter $\alpha>0$ controls the amount of shrinkage: the larger the value of , the greater the amount of shrinkage and thus the coefficients become more robust to collinearity.

```python
from sklearn import linear_model
reg = linear_model.Ridge(alpha=.5)
reg.fit([[0, 0], [0, 0], [1, 1]], [0, .1, 1])
print(reg.coef_, reg.intercept_)
# [0.34545455 0.34545455] 0.13636363636363638
```





















