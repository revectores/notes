$$
\newcommand{\d}{\text{d}}
\newcommand{\dt}{\d t}
\newcommand{\euler}{\mathrm{e}}
$$

### Fouries Series Representation of Continuous Signal

Given a signal $x(t)$ that can be presented as the sum of harmonically related signals:

$$
x(t) = \sum_{k=-\infin}^{\infin}a_ke^{jkw_0t}
$$

where $w_0$ is the base frequency. The parameter $a_k$ can be computed as

$$
a_k = \frac{1}{T}\int_T x(t)e^{-jk\omega_0t}\dt
$$

> Proof.
> Multiple $e^{-jn\omega_0t}$ on both sides of the series expression of $x(t)$ and integrate from $0$ to $T$ respect to $t$:
> 
> $$
> \begin{align}
> \int_0^T x(t)e^{-jn\omega_0t} \dt &= \int_0^T \sum_{k=-\infin}^{\infin}a_ke^{j(k-n)w_0t}\dt  \\
> &= \sum_{k=-\infin}^{\infin}a_k \int_0^T e^{j(k-n)w_0t}\dt  \\
> \end{align}
> $$
> 
> Notice that $\displaystyle\int_0^T e^{j(k-n)w_0t}\dt = \int_0^T \cos(k-n)\omega_0 t + j \int_0^T \sin(k-n)\omega_0 t$, LHS indicates that for $k=n$ the integral equals to $T$, and RHS indicates that for $k\neq n$ the integral equals to $0$, since the integral length $T$ must be the multiple of period of $\cos(k-n)\omega t$ and $\sin(k-n)\omega t$. i.e.
> 
> $$
> \int_0^T e^{j(k-n)w_0t}\dt = 
> \left\{\begin{array}{ll}\begin{align}
> T, ~~~~ & k = n \\
> 0, ~~~~ & k \neq n
> \end{align}\end{array}\right.
> $$
> 
> Hence, only $Ta_n$ left on the RHS of the equation:
> 
> $$
> \int_0^T x(t)e^{-jn\omega_0t} \dt = Ta_n
> $$
> 
> which concludes the theorem.

Specially, if the signal $x(t)$ is a **real signal**, we can represent it by trigonometric function, specifically, if $a_k = A_ke^{j\theta_k} = B_k + jC_k$, we can rewrite $x(t)$ as following:

$$
x(t) = a_0 + 2\sum_{k=1}^{\infin} A_k\cos{(k\omega_0t+\theta_k)}
=  a_0 + 2\sum_{k=1}^{\infin}\left(B_k\cos{k\omega_0 t} - C_k\sin{k\omega_0 t}\right)
$$

> Proof. since $x(t)$ is real signal, we have $x(t) = x^*(t)$, a.k.a. x(t) is always the same with its conjugate.
>
> $$
> \begin{align}
> x(t) &= x^*(t) \\
>  \sum_{k=-\infin}^{\infin}a_k e^{jk\omega_0 t} &= \sum_{k=-\infin}^{\infin}a^*_k e^{-jk\omega_0 t} = \sum_{k=-\infin}^{\infin}a^*_{-k} e^{jk\omega_0 t}
> \end{align}
> $$
>
> comparing both sides, we have $a_k = a^*_{-k}$, which could be used to simplify the expression of $x(t)$:
> $$
> \begin{align}
> x(t) &= \sum_{k=-\infin}^{\infin}a^*_{k} e^{jk\omega_0 t} \\
> &= a_0 + \sum_{k=1}^{\infin} (a_{k} e^{jk\omega t} + a_{-k} e^{-jk\omega_0 t}) \\
> &= a_0 + \sum_{k=1}^{\infin} (a_{k} e^{jk\omega t} + a^*_{k} e^{-jk\omega_0 t}) \\
> \end{align}
> $$
>
> Notice that $a_k = \overline{a^*_{k}}$, and $e^{jk\omega t} = \overline{e^{-jk\omega t}}$, hence
> $$
> \begin{align}
> x(t) = a_0 + \sum_{k=1}^{\infin} 2\mathcal{Re}\{{a_k e^{jk\omega t}}\}
> \end{align}
> $$
>
> Denoted $a_k = A_k e^{j\theta_k}$, with the Euler Theorem applied,
> 
> $$
> x(t) = a_0 + 2\sum_{k=1}^{\infin} A_k\cos{(k\omega_0t+\theta_k)}
> $$
>
> Or denoted $a_k = B_k + jC_k$, where $B_k$ and $C_k$ are both real number, with the Euler Theorem applied, 
>
> $$
> x(t) = a_0 + 2\sum_{k=1}^{\infin}\left(B_k\cos{k\omega t} - C_k\sin{k\omega t}\right)
> $$
>
>



### Property of Fouries Transformation

1. Linearity. For any two signals $x(t), y(t)$ which corresponding to fouries series $a_k, b_k$, the fouries series of the linear combination of them will also be the same linear combination of the fouries series:

$$
z(t) = Ax(t) + By(t) \xrightarrow[]{\mathcal{FS}} c_k = Aa_k + Bb_k
$$






















































