# SAT Algorithm

 ==SAT Algorithm, an algorithm to find the values fit a logic expression. literal, clause, CNF-formula.==

The algorithm contains three basic model:

1. `Decide()` function, 
2. `BCP()` function, [Boolean Constraint Propagation](https://www.coursera.org/lecture/vlsi-cad-logic/boolean-constraint-propagation-bcp-for-sat-OTOi5)
3. `resolveConflict()` function;

The search should be formed as a **Decision Tree**;

Backtracking Search in Action.

Status of Clause: Satisfied, Unsatisfied, Unit, Unresolved. Noticed that `Unit` Status is special and important. The prinicipal of `BCP()` algorithm is searching the pool of status, find the `Unit` Status and give it the proper value.

The degisn of `Decide()` and `resolveConfiit()` is tricky. When `BCP()` can not push anymore, the `Decide()` function must decide which variable to guess for next step, this required the

Implication graphs and learning

Non-chronological backtracking

More Conflict Clauses

Asserting Clause: Instant BCP affect. The first-UIP is the closest UIP to the conflict.



Conflict-driven backtracking (Option #2)

```pseudocode
procedure Analyze-Conflict
```





##### # Binary Resolution

$$
\cfrac{F(x)\lor p  \qquad G(x)\lor\neg p} {F(x)\lor G(x)}
$$



