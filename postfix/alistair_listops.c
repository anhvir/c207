//typedef struct node node_t;
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "listops.h"

struct node {
	data_t data;
	node_t *next;
};

struct list {
	node_t *head;
	node_t *foot;
};

list_t
*make_empty_list(void) {
	list_t *list;
	list = (list_t*)malloc(sizeof(*list));
	assert(list!=NULL);
	list->head = list->foot = NULL;
	return list;
}

int
is_empty_list(list_t *list) {
	assert(list!=NULL);
	return list->head==NULL;
}

void
free_list(list_t *list) {
	node_t *curr, *prev;
	assert(list!=NULL);
	curr = list->head;
	while (curr) {
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(list);
}

list_t
*insert_at_head(list_t *list, data_t value) {
	node_t *new;
	new = (node_t*)malloc(sizeof(*new));
	assert(list!=NULL && new!=NULL);
	new->data = value;
	new->next = list->head;
	list->head = new;
	if (list->foot==NULL) {
		/* this is the first insertion into the list */
		list->foot = new;
	}
	return list;
}

list_t
*insert_at_foot(list_t *list, data_t value) {
	node_t *new;
	new = (node_t*)malloc(sizeof(*new));
	assert(list!=NULL && new!=NULL);
	new->data = value;
	new->next = NULL;
	if (list->foot==NULL) {
		/* this is the first insertion into the list */
		list->head = list->foot = new;
	} else {
		list->foot->next = new;
		list->foot = new;
	}
	return list;
}

data_t
get_head(list_t *list) {
	assert(list!=NULL && list->head!=NULL);
	return list->head->data;
}

/* added by avo, not yet tested for correctness */
data_t
remove_head(list_t *list) {
	assert(list!=NULL && list->head!=NULL);
	data_t out= list->head->data;

	node_t *oldhead= list->head;
	list->head = list->head->next;
	if (list->head==NULL) {
		/* the only list node just got deleted */
		list->foot = NULL;
	}
	free(oldhead);

	return out;
}

/* added by avo, not yet tested for correctness */
data_t
list_size(list_t *list) {
	assert(list!=NULL);
	int size= 0;
	node_t *p= list->head;
	while (p) {
		size++;
		p= p->next;
	}
	return size;
}

list_t
*get_tail(list_t *list) {
	node_t *oldhead;
	assert(list!=NULL && list->head!=NULL);
	oldhead = list->head;
	list->head = list->head->next;
	if (list->head==NULL) {
		/* the only list node just got deleted */
		list->foot = NULL;
	}
	free(oldhead);
	return list;
}

/* =====================================================================
   Program written by Alistair Moffat, as an example for the book
   "Programming, Problem Solving, and Abstraction with C", Pearson
   Custom Books, Sydney, Australia, 2002; revised edition 2012,
   ISBN 9781486010974.

   See http://people.eng.unimelb.edu.au/ammoffat/ppsaa/ for further
   information.

   Prepared December 2012 for the Revised Edition.
   ================================================================== */
