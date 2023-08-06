#ifndef __LIBCPROJECT_CONVERT__
#define __LIBCPROJECT_CONVERT__

#include <stdio.h>
#include <stdlib.h>

#include "character.h"
#include "mathematics.h"
#include "stdbool.h"
#include "string.h"
#include "types.h"

/**
 * @brief Convert a character to a string.
 *
 * @param character
 * @since v1.0.0
 */
string_t convert_character_to_string(const char character);

/**
 * @brief Convert a character to a digit.
 *
 * @param character
 * @since v1.0.0
 */
char convert_character_to_digit(const char character);

/**
 * @brief Convert a digit to a character.
 *
 * @param digit
 * @since v1.0.0
 */
char convert_digit_to_character(const char digit);

/**
 * @brief Convert a string to a number.
 *
 * @param string
 * @since v1.0.0
 */
long long convert_string_to_number(const string_t string);

/**
 * @brief Convert a number to a string.
 *
 * @param integer
 * @since v1.0.0
 */
string_t convert_number_to_string(const long long integer);

/**
 * @brief Convert a number (base 10) to a string with a specific base.
 *
 * @param number
 * @param base
 * @since v1.0.0
 */
string_t convert_number_from_base_10_to_base(unsigned long long number, unsigned int base);

/**
 * @brief Convert a number with a specific base to a number base 10.
 *
 * @param number
 * @param base
 * @since v1.0.0
 */
int convert_number_from_base_to_base_10(string_t number, unsigned int base);

/**
 * @brief Convert a number with a specific base to a number of specific base.
 *
 * @param number
 * @param base_from
 * @param base_target
 * @since v1.0.0
 */
string_t convert_number_from_base_to_another(string_t number, int base_from, int base_target);

#endif
