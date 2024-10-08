#ifndef __LIBCPROJECT_DATE__
#define __LIBCPROJECT_DATE__

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "convert.h"
#include "mathematics.h"
#include "string.h"
#include "types.h"

#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR (60 * SECONDS_PER_MINUTE)
#define SECONDS_PER_DAY (24 * SECONDS_PER_HOUR)
#define MILLISECONDS_PER_SECOND 1000

/**
 * @brief Date object representing a single moment in time.
 * @since v4.3.0
 */
struct date {
  /**
   * Year.
   * Between [0, 9999] (inclusive).
   * As per ISO 8601, a four-digit year [YYYY] and represents years from 0000 to 9999, year 0000 being equal to 1 BC and all others AD.
   */
  uint16_t year;

  /**
   * Month.
   * Between [1, 12] (inclusive).
   */
  uint8_t month;

  /**
   * Day.
   * Between [1, 31] (inclusive).
   */
  uint8_t day;

  /**
   * Hours.
   * Between [0, 23] (inclusive).
   */
  uint8_t hours;

  /**
   * Minutes.
   * Between [0, 59] (inclusive).
   */
  uint8_t minutes;

  /**
   * Seconds.
   * Between [0, 59] (inclusive).
   */
  uint8_t seconds;

  /**
   * Milliseconds.
   * Between [0, 999] (inclusive).
   */
  uint16_t milliseconds;

  /**
   * Timezone UTC offset.
   * Between [-12, 14]
   */
  int8_t timezone_utc_offset;
};

/**
 * @brief Return the copy of a date.
 *
 * @param date
 * @return struct date*
 * @since v4.3.0
 */
struct date *date_copy(struct date *date_to_copy);

/**
 * @brief Check if a year is valid, between [0, 9999] (inclusive).
 *
 * @param year
 * @return bool
 * @since v4.3.0
 */
bool date_get_is_valid_year(uint16_t year);

/**
 * @brief Check if a month is valid, between [1, 12] (inclusive).
 *
 * @param month
 * @return bool
 * @since v4.3.0
 */
bool date_get_is_valid_month(uint8_t month);

/**
 * @brief Check if a day is valid, between [1, 31] (inclusive).
 *
 * @param day
 * @return bool
 * @since v4.3.0
 */
bool date_get_is_valid_day(uint8_t day);

/**
 * @brief Check if hours are valid, between [0, 23] (inclusive).
 *
 * @param hours
 * @return bool
 * @since v4.3.0
 */
bool date_get_is_valid_hours(uint8_t hours);

/**
 * @brief Check if minutes are valid, between [0, 59] (inclusive).
 *
 * @param minutes
 * @return bool
 * @since v4.3.0
 */
bool date_get_is_valid_minutes(uint8_t minutes);

/**
 * @brief Check if seconds are valid, between [0, 59] (inclusive).
 *
 * @param seconds
 * @return bool
 * @since v4.3.0
 */
bool date_get_is_valid_seconds(uint8_t seconds);

/**
 * @brief Check if milliseconds are valid, between [0, 999] (inclusive).
 *
 * @param milliseconds
 * @return bool
 * @since v4.3.0
 */
bool date_get_is_valid_milliseconds(uint16_t milliseconds);

/**
 * @brief Check if the timezone UTC offset is valid, between [-12, 14] (inclusive).
 *
 * @param timezone_utc_offset
 * @return bool
 * @since v4.3.0
 */
bool date_get_is_valid_timezone_utc_offset(int8_t timezone_utc_offset);

/**
 * @brief Check if the date is valid (all fields are possible).
 *
 * @param date
 * @return bool
 * @since v4.3.0
 */
bool date_get_is_valid(struct date *date);

/**
 * @brief String representing the date in the date time string format, a simplified format based on ISO 8601, which is always 24 characters long (`YYYY-MM-DDTHH:mm:ss.sssZ`). The timezone is always UTC, as denoted by the suffix `Z`.
 *
 * @param date
 * @return string_t
 *
 * @code
 * date_to_iso_string() // "2024-09-11T09:39:18.203Z"
 * @endcode
 *
 * @since v4.3.0
 */
