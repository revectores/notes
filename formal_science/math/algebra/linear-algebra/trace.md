# Trace

$$
\newcommand{\tr}{\mathop{\mathrm{tr}}}
$$

##### # Definition of Trace

The **trace** of a square matrix is defined as the sum of main diagonal elements:
$$
\tr(A) := \sum_{i=1}^n a_{ii}
$$



##### # Basic Property of Trace

Apparently the trace is a linear mapping, that is
$$
\tr(A + B) = \tr(A) + \tr(B) \\
\tr(cA) = c\tr(A)
$$
and reserve the same after transpose $\tr(A^T) = \tr(A)$



##### # Trace of Product

Element-wise product of two matrix can be encapsulated to a trace notation.
$$
\tr(A^TB) = \tr(AB^T) = \tr(B^TA) = \tr(BA^T) = \sum_{i=1}^m\sum_{j=1}^na_{ij}b_{ij}
$$
and since trace operator matches the definition of **inner product**, we can apply Cauchy-Schwarz inequality to it:
$$
0 \leq[\tr(AB)]^2 \leq \tr(A^2)\tr(B^2) \leq [\tr(A)]^2[\tr(B)]^2
$$

besides, operator $\tr(AB')$ also matches the definition of inner product, that is,
$$
[\tr(AB')]^2 \le \tr(AA')\tr(BB')
$$


##### # Trace as Sum of Eigenvalues

Trace is the sum of eigenvalues.
$$
\tr(A) = \sum_{i = 1}^n\lambda_i
$$

> Proof. 
