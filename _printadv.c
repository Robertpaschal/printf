#include "main.h"

/************* PRINT POINTER *************/

/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List of arguments
 * @b: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @_prec: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */

int print_pointer(va_list types, char b[],
		int flags, int width, int _prec, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	b[BUFF_SIZE - 1] = '\0';
	UNUSED(_prec);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		b[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	} 

	if ((flags &  F_NULL) && !(flags & F_SUBSTRACT))
		padd = '0';
	if (flags & F_ADDITION)
		extra_c = '+', length++;
	else if (flags &  F_WIDTH)
		extra_c = ' ', length++;

	ind++;

	/* return (write(1, &b[i], BUFF_SIZE - i - 1)); */
	return (write_pointer(b, ind, length,
				width, flags, padd, extra_c, padd_start));
}

/******************** PRINT NON PRINTABLE ********************/

/**
 * print_non_printable - Prints ascii codes in hexa of non printable
 * characters
 * @types: List of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @_prec: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */

int print_non_printable(va_list types, char b[],
		int flags, int width, int _prec, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(_prec);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (_canPrint(str[i]))
			b[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], b, i + offset);

		i++;
	}

	b[i + offset] = '\0';
	return (write(1, b, i + offset));
}

/******************** PRINT REVERSE ********************/

/**
 * print_reverse - Prints reverse string.
 * @types: List of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @_prec: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char b[],
		int flags, int width, int _prec, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(b);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(_prec);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/******************** PRINT A STRING IN ROT13 ********************/

/**
 * print_rot13string - Print a string in rot13.
 * @types: List of arguments
 * @b: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @_prec: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list types, char b[],
		int flags, int width, int _prec, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(b);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(_prec);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
