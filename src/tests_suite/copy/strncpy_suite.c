#include "copy_test_suite.h"

START_TEST(strncpy_test1) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  const char s3[] = "Good";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_test2) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  const char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(strncpy_test3) {
  char s1[5] = "";
  char s2[5] = "";
  const char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_strncpy(char *dest, const char *src, size_t n)");

  tc_core = tcase_create("strncpy");

  tcase_add_test(tc_core, strncpy_test1);
  tcase_add_test(tc_core, strncpy_test2);
  tcase_add_test(tc_core, strncpy_test3);
  suite_add_tcase(s, tc_core);

  return s;
}