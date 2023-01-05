#ifndef __STRING__
#define __STRING__

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Return the length of a string (excluding '\0').
 *
 * @param string
 * @return size_t
 */
size_t string_get_length(const char* string);

/**
 * @brief Converts all the alphabetic characters in a string to uppercase.
 *
 * @param string
 * @return char*
 */
char* string_to_uppercase(char* string);

/**
 * @brief Converts all the alphabetic characters in a string to lowercase.
 *
 * @param string
 * @return char*
 */
char* string_to_lowercase(char* string);

/**
 * @brief Replace all the occurrences of search value into replace value in the string.
 *
 * @param string
 * @param search_value A character search value.
 * @param replace_value A character containing the text to replace for match.
 * @return char*
 */
char* string_replace(char* string, char search, char replace);

/**
 * @brief Removes all whitespace from the start of a string.
 *
 * @param string
 * @return char*
 */
char* string_trim_start(char* string);

/**
 * @brief Removes all whitespace from the end of a string.
 *
 * @param string
 * @return char*
 */
char* string_trim_end(char* string);

/**
 * @brief Removes all whitespace from the start and end of a string.
 *
 * @param string
 * @return char*
 */
char* string_trim(char* string);

/**
 * @brief Return the copy of a string.
 *
 * @param string
 * @return char*
 */
char* string_copy(const char* string);

/**
 * @brief Capitalizes the string.
 *
 * @param string
 * @return char*
 */
char* string_capitalize(char* string);

/**
 * @brief Returns the total number of occurrences of the given character in the string.
 *
 * @param string
 * @param character
 * @return size_t
 */
size_t string_total_occurrences_of_character(char* string, char character);

/**
 * @brief Reverse the characters in an array.
 *
 * @param string
 * @return char*
 */
char* string_reverse(const char* string);

/**
 * @brief Check if two strings are equals.
 *
 * @param string1
 * @param string2
 * @return true if the strings are equals, false otherwise
 */
bool string_get_is_equal(const char* string1, const char* string2);

/**
 * @brief Check if the string is a integer.
 *
 * @param string
 * @return true if the string is a integer, false otherwise
 */
bool string_get_is_integer(const char* string);

/**
 * @brief Split a string into substrings using the specified separator and return them as an array and update the pointer `result_size` to the resulting size of the created array.
 *
 * @param string
 * @param separator
 * @return char**
 */
char** string_split(const char* string, char separator, size_t* result_size);

/**
 * @brief Adds all the elements of an array into a string, separated by the specified separator string.
 *
 * @param array
 * @param separator
 * @return char*
 */
char* string_join(char** array, const char separator, size_t array_length);

/**
 * @brief Concatenate two strings.
 *
 * @param string1
 * @param string2
 * @return char*
 */
char* string_concatenate(char* string1, char* string2);

/**
 * @brief Check if a string contains only unique characters.
 *
 * @param string
 * @return true if string contains only unique characters, false otherwise
 */
bool string_get_has_unique_characters(const char* string);

/**
 * @brief Returns the part of the string between the start and end indexes (both included).
 *
 * @param string
 * @param index_start
 * @param index_end
 * @return char*
 */
char* string_substring(const char* string, size_t index_start, size_t index_end);

/**
 * @brief Check if a string contains a substring.
 *
 * @param string
 * @param substring
 * @return true if the string contains the substring, false otherwise
 */
bool string_get_is_substring(const char* string, const char* substring);

/**
 * @brief Format a number to a string with specified separator.
 *
 * @param integer
 * @return char* example: string_get_formatted_number(1000, " ") => "1 000"
 */
char* string_get_formatted_number(const long long number, char* separator);

/**
 * @brief Returns a pointer to the last occurrence of character in the string.
 *
 * @param string
 * @param character
 * @return char*
 */
char* string_get_last_occurence_of_character(const char* string, char character);

/**
 * @brief Check if a string starts with a substring.
 *
 * @param string
 * @param prefix
 * @return true if the string starts with the substring, false otherwise
 */
bool string_starts_with(const char* string, const char* prefix);

/**
 * @brief Check if a string ends with a substring.
 *
 * @param string
 * @param prefix
 * @return true if the string ends with the substring, false otherwise
 */
bool string_ends_with(const char* string, const char* prefix);

#endif
