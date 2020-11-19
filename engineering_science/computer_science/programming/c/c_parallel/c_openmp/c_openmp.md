# C OpenMP

##### # OpenMP Demo

The simplist OpenMP demo is given in [openmp_demo.c](src__openmp_demo/openmp_demo.c)

```{.c .numberLines startFrom="1" filename="openmp_demo.c"}
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Hello(void);

int main(int argc, char* argv[]){
	int thread_count = strtol(argv[1], NULL, 10);

#	pragma omp parallel num_threads(thread_count)
	Hello();

	return 0;
}

void Hello(void) {
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();

	printf("Hello from thread %d of %d\n", my_rank, thread_count);
}
```

OpenMP instruction should be programmed inside `#pragma omp`. The statement

```c
#	pragma omp parallel num_threads(thread_count)
```

open `thread_count` threads to execute the followed **block**, specifically, the current thread, as the **master **thread, forks `thread_count - 1` **slaves** threads to execute the same block, the master and slaves are called a **team**. An **implicit barrier** is added after `Hello()` hence the master will block until all the threads returned from the block.

As shown, the function `omp_get_thread_num()` and `omp_get_num_threads()` return the rank of current thread and the count of threads respectively.

To be compatible with those complier does not support OpenMP, we can use the marco `_OPENMP` to do the conditional compiling, for example we can modify the demo program as [openmp_demo_comp.c](src__openmp_demo_comp/openmp_demo_comp.c)

```{.c .numberLines startFrom="1" filename="openmp_demo_comp.c"}
#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
	#include <omp.h>
#endif

void Hello(void);

int main(int argc, char* argv[]){
	int thread_count = strtol(argv[1], NULL, 10);

#	pragma omp parallel num_threads(thread_count)
	Hello();

	return 0;
}

void Hello(void) {
#ifdef _OPENMP
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();
#else
	int my_rank = 0;
	int thread_count = 1;
#endif

	printf("Hello from thread %d of %d\n", my_rank, thread_count);
}
```



##### # Compiling Command

To complie the C program with OpenMP:

```c
gcc -g -Wall -fopenmp -o hello hello.c
```

and two approaches to specify the threads count, passing argument or getting from environement variable:

by passing to argument:

```shell
./hello 4
```



##### # OpenMP Critical Section

Inside the OpenMP implementation of trapezoidal rule [openmp_trapezoidal.c](src__openmp_trapezoidal/openmp_trapezoidal.c), the **critical section** is specified by

```{.c .numberLines startFrom="57" filename="openmp_demo_comp.c"}
#	pragma omp critical
	*global_result_p += my_result;
```

where the pointer `global_result_p` points to the global sum which might be modified by multiple threads synchronically, we use the `#pragma omp critical` to implement mutual exclusion.



##### # OpenMP Variable Scope

There are two types of variable: **shared variable** that can be accessed by all the threads and, **private variable** can only be

All the variables defined before the parallel block are shared by default, while the variables defined in the block is private.



##### # OpenMP Reduction Clause

The **reduction clause** is provided in OpenMP as the shortcut for reduction:

```c
double global_result = 0.0;
#	pragma omp parallel num_threads(thread_count) \
		reduction(+: global_result)
	global_result += Local_trap(double a, double b, int n);
```

This is equivalent to the manual critical version

```c
double global_result = 0.0;
#	pragma omp parallel num_threads(thread_count)
{
	double my_result = 0.0;
	my_result += Local_trap(double a, double b, int n);
#	pragma omp critical
	global_result += Local_trap(double a, double b, int n);
}
```



| Operator | Identity Value |
| :------: | :------------: |
|    &&    |       1        |
|   \|\|   |       0        |
|    &     |   111...111    |
|    \|    |       0        |
|    ^     |       0        |



### 3. OpenMP Parallel `for`



```c
h = (b - a)/n;
approx = (f(a) + f(b))/2.0
#pragma omp parallel for num_threads(thread_count) \
	reduction(+:approx)
for (i = 0; i <= n-1; i++)
    approx += f(a + i*h);
approx = h * approx;
```



- The `index` must be a integer or pointer type. (for example, it can't be a float.)
- The expressions `start`, `end` and `incr` must have a compatible type.
- The expressions `start`, `end` and `incr` must not change during execution of the loop.
- During execution of the loop, the variable can only be modified by the increment expression inside the `for` statement.



```c
int Linear_search(int key, int A[], int n){
    int i;
#	paraga omp parallel 
}
```

OpenMP is not aware of the dependency between iteration.









