/* 
	Calculating the nth Fibonacci number by various means.
	Fibonacci numbers defined as: f(n) = f(n-1) + f(n-2), f(0) = 0, f(1) = 1
	
	wrapper created by Anh (anhvir@gmail.com) for COMP20007 Sem 1 2017
    content created by <your name here>
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_N 46

/* function prototypes for the three different methods */
int fibRecursive(int n);
int fibArray(int n);
int fibEfficient(int n);

int main(int argc, char **argv) {
	char method= 'R';
	int n;
	int wrongArg = 0;

    // process command line, making sure that arguments are valid 
	if (argc == 2) {
		n= atoi( argv[1] );
	} else if (argc==3) {
		method= toupper( *(argv[1]) );
		n= atoi (argv[1]);
	} else wrongArg= 1;
	if (wrongArg || n<1 || n>MAX_N || !strchr("RAE",method) ) {
		fprintf(stderr,
				"usage 1: %s n\n"
				"usage 2: %s method n\n"
				"where n     : order of fibonacci number to calculate\n"
				"              must be between 1 and %d\n"
				"      method: R(ecursive), A(rray), E(fficient)\n",
				argv[0], argv[0], MAX_N);  
		exit(EXIT_FAILURE);
	} 

	// running a chosen Fib version
	printf ("%d=th Fibonacci number is %d\n",
			n, method=='R'? fibRecursive(n) :
               method=='A'? fibArray(n) : fibEfficient(n) );
	return 0;
}

// calculate fibonacci number using recursion
int fibRecursive(int n) {
	fprintf(stderr, "fibRecursive not yet implemented. Implement me!\n");
	return 1; 
}

// calculate fibonacci number using a malloc'd array
int fibArray(int n) {
	fprintf(stderr, "fibArray not yet implemented. Implement me!\n");
	return 1; 
}

// calculate fibonacci number using a more memory-efficient method
int fibEfficient(int n) {
	fprintf(stderr, "fibEfficient not yet implemented. Implement me!\n");
	return 1; 
}
