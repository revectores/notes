# Spelling Correction



Types of spelling errors:

- Non-word errors
- Real-word errors
    - Typographical errors
    - Cognitive errors (homophones)



Noisy channel model: We see an observation $x$ of a misspelled word, find the correct word $w$.
$$
\begin{align}
\hat w
&= \arg\max_{w\in V} P(w|x) \\
&= \arg\max_{w\in V} \frac{P(x|w)P(w)}{P(x)} \\
&= \arg\max_{w\in V} P(x|w)P(w)
\end{align}
$$


Candidate generation

- Words with similar spelling: small edit distance to error
- Words with similar pronunciation.



Damerau-Levenshtein edit distance.

Minimal edit distance between two string, where edits are:

- insertion
- deletion
- substitution
- transposition of two sadjacent letters





For two strings, $X$ of length $n$ and $Y$ of length $m$, we define $D(i, j)$ as the edit distance between $X[1..i]$ and $Y[1..j]$ (the first $i$ characters of $X$ and the first $j$ characters of $Y$), then the edit distance between $X$ and $Y$ is $D(n, m)$.

Dynamic programming:

initialize $D(i, 0) = i, D(0, j) = j$, 
$$
D(i, j) =
\min \{D(i-1, j) + 1, D(i, j-1)+1, D(i-1, j-1)+d \} \\
$$
where
$$
d = \left\{\begin{array}{ll}
2, ~~~~ X(i)\neq Y(j)  \\
0, ~~~~ X(i) = Y(j)
\end{array}\right.
$$


|  N   |  9   |      |      |      |      |      |      |      |      |      |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|  O   |  8   |      |      |      |      |      |      |      |      |      |
|  I   |  7   |      |      |      |      |      |      |      |      |      |
|  T   |  6   |      |      |      |      |      |      |      |      |      |
|  N   |  5   |      |      |      |      |      |      |      |      |      |
|  E   |  4   |      |      |      |      |      |      |      |      |      |
|  T   |  3   |      |      |      |      |      |      |      |      |      |
|  N   |  2   |      |      |      |      |      |      |      |      |      |
|  I   |  1   |      |      |      |      |      |      |      |      |      |
|  #   |  0   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |
|      |  #   |  E   |  X   |  E   |  C   |  U   |  T   |  I   |  O   |  N   |

