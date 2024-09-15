#include "date.h"

struct date *date_copy(struct date *date_to_copy) {
  struct date *date = malloc(sizeof(struct date));
  if (date == NULL) {
    perror("Error (date_copy)");
    exit(EXIT_FAILURE);
  }
  date->year = date_to_copy->year;
  date->month = date_to_copy->month;
  date->day = date_to_copy->day;
  date->hours = date_to_copy->hours;
  date->minutes = date_to_copy->minutes;
  date->seconds = date_to_copy->seconds;
  date->milliseconds = date_to_copy->milliseconds;
  date->timezone_utc_offset = date_to_copy->timezone_utc_offset;
  return date;
}

bool date_get_is_valid_year(uint16_t year) {
  return year <= 9999;
}

bool date_get_is_valid_month(uint8_t month) {
  return month >= 1 && month <= 12;
}

bool date_get_is_valid_day(uint8_t day) {
  return day >= 1 && day <= 31;
}

bool date_get_is_valid_hours(uint8_t hours) {
  return hours <= 23;
}

bool date_get_is_valid_minutes(uint8_t minutes) {
  return minutes <= 59;
}

bool date_get_is_valid_seconds(uint8_t seconds) {
  return seconds <= 59;
}

bool date_get_is_valid_milliseconds(uint16_t milliseconds) {
  return milliseconds <= 999;
}

bool date_get_is_valid_timezone_utc_offset(int8_t timezone_utc_offset) {
  return timezone_utc_offset >= -12 && timezone_utc_offset <= 14;
}

bool date_get_is_valid(struct date *date) {
  size_t date_days_of_month = date_get_days_of_month(date->month, date->year);
  return (date_get_is_valid_month(date->month) &&
          date_get_is_valid_day(date->day) &&
          date->day <= date_days_of_month &&
          date_get_is_valid_hours(date->hours) &&
          date_get_is_valid_minutes(date->minutes) &&
          date_get_is_valid_seconds(date->seconds) &&
          date_get_is_valid_milliseconds(date->milliseconds) &&
          date_get_is_valid_timezone_utc_offset(date->timezone_utc_offset));
}

string_t date_to_iso_string(struct date *date_original) {
  struct date *date = date_copy(date_original);
  date_to_utc(date);

  size_t iso_string_length = 24;
  string_t result = malloc(sizeof(char) * (iso_string_length + 1));

  string_t year_string = string_zero_pad(date->year, 4);
  string_t month_string = string_zero_pad(date->month, 2);
  string_t day_string = string_zero_pad(date->day, 2);
  string_t hours_string = string_zero_pad(date->hours, 2);
  string_t minutes_string = string_zero_pad(date->minutes, 2);
  string_t seconds_string = string_zero_pad(date->seconds, 2);
  string_t milliseconds_string = string_zero_pad(date->milliseconds, 3);
  sprintf(result, "%s-%s-%sT%s:%s:%s.%sZ", year_string, month_string, day_string, hours_string, minutes_string, seconds_string, milliseconds_string);
  free(year_string);
  free(month_string);
  free(day_string);
  free(hours_string);
  free(minutes_string);
  free(seconds_string);
  free(milliseconds_string);

  free(date);
  return result;
}

string_t date_to_iso_string_without_time(struct date *date) {
  size_t iso_string_length = 10;
  string_t result = malloc(sizeof(char) * (iso_string_length + 1));
  if (result == NULL) {
    perror("Error (date_to_iso_string_without_time)");
    exit(EXIT_FAILURE);
  }

  string_t year_string = string_zero_pad(date->year, 4);
  string_t month_string = string_zero_pad(date->month, 2);
  string_t day_string = string_zero_pad(date->day, 2);
  sprintf(result, "%s-%s-%s", year_string, month_string, day_string);
  free(year_string);
  free(month_string);
  free(day_string);

  return result;
}

struct date *date_from_iso_string(string_t iso_string) {
  struct date *date = malloc(sizeof(struct date));
  if (date == NULL) {
    perror("Error (date_from_iso_string)");
    exit(EXIT_FAILURE);
  }

  string_t year_string = string_substring(iso_string, 0, 3);
  date->year = (uint16_t)convert_string_to_number(year_string);
  free(year_string);

  string_t month_string = string_substring(iso_string, 5, 6);
  date->month = (uint8_t)convert_string_to_number(month_string);
  free(month_string);

  string_t day_string = string_substring(iso_string, 8, 9);
  date->day = (uint8_t)convert_string_to_number(day_string);
  free(day_string);

