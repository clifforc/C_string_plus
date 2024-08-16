#include "special_test_suite.h"

START_TEST(trim_test1) {
  const char *str = "Hello, world!";
  char *up_str = s21_trim(str, " ");
  ck_assert_str_eq(up_str, "Hello,world!");
  free(up_str);
}
END_TEST

START_TEST(trim_test2) {
  const char *src = S21_NULL;
  char *up_str = s21_trim(src, " ");
  ck_assert_ptr_null(up_str);
}
END_TEST

START_TEST(trim_test3) {
  const char *src = "Hello, world!";
  char *up_str = s21_trim(src, S21_NULL);
  ck_assert_ptr_null(up_str);
}
END_TEST

Suite *trim_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_trim(const char *src, const char *trim_chars)");

  tc_core = tcase_create("trim");

  tcase_add_test(tc_core, trim_test1);
  tcase_add_test(tc_core, trim_test2);
  tcase_add_test(tc_core, trim_test3);
  suite_add_tcase(s, tc_core);

  return s;
}