#include "calculation_test_suite.h"

START_TEST(strlen_test1) {
  const char *test_str = "Hello, World!";
  ck_assert_int_eq(s21_strlen(test_str), strlen(test_str));
}
END_TEST

START_TEST(strlen_test2) {
  const char *test_str = "";
  ck_assert_int_eq(s21_strlen(test_str), strlen(test_str));
}
END_TEST

Suite *strlen_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_strlen(const char *str)");

  tc_core = tcase_create("strlen");

  tcase_add_test(tc_core, strlen_test1);
  tcase_add_test(tc_core, strlen_test2);
  suite_add_tcase(s, tc_core);

  return s;
}