  string_t hours_string = string_substring(iso_string, 11, 12);
  date->hours = (uint8_t)convert_string_to_number(hours_string);
  free(hours_string);

  string_t minutes_string = string_substring(iso_string, 14, 15);
  date->minutes = (uint8_t)convert_string_to_number(minutes_string);
  free(minutes_string);

  string_t seconds_string = string_substring(iso_string, 17, 18);
  date->seconds = (uint8_t)convert_string_to_number(seconds_string);
  free(seconds_string);

  string_t milliseconds_string = string_substring(iso_string, 20, 22);
  date->milliseconds = (uint16_t)convert_string_to_number(milliseconds_string);
  free(milliseconds_string);

  date->timezone_utc_offset = 0;

  return date;
}

uint8_t date_get_days_of_month(uint8_t month, uint16_t year) {
  switch (month) {
    case 1:
      return 31;
    case 2:
      return date_get_is_leap_year(year) ? 29 : 28;
    case 3:
      return 31;
    case 4:
      return 30;
    case 5:
      return 31;
    case 6:
      return 30;
    case 7:
      return 31;
    case 8:
      return 31;
    case 9:
      return 30;
    case 10:
      return 31;
    case 11:
      return 30;
    case 12:
      return 31;
    default:
      return 0;
  }
}

bool date_get_is_leap_year(uint16_t year) {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

uint64_t date_convert_milliseconds_to_seconds(uint16_t milliseconds) {
  return milliseconds / MILLISECONDS_PER_SECOND;
}

uint64_t date_convert_seconds_to_milliseconds(uint64_t seconds) {
  return seconds * MILLISECONDS_PER_SECOND;
}

uint64_t date_convert_days_to_seconds(uint64_t days) {
  return days * SECONDS_PER_DAY;
}

uint64_t date_convert_hms_to_seconds(uint8_t hours, uint8_t minutes, uint8_t seconds) {
  return (hours * SECONDS_PER_HOUR) + (minutes * SECONDS_PER_MINUTE) + seconds;
}

uint64_t date_to_total_seconds(struct date *date) {
  uint64_t total_seconds = 0;

  for (uint16_t year = 0; year < date->year; year++) {
    total_seconds += 365 * SECONDS_PER_DAY;
    if (date_get_is_leap_year(year)) {
      total_seconds += SECONDS_PER_DAY;
    }
  }

  for (uint8_t month = 1; month < date->month; month++) {
    total_seconds += date_convert_days_to_seconds(date_get_days_of_month(month, date->year));
  }

  total_seconds += date_convert_days_to_seconds(date->day - 1);
  total_seconds += date_convert_hms_to_seconds(date->hours, date->minutes, date->seconds);

  return total_seconds;
}

uint64_t date_duration_seconds_between_2_dates(struct date *date1, struct date *date2) {
  struct date *utc_date1 = date_copy(date1);
  struct date *utc_date2 = date_copy(date2);
  date_to_utc(utc_date1);
  date_to_utc(utc_date2);

  uint64_t total_seconds_date1 = date_to_total_seconds(utc_date1);
  uint64_t total_seconds_date2 = date_to_total_seconds(utc_date2);

  free(utc_date1);
  free(utc_date2);

  return total_seconds_date1 > total_seconds_date2 ? total_seconds_date1 - total_seconds_date2 : total_seconds_date2 - total_seconds_date1;
}

void date_add_hours(struct date *date, int64_t hours) {
  if (hours == 0) {
    return;
  }
  int64_t total_hours = date->hours + hours;
  int64_t additional_days = total_hours / 24;
  int64_t new_hours = total_hours % 24;

  if (new_hours < 0) {
    new_hours += 24;
    additional_days -= 1;
  }

  date->hours = (uint8_t)new_hours;

  if (additional_days != 0) {
    date->day += additional_days;

    while (date->day > date_get_days_of_month(date->month, date->year)) {
      date->day -= date_get_days_of_month(date->month, date->year);
      date->month++;

      if (date->month > 12) {
        date->month = 1;
        date->year++;
      }
    }

    while (date->day < 1) {
      date->month--;
      if (date->month < 1) {
        date->month = 12;
        date->year--;
      }

      date->day += date_get_days_of_month(date->month, date->year);
    }
  }
}

void date_add_days(struct date *date, int64_t days) {
  date_add_hours(date, days * 24);
}

void date_to_utc(struct date *date) {
  if (date->timezone_utc_offset == 0) {
    return;
  }
  int8_t timezone_utc_offset = date->timezone_utc_offset;
  date->timezone_utc_offset = 0;
  date_add_hours(date, mathematics_opposite(timezone_utc_offset));
}
