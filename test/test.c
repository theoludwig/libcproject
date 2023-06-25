#include "test.h"

bool assert_string_equal(const string_t actual, const string_t expected) {
  if (strcmp(expected, actual) != 0) {
    printf("FAIL: expected = \"%s\" ; actual = \"%s\"\n", expected, actual);
    return false;
  }
  return true;
}

bool assert_string_not_equal(const string_t actual, const string_t expected) {
  if (strcmp(expected, actual) == 0) {
    printf("FAIL: expected = \"%s\" ; actual = \"%s\"\n", expected, actual);
    return false;
  }
  return true;
}
