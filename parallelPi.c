#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
	
	int my_rank, my_size;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &my_size);

	if(argc < 2) {
		printf("Missing arguments\n");
		return 1;
	}

	double b = 1.0;
	double a = 0.0;
	int testValue = 0;
	double result = 0;
	double input;
	double temp = 0;
	double deltaX = 0;
	int n = atoi(argv[1]);

	printf("Hello\n");

	if(my_rank == 0) {
	
		//Determine delta X using our integration bounds and number of intervals desired
		deltaX = (b - a) / n;
		printf(" (%f - %f) / %f. The value of delta X is %f\n", b,a,n,deltaX);

		//compute the first iteration with the lower integration bound
		temp = (4 / (1 + pow(a,2)));
		printf("value of f(0) is %f\n", temp);

		result = result + temp;
		printf("Result is %f\n", result);

		testValue = testValue + 50;
	}

	MPI_Bcast(&deltaX, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        MPI_Bcast(&result, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        MPI_Bcast(&testValue, 1, MPI_INT, 0, MPI_COMM_WORLD);

	printf("value of test is: %d\n", testValue);
	printf("value of deltaX is: %f\n", deltaX);
	printf("value of result is: %f\n", result);


	//Last edge case I will skip for now
	/*
	if (my_rank == (my_size - 1)) {
		//temp = (4 / (1 + pow(b,2)));
                //result = result + temp;
                //result = result * (deltaX/2);
	}
	*/

        else {

		input = input + (a + deltaX);
		//printf("Next interval is %f\n", input);
		double tempFunction = (4 / (1 + pow(input, 2)));
		//printf("f of %f is %f", input, tempFunction);
		tempFunction = tempFunction * 2;
		result = result + tempFunction;
		//printf("Total result: %f\n", result);
	
	}


	

	MPI_Finalize();
	return 0;
}
