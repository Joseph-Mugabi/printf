#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - function that produces output according to format.
 * @format: a character string.
 *
 * Return: count/ number of characters counted or printed.
 */
int _printf(const char *format, ...)
{
	int count;

	datatype choice[] = {
		{"c", print_char},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"s", print_string},
		{"b", _print_binary},
		{"u", print_unsigned_int},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{NULL, NULL}

	};
	va_list list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);

	count = func_link(format, choice, list);

	va_end(list);
	return (count);
}
