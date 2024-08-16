#include "../../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0')  // Проверяем, не является ли needle пустой строкой
    return (char *)haystack;

  for (; *haystack; haystack++) {
    const char *haystack_copy = haystack;
    const char *needle_copy = needle;
    while (*haystack_copy && *needle_copy &&
           *haystack_copy ==
               *needle_copy) {  // Используем цикл while для сравнения символов
      haystack_copy++;
      needle_copy++;
    }
    if (*needle_copy ==
        '\0')  // Если needle_copy достиг конца, значит, вхождение найдено
      return (char *)haystack;
  }
  return S21_NULL;
}
