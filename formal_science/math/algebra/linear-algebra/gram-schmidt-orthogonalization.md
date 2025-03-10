# Gram-Schmidt Orthogonalization

可以通过以下方法求得 $\mathbb{V}$ 的一个规范正交基 $\boldsymbol{e}_{1}, \cdots$ ,  $\boldsymbol{e}_{r}$ . 这种方法称为 Gram-Schmidt 正交化.

取
$$
\begin{aligned}
\boldsymbol{b}_{1}= & \boldsymbol{a}_{1} \\
\boldsymbol{b}_{2}= & \boldsymbol{a}_{2}-\dfrac{\left\langle\boldsymbol{b}_{1}, \boldsymbol{a}_{2}\right\rangle}{\left\langle\boldsymbol{b}_{1}, \boldsymbol{b}_{1}\right\rangle} \boldsymbol{b}_{1} \\
& \vdots \\
\boldsymbol{b}_{r}= & \boldsymbol{a}_{r}-\dfrac{\left\langle\boldsymbol{b}_{1}, \boldsymbol{a}_{r}\right\rangle}{\left\langle\boldsymbol{b}_{1}, \boldsymbol{b}_{1}\right\rangle} \boldsymbol{b}_{1}-\dfrac{\left\langle\boldsymbol{b}_{2}, \boldsymbol{a}_{r}\right\rangle}{\left\langle\boldsymbol{b}_{2}, \boldsymbol{b}_{2}\right\rangle} \boldsymbol{b}_{2}-\cdots-\dfrac{\left\langle\boldsymbol{b}_{r-1}, \boldsymbol{a}_{r}\right\rangle}{\left\langle\boldsymbol{b}_{r-1}, \boldsymbol{b}_{r-1}\right\rangle} \boldsymbol{b}_{r-1}
\end{aligned}
$$

然后把它们单位化, 取
$$
\boldsymbol{e}_{1}=\dfrac{1}{\left\|\boldsymbol{b}_{1}\right\|} \boldsymbol{b}_{1}, \boldsymbol{e}_{2}=\dfrac{1}{\left\|\boldsymbol{b}_{2}\right\|} \boldsymbol{b}_{2}, \cdots, \boldsymbol{e}_{r}=\dfrac{1)}{\left\|\boldsymbol{b}_{r}\right\|} \boldsymbol{b}_{r}
$$

就是 $\mathbb{V}$ 的一个规范正交基.

> 例. 求向量组 $\boldsymbol{a}_{1}=(3,1,1), \boldsymbol{a}_{2}=(2,2,0)$ 的生成子空间的标准正交基.
>
> 取
> $$
> \begin{array}{l}
> \boldsymbol{b}_{1}=(3,1,1) \\
> \boldsymbol{b}_{2}=\boldsymbol{a}_{2}-\dfrac{\boldsymbol{b}_{1}^{\mathrm{T}} \boldsymbol{a}_{2}}{\boldsymbol{b}_{1}^{\mathrm{T}} \boldsymbol{b}_{1}} \boldsymbol{b}_{1}=(2,2,0)-\dfrac{8}{11}(3,1,1)=\dfrac{-2}{11}(1,-7,4) \\
> \boldsymbol{e}_{1}=\dfrac{1}{\sqrt{11}}(3,1,1) \\
> \boldsymbol{e}_{2}=\dfrac{1}{\sqrt{66}}(1,-7,4)
> \end{array}
> $$
>
> 故标准正交基为 $\boldsymbol{e}_{1}, \boldsymbol{e}_{2}$ . 