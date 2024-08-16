#include "../../s21_string.h"

char *s21_strchr(const char *str, int c) {
  for (; *str != '\0'; str++) {
    if (*str == c) {
      return (char *)str;
    }
  }
  return S21_NULL;
}
