#include "string.h"

size_t string_get_length(const string_t string) {
  size_t length = 0;
  while (string[length] != '\0') {
    length++;
  }
  return length;
}

void string_to_uppercase(string_t string) {
  size_t string_length = string_get_length(string);
  for (size_t index = 0; index < string_length; index++) {
    string[index] = character_to_upper(string[index]);
  }
  string[string_length] = '\0';
}

void string_to_lowercase(string_t string) {
  size_t string_length = string_get_length(string);
  for (size_t index = 0; index < string_length; index++) {
    string[index] = character_to_lower(string[index]);
  }
  string[string_length] = '\0';
}

void string_replace(string_t string, char search, char replace) {
  size_t string_length = string_get_length(string);
  for (size_t index = 0; index < string_length; index++) {
    bool is_search_value = search == string[index];
    if (is_search_value) {
      string[index] = replace;
    } else {
      string[index] = string[index];
    }
  }
  string[string_length] = '\0';
}

void string_trim_start(string_t string, char character) {
  size_t string_length = string_get_length(string);
  size_t index_space = 0;
  while (string[index_space] == character) {
    index_space++;
  }
  for (size_t index = 0; index < string_length - index_space; index++) {
    string[index] = string[index + index_space];
  }
  string[string_length - index_space] = '\0';
}

void string_trim_end(string_t string, char character) {
  size_t string_length = string_get_length(string);
  size_t index_space = string_length - 1;
  while (string[index_space] == character) {
    index_space--;
  }
  string[index_space + 1] = '\0';
}

void string_trim(string_t string, char character) {
  string_trim_start(string, character);
  string_trim_end(string, character);
}

