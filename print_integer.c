#include "main.h"

/**
 * print_num - prints a number
 * @n: number
 *
 * Return: 0
 */
int print_num(va_list list)
{
	unsigned int n1;
	int n, j = 1, len = 0;

	n = va_arg(list, int);
	if (n < 0)
	{
		len += _putchar('-');
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	for (; n1 / j > 9; )
		j *= 10;
	for (; j != 0; )
	{
		len += _putchar('0' + n1 / j);
		n1 %= j;
		j /= 10;
	}

	return (len);
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

	num_len = print_num(list);
	num_len++;
	return (num_len);
}
/**
 * print_percent - Prints a percent symbol
 * @list: list of arguments
 * Return: return the amount of characters printed.
 *
 */
int print_percent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}
