#ifndef __TEST__
#define __TEST__

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "libcproject.h"

bool assert_string_equal(const string_t actual, const string_t expected);

bool assert_string_not_equal(const string_t actual, const string_t expected);

#endif
