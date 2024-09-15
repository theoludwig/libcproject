#ifndef __LIBCPROJECT_MATHEMATICS__
#define __LIBCPROJECT_MATHEMATICS__

#define MATHEMATICS_FLOAT_PRECISION 0.00000001

#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#include "types.h"

/**
 * @brief Verify that 2 numbers are equal.
 *
 * @param number1
 * @param number2
 * @return true
 * @return false
 * @since v1.0.0
 */
bool mathematics_equals(const float number1, const float number2);

/**
 * @brief Get the absolute value of a number.
 *
 * @param number
 * @return unsigned long long
 * @since v1.0.0
 */
unsigned long long mathematics_absolute_value(const long long number);

/**
 * @brief Calculates the power of a number.
 *
 * @param base
 * @param exponent
 * @return unsigned long long
 * @since v1.0.0
 */
unsigned long long mathematics_pow(unsigned long long base, unsigned long long exponent);

/**
 * @brief Calculates the nth root of a number.
 *
 * @param number
 * @param nth_root
 * @return float
 * @since v1.0.0
 */
float mathematics_root(float number, unsigned int nth_root);

/**
 * @brief Calculates the square root of a number using Heron's method.
 *
 * @param number
 * @return float
 * @since v1.0.0
 */
float mathematics_square_root(float number);

/**
 * @brief Calculates the factorial of a number.
 *
 * @param number
 * @return unsigned long long
 * @since v1.0.0
 */
unsigned long long mathematics_factorial(unsigned long long number);

/**
 * @brief Calulcates the opposite number (additive inverse).
 *
 * @param number
 * @return int64_t
 *
 * @code
 * mathematics_opposite(7) // -7
 *
 * mathematics_opposite(-7) // 7
 * @endcode
 * @since v4.3.0
 */
int64_t mathematics_opposite(int64_t number);

/**
 * @brief Returns the largest number between 2 numbers.
 *
 * @param number1
 * @param number2
 * @return int64_t
 * @since v4.3.0
 */
int64_t mathematics_max(int64_t number1, int64_t number2);

/**
 * @brief Returns the largest number between multiple numbers. If the array is empty, returns 0.
 *
 * @param values
 * @param values_length
 * @return int64_t
 * @since v4.3.0
 */
int64_t mathematics_max_values(int64_t *values, size_t values_length);

/**
 * @brief Returns the smallest number between 2 numbers.
 *
 * @param number1
 * @param number2
 * @return int64_t
 * @since v4.3.0
 */
int64_t mathematics_min(int64_t number1, int64_t number2);

/**
 * @brief Returns the smallest number between multiple numbers. If the array is empty, returns 0.
 *
 * @param values
 * @param values_length
 * @return int64_t
 * @since v4.3.0
 */
int64_t mathematics_min_values(int64_t *values, size_t values_length);

#endif
