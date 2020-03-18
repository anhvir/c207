#ifndef LISTOPS_H
#define LISTOPS_H

 
typedef struct node node_t;
typedef struct list list_t;
typedef int data_t;

list_t
*make_empty_list(void);

int
is_empty_list(list_t *list);

void
free_list(list_t *list);

list_t
*insert_at_head(list_t *list, data_t value);

list_t
*insert_at_foot(list_t *list, data_t value);

data_t
get_head(list_t *list);

data_t
remove_head(list_t *list);

list_t
*get_tail(list_t *list);

// the last function is added by avo
int
list_size(list_t *list);

#endif
