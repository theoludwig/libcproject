#ifndef __STACK__
#define __STACK__

#include <stdlib.h>

// LIFO = Last In First Out
struct stack {
  struct stack_node *first;
  size_t length;
};

struct stack_node {
  void *data;
  struct stack_node *next;
};

struct stack *stack_initialization();

void stack_push(struct stack *stack, void *data);

void *stack_pop(struct stack *stack);

#endif
