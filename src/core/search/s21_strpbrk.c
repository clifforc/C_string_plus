#include "../../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  for (; *str1; str1++) {
    const char *str2_copy = str2;
    for (; *str2_copy; str2_copy++) {
      if (*str1 == *str2_copy) {
        return (char *)str1;
      }
    }
  }
  return S21_NULL;
}