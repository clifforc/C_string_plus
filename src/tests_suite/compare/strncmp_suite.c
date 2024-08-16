#include "compare_test_suite.h"

START_TEST(strncmp_test1) {
  const char s1[] = "Hello";
  const char s2[] = "Hello";
  ck_assert_int_eq(s21_strncmp(s1, s2, 3), strncmp(s1, s2, 3));
}
END_TEST

START_TEST(strncmp_test2) {
  const char s1[] = "Hello";
  const char s2[] = "Heppo";
  ck_assert_int_eq(s21_strncmp(s1, s2, 3), strncmp(s1, s2, 3));
}
END_TEST

START_TEST(strncmp_test3) {
  const char s1[] = "Hello";
  const char s2[] = "";
  ck_assert_int_eq(s21_strncmp(s1, s2, 3), strncmp(s1, s2, 3));
}
END_TEST

START_TEST(strncmp_test4) {
  const char s1[] = "Hello";
  const char s2[] = "Bye";
  ck_assert_int_eq(s21_strncmp(s1, s2, 0), strncmp(s1, s2, 0));
}
END_TEST

START_TEST(strncmp_test5) {
  const char s1[] = "Hello";
  const char s2[] = "hello";
  ck_assert_int_eq(s21_strncmp(s1, s2, 4), strncmp(s1, s2, 4));
}
END_TEST

START_TEST(strncmp_test6) {
  const char s1[] = "";
  const char s2[] = "Hello, world!";
  ck_assert_int_eq(s21_strncmp(s1, s2, 5), strncmp(s1, s2, 5));
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "Test s21_strncmp(const char *str1, const char *str2, size_t n)");

  tc_core = tcase_create("strncmp");

  tcase_add_test(tc_core, strncmp_test1);
  tcase_add_test(tc_core, strncmp_test2);
  tcase_add_test(tc_core, strncmp_test3);
  tcase_add_test(tc_core, strncmp_test4);
  tcase_add_test(tc_core, strncmp_test5);
  tcase_add_test(tc_core, strncmp_test6);
  suite_add_tcase(s, tc_core);

  return s;
}