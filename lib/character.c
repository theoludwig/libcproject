#include "character.h"

void character_append(string_t string_value, const char character) {
  size_t length = string_get_length(string_value);
  character_append_at(string_value, character, length);
}

void character_append_at(string_t string_value, const char character, const size_t index) {
  size_t length = string_get_length(string_value);
  for (size_t index_string = length; index_string > index; index_string--) {
    string_value[index_string] = string_value[index_string - 1];
  }
  string_value[index] = character;
  string_value[length + 1] = '\0';
}

char character_to_upper(const char character) {
  if (character >= 'a' && character <= 'z') {
    return character + ('A' - 'a');
  }
  return character;
}

char character_to_lower(const char character) {
  if (character >= 'A' && character <= 'Z') {
    return character - ('A' - 'a');
  }
  return character;
}

bool character_get_is_digit(const char character) {
  return character >= '0' && character <= '9';
}

unsigned char character_get_alphabet_position(const char character) {
  const char letter = character_to_lower(character);
  unsigned char position = 0;
  if (letter >= 'a' && letter <= 'z') {
    position = (letter - 'a') + 1;
  }
  return position;
}