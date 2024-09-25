#include "mathematics.h"

bool mathematics_equals(const double number1, const double number2) {
  return (number1 - number2) < MATHEMATICS_DOUBLE_PRECISION;
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

double mathematics_root(double number, unsigned int nth_root) {
  double result = number;
  double previous_result = 0;
  while (!mathematics_equals(result, previous_result)) {
    result = (((nth_root - 1) * previous_result) + (number / mathematics_pow(result, nth_root - 1))) / nth_root;
    previous_result = result;
  }
  return result;
}

double mathematics_square_root(double number) {
  return mathematics_root(number, 2);
}

unsigned long long mathematics_factorial(unsigned long long number) {
  return number == 0 ? 1 : number * mathematics_factorial(number - 1);
}

int64_t mathematics_opposite(int64_t number) {
  return number * -1;
}

int64_t mathematics_max(int64_t number1, int64_t number2) {
  return number1 > number2 ? number1 : number2;
}

int64_t mathematics_max_values(int64_t *values, size_t values_length) {
  int64_t max = 0;
  if (values_length <= 0) {
    return max;
  }
  max = values[0];
  for (size_t index = 1; index < values_length; index++) {
    max = mathematics_max(max, values[index]);
  }
  return max;
}

int64_t mathematics_min(int64_t number1, int64_t number2) {
  return number1 > number2 ? number2 : number1;
}

int64_t mathematics_min_values(int64_t *values, size_t values_length) {
  int64_t min = 0;
  if (values_length <= 0) {
    return min;
  }
  min = values[0];
  for (size_t index = 1; index < values_length; index++) {
    min = mathematics_min(min, values[index]);
  }
  return min;
}
