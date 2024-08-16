#include "../../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  const char *var1 = str1;
  const char *var2 = str2;

  for (size_t i = 0; i < n; i++) {
    if (var1[i] != var2[i]) {
      result = var1[i] - var2[i];
      break;
    }
  }
  return result;
}