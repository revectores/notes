# N Body Problem Numerical Algorithm

The n-body problem is the problem of predicting the individual motions of a group of objects (can be stars or particals) interacting with each other gravitationally. Formally, given initial position, volecity and mass for each object, we try to find the position and volecity at any time $t$.

There are two numerical approaches with slight difference, the first one, called **basic approach**, computes the forces from other practicals independently, while the second one, called **reduced approach**, reduce half of the computation by applying [Newton's third law](). When parallelizing them, the second one turns the communication from transferring position $s_i, s_j$ to each other to transferring one position and one force.





