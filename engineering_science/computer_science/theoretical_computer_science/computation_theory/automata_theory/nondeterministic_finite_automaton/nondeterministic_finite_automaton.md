# Nondeterministic Finite Automaton



## 1. Basic Concepts

##### # Definition

A **nondeterministic finite automata** is a five-tuple pair $A = (Q, \Sigma, \delta, q_0, F)$, where

- $Q$ is a finite set of states.
- $\Sigma$ is a finite set of input symbols.
- $q_0\in Q$ is the start state.
- $F\subset Q$ is the set of final (accepting) states.
- $\delta$ is a transition function that takes a state in $Q$ and an input symbol in $\Sigma$ as arguments and return a subset of $Q$.

The only difference between an NFA and a DFA is in the type of value that $\delta$ returns: a set of states in the case of NFA and a single state in the case of a DFA.



##### # Representation

Transition table and transition diagram can also be used to represent NFA, with two major differences:

- In transition table, the output of transition function is a set (even with the unique element), instead of a value.
- In transition diagram, there can be multiple arrows with the same input value.



##### # Extended Transition Function

Similarly, we can define extend transition function to accept a string in NFA, by applying mathematical induction:

**Basis**. $\hat\delta(q, \varepsilon) = \{q\}$.

**Induction**.  $\hat\delta(q, w) = \displaystyle\bigcup_{i=1}^k\delta(p_i, a)$, where $\{p_i \mid 0\le i\le k\} = \hat\delta(q, x)$.







### 2. Equivalence: DFA and NFA

The language of NFA $A$ is
$$
L(A) = \{w \mid \hat\delta(q_0, w) \cap F \neq \varnothing\}
$$
now we're going to prove the equivalene of expressiveness of DFA and NFA. That is, all languages that can be expressed by NFA can also be expressed by DFA (we'll prove this by **subset construction**), and all langauges that can be expressed by DFA can also be expressed by NFA (since NFA supports a superset of operations of DFA, this direction is trivial and left as an exercise).

Given a NFA $N = (Q_N, \Sigma, \delta_N, q_0, F_N)$, our target is to construct a DFA $D = \{Q_D, \Sigma, \delta_D, \{q_0\}, F_D\}$ which meets $L(D) = L(N)$. Note that the construction of alphabet and initial state is trivial. In addition:

- $Q_D = 2^{Q_N}$.
- $F_D = \{S \mid S\cap F_N \neq \varnothing \}$.
- $\delta_D(S, a) = \displaystyle \bigcup_{p\in S}\delta_N(p, a) ,~\forall S\in Q_N$.

> **Theorem**. If $D = \{Q_D, \Sigma, \delta_D, \{q_0\}, F_D\}$ is constructed from $N = (Q_N, \Sigma, \delta_N, q_0, F_N)$ from subset construction, $L(D) = L(N)$.
>
> **Proof**. Apply mathematical induction to formula
> $$
> \hat\delta_D(\{q_0\}, w) = \hat\delta_N(q_0, w)\tag{1}
> $$
> **Basis**. For $|w| = 0$, that is, $w = \varnothing$, we have
> $$
> \hat\delta_D(\{q_0\}, \varepsilon) = \hat\delta_N(q_0, \varepsilon) = \{q_0\}
> $$
> **Induction**. Suppose (1) is correct for $|w| = n$, then for $|w| = n + 1$, decompose $w$ by $w = xa$, the assumption gurantees $\hat\delta_D({q_0, x}) = \hat\delta_N(q_0, x) = \{p_1, p_2, \ldots, p_l\}$.
>
> Now we have
> $$
> \begin{align}
> \hat\delta_D(\{q_0\},w)
> &= \delta_D(\hat\delta_D(\{q_0\}, x), a) \\
> &= \delta_D({p_1, p_2, \ldots, p_k}, a)  \\
> &= \bigcup_{i=1}\delta_N(p, a)           \\
> &= \hat\delta_N(q_0, w)
> \end{align}
> $$
> which shows that (1) is correct for $n + 1$. In summary, (1) holds for all natural numbers.

