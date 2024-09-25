#ifndef __LIBCPROJECT_TERMINAL__
#define __LIBCPROJECT_TERMINAL__

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"
#include "character.h"
#include "hash_map.h"
#include "linked_list.h"
#include "queue.h"
#include "stack.h"
#include "types.h"

/**
 * @brief Read a line from stdin.
 *
 * @return string_t
 * @since v1.0.0
 */
string_t terminal_input();

/**
 * @brief Print a int.
 *
 * @param value
 * @since v1.0.0
 */
void terminal_print_int(void* value);

/**
 * @brief Print a boolean.
 *
 * @param value
 * @since v5.0.0
 */
void terminal_print_bool(void* value);

/**
 * @brief Print a long.
 *
 * @param value
 * @since v1.0.0
 */
void terminal_print_long(void* value);

/**
 * @brief Print a unsigned long.
 *
 * @param value
 * @since v1.0.0
 */
void terminal_print_unsigned_long(void* value);

/**
 * @brief Print a float.
 *
 * @param value
 * @since v5.0.0
 */
void terminal_print_float(void* value);

/**
 * @brief Print a double.
 *
 * @param value
 * @since v5.0.0
 */
void terminal_print_double(void* value);

/**
 * @brief Print a int8_t.
 *
 * @param value
 * @since v5.0.0
 */
void terminal_print_int8_t(void* value);

/**
 * @brief Print a int16_t.
 *
 * @param value
 * @since v5.0.0
 */
void terminal_print_int16_t(void* value);

/**
 * @brief Print a int32_t.
 *
 * @param value
 * @since v5.0.0
 */
void terminal_print_int32_t(void* value);

/**
 * @brief Print a int64_t.
 *
 * @param value
 * @since v5.0.0
 */
void terminal_print_int64_t(void* value);

/**
 * @brief Print a uint8_t.
 *
 * @param value
 * @since v5.0.0
 */
void terminal_print_uint8_t(void* value);

/**
 * @brief Print a uint16_t.
 *
 * @param value
 * @since v5.0.0
 */
void terminal_print_uint16_t(void* value);

/**
 * @brief Print a uint32_t.
 *
 * @param value
 * @since v5.0.0
 */
void terminal_print_uint32_t(void* value);

/**
 * @brief Print a uint64_t.
 *
 * @param value
 * @since v5.0.0
 */
void terminal_print_uint64_t(void* value);

/**
 * @brief Print a char.
 *
 * @param value
 * @since v1.0.0
 */
void terminal_print_char(void* value);

/**
 * @brief Print an array.
 *
 * @param array
 * @param array_size
 * @param element_size
 * @param print_element
 * @since v1.0.0
 */
void terminal_print_array(void* array, size_t array_size, size_t element_size, void (*print_element)(void*));

/**
 * @brief Print a string.
 *
 * @param value
 * @since v1.0.0
 */
void terminal_print_string(void* value);

/**
 * @brief Print a stack.
 *
 * @param stack
 * @param print_element
 * @since v1.0.0
 */
void terminal_print_stack(struct stack* stack, void (*print_element)(void*));

/**
 * @brief Print a queue.
 *
 * @param queue
 * @param print_element
 * @since v1.0.0
 */
void terminal_print_queue(struct queue* queue, void (*print_element)(void*));

/**
 * @brief Print a linked list.
 *
 * @param linked_list
 * @param print_element
 * @since v1.0.0
 */
void terminal_print_linked_list(struct linked_list* linked_list, void (*print_element)(void*));

/**
 * @brief Print a hash map.
 *
 * @param hash_map
 * @param print_element
 * @since v2.0.0
 */
void terminal_print_hash_map(struct hash_map* hash_map, void (*print_element)(void*));

/**
 * @brief Print an array list.
 *
 * @param list
 * @param print_element
 * @since v3.0.0
 */
void terminal_print_array_list(struct array_list* list, void (*print_element)(void*));

#endif
