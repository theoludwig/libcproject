#ifndef __STACK__
#define __STACK__

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Stack structure => LIFO (Last In First Out).
 * @since v1.0.0
 */
struct stack {
  struct stack_node *first;
  size_t length;
};

/**
 * @brief Stack node structure.
 * @since v1.0.0
 */
struct stack_node {
  void *data;
  struct stack_node *next;
};

/**
 * @brief Stack initialization.
 * @since v1.0.0
 */
struct stack *stack_initialization();

/**
 * @brief Push data to stack.
 * @since v1.0.0
 */
void stack_push(struct stack *stack, void *data);

/**
 * @brief Pop data from stack.
 * @since v1.0.0
 */
void *stack_pop(struct stack *stack);

#endif
