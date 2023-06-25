#include <stdio.h>
#include <stdlib.h>

#include "libcproject.h"

int main(int argc, string* argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <version>\n", argv[0]);
    return EXIT_FAILURE;
  }
  string content = "#ifndef __LIBCPROJECT_VERSION__\n";
  content = string_concatenate(content, "#define __LIBCPROJECT_VERSION__ \"");
  content = string_concatenate(content, argv[1]);
  content = string_concatenate(content, "\"\n\n");
  content = string_concatenate(content, "#endif\n");
  int result = filesystem_write("./version.h", content, string_get_length(content));
  if (result == -1) {
    fprintf(stderr, "Error: Could not write to file.\n");
    return EXIT_FAILURE;
  }
  printf("Success: Version set to %s.\n", argv[1]);
  return EXIT_SUCCESS;
}
