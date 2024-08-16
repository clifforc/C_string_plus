#include "../../s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = S21_NULL;
  if (str != S21_NULL) {
    const char OFFSET = 'a' - 'A';
    s21_size_t len = s21_strlen(str);
    result = (char *)calloc(len + 1, sizeof(char));
    if (result) {
      for (s21_size_t i = 0; i < len; i++) {
        result[i] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - OFFSET : str[i];
      }
      result[len] = '\0';
    }
  }
  return (void *)result;
}