# Signal

### 1. Basic Concepts 

##### # Representation

Signal can be represented as the one or multi variables function. In most of the cases, the variable is time for the actual physical systems, while the variable can also be other physical quantity, i.e. in the image analysis, if we regard the image as a signal, the $(x,y)$ coordinates of the point is the variable, and the RGB value or grey scale is the response.



##### # Classification

There're two kinds of signals which will be discussed parallely: continous-time signal and discrete-time signal(series), which can be represented as the continous function $x(t)$ or a series $x[n]$ respectively, where $t\in\R$ while $n\in\Z$

A discrete-time signal can represent those phenomenons that is discrete themselves, or **sampling** from the continous signal. In the general case the original contious signal cannot be recovered from its sample, since some information must lost in sampling operation, while the **sampling theorem** will show us that this is possible under a specific condition.



##### # Transformation

Since the signal is represented by function, the transformation of signal is exactly as the transformation of function. Three basic transformations included.

1. The **time shift** $x(t+t_0)$ is the translation over $x$-axis, which represents a time **delay** or a time **advance** based on the direction of translation, i.e. the sign of $t_0$ in $x(t+t_0)$.

2. The **time reversal** $x(-t)$ is the symmetry transformation of $t=0$.

3. The **time scaling** $x(kt)$ is the scaling transformation.

Combining the transformations above these three method, we're able to construct any **linear transformation** $x(\alpha t + \beta)$ for a singal. When the transformation formula is given, the workflow to generate the transformed graph is to first do the delay/advance and then the reversal/scaling.



##### # Property 

Some important properties of function is also introduced for singal:

1. The **periodic signal**. The smallest period $T_0$ is called the **fundamental period**. If a signal is not periodic, it's **aperiodic**.

2. The **odd signal** and **even signal**. One important fact is that: any signal can be broken into the sum of an odd signal and an even signal:

$$
x(t) = \mathcal{Ev}\{x(t)\} + \mathcal{Od}\{x(t)\}
$$

where

$$
\mathcal{Ev}\{x(t)\} = \frac{1}{2}[x(t) + x(-t)] ~~~~~~~~~~~~~~~~ \mathcal{Od}\{x(t)\} = \frac{1}{2}[x(t) - x(-t)].
$$

The $\mathcal{Ev}\{x(t)\}$ and $\mathcal{Od}\{x(t)\}$ is named the **even part** and the **odd part** respectively.



### 2. Energy

##### # Energy Over Finite Section

We define the **energy** of signal for continous and discrete signal as:

$$
E = \int_{t_1}^{t_2} |x(t)|^2 \text{d}t ~~~~~~~~~~~~~~~~
E = \sum_{n_1}^{n_2} |x(n)|^2
$$

The energy in the unit time, i.e. the **average power** of them are

$$
P = \cfrac{1}{{t_2}-{t_1}} \int_{t_1}^{t_2} |x(t)|^2 \text{d}t ~~~~~~~~~~~~~~~~
P = \cfrac{1}{{n_2-n_1+1}} \sum_{n = n_1}^{n_2} |x(n)|^2
$$

Notice that there are $n_2-n_1+1$ numbers in $[n_1, n_2]$ instead of $n_2-n_1$.



##### # Energy Over Infinite Section

In the infinity section, the **total energy** of them are

$$
E_{\infin} = \int_{-\infin}^{+\infin}|x(t)|^2 \text{d}t = \lim_{T \rightarrow \infin} \int_{-T}^{T} |x(t)|^2 \text{d}t \\~\\
E_{\infin} = \sum_{-\infin}^{+\infin}|x[n]|^2 = \lim_{N\rightarrow \infin} \sum_{-N}^{+N} |x(n)|^2
$$

and the average power in the infinite section are

$$
P_{\infin} = \lim_{T \rightarrow \infin} \cfrac{1}{2T} \int_{-T}^{T} |x(t)|^2 \text{d}t \\~\\
P_{\infin} = \lim_{N\rightarrow \infin} \cfrac{1}{2N+1} \sum_{n=-N}^{+N} |x(n)|^2
$$

We use the the total energy $E_{\infin}$ and average power $P_{\infin}$ over the infinity section to classify the singals:

1. Finite total energy, and in this case the average power must be zero.

2. Finite average power, and in this case the total energy must be infinite.

3. Infinite average power, of course, also the infinite total energy.

Several examples about the calculation of energy and average power can be referred in 



### 3. Exponent Signal

##### # Continous Time Complex Exponent

The continous-time **complex exponential signal** is the form

$$
x(t) = Ce^{at}
$$

where $C$ and $a$ is complex number, hence the different value of $a$ will affect the property of signal to a great extent.

1. If $a$ is a real number, then the signal will be exponential increase or decrease.

2. If $a$ is pure imaginary number, say $x(t) = e^{j\omega_0t} = \cos{\omega_{0}t} + i\sin{\omega_{0}t}$, where $\omega_{0}$ is the real number, which makes $\omega_{0}j$ pure imaginary number.

	One important property of this signal is that the fundamental period of this signal is

	$$
	T_0 = \cfrac{2\pi}{|\omega_0|}
	$$

	where the real number $\omega_{0}$ is called the **fundamental frequency**.

	> Proof. Notice that $e^{j \omega_0 (t+T_0)} = e^{j \omega_0 t}e^{j \omega_0 T_0} = e^{j \omega_0 t} e^{j 2\pi} = e^{j \omega_0 t}$ for any $t$, hence $T_{0}$ is the period.
	>
	> Since $T_{0}$ is the smallest number which makes $e^{j \omega_{0} T} = 1$, it's the fundamental period.

	If mutliple signals share the same period, we say they are **harmonically realted**. Obviously the fundamental frequency of harmonically related signals must all be the multiple of some frequency $\omega_{0}$.
	
	Notice since it is a **complex function**, the period is actually in the complex plane, but in this case, if we take a look at the real part or the imaginary part, they're both the period function with the same fundamental period $T_0$ and fundamental frequency $\omega_{0}$.

3. The general complex exponential signal, where $C$ and $a$ are both complex number with both real and imaginary parts, notes $C = |C|e^{j\theta}, a = r + j\omega_{0}$, from which we can expand the expression into

	$$
	Ce^{at} = |C|e^{j\theta}e^{(r+j\omega_{0})t} = |C|e^{rt}e^{j (\omega_{0}t + \theta)} = |C|e^{rt} (\cos{(\omega_{0}t+\theta)} + \sin{(\omega_{0}t+\theta))}
	$$

	which can be considered as the combination of (1)real exponential and (2)pure imaginary exponential, and with an extra bias $\theta$. Since it's complex function, to draw the imagine we need to extract the real and imaginary part individually, and both of them are the composition of exponential function and trigonometric function.



##### # Discrete Time Complex Exponent

































