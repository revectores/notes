# Turing Machine

$$
\newcommand{\eq}{\Leftrightarrow}
$$

##### # Definition

A **Turing machine (TM)** is a 7-tuple

$$
M = (Q, \Sigma, \Gamma, \delta, q_0, B, F)
$$

where

- $Q$ is the finite set of states of the finite control.
- $\Sigma$ is the finite set of **input symbols**.
- $\Gamma$ is the complete set of tape symbols; $\Sigma$ is always a subset of $\Gamma$.
- $\delta$ is the transition function. The arguments of $\delta(q, X)$ are a state $q$ and a tape symbol $X$. The value of $\delta(q, X)$, if it is defined, is a triple $(p, Y, D)$, where
    1. $p$ is the next state, in $Q$.
    2. $Y$ is the symbol, in $\Gamma$, written in the cell being scanned, replacing whatever symbol was there.
    3. $D$ is a direction, either $L$ or $R$, standing for "left", or "right", respectively, and telling us the direction in which the head moves.
- $q_0$ is the start state, in $Q$, in which the finite control is found initially.
- $B$ is the **blank** symbol. symbol is in $\Gamma$ but not in $\Sigma$. i.e., it is not an input symbol. The blank appears initially in all but the finite number of initial cells that hold input symbols.
- $F$ is the set of final or accepting states, a subset of $Q$.

