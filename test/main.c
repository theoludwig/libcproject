#include <stdio.h>
#include <stdlib.h>

#include "array_list_test.h"
#include "character_test.h"
#include "convert_test.h"
#include "dictionary_test.h"
#include "linked_list_test.h"
#include "mathematics_test.h"
#include "queue_test.h"
#include "stack_test.h"
#include "string_test.h"

int main() {
  array_list_test();
  character_test();
  convert_test();
  dictionary_test();
  linked_list_test();
  mathematics_test();
  queue_test();
  stack_test();
  string_test();
  printf("Success: Tests passed!\n");
  return EXIT_SUCCESS;
}
