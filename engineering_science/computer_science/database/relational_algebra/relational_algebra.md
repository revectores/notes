# Relational Algebra

### 1. Basic Relational Operator

##### # Basic Relational Operator: Introduction

Six basic relational algebra operator: select $\sigma$, projection $\Pi$, union $\cup$, difference $-$, Cartesian product $\times$, rename $\rho$.



##### # Basic Relational Operator: Select Operation

Formally, $\sigma_p(r) = \{ t \mid t\in r \land p(t) \}$. where $p$ are **predicates**. For instance,
$$
\sigma_{dept\_name = "Physics" \land salary > 90000}(instructor)
$$
comparison between attributes is allowed, for example, to find those department whose name is exactly the building name, we use
$$
\sigma_{dept\_name = building}(department)
$$



##### # Basic Relational Operator: Project Operation

Formally, $\Pi_{i_1, i_2, \ldots, i_m} = \{t \mid \left< t_{i_1}, t_{i_2}, \ldots, t_{i_m} \right> \and \left< t_1, \ldots, t_{i_1}, t_{i_2}, \ldots, t_{i_m}, \ldots, t_n \right> \in R \}$. For instance,
$$
\Pi_{ID,name,salary}(instructor)
$$

operations is allowed for the projection operation, to list the month salary instead of year:
$$
\Pi_{ID, name, salary/12}(instructor)
$$



##### # Basic Relational Operator: Union Operation

Formally, $r\cup s = \{ t \mid t\in r \or t \in s \}$. To make the union operation meaningful, the The number of attributes and their domains must be the same.



##### # Basic Relational Operator: Cartesian-Product Operation

Formally, $r\times s = \{ \left< t, q \right> \mid t\in r \and q\in s \}$. For instance,
$$
\sigma_{instructor.ID = teachers.ID}(instructor \times teachers)
$$

Since the same attribute names must occur in `r` and `s`, rename operation may be introduced.



##### # Basic Relational Operator: Rename Operation

Formally, $\rho_p(r) = \{ t \mid t\in r \land p(t) \}$.



##### # Formal Definition of Relational Algebra Expression

The basic expression is one of the following:

- A relation in database.
- As costant relation expressed by `{}` with tuples listed.

If $E_1$ and $E_2$ are relational algebra expression, then

- $E_1 \cup E_2$
- $E_1 - E_2$
- $E_1\times E_2$
- $\sigma_p(E_1)$, where $p$ is the predicate upon attributes of $E_1$.
- $\Pi_s(E_1)$, where $s$ is some attributes of $E_1$.
- $\rho_x(E_1)$, where $x$ is the new name of result of $E_1$.

are all relational algebra expressions.



##### # Examples

Find the highest salary in instructor:
$$
\Pi_{salary}(instructor)- \Pi_{instructor.salary}(\sigma_{instructor.salary < d.salary}(instructor\times \rho_d(instructor)))
$$








### 2. Extended Relational Operator

The extended relational operator cannot improve the expressive ability of relational algebra, but it can simplify some common queries. The extended relational operator includes intersection $\cap$, natural inner join $\bowtie$, assignment $\leftarrow$, division $\div$, and outer join.



##### # Extended Relational Operator: Intersection Operation

Formally, $r\cap s = \{ t \mid t\in r \land t\in s \}$. The intersection can be expressed by difference:
$$
r \cap s = r - (r - s) = s - (s - r)
$$


##### # Extended Relational Operator: Natural Join Operation

Formally,
$$
r\bowtie s = \Pi_{r.A, r.B, r.C, r.D, s.E}(\sigma_{r.B=s.B \land r.D = s.D}(r\times s))
$$
Natural join is associative and commutative.

The natural join automaically detect fields with the same names, **theta join** is provided to select the column manually:
$$
r\bowtie_\theta s = \sigma_\theta(r\times s)
$$


##### # Extended Relational Operator: Assignment











