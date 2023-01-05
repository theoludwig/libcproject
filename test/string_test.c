#include "string_test.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "libcproject.h"
#include "test.h"

void string_test() {
  string_get_length_test();
  string_to_uppercase_test();
  string_to_lowercase_test();
  string_replace_test();
  string_trim_start_test();
  string_trim_end_test();
  string_trim_test();
  string_copy_test();
  string_capitalize_test();
  string_total_occurrences_of_character_test();
  string_reverse_test();
  string_equals_test();
  string_get_is_integer_test();
  string_split_test();
  string_join_test();
  string_concatenate_test();
  string_get_has_unique_characters_test();
  string_substring_test();
  string_get_is_substring_test();
  string_get_formatted_number_test();
  string_get_last_occurence_of_character_test();
  string_starts_with_test();
  string_ends_with_test();
}

void string_get_length_test() {
  char *string = "Hello World!";
  size_t string_length = string_get_length(string);
  assert(string_length == 12);
}

void string_to_uppercase_test() {
  char *string = "heLlO world";
  string = string_to_uppercase(string);
  assert(assert_string_equal(string, "HELLO WORLD"));
}

void string_to_lowercase_test() {
  char *string = "HellO WoRLd";
  string = string_to_lowercase(string);
  assert(assert_string_equal(string, "hello world"));
}

void string_replace_test() {
  char *string = "hello world";
  string = string_replace(string, 'l', 'z');
  assert(assert_string_equal(string, "hezzo worzd"));
}

void string_trim_start_test() {
  char *string = "      hello world      ";
  string = string_trim_start(string);
  assert(assert_string_equal(string, "hello world      "));
}

void string_trim_end_test() {
  char *string = "      hello world      ";
  string = string_trim_end(string);
  assert(assert_string_equal(string, "      hello world"));
}

void string_trim_test() {
  char *string = "      hello world      ";
  string = string_trim(string);
  assert(assert_string_equal(string, "hello world"));
}

void string_copy_test() {
  char *string = "hello world";
  char *string2 = string_copy(string);
  assert(assert_string_equal(string, string2));
  string2[0] = 'a';
  assert(assert_string_not_equal(string, string2));
  assert(assert_string_equal(string, "hello world"));
  assert(assert_string_equal(string2, "aello world"));
}

void string_capitalize_test() {
  char *string = "hello world";
  string = string_capitalize(string);
  assert(assert_string_equal(string, "Hello world"));
}

void string_total_occurrences_of_character_test() {
  char *string = "hello world";
  assert(string_total_occurrences_of_character(string, 'l') == 3);
}

void string_reverse_test() {
  char *string = "hello world";
  string = string_reverse(string);
  assert(assert_string_equal(string, "dlrow olleh"));
}

void string_equals_test() {
  char *string1 = "hello world";
  char *string2 = "dlrow olleh";
  char *string3 = "dlrow olleh";
  assert(!string_equals(string1, string2));
  assert(string_equals(string1, string1));
  assert(string_equals(string2, string3));
}

void string_get_is_integer_test() {
  assert(string_get_is_integer("1"));
  assert(string_get_is_integer("12"));
  assert(string_get_is_integer("-12"));
  assert(!string_get_is_integer("1 000"));
  assert(!string_get_is_integer("abc"));
  assert(!string_get_is_integer("- 12"));
  assert(!string_get_is_integer(" -12"));
  assert(!string_get_is_integer("-12 "));
  assert(!string_get_is_integer("-"));
}

void string_split_test() {
  char *string = "abc def ghij kl";
  size_t result_length = 0;
  char **result = string_split(string, ' ', &result_length);
  assert(result_length == 4);
  assert(assert_string_equal(result[0], "abc"));
  assert(assert_string_equal(result[1], "def"));
  assert(assert_string_equal(result[2], "ghij"));
  assert(assert_string_equal(result[3], "kl"));
}

void string_join_test() {
  char *string = "abc def ghij kl";
  size_t result_length = 0;
  char **result = string_split(string, ' ', &result_length);
  char *new_string = string_join(result, ' ', result_length);
  char *new_string2 = string_join(result, '+', result_length);
  assert(assert_string_equal(new_string, string));
  assert(assert_string_equal(new_string2, "abc+def+ghij+kl"));
}

