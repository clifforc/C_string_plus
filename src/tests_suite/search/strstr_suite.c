#include "search_test_suite.h"

START_TEST(strstr_test1) {
  char str1[] = "abcd";
  const char str2[] = "cd";

  // char *res_orig = strstr(str1, str2);
  // char *res = s21_strstr(str1, str2);
  // ck_assert_str_eq(res, res_orig);

  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test2) {
  char str1[] = "aaa";
  const char str2[] = "cd";

  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test3) {
  char str1[] = "tyttytyty";
  const char str2[] = "cd";

  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test4) {
  char str1[] = "tyttytyty";
  const char str2[] = "";

  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_test5) {
  char str1[] = "abcd";
  const char str2[] = "abc";

  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_strstr(const char *haystack, const char *needle)");

  tc_core = tcase_create("strstr");

  tcase_add_test(tc_core, strstr_test1);
  tcase_add_test(tc_core, strstr_test2);
  tcase_add_test(tc_core, strstr_test3);
  tcase_add_test(tc_core, strstr_test4);
  tcase_add_test(tc_core, strstr_test5);
  suite_add_tcase(s, tc_core);

  return s;
}