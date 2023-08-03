#include "queue.h"

struct queue *queue_initialization() {
  struct queue *queue = malloc(sizeof(*queue));
  if (queue == NULL) {
    exit(EXIT_FAILURE);
  }
  queue->first = NULL;
  queue->length = 0;
  return queue;
}

void queue_push(struct queue *queue, void *data) {
  struct queue_node *node_new = malloc(sizeof(*node_new));
  if (queue == NULL || node_new == NULL) {
    exit(EXIT_FAILURE);
  }
  node_new->data = data;
  node_new->next = NULL;
  if (queue->first != NULL) {
    struct queue_node *node_current = queue->first;
    while (node_current->next != NULL) {
      node_current = node_current->next;
    }
    node_current->next = node_new;
  } else {
    queue->first = node_new;
  }
  queue->length = queue->length + 1;
}

void *queue_pop(struct queue *queue) {
  if (queue == NULL) {
    exit(EXIT_FAILURE);
  }
  struct queue_node *node = queue->first;
  void *data = NULL;
  if (node != NULL) {
    queue->first = node->next;
    data = node->data;
    free(node);
  }
  queue->length = queue->length - 1;
  return data;
}

void queue_free(struct queue *queue) {
  if (queue == NULL) {
    exit(EXIT_FAILURE);
  }
  struct queue_node *node = queue->first;
  while (node != NULL) {
    struct queue_node *node_next = node->next;
    free(node);
    node = node_next;
  }
  free(queue);
}
