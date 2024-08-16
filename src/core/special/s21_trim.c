#include "../../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  if (src != S21_NULL && trim_chars != S21_NULL) {
    s21_size_t len = s21_strlen(src);
    result = (char *)calloc(len + 1, sizeof(char));
    if (result) {
      s21_size_t offset = 0;
      for (s21_size_t i = 0; i < len; i++) {
        if (s21_strchr(trim_chars, src[i]) == S21_NULL) {
          result[offset++] = src[i];
        }
      }
      result[offset] = '\0';
    }
  }
  return (void *)result;
}