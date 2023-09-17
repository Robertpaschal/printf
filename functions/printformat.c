#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - prints a character that expects the int specifier
 * @format: the character that is passed to the input
 * Return: 0 (Success)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format++);
			count++;
		}
		else
		{
			format++;
			if (*format == 'c' || *format == '%')
			{
				putchar(va_arg(args, int));
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				while (*str)
				{
					putchar(*str++);
					count++;
				}
			}
			format++;
		}
	}
	va_end(args);
	return (count);
}
