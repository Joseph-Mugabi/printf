#include "main.h"

/**
 * convert_c - Converts an argument to an unsigned cha
 * @list: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_c(va_list list, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char c;
	unsigned int count = 0;

	(void)prec;
	(void)len;

	c = va_arg(list, int);
	count += print_width(output, count, flags, wid);
	count += _memcpy(output, &c, 1);
	count += print_neg_width(output, count, flags, wid);

	return (count);
}
/**
 * convert_percent - Stores a percent sign
 * @list: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 * Return: The number of bytes stored to the buffer (always 1).
 */
unsigned int convert_percent(va_list list, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char percent = '%';
	unsigned int count = 0;

	(void)list;
	(void)prec;
	(void)len;

	count += print_width(output, count, flags, wid);
	count += _memcpy(output, &percent, 1);
	count += print_neg_width(output, count, flags, wid);

	return (count);
}
/**
 * convert_p - Converts the address of an argument to hex
 * @list: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_p(va_list list, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int count = 0;

	(void)len;

	address = va_arg(list, unsigned long int);
	if (address == '\0')
		return (_memcpy(output, null, 5));
	flags |= 32;
	count += convert_ubase(output, address, "0123456789abcdef",
			flags, wid, prec);
	count += print_neg_width(output, count, flags, wid);

	return (count);
}
