# Adversarial Attack

$$
\newcommand{\sign}{\text{sign}}
\newcommand{\Clip}{\text{Clip}}
\newcommand{\E}{\mathbb{E}}
\newcommand{\b}{\boldsymbol}
\newcommand{\t}{\tilde}
\newcommand{\bx}{\b{x}}
\newcommand{\bX}{\b{X}}
\newcommand{\by}{\b{y}}
\newcommand{\bb}{\b{b}}
\newcommand{\adv}{\text{adv}}
\newcommand{\true}{\text{true}}
\newcommand{\false}{\text{false}}
\newcommand{\target}{\text{target}}
\newcommand{\pdata}{p_{\text{data}}}
\newcommand{\norm}[1]{\left\lVert#1\right\rVert}
\newcommand{\infnorm}[1]{\norm{#1}_{\infty}}
$$

##### # Adversarial Attack on Linear Models

To attack the model, that is, make it give a different preditiction (without be noticed by humans), we aim to maximize the variation of $y$ under small perturbation.

For linear system, the small perturbation $\infnorm{\b\eta} \le \epsilon$ leads to the maximum variation of $\by = \b\omega^T\bx$ when $\b\eta = \epsilon~\sign(\b\omega)$ since
$$
\b\omega^T \t\bx = \b\omega^T\bx + \b\omega^T\b\eta
$$
For instance, for $\b\omega = [2, 3, -2]$ and constraint $\epsilon \le 1$, that small perturbation shall be set to $\b\eta = \sign(\b\omega) = [1, 1, -1]$.



##### # Adversarial Attack on Non-Linear Models

For non-linear models, we simply linearize it by Taylor expansion so method to attack linear models can be applied.

Formally, let $\theta$ be the parameters of a model, $\bx$ is the input, $\by$ the target associated with $\bx$ and $J(\b\theta, \bx, y)$ be the cost used used to train the neural network. We can linearize the cost function around the current value of $\b\theta$, obtaining an optimal max-norm constrained pertubation of
$$
\b\eta = \epsilon ~\sign(\nabla_\bx J(\b\theta, \bx, y))
$$
make Taylor expansion at the current $x$,
$$
\begin{align}
J(\b\theta, \bx', y)
&\approx \nabla_\bx(J(\b\theta, \bx, y))(x' - x) + J(\b\theta, \bx, y) \\
&\approx \nabla_\bx(J(\b\theta, \bx, y))x'
\end{align}
$$
For image data, denote $\bX$ the clean image, $\bX^\adv$ the adversarial image, the cost function used to train the model is denoted $J(\bX, y_{\true})$, then we construct the $\bX^\adv$ by
$$
\bX^\adv = \bX + \epsilon~\sign(\nabla_\bX J(\bX, y_\true))
$$
This is what we called **Fast Gradient Sign Method(FSGM)**. An alternative approach is to maximize probability $p(y_\target \mid \bX)$ for some specific target class $y_\target$ which is unlikely to be the true class for a given image. For a neural network with cross-entropy loss this will lead to the following formula for the one-step target class method:
$$
\bX^\adv = \bX - \epsilon~\sign(\nabla_X J(\bX, y_\target))
$$
**One-step least likely class(step l.l.)** is the targeted FSGM when we use the least likely class predicted by the network $y_{LL} = \arg\min\{p(y\mid\bX)\}$. Otherwise if we choose the class randomly the method is named "**step rnd.**"

This method is simple and computationally efficient, but usually has a lower success rate. On ImageNet, top-1 error rate on candidate adversarial images for the FGSM is about 63%-69% for $e\in[2, 32]$.



##### # Basic Iterative Method

**Basic iterative method(BIM)** simply iterates FGSM. Formally,
$$
X_{0}^{adv} = X,
\quad
X_{N+1}^\adv
= \text{Clip}_{X, \epsilon}\{X_{N}^{\adv}
+ \alpha ~ \sign(\nabla_X J(X_N^\adv, y_\true))\}
$$
where the clip function is used to gurantee $\norm{\bX' - \bX} \le \epsilon$.
$$
\Clip\{X'\}(x, y, z)
= \min\{
	255,
	X(x, y, z) + \epsilon,
	\max\{0, \bX(x, y, z) - \epsilon, \bX'(x, y, z)\}
\}
$$

where $\bX(x, y, z)$ is the value of channel $z$ of the image $\bX$ at coordinates $(x, y)$.

This performs per-pixel clipping of the image $\bX'$, so the result will be in $L_{\infty}$ $\epsilon$-neighbourhood of the source image $\bX$.

Correspondingly, we have targeted basic iterative method:
$$
X_{0}^{adv} = X,
\quad
X_{N+1}^\adv
= \text{Clip}_{X, \epsilon}\{\bX_{N}^{\adv}
+ \alpha ~ \sign(\nabla_X J(\bX_N^\adv, y_{LL}))\}
$$


### 2. Defense of Adversarial Attack

There are two widely used approaches to defend from adversarial attack: minimize adversarial loss and adversarial training.



##### # Minimize Adversarial Loss

Minimize the max(attack):
$$
\min_{\theta}\rho(\theta),
\quad \text{where} ~
\rho(\theta) = \mathbb{E}_{(x, y) \sim \mathcal D}
\left[ \max_{\delta\in \mathcal S} L(\theta, x + \delta, y) \right]
$$

> **Case study**. For instance, if we train a single model to recognize labels $y = \{-1, 1\}$ with $P(y = 1) = \sigma(\b\omega^T\bx + \bb)$ where $\sigma(z)$ is the logistic sigmoid function, then training consists of gradient descent on
> $$
> \E_{\bx, y \sim \pdata}\zeta(-y(\b\omega^T\bx + \bb))
> $$
> where $\zeta(z) = \log(1 + \exp(z))$ is the softplus function. We can derive a simple analytical form for training on the worst-case adversarial perturbation of $\bx$ rather than $\bx$ itself, based on gradient sign perturbation. Note that the sign of the gradient is just $-\sign(\b\omega)$, and that $\b\omega^T\sign(\b\omega) = \norm{\b\omega}$. The adversarial version of logistic regression is therefore to minimize
>
>
> $$
> \E_{\bx, y \sim \pdata}\zeta(-y(\b\omega^T\bx + \bb - \epsilon\norm{\b\omega}_1 ))
> $$
>



##### # Adversarial Training


To make protect our model from adversarial attack, another simple idea is to feed them with adversarial data, this is what we called **adversarial training**. For instance, the adversarial training with one-step attack:
$$
\tilde J(\b\theta, \bx, y)
= \alpha J(\b\theta, \bx, y)
+ (1-\alpha) J(\b\theta, \bx + \epsilon~\sign(\nabla_\bx J(\b\theta, \bx, y)), y)
$$
where the first and second term (of RHS) are the primitive training data and constructed adversarial training data respectively.

The fundamental flaw of adversarial training is that it can only prevent model from the attack in pre-trained form.

