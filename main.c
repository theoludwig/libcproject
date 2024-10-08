#include <stdio.h>
#include <stdlib.h>

#include "libcproject.h"

int main() {
  int integer = 5;
  terminal_print_int(&integer);
  printf("\n");

  bool boolean = true;
  printf("terminal_print_bool: ");
  terminal_print_bool(&boolean);
  printf(", ");
  boolean = false;
  terminal_print_bool(&boolean);
  printf("\n");

  long integer_long = 5;
  printf("terminal_print_long: ");
  terminal_print_long(&integer_long);
  printf("\n");

  unsigned long integer_unsigned_long = 5;
  printf("terminal_print_unsigned_long: ");
  terminal_print_unsigned_long(&integer_unsigned_long);
  printf("\n");

  float floating_point = 5.5;
  printf("terminal_print_float: ");
  terminal_print_float(&floating_point);
  printf("\n");

  double floating_point_double = 5.5;
  printf("terminal_print_double: ");
  terminal_print_double(&floating_point_double);
  printf("\n");

  int8_t integer_8 = 5;
  printf("terminal_print_int8_t: ");
  terminal_print_int8_t(&integer_8);
  printf("\n");

  int16_t integer_16 = 5;
  printf("terminal_print_int16_t: ");
  terminal_print_int16_t(&integer_16);
  printf("\n");

  int32_t integer_32 = 5;
  printf("terminal_print_int32_t: ");
  terminal_print_int32_t(&integer_32);
  printf("\n");

  int64_t integer_64 = 5;
  printf("terminal_print_int64_t: ");
  terminal_print_int64_t(&integer_64);
  printf("\n");

  uint8_t integer_unsigned_8 = 5;
  printf("terminal_print_uint8_t: ");
  terminal_print_uint8_t(&integer_unsigned_8);
  printf("\n");

  uint16_t integer_unsigned_16 = 5;
  printf("terminal_print_uint16_t: ");
  terminal_print_uint16_t(&integer_unsigned_16);
  printf("\n");

  uint32_t integer_unsigned_32 = 5;
  printf("terminal_print_uint32_t: ");
  terminal_print_uint32_t(&integer_unsigned_32);
  printf("\n");

  uint64_t integer_unsigned_64 = 5;
  printf("terminal_print_uint64_t: ");
  terminal_print_uint64_t(&integer_unsigned_64);
  printf("\n");

  char character = 'c';
  printf("terminal_print_char: ");
  terminal_print_char(&character);
  printf("\n");

  int array[] = {1, 2, 3, 4, 5};
  printf("terminal_print_array: ");
  terminal_print_array(array, 5, sizeof(int), terminal_print_int);

  string_t string = "Hello, world!";
  printf("terminal_print_string: ");
  terminal_print_string(string);
  printf("\n");

  struct stack* stack = stack_initialization();
  stack_push(stack, &integer);
  printf("terminal_print_stack: ");
  terminal_print_stack(stack, terminal_print_int);
  stack_free(stack);

  struct queue* queue = queue_initialization();
  queue_push(queue, &integer);
  printf("terminal_print_queue: ");
  terminal_print_queue(queue, terminal_print_int);
  queue_free(queue);

  struct linked_list* linked_list = linked_list_initialization();
  linked_list_add_after_last(linked_list, string);
  linked_list_add_after_last(linked_list, string);
  printf("terminal_print_linked_list: ");
  terminal_print_linked_list(linked_list, terminal_print_string);
  linked_list_free(linked_list);

  struct hash_map* hash_map = hash_map_initialization();
  hash_map_add(hash_map, "key", &integer);
  printf("terminal_print_hash_map: ");
  terminal_print_hash_map(hash_map, terminal_print_int);
  hash_map_free(hash_map);

  struct array_list* array_list = array_list_initialization();
  array_list_add(array_list, &integer);
  array_list_add(array_list, &integer);
  printf("terminal_print_array_list: ");
  terminal_print_array_list(array_list, terminal_print_int);
  array_list_free(array_list);

  struct date* date = date_get_now_utc();
  string_t iso_string = date_to_iso_string(date);
  printf("date_get_now_utc = %s\n", iso_string);
  free(iso_string);
  free(date);

  date = date_get_now_local();
  iso_string = date_to_iso_string(date);
  printf("date_get_now_local = %s\n", iso_string);
  free(iso_string);
  free(date);

  return EXIT_SUCCESS;
}
