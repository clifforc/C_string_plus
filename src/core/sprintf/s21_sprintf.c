#include "s21_sprintf.h"

/*
str − Это С-строка, которую функция обрабатывает в качестве источника для
извлечения данных; format −  это С-строка, содержащая один или несколько
следующих элементов: пробельный символ, непробельный символ и спецификаторы
формата. Спецификатор формата для печатающих функций следует прототипу:
%[флаги][ширина][.точность][длина]спецификатор. Спецификатор формата для
сканирующих функций следует прототипу: %[*][ширина][длина]спецификатор.
*/

int s21_sprintf(char *str, const char *format, ...) {
  const char specifiers[] = "cdifsu%";
  // начальное положение, чтобы узнать сколько символов мы записали
  char *src = str;

  va_list args;
  va_start(args, format);
  while (*format) {
    if (*format == '%') {
      format++;
      desc spec = {0};  // нулим всю структуру
      spec.number_system = 10;  // делаем 10-чную систему счисления
      format = set_flags(&spec, format, &args);  // парсинг флагов
      // поиск спецификаторов
      while (!s21_strchr(specifiers, *format)) format++;
      str = spec_parser(str, src, format, spec, &args);
    } else {
      *str = *format;
      str++;
    }
    format++;
  }
  *str = '\0';
  va_end(args);
  return (str - src);
}

const char *get_flags(const char *format, desc *spec) {
  while (format) {
    if (*format == '+')
      spec->plus = 1;
    else if (*format == '-')
      spec->minus = 1;
    else if (*format == ' ')
      spec->space = 1;
    else {
      break;
    }
    format++;
  }

  // приоритет флагов и уничтожение тех что ниже  по приоритетности :c
  spec->space = (spec->space && !spec->plus);
  return format;
}

const char *set_flags(desc *spec, const char *format, va_list *args) {
  format = get_flags(format, spec);
  format = get_width(format, &spec->width, args);
  if (*format == '.') {  // встречаем точность после ширины
    spec->dot = 1;
    format += 1;
    format = get_width(format, &spec->precision, args);  // ширина после точки
  }
  if (*format == 'l')
    spec->length = 'l';
  else if (*format == 'h')
    spec->length = 'h';
  if (spec->length != 0) format += 1;
  return format;
}

/*
получаем ширину
допустим нам нужна ширина 14
в первой итерации мы  наш width 0 * 10 = 0 + ('1' - '0') получили 1
во второй итерации width 1 * 10 = 1 + ('4' - '0') получили 14
*/
const char *get_width(const char *format, int *width, va_list *args) {
  *width = 0;
  // если ширина идет с *, то ширина должна быть взять из переменной которая
  // идет после format
  if (*format == '*') {
    *width = va_arg(*args, int);
    format++;
  }
  while (format) {
    if ('0' <= *format && *format <= '9') {
      *width *= 10;
      // получаем из символьного числа обычное по таблице ASCII
      *width += *format - '0';
    } else {
      break;
    }
    format++;
  }
  return format;
}

char *spec_parser(char *str, char *src, const char *format, desc spec,
                  va_list *args) {
  if (*format == 'd' || *format == 'i') {
    str = spec_integer(str, spec, args);
  } else if (*format == 'u') {
    str = spec_uinteger(str, spec, *(format - 1), args);
  } else if (*format == 'c') {
    int sym = va_arg(*args, int);
    str = spec_char(str, spec, sym);
  } else if (*format == 's') {
    str = spec_string(str, spec, args);
  } else if (*format == '%') {
    str = spec_char(str, spec, '%');
  } else if (*format == 'f') {
    double value = va_arg(*args, double);
    str = spec_float(str, spec, value);
  }
  if (!str) *src = '\0';
  return str;
}

// обработка спецификатора d
char *spec_integer(char *str, desc spec, va_list *args) {
  long int num = 0;
  if (spec.length == 'l') {
    num = (long int)va_arg(*args, long int);
  } else if (spec.length == 'h') {
    num = (short)va_arg(*args, int);
  } else {
    num = (int)va_arg(*args, int);
  }
  s21_size_t integer_size = get_int_size(&spec, num);
  char *str_to_num = calloc(integer_size + 1, sizeof(char));
  if (str_to_num) {
    int i = int_to_str(spec, num, str_to_num, integer_size);
    // поскольку функция вернула нам число в обратном порядке, циклом
    // переворачиваем его обратно
    for (int j = i - 1; j >= 0; j--) {
      *str = str_to_num[j];
      str++;
    }
    // если количество записанных символов меньше чем ширина
    while (i < spec.width) {
      *str = ' ';
      str++;
      i++;
    }
  }
  if (str_to_num) free(str_to_num);
  return str;
}

