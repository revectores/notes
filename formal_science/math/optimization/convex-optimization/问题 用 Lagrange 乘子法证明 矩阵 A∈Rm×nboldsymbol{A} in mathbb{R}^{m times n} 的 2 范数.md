问题: 用 Lagrange 乘子法证明: 矩阵 $\boldsymbol{A} \in \mathbb{R}^{m \times n}$ 的 2 范数
$$
\|A\|_2=\max _{\|x\|_2=1, x \in \mathbb{R}^n}\|A \boldsymbol{x}\|_2
$$

的平方是 $\boldsymbol{A}^T \boldsymbol{A}$ 的最大特征值



ChatGPT的回答

(2) 矩阵 $A$ 的算子 2 范数(又称谱范数) 定义为
$$
\|A\|_{2}=\max _{x \neq 0} \dfrac{\|A x\|_{2}}{\|x\|_{2}}=\max _{\|x\|_{2}=1}\|A x\|_{2}
$$

要证明 $\|A\|_{2}^{2}=\lambda_{\text {max }}\left(A^{T} A\right)$, 我们可以先把它转化为一个最大化问题:
$$
\|A\|_{2}^{2}=\max _{\|x\|_{2}=1}\|A x\|_{2}^{2}=\max _{\|x\|_{2}=1}(A x)^{\top}(A x)=\max _{\|x\|_{2}=1} x^{\top}\left(A^{\top} A\right) x
$$

因此, 需要我们解决:
$$
\max _{x \in \mathbb{R}^{n}} x^{\top}\left(A^{\top} A\right) x \quad \text { subject to } \quad\|x\|_{2}^{2}=x^{\top} x=1
$$

这是一个 带球面约束 的二次型最大化问题, 可以用拉格朗日乘子法来证明它的最优值即为矩阵 $A^{\top} A$的最大特征值. 下面是简要推导: 

1. 构造拉格朗日函数

$$
L(x, \lambda)=x^{\top}\left(A^{\top} A\right) x-\lambda\left(x^{\top} x-1\right)
$$

2. 站立性(对 $x$ 求导为 0 )

$$
\dfrac{\partial L}{\partial x}=\dfrac{\partial}{\partial x}\left[x^{\top}\left(A^{\top} A\right) x\right]-\lambda \dfrac{\partial}{\partial x}\left(x^{\top} x\right)=2\left(A^{\top} A\right) x-2 \lambda x=0 .
$$

这里用到对称性:  $\dfrac{\partial}{\partial x}\left(x^{\top} B x\right)=2 B x$ (若 $B$ 对称; 对于 $A^{\top} A$ 显然对称).
由此可得
$$
\left(A^{\top} A\right) x=\lambda x
$$

说明最优点 $x$ 必须是 $A^{\top} A$ 的某个特征向量, $\lambda$ 则是相应的特征值.

3. 约束 $x^{\top} x=1$

==表明我们只在单位球面上选取 $x$, 因此能取得的最大值即为 $A^{\top} A$ 最大特征值 $\lambda_{\max }$ .==

4. 结论

$$
\max _{\|x\|_{2}=1} x^{\top}\left(A^{\top} A\right) x=\lambda_{\max }\left(A^{\top} A\right)
$$

相应地, 
$$
\|A\|_{2}^{2}=\lambda_{\max }\left(A^{\top} A\right) \Longrightarrow\|A\|_{2}=\sqrt{\lambda_{\max }\left(A^{\top} A\right)} .
$$

从而完成了对矩阵 $A$ 的 2 范数与 $A^{T} A$ 最大特征值之间关系的证明. 



这里引出了一个新问题: 为什么最大特征值$\lambda$可以取得$\lambda_\max$? 