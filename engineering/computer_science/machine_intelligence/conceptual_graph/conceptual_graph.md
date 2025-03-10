# Conceptual Graph

##### # The Importance of Concept

1. Concept is the basis of "understanding".
2. Concept can be used to recognize a class of objects.
3. Concept is the basis of 联想?.
4. Concept is the basis of conclusion and deduction.



##### # Concept Graph

Concept graph is the graph which model the "isA" relation between concept and entity, and the "subclassOf" relation between concepts (sometimes we do not distinguish "subclassOf" from "isA"). For instance, apple isA fruit.

From congnitive perspective,

From language's perspective, 



##### # Common Concept Graph

**WordNet**. A English lexical database

**WikiTaxonomy**.

**Probase**. The frequency of concept in database is included in Probase.
$$
P(c\mid e) = \#(e~\text{isA}~ )
$$
**CN-Probase**.



The two main applications of concept graph are:

- **Instantialization**. List typical entities for given concept.
- **Conceptualization**. Infer the belonging concept of given concepts.

We are able to use instantialization and conceptualization respectively or both to create more applications.

- Data enhancement: Replace entity in sentence with different entities in the same concept. For instance, ""
- Subject deduction: Extract concept of entity and then deduct subject from concepts. 
- Language concept template: Generate pattern by extracting concept of entity in corpus, 
- Text Classification, document tagging, user portrait.
- Concept-based interpretation. The hyponym entity inherit properties from hypernym.
- Concept conclusion.
- Semantic representation.
- **Entity recommandation**: combine instantialization and conceptualization.



Extract isA relation manually vs automatically:

Construct the concept graph manually cost.



Automatical methods:

- Pattern-based method. High coverage. 
- Wikipedia-based method. High precision.
- Embedding-based method. 

Concept graphs:

- YAGO: Wikipedia-based method, using WordNet as the basic taxinomy.
- Hearst Patterns: Extract isA relation from fixed sentence pattern. The first three pattern is constructed automatically by specialists.

How to construct Chinese concept graph:

- Pattern based: The accuracy of Chinese pattern is lower then English pattern.
- Translate from English graph:
    - Ambiguity
    - Different languages tend to express different knowledges

Chinese concept graphs:

- 大词林: Chinese concept graph based on extraction and sorting:
- **CN-Probase**. Hearst patterns have bad performance in Chinese. "NP such as {NP, }" in English: 92% accuracy; Chinese: 75% accuracy. In CN-Probase we combine pattern-based method and wikipedia-based method.
- 





Cause of loss of isA relation:

- Loss of common sense.
- Some object only occur several times.

How to complete:

- Transitivity-based. Problem: trasitivity is not always held. Determine whether the transitivity holds can be modelled as a machine learning problem.
- Recommanding system-based. For instance, apply **collaborative filtering**.
- 





