$$
\newcommand{\sgn}{\text{sgn}}
\newcommand{\sig}{\text{sigmoid}}
$$

# Neural Network

### 1. Neural Network

##### # Concepts

A **neuron** is a node which accepts multiple inputs and generates a single output, the input or output is received from/sent to outside environment or other neurons. A neuron is no more than a **mutivariable function** based on this definition:
$$
y = h(x_1, x_2, ..., x_n)
$$
In the traditional M-P neuron model, the function form of a neuron is limited to the following form: a function on the linear combination of inputs.
$$
y =
f\left(\sum_{i=1}^n\omega_i x_i - \theta\right)
$$
where $f$ is called **Activation Function**,  $w_i$ are **Weights**, which demonstrate the relative importance for the inputs, and $\theta$ is **Threshold**. To unify the threshold into weights, constant $\theta$ can be considered as a coefficient of constant input $x_{i+1}=-1$, which is usually called **Dummy Node**.



##### # Activation Function

Two kinds of activation functions are used in neuron network, **Heaviside Step Function** and the **Sigmoid Function**:
$$
\sgn(x) = \left\{
\begin{array}{c l}
     1,  & x\ge 0 \\
     0,  & x < 0
\end{array}\right.
\qquad\qquad

\sig(x) = \cfrac{1}{1+e^{-x}}
$$
Since the simple calculation of heaviside step function, most of the calculated inductive will be demonstrated in this activation function. In the contrary, since the well continuity and other properties of sigmoid function, most of example including prove will consider activation function as this function. 



##### # Network of Neurons

The connection of neurons construct the network of neurons. 

> E.G. Count how many parameters are there in a 10-neuros networks with connection between any two neurons.
>
> There're two possible answers depend on weather the graph of neural network is directed.
>
> For the directed case, any neuron accept inputs from other 9 neurons, and each neuron preserves one threshold, so the answer will be $(9+1)\times10 + 10 = 100$.
>
> For the undirected case, 



Different structures of neural networks fit different kinds of problems.







### 2. Perceptron

**Perceptron**, or **Threshold Logic Unit**, defined as the one-layer neural network, which is constructed by two-layer neurons.

We introduce the construction of neurons, along with detailed explainations for training process  in [Construction of Perceptron](Construction of Perceptron) trying to generate basic logic gates.

Because of the limitation of form of neuron, as one-layer network, perceptron can only be trianed to solve line-seperable problem, for example, the logic `and`, `or`, and `not` are all line-seperable, but not `xor`, which requires two-layer perceptron to solve.







### 3. Classifications of NN

##### # FeedForward Neural Netwok: FNN

FeedForward Neural Netwrok is the most simple type, in which the singal only 



##### # Recurrent Neural Network: RNN



 pure RNN LSTM



##### # Convolutional Neural Network: CNN