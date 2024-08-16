#include "additional_test_suite.h"

START_TEST(strtok_test1) {
  char string[] = "Hope you are doing fine";
  const char *delimiter = " ";
  char *token, *token1;
  token = s21_strtok(string, delimiter);
  token1 = strtok(string, delimiter);
  ck_assert_str_eq(token, token1);
}
END_TEST

START_TEST(strtok_test3) {
  char string[] = "Hope you are doing fine";
  const char *delimiter = " ";
  char *token, *token1;
  token1 = s21_strtok(string, delimiter);
  token1 = s21_strtok(S21_NULL, delimiter);
  token = "you";
  ck_assert_str_eq(token, token1);
}
END_TEST

START_TEST(strtok_test4) {
  char string[] = "Hope\0";
  const char *delimiter = " ";
  char *token;
  token = s21_strtok(string, delimiter);
  token = s21_strtok(S21_NULL, delimiter);
  token = s21_strtok(S21_NULL, delimiter);
  token = s21_strtok(S21_NULL, delimiter);
  ck_assert_ptr_null(token);
}
END_TEST

START_TEST(strtok_test5) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  const char s5[] = " o";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_strtok(char *str, const char *delim)");

  tc_core = tcase_create("strtok");

  tcase_add_test(tc_core, strtok_test1);
  tcase_add_test(tc_core, strtok_test3);
  tcase_add_test(tc_core, strtok_test4);
  tcase_add_test(tc_core, strtok_test5);
  suite_add_tcase(s, tc_core);

  return s;
}