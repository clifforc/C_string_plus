#include "search_test_suite.h"

START_TEST(memchr_test1) {
  char str[] = "Hello, world!";
  int ch = ' ';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test2) {
  char str[] = "Hello, world!";
  int ch = '1';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(memchr_test3) {
  char str[] = "Hello, world!";
  int ch = 65;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

Suite *memchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_memchr(const void *str, int c, size_t n)");

  tc_core = tcase_create("memchr");

  tcase_add_test(tc_core, memchr_test1);
  tcase_add_test(tc_core, memchr_test2);
  tcase_add_test(tc_core, memchr_test3);
  suite_add_tcase(s, tc_core);

  return s;
}