// вычисляем длину числа в строке
s21_size_t get_int_size(desc *spec, long int num) {
  s21_size_t result = 0;
  long int num_cpy = num;
  // если пришло отрицательное число то меняем на положительное
  if (num_cpy < 0) {
    num_cpy = -num_cpy;
    result++;
  }
  //если пришло число 125 то в цикле поочередно делим его на 10 чтобы получить
  //длину 3
  while (num_cpy > 0) {
    num_cpy /= 10;
    result++;
  }
  // обработка для флагов , выделяем место под них
  if (num_cpy == 0 && result == 0 &&
      (spec->precision || spec->width || spec->space)) {
    result++;
  }
  // теперь проверяем нужно ли доп место под флаги
  if ((s21_size_t)spec->width > result) result = spec->width;
  if ((s21_size_t)spec->precision > result) result = spec->precision;

  if (spec->space || spec->plus || num < 0) {
    spec->flag_to_size = 1;
    result++;
  }
  if (result == 0 && num_cpy == 0 && !spec->precision && !spec->width &&
      !spec->space && !spec->dot) {
    result++;
  }
  return result;
}

// инт в строку
int int_to_str(desc spec, long int num, char *str_to_num,
               s21_size_t integer_size) {
  // для удобства работаю с модулем числа
  int flag = 0;
  if (num < 0) {
    flag = 1;
    num = -num;
  }
  int i = 0;
  long int num_cpy = num;
  // запись числа в буфер, если число == 0
  if ((num_cpy == 0 && (spec.precision || spec.width || spec.space)) ||
      (num_cpy == 0 && !spec.precision && !spec.width && !spec.dot)) {
    // 0 == '\0', получаем сивол нуля
    char sym = num_cpy % spec.number_system + '0';
    str_to_num[i] = sym;
    i++;
    integer_size--;
    num_cpy /= 10;
  }
  // запись числа в буфер, если число != 0
  while (num_cpy && str_to_num && integer_size) {
    char sym = get_num_char(num_cpy % spec.number_system);
    str_to_num[i] = sym;
    i++;
    integer_size--;
    num_cpy /= 10;
  }

  if (flag) num = -num;

  // обработка + - и space

  if (spec.space && num >= 0 && integer_size) {
    str_to_num[i] = ' ';
    i++;
    integer_size--;
  }
  if (num < 0 && integer_size) {
    str_to_num[i] = '-';
    i++;
    integer_size--;
  }
  if (num > 0 && spec.plus && integer_size) {
    str_to_num[i] = '+';
    i++;
    integer_size--;
  }

  // ситуация когда осталось свободное место в строке
  if (integer_size > 0 && spec.minus == 0) {
    while ((integer_size - spec.flag_to_size > 0) && str_to_num) {
      str_to_num[i] = ' ';
      i++;
      integer_size--;
    }
  }
  return i;
}

char get_num_char(int num) {
  char flag = '0';
  if (num >= 0 && num <= 9) flag = (char)(num + 48);  // 48 == '0'
  return flag;
}

// обработка u
char *spec_uinteger(char *str, desc spec, char format, va_list *args) {
  unsigned long int num = 0;
  if (format == 'l')
    num = (unsigned long int)va_arg(*args, unsigned long int);
  else if (format == 'h')
    num = (unsigned short)va_arg(*args, unsigned int);
  else
    num = (unsigned int)va_arg(*args, unsigned int);

  // вычисление размера массива
  s21_size_t uinteger_size = get_uint_size(&spec, num);
  char *buf = calloc(uinteger_size + 1, sizeof(char));
  // перевод uint в строку
  if (buf) {
    int i = uint_to_str(buf, spec, num, uinteger_size);
    for (int j = i - 1; j >= 0; j--) {
      *str = buf[j];
      str++;
    }
    // если количество записанных символов меньше чем ширина
    // while (i < spec.width) {
    //   *str = ' ';
    //   str++;
    // }
  }
  if (buf) free(buf);
  return str;
}

// вычисляю длину unsigned
s21_size_t get_uint_size(desc *spec, unsigned long int num) {
  s21_size_t result = 0;
  unsigned long int num_cpy = num;
  //если пришло число 125 то в цикле поочередно делим его на 10 чтобы получить
  //длину 3
  while (num_cpy > 0) {
    num_cpy /= 10;
    result++;
  }
  // обработка для флагов , выделяем место под них
  if (result == 0 && (spec->precision || spec->width || spec->space)) {
    result++;
  }
  // теперь проверяем нужно ли доп место под флаги
  if ((s21_size_t)spec->width > result) result = spec->width;
  if ((s21_size_t)spec->precision > result) result = spec->precision;

  if (result == 0 && !spec->precision && !spec->width && !spec->space &&
      !spec->dot) {
    result++;
  }
  return result;
}

