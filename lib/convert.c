#include "convert.h"

char* convert_character_to_string(const char character) {
  char* string = malloc(sizeof(char*) * 2);
  if (string == NULL) {
    exit(EXIT_FAILURE);
  }
  character_append(string, character);
  return string;
}

char convert_character_to_digit(const char character) {
  return character - '0';
}

char convert_digit_to_character(const char digit) {
  return digit + '0';
}

long long convert_string_to_number(const char* string) {
  bool is_negative = string[0] == '-';
  long long integer = 0;
  size_t length = string_get_length(string);
  for (size_t index = is_negative ? 1 : 0; index < length; index++) {
    integer = integer * 10 + convert_character_to_digit(string[index]);
  }
  return is_negative ? integer * -1 : integer;
}

char* convert_number_to_string(const long long integer) {
  if (integer == 0) {
    return convert_character_to_string('0');
  }
  bool is_negative = integer < 0;
  size_t length = 1;
  char* string = malloc(sizeof(char*) * length);
  if (string == NULL) {
    exit(EXIT_FAILURE);
  }
  long long current = mathematics_absolute_value(integer);
  while (current != 0) {
    character_append(string, convert_digit_to_character(current % 10));
    current = current / 10;
    length++;
    string = realloc(string, sizeof(char*) * length);
  }
  if (is_negative) {
    character_append(string, '-');
    length++;
    string = realloc(string, sizeof(char*) * length);
  }
  return string_reverse(string);
}

char* convert_number_from_base_10_to_base(unsigned long long number, unsigned int base) {
  if (number == 0) {
    return "0";
  }
  int remainders[64];
  int index = 0;
  while (number > 0) {
    remainders[index] = number % base;
    number = number / base;
    index++;
  }
  char* result = malloc(sizeof(char) * (index + 1));
  int index_result = 0;
  for (int iteration = index - 1; iteration >= 0; iteration--) {
    int remainder = remainders[iteration];
    if (remainder >= 10) {
      result[index_result] = (char)((remainder - 10) + 'A');
    } else {
      result[index_result] = (char)(remainder + '0');
    }
    index_result++;
  }
  return result;
}

int convert_number_from_base_to_base_10(char* number, unsigned int base) {
  int length = string_get_length(number);
  int exponent = length - 1;
  int result = 0;
  int index = 0;
  while (exponent >= 0) {
    int current_number = (int)(number[index] - '0');
    if (current_number >= 10) {
      current_number = (int)(number[index] - 'A') + 10;
    } else {
      current_number = (int)(number[index] - '0');
    }
    result = result + current_number * mathematics_pow(base, exponent);
    exponent--;
    index++;
  }
  return result;
}

char* convert_number_from_base_to_another(char* number, int base_from, int base_target) {
  return convert_number_from_base_10_to_base(convert_number_from_base_to_base_10(number, base_from), base_target);
}
