#include "../../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  if (n == 0) {
    return 0;
  }
  for (; n > 1 && *str1 && *str1 == *str2; str1++, str2++, n--) {
  }
  return *str1 - *str2;
}
