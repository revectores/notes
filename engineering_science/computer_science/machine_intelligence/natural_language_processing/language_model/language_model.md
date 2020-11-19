# Language Model


$$
\prod_i^n P(\omega_i) \times P(STOP)
$$

$$
\prod_i^n P(\omega_i | \omega_{i-1}) \times P(STOP | w_n)
$$

$$
\prod_i^n P(\omega_i | \omega_{i-2}, \omega_{i-1}) \times P(STOP | \omega_{n-1}, \omega_n)
$$



Perplexity: inverse probability of test data, averaged by word.
$$
p = \sqrt[N]{{[P(\omega_1, \ldots, \omega_n)]^{-1}}}
$$


Data sparsity
$$
P(x_i|y) = \frac{n_{i, y}+\alpha}{n_y + V\alpha}
$$


Interpolation

A linear interpolation of any two language models $p$ and $q$ with $\lambda\in[0, 1]$ is also a valid language model
$$
r = \lambda p + (1-\lambda)q
$$
use this 

expectation-maximization algorithm: treat as missing parameters to be estimated to maximize the probability of the data we see.



Kneser-Ney smoothing 
$$
P_{CONTINUATION}(\omega) = \frac{v\in \mathcal{V}: c(v, w)>0}{v', w'\in \mathcal{V}: c(v', w') > 0}
$$

$$
\frac{\max\left\{{c(w_{i-1}, w_i)} -d, 0\right\}}{c(w_{i-1})} + \lambda(w_{i-1})P_{CONTINUATION}(w_i)
$$







