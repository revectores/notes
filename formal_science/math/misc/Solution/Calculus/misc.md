##### # Exercise 1.

Calculate integral:

$$
\int \cfrac{\ln{x}-1}{\ln^2{x}} \text{d}x
$$

Notice that the denominator is the square form, so this might be the result of the application of division rule of derivative:

$$
\left(\cfrac{x}{\ln{x}}\right)' = \cfrac{\ln{x}-1}{\ln^2{x}} 
$$

If this observation is not trivial to you, we can also use the partical integral method:

$$
\begin{align}
\int \cfrac{\ln{x}-1}{\ln^2{x}} \text{d}x
&= \int \cfrac{1}{\ln{x}} \text{d}x - \int \cfrac{1}{\ln^2{x}} \text{d}x \\
&= \cfrac{x}{\ln{x}} - \int x ~ \text{d}\ \cfrac{1}{\ln{x}} - \int \cfrac{1}{\ln^2{x}} \text{d}x \\
&= \cfrac{x}{\ln{x}} - \int x \cdot \left(-\cfrac{1}{x\ln^2{x}}\right) \text{d}x - \int \cfrac{1}{\ln^2{x}} \text{d}x \\
&= \cfrac{x}{\ln{x}}
\end{align}
$$




