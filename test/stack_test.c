#include "stack_test.h"

void stack_test() {
  stack_initialization_test();
  stack_push_test();
  stack_pop_test();
}

void stack_initialization_test() {
  struct stack *stack = stack_initialization();
  assert(stack->length == 0);
  assert(stack->first == NULL);
}

void stack_push_test() {
  struct stack *stack = stack_initialization();
  stack_push(stack, (void *)4);
  stack_push(stack, (void *)8);
  stack_push(stack, (void *)15);
  assert(stack->length == 3);
  assert(((uintptr_t)stack->first->data) == 15);
  assert(((uintptr_t)stack->first->next->data) == 8);
  assert(((uintptr_t)stack->first->next->next->data) == 4);
  assert(stack->first->next->next->next == NULL);
}

void stack_pop_test() {
  struct stack *stack = stack_initialization();
  stack_push(stack, (void *)4);
  stack_push(stack, (void *)8);
  stack_push(stack, (void *)15);
  void *node = stack_pop(stack);
  assert(stack->length == 2);
  assert(((uintptr_t)node) == 15);
  assert(((uintptr_t)stack->first->data) == 8);
  assert(((uintptr_t)stack->first->next->data) == 4);
  assert(stack->first->next->next == NULL);
}
