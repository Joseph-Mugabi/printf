#include "main.h"

/**
 * print_char - prints character to the stdout
 *
 * @va_list: list from the _printf
 * Return: 1
 */
int Print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}
