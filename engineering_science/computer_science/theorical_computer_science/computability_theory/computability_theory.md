$$
\newcommand{\mF}{\mathcal F}
\newcommand{\mP}{\mathcal P}
$$

# Theory of Computation

##### # Unsolvable Problem

A problem can be solved, if and only if there's a program to correspond.

A problem can be modeled as a function, here we constrain the domain on $\N$, all the functions upon $\N$ constrcut a set $\mF\sim2^{\N} = \aleph_1$. Program is a string of inputable alphabet $\Sigma$, so all the programs construct a set $\mP\sim\N = \aleph_0$. This shows that the number of programs is far less than the number of problems, which implies there must be infinite problems which got no program to correspond, i.e. there're infinite problems unsolvable.



##### # Halting Problem

With a function and the inputs feed to the function given, is there a function `halt` to judge weather the program will stop?

> Construct a function `contradiction`:
>
> ```c
> void contradication(char *prog){
>     if(halt(prog, prog)) while(1);
> }
> ```
>
> 