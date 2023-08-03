#include "character_test.h"

void character_test() {
  character_append_test();
  character_append_at_test();
  character_to_upper_test();
  character_to_lower_test();
  character_get_is_digit_test();
  character_get_alphabet_position_test();
}

void character_append_test() {
  char string[5] = "abc";
  character_append(string, 'd');
  assert(assert_string_equal(string, "abcd"));
}

void character_append_at_test() {
  char string[5] = "abc";
  character_append_at(string, 'd', 1);
  assert(assert_string_equal(string, "adbc"));

  char string2[6] = "abcd";
  character_append_at(string2, 'e', 4);
  assert(assert_string_equal(string2, "abcde"));
}

void character_to_upper_test() {
  assert(character_to_upper('a') == 'A');
  assert(character_to_upper('e') == 'E');
  assert(character_to_upper('A') == 'A');
}

void character_to_lower_test() {
  assert(character_to_lower('A') == 'a');
  assert(character_to_lower('E') == 'e');
  assert(character_to_lower('a') == 'a');
}

void character_get_is_digit_test() {
  assert(character_get_is_digit('0'));
  assert(character_get_is_digit('1'));
  assert(character_get_is_digit('2'));
  assert(character_get_is_digit('3'));
  assert(character_get_is_digit('4'));
  assert(character_get_is_digit('5'));
  assert(character_get_is_digit('6'));
  assert(character_get_is_digit('7'));
  assert(character_get_is_digit('8'));
  assert(character_get_is_digit('9'));
  assert(!character_get_is_digit('a'));
  assert(!character_get_is_digit('/'));
  assert(!character_get_is_digit(':'));
}

void character_get_alphabet_position_test() {
  assert(character_get_alphabet_position('a') == 1);
  assert(character_get_alphabet_position('A') == 1);
  assert(character_get_alphabet_position('B') == 2);
  assert(character_get_alphabet_position('D') == 4);
  assert(character_get_alphabet_position('m') == 13);
  assert(character_get_alphabet_position('n') == 14);
  assert(character_get_alphabet_position('z') == 26);
  assert(character_get_alphabet_position('@') == 0);
  assert(character_get_alphabet_position('-') == 0);
}
