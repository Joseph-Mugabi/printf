#include "main.h"

/**
 * print_char - prints character to the stdout
 *
 * @list: list from the _printf
 * Return: 1
 */
int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}
