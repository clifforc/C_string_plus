#include "additional_test_suite.h"

START_TEST(strerror_test1) {
  for (int i = 0; i < 107; i++) ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_test2) {
  for (int i = -10; i < 0; i++) ck_assert_str_eq(strerror(i), s21_strerror(i));
}
END_TEST

START_TEST(strerror_test3) {
  ck_assert_str_eq(strerror(155), s21_strerror(155));
}
END_TEST

Suite *strerror_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_strerror(int errnum)");

  tc_core = tcase_create("strerror");

  tcase_add_test(tc_core, strerror_test1);
  tcase_add_test(tc_core, strerror_test2);
  tcase_add_test(tc_core, strerror_test3);
  suite_add_tcase(s, tc_core);

  return s;
}