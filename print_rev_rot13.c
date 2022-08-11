#include "main.h"

/**
 *  _memcpy - copy memory area
 *  @dest: Destination for copying
 *  @src: Source to copy from
 *  @n: number of bytes to copy
 *  Return: returns a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int j;

	for (j = 0; j < n; j++)
		dest[j] = src[j];
	dest[j] = '\0';
	return (dest);
}
/**
 * rev_string - reverses a string in place
 *
 *  @s: string to reverse
 *  Return: A pointer to a character
 */
char *rev_string(char *s)
{
	int len, h;
	char tmp, *dest;

	for (len = 0; s[len] != '\0'; len++)
	{}

	dest = malloc(sizeof(char) * len + 1);
	if (dest == NULL)
		return (NULL);
	_memcpy(dest, s, len);
	for (h = 0; h < len; h++, len--)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[h];
		dest[h] = tmp;
	}
	return (dest);
}
/**
 * print_rev - Calls a function to reverse and print a string
 * @list: Argument passed to the function
 * Return: length of characters printed
 */
int print_rev(va_list list)
{
	int len;
	char *str;
	char *p;

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	p = rev_string(str);
	if (p == NULL)
		return (-1);
	for (len = 0; p[len] != '\0'; len++)
		_putchar(p[len]);
	free(p);
	return (len);
}
/**
 * rot13 - Converts string to rot13
 *  @list: string to convert
 *  Return: converted string
*/
int rot13(va_list list)
{
	int j, count = 0;
	int x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	if (str == NULL)
		return (-1);
	for (j = 0; str[j] != '\0'; j++)
	{
		for (x = 0; x < 52; x++)
		{
			if (str[j] == s[x])
			{
				_putchar(u[x]);
				count++;
				break;
			}
		}
		if (x == 53)
			_putchar(str[j]);
		j++;

	}
	return (j);
}
/**
 *  print_S - prints custom specifier
 *  @list: va_list
 *  Return: number of characters printed
 */
int print_S(va_list list)
{
	int count = 0, j = 0;
	char c;
	char *str = va_arg(list, char *);

	if (str == NULL || *str == '\0')
		return (0);
	while (str[j])
	{
		c = str[j];
		if ((c > 0 && c < 32) || c >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar('0');
			count += _printf("%X", (unsigned int) c);
		}
		else
		{
			count += _putchar(c);
		}
		j++;
	}
	return (count);
}
