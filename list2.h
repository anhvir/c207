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

#ifndef _LIST2_H_
#define _LIST2_H_

#include <stdbool.h>
#include "data_type.h"

typedef struct list List;

typedef struct list_iterator ListIterator;

// create a new list and return its pointer
List *new_list();

// destroy a list and free its memory
void free_list(List *list);

// add an element to the front of a list
// this operation is O(1)
void list_add_start(List *list, data_t data);

// add an element to the back of a list
// this operation is O(1)
void list_add_end(List *list, data_t data);

// remove and return the front data element from a list
// this operation is O(1)
data_t list_remove_start(List *list);

// remove and return the final data element in a list
// this operation is O(n), where n is the number of elements in the list
data_t list_remove_end(List *list);

// return the number of elements contained in a list
int list_size(List *list);

// returns whether the list contains no elements (true) or some elements (false)
bool list_is_empty(List *list);

// returns whether the list contains the specified element.
// this operation is O(n)
bool list_contains(List *list, int id);

// returns a new iterator
ListIterator *new_list_iterator(List *list);

// frees the list iterator
void free_list_iterator(ListIterator *iterator);

// whether or not there are elements remaining to be iterated through
bool list_iterator_has_next(ListIterator *iterator);

// get's the next element in the list
data_t list_iterator_next(ListIterator *iterator);

void print_list(List *);

// remove and return the data with min weight
data_t list_remove_end(List *list);

// update weight for the element in list
// return true if successful (ie element exists)  
bool list_update(List *l, data_t data);

// remove and return the data with min weight
data_t list_remove_min(List *l); 

// copy element of list to an array
// returns number of element in array
// supposing that array is large enough
int list_2_array(List *l, data_t A[]);

#endif
