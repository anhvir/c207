/* 
	main-2.c: Skeleton for a very simple program to test list.c
              Just build and print a list of int from MIN to MAX

	Created by Anh Vo, avo@unimelb.edu.au, for COMP20007 2020 S1 @ unimelb
	Program finished by:

	NOTE: for this program, you need to add only 2 statements, one in
	      each of the FIXME location   
*/


#include <stdio.h>
#include "listops.h"

#define MIN 1
#define MAX 10

int main(int argc, char *argv[]) {
	int i;
	list_t *l= make_empty_list();

  	for (i=MIN; i<=MAX; i++) {
		// FIXME: add i to the beginning or the end of the list
		
	}

	printf("Elements of the list: \n");
	while (!is_empty_list(l)) {
		// FIXME: remove an element (from the beginning or end of) the list
		//        and print it. 
		//        You should need a single printf statement 
		
	}
	printf("\n");

	free_list(l);	// remember that this one is important!
	return 0;
} 
