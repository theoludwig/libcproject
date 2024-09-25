#ifndef __LIBCPROJECT_ARRAY_LIST__
#define __LIBCPROJECT_ARRAY_LIST__

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
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
  size_t capacity_step;
};

/**
 * @brief Initializes a new array list.
 * @since v1.2.0
 */
struct array_list* array_list_initialization();

/**
 * @brief Initializes a new array list with a capacity.
 * @since v5.0.0
 */
struct array_list* array_list_initialization_with_capacity(size_t capacity);

/**
 * @brief Adds an element to the end of the array list.
 *
 * @param list
 * @param element
 * @since v1.2.0
 */
void array_list_add(struct array_list* list, void* element);

/**
 * @brief Removes an element from the array list.
 *
 * @param list
 * @param index
 * @since v1.2.0
 */
void array_list_remove(struct array_list* list, size_t index);

/**
 * @brief Gets an element from the array list.
 *
 * @param list
 * @param index
 * @return void*
 * @since v1.2.0
 */
void* array_list_get(struct array_list* list, size_t index);

/**
 * @brief Frees the array list.
 *
 * @param list
 * @since v3.0.0
 */
void array_list_free(struct array_list* list);

#endif
