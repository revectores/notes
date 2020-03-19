$$
\newcommand{\dom}{\text{dom}}
\newcommand{\ran}{\text{ran}}
$$

# Relation

### Basic Concept

##### # Basic Concepts About Relation

Assume that $X, Y$ are two sets, the subset $R$ of $X\times Y$ is defined as the **binary relation** or **relation** from $X$ to $Y$. If tuple $(x, y)\in R$, we say $x, y$ satisfies relation $R$, denoted as $xRy$, and we named $x$ as the **antecedent**, and $y$ as **seccedent**.

The **Domain** and **Range** of relation are denoted as $\dom(R)$ and $\ran(R)$, which are defined as
$$
\dom(R) = \{x\ |\ (x,y)\in R\} \\
\ran(R) = \{y\ |\ (x,y)\in R\}
$$


##### # Classification

If $X=Y$, the sebset is called the relation **on** $X$, this binary relation is called a **homogeneous relation**. The $X\neq Y$ case is called heterogeneous relatively.

There're several special relations:

1. There're two trivial subsets of $X\times Y$, empty set $\varnothing$ and $X\times Y$ itself, which two are called **Empty Relation** and **Total Relation**.

2. Identity Relaiton $I$ above $X$: $I_x = \{(x,x)\ | \ x\in X\}$.

3. The relation which got **one any only one** seccedent for any antecedent is called **[Function](Function)**. 



##### # Representation of Relation

Since the relation is no more than a set, so any methods to represent a set can be used to represent a binary relation. Besides, there're **Relation Map** and **Relation Matrix** to help us represent binary relation.



### Calculation of Relation

##### # Basic Calculation

Again, since relation is no more than a set, any calculations between sets work on relation as well, notes that the universal set of complementary calculation is $X\times Y$. Besides, there're two more calculation for relations: **Reverse** and **Compose**.

Reverse of relation change the position of antecedent and seccedent:
$$
R^{-1} = \{(y, x) \ | \ (x,y)\in R \}
$$
Composition of relation compose two relation into one:
$$
R\circ S = \{(x,z)\ |  \ (x,y)\in R,\ (y,z)\in S \}
$$
It's trival that the composition with identity relation don't change the original relation, this can be proved by the conditions of set equivlance (notice the symbol and domain):

> $R: X\rightarrow Y$, Prove that $I_X\circ R = R\circ I_Y = R$.
>
> 



##### # Properties of Relation Calculation



### Special Properties of Relation

##### # Special Relation

##### # Closure





### Equivlance Relation

##### # Basic concepts and Properties

##### # Division





### Function

##### # Basic Concepts

As mentioned before, function is a relation which got **one any only one** seccedent for any antecedent.

##### # Composition and Reverse of Function

The reverse of function is a relation but not may not be a function, unless it's a **bijective**.

The compostion of function is still a function, and the composition keeps the correspondent property of function, which means if two functions $F,G$ are (sur/in/bi)jective, the composition of them $F\circ G$ is also (sur/in/bi)jective.



This is another test about this helper who is not the succdent.