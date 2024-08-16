#include "../../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *token = S21_NULL;
  if (str == S21_NULL) str = token;
  while ((str != NULL) && (*str != '\0') && (s21_strchr(delim, *str) != NULL)) {
    str++;
  }
  if (str && *str == '\0') {
    str = S21_NULL;
    token = S21_NULL;
  }
  if (str && *str != '\0') {
    token = str;
    while (*token && !(s21_strchr(delim, *token))) {
      token++;
    }
  }
  if (token && *token) {
    *token = '\0';
    token++;
  }
  return str;
}