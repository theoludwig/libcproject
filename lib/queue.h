#ifndef __QUEUE__
#define __QUEUE__

#include <stdio.h>
#include <stdlib.h>

// FIFO = First In First Out
struct queue {
  struct queue_node *first;
  size_t length;
};

struct queue_node {
  void *data;
  struct queue_node *next;
};

struct queue *queue_initialization();

void queue_push(struct queue *queue, void *data);

void *queue_pop(struct queue *queue);

#endif
