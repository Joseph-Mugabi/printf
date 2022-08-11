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
	int num_len = 0, len, i, count, n, p, num;

	n = va_arg(list, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			num_len++;
		}
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		p = 1;
		for (i = 1; i <= len - 1; i++)
			p *= 10;
		for (i = 1; i <= len; i++)
		{
			count = n / p;
			if (n < 0)
				_putchar((count * -1) + 48);
			else
				_putchar(count + '0');
			num_len++;
			n -= (count * p);
			p /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
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
