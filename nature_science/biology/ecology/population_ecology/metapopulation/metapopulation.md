# Metapopulation

$$
\newcommand{\d}{\text{d}}
\newcommand{\dp}{\d p}
\newcommand{\dt}{\d t}
$$

##### # Metapopulation Definition

The **metapopulation** consists of a group of spatially separated populations of the same species which interact at some level. Metapopulation is the population of population. The processing of [habitat fragmentation](https://en.wikipedia.org/wiki/Habitat_fragmentation) makes humans attach importance to this concept.

The **metapopulation size** is defined as the numbe of habitat patches that has been occupied and the total number of habitat patches:
$$
p(t) = \frac{h(t)}{H}
$$
where $0\le p\le 1$, $p=0$ indicates the extinction of metapopulation, and $p=1$ indicates that all the patches have been occupied.



##### # Turnover

**Turnover** is the event when a habitat patch becomes unoccupied through extinction and is then recolonized by individuals from other local populations. The speed of turnover decreases if the area of path decreases or the isolation degree increases.



##### # Levins Model

Levins Model describe the growth of metapopulation:
$$
\frac{\dp}{\dt} = mp(1-p)-ep
$$

where $m$ is the migration rate, and $e$ is the extinction rate. The balance state is given by $\dfrac{\dp}{\dt} = 0$, that is $p_0 = 1-e/m$. If $p < p_0(m < e)$, the metapopulation will become extinct eventually, if $p>p_0(m>e)$ the metapopulation continues to exist.

The Levins model can be written as the form
$$
\frac{\dp}{\dt} = (m-e)p\left( 1 - \frac{p}{1-e/m} \right)
$$
which indicates that Levins model is equivalent to [Logistic equation](/Users/rex/Library/Mobile Documents/com~apple~CloudDocs/skill/notes/nature_science/biology/ecology/population_ecology/population_growth_model/population_growth_model.md#logistic-equation), where the $(m-e)$ can be intepreted as the instant growth rate and $\left(1-\dfrac{e}{m}\right)$ is the $K$-value.

