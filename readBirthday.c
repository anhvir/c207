/* avo@unimelb.edu.au, for comp20007 workshop week 2 */

#include <stdio.h>
#include <stdlib.h>


#define MAX_NAME 30
#define FNAME "birthday.data.txt"

int main(int argc, char *argv[]) {
	char name[MAX_NAME+1];
	int month;
	FILE *f= fopen(FNAME,"r");
	if (!f) {
		printf("Error: Cannot find data file %s\nPlease download it!\n",
		        FNAME);
		exit(EXIT_FAILURE);
	}

	printf("Content of file %s\n", FNAME);
	printf("    name          month_of_birth\n");      
	while( fscanf(f, "%[^,], %d ", name, &month) == 2 ) {
		// Note: In the above format string:
        //            %[^,]  means "read all character until comma"
		//            ,      means just consume the comma (not assigning)
		//                   the space after %d is important (why?)
 
		printf ("%-*s %2d\n", MAX_NAME, name, month);
		// Note: the value of MAX_NAME will be replaced the *
		//       and become ("%-30s %d\n", name, month)
		// Q   : Why that complicated?
		//       Can we just use simple format "%s, %d " ???
 	
		// Extension 1:
		//   Feel free to add any processing of birthday data here
		//   For example:
		//      + storing them in a dynamically-resized array,
        //      + storing them in a linked list
		//        (you can used Alistair's listops.c from last year) 
	}

	// Extension 2:
	//   Feel free to add some additional functinality, say:
	//    + print the birthday liat in some sorted order
	//    + print out the names with birthday in August 
	//    + any other thing you can think about,
	//      if you think your extension is interesting, share
	//      it with the class and/or your tutor  
	
	return 0;
}

