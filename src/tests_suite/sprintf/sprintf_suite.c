#include "sprintf_test_suite.h"

/**
 *  Спецификаторы: c, d, f, s, u, %
 *  Флаги: -, +, (пробел)
 *  Ширина: (число)
 *  Точность: .(число)
 *  Длина: h, l
 **/

// Char
START_TEST(sprintf_test1) {
  char buff_s21[128];
  char buff_orig[128];

  char letter = 'A';

  s21_sprintf(buff_s21, "Char: %c", letter);
  sprintf(buff_orig, "Char: %c", letter);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// Signed int
START_TEST(sprintf_test2) {
  char buff_s21[128];
  char buff_orig[128];

  int num = -12345;

  s21_sprintf(buff_s21, "Int: %d", num);
  sprintf(buff_orig, "Int: %d", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// Float
START_TEST(sprintf_test3) {
  char buff_s21[128];
  char buff_orig[128];

  float num = 0.123456;

  s21_sprintf(buff_s21, "Float: %f", num);
  sprintf(buff_orig, "Float: %f", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// String
START_TEST(sprintf_test4) {
  char buff_s21[128];
  char buff_orig[128];

  char str[] = "Hello, world!";

  s21_sprintf(buff_s21, "Float: %s", str);
  sprintf(buff_orig, "Float: %s", str);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// Unsigned int
START_TEST(sprintf_test5) {
  char buff_s21[128];
  char buff_orig[128];

  unsigned int num = 12345;

  s21_sprintf(buff_s21, "Int: %u", num);
  sprintf(buff_orig, "Int: %u", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// Percent
START_TEST(sprintf_test6) {
  char buff_s21[128];
  char buff_orig[128];

  s21_sprintf(buff_s21, "Percent: %%");
  sprintf(buff_orig, "Percent: %%");

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// Left justification
START_TEST(sprintf_test7) {
  char buff_s21[128];
  char buff_orig[128];

  int num = 12345;

  s21_sprintf(buff_s21, "Int: %-10d", num);
  sprintf(buff_orig, "Int: %-10d", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// + sign
START_TEST(sprintf_test8) {
  char buff_s21[128];
  char buff_orig[128];

  int num = 12345;

  s21_sprintf(buff_s21, "Int: %+d", num);
  sprintf(buff_orig, "Int: %+d", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// Space
START_TEST(sprintf_test9) {
  char buff_s21[128];
  char buff_orig[128];

  int num = 12345;

  s21_sprintf(buff_s21, "Int: % d", num);
  sprintf(buff_orig, "Int: % d", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// width 1
START_TEST(sprintf_test10) {
  char buff_s21[128];
  char buff_orig[128];

  char str[] = "Hello, world!";

  s21_sprintf(buff_s21, "%5s", str);
  sprintf(buff_orig, "%5s", str);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// width 2
START_TEST(sprintf_test11) {
  char buff_s21[128];
  char buff_orig[128];

  char str[] = "Hello, world!";

  s21_sprintf(buff_s21, "%25s", str);
  sprintf(buff_orig, "%25s", str);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// Float with precision
START_TEST(sprintf_test12) {
  char buff_s21[128];
  char buff_orig[128];

  float num = 0.123456;

  s21_sprintf(buff_s21, "Float: %.2f", num);
  sprintf(buff_orig, "Float: %.2f", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// h length description
START_TEST(sprintf_test13) {
  char buff_s21[128];
  char buff_orig[128];

  short num = 12345;

  s21_sprintf(buff_s21, "short int: %hd", num);
  sprintf(buff_orig, "short int: %hd", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

// l length description
START_TEST(sprintf_test14) {
  char buff_s21[128];
  char buff_orig[128];

  long long num = 123456789012345;

  s21_sprintf(buff_s21, "long long int: %lld", num);
  sprintf(buff_orig, "long long int: %lld", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test15) {
  char buff_s21[128];
  char buff_orig[128];

  int num = 1234;

  s21_sprintf(buff_s21, "int: %6d", num);
  sprintf(buff_orig, "int: %6d", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test16) {
  char buff_s21[128];
  char buff_orig[128];

  unsigned int num = 1234;

  s21_sprintf(buff_s21, "int: %6u", num);
  sprintf(buff_orig, "int: %6u", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test17) {
  char buff_s21[128];
  char buff_orig[128];

  unsigned int num = 1234;

  s21_sprintf(buff_s21, "int: %*u", 6, num);
  sprintf(buff_orig, "int: %*u", 6, num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test18) {
  char buff_s21[128];
  char buff_orig[128];

  int num = 0;

  s21_sprintf(buff_s21, "Int: %d", num);
  sprintf(buff_orig, "Int: %d", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test19) {
  char buff_s21[128];
  char buff_orig[128];

  int num = -12;

  s21_sprintf(buff_s21, "Int: %-6d", num);
  sprintf(buff_orig, "Int: %-6d", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test20) {
  char buff_s21[128];
  char buff_orig[128];

  int num = 0;

  s21_sprintf(buff_s21, "Int: %6d", num);
  sprintf(buff_orig, "Int: %6d", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test21) {
  char buff_s21[128];
  char buff_orig[128];

  unsigned long int num = 12345;

  s21_sprintf(buff_s21, "Int: %lu", num);
  sprintf(buff_orig, "Int: %lu", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test22) {
  char buff_s21[128];
  char buff_orig[128];

  unsigned short num = 12345;

  s21_sprintf(buff_s21, "Int: %hu", num);
  sprintf(buff_orig, "Int: %hu", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test23) {
  char buff_s21[128];
  char buff_orig[128];

  unsigned num = 12345;

  s21_sprintf(buff_s21, "Int: %6u", num);
  sprintf(buff_orig, "Int: %6u", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test24) {
  char buff_s21[128];
  char buff_orig[128];

  unsigned num = 0;

  s21_sprintf(buff_s21, "Int: %6u", num);
  sprintf(buff_orig, "Int: %6u", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test25) {
  char buff_s21[128];
  char buff_orig[128];

  char num = 'a';

  s21_sprintf(buff_s21, "Int: %6c", num);
  sprintf(buff_orig, "Int: %6c", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test26) {
  char buff_s21[128];
  char buff_orig[128];

  unsigned int num = 0;

  s21_sprintf(buff_s21, "Int: %u", num);
  sprintf(buff_orig, "Int: %u", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test27) {
  char buff_s21[128];
  char buff_orig[128];

  char num[] = "";

  s21_sprintf(buff_s21, "Int: %6s", num);
  sprintf(buff_orig, "Int: %6s", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test28) {
  char buff_s21[128];
  char buff_orig[128];

  float num = 1.4;

  s21_sprintf(buff_s21, "Int: %6f", num);
  sprintf(buff_orig, "Int: %6f", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test29) {
  char buff_s21[128];
  char buff_orig[128];

  char num = 'a';

  s21_sprintf(buff_s21, "Int: %-6c", num);
  sprintf(buff_orig, "Int: %-6c", num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test30) {
  char buff_s21[128];
  char buff_orig[128];

  char str[] = "Hello, world!";

  s21_sprintf(buff_s21, "Int: %.3s", str);
  sprintf(buff_orig, "Int: %.3s", str);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test31) {
  char buff_s21[128];
  char buff_orig[128];

  char str[] = "Hello, world!";

  s21_sprintf(buff_s21, "Int: %-20s", str);
  sprintf(buff_orig, "Int: %-20s", str);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test32) {
  char buff_s21[128];
  char buff_orig[128];

  char str[] = "Hello, world!";

  s21_sprintf(buff_s21, "Int: %5.1s", str);
  sprintf(buff_orig, "Int: %5.1s", str);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test33) {
  char buff_s21[100];
  char buff_orig[100];

  unsigned int num = 42;
  int width = 6;

  s21_sprintf(buff_s21, "Int: %*u", width, num);
  sprintf(buff_orig, "Int: %*u", width, num);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test34) {
  char buff_s21[128];
  char buff_orig[128];

  int str = 1;

  s21_sprintf(buff_s21, "Int: %+i", str);
  sprintf(buff_orig, "Int: %+i", str);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test35) {
  char buff_s21[128];
  char buff_orig[128];

  int str = 0;

  s21_sprintf(buff_s21, "Int: % 6.1i", str);
  sprintf(buff_orig, "Int: % 6.1i", str);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

START_TEST(sprintf_test36) {
  char buff_s21[128];
  char buff_orig[128];

  int str = 0;

  s21_sprintf(buff_s21, "Int: % 6i", str);
  sprintf(buff_orig, "Int: % 6i", str);

  ck_assert_str_eq(buff_s21, buff_orig);
}
END_TEST

Suite *sprintf_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Test s21_sprintf");

  tc_core = tcase_create("sprintf");

  tcase_add_test(tc_core, sprintf_test1);
  tcase_add_test(tc_core, sprintf_test2);
  tcase_add_test(tc_core, sprintf_test3);
  tcase_add_test(tc_core, sprintf_test4);
  tcase_add_test(tc_core, sprintf_test5);
  tcase_add_test(tc_core, sprintf_test6);
  tcase_add_test(tc_core, sprintf_test7);
  tcase_add_test(tc_core, sprintf_test8);
  tcase_add_test(tc_core, sprintf_test9);
  tcase_add_test(tc_core, sprintf_test10);
  tcase_add_test(tc_core, sprintf_test11);
  tcase_add_test(tc_core, sprintf_test12);
  tcase_add_test(tc_core, sprintf_test13);
  tcase_add_test(tc_core, sprintf_test14);
  tcase_add_test(tc_core, sprintf_test15);
  tcase_add_test(tc_core, sprintf_test16);
  tcase_add_test(tc_core, sprintf_test17);
  tcase_add_test(tc_core, sprintf_test18);
  tcase_add_test(tc_core, sprintf_test19);
  tcase_add_test(tc_core, sprintf_test20);
  tcase_add_test(tc_core, sprintf_test21);
  tcase_add_test(tc_core, sprintf_test22);
  tcase_add_test(tc_core, sprintf_test23);
  tcase_add_test(tc_core, sprintf_test24);
  tcase_add_test(tc_core, sprintf_test25);
  tcase_add_test(tc_core, sprintf_test26);
  tcase_add_test(tc_core, sprintf_test27);
  tcase_add_test(tc_core, sprintf_test28);
  tcase_add_test(tc_core, sprintf_test29);
  tcase_add_test(tc_core, sprintf_test30);
  tcase_add_test(tc_core, sprintf_test31);
  tcase_add_test(tc_core, sprintf_test32);
  tcase_add_test(tc_core, sprintf_test33);
  tcase_add_test(tc_core, sprintf_test34);
  tcase_add_test(tc_core, sprintf_test35);
  tcase_add_test(tc_core, sprintf_test36);
  suite_add_tcase(s, tc_core);

  return s;
}
