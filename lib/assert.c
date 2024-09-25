#include "assert.h"

bool assert_string_equal(const string_t actual, const string_t expected) {
  if (!string_equals(actual, expected)) {
    printf("FAIL: expected = \"%s\" ; actual = \"%s\"\n", expected, actual);
    return false;
  }
  return true;
}

bool assert_string_not_equal(const string_t actual, const string_t expected) {
  if (string_equals(actual, expected)) {
    printf("FAIL: expected = \"%s\" ; actual = \"%s\"\n", expected, actual);
    return false;
  }
  return true;
}
