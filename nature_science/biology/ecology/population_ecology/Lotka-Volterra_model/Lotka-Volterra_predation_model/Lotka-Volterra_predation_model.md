# Lotka-Volterra Predation Model

> Predators run for their dinner. Prey run for their lives.
>
> <p align="right">—Old Ecologist's Proverb</p>

$$
\newcommand{\d}{\text d}
\newcommand{\dt}{\d t}
\newcommand{\dN}{\d N}
\newcommand{\dP}{\d P}
$$

Denote $N$ as the population size of pery and $P$ as the population size of predator. Assume the pery population grows exponentially if there is no predator, and the population decrease exponentially if there is no prey, and assume the probability they meet depends on the production of both sizes. **Lotka-Volterra predation model** can be inferred:

$$
\left\{\begin{array}{ll}\begin{align}
& \frac{\dN}{\dt} = r_1N - \varepsilon PN \\
& \frac{\dP}{\dt} = -r_2P + \theta PN
\end{align}\end{array}\right.
$$
where the $\varepsilon$ is the **predator attack effeciency**, and $\theta$ is the **predator constant**, which indicates the effeciency of conversion from prey to predator (depends on the energy effeciency).

