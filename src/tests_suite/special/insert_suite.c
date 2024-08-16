#include "special_test_suite.h"

START_TEST(insert_test1) {
  const char src[] = "hello world";
  const char str[] = "beautiful ";
  s21_size_t start_index = 6;
  char sample[] = "hello beautiful world";
  char *up_str = s21_insert(src, str, start_index);
  ck_assert_str_eq(sample, up_str);
  free(up_str);
}
END_TEST

START_TEST(insert_test2) {
  const char *str = S21_NULL;
  const char src[] = "hello world";
  s21_size_t start_index = 6;
  char *up_str = s21_insert(src, str, start_index);
  ck_assert_ptr_null(up_str);
}
END_TEST

START_TEST(insert_test3) {
  const char str[] = "beautiful ";
  const char src[] = "hello world";
  s21_size_t start_index = 40;
  char *up_str = s21_insert(src, str, start_index);
  ck_assert_ptr_null(up_str);
  free(up_str);
}
END_TEST

START_TEST(insert_test4) {
  const char *src = S21_NULL;
  const char str[] = "hello world";
  s21_size_t start_index = 6;
  char *up_str = s21_insert(src, str, start_index);
  ck_assert_ptr_null(up_str);
}
END_TEST

Suite *insert_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create(
      "Test s21_insert(const char *src, const char *str, size_t start_index)");

  tc_core = tcase_create("insert");

  tcase_add_test(tc_core, insert_test1);
  tcase_add_test(tc_core, insert_test2);
  tcase_add_test(tc_core, insert_test3);
  tcase_add_test(tc_core, insert_test4);
  suite_add_tcase(s, tc_core);

  return s;
}