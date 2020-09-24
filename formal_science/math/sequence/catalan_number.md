# Catalan Number

The n-th **Catalan number** (sequence [A000108](https://oeis.org/A000108) in OEIS) is defined as
$$
C_n = \frac{1}{n+1}{2n\choose n} = \frac{(2n)!}{(n+1)!n!} = \prod_{k=2}^n\frac{n+k}{k}
$$
which satisfy the recurrence relation
$$
C_0 = 1 ~~~~ C_{n+1} = \sum_{i=0}^nC_iC_{n-i}
$$
Catalan number arise in multiple problems in combinatorics and computer science:

- 