string_t date_to_iso_string(struct date *date);

/**
 * @brief String representing the date in the ISO 8601 format, without time information (`YYYY-MM-DD`).
 *
 * @param date
 * @return string_t
 *
 * @code
 * date_to_iso_string_without_time() // "2024-09-11"
 * @endcode
 *
 * @since v4.3.0
 */
string_t date_to_iso_string_without_time(struct date *date);

/**
 * @brief Create a date from an ISO 8601 string, with the format `YYYY-MM-DDTHH:mm:ss.sssZ`.
 *
 * The timezone is always UTC, as denoted by the suffix `Z`.
 *
 * @param iso_string
 * @return struct date*
 * @since v4.3.0
 */
struct date *date_from_iso_string(string_t iso_string);

/**
 * @brief Get number of days in one month [1, 12].
 *
 * @param month
 * @return uint8_t
 * @since v4.3.0
 */
uint8_t date_get_days_of_month(uint8_t month, uint16_t year);

/**
 * @brief Determine if a year is a leap year.
 *
 * @param year
 * @return bool
 *
 * @code
 * date_is_leap_year(2020) // true
 *
 * date_is_leap_year(2021) // false
 *
 * date_is_leap_year(2022) // false
 *
 * date_is_leap_year(2023) // false
 *
 * date_is_leap_year(2024) // true
 * @endcode
 *
 * @since v4.3.0
 */
bool date_get_is_leap_year(uint16_t year);

/**
 * @brief Convert milliseconds to seconds.
 *
 * @param milliseconds
 * @return uint64_t
 * @since v4.3.0
 */
uint64_t date_convert_milliseconds_to_seconds(uint16_t milliseconds);

/**
 * @brief Convert seconds to milliseconds.
 *
 * @param seconds
 * @return uint64_t
 * @since v4.3.0
 */
uint64_t date_convert_seconds_to_milliseconds(uint64_t seconds);

/**
 * @brief Convert days to seconds.
 *
 * @param days
 * @return uint64_t
 * @since v4.3.0
 */
uint64_t date_convert_days_to_seconds(uint64_t days);

/**
 * @brief Convert hours, minutes, and seconds to seconds.
 *
 * @param hours
 * @param minutes
 * @param seconds
 * @return uint64_t
 * @since v4.3.0
 */
uint64_t date_convert_hms_to_seconds(uint8_t hours, uint8_t minutes, uint8_t seconds);

/**
 * @brief Convert a date to total seconds.
 *
 * @param date
 * @return uint64_t
 * @since v4.3.0
 */
uint64_t date_to_total_seconds(struct date *date);

/**
 * @brief Calculate the duration in seconds between 2 dates.
 *
 * @param date1
 * @param date2
 * @return uint64_t
 * @since v4.3.0
 */
uint64_t date_duration_seconds_between_2_dates(struct date *date1, struct date *date2);

/**
 * @brief Add hours to the date, managing the day, month, year changes if necessary.
 *
 * NOTE: Mutates the date.
 *
 * @param date
 * @param hours
 * @since v4.3.0
 */
void date_add_hours(struct date *date, int64_t hours);

/**
 * @brief Adds days to the date, managing month and year changes as needed.
 *
 * NOTE: Mutates the date.
 *
 * @param date The date to which days are being added.
 * @param days The number of days to add.
 * @since v4.3.0
 */
void date_add_days(struct date *date, int64_t days);

/**
 * @brief Transform the date with a Timezone UTC Offset to UTC (timezone_utc_offset = 0).
 *
 * NOTE: Mutates the date.
 *
 * @param date
 * @since v4.3.0
 */
void date_to_utc(struct date *date);

/**
 * @brief Get the current date in UTC.
 *
 * @return struct date*
 * @since v5.1.0
 */
struct date *date_get_now_utc();

#endif
