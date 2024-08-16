#include "calculation_test_suite.h"

START_TEST(strcspn_test1) {
  const char s1[] = "Atilewocrld";
  const char s2[] = "cbzk";
  ck_assert_uint_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_test2) {
  const char s1[] = "Atilewocrld";
  const char s2[] = "z";
  ck_assert_uint_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_strcspn(const char *str1, const char *str2)");

  tc_core = tcase_create("strcspn");

  tcase_add_test(tc_core, strcspn_test1);
  tcase_add_test(tc_core, strcspn_test2);
  suite_add_tcase(s, tc_core);

  return s;
}