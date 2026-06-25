#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {

	int my_rank, my_size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &my_size);

	//Size is how many processes will be running
	//Rank is the unique identifier for each process
	
	//My size is 100 and my rank is 57. I spawned 100 processes and the 57th is being used right now
	printf("Hello world from processes %d of %d totalgprocesses\n", my_rank,my_size);

	if(my_rank == 0) {
		printf("This is the master rank\n");
	}
	MPI_Finalize();

	return 0;

}
