#include <stdio.h>
#include <stdlib.h>

#include "libcproject.h"

int main() {
  string_t string = "Hello, world!";
  printf("%s\n", string);
  printf("string_length = %ld\n", string_get_length(string));
  return EXIT_SUCCESS;
}
