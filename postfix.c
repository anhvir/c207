/* Anh Vo, anhvir@gmail.com, for COMP20007 2017 S1 @ unimelb

   
   postfix.c: demonstrating the use of stack
              in evaluating postfix expression 
              (a.k.a. reverse Polish notation)
   CONCEPTS: Postfix expression is an (here, arithmetic) expression
             where operators follow (as opposed to "are in between")
             the operands, for example:
               3 5 +       means 3+5
               2 13 5 + *   means 2 * ( 13 + 5 )
             IMPORTANT: for simplicity, we suppose that all operands are
             non-negative integer. For instance, we do not consider postfix
             notation for expression like (-30) + 5, or 2.5 + 7.  

  APPROACH:  Here, we use stack to evaluate the expression, for example,
             the second expression is evaluated as:
				read 2
				push 2
				read 3
				push 3
				read 5
				push 5
				read +  (which is an operator requiring 2 operands)
				pop     // got 5   
				pop     // got 3
				push 3*5 
				read *  (which is an operator requiring 2 operands)
				pop     // got 15
				pop     // got 2
				push 2*15
                as input finishes, pop (got 30) gives the final value
	  

   IMPORTANT NOTES:
	This program should be used with your implementation of Stack
	Supposing:
		- stack.h is the interface of your stack module
		- the stack data type is Stack, and there are functions: 
			Stack *new_stack()
			void stack_free(Stack *s)
			void stack_push(Stack *s, int x)
			int stack_pop(Stack *s)
			int stack_size(Stack *s)
		- you might need to change the function calls to fit your stack implementation! 


*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>  
#include "stack.h"

#define MAX_STRLEN 255  /* max length of expression */

// define status of expression
#define NO_EXP 0
#define GOOD_EXP 1
#define UNBALANCED 2



int main(int argc, char *argv[]) {
	char s[MAX_STRLEN+1];

	printf("Enter postfix expression: ");
	while (fgets(s, MAX_STRLEN, stdin)) { // read new expression to s
		Stack *st= new_stack();
		char *p;
		int a, b, c;
		int status= NO_EXP;

		for (p=s; *p; p++) {
			if (isdigit(*p)) {              // gets a number
				status= GOOD_EXP;
				for (a= 0; *p && isdigit(*p); p++) a= a*10 + (*p-'0');
				stack_push(st, a);
			} 
			if ( !strchr("+-*/", *p) ) continue;
			/*    skip anything which is not an operator 
			      (such as comma, blank, \t, \n)  */         
 
			/* now, *p must be a binary operator (a limit of this prog) */
			if (stack_size(st)<2) { // should have at least 2 operands      
				status= UNBALANCED;
				break;
			}
			b= stack_pop(st); // now takes 2 operands & perform calculation
			a= stack_pop(st);
			switch (*p) {
				case '+': c= a+b; break;
				case '-': c= a-b; break;
				case '*': c= a*b; break;
				case '/': c= a/b; break;
			}
			stack_push(st, c);
		}
		if (status==NO_EXP) 
			printf("No epresssion.\n\n");
		else if (status==GOOD_EXP && stack_size(st)==1 ) 
			printf("   Value= %d\n\n", stack_pop(st));
 		else 
			printf("Wrong balance between operators"
			       " and operands in expression.\n\n");

		free_stack(st);
		printf("Enter postfix expression: ");
	}
	return 0;
} 
