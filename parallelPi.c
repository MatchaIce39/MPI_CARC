#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	
	if(argc < 2) {
		printf("Missing arguments\n");
		return 1;
	}

	double b = 1.0;
	double a = 0.0;
	double result;
	double input;
	int n = atoi(argv[1]);

	//Determine delta X using our integration bounds and number of intervals desired
	double deltaX = (b - a) / n;
	printf(" (%f - %f) / %f. The value of delta X is %f\n", b,a,n,deltaX);

	//compute the first iteration with the lower integration bound
	double temp = (4 / (1 + pow(a,2)));
	printf("value of f(0) is %f\n", temp);
	result = result + temp;
	printf("Result is %f\n", result);

	for (int i = 0; i < (n-1); i++){
		input = input + (a + deltaX);
		printf("Next interval is %f\n", input);
		double tempFunction = (4 / (1 + pow(input, 2)));
		printf("f of %f is %f", input, tempFunction);
		tempFunction = tempFunction * 2;
		result = result + tempFunction;
		printf("Total result: %f\n", result);
	}

	temp = (4 / (1 + pow(b,2)));
	result = result + temp;
	result = result * (deltaX/2);

	printf("The approximation of the function is %f\n", result);
	return 0;
}
