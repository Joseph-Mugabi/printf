#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  print_hex_HEX - prints an unsigned int in hexidecimal form
 *  @n: unsigned int to print
 *  @l: flag to determine case of printing (0 = lower, 1 = upper)
 *
 *  Return: number of digits printed
 */
int print_hex_HEX(unsigned int n, unsigned int l)
{
	unsigned int a[8], i, m, sum;
	char d;
	int count;

	m = 268435456; /* 16^7 */
	if (l)
	{
		d = 'A' - ':';
	}
	else
	{
		d = 'a' - ':';
	}
	a[0] = n / m;
	for (i = 1; i < 8; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0, count = 0; i < 8; i++)
	{
		sum += a[i];
		if (sum || i == 7)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + d + a[i]);
			count++;
		}
	}
	return (count);
}
/**
 *  print_hex - takes an unsigned int and prints it in lowercase hex notation
 *  @list: unsigned int to print
 *
 *  Return: number of digits printed
 */
int print_hex(va_list list)
{
	return (print_hex_HEX(va_arg(list, unsigned int), 0));
}
/**
 *  print_HEX - takes am unsigned int and prints it in uppercase hex notation
 *  @list: unsigned int to print
 *
 *  Return: number of digits printed
 */
int print_HEX(va_list list)
{
	return (print_hex_HEX(va_arg(list, unsigned int), 1));
}
/**
 * print_octal - prints octal
 *  @list: octal list to be printed
 * Return: size or count
 */

int print_octal(va_list list)
{
	int count = 0;
	unsigned int len, p, j, d, n, num;

	n = va_arg(list, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 8;
			len++;
		}
		p = 1;
		for (j = 1; j <= len - 1; j++)
			p *= 8;
		for (j = 1; j <= len; j++)
		{
			d = n / p;
			_putchar(d + '0');
			count++;
			n -= (d * p);
			p /= 8;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
