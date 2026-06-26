#include <stdio.h>
#include <mpi.h>

int main(int agrc, char** argv) {

	int my_rank, my_size, s = 0, x = 0;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &my_size);

	if(my_rank == 0) {
		printf("I am process 0 and I set 0 equal to 2\n");
		int x = 2;
	}

	MPI_Bcast(&x, 1, MPI_INT, 0, MPI_COMM_WORLD);
	printf("All processes now have the value of x\n");
	x = x * my_rank;
	printf("process %d set x to %d\n", my_rank, x);

	MPI_Reduce(&x, &s, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if(my_rank == 0) {
		printf("The sum is %d\n", s);
	}

	MPI_Finalize();

	return 0;
}
