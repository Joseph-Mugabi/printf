#include "main.h"

/**
 * _puts - output a string from stdout
 *   
 *  @str: string from main
 *  Return: 0
 */
 int _puts(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		_putchar(str[i]);
		count++;
		i++;
	}
	return (count);
}
/**
 * print_string - prints a string
 * @list: list from _printf  
 */
int print_string(va_list list)
{
	return (_puts(va_arg(list, char *)));
}
