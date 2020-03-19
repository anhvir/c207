#ifndef STACK_H
#define STACK_H

#include "listops.h"



typedef list_t stack_adt;

stack_adt *new_stack();
int pop(stack_adt *);
void push(stack_adt *, int);
int is_empty_stack(stack_adt *);
int stack_size(stack_adt *);
void free_stack(stack_adt *);

#endif
