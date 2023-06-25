#ifndef __STRING__
#define __STRING__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "character.h"
#include "convert.h"
#include "dictionary.h"

typedef char* string;

/**
 * @brief Return the length of a string (excluding '\0').
 *
 * @param string
 * @return size_t
 * @since v1.0.0
 */
size_t string_get_length(const string string_value);

/**
 * @brief Converts all the alphabetic characters in a string to uppercase.
 *
 * @param string
 * @since v1.0.0
 */
string string_to_uppercase(string string_value);

/**
 * @brief Converts all the alphabetic characters in a string to lowercase.
 *
 * @param string
 * @since v1.0.0
 */
string string_to_lowercase(string string_value);

/**
 * @brief Replace all the occurrences of search value into replace value in the string.
 *
 * @param string
 * @param search_value A character search value.
 * @param replace_value A character containing the text to replace for match.
 * @since v1.0.0
 */
string string_replace(string string_value, char search, char replace);

/**
 * @brief Removes all whitespace from the start of a string.
 *
 * @param string
 * @since v1.0.0
 */
string string_trim_start(string string_value);

/**
 * @brief Removes all whitespace from the end of a string.
 *
 * @param string
 * @since v1.0.0
 */
string string_trim_end(string string_value);

/**
 * @brief Removes all whitespace from the start and end of a string.
 *
 * @param string
 * @since v1.0.0
 */
string string_trim(string string_value);

/**
 * @brief Return the copy of a string.
 *
 * @param string
 * @since v1.0.0
 */
string string_copy(const string string_value);

/**
 * @brief Capitalizes the string.
 *
 * @param string
 * @since v1.0.0
 */
string string_capitalize(string string_value);

/**
 * @brief Returns the total number of occurrences of the given character in the string.
 *
 * @param string
 * @param character
 * @return size_t
 * @since v1.0.0
 */
size_t string_total_occurrences_of_character(string string_value, char character);

/**
 * @brief Reverse the characters in an array.
 *
 * @param string
 * @since v1.0.0
 */
string string_reverse(const string string_value);

/**
 * @brief Check if two strings are equals.
 *
 * @param string1
 * @param string2
 * @return true if the strings are equals, false otherwise.
 * @since v1.0.0
 */
bool string_equals(const string string1, const string string2);

/**
 * @brief Check if the string is a integer.
 *
 * @param string
 * @return true if the string is a integer, false otherwise.
 * @since v1.0.0
 */
bool string_get_is_integer(const string string_value);

/**
 * @brief Split a string into substrings using the specified separator and return them as an array and update the pointer `result_size` to the resulting size of the created array.
 *
 * @param string
 * @param separator
 * @since v1.0.0
 */
string* string_split(const string string_value, char separator, size_t* result_size);

/**
 * @brief Adds all the elements of an array into a string, separated by the specified separator string.
 *
 * @param array
 * @param separator
 * @since v1.0.0
 */
string string_join(string* array, const char separator, size_t array_length);

/**
 * @brief Concatenate two strings.
 *
 * @param string1
 * @param string2
 * @since v1.0.0
 */
string string_concatenate(string string1, string string2);

/**
 * @brief Check if a string contains only unique characters.
 *
 * @param string
 * @return true if string contains only unique characters, false otherwise.
 * @since v1.0.0
 */
bool string_get_has_unique_characters(const string string);

/**
 * @brief Returns the part of the string between the start and end indexes (both included).
 *
 * @param string
 * @param index_start
 * @param index_end
 * @since v1.0.0
 */
string string_substring(const string string_value, size_t index_start, size_t index_end);

/**
 * @brief Check if a string contains a substring.
 *
 * @param string
 * @param substring
 * @return true if the string contains the substring, false otherwise.
 * @since v1.0.0
 */
bool string_get_is_substring(const string string_value, const string substring);

/**
 * @brief Format a number to a string with specified separator.
 *
 * @param integer
 * @example string_get_formatted_number(1000, " ") // "1 000"
 * @since v1.0.0
 */
string string_get_formatted_number(const long long number, string separator);

/**
 * @brief Returns a pointer to the last occurrence of character in the string.
 *
 * @param string
 * @param character
 * @since v1.0.0
 */
string string_get_last_occurence_of_character(const string string_value, char character);

/**
 * @brief Check if a string starts with a substring.
 *
 * @param string
 * @param prefix
 * @return true if the string starts with the substring, false otherwise.
 * @since v1.0.0
 */
bool string_starts_with(const string string_value, const string prefix);

/**
 * @brief Check if a string ends with a substring.
 *
 * @param string
 * @param prefix
 * @return true if the string ends with the substring, false otherwise.
 * @since v1.0.0
 */
bool string_ends_with(const string string_value, const string prefix);

#endif
