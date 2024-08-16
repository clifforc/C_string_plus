#ifndef SEARCH_TEST_SUITE_H
#define SEARCH_TEST_SUITE_H

#include <check.h>

#include "../../../src/s21_string.h"

Suite *memchr_suite(void);
Suite *strchr_suite(void);
Suite *strpbrk_suite(void);
Suite *strrchr_suite(void);
Suite *strstr_suite(void);

#endif