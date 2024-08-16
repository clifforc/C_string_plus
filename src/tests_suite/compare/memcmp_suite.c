#include "compare_test_suite.h"

START_TEST(memcmp_test1) {
  const char str1[20] = "HELLO";
  const char str2[20] = "HELLO";
  ck_assert_int_eq(memcmp(str1, str2, 4), s21_memcmp(str1, str2, 4));
}
END_TEST

START_TEST(memcmp_test2) {
  char str1[100] = "School21 is awesome";
  char str2[100] = "HELLO";
  ck_assert_int_eq(memcmp(str1, str2, 20), s21_memcmp(str1, str2, 20));
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "Test s21_memcmp(const void *str1, const void *str2, size_t n)");

  tc_core = tcase_create("memcmp");

  tcase_add_test(tc_core, memcmp_test1);
  tcase_add_test(tc_core, memcmp_test2);
  // tcase_add_test(tc_core, memcmp_test3);
  suite_add_tcase(s, tc_core);

  return s;
}