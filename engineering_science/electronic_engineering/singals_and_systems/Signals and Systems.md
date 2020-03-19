Since $y[n] = x[n] - x[n-1]$, and $x[0] = 1$, there is two special $y$,
$$
y[0] = x[0] - x[-1] = 1 \\
y[1] = x[1] - x[0] = -1
$$
and for other value of $n$, $y[n] = x[n] - x[n-1] = 0-0=0$ is a constant, so 1,3,5 is correct.

As for conclusion 4, use the definition:
$$
y[n] = x[n] - x[n-1] \\
y[n-1] = x[n-1] - x[n-2]
$$



As the result,
$$
y[n] - y[n-1] = x[n] - 2x[n-1] + x[n-2]
$$
is correct.

Actually, $y[n]$ symbols the derivative of $x[n]$, and $z[n] = y[n] - y[n-1]$ is the second order derivative of $x[n]$.

