#include "special_test_suite.h"

START_TEST(to_lower_test1) {
  const char str[] = "HELLO";
  char sample[] = "hello";
  char *up_str = s21_to_lower(str);
  ck_assert_str_eq(sample, up_str);
  free(up_str);
}
END_TEST

START_TEST(to_lower_test2) {
  const char *str = S21_NULL;
  char *up_str = s21_to_lower(str);
  ck_assert_ptr_null(up_str);
}
END_TEST

START_TEST(to_lower_test3) {
  const char str[] = "hello";
  char sample[] = "hello";
  char *up_str = s21_to_lower(str);
  ck_assert_str_eq(sample, up_str);
  free(up_str);
}
END_TEST

START_TEST(to_lower_test4) {
  const char str[] = " STRING1+1n   \n\0";
  char sample[] = " string1+1n   \n\0";
  char *up_str = s21_to_lower(str);
  ck_assert_str_eq(sample, up_str);
  free(up_str);
}
END_TEST

Suite *to_lower_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_to_lower(const char *str)");

  tc_core = tcase_create("to_lower");

  tcase_add_test(tc_core, to_lower_test1);
  tcase_add_test(tc_core, to_lower_test2);
  tcase_add_test(tc_core, to_lower_test3);
  tcase_add_test(tc_core, to_lower_test4);
  suite_add_tcase(s, tc_core);

  return s;
}