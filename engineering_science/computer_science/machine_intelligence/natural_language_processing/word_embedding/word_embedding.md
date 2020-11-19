# Word Embedding

**Word embedding** is to map words into to $\R^n$. Words that appear in similar **contexts** have similar representations (and similar meanings, by the distributional hypothesis).



For the term-document matrix, we use tf-idf instead of raw term counts.

For the term-context matrix, **positive pointwise mutual information(PPMI)** is common.

##### # tf-idf

$$
\text{tf}_{i, j} = \frac{n_{i, j}}{\displaystyle\sum n_{k,j}}
$$

$$
\text{idf}_i = \log\frac{|D|}{|\{ d: t_i \in d\}|}
$$

$$
\text{tfidf}_{i, j} = \text{tf}_{i, j}\cdot\text{idf}_{i}
$$



##### # Pointwise Mutual Information

$$
\text{PMI}(X, Y) = \log_2\frac{P(x, y)}{P(x)P(y)}
$$

$$
\text{PMI}(\text{word}_1, \text{word}_2) = \log\frac{P()}{}
$$



##### # Cosine Similarity







### 3. SVD

Singular Value De

