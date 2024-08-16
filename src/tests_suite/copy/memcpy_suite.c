#include "copy_test_suite.h"

START_TEST(memcpy_test1) {
  char s1[] = "School 21 is awesome!";
  char s2[] = "School 21 is awesome!";
  const char s3[] = "School";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(memcpy_test2) {
  char s1[] = "School 21 is awesome!";
  char s2[] = "School 21 is awesome!";
  const char s3[] = "Hello";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_memcpy(void *dest, const void *src, size_t n)");

  tc_core = tcase_create("memcpy");

  tcase_add_test(tc_core, memcpy_test1);
  tcase_add_test(tc_core, memcpy_test2);
  suite_add_tcase(s, tc_core);

  return s;
}