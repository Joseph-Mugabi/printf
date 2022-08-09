#include "main.h"

/**
 * convert - converts int to binary, then print prints
 * @n: unsigned integer
 * @count: pointer to the count of iteration
 *
 * Return: 0
 */
int convert(unsigned int n, int *count)
{
	if (n / 2)
	{
		convert(n / 2, count);
		_putchar((n % 2) + '0');
		(*count)++;
	}
	return (0);
}
/**
 * _print_binary - prints an integer to  binary base
 * @list: pointer to unsigned integer
 *
 * Return: integer/ count of characters
 */
int _print_binary(va_list list)
{
	unsigned int ;
	int count = 0;

	n = va_arg(list, unsigned int);
	convert(n, &count);

	return (count);
}
