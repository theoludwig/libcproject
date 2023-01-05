#include "mathematics.h"

#include <stdbool.h>

bool mathematics_equals(const float number1, const float number2) {
  return (number1 - number2) < MATHEMATICS_FLOAT_PRECISION;
}

unsigned long long mathematics_absolute_value(const long long number) {
  if (number >= 0) {
    return number;
  }
  return -number;
}

unsigned long long mathematics_pow(unsigned long long base, unsigned long long exponent) {
  return exponent == 0 ? 1 : base * mathematics_pow(base, exponent - 1);
}

float mathematics_root(float number, unsigned int nth_root) {
  float result = number;
  float previous_result = 0;
  while (!mathematics_equals(result, previous_result)) {
    result = (((nth_root - 1) * previous_result) + (number / mathematics_pow(result, nth_root - 1))) / nth_root;
    previous_result = result;
  }
  return result;
}

float mathematics_square_root(float number) {
  return mathematics_root(number, 2);
}

unsigned long long mathematics_factorial(unsigned long long number) {
  return number == 0 ? 1 : number * mathematics_factorial(number - 1);
}
