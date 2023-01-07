#include "queue_test.h"

void queue_test() {
  queue_initialization_test();
  queue_push_test();
  queue_pop_test();
}

void queue_initialization_test() {
  struct queue *queue = queue_initialization();
  assert(queue->length == 0);
  assert(queue->first == NULL);
}

void queue_push_test() {
  struct queue *queue = queue_initialization();
  queue_push(queue, (void *)4);
  queue_push(queue, (void *)8);
  queue_push(queue, (void *)15);
  assert(queue->length == 3);
  assert(((uintptr_t)queue->first->data) == 4);
  assert(((uintptr_t)queue->first->next->data) == 8);
  assert(((uintptr_t)queue->first->next->next->data) == 15);
  assert(queue->first->next->next->next == NULL);
}

void queue_pop_test() {
  struct queue *queue = queue_initialization();
  queue_push(queue, (void *)4);
  queue_push(queue, (void *)8);
  queue_push(queue, (void *)15);
  void *node = queue_pop(queue);
  assert(queue->length == 2);
  assert(((uintptr_t)node) == 4);
  assert(((uintptr_t)queue->first->data) == 8);
  assert(((uintptr_t)queue->first->next->data) == 15);
  assert(queue->first->next->next == NULL);
}
