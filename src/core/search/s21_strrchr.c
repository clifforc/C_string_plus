#include "../../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *last = S21_NULL;
  for (; *str != '\0'; str++) {
    if (*str == c) {
      last = (char *)str;
    }
  }
  return last;
}
