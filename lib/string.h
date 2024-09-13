#ifndef __LIBCPROJECT_STRING__
#define __LIBCPROJECT_STRING__

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "character.h"
#include "convert.h"
#include "hash_map.h"
#include "types.h"

/**
 * @brief Return the length of a string (excluding '\0').
 *
 * @param string
 * @return size_t
 * @since v1.0.0
 */
size_t string_get_length(const string_t string);

/**
 * @brief Converts all the alphabetic characters in a string to uppercase.
 *
 * NOTE: Mutates the string.
 *
 * @param string
 * @since v1.0.0
 */
void string_to_uppercase(string_t string);

/**
 * @brief Converts all the alphabetic characters in a string to lowercase.
 *
 * NOTE: Mutates the string.
 *
 * @param string
 * @since v1.0.0
 */
void string_to_lowercase(string_t string);

/**
 * @brief Replace all the occurrences of search value into replace value in the string.
 *
 * NOTE: Mutates the string.
 *
 * @param string
 * @param search A character search value.
 * @param replace A character containing the text to replace for match.
 * @since v1.0.0
 */
void string_replace(string_t string, char search, char replace);

/**
 * @brief Removes all the occurrences of a character in a string.
 *
 * NOTE: Mutates the string.
 *
 * @param string
 * @param search A character search value.
 * @since v4.1.0
 */
void string_remove_character(string_t string, char search);

/**
 * @brief Removes all `character` from the start of a string.
 *
 * NOTE: Mutates the string.
 *
 * @param string
 * @since v1.0.0
 */
void string_trim_start(string_t string, char character);

/**
 * @brief Removes all `character` from the end of a string.
 *
 * NOTE: Mutates the string.
 *
 * @param string
 * @since v1.0.0
 */
void string_trim_end(string_t string, char character);

/**
 * @brief Removes all `character` from the start and end of a string.
 *
 * NOTE: Mutates the string.
 *
 * @param string
 * @since v1.0.0
 */
void string_trim(string_t string, char character);

/**
 * @brief Return the copy of a string.
 *
 * @param string
 * @return string_t
 * @since v1.0.0
 */
string_t string_copy(const string_t string);

/**
 * @brief Capitalizes the string.
 *
 * NOTE: Mutates the string.
 *
 * @param string
 * @since v1.0.0
 */
void string_capitalize(string_t string);

/**
 * @brief Returns the total number of occurrences of the given character in the string.
 *
 * @param string
 * @param character
 * @return size_t
 * @since v1.0.0
 */
size_t string_total_occurrences_of_character(string_t string, char character);

/**
 * @brief Reverse the characters in a string.
 *
 * NOTE: Mutates the string.
 *
 * @param string
 * @since v1.0.0
 */
void string_reverse(const string_t string);

/**
 * @brief Check if two strings are equals.
 *
 * @param string1
 * @param string2
 * @return true if the strings are equals.
 * @return false if the strings are not equals.
 * @since v1.0.0
 */
bool string_equals(const string_t string1, const string_t string2);

/**
 * @brief Check if the string is an integer.
 *
 * @param string
 * @return true if the string is an integer.
 * @return false if the string is not an integer.
 * @since v1.0.0
 */
bool string_get_is_integer(const string_t string);

/**
 * @brief Split a string into substrings using the specified separator and return them as an array and update the pointer `result_size` to the resulting size of the created array.
 *
 * @param string
 * @param separator
 * @param result_size
 * @return string_t*
 * @since v1.0.0
 */
string_t* string_split(const string_t string, char separator, size_t* result_size);

/**
 * @brief Adds all the elements of an array into a string, separated by the specified separator string.
 *
 * @param array
 * @param separator
 * @param array_length
 * @return string_t
 * @since v1.0.0
 */
string_t string_join(string_t* array, const char separator, size_t array_length);

/**
 * @brief Concatenate two strings.
 *
 * NOTE: Mutates the string `destination`.
 *
 * @param destination
 * @param source
 * @since v1.0.0
 */
void string_concatenate(string_t* destination, string_t source);

/**
 * @brief Check if a string contains only unique characters.
 *
 * @param string
 * @return true if string contains only unique characters.
 * @return false if string contains duplicate characters.
 * @since v1.0.0
 */
bool string_get_has_unique_characters(const string_t string);

/**
 * @brief Returns the part of the string between the start and end indexes (both included).
 *
 * @param string
 * @param index_start
 * @param index_end
 * @return string_t
 * @since v1.0.0
 */
string_t string_substring(const string_t string, size_t index_start, size_t index_end);

/**
 * @brief Check if a string contains a substring.
 *
 * @param string
 * @param substring
 * @return true if the string contains the substring.
 * @return false if the string does not contain the substring.
 * @since v1.0.0
 */
bool string_get_is_substring(const string_t string, const string_t substring);

/**
 * @brief Format a number to a string with specified separator.
 *
 * @param number
 * @param separator
 * @return string_t
 *
 * @code
 * string_get_formatted_number(1000, " ") // "1 000"
 * string_get_formatted_number(1000, ",") // "1,000"
 * @endcode
 * @since v1.0.0
 */
string_t string_get_formatted_number(const long long number, string_t separator);

/**
 * @brief Returns a pointer to the last occurrence of character in the string.
 *
 * @param string
 * @param character
 * @return string_t
 * @since v1.0.0
 */
string_t string_get_last_occurence_of_character(const string_t string, char character);

/**
 * @brief Check if a string starts with a substring.
 *
 * @param string
 * @param prefix
 * @return true if the string starts with the substring.
 * @return false if the string does not start with the substring.
 * @since v1.0.0
 */
bool string_starts_with(const string_t string, const string_t prefix);

/**
 * @brief Check if a string ends with a substring.
 *
 * @param string
 * @param prefix
 * @return true if the string ends with the substring.
 * @return false if the string does not end with the substring.
 * @since v1.0.0
 */
bool string_ends_with(const string_t string, const string_t prefix);

/**
 * @brief Returns the position (index + 1) within the string of the first occurrence of the specified substring (0 if not found).
 *
 * @param string
 * @param substring
 * @return size_t
 *
 * @code
 * string_position_of("hello world", 'e') // 2
 * @endcode
 * @since v4.2.0
 */
size_t string_position_of(const string_t string, const char character);

/**
 * @brief Returns the position (index + 1) within the string of the last occurrence of the specified substring (0 if not found).
 *
 * @param string
 * @param character
 * @return size_t
 *
 * @code
 * string_last_position_of("hello world", 'o') // 8
 * @endcode
 * @since v4.2.0
 */
size_t string_last_position_of(const string_t string, const char character);

/**
 * @brief Pads a `string` with another `pad_string` (multiple times, if needed) until the resulting string reaches the `target_length`. The padding is applied from the start (left) of the string.
 *
 * @param string The string to pad.
 * @param pad_string The string to pad the current string with, to the left.
 * @param target_length
 * @return string_t
 *
 * @code
 * string_pad_start("hello", " ", 10) // "     hello"
 * @endcode
 * @since vTODO
 */
string_t string_pad_start(const string_t string, const string_t pad_string, size_t target_length);

/**
 * @brief Pad a number with zeros.
 *
 * @param number
 * @param places
 * @return string_t
 *
 * @code
 * string_zero_pad(1, 2) // "01"
 *
 * string_zero_pad(10, 2) // "10"
 * @endcode
 * @since vTODO
 */
string_t string_zero_pad(uint64_t number, size_t places);

#endif
