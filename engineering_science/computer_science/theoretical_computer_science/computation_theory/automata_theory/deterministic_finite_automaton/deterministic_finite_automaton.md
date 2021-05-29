

## 1. Basic Concepts

##### # Definition

A **deterministic finite automaton** is a five-tuple pair $A = (Q, \Sigma, \delta, q_0, F)$, where

- Q is a finite set of states.
- $\Sigma$ is a finite set of input symbols $\Sigma$.
- $q_0$ is the start state.
- $F \subset Q$ is a set of **final (accpeting) states**.
- $\delta$ is a **transition function** that takes a state and an input as arguments symbol and returns a state.

> **Example of DFA**. For instance, consider language
> $$
> L = \{\omega \mid x01y,~ x,y\in\{0, 1\}^* \}
> $$
> which can be expressed by the DFA $A = (\{q_0, q_1, q_2\}, \{0, 1\}, \delta, q_0, \{q_2\})$, where the $\delta$ is defined by
> $$
> \delta(q_0, 0) = q_1    \qquad
> \delta(q_0, 1) = q_0    \qquad \\
> \delta(q_1, 0) = q_0    \qquad
> \delta(q_1, 1) = q_2    \qquad \\
> \delta(q_2, 0) = q_2    \qquad
> \delta(q_2, 1) = q_2    \qquad \\
> $$
>
> 



##### # Representation

**Transition diagram** and **transition table** are two preferred notations to represent DFA, as also other automata, since they are more intuitive to human beings.

The DFA given previously can be expressed by a transition table:

|       |  $0$  |  $1$  |
| :---: | :---: | :---: |
| $q_0$ | $q_1$ | $q_0$ |
| $q_1$ | $q_0$ | $q_2$ |
| $q_2$ | $q_2$ | $q_2$ |

and visualized as transition diagram:

<img src="__img__/dfa_transition_diagram_demo.png" alt="dfa_demo" style="zoom:25%;" />



##### # Extended Transition Function

The built-in transition function of DFA only consumes one symbol at a time. It can be convient to extend this notation to define a new operation that consumes multiple symbols (that is, a string), at a time, and produce the result given by the string path.

To formalize this idea, we define the **extended transition function** by applying mathematical induction:

**Basis**. $\hat\delta(q, \varepsilon) = q$.

**Induction**. $\hat\delta(q, w) = \delta(\hat\delta(q, x), a)$, where $w = xa$, that is, $a$ is the last symbol of $w$, and $x$ is the string consisting of all but the last symbol.







## 2. Regular Language

Using notation of extended transition function, the **language of DFA** $A = \{Q, \Sigma, \delta, q_0, F\}$ can be defined as
$$
L(A) = \{w \mid \hat\delta(q_0, w) \in F\}
$$
If $L$ can be expressed by some DFA, formally, if $L$ is $L(A)$ for some DFA $A$, we call $L$ a **regular language**.

