/* 
	My play ground, for trying various things
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MIN 1
#define MAX 13

int fact(int);

int main(int argc, char *argv[]) {
	int in, out;
	printf("Enter an int between %d and %d: ", MIN, MAX);
	if ( scanf("%d", &in) != 1 || in<MIN || in>MAX ) {
		printf("Invalid input, please rerun!\n");
		exit(EXIT_FAILURE);
	}

	out= fact(in);

	printf("Testing FACTORIAL.\nInput= %d, Output= %d\n", in, out);

	

	return 0;
} 

int fact(int n) {
	if (n<=1) return 1;
	return n*fact(n-1);
}
