# Bit Tricks

$$
\newcommand{\band}{\mathbin{\&}}
\newcommand{\bor}{\mathbin{|}}
\newcommand{\bnot}{\neg}
\newcommand{\lsl}{\stackrel{u}{\ll}}
\newcommand{\lsr}{\stackrel{u}{\gg}}
\newcommand{\asl}{\stackrel{s}{\ll}}
\newcommand{\asr}{\stackrel{s}{\gg}}
$$

##### # Notations

|          Symbol          |       Interpretation        |
| :----------------------: | :-------------------------: |
| $\band$, $\bor$, $\bnot$ |    bitwise and, or, not     |
|      $\lsl$, $\lsr$      |  Logical left/right shift   |
|      $\asl$, $\asr$      | Arithmetic left/right shift |



##### # Expressiveness of 

A function mapping words to words can be implemented with word-parallel `add`, `substract`, `and`, `or`, and `not` instructions if and only if each bit of the result depends only on bits and to the right of each input operand.







##### # Operations on Rightmost Bit

Set the rightmost 1 to 0 (keep $x$ all 0 if there is no 1 at all):
$$
x \band (x - 1)
$$
This can be used to detect whether an unsigned number is the power of 2 (applying zero detection).



Isolate the rightmost 1 (that is, clear all other 1):
$$
x \band (-x)
$$


Isolate the rightmost 0 (that is, only the bit of rightmost zero is 1):
$$
\bnot x \band(x + 1)
$$









