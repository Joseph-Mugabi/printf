#include "main.h"

/**
 * _printf - function that produces output according to format.
 * @format: a character string.
 *
 * Return: count/ number of characters counted or printed.
 */
int _printf(const char *format, ...)
{
	int i = 0, count  = 0;

	while (format[i])
	{
		_putchar(format[i]);
		count++;
		i++;
	}
	return (count);
}
