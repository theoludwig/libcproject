#include "terminal.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "character.h"
#include "dictionary.h"
#include "linked_list.h"
#include "queue.h"
#include "stack.h"

char* terminal_input() {
  char character;
  size_t length = 1;
  char* string = malloc(length * sizeof(char));
  if (string == NULL) {
    exit(EXIT_FAILURE);
  }
  *string = '\0';
  while ((character = getchar()) != '\n' && character != EOF) {
    length++;
    string = realloc(string, length * sizeof(char));
    if (string == NULL) {
      exit(EXIT_FAILURE);
    }
    character_append(string, character);
  }
  return string;
}

void terminal_print_array(void* array, size_t array_size, size_t element_size, void (*print_element)(void*)) {
  printf("[");
  for (size_t index = 0; index < array_size; index++) {
    void* element = (char*)array + index * element_size;
    print_element(element);
    bool is_last = index == array_size - 1;
    if (!is_last) {
      printf(", ");
    }
  }
  printf("]\n");
}

void terminal_print_int(void* value) {
  printf("%d", *(int*)value);
}

void terminal_print_long(void* value) {
  printf("%ld", *(long*)value);
}

void terminal_print_unsigned_long(void* value) {
  printf("%lu", *(unsigned long*)value);
}

void terminal_print_char(void* value) {
  printf("%c", *(char*)value);
}

void terminal_print_string(void* value) {
  printf("%s", (char*)value);
}

void terminal_print_stack(struct stack* stack, void (*print_element)(void*)) {
  if (stack == NULL) {
    exit(EXIT_FAILURE);
  }
  struct stack_node* node_current = stack->first;
  while (node_current != NULL) {
    printf("|\t");
    void* element = (char*)node_current->data;
    print_element(&element);
    node_current = node_current->next;
    printf("\t|\n");
  }
}

void terminal_print_queue(struct queue* queue, void (*print_element)(void*)) {
  if (queue == NULL) {
    exit(EXIT_FAILURE);
  }
  struct queue_node* node_current = queue->first;
  while (node_current != NULL) {
    printf("|\t");
    void* element = (char*)node_current->data;
    print_element(&element);
    node_current = node_current->next;
    printf("\t|\n");
  }
}

void terminal_print_linked_list(struct linked_list* linked_list, void (*print_element)(void*)) {
  if (linked_list == NULL) {
    exit(EXIT_FAILURE);
  }
  struct linked_list_node* node_current = linked_list->head;
  while (node_current != NULL) {
    void* element = (char*)node_current->data;
    node_current = node_current->next;
    print_element(&element);
    printf(" -> ");
  }
  printf("NULL\n");
}

void terminal_print_dictionary(struct dictionary* dictionary, void (*print_element)(void*)) {
  if (dictionary == NULL) {
    exit(EXIT_FAILURE);
  }
  printf("{\n");
  for (size_t index = 0; index < dictionary->length; index++) {
    struct dictionary_item* item = dictionary->items[index];
    printf("\t\"");
    terminal_print_string(item->key);
    printf("\" -> ");
    print_element(&item->data);
    printf("\n");
  }
  printf("}\n");
}
