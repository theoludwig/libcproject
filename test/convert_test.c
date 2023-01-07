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
  assert(assert_string_equal(convert_character_to_string('a'), "a"));
  assert(assert_string_equal(convert_character_to_string('A'), "A"));
  assert(assert_string_equal(convert_character_to_string('0'), "0"));
  assert(assert_string_equal(convert_character_to_string(' '), " "));
  assert(assert_string_equal(convert_character_to_string('\0'), ""));
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
  assert(assert_string_equal(convert_number_to_string(0), "0"));
  assert(assert_string_equal(convert_number_to_string(1), "1"));
  assert(assert_string_equal(convert_number_to_string(2), "2"));
  assert(assert_string_equal(convert_number_to_string(3), "3"));
  assert(assert_string_equal(convert_number_to_string(4), "4"));
  assert(assert_string_equal(convert_number_to_string(5), "5"));
  assert(assert_string_equal(convert_number_to_string(6), "6"));
  assert(assert_string_equal(convert_number_to_string(7), "7"));
  assert(assert_string_equal(convert_number_to_string(8), "8"));
  assert(assert_string_equal(convert_number_to_string(9), "9"));
  assert(assert_string_equal(convert_number_to_string(10), "10"));
  assert(assert_string_equal(convert_number_to_string(11), "11"));
  assert(assert_string_equal(convert_number_to_string(20), "20"));
  assert(assert_string_equal(convert_number_to_string(-0), "0"));
  assert(assert_string_equal(convert_number_to_string(-1), "-1"));
  assert(assert_string_equal(convert_number_to_string(-20), "-20"));
}

void convert_number_from_base_to_another_test() {
  assert(assert_string_equal(convert_number_from_base_to_another("15", 10, 16), "F"));
  assert(assert_string_equal(convert_number_from_base_to_another("100000000", 2, 16), "100"));
  assert(assert_string_equal(convert_number_from_base_to_another("FFFFFF", 16, 10), "16777215"));
  assert(assert_string_equal(convert_number_from_base_to_another("1D57", 17, 35), "75C"));
  assert(assert_string_equal(convert_number_from_base_to_another("80E", 20, 5), "100324"));
  assert(assert_string_equal(convert_number_from_base_to_another("99", 10, 10), "99"));
  assert(assert_string_equal(convert_number_from_base_to_another("3433024", 6, 28), "8008"));
  assert(assert_string_equal(convert_number_from_base_to_another("30288G3A", 17, 36), "KF12OI"));
  assert(assert_string_equal(convert_number_from_base_to_another("10", 9, 9), "10"));
  assert(assert_string_equal(convert_number_from_base_to_another("10E", 23, 8), "1037"));
}
