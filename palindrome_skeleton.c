/* Skeleton for maximal palindrome problem

   Anh Vo, May 2016

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRLEN 255

void normalize(char *s, char *ns, int *a); 
void max_polindrome(char *s, int *ii, int *jj);

int main() {
  char s[MAXSTRLEN+1];          /* original string */
	char ns[MAXSTRLEN+1];         /* normalized string */
	int a[MAXSTRLEN];             /* maps position in ns to poiion in s */ 
	int i, j;

															


  while( fgets(s, MAXSTRLEN, stdin) ) {
		/* when using fgets, s can have some crazy trailing '\n' at the end,
		   which can by anoying sometime;
			 the next 2 lines aim to cut off these '\n' 
			 by replacing the first appearance of '\n' with '\0'
			 For this task, of course you can safely remove these 2 lines
		*/
		char *p;
  	if ( (p= strchr(s,'\n')) ) *p= '\0'; 
		
		normalize(s,ns, a);         /* produce the normalized string */ 
  	max_polindrome(ns, &i, &j); /* and work on that normalized string instead*/ 
  
  	printf("String : %s\n", s);
		s[a[j]+1]= '\0';
		printf("Max Palindrome = %s\n\n", s+a[i]);
	}
	return 0;
}



/* makes ns the "normalized" string of s,
   where only alphanumeric characters are kept,
	 and all uppercase letters changed to lower case;

	 also return array a[] with maps position i in the normalised string
	 into a[i]= equivalent position in  s
*/
void normalize(char *s, char *ns, int *a) {
  int n= strlen(s);
  int i, j;

	for (i=0, j=0; j<n; j++) {
	 	if (isalnum(s[j])) {
			ns[i]= tolower(s[j]);
			a[i++]= j;
		}
	}
	ns[i]= '\0';
}


/* work out *ii, *jj such that s[*ii,...,*jj] is a max polindrome of s */
void max_polindrome(char *s, int *ii, int *jj) {
	
  *ii= *jj= 0;  /* REPLACE ME */
	

}

  





