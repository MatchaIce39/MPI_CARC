#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {

	int my_rank, my_size;
	int numToSend, numToReceive;
	int currentProcess = 0;
	int neighbor = currentProcess + 1;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &my_size);
	
	numToSend = 67;

	//printf("Process: %d. Sending to my neighbor: %d", my_rank, (my_rank + 1));
	//test comment

	if(my_rank != (my_size - 1)) {

		if(my_rank == 0) {
			printf("Process %d sending to Process %d\n", my_rank, (my_rank + 1));
			MPI_Send(&numToSend, 1, MPI_INT, (my_rank + 1), 10, MPI_COMM_WORLD);

			printf("Process %d waiting for message from process %d\n", my_rank, (my_size - 1));
			MPI_Recv(&numToReceive, 1, MPI_INT, (my_size - 1), 11, MPI_COMM_WORLD, NULL);
		}
		else{
			printf("Process %d receiving from %d\n", my_rank, (my_rank - 1));
			MPI_Recv(&numToReceive, 1, MPI_INT, (my_rank - 1), 10, MPI_COMM_WORLD, NULL);
			printf("Process %d, sending to %d\n", my_rank, (my_rank + 1));
			MPI_Send(&numToSend, 1, MPI_INT, (my_rank + 1), 10, MPI_COMM_WORLD);
		}
	}
	else if(my_rank == (my_size - 1)) {
		printf("Process %d sending to Process 0\n", (my_size - 1));
		MPI_Send(&numToSend, 1, MPI_INT, 0, 11, MPI_COMM_WORLD);
	}

	MPI_Finalize();

	return 0;
}
