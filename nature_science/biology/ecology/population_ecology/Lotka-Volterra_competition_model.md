# Lotka-Volterra Competition Model

$$
\newcommand{\d}{\text d}
\newcommand{\dt}{\d t}
\newcommand{\dN}{\d N}
$$

##### # Modeling

For the two competition species with population number $N_1, N_2$, the environment environmental capacity and instant growth rate are $K_1, r_1, K_2, r_2$ respectively. For the species 1, based on [Logistic equation](), we have
$$
\frac{\dN_1}{\dt} = r_1N_1\left( 1-\frac{N_1}{K_1}-\alpha\frac{N_2}{K_1} \right)
$$
where $\alpha$ is the **competition coefficient** from species 2 to species 1, the physical meaning is "one animal of species 2 is the same as $\alpha$ animals of species 1". Similarly, for species 2 we have
$$
\frac{\dN_2}{\dt} = r_2N_2\left( 1-\frac{N_2}{K_2}-\alpha\frac{N_1}{K_2} \right)
$$
where $\alpha$ is the competition coefficient of species 1 to species 2.

The two equations give the **Lotka-Volterra competition model**.



##### # Conclusion[^1]

We could use the reciprocal of capacity $K^{-1}$ as the indicator of the **intensity of intraspecific competition,** and $\alpha K_1^{-1}$ as the **intensity of interspecific competition** from species 2 to species 1, symmetrically, $\beta K_2^{-1}$ as the intensity of interspecific completition from species 1 to species 2.

One species win in the interspecific competition, if and only if the intensity of interspecific completition larger than the intensity of intraspecific competition, that is

1. $K_1^{-1} < \beta K_2^{-1}, K_2^{-1} > \alpha K_1^{-1}$, species 1 win, species 2 is excluded.
2. $K_1^{-1} > \beta K_2^{-1}, K_2^{-1} < \alpha K_1^{-1}$ , species 2 win, species 1 is excluded.
3. $K_1^{-1} < \beta K_2^{-1}, K_2^{-1} < \alpha K_1^{-1}$, both species might win, unstable equilibrium.
4. $K_1^{-1} > \beta K_2^{-1}, K_2^{-1} > \alpha K_1^{-1}$, both species exist.





[^1]: The detailed proof refers to 《基础生态学(第2版)》P133-P134

