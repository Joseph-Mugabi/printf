#include "main.h"

/**
 * func_link - receives and link the string parameter
 * @format: contain strings
 * @list: list from the _printf
 * @choice: choice of all functions.
 *
 * Return: count of characters in total
 */
int func_link(const char *format, datatype choice[], va_list list)
{
	int i, j, k;
	int count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; choice[j].letter != NULL; j++)
			{
				if (format[i + 1] == choice[j].letter[0])
				{
					k = choice[j].format(list);
					if (k == -1)
						return (-1);
					count += k;
					break;
				}
			}
			if (choice[j].letter == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					count += 2;
				}
				else
					return (-1);
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	return (count);
}
