#ifndef __LIBCPROJECT_ARRAY_LIST__
#define __LIBCPROJECT_ARRAY_LIST__

#include <stdbool.h>
#include <stdlib.h>

#include "types.h"

#define ARRAY_LIST_INITIAL_CAPACITY 10

/**
 * @brief A dynamic array implementation.
 * @since v1.2.0
 */
struct array_list {
  void** data;
  size_t size;
  size_t capacity;
};

/**
 * @brief Initializes a new array list.
 * @since v1.2.0
 */
struct array_list* array_list_initialization();

/**
 * @brief Adds an element to the end of the array list.
 * @since v1.2.0
 */
void array_list_add(struct array_list* list, void* element);

/**
 * @brief Removes an element from the array list.
 * @since v1.2.0
 */
void array_list_remove(struct array_list* list, size_t index);

/**
 * @brief Gets an element from the array list.
 * @since v1.2.0
 */
void* array_list_get(struct array_list* list, size_t index);

#endif
