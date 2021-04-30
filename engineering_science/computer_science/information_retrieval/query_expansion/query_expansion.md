# Query Expansion

Query expansion expands each word using the relavent words in thesaurus. This approach is widely used in the scientific and engineering search engine.

Query expansion usually improve recall, but may reduce precision significantly, especially for those words with ambiguity.

Some methods to construct **thesaurus**:

1. Construct manually.

2. Automatically constructed by similarity based on statistical information.

    How to mining similarity:

    - Words with similar co-occurrence words in the context are similar. The most simple method is to compute the word-word similarity based on the dictionary-document matrix $C = AA^T$. $c_{ij}$ now represent the co-occurrence frequency of word $w_i, w_j$. 
    - Words has similar grammar relations with similar words are similar.

    ==The co-occurrence relation is more robust while the grammar relation is more precise: Why?==

3. Automatically constructed by query logs (This approach is widely used in Web). For instance:

    - User tends to search `herbal remedies ` after query `herbs`: This infers `herbal remedies` is the potential query expansion of `herbs`.
    - User click the same URL `photobucket.com/flower` in query `flower pix` and `flower clipart`: These two query may be query expansion of each other.

