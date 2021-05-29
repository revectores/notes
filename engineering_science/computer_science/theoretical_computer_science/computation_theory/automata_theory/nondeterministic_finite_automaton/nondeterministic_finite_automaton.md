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

