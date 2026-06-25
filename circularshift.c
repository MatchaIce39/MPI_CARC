#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {

	int my_rank, my_size;
	//int counter = 2;
	int numberToReceive, numberToSend;
	MPI_Init(&argc, &argv);
	//MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &my_size);

	numberToSend = 67;
	printf("Sending %d to process 1\n", numberToSend);
	
	MPI_Send(&numberToSend, 1, MPI_INT, 1, 10, MPI_COMM_WORLD);
	MPI_Recv(&numberToReceive, 1, MPI_INT, 0, 10, MPI_COMM_WORLD, NULL);

	MPI_Finalize();

	return 0;
}
