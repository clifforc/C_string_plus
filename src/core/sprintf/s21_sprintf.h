#ifndef S21_SPRINTF_H_
#define S21_SPRINTF_H_

#include <math.h>
#include <stdarg.h>

#include "../../s21_string.h"

typedef struct descriptions {
  int minus;          // к левому краю
  int plus;           // пишем знак
  int space;          // знак или пробел
  int width;          // ширина
  int precision;      // точность
  char length;        // тип переменной
  int number_system;  // система исчисления
  int flag_to_size;  // если число отрицательное или есть  + или space
  int dot;           // наличие точки в числе
  int g;             // наличие спецификатора g
  int e;             // запись числа в научной нотации
} desc;

const char *get_flags(const char *format, desc *spec);
const char *set_flags(desc *spec, const char *format, va_list *args);
const char *get_width(const char *format, int *width, va_list *args);
char *spec_parser(char *str, char *src, const char *format, desc spec,
                  va_list *args);
char *spec_integer(char *str, desc spec, va_list *arguments);
s21_size_t get_int_size(desc *spec, long int num);
int int_to_str(desc spec, long int num, char *str_to_num,
               s21_size_t integer_size);
char get_num_char(int num);
char *spec_uinteger(char *str, desc spec, char format, va_list *args);
s21_size_t get_uint_size(desc *spec, unsigned long int num);
int uint_to_str(char *buf, desc spec, unsigned long int num,
                s21_size_t uinteger_size);
char *spec_char(char *str, desc spec, int sym);
char *spec_string(char *str, desc spec, va_list *args);
char *spec_float(char *str, desc spec, double value);

#endif