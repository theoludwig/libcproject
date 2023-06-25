#ifndef __TERMINAL__
#define __TERMINAL__

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "character.h"
#include "dictionary.h"
#include "linked_list.h"
#include "queue.h"
#include "stack.h"

/**
 * @brief Read a line from stdin.
 * @since v1.0.0
 */
string terminal_input();

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
 * @brief Print a int.
 *
 * @param value
 * @since v1.0.0
 */
void terminal_print_int(void* value);

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
 * @brief Print a char.
 *
 * @param value
 * @since v1.0.0
 */
void terminal_print_char(void* value);

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
 * @brief Print a dictionary.
 *
 * @param dictionary
 * @param print_element
 * @since v1.0.0
 */
void terminal_print_dictionary(struct dictionary* dictionary, void (*print_element)(void*));

#endif
