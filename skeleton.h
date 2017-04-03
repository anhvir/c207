/*
   heap.c, heap.h: implementation of min heap,
             allowing random access to heap using index of data payload

   Skeleton plus some implementation for COMP20007 Lab Week 5
   Prepared by Anh Vo (anhvir@gmail.com), 02 Apr 2017
   Based on the originals by:
** Andrew Turpin
** Wed  3 Apr 2013 13:47:20 EST
*/

#ifndef _HEAP_H_
#define _HEAP_H_


#define HEAP_SUCCESS 1
#define HEAP_FAILURE  0

typedef struct heap Heap;

// returns a pointer to a new, empty heap
Heap *create_heap(void); 

// inserts (dataIndex,key) into h
int insert(Heap *h, int dataIndex, float key);

// returns the data index of the root.
int peek(Heap *h);

// returns the key of the root.
int peek_key(Heap *h);

// removes the root, returns the data index to it, and re-heapifies 
int remove_min(Heap *h);
 
// adds delta to the key of dataIndex
void change_key(Heap *h, int dataIndex, int delta);

// free any memory you might of alloced in heap creation
void destroy_heap(Heap *h);

void print_heap(Heap *h);

#endif
