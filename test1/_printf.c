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
	int i = 0, count  = 0;

	va_list list;

	va_start(list, format);
	while (format[i])
	{
		while (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case 'c':
				count += print_char(list);
				i += 2;
				break;
			case '%':
				_putchar('%');
				count++;
				i += 2;
				break;
			case 'i':
				count += print_integer(list);
				i += 2;
				break;
			case 'b':
				count += _print_binary(list);
				i += 2;
				break;
			default:
				_putchar(format[i]);
				_putchar(format[i + 1]);
				i += 2;
				break;
			}
		}
		if (format[i])
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(list);
	return (count);
}
