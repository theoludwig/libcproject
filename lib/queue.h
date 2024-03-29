#ifndef __LIBCPROJECT_QUEUE__
#define __LIBCPROJECT_QUEUE__

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "types.h"

/**
 * @brief Queue structure => FIFO (First In First Out).
 * @since v1.0.0
 */
struct queue {
  struct queue_node *first;
  size_t length;
};

/**
 * @brief Queue node structure.
 * @since v1.0.0
 */
struct queue_node {
  void *data;
  struct queue_node *next;
};

/**
 * @brief Queue initialization.
 *
 * @return struct queue*
 * @since v1.0.0
 */
struct queue *queue_initialization();

/**
 * @brief Push data to queue.
 *
 * @param queue
 * @param data
 * @since v1.0.0
 */
void queue_push(struct queue *queue, void *data);

/**
 * @brief Pop data from queue.
 *
 * @param queue
 * @return void*
 * @since v1.0.0
 */
void *queue_pop(struct queue *queue);

/**
 * @brief Frees the queue.
 *
 * @param queue
 * @since v3.0.0
 */
void queue_free(struct queue *queue);

#endif
