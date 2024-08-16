#include "search_test_suite.h"

START_TEST(strchr_test1) {
  const char str[] = "Hello";
  ck_assert_str_eq(s21_strchr(str, 'e'), strchr(str, 'e'));
}
END_TEST

START_TEST(strchr_test2) {
  const char str[] = "eee";
  ck_assert_str_eq(s21_strchr(str, 'e'), strchr(str, 'e'));
}
END_TEST

START_TEST(strchr_test3) {
  const char str[] = "Hello";
  ck_assert_str_eq(s21_strchr(str, 'o'), strchr(str, 'o'));
}
END_TEST

START_TEST(strchr_test4) {
  const char str[] = "Hello";
  ck_assert_ptr_null(s21_strchr(str, 'g'));
}
END_TEST

Suite *strchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_strchr(const char *str, int c)");

  tc_core = tcase_create("strchr");

  tcase_add_test(tc_core, strchr_test1);
  tcase_add_test(tc_core, strchr_test2);
  tcase_add_test(tc_core, strchr_test3);
  tcase_add_test(tc_core, strchr_test4);
  suite_add_tcase(s, tc_core);

  return s;
}