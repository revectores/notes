##### # The coupon collector problem

> Problem. Find the mathematical expectation of count of roll to collected all possible numbers (1-6).

Let $X$ be the count expectation. Let $X_i$ be the count expectation to get a new number after $j$ possible numbers have been collected. Then we have
$$
E(X) = E\left(\sum_{i=0}^5 X_i \right) = \sum_{i=0}^5 E(X_i)
$$
where
$$
E(X_i) = \sum_{k=1}^\infty k P(X_i = k)
       = \sum_{k=1}^\infty kp^{k-1}(1-p)
       = \sum_{k=1}^\infty k(p^{k-1} - p^k)
       = \sum_{k=0}^\infty p^{k}
       = \frac{1}{1-p}
$$
where $p = \cfrac{i}{6} < 1$. Hence
$$
E(X) = \sum_{i=0}^5  E(X_i) = 6\sum_{i=0}^5 \frac{1}{i} = 6\times\left(1 + \frac{1}{2} + \cdots + \frac{1}{6} \right)
$$
Generally for $k$-coupon case we have
$$
E(X) = n H_n
$$
where $H_n$ is harmonic series.