#ifndef __LIBCPROJECT_CHARACTER__
#define __LIBCPROJECT_CHARACTER__

#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#include "string.h"
#include "types.h"

/**
 * @brief Append a character to a string, assuming string points to an array
 * with enough space.
 *
 * @param string
 * @param character
 * @since v1.0.0
 */
void character_append(string_t string, char character);

/**
 * @brief Append a character to a string at a specific index, assuming string points to an array with enough space.
 *
 * @param string
 * @param character
 * @param index
 * @since v1.0.0
 */
void character_append_at(string_t string, const char character, const size_t index);

/**
 * @brief Converts the character to uppercase.
 *
 * @param character
 * @since v1.0.0
 */
char character_to_upper(const char character);

/**
 * @brief Converts the character to lowercase.
 *
 * @param character
 * @since v1.0.0
 */
char character_to_lower(const char character);

/**
 * @brief Check if the character is a digit ('0', '1', '2', '3', '4', '5', '6', '7, '8' or '9').
 *
 * @return true if the character is a digit, false otherwise
 * @since v1.0.0
 */
bool character_get_is_digit(const char character);

/**
 * @brief Get the position in latin alphabet of the letter (case-insensitive) from 1 to 26.
 * Return 0 if the character is not a letter.
 *
 * @param character
 * @since v1.0.0
 */
unsigned char character_get_alphabet_position(const char character);

#endif
