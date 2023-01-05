#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdlib.h>

struct linked_list {
  // first node of the list
  struct linked_list_node *head;

  size_t length;
};

struct linked_list_node {
  void *data;
  struct linked_list_node *next;
};

struct linked_list *linked_list_initialization();

struct linked_list_node *linked_list_add_in_head(struct linked_list *list, void *new_value);

void linked_list_delete_in_head(struct linked_list *list);

struct linked_list_node *linked_list_add_after_last(struct linked_list *list, void *new_data);

struct linked_list *linked_list_reverse(struct linked_list *list);

void linked_list_reverse_mutate(struct linked_list *list);

#endif
