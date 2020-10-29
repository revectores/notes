# Text Classification

### 1. Basic Concept

##### # Definition

A mapping $h$ from input data $x$ (drawn from instance space $\mathcal X$) to a label (or labels) $y$ from some enumberable output space $\mathcal Y$.



##### # Classification of Text Classification

- Content classification
- Emotion classification
- Form classification



##### # Methods

- Hand-coded rules.

    pros: high acc

    cons: low recall, hard to construct and maintain rule.

- [Supervised learning](). Use a training set of $m$ hand-labeled documents $(d_1, c_1), \ldots, (d_m, c_m)$.

- 







### 2. Classification Process

```mermaid
graph LR;

tp[Text Preprocessing]
tr[Text Representation]
fs[Feature Selection]
model[Model Construction]
tp --> tr --> fs --> model
```

To represent the document as computer-understandable, we shall express document as the vector in vector space. The distance between vector should indicate the semantic distance.

One classical method of vectorize a document using the **bag of word**, which is simply the counts of words:

```python
bag_of_word = {
    "word": 5,
    "hello": 2,
    # ...       
}
```

Problems of bag of word:

- Words relation lost. The bag of words just counts the word itself but the context information is not included.
- Sparse matrix.

The word of bags usually are too large to use, we should do features selection based on some statistical correlation indicators between the feature and type like frequency, mutual information, informaytion gain, $\chi^2$ etc.

Convential machine learning models for text classification:

- [Naive Bayes]()
- [Logical Regression]()
- [SVM]()
- [CNN]()







### 3.  Classification

##### # [Naive Bayes Algorithm]() for Text Classification

Recall Naïve Bayes Algorithm which simply applies the Bayes' Rule to compute all the inverse probability and pick the maxmium one as prediction:
$$
\hat y = \arg\max_{y\in \mathcal Y} P(Y|X)
$$
where the inverse probability is computed as
$$
P(Y|X) = \cfrac{P(XY)}{P(X)} = \cfrac{P(Y=y)P(X=x|Y=y)}{\displaystyle\sum_{y\in \mathcal Y}P(Y=y)P(X=x|Y=y)}
$$
where terms $P(Y=y), P(X=x|y=y)$ are computed(learned) from training test.

In the context of document classification that vectorizing document by , the parameters are interpreted as:

- $Y$: The labels set.
- $X$: The set of words.





We implement Naive Bayes [text_classification_naive_bayes.py](text_classification_naive_bayes/text_classification_naive_bayes.py).

