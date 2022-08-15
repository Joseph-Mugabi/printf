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
	static char buffer[50];
	char *p;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	p = &buffer[9];
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
int print_address(va_list l, flags_t *f)
{
	char *s;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));
	s = conver_t(p, 16, 1);
	count += _puts("0x");
	count += _puts(s);
	return (count);
}
