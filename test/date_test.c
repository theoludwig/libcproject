#include "date_test.h"

void date_test() {
  date_copy_test();
  date_to_iso_string_test();
  date_to_iso_string_without_time_test();
  date_from_iso_string_test();
  date_get_is_leap_year_test();
  date_duration_seconds_between_2_dates_test();
  date_to_utc_test();
  date_get_age_test();
}

void date_copy_test() {
  struct date *date = malloc(sizeof(struct date));
  date->year = 2024;
  date->month = 9;
  date->day = 10;
  date->hours = 20;
  date->minutes = 34;
  date->seconds = 25;
  date->milliseconds = 76;
  date->timezone_utc_offset = 0;

  struct date *date2 = date_copy(date);
  assert(date != date2);
  assert(date->year == date2->year);
  assert(date->month == date2->month);
  assert(date->day == date2->day);
  assert(date->hours == date2->hours);
  assert(date->minutes == date2->minutes);
  assert(date->seconds == date2->seconds);
  assert(date->milliseconds == date2->milliseconds);
  assert(date->timezone_utc_offset == date2->timezone_utc_offset);

  date->year = 2025;
  assert(date->year == 2025);
  assert(date2->year == 2024);

  free(date);
  free(date2);
}

void date_to_iso_string_test() {
  struct date *date = malloc(sizeof(struct date));
  date->year = 2024;
  date->month = 9;
  date->day = 10;
  date->hours = 20;
  date->minutes = 34;
  date->seconds = 25;
  date->milliseconds = 76;
  date->timezone_utc_offset = 0;

  string_t iso_string = date_to_iso_string(date);
  assert(assert_string_equal(iso_string, "2024-09-10T20:34:25.076Z"));
  free(iso_string);

  free(date);
}

void date_to_iso_string_without_time_test() {
  struct date *date = malloc(sizeof(struct date));
  date->year = 2024;
  date->month = 9;
  date->day = 10;
  date->hours = 20;
  date->minutes = 34;
  date->seconds = 25;
  date->milliseconds = 76;
  date->timezone_utc_offset = 0;

  string_t iso_string = date_to_iso_string_without_time(date);
  assert(assert_string_equal(iso_string, "2024-09-10"));
  free(iso_string);

  free(date);
}

void date_from_iso_string_test() {
  string_t iso_string = "2024-09-10T20:34:25.076Z";
  struct date *date = date_from_iso_string(iso_string);
  assert(date->year == 2024);
  assert(date->month == 9);
  assert(date->day == 10);
  assert(date->hours == 20);
  assert(date->minutes == 34);
  assert(date->seconds == 25);
  assert(date->milliseconds == 76);
  assert(date->timezone_utc_offset == 0);

  free(date);
}

void date_get_is_leap_year_test() {
  assert(date_get_is_leap_year(2020));
  assert(!date_get_is_leap_year(2021));
  assert(!date_get_is_leap_year(2022));
  assert(!date_get_is_leap_year(2023));
  assert(date_get_is_leap_year(2024));
}

void date_duration_seconds_between_2_dates_test() {
  struct date *date1 = date_from_iso_string("2024-09-10T20:34:25.076Z");
  struct date *date2 = date_from_iso_string("2024-09-10T20:34:25.076Z");
  assert(date_duration_seconds_between_2_dates(date1, date2) == 0);
  free(date1);
  free(date2);

  date1 = date_from_iso_string("2024-09-10T20:34:25.076Z");
  date2 = date_from_iso_string("2024-09-10T23:34:26.076Z");
  assert(date_duration_seconds_between_2_dates(date1, date2) == 10801);
  free(date1);
  free(date2);

  date1 = date_from_iso_string("2024-09-10T20:34:25.076Z");
  date2 = date_from_iso_string("2024-09-10T20:48:25.076Z");
  assert(date_duration_seconds_between_2_dates(date1, date2) == 840);
  free(date1);
  free(date2);

  date1 = date_from_iso_string("2024-09-10T20:34:25.076Z");
  date2 = date_from_iso_string("2024-09-10T20:34:38.076Z");
  assert(date_duration_seconds_between_2_dates(date1, date2) == 13);
  free(date1);
  free(date2);
}

void date_to_utc_test() {
  struct date *date = date_from_iso_string("2024-09-10T20:34:25.076Z");
  date->timezone_utc_offset = 3;
  date_to_utc(date);
  assert(date->timezone_utc_offset == 0);
  string_t iso_string = date_to_iso_string(date);
  assert(assert_string_equal(iso_string, "2024-09-10T17:34:25.076Z"));
  free(iso_string);
  free(date);

  date = date_from_iso_string("2024-09-10T20:34:25.076Z");
  date->timezone_utc_offset = -3;
  date_to_utc(date);
  assert(date->timezone_utc_offset == 0);
  iso_string = date_to_iso_string(date);
  assert(assert_string_equal(iso_string, "2024-09-10T23:34:25.076Z"));
  free(iso_string);
  free(date);

  date = date_from_iso_string("2024-01-01T00:00:00.000Z");
  date->timezone_utc_offset = 3;
  date_to_utc(date);
  assert(date->timezone_utc_offset == 0);
  iso_string = date_to_iso_string(date);
  assert(assert_string_equal(iso_string, "2023-12-31T21:00:00.000Z"));
  free(iso_string);
  free(date);

  date = date_from_iso_string("2023-12-31T21:00:00.000Z");
  date->timezone_utc_offset = -4;
  date_to_utc(date);
  assert(date->timezone_utc_offset == 0);
  iso_string = date_to_iso_string(date);
  assert(assert_string_equal(iso_string, "2024-01-01T01:00:00.000Z"));
  free(iso_string);
  free(date);
}

void date_get_age_test() {
  struct date *birth_date = date_from_iso_string("1980-02-20T00:00:00.000Z");
  struct date *current_date = date_from_iso_string("2018-03-20T00:00:00.000Z");
  assert(date_get_age(birth_date, current_date) == 38);
  free(birth_date);
  free(current_date);

  birth_date = date_from_iso_string("1980-07-20T00:00:00.000Z");
  current_date = date_from_iso_string("2018-03-20T00:00:00.000Z");
  assert(date_get_age(birth_date, current_date) == 37);
  free(birth_date);
  free(current_date);

  birth_date = date_from_iso_string("1980-03-20T00:00:00.000Z");
  current_date = date_from_iso_string("2018-03-20T00:00:00.000Z");
  assert(date_get_age(birth_date, current_date) == 38);
  free(birth_date);
  free(current_date);

  birth_date = date_from_iso_string("1980-03-25T00:00:00.000Z");
  current_date = date_from_iso_string("2018-03-20T00:00:00.000Z");
  assert(date_get_age(birth_date, current_date) == 37);
  free(birth_date);
  free(current_date);
}