void string_concatenate_test() {
  assert(assert_string_equal(string_concatenate("abc", "def"), "abcdef"));
  assert(assert_string_equal(string_concatenate("abc ", " defghi"), "abc  defghi"));
}

void string_get_has_unique_characters_test() {
  assert(string_get_has_unique_characters("ABCDEF"));
  assert(!string_get_has_unique_characters("AAABCDEF"));
  assert(!string_get_has_unique_characters("AaaBCDEF"));
}

void string_substring_test() {
  char *string = "abcdef";
  char *substring = string_substring(string, 1, 3);
  assert(assert_string_equal(substring, "bcd"));
}

void string_get_is_substring_test() {
  char *string = "abcdef";
  assert(string_get_is_substring(string, "abc"));
  assert(string_get_is_substring(string, "bcd"));
  assert(string_get_is_substring(string, "de"));
  assert(string_get_is_substring(string, "f"));
  assert(!string_get_is_substring(string, "af"));
  assert(string_get_is_substring("3662277", "2277"));
  assert(string_get_is_substring("3662277", "62"));
  assert(!string_get_is_substring("3662277", "322"));
}

void string_get_formatted_number_test() {
  assert(assert_string_equal(string_get_formatted_number(1000, " "), "1 000"));
  assert(assert_string_equal(string_get_formatted_number(123, ","), "123"));
  assert(assert_string_equal(string_get_formatted_number(1234, ","), "1,234"));
  assert(assert_string_equal(string_get_formatted_number(12345, ","), "12,345"));
  assert(assert_string_equal(string_get_formatted_number(123456, ","), "123,456"));
  assert(assert_string_equal(string_get_formatted_number(1234567, ","), "1,234,567"));
  assert(assert_string_equal(string_get_formatted_number(12345678, ","), "12,345,678"));
  assert(assert_string_equal(string_get_formatted_number(123456789, ","), "123,456,789"));
  assert(assert_string_equal(string_get_formatted_number(1234567890, ","), "1,234,567,890"));
  assert(assert_string_equal(string_get_formatted_number(-123, ","), "-123"));
  assert(assert_string_equal(string_get_formatted_number(-1234, ","), "-1,234"));
  assert(assert_string_equal(string_get_formatted_number(-12345, ","), "-12,345"));
  assert(assert_string_equal(string_get_formatted_number(-123456, ","), "-123,456"));
  assert(assert_string_equal(string_get_formatted_number(-1234567, ","), "-1,234,567"));
  assert(assert_string_equal(string_get_formatted_number(-12345678, ","), "-12,345,678"));
  assert(assert_string_equal(string_get_formatted_number(-123456789, ","), "-123,456,789"));
  assert(assert_string_equal(string_get_formatted_number(-1234567890, ","), "-1,234,567,890"));
}

void string_get_last_occurence_of_character_test() {
  char *string = "abcdef";
  assert(assert_string_equal(string_get_last_occurence_of_character(string, 'a'), "abcdef"));
  assert(assert_string_equal(string_get_last_occurence_of_character(string, 'b'), "bcdef"));
  assert(assert_string_equal(string_get_last_occurence_of_character(string, 'c'), "cdef"));
  assert(assert_string_equal(string_get_last_occurence_of_character(string, 'd'), "def"));
  assert(assert_string_equal(string_get_last_occurence_of_character(string, 'e'), "ef"));
  assert(assert_string_equal(string_get_last_occurence_of_character(string, 'f'), "f"));
}

void string_starts_with_test() {
  assert(string_starts_with("abcdef", "abc"));
  assert(!string_starts_with("abcdef", "bcd"));
  assert(!string_starts_with("abcdef", "def"));
  assert(!string_starts_with("abcdef", "ef"));
  assert(!string_starts_with("abcdef", "f"));
  assert(!string_starts_with("abcdef", "abcdefg"));
}

void string_ends_with_test() {
  assert(string_ends_with("abcdef", "def"));
  assert(string_ends_with("abcdef", "ef"));
  assert(string_ends_with("abcdef", "f"));
  assert(!string_ends_with("abcdef", "abc"));
  assert(!string_ends_with("abcdef", "bcd"));
  assert(!string_ends_with("abcdef", "abcdefg"));
}
