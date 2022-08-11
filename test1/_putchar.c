#include <unistd.h>

/**
 * _putchar - to write the character c to the stdout
 * @c: character to print
 * 
 * Return: 1 on success, or -1 on error and errno is  set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
