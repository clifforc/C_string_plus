#include "search_test_suite.h"

START_TEST(strrchr_test1) {
  const char str[] = "Hello";
  ck_assert_str_eq(s21_strrchr(str, 'e'), strrchr(str, 'e'));
}
END_TEST

START_TEST(strrchr_test2) {
  const char str[] = "eee";
  ck_assert_str_eq(s21_strrchr(str, 'e'), strrchr(str, 'e'));
}
END_TEST

START_TEST(strrchr_test3) {
  const char str[] = "Hello";
  ck_assert_str_eq(s21_strrchr(str, 'o'), strrchr(str, 'o'));
}
END_TEST

START_TEST(strrchr_test4) {
  const char str[] = "Hello";
  ck_assert_ptr_null(s21_strrchr(str, 'g'));
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_strrchr(const char *str, int c)");

  tc_core = tcase_create("strrchr");

  tcase_add_test(tc_core, strrchr_test1);
  tcase_add_test(tc_core, strrchr_test2);
  tcase_add_test(tc_core, strrchr_test3);
  tcase_add_test(tc_core, strrchr_test4);
  suite_add_tcase(s, tc_core);

  return s;
}