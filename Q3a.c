/* import standard input/output library */
#include <stdio.h>

int main(int argc, char *argv[]){

	printf("%s\n", argv[0]);

	//validation check
	//if no of args not 3 (one for compiler, 2 for integers), error message
	// & program wont run
	if (argc != 3){
		printf("\nError: 2 arguments required!\n");
		return 1;
	}

	//declare variables for +ve integers
	//assign arguments to local variables
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	//start loop for calculating GCD
	//prints current calculation for each iteration
	while(b != 0){
		if (a > b){
			printf("Calculating %d\n - %d\n", a, b);
			a = a - b;
		}
		else{
			printf("Calculating %d\n - %d\n", b, a);
			b = b - a;
		}
	}

	//selecton statement, different response based on if GCD exists or not
	if (a > 1){
		printf("The greatest common divisor is: %d\n", a);
	}
	else{
		printf("There is no common divisor, apart from: %d\n", a);
	}
	return 0;
}
