#include "main.h"

void handle_loading(char b[], int *Lmain);

/**
 * _printf - prints formated string to standard output
 * @format: formated string containing the string to print with specifiers
 * Return: count of Printed characters
 */
int _printf(const char *format, ...)
{
	int s, gValuecount = 0, printNum = 0;
	int marks, base, eval, size, load_ind = 0;
	va_list list;
	char b[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (s = 0; format && format[s] != '\0'; s++)
	{
		if (format[s] != '%')
		{
			b[load_ind++] = format[s];
			if (load_ind == BUFF_SIZE)
				handle_loading(b, &load_ind);
			/* write(1, &format[i], 1); */
			printNum++;
		}
		else
		{
			handle_loading(b, &load_ind);
			marks = fetchmarks(format, &s);
			base = fetchbase(format, &s, list);
			eval = fetchPreci(format, &s, list);
			size = fetchSize(format, &s);
			++s;
			gValuecount = _processPrint(format, &s, list, b,
					marks, base, eval, size);
			if (gValuecount == -1)
				return (-1);
			printNum += gValuecount;
		}
	}

	handle_loading(b, &load_ind);

	va_end(list);

	return (printNum);
}

/**
 * handle_loading - handles buffer contents if they exists
 * @b:  Character arrays
 * @Lmain: Index to add next character, representing the length.
 */

void handle_loading(char b[], int *Lmain)
{
	if (*Lmain > 0)
		write(1, &b[0], *Lmain);

	*Lmain = 0;
}
