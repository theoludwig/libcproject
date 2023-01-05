#ifndef __CONVERT__
#define __CONVERT__

char* convert_character_to_string(const char character);

char convert_character_to_digit(const char character);

char convert_digit_to_character(const char digit);

long long convert_string_to_number(const char* string);

char* convert_number_to_string(const long long integer);

char* convert_number_from_base_10_to_base(unsigned long long number, unsigned int base);

int convert_number_from_base_to_base_10(char* number, unsigned int base);

char* convert_number_from_base_to_another(char* number, int base_from, int base_target);

#endif
