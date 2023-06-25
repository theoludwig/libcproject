#ifndef __MATHEMATICS__
#define __MATHEMATICS__

#define MATHEMATICS_FLOAT_PRECISION 0.00000001

#include <stdbool.h>

#include "types.h"

/**
 * @brief Verify that 2 numbers are equal.
 *
 * @param number1
 * @param number2
 * @since v1.0.0
 */
bool mathematics_equals(const float number1, const float number2);

/**
 * @brief Get the absolute value of a number.
 *
 * @param number
 * @since v1.0.0
 */
unsigned long long mathematics_absolute_value(const long long number);

/**
 * @brief Calculates the power of a number.
 *
 * @param base
 * @param exponent
 * @since v1.0.0
 */
unsigned long long mathematics_pow(unsigned long long base, unsigned long long exponent);

/**
 * @brief Calculates the nth root of a number using Heron's method.
 *
 * @param number
 * @param nth_root
 * @since v1.0.0
 */
float mathematics_root(float number, unsigned int nth_root);

/**
 * @brief Calculates the square root of a number using Heron's method.
 *
 * @param number
 * @since v1.0.0
 */
float mathematics_square_root(float number);

/**
 * @brief Calculates the factorial of a number.
 *
 * @param number
 * @since v1.0.0
 */
unsigned long long mathematics_factorial(unsigned long long number);

#endif
