

# Greatest Common Divisor

$$
\newcommand\gcd{\textrm{gcd}}
\newcommand\lcm{\textrm{lcm}}
$$

##### # **Euclidean Algorithm**

Euclidean Algorithm shows the method of 

```python
def gcd(a, b):
  return a if b==0 else gcd(b, a%b)

def lcm(a, b):
  return a*b/gcd(a, b)
```

> Ex1. Prove $(n^2+n+4, n-1)|6$.
>
> Prov. Notices that $n+n+4 = (n-1)(n+2)+6$, as a result $(n^2+n+4, n-1) = (n-1, 6)$.



##### # Properties

- Any Common Divisor is the divisor of GCD; Any Common Multiple is the multiple of LCM.

- Arbitrariness of Combinition:
    $$
    \gcd(a_1,\ a_2,\ ...,\ a_{n-1}, \ a_n) = \gcd(\gcd(a_1,\ \ a_2,\ ...,a_{n-1}),  \ a_n)
    $$
    This can be applied in the recursion algorithm.

- Since anything can be considered as the factor of zero, $\gcd(0, \ a) = a$.

- Permission of Linear Conversion:
    $$
    \gcd(a_1,\ a_2,\ ...,\ a_n) = \gcd(a_1,\ \ a_2,\ ...,\ a_i,\ ..., \ 	a_j+a_i,\ ...,\ a_n)
    $$

    >  This is the direct result of Euclidean Algorithm.

    $$
    \gcd(ma_1,\ ma_2,\ ...,\ ma_n) = m\ \gcd(a_1,\ a_2,\ ...,\ a_n)
    $$

    

- **Bézout's Theorem**:
    $$
    \gcd(a_1, \ a_2,\ , ... ,\ a_n) = \sum k_ia_i, \quad k_i\in\Z
    $$
    Bézout's Lemma tells us the GCD of a series of number must can be expressed by the linear combination of numbers.

- FTA's Perspective:
    $$
    \gcd(a,\ b) = \sum p_i^{\min(e_i, f_i)},
    \qquad
    \lcm(a,\ b) = \sum p_i^{\max(e_i, f_i)}
    $$
    FTA's Perspective directly convert the abstract notation `gcd` into the algebra expression, so many attributes of GCD can be proved by consider it FTA's way.

- Relation between GCD and LCM:
    $$
    \gcd(a,\ b) \times \lcm(a, \ b) = a\times b
    $$

    > This can be proved with the help with the FTA's Perspective plus a simple fact:
    > $$
    > \min(a,\ b) + \max(a,\ b) =  a + b
    > $$
    > Noticed that this prove convert the second-progression operation into first-progression, by the nature of exponent.
    >
    > Plus, this is true only in the 2-number case.





