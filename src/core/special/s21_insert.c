#include "../../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *result = S21_NULL;
  if (src != S21_NULL && str != S21_NULL && start_index <= s21_strlen(src)) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t all_len = src_len + str_len;
    result = (char *)calloc(all_len + 1, sizeof(char));
    if (result) {
      s21_strncpy(result, src, start_index);
      s21_strncpy(result + start_index, str, str_len);
      s21_strncpy(result + start_index + str_len, src + start_index,
                  src_len - start_index);
      result[all_len] = '\0';
    }
  }
  return (void *)result;
}