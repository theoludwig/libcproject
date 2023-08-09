#ifndef __LIBCPROJECT_STACK__
#define __LIBCPROJECT_STACK__

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

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
 *
 * @return struct stack*
 * @since v1.0.0
 */
struct stack *stack_initialization();

/**
 * @brief Push data to stack.
 *
 * @param stack
 * @param data
 * @since v1.0.0
 */
void stack_push(struct stack *stack, void *data);

/**
 * @brief Pop data from stack.
 *
 * @param stack
 * @return void*
 * @since v1.0.0
 */
void *stack_pop(struct stack *stack);

/**
 * @brief Frees the stack.
 *
 * @param stack
 * @since v3.0.0
 */
void stack_free(struct stack *stack);

#endif
