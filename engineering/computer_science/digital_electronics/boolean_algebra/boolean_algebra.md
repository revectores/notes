$$
\newcommand{\o}{\overline}
\newcommand{\oA}{\o A}
\newcommand{\oB}{\o B}
\newcommand{\oC}{\o C}
\newcommand{\dual}{\quad\stackrel{\mathrm{duality}}{\longleftrightarrow}\quad}
$$

# Boolean Algebra

### 1. Boolean Function

##### # Definition and Representation

Input/Output are all boolean type(0/1).

There're five representation methods of Boolean Function:

- Truth Table
- Boolean Function Formula
- Logic Graph - Notice the differences between Chinese Standard and International Standard.
- **Karnaugh Map**
- Hardware Description Language (HDL)

**Reverse Function**: All the output values are the oppsite of the primitive function.



##### # Form Transformation

Using De morgan's Law or Duality Principle.

e.g. Transform the `AND-OR` expression into `OR-AND` form.
$$
\begin{align*}
& Y  \ \ \ = AB+CD \\
& Y^* \  = (A+B)(C+D) = AC+BC+AD+BC \\
& Y^{**} = (A+C)(B+C)(A+D)(B+C)
\end{align*}
$$



##### # Minimal/Maximum Term

**Minimal Term**: Each boolean variable (or its oppsite) occurs and only once in this term. e.g. The standard form of three-men votes problem: $f(ABC) = \o ABC + A\o BC + AB\o C + ABC$.

The subscript of the minimal term is the value of boolean variables when this term get value `1`. e.g. $m_3 = \o ABC, \quad m_5 = A\o BC, \quad m_6 = AB\o C, \quad m_7 = ABC$.

Using subscript of minimal term, we can compress the expression into
$$
f(ABC) = \sum m(3,5,6,7)
$$
Properties of Minimal Term:

- **There's one and only one minimal term's value is 1.**
- $m_im_j = 0, \quad i\neq j$.
- $\sum_{i=0}^{2^n-1}m_i =1$ 

The last two properties are based on the fist property.

We can also introduce **Maximum Term** correspondently. e.g.
$$
f^*(ABC) = (A+B+C)(A+B+\o C)(A+\o B+C)(\o A+B+C) = \displaystyle\prod M(0,1,2,4)
$$
Relation between minimal/maximum term: $m_iM_i = 0$.



##### # Standard Representation

Sum of Product (SOP) Form:
$$
f(x_1, \ x_2, \ x_3, \ ..., \ x_n) = 
\sum_{i=0}^{2^n-1}\alpha_{i}m_i, \quad \alpha \in \{0,1\}.
$$
Product of Sum (POS) Form:
$$
f(x_1, \ x_2, \ x_3, \ ..., \ x_n) = 
\prod_{i=0}^{2^n-1}(\alpha_{i}+m_i), \quad \alpha \in \{0,1\}.
$$
Relation between boolean function and its reverse function:
$$
F = \sum m_i \quad \rightarrow \quad \o F = \prod M_i
$$
Relation between two standard form:
$$
F = \sum m_i \quad \rightarrow \quad F = \prod M_j, \qquad\qquad j\neq i
$$

> The Prove of these two relations relay on the sum property of minimal term.



##### # Representation Standardization

Multiple the non-minimal-term by something like $A+\o A$. e.g.
$$
F(ABC)
= A+\oB C + A\oC
= A(B+\oB)(C + \oC) + \oB C(A+ \oA) + A\oC(B+\oB)
= \ ...
$$
Add the non-maximum-term by something like $A\o A$.







### 2. Boolean Operations and Properties

#####  # Complex Opeartor

$\o{AB}, \o{A+B}, A\bigoplus B, A\bigotimes B$

==TODO: Complete the definition of complex operator, serach wiki and add for more complex operator.== 



##### # Distribution Law

$$
A(B+C) = AB+AC \quad \leftrightarrow \quad A+BC = (A+B)(A+C)
$$



##### # De morgan's Law

 $\o{AB} = \o A + \o B$, $\o{A+B} = \o A \o B$. This is quite useful cause it can replace `and/or` by another kinds of operation. Generalization of De morgan's law (**Inversion Law**): Change the function expression into its dual, and then get **the inverse of the variables**, you can get the reverse function.



##### # Duality Principle

**Dual expression**: Change logic operator and constant into its dual. e.g. $Y = A\o B + \o CD + 0 \dual \o Y = (\o A + B)(C + \o D)\cdot1$

If two function equal, the dual of their expressions are still equal. Prov: $F = G \rightarrow \o F = \o G \rightarrow F^* = G^*$. The Second Arrow is done by 

Ex. $(A+D)\o C = A\o C + \o CD + 0 \rightarrow AD+\o C = (A+\o C)(\o C + D) \cdot 1$



Based on the properties of boolean operations, we could use `NAND` or `NOR` to construct all types of boolean function.







### 3. Karnaugh Map

##### # Generation

Notification:

- Enclose 1 to generate SOP representation, and enclose 0 to generate POS representation.
- Enclose $2^n$ grids exactly as large as possible, and don't miss any grid.



##### # Karnaugh Map Calculation

$$
f_1 = \sum\alpha_{1i}m_i, \quad f_2 = \sum\alpha_{2i}m_i \\~\\
\begin{equation}
\begin{split}
f_1 \cdot f_2
& = \sum\alpha_{1i}m_i \cdot \sum\alpha_{2i}m_i \\
& = \sum_i\alpha_{1i}\alpha_{2_i}m_i + \sum_{i\neq j}\alpha_{1i}\alpha_{2_j}m_i \\
& = \sum_i\alpha_{1i}\alpha_{2_i}m_i \\
\end{split}
\end{equation}
$$

##### # Simplify by the XOR Function

The map of XOR function views like the "chessboard". the 0 position of `XOR` function is 0, and the 



##### # Process of Arbitrary Item

The arbitrary item is those input combination that won't occur or meaningless. Can be enclosed whether or not arbitraray (recommend to make the expression simple).



##### # Multi-output Logic Function

Find the common-cover first to make least item occurance among all the results.



##### # Vast-Variable(>4) Map

We can expressed by multiple 4-variables karnaugh map, e.x. 6-variables need $2^{6-4} = 4$ counts of 4-variables map. The core idea of this approach is to expand $n$ dimension space into the plane.



##### # Mapped-Variable



==TODO: contain, prime contain, necessary contain, cover, non-reduncany cover, minimal cover?==

==TODO: Find out a way to auto-generate Karnaugh Map==

==TODO:Write a function to auto convert boolean function into the standard representation, and draw the karnaugh map.==

