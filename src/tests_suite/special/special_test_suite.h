#ifndef SPECIAL_TEST_SUITE_H
#define SPECIAL_TEST_SUITE_H

#include <check.h>

#include "../../../src/s21_string.h"

Suite *to_upper_suite(void);
Suite *to_lower_suite(void);
Suite *insert_suite(void);
Suite *trim_suite(void);

#endif