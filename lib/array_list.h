#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__

#include <stdbool.h>
#include <stdlib.h>

#include "linked_list.h"

#define ARRAY_LIST_INITIAL_CAPACITY 10

struct array_list {
  void** data;
  size_t size;
  size_t capacity;
};

struct array_list* array_list_initialization();

void array_list_add(struct array_list* list, void* element);

void array_list_remove(struct array_list* list, size_t index);

void* array_list_get(struct array_list* list, size_t index);

#endif
