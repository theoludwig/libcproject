#include "string.h"

size_t string_get_length(const string_t string_value) {
  size_t length = 0;
  while (string_value[length] != '\0') {
    length++;
  }
  return length;
}

string_t string_to_uppercase(string_t string_value) {
  size_t string_length = string_get_length(string_value);
  string_t result = malloc(sizeof(string_t) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t index = 0; index < string_length; index++) {
    character_append(result, character_to_upper(string_value[index]));
  }
  return result;
}

string_t string_to_lowercase(string_t string_value) {
  size_t string_length = string_get_length(string_value);
  string_t result = malloc(sizeof(string_t) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t index = 0; index < string_length; index++) {
    character_append(result, character_to_lower(string_value[index]));
  }
  return result;
}

string_t string_replace(string_t string_value, char search, char replace) {
  size_t string_length = string_get_length(string_value);
  string_t result = malloc(sizeof(string_t) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t index = 0; index < string_length; index++) {
    bool is_search_value = search == string_value[index];
    if (is_search_value) {
      character_append(result, replace);
    } else {
      character_append(result, string_value[index]);
    }
  }
  return result;
}

string_t string_trim_start(string_t string_value) {
  size_t string_length = string_get_length(string_value);
  string_t result = malloc(sizeof(string_t) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t index_space = 0;
  while (string_value[index_space] == ' ') {
    index_space++;
  }
  for (size_t index = index_space; index < string_length; index++) {
    character_append(result, string_value[index]);
  }
  return result;
}

string_t string_trim_end(string_t string_value) {
  size_t string_length = string_get_length(string_value);
  string_t result = malloc(sizeof(string_t) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t index_space = string_length - 1;
  while (string_value[index_space] == ' ') {
    index_space--;
  }
  for (size_t index = 0; index < index_space + 1; index++) {
    character_append(result, string_value[index]);
  }
  return result;
}

string_t string_trim(string_t string_value) {
  string_t result = string_trim_start(string_value);
  result = string_trim_end(result);
  return result;
}

string_t string_copy(const string_t string_value) {
  return string_substring(string_value, 0, string_get_length(string_value));
}

string_t string_capitalize(string_t string_value) {
  size_t string_length = string_get_length(string_value);
  string_t result = malloc(sizeof(string_t) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t index = 0; index < string_length; index++) {
    bool is_first_character = index == 0;
    if (is_first_character) {
      character_append(result, character_to_upper(string_value[index]));
    } else {
      character_append(result, string_value[index]);
    }
  }
  return result;
}

size_t string_total_occurrences_of_character(string_t string_value, char character) {
  size_t result = 0;
  size_t string_length = string_get_length(string_value);
  for (size_t index = 0; index < string_length; index++) {
    char current_character = string_value[index];
    if (current_character == character) {
      result += 1;
    }
  }
  return result;
}

string_t string_reverse(const string_t string_value) {
  size_t string_length = string_get_length(string_value);
  size_t index = 0;
  string_t result = malloc(sizeof(string_t) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  for (index = string_length - 1; index > 0; index--) {
    character_append(result, string_value[index]);
  }
  character_append(result, string_value[index]);
  return result;
}

bool string_equals(const string_t string1, const string_t string2) {
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

bool string_get_is_integer(const string_t string_value) {
  size_t index = 0;
  size_t string_length = string_get_length(string_value);
  bool is_integer = string_length >= 1;
  if (is_integer && string_value[0] == '-') {
    if (string_length == 1) {
      is_integer = false;
    } else {
      index++;
    }
  }
  while (index < string_length && is_integer) {
    if (!character_get_is_digit(string_value[index])) {
      is_integer = false;
    }
    index++;
  }
  return is_integer;
}

string_t* string_split(const string_t string_value, char separator, size_t* result_size) {
  size_t string_length = string_get_length(string_value);
  size_t index_string = 0;
  size_t index_current = 0;
  size_t index_result = 0;
  string_t current = malloc(sizeof(string_t) * string_length);
  string_t* result = malloc(sizeof(string_t*) * index_result);
  if (result == NULL || current == NULL) {
    exit(EXIT_FAILURE);
  }
  while (index_string < string_length) {
    if (string_value[index_string] == separator) {
      result[index_result] = string_copy(current);
      index_result++;
      result = realloc(result, sizeof(string_value) * index_result);
      if (result == NULL) {
        exit(EXIT_FAILURE);
      }
      index_current = 0;
      current = string_copy("");
    } else {
      character_append(current, string_value[index_string]);
      index_current++;
    }
    index_string++;
  }
  result[index_result] = string_copy(current);
  free(current);
  *result_size = index_result + 1;
  return result;
}

string_t string_join(string_t* array, const char separator, size_t array_length) {
  size_t string_length = array_length;
  string_t string_value = malloc(sizeof(string_value) * string_length);
  if (string_value == NULL) {
    exit(EXIT_FAILURE);
  }
  for (size_t index_array = 0; index_array < array_length; index_array++) {
    string_t substring = array[index_array];
    size_t substring_length = string_get_length(substring);
    string_length += substring_length;
    string_value = realloc(string_value, sizeof(string_value) * string_length);
    if (string_value == NULL) {
      exit(EXIT_FAILURE);
    }
    for (size_t index_substring = 0; index_substring < substring_length; index_substring++) {
      character_append(string_value, substring[index_substring]);
    }
    bool is_last_character = index_array == (array_length - 1);
    if (!is_last_character) {
      character_append(string_value, separator);
    }
  }
  return string_value;
}

string_t string_concatenate(string_t string1, string_t string2) {
  size_t string1_length = string_get_length(string1);
  size_t string2_length = string_get_length(string2);
  size_t result_length = string1_length + string2_length;
  string_t result = malloc(sizeof(string_t) * result_length);
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

bool string_get_has_unique_characters(const string_t string_value) {
  bool has_unique = true;
  size_t string_length = string_get_length(string_value);
  struct hash_map* characters_already_seen = hash_map_initialization();
  for (size_t index = 0; index < string_length && has_unique; index++) {
    char character = string_value[index];
    string_t key = convert_character_to_string(character);
    if (hash_map_contains_key(characters_already_seen, key)) {
      has_unique = false;
    } else {
      hash_map_add(characters_already_seen, key, (void*)true);
    }
  }
  return has_unique;
}

string_t string_substring(const string_t string_value, size_t index_start, size_t index_end) {
  size_t string_length = string_get_length(string_value);
  string_t result = malloc(sizeof(string_t) * string_length);
  for (size_t index = index_start; index <= index_end; index++) {
    character_append(result, string_value[index]);
  }
  return result;
}

bool string_get_is_substring(const string_t string_value, const string_t substring) {
  bool is_substring = false;
  size_t string_length = string_get_length(string_value);
  size_t substring_length = string_get_length(substring);
  for (size_t index_string = 0; index_string < string_length && !is_substring; index_string++) {
    size_t index_substring = 0;
    size_t index_considered = index_string;
    while (index_substring < substring_length && string_value[index_considered] == substring[index_substring]) {
      index_substring++;
      index_considered++;
    }
    is_substring = index_substring == substring_length;
  }
  return is_substring;
}

string_t string_get_formatted_number(const long long number, string_t separator) {
  string_t number_string = convert_number_to_string(number);
  bool is_negative = number_string[0] == '-';
  if (is_negative) {
    number_string = string_substring(number_string, 1, string_get_length(number_string));
  }
  size_t number_string_length = string_get_length(number_string);
  string_t result = malloc(sizeof(string_t) * number_string_length);
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

string_t string_get_last_occurence_of_character(const string_t string_value, char character) {
  size_t string_length = string_get_length(string_value);
  string_t result = malloc(sizeof(string_t) * string_length);
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t index_result = 0;
  for (size_t index = 0; index < string_length; index++) {
    if (string_value[index] == character) {
      index_result = 0;
      result = string_copy("");
    }
    character_append(result, string_value[index]);
    index_result++;
  }
  return result;
}

bool string_starts_with(const string_t string_value, const string_t prefix) {
  bool starts_with = true;
  size_t prefix_length = string_get_length(prefix);
  for (size_t index = 0; index < prefix_length && starts_with; index++) {
    starts_with = string_value[index] == prefix[index];
  }
  return starts_with;
}

bool string_ends_with(const string_t string_value, const string_t prefix) {
  bool ends_with = true;
  size_t string_length = string_get_length(string_value);
  size_t prefix_length = string_get_length(prefix);
  size_t index_string = string_length - 1;
  size_t index_prefix = prefix_length - 1;
  while (index_prefix > 0 && ends_with) {
    ends_with = string_value[index_string] == prefix[index_prefix];
    index_string--;
    index_prefix--;
  }
  return ends_with;
}
