#include "special_test_suite.h"

START_TEST(to_upper_test1) {
  const char str[] = "hello";
  char sample[] = "HELLO";
  char *up_str = s21_to_upper(str);
  ck_assert_str_eq(sample, up_str);
  free(up_str);
}
END_TEST

START_TEST(to_upper_test2) {
  const char *str = S21_NULL;
  char *up_str = s21_to_upper(str);
  ck_assert_ptr_null(up_str);
}
END_TEST

START_TEST(to_upper_test3) {
  const char str[] = "HELLO";
  char sample[] = "HELLO";
  char *up_str = s21_to_upper(str);
  ck_assert_str_eq(sample, up_str);
  free(up_str);
}
END_TEST

START_TEST(to_upper_test4) {
  const char str[] = " string1+1#$Naz{}   \n\0";
  char sample[] = " STRING1+1#$NAZ{}   \n\0";
  char *up_str = s21_to_upper(str);
  ck_assert_str_eq(sample, up_str);
  free(up_str);
}
END_TEST

Suite *to_upper_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_to_upper(const char *str)");

  tc_core = tcase_create("to_upper");

  tcase_add_test(tc_core, to_upper_test1);
  tcase_add_test(tc_core, to_upper_test2);
  tcase_add_test(tc_core, to_upper_test3);
  tcase_add_test(tc_core, to_upper_test4);
  suite_add_tcase(s, tc_core);

  return s;
}