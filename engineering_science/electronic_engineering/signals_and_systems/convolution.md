# Convolution

### Convolution Sum

##### # Impulse Representation

By ultilizing the **sifting property** of the unit impulse $\delta[n]$, we can represent any discrete signal by the combination of the function value in each point:

$$
x[n] = \sum_{k=-\infin}^{+\infin} x[k]\delta[n-k]
$$

The signal set of all time shifting of $\delta[n]$ is **orthogonal**:

$$
\delta[n-k]\delta[n-m] =

\left\{
\begin{array}{ll}
\begin{align}
& 1, ~~~~ k=m \\
& 0, ~~~~ k\neq m
\end{align}
\end{array}
\right.
$$




##### # Unit Impulse Sample Response 

The **unit impulse sample respone** $h_0[n]$, is defined as the response to the unit impluse **at** $n=0$, aka. $\delta[n]$. Generally, the notation $h_k[n]$ represents to the response to unit impluse at $n=k$. In the general case, those $h_k[n]$ is irrelevant, while if the system is time-invariant, then the arbritary response $h_k[n]$ is simply the translation of $h_0[n]$. 

i.e. if the response of the impulse $\delta[n]$ in some LTI system $h_{0}[n]$ is 

$$
h_{0}[n] = 
\left\{
\begin{array}{ll}
	\begin{align}
		& 1, ~~~~ n = a, \\
		& 0, ~~~~ n \neq a,
	\end{align}
\end{array}
\right.
$$

then due to the **time-irrelevance** of system, the response to $\delta[n-k]$ (the impluse at $n=k$) must be

$$
h_{k}[n-k] = 
\left\{
\begin{array}{ll}
	\begin{align}
		& 1, ~~~~ n-k = a, \\
		& 0, ~~~~ n-k \neq a,
	\end{align}
\end{array}
\right.
$$

aka.

$$
h_{k}[n] = 
\left\{
\begin{array}{ll}
	\begin{align}
		& 1, ~~~~ n = a+k, \\
		& 0, ~~~~ n \neq a+k,
	\end{align}
\end{array}
\right.
$$

As noticed, the response moves towards the same direction and steps in $x$-axis.

Moreover, due to the **linearity** of system, if the impulse multiple some cofficient $c$, the response must also be the $c$ times.



##### # Convolution Sum: Definition

Combining the impulse representation and the property of LTI system, we first represent the discrete into infinity sum:

$$
x[n] = \sum_{k=-\infin}^{+\infin} x[k]\delta[n-k]
$$

And due to LTI:

$$
y[n] = \sum_{k=-\infin}^{+\infin} x[k]h_0[n-k]
$$

which is defined as the **convolution sum** or **superposition sum** of $x[n]$ and $h[n]$, noted as $x[n] * h[n]$.



##### # Computation of Convolution Sum

The definition of convolution sum requires the 

Steps of the computation of convolution sum:

1. Change of variable.

2. Reverse and translation. ("Convolute")

3. Product.

4. Sum.

Here an example is given to illustrate this process:

Example 1. For the input signal 

$$
x[n] = 
\left\{\begin{array}{ll}\begin{align}
&1, ~~~~ 0\le n \le4 \\
&0, ~~~~ \mathrm{otherwise}
\end{align}\end{array}\right.
$$

and the unit response

$$
h[n] = 
\left\{\begin{array}{ll}\begin{align}
&\alpha^n, ~~~~ 0\le n \le6 \\
&0, ~~~~ \mathrm{otherwise}
\end{align}\end{array}\right.
$$

where the 













### Convolution Integral





##### # Computation of Convolution Integral

Steps of the computation of convolution integral is similar to the convolution sum:

1. Change of variable.

2. Reverse and translation.

3. Product.

4. Integrate.






























