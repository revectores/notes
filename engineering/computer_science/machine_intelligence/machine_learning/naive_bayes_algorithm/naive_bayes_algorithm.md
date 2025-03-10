# Naive Bayes Algorithm

Just simply apply the Bayes' rule, the likelihood and prior probability are given by training set, choose the one prediction with maxmium inverse probability. Formally,
$$
\hat y = \arg\max_{y\in \mathcal Y} P(y|X)
$$
where the inverse probability is computed as
$$
P(y|X) = \cfrac{P(Xy)}{P(X)} = \cfrac{P(y)P(X|y)}{\displaystyle\sum_{y\in \mathcal Y}P(y)P(X|y)}
$$
where terms $P(y), P(X|y)$ are computed(learned) from training test.

Through its a quite simple applying the Bayes' rule directly, its the basis of many other more complex algorithm(that's why we call it naive), and Naive Bayes with its developed version has been widely applyed in a wide range of statistical learning tasks like [text classification]().

