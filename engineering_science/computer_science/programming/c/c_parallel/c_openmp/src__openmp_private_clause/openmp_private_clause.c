#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Hello(void);

int main(int argc, char* argv[]){
	int thread_count = strtol(argv[1], NULL, 10);

	int x = 5;
#	pragma omp parallel num_threads(thread_count) \
	private(x)
{
	int my_rank = omp_get_thread_num();
	printf("Thread %d > before init, x = %d\n", my_rank, x);
	x = 2 * my_rank + 2;
	printf("Thread %d > after init, x = %d\n", my_rank, x);
}
	printf("After parallel block, x = %d\n", x);

	return 0;
}

void Hello(void) {
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();

	printf("Hello from thread %d of %d\n", my_rank, thread_count);
}
