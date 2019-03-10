#include <stdio.h>


#define MAX_NAME 30

int main(int argc, char *argv[]) {
	char name[MAX_NAME+1];
	int month;

	printf("The input data:\n");
	printf("    name             month_of_birth\n");      
	while( scanf("%[^,], %d ", name, &month) == 2 ) {
		// Note: %[^,]  means "read all character until comma"
		//            , means just consume the comma (not assigning)
		// the space after %d is important (why?) 
		printf ("%-*s %2d\n", MAX_NAME, name, month);
		// Note: the value of MAX_NAME will be replaced the *
		//       and become ("%-30s %d\n", name, month)

		/* For the birthday task:
		   Now you need to make a new node with name, month
			then insert that node into an appropriate list
		*/ 
	}
	
	return 0;
}

