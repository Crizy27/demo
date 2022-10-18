#include "main.h"

/************************ PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = conver_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';

	buffer[BUFFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*************** PRINT UNSIGNED NUMBER IN OCTAL ***************/
/**
 * print_octal - prints an unsigned number in octal notation
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = conver_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/************* PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
  /**
   * print_hexadecimal - prints an unsigned number in hexadecimal notation
   * @types: List a of arguments
   * @buffer: Buffer array to handle print
   * @flags: Calculates active flags
   * @width: get width
   * @precision specification
   * @size: Size specifier
   * Return: Number of chars printed.
   */
int print_hexadecimal(va_list types, char buffer[],
		 int flags, int width, int precision, int size)

{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
/************** PRINT HEXX NUM IN LOWER OR UPPER ***************/
/**
 * print_hexa - prints a hexadecimal number in lower or upper
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_hexa(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFFF_SIZE - 2;

	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = conver_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flags;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

