#include "../../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = dest;
  const unsigned char *c = src;
  for (s21_size_t i = 0; i < n; i++) {
    d[i] = c[i];
  }
  return dest;
}