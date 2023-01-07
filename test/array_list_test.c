#include "array_list_test.h"

void array_list_test() {
  struct array_list *list = array_list_initialization();
  assert(list->size == 0);
  array_list_add(list, (void *)'a');
  array_list_add(list, (void *)'b');
  array_list_add(list, (void *)'c');
  array_list_add(list, (void *)'d');
  array_list_add(list, (void *)'e');
  array_list_add(list, (void *)'f');
  assert(list->size == 6);
  assert(array_list_get(list, 0) == (void *)'a');
  assert(array_list_get(list, 1) == (void *)'b');
  assert(array_list_get(list, 2) == (void *)'c');
  assert(array_list_get(list, 3) == (void *)'d');
  assert(array_list_get(list, 4) == (void *)'e');
  assert(array_list_get(list, 5) == (void *)'f');
  array_list_add(list, (void *)'a');
  assert(array_list_get(list, 6) == (void *)'a');
  assert(list->size == 7);
  array_list_remove(list, 6);
  assert(list->size == 6);
  assert(array_list_get(list, 6) == NULL);

  for (size_t index = 0; index < 100; index++) {
    array_list_add(list, (void *)index);
  }
  assert(list->size == 106);
  assert(array_list_get(list, 100) == (void *)94);
  assert(array_list_get(list, 101) == (void *)95);
  array_list_remove(list, 100);
  assert(list->size == 105);
  assert(array_list_get(list, 100) == (void *)95);
}
