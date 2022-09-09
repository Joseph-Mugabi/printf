#include "main.h"

/**
 * convert_x - Converts an unsigned int argument to hex using abcdef
 * @list: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 *
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_x(va_list list, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0x";

	if (len == LONG)
		num = va_arg(list, unsigned long int);
	else
		num = va_arg(list, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, lead, 2);
	if (!(num == 0 && prec == 0))
		ret += convert_ubase(output, num, "0123456789abcdef",
				flags, wid, prec);
	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
/**
 * convert_X - Converts an unsigned int argument to hex using ABCDEF
 * @list: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_X(va_list list, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0X";

	if (len == LONG)
		num = va_arg(list, unsigned long);
	else
		num = va_arg(list, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, lead, 2);
	if (!(num == 0 && prec == 0))
		ret += convert_ubase(output, num, "0123456789ABCDEF",
				flags, wid, prec);
	ret += print_neg_width(output, ret, flags, wid);
	return (ret);
}