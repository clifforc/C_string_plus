#include "sscanf_test_suite.h"

START_TEST(sscanf_test1) {
  char c_s21, c_orig;
  int d_s21, d_orig;
  char str_s21[100], str_orig[100];
  float f_s21, f_orig;
  unsigned int u_s21, u_orig;

  const char *input = "a Hello 123 0.123456 123";

  int result_s21 = s21_sscanf(input, "%c %s %d %f %u", &c_s21, str_s21, &d_s21,
                              &f_s21, &u_s21);
  int result_orig = sscanf(input, "%c %99s %d %f %u", &c_orig, str_orig,
                           &d_orig, &f_orig, &u_orig);

  ck_assert_int_eq(result_s21, result_orig);
  ck_assert_int_eq(c_s21, c_orig);
  ck_assert_str_eq(str_s21, str_orig);
  ck_assert_int_eq(d_s21, d_orig);
  ck_assert_float_eq_tol(f_s21, f_orig, 0.00001);
  ck_assert_uint_eq(u_s21, u_orig);
}
END_TEST

START_TEST(sscanf_test2) {
  int d_s21, d_orig;
  float f_s21, f_orig;

  const char *input = "-123 -0.123456";

  int result_s21 = s21_sscanf(input, "%d %f", &d_s21, &f_s21);
  int result_orig = sscanf(input, "%d %f", &d_orig, &f_orig);

  ck_assert_int_eq(result_s21, result_orig);
  ck_assert_int_eq(d_s21, d_orig);
  ck_assert_float_eq_tol(f_s21, f_orig, 0.00001);
}
END_TEST

START_TEST(sscanf_test3) {
  int d_s21;
  const char *input = "123";

  int result_s21 = s21_sscanf(input, "abc%d", &d_s21);

  ck_assert_int_eq(result_s21, 0);
}
END_TEST

START_TEST(sscanf_test4) {
  int i;
  s21_sscanf("123", "%d", &i);
  ck_assert_int_eq(i, 123);
}
END_TEST

Suite *sscanf_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_sscanf");

  tc_core = tcase_create("sscanf");

  tcase_add_test(tc_core, sscanf_test1);
  tcase_add_test(tc_core, sscanf_test2);
  tcase_add_test(tc_core, sscanf_test3);
  tcase_add_test(tc_core, sscanf_test4);
  suite_add_tcase(s, tc_core);

  return s;
}