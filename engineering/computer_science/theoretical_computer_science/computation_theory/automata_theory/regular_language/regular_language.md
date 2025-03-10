# Regular Language







## 3. Pumping Lemma

Let $L$ be a regular language. Then there exists a constant $n$ (which depends on $L$) such that for every string $w$ in $L$ such that $|w| \ge n$, we can break $w$ into three strings, $w = xyz$, such that

1. $y\neq\epsilon$
2. $|xy|\le n$
3. For all $k\ge 0$, the string $xy^kz$ is also in $L$

That is, we can always find a nonempty string $y$ not too far from the beginning of $w$ that can be "pumped"; that is, repeating $y$ any number of times, or deleting it (the case $k = 0$), keeps the resulting string in the language $L$.

