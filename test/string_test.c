#include "string_test.h"

void string_test() {
  string_get_length_test();
  string_to_uppercase_test();
  string_to_lowercase_test();
  string_replace_test();
  string_remove_character_test();
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
  string_t string = "Hello World!";
  size_t string_length = string_get_length(string);
  assert(string_length == 12);
  assert(strlen(string) == string_length);
}

void string_to_uppercase_test() {
  string_t string = string_copy("heLlO world");
  string_to_uppercase(string);
  assert(assert_string_equal(string, "HELLO WORLD"));
  free(string);
}

void string_to_lowercase_test() {
  string_t string = string_copy("HellO WoRLd");
  string_to_lowercase(string);
  assert(assert_string_equal(string, "hello world"));
  free(string);
}

void string_replace_test() {
  string_t string = string_copy("hello world");
  string_replace(string, 'l', 'z');
  assert(assert_string_equal(string, "hezzo worzd"));
  free(string);
}

void string_remove_character_test() {
  string_t string = string_copy("hello world");
  string_remove_character(string, 'l');
  assert(assert_string_equal(string, "heo word"));
  free(string);
}

void string_trim_start_test() {
  string_t string = string_copy("      hello world      ");
  string_trim_start(string, ' ');
  assert(assert_string_equal(string, "hello world      "));
  free(string);
}

void string_trim_end_test() {
  string_t string = string_copy("      hello world      ");
  string_trim_end(string, ' ');
  assert(assert_string_equal(string, "      hello world"));
  free(string);
}

void string_trim_test() {
  string_t string = string_copy("      hello world      ");
  string_trim(string, ' ');
  assert(assert_string_equal(string, "hello world"));
  free(string);
}

void string_copy_test() {
  string_t string = "hello world";
  string_t string2 = string_copy(string);
  assert(assert_string_equal(string, string2));
  string2[0] = 'a';
  assert(assert_string_not_equal(string, string2));
  assert(assert_string_equal(string, "hello world"));
  assert(assert_string_equal(string2, "aello world"));
  free(string2);
}

void string_capitalize_test() {
  string_t string = string_copy("hello world");
  string_capitalize(string);
  assert(assert_string_equal(string, "Hello world"));
  free(string);
}

void string_total_occurrences_of_character_test() {
  string_t string = "hello world";
  assert(string_total_occurrences_of_character(string, 'l') == 3);
}

void string_reverse_test() {
  string_t string = string_copy("hello world");
  string_reverse(string);
  assert(assert_string_equal(string, "dlrow olleh"));
  free(string);
}

void string_equals_test() {
  string_t string1 = "hello world";
  string_t string2 = "dlrow olleh";
  string_t string3 = "dlrow olleh";
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
  string_t string = "abc def ghij kl";
  size_t result_length = 0;
  string_t* result = string_split(string, ' ', &result_length);
  assert(result_length == 4);
  assert(assert_string_equal(result[0], "abc"));
  assert(assert_string_equal(result[1], "def"));
  assert(assert_string_equal(result[2], "ghij"));
  assert(assert_string_equal(result[3], "kl"));
  for (size_t index = 0; index < result_length; index++) {
    free(result[index]);
  }
  free(result);
}

void string_join_test() {
  string_t string = "abc def ghij kl";
  size_t result_length = 0;
  string_t* result = string_split(string, ' ', &result_length);
  string_t new_string = string_join(result, ' ', result_length);
  string_t new_string2 = string_join(result, '+', result_length);
  assert(assert_string_equal(new_string, string));
  assert(assert_string_equal(new_string2, "abc+def+ghij+kl"));
  free(new_string);
  free(new_string2);
  for (size_t index = 0; index < result_length; index++) {
    free(result[index]);
  }
  free(result);
}

void string_concatenate_test() {
  string_t result = string_copy("abc");
  string_concatenate(&result, "def");
  assert(assert_string_equal(result, "abcdef"));
  free(result);

  result = string_copy("abcz");
  string_concatenate(&result, "  defghi");
  assert(assert_string_equal(result, "abcz  defghi"));
  free(result);
}

void string_get_has_unique_characters_test() {
  assert(string_get_has_unique_characters("ABCDEF"));
  assert(!string_get_has_unique_characters("AAABCDEF"));
  assert(!string_get_has_unique_characters("AaaBCDEF"));
}

void string_substring_test() {
  string_t string = "abcdef";
  string_t substring = string_substring(string, 1, 3);
  assert(assert_string_equal(substring, "bcd"));
  free(substring);
}

void string_get_is_substring_test() {
  string_t string = "abcdef";
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
  string_t result = string_get_formatted_number(1000, " ");
  assert(assert_string_equal(result, "1 000"));
  free(result);

  result = string_get_formatted_number(123, ",");
  assert(assert_string_equal(result, "123"));
  free(result);

  result = string_get_formatted_number(1234, ",");
  assert(assert_string_equal(result, "1,234"));
  free(result);

  result = string_get_formatted_number(12345, ",");
  assert(assert_string_equal(result, "12,345"));
  free(result);

  result = string_get_formatted_number(-123, ",");
  assert(assert_string_equal(result, "-123"));
  free(result);

  result = string_get_formatted_number(-1234, ",");
  assert(assert_string_equal(result, "-1,234"));
  free(result);

  result = string_get_formatted_number(-1234567890, ",");
  assert(assert_string_equal(result, "-1,234,567,890"));
  free(result);
}

void string_get_last_occurence_of_character_test() {
  string_t string = "abcdef";

  string_t result = string_get_last_occurence_of_character(string, 'a');
  assert(assert_string_equal(result, "abcdef"));
  free(result);

  result = string_get_last_occurence_of_character(string, 'b');
  assert(assert_string_equal(result, "bcdef"));
  free(result);

  result = string_get_last_occurence_of_character(string, 'c');
  assert(assert_string_equal(result, "cdef"));
  free(result);

  result = string_get_last_occurence_of_character(string, 'd');
  assert(assert_string_equal(result, "def"));
  free(result);

  result = string_get_last_occurence_of_character(string, 'e');
  assert(assert_string_equal(result, "ef"));
  free(result);

  result = string_get_last_occurence_of_character(string, 'f');
  assert(assert_string_equal(result, "f"));
  free(result);
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
