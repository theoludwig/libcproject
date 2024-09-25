#include "mathematics.h"

bool mathematics_equals(const float64_t number1, const float64_t number2) {
  return (number1 - number2) < MATHEMATICS_DOUBLE_PRECISION;
}

uint64_t mathematics_absolute_value(const int64_t number) {
  if (number >= 0) {
    return number;
  }
  return -number;
}

uint64_t mathematics_pow(uint64_t base, uint64_t exponent) {
  return exponent == 0 ? 1 : base * mathematics_pow(base, exponent - 1);
}

float64_t mathematics_root(float64_t number, uint64_t nth_root) {
  float64_t result = number;
  float64_t previous_result = 0;
  while (!mathematics_equals(result, previous_result)) {
    result = (((nth_root - 1) * previous_result) + (number / mathematics_pow(result, nth_root - 1))) / nth_root;
    previous_result = result;
  }
  return result;
}

float64_t mathematics_square_root(float64_t number) {
  return mathematics_root(number, 2);
}

uint64_t mathematics_factorial(uint64_t number) {
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
