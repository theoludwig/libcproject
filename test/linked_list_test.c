#include "linked_list_test.h"

void linked_list_test() {
  linked_list_initialization_test();
  linked_list_add_in_head_test();
  linked_list_delete_in_head_test();
  linked_list_add_after_last_test();
  linked_list_reverse_test();
  linked_list_reverse_mutate_test();
}

void linked_list_initialization_test() {
  struct linked_list *list = linked_list_initialization();
  assert(list->length == 0);
  assert(list->head == NULL);
  linked_list_free(list);
}

void linked_list_add_in_head_test() {
  struct linked_list *list = linked_list_initialization();
  linked_list_add_in_head(list, (void *)4);
  linked_list_add_in_head(list, (void *)8);
  linked_list_add_in_head(list, (void *)15);
  assert(list->length == 3);
  assert(((uintptr_t)list->head->data) == 15);
  assert(((uintptr_t)list->head->next->data) == 8);
  assert(((uintptr_t)list->head->next->next->data) == 4);
  assert(list->head->next->next->next == NULL);
  linked_list_free(list);
}

void linked_list_delete_in_head_test() {
  struct linked_list *list = linked_list_initialization();
  linked_list_add_in_head(list, (void *)4);
  linked_list_add_in_head(list, (void *)8);
  linked_list_add_in_head(list, (void *)15);
  linked_list_delete_in_head(list);
  assert(list->length == 2);
  assert(((uintptr_t)list->head->data) == 8);
  assert(((uintptr_t)list->head->next->data) == 4);
  assert(list->head->next->next == NULL);
  linked_list_free(list);
}

void linked_list_add_after_last_test() {
  struct linked_list *list = linked_list_initialization();
  linked_list_add_in_head(list, (void *)4);
  linked_list_add_in_head(list, (void *)8);
  linked_list_add_in_head(list, (void *)15);
  assert(list->length == 3);
  assert(((uintptr_t)list->head->data) == 15);
  assert(((uintptr_t)list->head->next->data) == 8);
  assert(((uintptr_t)list->head->next->next->data) == 4);
  linked_list_add_after_last(list, (void *)18);
  assert(list->length == 4);
  assert(((uintptr_t)list->head->data) == 15);
  assert(((uintptr_t)list->head->next->data) == 8);
  assert(((uintptr_t)list->head->next->next->data) == 4);
  assert(((uintptr_t)list->head->next->next->next->data) == 18);
  linked_list_free(list);
}

void linked_list_reverse_test() {
  struct linked_list *list = linked_list_initialization();
  linked_list_add_after_last(list, (void *)'A');
  linked_list_add_after_last(list, (void *)'B');
  linked_list_add_after_last(list, (void *)'C');
  linked_list_add_after_last(list, (void *)'D');
  assert(list->length == 4);
  struct linked_list *list_reversed = linked_list_reverse(list);
  assert(list->length == 4);
  assert((list->head->data) == (void *)'A');
  assert((list->head->next->data) == (void *)'B');
  assert((list->head->next->next->data) == (void *)'C');
  assert((list->head->next->next->next->data) == (void *)'D');
  assert(list_reversed->length == 4);
  assert((list_reversed->head->data) == (void *)'D');
  assert((list_reversed->head->next->data) == (void *)'C');
  assert((list_reversed->head->next->next->data) == (void *)'B');
  assert((list_reversed->head->next->next->next->data) == (void *)'A');
  linked_list_free(list);
}

void linked_list_reverse_mutate_test() {
  struct linked_list *list = linked_list_initialization();
  linked_list_add_after_last(list, (void *)'A');
  linked_list_add_after_last(list, (void *)'B');
  linked_list_add_after_last(list, (void *)'C');
  linked_list_add_after_last(list, (void *)'D');
  assert(list->length == 4);
  linked_list_reverse_mutate(list);
  assert(list->length == 4);
  assert((list->head->data) == (void *)'D');
  assert((list->head->next->data) == (void *)'C');
  assert((list->head->next->next->data) == (void *)'B');
  assert((list->head->next->next->next->data) == (void *)'A');
  linked_list_free(list);
}
