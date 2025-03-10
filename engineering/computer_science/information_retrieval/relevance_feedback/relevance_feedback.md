# Relevance Feedback

$$
\newcommand{\sim}{\text{sim}}
\newcommand{\Dr}{D_{\text{r}}}
\newcommand{\Dnr}{D_{\text{nr}}}
$$

### 1. Introduction to Relevance Feedback

Steps of relevance feedback:

- User submits a query and get the first series of documents.
- User marks(explicitly or implicitly) some documents as relavent, others are irrelavent.
- Search engine compute a new query representation based on the user's marks, and process this new query to return a new sereis of documents. Ideally, the recall of this new result should be higher than the previous one.

Based on whether and how the user provides feedback information to search engine, there are three types of relevance feedback:

- **User feedback(explicit feedback)**. User explicitly select relevant documents and irrelevant documents.
- **Implicit feedback**. Search engine infers the preference of users by collecting users' behaviours: click links, add to favorite, copy, stay, switch pages, zoom in, zoom out, and so on. The eye tracking can be modelled by the movement of cursor.
- **Pseudo feedback(blind feedback)**. Pseudo-relevance do not depend on any actions from users: It assume the first $k$ documents are relavent.

The advantage and disadvantage of the three relevance feedback approaches:

|                    |                          Advantage                           |                         Disadvantage                         |
| :----------------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
| Relevance Feedback |                  Improve query performance                   | The query generated are long usually, which requires more computational resource. |
| Explicit Feedback  |     Explicit feedback shows the real interests of user.      | Users perfers modifying query rather than giving explicit feedback. |
| Implicit Feedback  | (1) Release users. <br/>(2) Behaviours reflect the interests of users to a certain extent. |   The feedback may not reflect real interests of the user.   |
|  Pseudo Feedback   | (1) Do not rely on users. <br/>(2) Good performace in average. | (1) It can lead to bad query result for specific cases. <br/>(2) Repeated pseudo-relevance feedback may lead to **query drift**. |

We can repeat relevance feedback multiple times to improve performance. On the contrary, the normal query which does not applies relevance feedback is named **ad hoc retrieval**.







### 2. Rocchio Algorithm

Rocchio algorithm is the implementation of relevance query under vector space document model.

The center of mass of documents can be defined as
$$
\vec\mu(D) = \frac{1}{|D|}\sum_{d\in D}\vec v(d)
$$
where $D$ is a **set of documents**, and $\vec v(d) = \vec d$ is the vector representation of document $d$.

Rocchio algorithm select that optimal query as


$$
\vec q_{\text{opt}} = \arg \max_{\vec q}(\sim(\vec q, \mu(D_\text{r})) - \sim(\vec q, \mu(D_{\text{nr}})))
$$
where $\Dr$ is relavent document set, and $\Dnr$ is the irrelavent document set. The interpretation of this formula is straightforward: Select the one query which distinguish similarity between relavent documents and irrelavent documents with the best performance.

==With some assumptions(?)== we have
$$
\vec q_{\text{opt}} = \mu(\Dr) + (\mu(\Dr) - \mu(\Dnr))
$$
The formula used in practice is
$$
\vec q_m = \alpha\vec q_0 + \beta\mu(\Dr) - \gamma\mu(\Dnr)
$$
where $\vec q_0$ is the primitive query, $\vec q_m$ is the updated query. $\alpha, \beta, \gamma$ are weights. The difference between theoretical formula practical formual is the introduction of primitive query $\vec q_0$ and weights $\alpha, \beta, \gamma$ so we make the relative importance of primitive query and the relevance feedback configurable.

How to configure weights: If there are amounts of documents $\Dr, \Dnr$, weights $\beta, \gamma$ should be set larger. Normally the value of positive feedback is larger than negative feedback, since there are more inrelavent documents than relavent ones. For instance, we can configure $\beta = 0.75, \gamma = 0.25$ to give larger weights to positive feedback. Some system set $\gamma = 0$, in which case only positive feedback is enabled.

Two assumptions must be satisified to gurantee that relavence feedback improves recall:

- **Assumption 1**. The dictionary of user query fits the dictionary of document set.
- **Assumption 2**. The words in relavent documents are similar, and the words between relavent documents and irrelavent documents are different.







### 3. Indicator of Relevance Query

To compare the performance before and after relevance feedback, we pick an indicator for query, for instance, $P@10$, then simply compute the same indicator for primitive query and modified query. However, this is not an fair comparsion since

- Some of the top query are selected explicitly by user. Hence the indicator must based on the **residual collection**: those documents without users' marks.
- More computational resource and user attention are used during relevance feedback operations. We must compare this method with those methods that use similar computational resource. For instance, an alternative is to let users modify the query by themselves.

Relevance query is seldom used by search engine in practice. Modification of query is perferred.
