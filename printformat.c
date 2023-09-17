#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - prints a character that expects the int specifier
 * @format: the character that is passed to the input
 * @...: list of argument
 * Return: 0 (Success)
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int count;
	int i;
	int len;

	va_start(args, format);
	count = 0;

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				_mputchar(va_arg(args, int));
				count++;
			}
			else if (*format == 'c')
			{
				char asci = va_arg(args, int);

				if (asci >= 32 && asci <= 126)
					_mputchar(asci);
				else
					return (-1);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				len = strlen(str);
				for (i = 0; i < len; i++)
				{
					_mputchar(str[i]);

					count += len;
				}
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
