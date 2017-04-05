/*
	heap.c, heap.h: implementation of min heap,
		allowing random access to heap using index of data payload

	Skeleton plus some implementation for COMP20007 Lab Week 6
	Prepared by Anh Vo (anhvir@gmail.com), 02 Apr 2017
	Based on the originals by:
** Andrew Turpin
** Wed  3 Apr 2013 13:47:20 EST
*/

#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

// utilities for replacing malloc and realloc ===========

void *safe_malloc(int bytes) {
	void *p;
	if ( !(p=malloc(bytes))) {
		fprintf(stderr, "Cannot malloc %d bytes\n", bytes);
		exit (EXIT_FAILURE);
	}
	return p;
}

void *safe_realloc(void *block, int bytes) {
	void *p;
	if ( !(p=realloc(block, bytes))) {
		fprintf(stderr, "Cannot realloc %d bytes\n", bytes);
		exit (EXIT_FAILURE);
	}
	return p;
}

void error(char *caller) {
	fprintf(stderr, "%s : not yet implemented. Implement me first!\n", caller);
}

// end of utilities =========================================


#define MIN_HEAP_SIZE 4    // initial maxial heap size

typedef struct item {
	float key;	    // the key for deciding position in heap
	int  dataIndex;	// the payload index provided by the calling program
} HeapItem;

struct heap {
	HeapItem *H;// the underlying array
	int *map;	// map[i] is index into H of location of item with
				//      dataIndex == i
				// H[] and map[] are dynamic array
	int n;		// the number of items currently in the heap
	int size;	// the current maximum number of items allowed in the heap
};



// returns a pointer to a new, empty heap
Heap *create_heap() { 
	Heap *h = safe_malloc(sizeof(*h));
	h->H   = safe_malloc(sizeof(HeapItem)*MIN_HEAP_SIZE);
	h->map = safe_malloc(sizeof(int)*MIN_HEAP_SIZE);
	h->n   = 0;
	h->size= MIN_HEAP_SIZE;
	return h;
}                               

// double the size of arrays H[] and map[] in heap
// assumes h != NULL, h->size > 0
void enlarge_heap(Heap *h) {
	h->H = safe_realloc(h->H, sizeof(HeapItem) * h->size * 2);
	h->map = realloc(h->map, sizeof(int) * h->size * 2);
	h->size *= 2;
}

// Swap elements a and b in heap. That include:
//    - swapping map[ H[a].dataIndex ] with map[ H[b].dataIndex ]  (WHY?)
//    - swapping H[a] with H[b]
// Notes: You should carefully read the lab instruction to understand
//        map[], and why & how we should swap elements in map[] 
// assumes h != NULL 
void swap (Heap *h, int a, int b) {
	
    // swapping map elements
	int i  = h->map[h->H[a].dataIndex];
	h->map[h->H[a].dataIndex] = h->map[h->H[b].dataIndex];
	h->map[h->H[b].dataIndex] = i;

	// swapping heap elements
	HeapItem t = h->H[a];    
	h->H[a] = h->H[b];       
	h->H[b] = t;             
}





// siftup: heap element in position n is likely larger than its parent
//         siftup keeps move it up when neccessary  
// assumes h != NULL
void
siftup(Heap *h, int n) {
	int child  = n;
	int parent = (child - 1) / 2;
	while ((child > 0) && (h->H[parent].key > h->H[child].key)) {
		swap(h, parent, child);
		child = parent;
		parent = (child - 1) / 2;
	}
}

// return the position of the smllest-weight child of p
//        -1 if not exists
int min_child(Heap *h, int p) {
	int c= 2*p+1;
	if ( c < h->n ) {
		if ( (c+1 < h->n) && (h->H[c+1].key < h->H[c].key) ) c++;
	} else 
		c= -1;
	return c;
}

// siftdown: heap element in position n is likely smaller than its children
//         siftup keeps move it down when neccessary  
// assumes h != NULL
void
siftdown(Heap *h, int n) {
	int parent = n, child;
	child= min_child(h, parent);

	// similar to sifup, now we iteratively consider swapping parent & child

	error("siftdown");	
}

// inserts dataIndex into h, supposing h != NULL
// to insert: 
//            +  add the element to position n of the heap,
//                  don't forget h->map           
//            + update h->n
//            + call siftup to repair the heap 
int 
insert(Heap *h, int dataIndex, float key) { 
	if (h->n == h->size) enlarge_heap(h);
	error("insert"); 	
	return HEAP_SUCCESS;
}     

// returns the data index of the root.
// or HEAP_FAILURE if no data in heap
int 
peek(Heap *h) { 
	if (h && h->n > 0)
		return h->H[0].dataIndex;
	else
		return HEAP_FAILURE;
}

// returns the key of the root.
// or -1 if no data in heap
int 
peek_key(Heap *h) { 
	if (h && h->n > 0)
		return h->H[0].key;
	else
		return HEAP_FAILURE;
}

// removes the root, returns the data index to it, and re-heapifies
// to remove_min:
//    - swap heap elements at 0 and n-1
//    - update h->n 
//    - use siftdown to make sure that H[0] now is the min
//    - return dataindex of H[n]      
int remove_min(Heap *h) { 
	error("remove_min");
	return 1;
}                           

// adds delta to the key of dataIndex
void 
change_key(Heap *h, int dataIndex, int delta) { 
	int i = h->map[dataIndex];   // the index of dataIndex in h->H 
	h->H[i].key += delta;
	if (delta < 0) 
		siftup(h, i);
	else if (delta > 0) 
		siftdown(h, i);
} 

// free any memory you might of alloced in heap creation
void 
destroy_heap(Heap *h) {
	if (h == NULL) return;
	if (h->size > 0) {
		free(h->map);
		free(h->H);
	}
	free(h);
}

// debug
void
print_heap(Heap *h) {
	if (h == NULL) return;

	int i;
	printf("---------------------------\n");
	printf("keys: ");
	for(i = 0 ; i < h->n ; i++)
		printf("%5.0f ", h->H[i].key);
	printf("\n");
	printf("di  : ");
	for(i = 0 ; i < h->n ; i++)
		printf("%5d ", h->H[i].dataIndex);
	printf("\n");
	printf("map : ");
	for(i = 0 ; i < h->n ; i++)
		printf("%5d ", h->map[i]);
	printf("\n");
}
