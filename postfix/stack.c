#include "stack.h"

stack_adt *new_stack() {
	return make_empty_list();
}

int pop(stack_adt *s) {
	return remove_head(s);
}

void push(stack_adt *s, int x) {
	insert_at_head(s, x);
}

int is_empty_stack(stack_adt *s) {
	return is_empty_list(s);
}

int stack_size(stack_adt *s) {
	return list_size(s);
}

void free_stack(stack_adt *s) {
	free_list(s);
}
