#include <stdarg.h>
#include <stdbool.h>

#include "../../s21_string.h"

int str_to_int(const char *str, int *result) {
  int sign = 1;
  int ok = 1;
  *result = 0;

  if (*str == '-') {
    sign = -1;
    str++;
  }

  while (*str >= '0' && *str <= '9') {
    *result = (*result * 10) + (*str - '0');
    str++;
  }

  *result *= sign;
  return ok;
}

int str_to_unsigned_int(const char *str, unsigned int *result) {
  *result = 0;
  int ok = 1;

  while (*str >= '0' && *str <= '9') {
    *result = (*result * 10) + (*str - '0');
    str++;
  }

  return ok;
}

int str_to_float(const char *str, float *result) {
  int sign = 1;
  *result = 0.0f;
  float fraction = 0.0f;
  float divisor = 10.0f;
  int is_decimal_point = 0;
  int ok = 1;

  if (*str == '-') {
    sign = -1;
    str++;
  }

  while (*str != '\0' && ((*str >= '0' && *str <= '9') || *str == '.')) {
    if (*str == '.') {
      is_decimal_point = 1;
      str++;
      continue;
    }
    if (is_decimal_point) {
      fraction += (*str - '0') / divisor;
      divisor *= 10.0f;
    } else {
      *result = (*result * 10.0f) + (*str - '0');
    }
    str++;
  }

  *result += fraction;
  *result *= sign;
  return ok;
}

void parse_char(const char **s, char *ptr, int *count) {
  if (**s != '\0') {
    *ptr = **s;
    (*s)++;
    (*count)++;
  }
}

void parse_int(const char **s, int *ptr, int *count) {
  str_to_int(*s, ptr);
  while (**s != '\0' && (**s == '-' || (**s >= '0' && **s <= '9'))) {
    (*s)++;
  }
  (*count)++;
}

void parse_unsigned_int(const char **s, unsigned int *ptr, int *count) {
  str_to_unsigned_int(*s, ptr);
  while (**s != '0' && (**s >= '0' && **s <= '9')) {
    (*s)++;
  }
  (*count)++;
}

void parse_float(const char **s, float *ptr, int *count) {
  str_to_float(*s, ptr);
  while (**s != '\0' &&
         ((**s >= '0' && **s <= '9') || **s == '.' || **s == '-')) {
    (*s)++;
  }
  (*count)++;
}

void parse_str(const char **s, char *ptr, int *count) {
  while (**s != '\0' && **s != ' ' && **s != '\t') {
    *ptr = **s;
    ptr++;
    (*s)++;
  }
  *ptr = '\0';
  (*count)++;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int count = 0;
  const char *s = str;
  const char *f = format;

  while (*f != '\0') {
    if (*f == '%') {
      f++;
      if (*f == '\0') break;
      switch (*f) {
        case 'c': {
          char *ptr = va_arg(args, char *);
          parse_char(&s, ptr, &count);
          break;
        }
        case 'd': {
          int *ptr = va_arg(args, int *);
          parse_int(&s, ptr, &count);
          break;
        }
        case 'f': {
          float *ptr = va_arg(args, float *);
          parse_float(&s, ptr, &count);
          break;
        }
        case 's': {
          char *ptr = va_arg(args, char *);
          parse_str(&s, ptr, &count);
          break;
        }
        case 'u': {
          unsigned int *ptr = va_arg(args, unsigned int *);
          parse_unsigned_int(&s, ptr, &count);
          break;
        }
      }
    } else {
      if (*f != *s) {
        va_end(args);
        return count;
      }
      s++;
    }
    f++;
  }
  va_end(args);
  return count;
}
