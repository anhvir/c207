/*  Module: priorityqueue
	Dependencies: list2 , data_type

	Simple implementation of priority queue using linked list
	NOTE: main operations have compexity O(n), not O(log n)

	Created by Anh Vo, anhvir@gmail.com, for comp20007_2018s1 week 7
*/

#ifndef _PRIORITYQUEUE_H_
#define _PRIORITYQUEUE_H_

#include "list2.h"

typedef List pq_t;

// create a new priority queue
pq_t *new_pq();

// free pq memory
void free_pq(pq_t *pq);

// insert (id, weight) into the queue
void pq_enqueue(pq_t *pq, int id, double weight);

// remove the element with the lowest priority and return the key
int pq_remove_min(pq_t *pq);

// update element id in pq, with new_weight 
// returns true if successful (ie. if id is in the pq) 
bool pq_update(pq_t *pq, int id, double new_weight);

// returns true the queue is empty
bool pq_is_empty(pq_t *pq);


#endif
