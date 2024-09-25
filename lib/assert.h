#ifndef __LIBCPROJECT_ASSERT__
#define __LIBCPROJECT_ASSERT__

#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>

#include "string.h"
#include "types.h"

/**
 * @brief Check if the two strings are equal. If they are not equal, print the expected and actual strings.
 *
 * @param character
 * @return bool
 * @since v5.0.0
 */
bool assert_string_equal(const string_t actual, const string_t expected);

/**
 * @brief Check if the two strings are not equal. If they are equal, print the expected and actual strings.
 *
 * @param character
 * @return bool
 * @since v5.0.0
 */
bool assert_string_not_equal(const string_t actual, const string_t expected);

#endif
