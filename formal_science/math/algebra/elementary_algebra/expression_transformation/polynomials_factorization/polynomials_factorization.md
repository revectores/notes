# Polynomials Factorization

> Factor $a^3+b^3+c^3-3abc$.
>
> Observation. Notice that the polynomial is symmetric, we guess it contains $(a+b+c)$, to generate $a^3$, we need to provide $a^2$, hence $(a^2+b^2+c^2)$ must be included due to the symmetry, but this also generate $a^2b$, hence we need to substract a second-order symmetric polynomial $(ab+bc+ca)$ to remove the redundant term, hence we got
> $$
> a^3+b^3+c^3 - 3abc = (a+b+c)(a^2+b^2+c^2-ab-bc-ca)
> $$

