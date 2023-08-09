#include <stdio.h>
#include <stdlib.h>

#include "libcproject.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <version>\n", argv[0]);
    return EXIT_FAILURE;
  }
  string_t content = string_copy("#ifndef __LIBCPROJECT_VERSION__\n");
  string_concatenate(&content, "#define __LIBCPROJECT_VERSION__ \"");
  string_concatenate(&content, argv[1]);
  string_concatenate(&content, "\"\n\n");
  string_concatenate(&content, "#endif\n");
  int result = filesystem_write("./version.h", (byte_t*)content, string_get_length(content));
  if (result == -1) {
    fprintf(stderr, "Error: Could not write to file.\n");
    perror("Error (set_version)");
    return EXIT_FAILURE;
  }
  printf("Success: Version set to %s.\n", argv[1]);
  free(content);
  return EXIT_SUCCESS;
}