string_t string_copy(const string_t string) {
  size_t source_length = string_get_length(string);
  string_t copy = malloc(sizeof(char) * (source_length + 1));
  if (copy == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t index;
  for (index = 0; index < source_length; index++) {
    copy[index] = string[index];
  }
  copy[index] = '\0';
  return copy;
}

void string_capitalize(string_t string) {
  size_t string_length = string_get_length(string);
  if (string_length == 0) {
    return;
  }
  string[0] = character_to_upper(string[0]);
}

size_t string_total_occurrences_of_character(string_t string, char character) {
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

void string_reverse(const string_t string) {
  size_t string_length = string_get_length(string);
  size_t index_start = 0;
  size_t index_end = string_length - 1;
  while (index_start < index_end) {
    char temporary = string[index_start];
    string[index_start] = string[index_end];
    string[index_end] = temporary;
    index_start++;
    index_end--;
  }
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

bool string_get_is_integer(const string_t string) {
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

string_t* string_split(const string_t string, char separator, size_t* result_size) {
  size_t string_length = string_get_length(string);
  size_t index_string = 0;
  size_t index_current = 0;
  size_t index_result = 0;
  string_t current = malloc(sizeof(char) * (string_length + 1));
  string_t* result = NULL;
  if (current == NULL) {
    exit(EXIT_FAILURE);
  }
  while (index_string < string_length) {
    if (string[index_string] == separator) {
      current[index_current] = '\0';
      result = realloc(result, sizeof(string_t) * (index_result + 1));
      if (result == NULL) {
        exit(EXIT_FAILURE);
      }
      result[index_result] = string_copy(current);
      index_result++;
      index_current = 0;
    } else {
      current[index_current] = string[index_string];
      index_current++;
    }
    index_string++;
  }

  current[index_current] = '\0';
  result = realloc(result, sizeof(string_t) * (index_result + 1));
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  result[index_result] = string_copy(current);
  free(current);
  *result_size = index_result + 1;
  return result;
}

string_t string_join(string_t* array, const char separator, size_t array_length) {
  size_t total_length = 0;
  for (size_t index_array = 0; index_array < array_length; index_array++) {
    total_length += string_get_length(array[index_array]);
  }
  size_t string_length = total_length + (array_length - 1);
  string_t string = malloc(sizeof(char) * (string_length + 1));
  if (string == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t current_index = 0;
  for (size_t index_array = 0; index_array < array_length; index_array++) {
    string_t substring = array[index_array];
    size_t substring_length = string_get_length(substring);
    for (size_t index_substring = 0; index_substring < substring_length; index_substring++) {
      string[current_index] = substring[index_substring];
      current_index++;
    }
    bool is_last_character = index_array == (array_length - 1);
    if (!is_last_character) {
      string[current_index] = separator;
      current_index++;
    }
  }
  string[string_length] = '\0';
  return string;
}

string_t string_concatenate(string_t string1, string_t string2) {
  size_t string1_length = string_get_length(string1);
  size_t string2_length = string_get_length(string2);
  size_t result_length = string1_length + string2_length;
  string_t result = malloc(sizeof(char) * (result_length + 1));
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t index_string1 = 0;
  for (; index_string1 < string1_length; index_string1++) {
    result[index_string1] = string1[index_string1];
  }
  for (size_t index_string2 = 0; index_string2 < string2_length; index_string2++) {
    result[index_string1 + index_string2] = string2[index_string2];
  }
  result[result_length] = '\0';
  return result;
}

bool string_get_has_unique_characters(const string_t string) {
  bool has_unique = true;
  size_t string_length = string_get_length(string);
  struct hash_map* characters_already_seen = hash_map_initialization();
  string_t* keys = malloc(sizeof(string_t) * string_length);
  for (size_t index = 0; index < string_length; index++) {
    keys[index] = NULL;
  }
  for (size_t index = 0; index < string_length && has_unique; index++) {
    char character = string[index];
    keys[index] = convert_character_to_string(character);
    string_t key = keys[index];
    if (hash_map_contains_key(characters_already_seen, key)) {
      has_unique = false;
    } else {
      hash_map_add(characters_already_seen, key, (void*)true);
    }
  }
  for (size_t index = 0; index < string_length; index++) {
    if (keys[index] != NULL) {
      free(keys[index]);
    }
  }
  free(keys);
  hash_map_free(characters_already_seen);
  return has_unique;
}

string_t string_substring(const string_t string, size_t index_start, size_t index_end) {
  size_t substring_length = index_end - index_start + 1;
  string_t result = malloc(sizeof(char) * (substring_length + 1));
  for (size_t index = 0; index < substring_length; index++) {
    result[index] = string[index_start + index];
  }
  result[substring_length] = '\0';
  return result;
}

bool string_get_is_substring(const string_t string, const string_t substring) {
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

string_t string_get_formatted_number(const long long number, string_t separator) {
  string_t number_string_temp = convert_number_to_string(number);
  string_t number_string = number_string_temp;
  bool is_negative = number_string_temp[0] == '-';
  if (is_negative) {
    number_string = string_substring(number_string_temp, 1, string_get_length(number_string_temp));
    free(number_string_temp);
  }
  size_t number_string_length = string_get_length(number_string);
  size_t formatted_length = number_string_length + (number_string_length - 1) / 3;
  string_t result = malloc(sizeof(char) * (formatted_length + 1));
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t count = 0;
  size_t result_index = 0;
  for (size_t index = 0; index < number_string_length; index++) {
    size_t index_reversed = number_string_length - index - 1;
    result[result_index] = number_string[index_reversed];
    count++;
    result_index++;
    if (count == 3 && index != number_string_length - 1) {
      for (size_t sep_index = 0; sep_index < string_get_length(separator); sep_index++) {
        result[result_index] = separator[sep_index];
        result_index++;
      }
      count = 0;
    }
  }
  free(number_string);
  result[formatted_length] = '\0';
  string_reverse(result);
  if (is_negative) {
    string_t dash = convert_character_to_string('-');
    string_t negative_result = string_concatenate(dash, result);
    free(result);
    free(dash);
    return negative_result;
  }
  return result;
}

string_t string_get_last_occurence_of_character(const string_t string, char character) {
  size_t string_length = string_get_length(string);
  size_t index_last_occurrence = SIZE_MAX;
  for (size_t index = 0; index < string_length; index++) {
    if (string[index] == character) {
      index_last_occurrence = index;
    }
  }
  if (index_last_occurrence == SIZE_MAX) {
    return "";
  }
  string_t result = malloc(sizeof(char) * (string_length - index_last_occurrence + 1));
  if (result == NULL) {
    exit(EXIT_FAILURE);
  }
  size_t index_result = 0;
  for (size_t index = index_last_occurrence; index < string_length; index++) {
    result[index_result++] = string[index];
  }
  result[index_result] = '\0';
  return result;
}

bool string_starts_with(const string_t string, const string_t prefix) {
  bool starts_with = true;
  size_t prefix_length = string_get_length(prefix);
  for (size_t index = 0; index < prefix_length && starts_with; index++) {
    starts_with = string[index] == prefix[index];
  }
  return starts_with;
}

bool string_ends_with(const string_t string, const string_t prefix) {
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
