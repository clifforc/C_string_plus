#include "additional_test_suite.h"

START_TEST(strncat_test1) {
  char str1[40] = ",";
  const char str2[] = "Hello world";
  ck_assert_str_eq(s21_strncat(str1, " world!", 8),
                   strncat(str1, " world!", 8));
  ck_assert_str_eq(s21_strncat(str1, str2, 10), strncat(str1, str2, 10));
}
END_TEST

START_TEST(strncat_test2) {
  //   ck_assert( ... );
}
END_TEST

START_TEST(strncat_test3) {
  //   ck_assert( ... );
}
END_TEST

Suite *strncat_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_strncat(char *dest, const char *src, size_t n)");

  tc_core = tcase_create("strncat");

  tcase_add_test(tc_core, strncat_test1);
  tcase_add_test(tc_core, strncat_test2);
  tcase_add_test(tc_core, strncat_test3);
  suite_add_tcase(s, tc_core);

  return s;
}