#include "main.h"

/**
 * print_num - prints a number
 * @n: number
 *
 * Return: 0
 */
int print_num(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;
	if (n1 / 10)
		print_num(n1 / 10);
	_putchar((n1 % 10) + '0');
	return (0);
}
/**
 * print_integer - prints an integer
 *
 * @list: list from the _printf
 *
 * Return: number
 */
int print_integer(va_list list)
{
	int num_len;

	num_len = print_num(va_arg(list, int));
	return (num_len);
}
/**
 * print_percent - Prints a percent symbol
 * @list: list of arguments
 * Return: return the amount of characters printed.
 *
 */
int print_percent(va_list list)
{
	int count;

	count = _putchar(va_arg(list, int));
	_putchar('%');
	count++;
	return (1);
}
