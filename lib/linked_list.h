#ifndef __LIBCPROJECT_LINKED_LIST__
#define __LIBCPROJECT_LINKED_LIST__

#include <errno.h>
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
 *
 * @return struct linked_list*
 * @since v1.0.0
 */
struct linked_list *linked_list_initialization();

/**
 * @brief Add a new node in the head of the linked list.
 *
 * @param list
 * @param new_value
 * @return struct linked_list_node*
 * @since v1.0.0
 */
struct linked_list_node *linked_list_add_in_head(struct linked_list *list, void *new_value);

/**
 * @brief Delete node in the head of the linked list.
 *
 * @param list
 * @since v1.0.0
 */
void linked_list_delete_in_head(struct linked_list *list);

/**
 * @brief Add a new node in the tail of the linked list.
 *
 * @param list
 * @param new_data
 * @return struct linked_list_node*
 * @since v1.0.0
 */
struct linked_list_node *linked_list_add_after_last(struct linked_list *list, void *new_data);

/**
 * @brief Reverse the linked list by creating a new one.
 *
 * @param list
 * @return struct linked_list*
 * @since v1.0.0
 */
struct linked_list *linked_list_reverse(struct linked_list *list);

/**
 * @brief Reverse the linked list by mutating it.
 *
 * @param list
 * @since v1.0.0
 */
void linked_list_reverse_mutate(struct linked_list *list);

/**
 * @brief Frees the linked list.
 *
 * @param list
 * @since v3.0.0
 */
void linked_list_free(struct linked_list *list);

#endif
