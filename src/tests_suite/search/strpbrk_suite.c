#include "search_test_suite.h"

START_TEST(strpbrk_test1) {
  const char str1[] = "a2bcd";
  const char str2[] = "123";

  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test2) {
  const char str1[] = "a2bcd";
  const char str2[] = "456";

  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_test3) {
  const char str1[] = "";
  const char str2[] = "";

  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_strpbrk(const char *str1, const char *str2)");

  tc_core = tcase_create("strpbrk");

  tcase_add_test(tc_core, strpbrk_test1);
  tcase_add_test(tc_core, strpbrk_test2);
  tcase_add_test(tc_core, strpbrk_test3);
  suite_add_tcase(s, tc_core);

  return s;
}