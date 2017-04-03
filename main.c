/* 
   main.c: testing heap.[c,h]
   Anh Vo, anhvir@gmail.com, 2 Apr 2017
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"

#define V 10

int 
main(int argc, char *argv[]) {
    
    Heap *h = create_heap();
	int i, m;

    // insert V random keys >=10 into heap
	srand(time(NULL));   // starts usinf random numbers
    for( i = 0 ; i < V ; i++) {
        insert(h, i, rand()%V +10);   // all  >= 10
        print_heap(h);
    }

    // changing key of dataIndex V/2 twice
    for (i=0; i<2; i++) {
		m= i==0? -8 : 12; 
        change_key(h, V/2, m );
		printf("after changing key of dataIndex [%d] by %d:\n", V/2, m);
        print_heap(h);
        printf("Min is %d with key %d\n", peek(h), peek_key(h));
    }

	// remove_min twice
    for (i=0; i<2; i++) {
    	m= remove_min(h);
		printf("after remove_min get result=%d:\n",m);
    	print_heap(h);
    	printf("Min is %d with key %d\n", peek(h), peek_key(h));
    }
    
	destroy_heap(h);

    return EXIT_SUCCESS;
}
