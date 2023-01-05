#include "mathematics_test.h"

#include <assert.h>

#include "libcproject.h"

void mathematics_test() {
  mathematics_absolute_value_test();
  mathematics_pow_test();
  mathematics_root_test();
  mathematics_square_root_test();
  mathematics_factorial_test();
}

void mathematics_absolute_value_test() {
  assert(mathematics_absolute_value(0) == 0);
  assert(mathematics_absolute_value(-0) == 0);
  assert(mathematics_absolute_value(1) == 1);
  assert(mathematics_absolute_value(-1) == 1);
  assert(mathematics_absolute_value(2) == 2);
  assert(mathematics_absolute_value(-2) == 2);
}

void mathematics_pow_test() {
  assert(mathematics_pow(0, 0) == 1);
  assert(mathematics_pow(0, 1) == 0);
  assert(mathematics_pow(2, 2) == 4);
  assert(mathematics_pow(5, 2) == 25);
  assert(mathematics_pow(3, 3) == 27);
  assert(mathematics_pow(7, 5) == 16807);
}

void mathematics_root_test() {
  assert(mathematics_get_is_equal(mathematics_root(0, 0), 0));
  assert(mathematics_get_is_equal(mathematics_root(0, 1), 0));
  assert(mathematics_get_is_equal(mathematics_root(2, 2), 1));
  assert(mathematics_get_is_equal(mathematics_root(27, 3), 3));
  assert(mathematics_get_is_equal(mathematics_root(16807, 5), 7));
}

void mathematics_square_root_test() {
  assert(mathematics_get_is_equal(mathematics_square_root(0), 0));
  assert(mathematics_get_is_equal(mathematics_square_root(1), 1));
  assert(mathematics_get_is_equal(mathematics_square_root(4), 2));
  assert(mathematics_get_is_equal(mathematics_square_root(9), 3));
  assert(mathematics_get_is_equal(mathematics_square_root(25), 5));
  assert(mathematics_get_is_equal(mathematics_square_root(100), 10));
}

void mathematics_factorial_test() {
  assert(mathematics_factorial(0) == 1);
  assert(mathematics_factorial(1) == 1);
  assert(mathematics_factorial(2) == 2);
  assert(mathematics_factorial(3) == 6);
  assert(mathematics_factorial(4) == 24);
  assert(mathematics_factorial(5) == 120);
  assert(mathematics_factorial(6) == 720);
  assert(mathematics_factorial(7) == 5040);
  assert(mathematics_factorial(8) == 40320);
  assert(mathematics_factorial(9) == 362880);
  assert(mathematics_factorial(10) == 3628800);
}
