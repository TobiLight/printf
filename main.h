#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/* sizes */
#define S_LONG 2
#define S_SHORT 1

/* flags */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @func: The function associated.
 */
typedef struct fmt
{
	char fmt;
	int (*func)(va_list, char[], int, int, int, int);
} fmt_t;

int _printf(const char *format, ...);
int print_handler(const char *fmt, int *i, va_list list, char buffer[],
				  int flags, int width, int precision, int size);

int print_char(va_list types, char buffer[],
			   int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
				 int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int, int, int, int);

/* Specifier function handlers */
int handle_flags(const char *format, int *i);
int handle_width(const char *format, int *i, va_list list);
int handle_size(const char *format, int *i);
int handle_precision(const char *format, int *i, va_list list);

/* HANDLER */
int write_char(char c, char buffer[], int flags, int width,
			   int precision, int size);

/* utils */
int is_digit(char c);
#endif
