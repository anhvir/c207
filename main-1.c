/* 
	main-1.c: Skeleton for a very simple program to test list.c
              Just build and print a list of int from MIN to MAX

	Created by Anh Vo, anhvir@gmail.com, for COMP20007 2017 S1 @ unimelb
	Program finished by:

	NOTE: for this program, you need to add only 2 statements, one in
	      each of the FIXME location   
*/


#include <stdio.h>
#include "list.h"

#define MIN 1
#define MAX 10

int main(int argc, char *argv[]) {
	int i;
	List *l= new_list();

  	for (i=MIN; i<=MAX; i++) {
		// FIXME: add i to the beginning or the end of the list
		
	}

	printf("Elements of the list: \n");
	while (!list_is_empty(l)) {
		// FIXME: remove an element (from the beginning or end of) the list
		//        and print it. 
		//        You should need a single printf statement 
		
	}
	printf("\n");

	free_list(l);	// remember that this one is important!
	return 0;
} 
