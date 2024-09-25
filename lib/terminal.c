#include "terminal.h"

string_t terminal_input() {
  char character;
  size_t length = 1;
  string_t string = malloc(length * sizeof(char));
  if (string == NULL) {
    perror("Error (terminal_input)");
    exit(EXIT_FAILURE);
  }
  *string = '\0';
  while ((character = getchar()) != '\n' && character != EOF) {
    length++;
    string = realloc(string, length * sizeof(char));
    if (string == NULL) {
      perror("Error (terminal_input)");
      exit(EXIT_FAILURE);
    }
    character_append(string, character);
  }
  return string;
}

void terminal_print_int(void* value) {
  printf("%d", *(int*)value);
}

void terminal_print_bool(void* value) {
  printf("%s", *(bool*)value ? "true" : "false");
}

void terminal_print_long(void* value) {
  printf("%ld", *(long*)value);
}

void terminal_print_unsigned_long(void* value) {
  printf("%lu", *(unsigned long*)value);
}

void terminal_print_float(void* value) {
  printf("%f", *(float*)value);
}

void terminal_print_double(void* value) {
  printf("%f", *(double*)value);
}

void terminal_print_int8_t(void* value) {
  printf("%d", *(int8_t*)value);
}

void terminal_print_int16_t(void* value) {
  printf("%d", *(int16_t*)value);
}

void terminal_print_int32_t(void* value) {
  printf("%d", *(int32_t*)value);
}

void terminal_print_int64_t(void* value) {
  printf("%ld", *(int64_t*)value);
}

void terminal_print_uint8_t(void* value) {
  printf("%u", *(uint8_t*)value);
}

void terminal_print_uint16_t(void* value) {
  printf("%u", *(uint16_t*)value);
}

void terminal_print_uint32_t(void* value) {
  printf("%u", *(uint32_t*)value);
}

void terminal_print_uint64_t(void* value) {
  printf("%lu", *(uint64_t*)value);
}

void terminal_print_char(void* value) {
  printf("%c", *(string_t)value);
}

void terminal_print_array(void* array, size_t array_size, size_t element_size, void (*print_element)(void*)) {
  printf("[");
  for (size_t index = 0; index < array_size; index++) {
    void* element = (string_t)array + index * element_size;
    print_element(element);
    bool is_last = index == array_size - 1;
    if (!is_last) {
      printf(", ");
    }
  }
  printf("]\n");
}

void terminal_print_string(void* value) {
  printf("%s", (string_t)value);
}

void terminal_print_stack(struct stack* stack, void (*print_element)(void*)) {
  if (stack == NULL) {
    errno = EINVAL;
    perror("Error (terminal_print_stack)");
    exit(EXIT_FAILURE);
  }
  struct stack_node* node_current = stack->first;
  while (node_current != NULL) {
    printf("|\t");
    void* element = node_current->data;
    print_element(element);
    node_current = node_current->next;
    printf("\t|\n");
  }
}

void terminal_print_queue(struct queue* queue, void (*print_element)(void*)) {
  if (queue == NULL) {
    errno = EINVAL;
    perror("Error (terminal_print_queue)");
    exit(EXIT_FAILURE);
  }
  struct queue_node* node_current = queue->first;
  while (node_current != NULL) {
    printf("|\t");
    void* element = node_current->data;
    print_element(element);
    node_current = node_current->next;
    printf("\t|\n");
  }
}

void terminal_print_linked_list(struct linked_list* linked_list, void (*print_element)(void*)) {
  if (linked_list == NULL) {
    errno = EINVAL;
    perror("Error (terminal_print_linked_list)");
    exit(EXIT_FAILURE);
  }
  struct linked_list_node* node_current = linked_list->head;
  while (node_current != NULL) {
    void* element = (string_t)node_current->data;
    node_current = node_current->next;
    print_element(element);
    printf(" -> ");
  }
  printf("NULL\n");
}

void terminal_print_hash_map(struct hash_map* hash_map, void (*print_element)(void*)) {
  if (hash_map == NULL) {
    errno = EINVAL;
    perror("Error (terminal_print_hash_map)");
    exit(EXIT_FAILURE);
  }
  printf("{\n");
  string_t* keys = hash_map_get_keys(hash_map);
  for (size_t index = 0; index < hash_map->length; index++) {
    string_t key = keys[index];
    void* value = hash_map_get(hash_map, key);
    printf("\t\"");
    terminal_print_string(key);
    printf("\" -> ");
    print_element(value);
    printf("\n");
  }
  printf("}\n");
  free(keys);
}

void terminal_print_array_list(struct array_list* list, void (*print_element)(void*)) {
  printf("[");
  for (size_t index = 0; index < list->size; index++) {
    void* element = list->data[index];
    print_element(element);
    if (index < list->size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}
