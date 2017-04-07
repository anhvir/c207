/*  Function: cpu_time() 
	Purpose: returns CPU time (in seconds) between 
			 the previous call to cpu_time() and now

	Anh Vo, anhvir@gmail.com, 8 Apr 2017
*/



#include <time.h>



// returns the CPU time (in seconds) used the previous call 
//    and the current call to this function
double cpu_time() {
	static double prev_clock= -1;
	if (prev_clock<0) prev_clock= clock(); // this happens only once

	double sec= ( clock()-prev_clock )/CLOCKS_PER_SEC;
	prev_clock= clock();
	return sec;
}  


// example: delete this part, or replace 1 with 0 in the following line 
#if 1   

#include <stdio.h>
int main() {
	double s;
	cpu_time();     /* first call for setting the clock time */
	for (int i=0, s=0; i<1e9; i++) s += i;
	printf("CPU time for summing 10^9 numbers= %f\n", cpu_time());
					/* next call gives time from the last call */ 
	return 0;
}

#endif
