#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_SUBSTRACT 1
#define F_ADDITION 2
#define F_NULL 4
#define F_STRUCT 8
#define F_WIDTH 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format
 * @fn: The function associated
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: Struct format
 * @fm_t: Struct function associated
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int _processPrint(const char *fmt, int *i,
		va_list list, char b[], int flags, int width, int _prec, int size);

/* FUNCTIONS */

/* Handles characters and strings */
int _printC(va_list types, char b[],
		int flags, int width, int _prec, int size);
int _printS(va_list types, char b[],
		int flags, int width, int _prec, int size);
int _printPerc(va_list types, char b[],
		int flags, int width, int _prec, int size);

/* Handles numbers */
int _printI(va_list types, char b[],
		int flags, int width, int _prec, int size);
int _printB(va_list types, char b[],
		int flags, int width, int _prec, int size);
int _printU(va_list types, char b[],
		int flags, int width, int _prec, int size);
int _printO(va_list types, char b[],
		int flags, int width, int _prec, int size);
int _printH(va_list types, char b[],
		int flags, int width, int _prec, int size);
int print_hexa_upper(va_list types, char b[],
		int flags, int width, int _prec, int size);
int print_hexa(va_list types, char map_to[],
		char b[], int flags, char flag_ch, int width, int _prec, int size);

/* Handles non printable characters */
int print_non_printable(va_list types, char b[],
		int flags, int width, int _prec, int size);

/* Handles memory address */
int print_pointer(va_list types, char b[],
		int flags, int width, int _prec, int size);

/* Process other specifiers */
int fetchMark(const char *format, int *i);
int fetchSpace(const char *format, int *i, va_list list);
int fetchPrecision(const char *format, int *i, va_list list);
int fetchRange(const char *format, int *i);

/* Handles string in reverse */
int print_reverse(va_list types, char b[],
		int flags, int width, int _prec, int size);

/* Handles string in rot13 */
int print_rot13string(va_list types, char b[],
		int flags, int width, int _prec, int size);

/* Handles width */
int handle_write_char(char c, char b[],
		int flags, int width, int _prec, int size);
int write_number(int is_positive, int ind, char b[],
		int flags, int width, int _prec, int size);
int write_digit(int ind, char bff[], int flags, int width, int _prec,
		int length, char padd, char extra_c);
int write_pointer(char b[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int has_neg, int ind, char b[],
		int flags, int width, int _prec, int size);

/* UTILS */
int _canPrint(char);
int append_hexa_code(char, char[], int);
int _hasDigit(char);

long int size_to_digit(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
