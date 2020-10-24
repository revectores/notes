# Log Sum Inequality

$$
\sum _{{i=1}}^{n}a_{i}\log {\frac  {a_{i}}{b_{i}}}\geq a\log {\frac  {a}{b}},
$$

> **Proof**. Applying Jensen's inequality
> $$
> \begin{aligned}
> \sum_{i=1}^{n} a_{i} \log \frac{a_{i}}{b_{i}} &=\sum_{i=1}^{n} b_{i} f\left(\frac{a_{i}}{b_{i}}\right)=b \sum_{i=1}^{n} \frac{b_{i}}{b} f\left(\frac{a_{i}}{b_{i}}\right) \\
> & \geq b f\left(\sum_{i=1}^{n} \frac{b_{i}}{b} \frac{a_{i}}{b_{i}}\right)=b f\left(\frac{1}{b} \sum_{i=1}^{n} a_{i}\right)=b f\left(\frac{a}{b}\right) \\
> &=a \log \frac{a}{b}
> \end{aligned}
> $$

