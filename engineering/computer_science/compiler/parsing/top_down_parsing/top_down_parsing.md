
$$
\newcommand{\FIRST}{\text{FIRST}}
\newcommand{\FOLLOW}{\text{FOLLOW}}
\newcommand{\ra}{\rightarrow}
\newcommand{\Ra}{\Rightarrow}
$$






For any non-terminal symbol $A$, we define
$$
\FOLLOW(A) = \{a \mid S\Rightarrow^* \ldots Aa\ldots, a\in V_T  \}
$$
Specifically, if 



1. There is no left-recursion in grammar.

2. For each non-terminal symbol $A$, the union of first symbol set of eac h production rule is empty, formally:
    $$
    A \ra \alpha_1 \mid \alpha_2 \mid \ldots \mid \alpha_n
    $$
    
3. 

    

The set $\FIRST(X)$ is constructed by following rules:

- If $X\in V_T$, $\FIRST(X) = \{X\}$.
- If $X\in V_N$, and $X\ra a\ldots$, then $a\in \FIRST(X)$, specically, if $X\ra \varepsilon$, $\varepsilon \in \FIRST(X)$.





The set $\FOLLOW(A)$ is constructed by following rules:

1. $\{\#\} \in \FOLLOW(S)$
2. If $A\ra \alpha B \beta$ is a production rule, then  $\FIRST(\beta)\backslash\{\varepsilon\} \in \FOLLOW(B)$ 
3. If $A\ra \alpha B$ is a production rule, or $A\ra \alpha B\beta$ is a production rule and $\beta \Ra^* \varepsilon$ (that is $\varepsilon \in \FIRST(\beta)$), then $\FOLLOW(A)\sub \FOLLOW(B)$.

Let's try to apply these rules to real grammar:

> Example. For grammar $G(E)$:
> $$
> \begin{align}
> & E\ra TE' \\
> & E'\ra +TE' \mid \varepsilon \\
> & T \ra FT' \\
> & T' \ra *FT' \mid \varepsilon \\
> & F \ra  (E) \mid i
> \end{align}
> $$



