# Clustering

Clustering is a new and fast-developing domain in machine learning. In this notes we'll first give basic concepts, including definition and the performance index of clustering, then talk about three types of clustering:

- Prototype-based clustering.
- densitry-based clustering.
- hierarchical clustering.



### Concepts

##### # Definition

Clustering is partition of unlabelled samples set. i.e. Clustering partition $D=\{x_1, x_2, ..., x_m\}$ into $k$ **disjoint** different cluster $\{C_l ~|~ 1\le l\le k\}$. We denoted $1\le\lambda_j\le k$ as **cluster label** of sample $x_j$, that is, $x_j\in C_{\lambda_j}$, and represents the result of clustering process as the vector of  $m$ labels: ${\boldsymbol\lambda} = \{\lambda_1, \lambda_2, ..., \lambda_m \}$.



##### # Validity Index

There are two types of approaches to check the performance of a clustering algorithm, use the **external index** or **internal index**.

The external index clustering the samples manually, which called **reference model**. and we check the difference between reference model and the result given from the algorithm. For any two sample $x_i, x_j$, reference model indicates the positive (in same cluster) and negative (in different cluster) in reality.

Here we give three classical types of external index:

- **Jaccard Coefficient(JC)** .
    $$
    \text{JC} = \frac{TP}{TP+FP+FN}
    $$

- **Forlkes-Mallows Index(FMI)**.
    $$
    \text{FMI} = \sqrt{\frac{TP}{TP+FP}\times\frac{TP}{TP+FN}}
    $$

- **Rand Index(RI)**.
    $$
    \text{RI} = \frac{TP+TN}{TP+TN+FP+FN}
    $$



For the most cases, it's not possible to give the reference model manually (anyway, in this case we've actually labelled all the samples, why brother to use unsupervised learning method...?). Internal index uses the internal information of the distances among samples to try to validate whether an algorithm is proper. The core idea is to compare the **similarity** inside cluster and **difference** among clusters. Clearly, the algorithm is better for the higher similarity inside and higher difference comparing with others.

To describe the similiarity and difference quantitatively, we define the following property of clusters:

- Average distance between samples inside cluster $C$:
	$$
	\newcommand{\avg}{\text{avg}}
	\newcommand{\dist}{\text{dist}}
	\newcommand{\diam}{\text{diam}}
	\avg(C) = \frac{2}{|C|(|C|-1)}\sum_{1\le i \lt j \le |C|} \dist(x_i, x_j)
	$$

- The maximum distance between samples inside cluster $C$:
	$$
	\diam(C) = \max_{1\le i \lt j \le|C|} \dist(x_i, x_j)
	$$

- The distance of two nearest samples in cluster $C_{i}$ and $C_j$ respectively:
	$$
	d_{min}(C_i, C_j) = \min_{x_i\in C_i, x_j\in C_j} \dist(x_i, x_j)
	$$

- The distance of the central vector of two cluster
	$$
	d_{cen}(C_i, C_j) = \dist(\mu_i, \mu_j)
	$$
	where the centeral vector $\mu_i = \dfrac{1}{|C_i|}\displaystyle\sum_{x_k\in C_i}x_k$



Now two internal index based on the properties above are introduced:

- **Davies-Bouldin Index(DBI)**.
	Davies-Bouldin Index use the average distance between samples to describe the similarity inside cluster, and the distance of the central vector to describe the difference. Larger DBI indicates better clustering.
	$$
	\textrm{DBI} = \cfrac{1}{k}\sum_{i=1}^k \max_{j\neq i}\left( \cfrac{\avg(C_i)+\avg(C_j)}{d_{\textrm{cen}}(C_i, C_j)} \right)
	$$

- **Dunn Index(DI)**.
	Dunn Index use the maximum distance between samples inside cluster to describe th e similarity inside clutser, and the minimum distance between clusters to describe the difference.
	$$
	\min_{1\le i \le k}\left\{ \min_{j\neq i}\left( \frac{d_\min(C_i, C_j)}{\max_{1\le l\le k}\diam(C_l)} \right)  \right\}
	$$
	Unlike the sum form in DBI, DI only takes the minimum value from all the pairs, besides, since its "difference/similarity", Smaller DI indicates better clustering, which is in constrast to DBI.

The two internal index are both based on **distances** of samples. Thus, in some tasks where the classification are not based on distances(i.e. density-based clustering), the two index might be not appropriate.



##### # Defining Distance

Most clustering algorithm consider distance as the indicator of similarity, while there are different types of distance and we should choose carefully properly based on the background and requirement. The most famous distance is **Minkowski distance**:

$$
\newcommand{\distm}{\dist_{\text{wmk}}}
\distm(x_i, x_j) = \|x_i, x_j\|_p  =  \left( \sum_{u=1}^n|x_{iu} - x_{ju}|^p  \right)^{\frac{1}{p}}
$$

**Euclidean distance** and **Manhattan distance** are the special case at $p=2$ and $p=1$, denoted as $\|x_i, x_j\|_2$ and $\|x_i, x_j\|_1$ respectively.
And there's weighted version of Minkowski distance, applied if the some properties are considered more important than others to check the similarity:

$$
\distm(x_i, x_j) = \left( \sum_{u=1}^n w_i | x_{iu} - x_{ju}|^p  \right)^{\frac{1}{p}}
$$

You may refer ==TODO: math notes link== for more theoretical material about rich types of distance.

For some algorithms, the definition of distance is pre-defined and will not change during training, while there is also some algorithm that based on the data samples to learn the proper distance formula, which process is named **distance metric learning**.




### Prototype-based Clustering 

The prototype-based clustering uses one **prototype vectors** to represents a type, and the classification of one sample is determined by which prototype vector it is nearest.

Three prototype-based clustering methods are introduced:

- $k$-means algorithm
- Learning vector quantization
- Mixture-of-Gaussian.

We'll focus on $k$-means algorithm and learning vector quantization, and leave mixture-of-Gaussian after we bulit a strong basis of probability and statistics.



































