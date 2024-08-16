# s21_string+

## Description

s21_string+ is an implementation of the standard C string.h library with additional string manipulation functions inspired by C#. This project is part of an educational program, completed as a team effort, aimed at deepening the understanding of string operations, memory management, and C programming.

The library is developed in C11 standard using the gcc compiler.</br>
The library is implemented as a static library named `s21_string.a`.</br>
The project is fully covered with unit tests using the Check library.

## Implemented Functions

### string.h Functions

1. **memchr** - Locate character in block of memory;
2. **memcmp** - Compare two blocks of memory;
3. **memcpy** - Copy block of memory;
4. **memset** - Fill block of memory;
5. **strncat** - Concatenate strings with limit;
6. **strchr** - Locate first occurrence of character in string;
7. **strncmp** - Compare strings with limit;
8. **strncpy** - Copy string with limit;
9. **strcspn** - Get span until character in string;
10. **strerror** - Get string describing error code;
11. **strlen** - Get string length;
12. **strpbrk** - Locate characters in string;
13. **strrchr** - Locate last occurrence of character in string;
14. **strstr** - Locate substring;
15. **strtok** - Split string into tokens.

### sprintf Function (Partial Implementation)

Partial support for string formatting with the following capabilities:

#### Format Specifiers:
- **%c** - Character;
- **%d** - Signed decimal integer;
- **%f** - Decimal floating point;
- **%s** - String of characters;
- **%u** - Unsigned decimal integer;
- **%%** - Percent sign.

#### Flags:
- **-** - Left-justify within the given field width;
- **+** - Forces to precede the result with a plus or minus sign (+ or -);
- **(space)** - If no sign is going to be written, a blank space is inserted before the value.

#### Width:
- **(number)** - Minimum number of characters to be printed.

#### Precision:
- **.(number)** - For floating-point numbers: number of digits after the decimal point.
  For strings: maximum number of characters to be printed.

#### Length:
- **h** - Used with integer types (short int);
- **l** - Used with integer types (long int).

### Additional String Functions

1. **to_upper** - Convert string to uppercase;
2. **to_lower** - Convert string to lowercase;
3. **insert** - Insert substring at given position;
4. **trim** - Remove specified characters from the beginning and end of the string.

## Building and Usage

A Makefile is used to build the library and run tests with the following targets:

- `make all`: build the entire project;
- `make clean`: clean build files;
- `make test`: run unit tests;
- `make s21_string.a`: build the static library;
- `make gcov_report`: generate a test coverage report in HTML format.

## Project Team

The project was completed by a team of School 21 students.

## License

This project is part of the educational program at [School21](https://21-school.ru/) - an educational project by Sber for developers.