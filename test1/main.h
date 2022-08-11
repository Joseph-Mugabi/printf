#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
/**
 *  struct dt - struct
 *  @letter: letter signifying data type
 *  @format: function ptr (pointer)
 */
struct dt
{
	char *letter;
	int (*format)(va_list);
};
typedef struct dt datatype;

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list);
int print_integer(va_list);
int _print_binary(va_list);
int func_link(const char *format, datatype choice[], va_list list);
int print_percent(va_list);
int print_string(va_list list);
int print_unsigned_int(va_list list);
int print_octal(va_list);
int print_HEX(va_list);
int print_hex(va_list);

#endif
