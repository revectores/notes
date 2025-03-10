# Knapsack Problem

### 0-1 Knapsack Problem

##### # Definition

For $n$ given items, each with a weight $w_i$ and value $v_i$, determine which items to pick up into the knapsack with weight limit $W$, to maximize the values in knapsack. Formally speaking, we're going to do the optimization $F(x)$:
$$
F(x) = \sum_{i=0}^n x_iv_i, \qquad \sum_{i=0}^n x_iw_i\leq W, \ x_i\in\{0,1\}
$$
Since the items are indivisible, the selection sign variable $x_i$ can only be 0 (not selected) or 1 (selected), that's why this type of problem is named `0-1 Knapsack Problem`, which is the simplist problem for knapsack.

Let's devide the final chosen items into a selection process:

