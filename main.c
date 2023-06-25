#include <stdio.h>
#include <stdlib.h>

#include "libcproject.h"

int main() {
  string string_value = "Hello, world!";
  printf("%s\n", string_value);
  printf("string_length = %ld\n", string_get_length(string_value));
  return EXIT_SUCCESS;
}
