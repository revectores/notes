**Example**. To express an algorithm succinctly in a program, it does not matter which programming language we use (up to a fixed additive constant that depends only on the two programming languages).

**Proof**. Let $L_1, L_2$ the two languages. Consider the lexicographic enumeration of all syntactically correct $L_1, L_2$ programs $\lambda_1, \lambda_2, \ldots$ and $\pi_1, \pi_2, \ldots$, which can be viewed as computing partial recursive functions. We can define $C_{L_1}(x)$ and $C_{L_2}(x)$ analogous to $C(x)$. Now we're going to prove that
$$
|C_{L_1}(x) - C_{L_2}(x)| \le c_{L_1, L_2}
$$


