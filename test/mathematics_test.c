#include "mathematics_test.h"

void mathematics_test() {
  mathematics_absolute_value_test();
  mathematics_pow_test();
  mathematics_root_test();
  mathematics_square_root_test();
  mathematics_factorial_test();
  mathematics_opposite_test();
  mathematics_max_test();
  mathematics_max_values_test();
  mathematics_min_test();
  mathematics_min_values_test();
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
  assert(mathematics_equals(mathematics_root(0, 0), 0));
  assert(mathematics_equals(mathematics_root(0, 1), 0));
  assert(mathematics_equals(mathematics_root(2, 2), 1));
  assert(mathematics_equals(mathematics_root(27, 3), 3));
  assert(mathematics_equals(mathematics_root(16807, 5), 7));
}

void mathematics_square_root_test() {
  assert(mathematics_equals(mathematics_square_root(0), 0));
  assert(mathematics_equals(mathematics_square_root(1), 1));
  assert(mathematics_equals(mathematics_square_root(4), 2));
  assert(mathematics_equals(mathematics_square_root(9), 3));
  assert(mathematics_equals(mathematics_square_root(25), 5));
  assert(mathematics_equals(mathematics_square_root(100), 10));
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

void mathematics_opposite_test() {
  assert(mathematics_opposite(-7) == 7);
  assert(mathematics_opposite(7) == -7);
}

void mathematics_max_test() {
  assert(mathematics_max(0, 0) == 0);
  assert(mathematics_max(0, 1) == 1);
  assert(mathematics_max(2, 0) == 2);
  assert(mathematics_max(54, 37) == 54);
}

void mathematics_max_values_test() {
  int64_t values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  assert(mathematics_max_values(values, 10) == 9);

  int64_t values2[] = {8, 6, 4, 7};
  assert(mathematics_max_values(values2, 4) == 8);
}

void mathematics_min_test() {
  assert(mathematics_min(0, 0) == 0);
  assert(mathematics_min(3, 5) == 3);
  assert(mathematics_min(2, 1) == 1);
  assert(mathematics_min(54, 37) == 37);
}

void mathematics_min_values_test() {
  int64_t values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  assert(mathematics_min_values(values, 10) == 0);

  int64_t values2[] = {9, 6, 8, 7};
  assert(mathematics_min_values(values2, 4) == 6);
}
