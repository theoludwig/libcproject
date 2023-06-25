#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"
#include "types.h"

/**
 * @brief Linked list data structure.
 * @since v1.0.0
 */
struct linked_list {
  struct linked_list_node *head;

  size_t length;
};

/**
 * @brief Linked list node data structure.
 * @since v1.0.0
 */
struct linked_list_node {
  void *data;
  struct linked_list_node *next;
};

/**
 * @brief Linked list initialization.
 * @since v1.0.0
 */
struct linked_list *linked_list_initialization();

/**
 * @brief Add a new node in the head of the linked list.
 * @since v1.0.0
 */
struct linked_list_node *linked_list_add_in_head(struct linked_list *list, void *new_value);

/**
 * @brief Delete node in the head of the linked list.
 * @since v1.0.0
 */
void linked_list_delete_in_head(struct linked_list *list);

/**
 * @brief Add a new node in the tail of the linked list.
 * @since v1.0.0
 */
struct linked_list_node *linked_list_add_after_last(struct linked_list *list, void *new_data);

/**
 * @brief Reverse the linked list by creating a new one.
 * @since v1.0.0
 */
struct linked_list *linked_list_reverse(struct linked_list *list);

/**
 * @brief Reverse the linked list by mutating it.
 * @since v1.0.0
 */
void linked_list_reverse_mutate(struct linked_list *list);

#endif
