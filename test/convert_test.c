#include "convert_test.h"

void convert_test() {
  convert_character_to_string_test();
  convert_character_to_digit_test();
  convert_digit_to_character_test();
  convert_string_to_number_test();
  convert_number_to_string_test();
  convert_number_from_base_to_another_test();
}

void convert_character_to_string_test() {
  char* result = convert_character_to_string('a');
  assert(assert_string_equal(result, "a"));
  free(result);

  result = convert_character_to_string('A');
  assert(assert_string_equal(result, "A"));
  free(result);

  result = convert_character_to_string('0');
  assert(assert_string_equal(result, "0"));
  free(result);

  result = convert_character_to_string(' ');
  assert(assert_string_equal(result, " "));
  free(result);

  result = convert_character_to_string('\0');
  assert(assert_string_equal(result, ""));
  free(result);
}

void convert_character_to_digit_test() {
  assert(convert_character_to_digit('0') == 0);
  assert(convert_character_to_digit('1') == 1);
  assert(convert_character_to_digit('2') == 2);
  assert(convert_character_to_digit('3') == 3);
  assert(convert_character_to_digit('4') == 4);
  assert(convert_character_to_digit('5') == 5);
  assert(convert_character_to_digit('6') == 6);
  assert(convert_character_to_digit('7') == 7);
  assert(convert_character_to_digit('8') == 8);
  assert(convert_character_to_digit('9') == 9);
}

void convert_digit_to_character_test() {
  assert(convert_digit_to_character(0) == '0');
  assert(convert_digit_to_character(1) == '1');
  assert(convert_digit_to_character(2) == '2');
  assert(convert_digit_to_character(3) == '3');
  assert(convert_digit_to_character(4) == '4');
  assert(convert_digit_to_character(5) == '5');
  assert(convert_digit_to_character(6) == '6');
  assert(convert_digit_to_character(7) == '7');
  assert(convert_digit_to_character(8) == '8');
  assert(convert_digit_to_character(9) == '9');
}

void convert_string_to_number_test() {
  assert(convert_string_to_number("0") == 0);
  assert(convert_string_to_number("1") == 1);
  assert(convert_string_to_number("2") == 2);
  assert(convert_string_to_number("3") == 3);
  assert(convert_string_to_number("4") == 4);
  assert(convert_string_to_number("5") == 5);
  assert(convert_string_to_number("6") == 6);
  assert(convert_string_to_number("7") == 7);
  assert(convert_string_to_number("8") == 8);
  assert(convert_string_to_number("9") == 9);
  assert(convert_string_to_number("10") == 10);
  assert(convert_string_to_number("11") == 11);
  assert(convert_string_to_number("20") == 20);
  assert(convert_string_to_number("-0") == 0);
  assert(convert_string_to_number("-1") == -1);
  assert(convert_string_to_number("-20") == -20);
}

void convert_number_to_string_test() {
  char* result = convert_number_to_string(0);
  assert(assert_string_equal(result, "0"));
  free(result);

  result = convert_number_to_string(1);
  assert(assert_string_equal(result, "1"));
  free(result);

  result = convert_number_to_string(2);
  assert(assert_string_equal(result, "2"));
  free(result);

  result = convert_number_to_string(3);
  assert(assert_string_equal(result, "3"));
  free(result);

  result = convert_number_to_string(4);
  assert(assert_string_equal(result, "4"));
  free(result);

  result = convert_number_to_string(5);
  assert(assert_string_equal(result, "5"));
  free(result);

  result = convert_number_to_string(6);
  assert(assert_string_equal(result, "6"));
  free(result);

  result = convert_number_to_string(7);
  assert(assert_string_equal(result, "7"));
  free(result);

  result = convert_number_to_string(8);
  assert(assert_string_equal(result, "8"));
  free(result);

  result = convert_number_to_string(9);
  assert(assert_string_equal(result, "9"));
  free(result);

  result = convert_number_to_string(10);
  assert(assert_string_equal(result, "10"));
  free(result);

  result = convert_number_to_string(11);
  assert(assert_string_equal(result, "11"));
  free(result);

  result = convert_number_to_string(20);
  assert(assert_string_equal(result, "20"));
  free(result);

  result = convert_number_to_string(-0);
  assert(assert_string_equal(result, "0"));
  free(result);

  result = convert_number_to_string(-1);
  assert(assert_string_equal(result, "-1"));
  free(result);

  result = convert_number_to_string(-20);
  assert(assert_string_equal(result, "-20"));
  free(result);
}

void convert_number_from_base_to_another_test() {
  char* result = convert_number_from_base_to_another("15", 10, 16);
  assert(assert_string_equal(result, "F"));
  free(result);

  result = convert_number_from_base_to_another("100000000", 2, 16);
  assert(assert_string_equal(result, "100"));
  free(result);

  result = convert_number_from_base_to_another("FFFFFF", 16, 10);
  assert(assert_string_equal(result, "16777215"));
  free(result);

  result = convert_number_from_base_to_another("1D57", 17, 35);
  assert(assert_string_equal(result, "75C"));
  free(result);

  result = convert_number_from_base_to_another("80E", 20, 5);
  assert(assert_string_equal(result, "100324"));
  free(result);

  result = convert_number_from_base_to_another("99", 10, 10);
  assert(assert_string_equal(result, "99"));
  free(result);

  result = convert_number_from_base_to_another("3433024", 6, 28);
  assert(assert_string_equal(result, "8008"));
  free(result);

  result = convert_number_from_base_to_another("30288G3A", 17, 36);
  assert(assert_string_equal(result, "KF12OI"));
  free(result);

  result = convert_number_from_base_to_another("10", 9, 9);
  assert(assert_string_equal(result, "10"));
  free(result);

  result = convert_number_from_base_to_another("10E", 23, 8);
  assert(assert_string_equal(result, "1037"));
  free(result);
}
