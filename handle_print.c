/*
 * File: handle_print.c
 * Authors: TobiLight & Prince460
*/

#include "main.h"

/**
 * print_handler - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int print_handler(const char *fmt, int *ind, va_list list, char buffer[],
				  int flags, int width, int precision, int size)
{
	int i, len = 0, printed_chars = -1;
	fmt_t fmt_specifiers[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'o', print_octal}, {'u', print_unsigned}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'S', print_non_printable},
		{'\0', NULL}};
	for (i = 0; fmt_specifiers[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_specifiers[i].fmt)
			return (fmt_specifiers[i].func(list, buffer, flags, width,
										   precision, size));

	if (fmt_specifiers[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &fmt[*ind], 1);
		return (len);
	}
	return (printed_chars);
}
