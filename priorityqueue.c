/*  Module: priorityqueue
	Dependencies: list2 , data_type

	Simple implementation of priority queue using linked list
	NOTE: main operations have compexity O(n), not O(log n)

	Created by Anh Vo, anhvir@gmail.com, for comp20007_2018s1 week 7
*/

#include "priorityqueue.h"

// create a new priority queue
pq_t *new_pq() {
	return new_list();
}

// free pq memory
void free_pq(pq_t *pq) {
	free_list(pq);
}

// insert (id, weight) into the queue
void pq_enqueue(pq_t *pq, int id, double weight) {
	list_add_start(pq, make_data(id, weight));
}

// remove the element with the lowest priority and return the key
int pq_remove_min(pq_t *pq) {
	data_t d= list_remove_min(pq);
	return d.id;
}

// update element id in pq, with new_weight 
// returns true if successful (ie. if id is in the pq) 
bool pq_update(pq_t *pq, int id, double new_weight) {
	return list_update(pq, make_data(id, new_weight));
}

// returns true the queue is empty
bool pq_is_empty(pq_t *pq) {
	return list_is_empty(pq);
}
