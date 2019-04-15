/* list2:
   Module for creating and manipulating singly-linked lists of
        data_t elements

   Dependencies: data_type.c, data_type.h  
    

   Created by Anh Vo <anhvir@gmail.com>
   Based on the original module "list" which was:
 * created for COMP20007 Design of Algorithms 2017
 * by Matt Farrugia <matt.farrugia@unimelb.edu.au>
 *
 * list_contains(), ListIterator created for COMP20007 2019 Workshop 4
 * by Tobias Edwards <tobias.edwards@unimelb.edu.au>
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list2.h"

typedef struct node Node;

// a list node points to the next node in the list, and to some data
struct node {
	Node *next;
	data_t data;
};

// a list points to its first and last nodes, and stores its size (num. nodes)
struct list {
	Node *head;
	Node *tail;
	int size;
};

// helper function to create a new node and return its address
Node *new_node();

// helper function to clear memory of a node (does not free the node's data)
void free_node(Node *node);

// a list iterator is a helper data structure to iterate through a list,
// this is required to avoid exposing the underlying node structure of the
// list to the user
struct list_iterator {
	Node *next;
};

/* * * *
 * FUNCTION DEFINITIONS
 */

// create a new list and return a pointer to it
List *new_list() {
	List *list = malloc(sizeof *list);
	assert(list);

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

// destroy a list and free its memory
void free_list(List *list) {
	assert(list != NULL);
	// free each node
	Node *node = list->head;
	Node *next;
	while (node) {
		next = node->next;
		free_node(node);
		node = next;
	}
	// free the list struct itself
	free(list);
}

// helper function to create a new node and return its address
Node *new_node() {
	Node *node = malloc(sizeof *node);
	assert(node);

	return node;
}

// helper function to clear memory of a node
void free_node(Node *node) {
	free(node);
}

// add an element to the front of a list
// this operation is O(1)
void list_add_start(List *list, data_t data) {
	assert(list != NULL);

	// create and initialise a new list node
	Node *node = new_node();
	node->data = data;
	node->next = list->head; // next will be the old first node (may be null)

	// place it at the start of the list
	list->head = node;

	// if list was empty, this new node is also the last node now
	if(list->size == 0) {
		list->tail = node;
	}

	// and we need to keep size updated!
	list->size++;
}

// add an element to the back of a list
// this operation is O(1)
void list_add_end(List *list, data_t data) {
	assert(list != NULL);

	// we'll need a new list node to store this data
	Node *node = new_node();
	node->data = data;
	node->next = NULL; // as the last node, there's no next node

	if(list->size == 0) {
		// if the list was empty, new node is now the first node
		list->head = node;
	} else {
		// otherwise, it goes after the current last node
		list->tail->next = node;
	}

	// place this new node at the end of the list
	list->tail = node;

	// and keep size updated too
	list->size++;
}

// remove and return the front data element from a list
// this operation is O(1)
// error if the list is empty (so first ensure list_size() > 0)
data_t list_remove_start(List *list) {
	assert(list != NULL);
	assert(list->size > 0);

	// we'll need to save the data to return it
	Node *start_node = list->head;
	data_t data = start_node->data;

	// then replace the head with its next node (may be null)
	list->head = list->head->next;

	// if this was the last node in the list, the tail also needs to be cleared
	if(list->size == 1) {
		list->tail = NULL;
	}

	// the list is now one node smaller
	list->size--;

	// and we're finished with the node holding this data
	free_node(start_node);

	// done!
	return data;
}

// remove and return the final data element in a list
// this operation is O(n), where n is the number of elements in the list
// error if the list is empty (so first ensure list_size() > 0)
data_t list_remove_end(List *list) {
	assert(list != NULL);
	assert(list->size > 0);

	// we'll need to save the data to return it
	Node *end_node = list->tail;
	data_t data = end_node->data;

	// then replace the tail with the second-last node (may be null)
	// (to find this replacement, we'll need to walk the list --- the O(n) bit
	Node *node = list->head;
	Node *prev = NULL;
	while (node->next) {
		prev = node;
		node = node->next;
	}
	list->tail = prev;

	if(list->size == 1) {
		// if we're removing the last node, the head also needs clearing
		list->head = NULL;
	} else {
		// otherwise, the second-last node needs to drop the removed last node
		prev->next = NULL;
	}

	// the list just got one element shorter
	list->size--;

	// we're finished with the list node holding this data
	free_node(end_node);

	// done!
	return data;
}

// return the number of elements contained in a list
int list_size(List *list) {
	assert(list != NULL);
	return list->size;
}

// returns whether the list contains no elements (true) or some elements (false)
bool list_is_empty(List *list) {
	assert(list != NULL);
	return (list->size==0);
}

// returns whether the list contains the specified element id.
// this operation is O(n)
bool list_contains(List *list, int id) {
  assert(list != NULL);

  Node *node = list->head;
  while (node != NULL) {
    if (node->data.id == id) {
      return true;
    }
    node = node->next;
  }

  // if we get here without returning true then the element must not be
  // contained in the list
  return false;
}

// returns a new iterator
ListIterator *new_list_iterator(List *list) {
  ListIterator *iterator = malloc(sizeof(*iterator));
  assert(iterator);

  iterator->next = list->head;

  return iterator;
}

// frees the list iterator
void free_list_iterator(ListIterator *iterator) {
  assert(iterator != NULL);

  free(iterator);
}

// whether or not there are elements remaining to be iterated through
bool list_iterator_has_next(ListIterator *iterator) {
  assert(iterator != NULL);

  return (iterator->next != NULL);
}

// get's the next element in the list
data_t list_iterator_next(ListIterator *iterator) {
  assert(iterator != NULL);
  // User should call has_next() before calling this, otherwise we'll abort
  assert(iterator->next != NULL);

  // Save the value for later
  data_t value = iterator->next->data;

  // Move the pointer along the linked list
  iterator->next = iterator->next->next;

  return value;
}


/******************************************
   The remaining functions were created by anhvir@gmail.com
   for implementing naive priority queue
***********************************************/

// print a list in format data->data->...
void print_list(List *l) {
	Node *n= l->head;
	while (n) {
		print_data(&(n->data));
		n= n->next;
		if (n) printf(" -> ");
	}
	printf("\n");
}

// remove and return the data with min weight
data_t list_remove_min(List *l) {
	Node **pp, **min= &(l->head);
	data_t d;
	assert(l->size > 0);

	// make *min the one that points to min element
	for (pp= &(l->head); *pp ; pp= &((*pp)->next)) {
		if ((*min)->data.weight > (*pp)->data.weight) {
			min= pp; 
		}
	}
	
	// keep *min for freeing later
	Node *ppp= *min;

	// cut off *min from the list chain
	*min= (*min)->next;
	l->size--;

	// special case when list becomes NULL
	if (l->head==NULL) {
		l->tail= NULL;
	}

	d= ppp->data;
	free(ppp);

	return d;
}


// update weight for the element in list
// return true if successful (ie element exists)
bool list_update(List *l, data_t data) {
	Node *p;
	// find the element and change weight
	// assuming no duplication of element id inside the list
	for (p=l->head; p ; p= p->next) {
		if (p->data.id == data.id) {
			p->data.weight= data.weight;
			return true;
		}
	}

	return false;
}


// copy element of list to an array
// returns number of element in array
// supposing that array is large enough
int list_2_array(List *l, data_t A[]) {
	Node *p=  l->head;
	int i;
	for (i=0; p; p= p->next, i++) 
		A[i]= p->data;
	return i;
}
