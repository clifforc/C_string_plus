#include "copy_test_suite.h"

START_TEST(memset_test1) {
  char str1[15] = "1234567890";
  char str2[15] = "1234567890";
  int c = '1';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_test2) {
  char str1[15] = "1234567890";
  char str2[15] = "5432167890";
  int c = 'q';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

Suite *memset_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_memset(void *str, int c, size_t n)");

  tc_core = tcase_create("memset");

  tcase_add_test(tc_core, memset_test1);
  tcase_add_test(tc_core, memset_test2);
  suite_add_tcase(s, tc_core);

  return s;
}