#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	
	if(argc < 2) {
		printf("Missing arguments\n");
		return 1;
	}

	int b = 1;
	int a = 0;
	int result = 0;
	int input;
	int n = atoi(argv[1]);

	int deltaX = (b - a) / n;

	//Inputting a in the function
	int temp = (4 / (1 + pow(a,2)));
	result = result + temp;

	for (int i = 0; i < (n-1); i++){
		input = input + (a + deltaX);
		int tempFunction = (4 / (1 + pow(input, 2)));
		tempFunction = tempFunction * 2;
		result = result + tempFunction; 
	}

	temp = (4 / (1 + pow(b,2)));
	result = result + temp;

	result = result * (deltaX/2);

	printf("The approximation of the function is %d\n", result);
	return 0;
}
