#include "../../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  s21_size_t i = 0;
  char *s = str;
  while (i < n) {
    s[i] = c;
    i++;
  }
  return str;
}
