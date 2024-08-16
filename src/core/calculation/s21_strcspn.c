#include "../../s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t len = 0;
  while (*str1 && !s21_strchr(str2, *str1)) {
    str1++;
    len++;
  }
  return len;
}