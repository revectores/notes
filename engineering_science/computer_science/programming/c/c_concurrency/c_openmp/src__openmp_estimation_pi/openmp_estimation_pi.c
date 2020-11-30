#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define RANDD() ((double) rand() / RAND_MAX)



int main(int argc, char* argv[]){
	int thread_count;
	double pi = 0;
	long long total_count = 0;
	long long inside_count = 0;

	thread_count = strtol(argv[1], NULL, 10);
	total_count = strtol(argv[2], NULL, 10);

	double start = omp_get_wtime();

#	pragma omp parallel for num_threads(thread_count) \
		reduction(+: inside_count) \
		schedule(runtime)
	for (int c = 0; c < total_count; c++){
		// long long my_count = 0;
		double x = RANDD();
		double y = RANDD();
		double dist = (x * x + y * y);
		if (dist < 1){
			inside_count++;
		}
	}

	double end = omp_get_wtime();
	printf("time_cost = %f\n", end - start);

	pi = 4 * (double)inside_count / total_count;
	printf("total = %lld\ninside = %lld\npi= %.10f", total_count, inside_count, pi);
	return 0;
}
