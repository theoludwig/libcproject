#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool assert_string_equal(const char *actual, const char *expected) {
  if (strcmp(expected, actual) != 0) {
    printf("FAIL: expected = \"%s\" ; actual = \"%s\"\n", expected, actual);
    return false;
  }
  return true;
}

bool assert_string_not_equal(const char *actual, const char *expected) {
  if (strcmp(expected, actual) == 0) {
    printf("FAIL: expected = \"%s\" ; actual = \"%s\"\n", expected, actual);
    return false;
  }
  return true;
}
