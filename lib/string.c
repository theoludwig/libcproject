#include "string.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "character.h"
#include "convert.h"
#include "dictionary.h"

size_t string_get_length(const char* string) {
  size_t length = 0;
  while (string[length] != '\0') {
    length++;
  }
  return length;
}

char* string_to_uppercase(char* string) {
  size_t string_length = string_get_length(string);
  char* result = malloc(sizeof(char*) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t index = 0; index < string_length; index++) {
    character_append(result, character_to_upper(string[index]));
  }
  return result;
}

char* string_to_lowercase(char* string) {
  size_t string_length = string_get_length(string);
  char* result = malloc(sizeof(char*) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t index = 0; index < string_length; index++) {
    character_append(result, character_to_lower(string[index]));
  }
  return result;
}

char* string_replace(char* string, char search, char replace) {
  size_t string_length = string_get_length(string);
  char* result = malloc(sizeof(char*) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t index = 0; index < string_length; index++) {
    bool is_search_value = search == string[index];
    if (is_search_value) {
      character_append(result, replace);
    } else {
      character_append(result, string[index]);
    }
  }
  return result;
}

char* string_trim_start(char* string) {
  size_t string_length = string_get_length(string);
  char* result = malloc(sizeof(char*) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t index_space = 0;
  while (string[index_space] == ' ') {
    index_space++;
  }
  for (size_t index = index_space; index < string_length; index++) {
    character_append(result, string[index]);
  }
  return result;
}

char* string_trim_end(char* string) {
  size_t string_length = string_get_length(string);
  char* result = malloc(sizeof(char*) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t index_space = string_length - 1;
  while (string[index_space] == ' ') {
    index_space--;
  }
  for (size_t index = 0; index < index_space + 1; index++) {
    character_append(result, string[index]);
  }
  return result;
}

char* string_trim(char* string) {
  char* result = string_trim_start(string);
  result = string_trim_end(result);
  return result;
}

char* string_copy(const char* string) {
  return string_substring(string, 0, string_get_length(string));
}

char* string_capitalize(char* string) {
  size_t string_length = string_get_length(string);
  char* result = malloc(sizeof(char*) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t index = 0; index < string_length; index++) {
    bool is_first_character = index == 0;
    if (is_first_character) {
      character_append(result, character_to_upper(string[index]));
    } else {
      character_append(result, string[index]);
    }
  }
  return result;
}

size_t string_total_occurrences_of_character(char* string, char character) {
  size_t result = 0;
  size_t string_length = string_get_length(string);
  for (size_t index = 0; index < string_length; index++) {
    char current_character = string[index];
    if (current_character == character) {
      result += 1;
    }
  }
  return result;
}

char* string_reverse(const char* string) {
  size_t string_length = string_get_length(string);
  size_t index = 0;
  char* result = malloc(sizeof(char*) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  for (index = string_length - 1; index > 0; index--) {
    character_append(result, string[index]);
  }
  character_append(result, string[index]);
  return result;
}

bool string_equals(const char* string1, const char* string2) {
  size_t string1_length = string_get_length(string1);
  size_t string2_length = string_get_length(string2);
  bool is_equal = string1_length == string2_length;
  for (size_t index = 0; index < string1_length && is_equal; index++) {
    if (string1[index] != string2[index]) {
      is_equal = false;
    }
  }
  return is_equal;
}

bool string_get_is_integer(const char* string) {
  size_t index = 0;
  size_t string_length = string_get_length(string);
  bool is_integer = string_length >= 1;
  if (is_integer && string[0] == '-') {
    if (string_length == 1) {
      is_integer = false;
    } else {
      index++;
    }
  }
  while (index < string_length && is_integer) {
    if (!character_get_is_digit(string[index])) {
      is_integer = false;
    }
    index++;
  }
  return is_integer;
}

char** string_split(const char* string, char separator, size_t* result_size) {
  size_t string_length = string_get_length(string);
  size_t index_string = 0;
  size_t index_current = 0;
  size_t index_result = 0;
  char* current = malloc(sizeof(char*) * string_length);
  char** result = malloc(sizeof(char**) * index_result);
  if (result == NULL || current == NULL) {
    exit(EXIT_FAILURE);
  }
  while (index_string < string_length) {
    if (string[index_string] == separator) {
      result[index_result] = string_copy(current);
      index_result++;
      result = realloc(result, sizeof(char*) * index_result);
      if (result == NULL) {
        exit(EXIT_FAILURE);
      }
      index_current = 0;
      current = string_copy("");
    } else {
      character_append(current, string[index_string]);
      index_current++;
    }
    index_string++;
  }
  result[index_result] = string_copy(current);
  free(current);
  *result_size = index_result + 1;
  return result;
}

char* string_join(char** array, const char separator, size_t array_length) {
  size_t string_length = array_length;
  char* string = malloc(sizeof(char*) * string_length);
  if (string == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t index_array = 0; index_array < array_length; index_array++) {
    char* substring = array[index_array];
    size_t substring_length = string_get_length(substring);
    string_length += substring_length;
    string = realloc(string, sizeof(char*) * string_length);
    if (string == NULL) {
      exit(EXIT_FAILURE);
    }
    for (size_t index_substring = 0; index_substring < substring_length; index_substring++) {
      character_append(string, substring[index_substring]);
    }
    bool is_last_character = index_array == (array_length - 1);
    if (!is_last_character) {
      character_append(string, separator);
    }
  }
  return string;
}

char* string_concatenate(char* string1, char* string2) {
  size_t string1_length = string_get_length(string1);
  size_t string2_length = string_get_length(string2);
  size_t result_length = string1_length + string2_length;
  char* result = malloc(sizeof(char*) * result_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t index_string1 = 0; index_string1 < string1_length; index_string1++) {
    character_append(result, string1[index_string1]);
  }
  for (size_t index_string2 = 0; index_string2 < string2_length; index_string2++) {
    character_append(result, string2[index_string2]);
  }
  return result;
}

bool string_get_has_unique_characters(const char* string) {
  bool has_unique = true;
  size_t string_length = string_get_length(string);
  struct dictionary* characters_already_seen = dictionary_initialization();
  for (size_t index = 0; index < string_length && has_unique; index++) {
    char character = string[index];
    char* key = convert_character_to_string(character);
    if (dictionary_contains_key(characters_already_seen, key)) {
      has_unique = false;
    } else {
      dictionary_add(characters_already_seen, key, (void*)true);
    }
  }
  return has_unique;
}

char* string_substring(const char* string, size_t index_start, size_t index_end) {
  size_t string_length = string_get_length(string);
  char* result = malloc(sizeof(char*) * string_length);
  for (size_t index = index_start; index <= index_end; index++) {
    character_append(result, string[index]);
  }
  return result;
}

bool string_get_is_substring(const char* string, const char* substring) {
  bool is_substring = false;
  size_t string_length = string_get_length(string);
  size_t substring_length = string_get_length(substring);
  for (size_t index_string = 0; index_string < string_length && !is_substring; index_string++) {
    size_t index_substring = 0;
    size_t index_considered = index_string;
    while (index_substring < substring_length && string[index_considered] == substring[index_substring]) {
      index_substring++;
      index_considered++;
    }
    is_substring = index_substring == substring_length;
  }
  return is_substring;
}

char* string_get_formatted_number(const long long number, char* separator) {
  char* number_string = convert_number_to_string(number);
  bool is_negative = number_string[0] == '-';
  if (is_negative) {
    number_string = string_substring(number_string, 1, string_get_length(number_string));
  }
  size_t number_string_length = string_get_length(number_string);
  char* result = malloc(sizeof(char*) * number_string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t count = 0;
  for (size_t index = 0; index < number_string_length; index++) {
    size_t index_reversed = number_string_length - index - 1;
    count++;
    result = string_concatenate(result, convert_character_to_string(number_string[index_reversed]));
    if (count == 3) {
      result = string_concatenate(result, separator);
      count = 0;
    }
  }
  result = string_reverse(result);
  size_t result_length = string_get_length(result);
  if (result_length % 4 == 0) {
    result = string_substring(result, 1, result_length);
  }
  if (is_negative) {
    result = string_concatenate(convert_character_to_string('-'), result);
  }
  return result;
}

char* string_get_last_occurence_of_character(const char* string, char character) {
  size_t string_length = string_get_length(string);
  char* result = malloc(sizeof(char*) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t index_result = 0;
  for (size_t index = 0; index < string_length; index++) {
    if (string[index] == character) {
      index_result = 0;
      result = string_copy("");
    }
    character_append(result, string[index]);
    index_result++;
  }
  return result;
}

bool string_starts_with(const char* string, const char* prefix) {
  bool starts_with = true;
  size_t prefix_length = string_get_length(prefix);
  for (size_t index = 0; index < prefix_length && starts_with; index++) {
    starts_with = string[index] == prefix[index];
  }
  return starts_with;
}

bool string_ends_with(const char* string, const char* prefix) {
  bool ends_with = true;
  size_t string_length = string_get_length(string);
  size_t prefix_length = string_get_length(prefix);
  size_t index_string = string_length - 1;
  size_t index_prefix = prefix_length - 1;
  while (index_prefix > 0 && ends_with) {
    ends_with = string[index_string] == prefix[index_prefix];
    index_string--;
    index_prefix--;
  }
  return ends_with;
}
