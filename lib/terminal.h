#ifndef __TERMINAL__
#define __TERMINAL__

#include <stdlib.h>

#include "dictionary.h"
#include "linked_list.h"
#include "queue.h"
#include "stack.h"

/**
 * @brief Read a line from stdin.
 *
 * @return char*
 */
char* terminal_input();

void terminal_print_array(void* array, size_t array_size, size_t element_size, void (*print_element)(void*));

void terminal_print_int(void* value);

void terminal_print_long(void* value);

void terminal_print_unsigned_long(void* value);

void terminal_print_char(void* value);

void terminal_print_string(void* value);

void terminal_print_stack(struct stack* stack, void (*print_element)(void*));

void terminal_print_queue(struct queue* queue, void (*print_element)(void*));

void terminal_print_linked_list(struct linked_list* linked_list, void (*print_element)(void*));

void terminal_print_dictionary(struct dictionary* dictionary, void (*print_element)(void*));

#endif
