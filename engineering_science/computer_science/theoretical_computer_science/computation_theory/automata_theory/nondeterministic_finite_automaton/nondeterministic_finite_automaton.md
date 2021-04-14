# Nondeterministic Finite Automaton

##### # Definition

A **nondeterministic finite automata** is a five-tuple pair $A = (Q, \Sigma, \delta, q_0, F)$:

1. A finite set of states $Q$.
2. A finite set of input symbols $\Sigma$.
3. The start state $q_0 \in Q$.
4. The set of final (accepting) states $F\subset Q$.
5. A transition function $\delta$, that takes a state in $Q$ and an input symbol in $\Sigma$ as arguments and return a subset of $Q$.

The only difference between an NFA and a DFA is in the type of value that $\delta$ returns: a set of states in the case of NFA and a single state in the case of a DFA.

