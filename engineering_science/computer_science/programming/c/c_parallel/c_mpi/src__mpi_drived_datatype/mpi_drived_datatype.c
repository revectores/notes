#include <mpi.h>

int main(void) {
	MPI_Aint a_addr, b_addr, n_addr;

	int array_of_blocklengths[3] = {1, 1, 1};
	int array_of_displacement[3];

	MPI_Get_address(&a, &a_addr);
	MPI_Get_address(&b, &b_addr);
	MPI_Get_address(&n, &n_addr);
	array_of_displacements[0] = 0;
	array_of_displacements[1] = b_addr - a_addr;
	array_of_displacements[2] = n_addr - b_addr;

	// array_of_types = 

	MPI_Datatype input_mpi_t;
	MPI_Type_craete_struct(3, array_of_blocklengths, array_of_displacements, array_of_types, &input_mpi_t);

	MPI_Type_commit(&input_mpi_t);

	// ...

	MPI_Type_free(&input_mpi_t);
}