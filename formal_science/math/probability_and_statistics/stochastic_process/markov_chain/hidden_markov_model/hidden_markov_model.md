# Hidden Markov Model





##### # Markov Chain

The **(First-Order) Markov chain** embodies the **Markov assumption** which states that each state only depends on the last state on a state sequence, in other words, to predict the future, the past doesn't matter, only the present.

Formally, the Markov assumption reduces the condition in the conditional probability expression:
$$
P(q_i = a \mid q_1q_2\ldots q_{i-1}) = P(q_i = a \mid q_{i-1})
$$
Formally, a Markov chain is specified by three components:

1. **Set of $N$ states**. $Q = \{q_1, q_2, \ldots, q_N\}$.

2. **Transition probability matrix** $A = \{a_{ij}\}, 1\le i, j\le n$. $a_{ij}$ represents the probability moving from state $i$ to state $j$. s.t.
    $$
    a_{ij} \ge 0, \quad \sum_{j=1}^N a_{ij} = 1
    $$

3. **Initial probability distribution** over states $\pi = [\pi_1, \pi_2, \ldots, \pi_N]$. $\pi_i$ is the probability that the Markov chain will start in state $i$. s.t.
    $$
    \pi_i \ge 0, \quad \sum_{i=1}^n \pi_i = 1
    $$

4. 

The markov chain can be described as [undetermined finite state machine](), with probability on the arcs:

==TODO: Draw undetermined FSM to represent an instance of markov chain.==



Applying Markov assumption, we're able to compute the likelihood of any given state sequence:
$$
\begin{align}
p(S_1, \cdots, S_T)
&= p(S_1) \times  p(S_2 \mid S_1) \times p(S_3 \mid S_1, S_2) \times p(S_T \mid S_1, \cdots, S_{T-1}) \\
&= p(S_1) \times p(S_2 \mid S_1) \times p(S_3 \mid S_2) \times p(S_T \mid S_{T-1}) \\
&= \pi_{S_1}\prod_{t=1}^{T-1}a_{S_iS_{i+1}}
\end{align}
$$
where the $\Pi_{S_1}$ is the probability of the initial state.



##### # Hidden Markov Process

The hidden Markov process is a **doubly stochastic process**:

- Stochastic process of hidden state transition.
- Stochastic process of emission, from hidden state to observable result.

In context of [part of speech tagging](), the tag conversion from previous word to next word can be considerred as state conversion, and the word (emitted from word tag) can be considered as emission.

A hidden Markov process is specified by five components:

1. A set of $N$ states $Q = \{q_1, q_2, \ldots, q_N\}$.

2. A sequence of $T$ observations $O =o_1o_2 \ldots o_T$, each one drawn from a **vocabulary** $V = \{v_1, v_2, \ldots, v_V\}$.

3. State **transition probability matrix** $A = \{a_{ij}\}, 1\le i, j\le n$. $a_{ij}$ represents the probability moving from state $i$ to state $j$. s.t.
    $$
    a_{ij} \ge 0, \quad \sum_{j=1}^N a_{ij} = 1
    $$

4. The **observation likelihoods** or **emission probability** $B = b_i(o_t)$, each represents the probability of an observation $o_t$ being generated from a state $i$.
    $$
    \left\{\begin{array}{ll}
    b_j(k) = p(O_t = v_k \mid q_t = S_j), \quad 1 \le j \le N, 1\le k \le M \\
    b_j(k) \ge 0 \\
    \displaystyle\sum_{k=1}^M b_j(k) = 1 
    \end{array}\right.
    $$

5. **Initial probability distribution** over states $\pi = [\pi_1, \pi_2, \ldots, \pi_N]$. $\pi_i$ is the probability that the Markov chain will start in state $i$. s.t.
    $$
    \pi_i \ge 0, \quad \sum_{i=1}^n \pi_i = 1
    $$

6. 

Hence we can denote HMM as a triple $\mu = (A, B, \pi)$ or quintuple $\mu = (Q, O, A, B, \pi)$.

The hidden Markov models should be characteried by three fundamental problems:

1. **[Likelihood]** Given an HMM $\lambda$ and an observation sequence $O$, determine the likelihood $P(O \mid \lambda)$.
2. **[Decoding]** Given an observation sequence $O$ and an HMM $\lambda$, discover the best hidden state sequence $Q$.
3. **[Learning]** Given an observation sequence $O$ and the set of states in the HMM, learn the HMM parameters $A, B$.



##### # Likelihood: Forward Algorithm

Problem: Given an HMM $\lambda$ and an observation sequence $O$, determine the likelihood $P(O \mid \lambda)$.

To compute the probability of $O$, we simply iterate all the possible state transitions sequence $Q$ then sum them up: (all of the probability is computed based on given HMM $\lambda$, for conciseness, we omit the condition $\lambda$)
$$
P(O) = \sum_Q P(O, Q) = \sum_Q P(Q)P(O\mid Q)
$$
where the $p(Q)$ and $p(O \mid Q)$ can be easily computed by the given HMM $\lambda$:
$$
\begin{align}
p(Q) &= \pi_{q_1}a_{q_1q_2}a_{{q_2}{q_3}}\cdots a_{{q_{T-1}}{q_T}}
\\
p(O\mid Q) &= b_{q_1}(o_1)b_{q_2}(o_2)\cdots b_{q_T}(o_T)
\end{align}
$$

This approach requires $N^T$ multiplication, we apply a dynamic programmin approach named **forward algorithm** to simplify the computation:

Define
$$
\alpha_t(j) = P(o_1o_2\ldots o_t, q_t = j \mid \lambda)
$$
to represent the probability of being in state $j$ after seeing the first $t$ observation, which can be computed incrementally as
$$
\alpha_t(j) = \sum_{i=1}^N \alpha_{t-1}(i)a_{ij}b_j(o_t)
$$
where the three factors

- $\alpha_{t-1}(i)$ is the previous forward path probability from previous time step.
- $\alpha_{ij}$ is the transition probability from previous state $q_i$ to current state $q_j$.
- $b_j(o_t)$ is the state observation likelihood of the observation symbol $o_t$ given the current state $j$.

Then the final probabiltiy $P(O \mid \lambda)$ can be interpreted as
$$
p(O\mid\lambda) = \sum_{S_i} p(o_1,o_2,\ldots, o_T, q_T=S_i \mid \mu) = \sum_{i=1}^N \alpha_T(i)
$$

In summary, the forward algorithm can be implemented by three steps:

1. Initialize:
    $$
    \alpha_1(j) = \pi_j b_j(o_1), 1\le i \le N
    $$

2. Recursion:
    $$
    \alpha_t(j) = \sum_{i=1}^N\alpha_{t-1}(i)a_{ij}b_j(o_t), \quad 1 \le j \le N, 1 < t \le T
    $$

3. Termination:
    $$
    P(O\mid\lambda) = \sum_{i=1}^N \alpha_T(i)
    $$

4. 

Time complexity of forward algorithm: $O(N^2T)$.

**Backward algorithm** is a similar algorithm with different direction in computation.



##### # Decoding: Viterbi Algorithm

Problem: Given an observation sequence $O$ and an HMM $\lambda$, discover the best hidden state sequence $Q$.





##### # Forward-Backward procedure

Problem: Given an observation sequence $O$ and the set of states in the HMM, learn the HMM parameters $A, B$.

