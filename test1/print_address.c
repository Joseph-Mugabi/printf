#include "main.h"

/**
 *  conver_t - converts number and base into string
 *  @num: input number
 *  @base: input base
 *  @lowercase: flag if hexa values need to be lowercase
 *  Return: result string
 */
char *conver_t(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buf[50];
	char *p;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	p = &buf[9];
	*p = '\0';
	do {
		*--p = rep[num % base];
		num /= base;
	} while (num != 0);
	return (p);
}
/**
 *  print_address - prints address of input in hexa format
 *  @list: va_list arguments from _printf
 *
 *  if a flag is passed to _printf
 *  Return: count
 */
int print_address(va_list list)
{
	char *s;
	unsigned long int p = va_arg(list, unsigned long int);

	register int count = 0;

	if (!p)
		return (puts("(nil)"));
	s = conver_t(p, 16, 1);
	count += _puts("0x");
	count += _puts(s);
	return (count);
}
