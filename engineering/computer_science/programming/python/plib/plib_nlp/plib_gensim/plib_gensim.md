# Gensim

[Gensim](https://radimrehurek.com/gensim/) (Generate Similar) is a open source natural language processing library used for unsupervised topic modelling,  using academic models and modern statistical machine learning.

Four core concepts of `gensim`:

1. Document: some text.
2. Corpus: a collection of documents.
3. Vector: representation of docuemnt.
4. Model: an algorithm for transforming vectors from one representation to another.





### `gensim.models.Word2Vec`

##### Training Process of `gensim.models.Word2Vec`

`gensim.models.Word2Vec` applys word2vec model to training text.

```python
from gensim.test.utils import common_texts
from gensim.models import Word2Vec

model = Word2Vec(sentences=common_texts, vector_size=100, window=5, min_count=1, workers=4)
```

where the sentences shall be presented by list of sentences(which is presented by list of words).

After training, the model can be saved as a file and load in the future:

```python
model.save("word2vec.model")
model = Word2Vec.load("word2vec.model")
```

The training is incremental and streamed, you can train the model later with new sentences:

```python
model.train([['hello', 'world']], total_examples=1, epochs=1)
```



##### Access Word Vector from `gensim.models.Word2Vec`

The trained word vectors are stored in a `KeyedVectors` instance:

```python
computer_vec = model.wv['computer']
```

We can store the trained word vector as an independent file and disgard the model if it's no longer needed:

```python
from gensim.models import KeyedVectors

word_vectors = model.wv
word_vectors.save("wordvectors")
wv = KeyedVectors.load("wordvectors", mmap='r')
```
