/* 
	Skeleton for Lab's Problem 2: Calculating the nth Fibonacci number
	                              using 3 different methods.
	NOTES : This program include all 3 methods,
	        So we just write 1 instead of 3 separate programs (as required)
	TIMING: 15 minutes maximum. 
	ADVICE: Compile and try the program before making any change
	        You can choose to implement just 1 or 2 methods,
	        as you need time for other exercises.
	
	BACKGROUND:
	Fibonacci numbers defined as: f(n) = f(n-1) + f(n-2), f(0) = 0, f(1) = 1
	
	------------------------------------------------------------------
	wrapper created by Anh Vo (anhvir@gmail.com) for COMP20007 2019s1
    full program created by <your name here>
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MIN_N 1
#define MAX_N 46
const char *methodNames[]={"Recursive", "Array", "InPlace", ""};
/* the lats member, an empty string, serves as a sentinel */ 


/* function prototypes for the three different methods */
int fibRecursive(int n);
int fibArray(int n);
int fibInPlace(int n);


/* The main() function is fully implemented
   You can just ignore it, and go to implement each of the fib functions
*/  
int main(int argc, char **argv) {
	int (*fibFunctions[]) (int)= {&fibRecursive, &fibArray, &fibInPlace};
	/* fibFunctions is an array of "function pointers"
		Used here to pack functions into an array, and then we can
		access an individual function with the help of an index
       
	  NOTE: We can also write
	int (*fibFunctions[]) (int)= {fibRecursive, fibArray, fibInPlace};
    */

	int method= 0;     // default method is the first one
	int n;
	int wrongArg = 0;
			
    // process command line, and make sure that arguments are valid 
	if (argc == 2) {
		n= atoi( argv[1] );
	} else if (argc==3) {
		n= atoi (argv[2]);
		method= 0;
		for (method=0; 
			*methodNames[method] 
			  && toupper(*methodNames[method]) != toupper(*argv[1]); 
			method++); 
		// Notes: *s[i] is the first character of string s[i]
		//        Recall that the last member of methodNames[] is a sentinel  
		if ( !*methodNames[method] ) wrongArg= 1;
	} else wrongArg= 1;

	if (wrongArg || n<MIN_N || n>MAX_N ) {
		fprintf(stderr,
				"usage 1: %s n\n"
				"usage 2: %s method n\n"
				"where n     : order of fibonacci number to calculate\n"
				"              must be between %d and %d\n"
				"      method: R(ecursive), A(rray), I(nPlace)\n",
				argv[0], argv[0], MIN_N, MAX_N);  
		exit(EXIT_FAILURE);
	} 
 	
    printf("Fibonacci calculation using the %s method\n", methodNames[method]);
	
	// running a chosen Fib version
	printf ("%d-th Fibonacci number is %d\n", n, fibFunctions[method](method));
	
	/* if you don't like array of function pointers, you can replace
	   the last member above with something like: 
	   method==0? fibRecursive(method) : (method==1? fibArray(method) : ...)
	*/
	
	return 0;
}

// calculate fibonacci number using recursion
// THINK: What is the major problem of this approach in terms of efficiency?
int fibRecursive(int n) {
	/* A good approach for recursive functions is to solve the base cases first
	   For this task the base cases are when n is 0 or 1, ie n <= 1 
	*/ 
	if (n <= 1) {
		/* return solution for n<=1 */
	}
	
	/* now solve the general case when n > 1 */
	
	fprintf(stderr, "fibRecursive not yet implemented. Implement me!\n");
	return 1; 
}

// calculate fibonacci number using a dynamic (ie with malloc) array
// THINK: What is the major problem of this approach in terms of efficiency?
int fibArray(int n) {
	int nfib=1;  // variable to keep the n-th Fibonacci number
	int *fib;    // need to turn fib into an array of n+1 cells using malloc 
	/* 1. Allocate n+1 cells for array fib */
	
	
	/* 2. setting value for n+1 Fibonacci numbers into fib[] */
	
	
	/* 3. store the n-th Fibonacci in nfb*/
	
	
	/* 4. free the memory alloceted for fib */
	
	
	/* REMEMBER: procedure to work with dynamic memory & example:
	   malloc              x= malloc( sizeof(*x) * k );
	   assert              assert( x && "Cannot malloc" );
	   use the memory      for ( ; k>0 ; k-- ) x[k]= k; 
	   free                free(x); 
	                    (have you added #include <stdlib>, <assert.h> ? )
	*/
	
	fprintf(stderr, "fibArray not yet implemented. Implement me!\n");
	return nfib; 
}

// calculate fibonacci number using a more memory-efficient method
// NOTE: The target is to use just 3 variables to store intermediate fib value,
//       that does not count the variable n, and, if needed, a loop counter.
//       Using just 2 intermediate variables is possible, but a bit tricky,
//       don't try that if you can't think about a way within 1 minute.
int fibInPlace(int n) {
	fprintf(stderr, "fibInPlace not yet implemented. Implement me!\n");
	return 1; 
}
