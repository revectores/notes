#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


void Trap(double a, double b, int n, double* global_result_p);

int main(int argc, char* argv[]){
	int thread_count;

	thread_count = strtol(argv[1], NULL, 10);

	int sub = 0;
#	pragma omp parallel num_threads(thread_count) \
		reduction(-: sub)
	{
		int my_rank = omp_get_thread_num();
		sub -= my_rank;
	}

	printf("%d", sub);
	return 0;
}