int uint_to_str(char *buf, desc spec, unsigned long int num,
                s21_size_t uinteger_size) {
  int i = 0;
  unsigned long int num_cpy = num;

  // запись числа в буфер, если число == 0
  if ((num_cpy == 0 && (spec.precision || spec.width || spec.space)) ||
      (num_cpy == 0 && !spec.precision && !spec.width && !spec.dot)) {
    // 0 == '\0', получаем сивол нуля
    char sym = num_cpy % spec.number_system + '0';
    buf[i] = sym;
    i++;
    uinteger_size--;
    num_cpy /= 10;
  }
  // запись числа в буфер, если число != 0
  while (num_cpy && buf && uinteger_size) {
    char sym = get_num_char(num_cpy % spec.number_system);
    buf[i] = sym;
    i++;
    uinteger_size--;
    num_cpy /= 10;
  }

  // под осташееся место в строке для пробелов
  if (uinteger_size > 0 && spec.minus == 0) {
    while ((uinteger_size - spec.flag_to_size > 0) && buf) {
      buf[i] = ' ';
      i++;
      uinteger_size--;
    }
  }
  return i;
}

// обработка char
char *spec_char(char *str, desc spec, int sym) {
  char *ptr = S21_NULL;
  int i = 0;

  // - 1 потому что резервируем один сивол под сам спецификатор
  while (spec.width - 1 > 0 && !spec.minus) {
    *str = ' ';
    str++;
    i++;
    spec.width--;
  }
  // обработка ascii символов
  if (sym <= 127) {
    *str = sym;
    str++;
    i++;
    // запись пробелов справа если был минус
    while (spec.width - 1 > 0 && spec.minus) {
      *str = ' ';
      str++;
      i++;
      spec.width--;
    }
    ptr = str;
  }
  return ptr;
}

// обработка строк

char *spec_string(char *str, desc spec, va_list *args) {
  char *ptr = str;
  char *string = va_arg(*args, char *);
  // если получили строку
  if (string) {
    int res = spec.width, i = 0;
    // если ширина не указана или меньше длины строки
    if ((s21_size_t)spec.width < s21_strlen(string))
      spec.width = s21_strlen(string);

    // если ширина больше чем длина строки, то пустое место пробелами
    // white = кол-ву пробелов
    int white = spec.width - s21_strlen(string);

    // если точность не указана
    if (spec.precision == 0) spec.precision = spec.width;

    //  если точность меньше изначальной длины и она указана меня кол-во
    //  пробелов
    if (spec.precision != 0 && spec.precision < res)
      white = res - spec.precision;

    // если минуса не было - пробелы слева
    while (white && !spec.minus) {
      *str = ' ';
      str++;
      white--;
    }

    // посимвольная запись полученной строки в str
    while (*string != '\0') {
      if (!spec.precision) break;
      *str = *string;
      str++;
      string++;
      i++;
      spec.precision--;
    }

    // если был указан минус, то заполняем пробелы справа
    while (white && spec.minus) {
      *str = ' ';
      str++;
      white--;
    }
  } else {
    // если не удалось получить строку то в нее null
    str = s21_memcpy(str, "(null)", 6);
    str += 6;
  }
  // присваем ptr str и возвращаем его, чтобы передвинуть указатель нашей строки
  if (ptr) ptr = str;
  return ptr;
}

char *spec_float(char *str, desc spec, double value) {
  int int_part = (int)value;
  double fractional_part = value - int_part;
  char temp[100];
  int i = 0;

  if (int_part == 0) {
    *str++ = '0';
  } else {
    while (int_part != 0) {
      temp[i++] = '0' + (int_part % 10);
      int_part /= 10;
    }
    while (i > 0) {
      *str++ = temp[--i];
    }
  }

  int precision = 0;
  if (!spec.precision) {
    precision = 6;
  } else {
    precision = spec.precision;
  }

  *str++ = '.';

  fractional_part *= pow(10, precision);
  int fractional_as_int = (int)round(fractional_part);
  i = 0;
  while (fractional_as_int != 0) {
    temp[i++] = '0' + (fractional_as_int % 10);
    fractional_as_int /= 10;
  }
  while (i > 0) {
    *str++ = temp[--i];
  }

  *str = '\0';

  return str;
}