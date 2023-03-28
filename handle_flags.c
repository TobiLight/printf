/*
 * File: handle_flags.c
 * Author: TobiLight & ...
 */

#include "main.h"

/**
 * handle_flags - Returns the flags for a given format specifier
 * @format: The format string
 * @start: The starting index of the format specifier
 *
 * Return: the flags for the format specifier at the given index.
 */

int handle_flags(const char *format, int *start)
{
	int flags = 0;
	int i;

	for (i = *start; format[i] != '\0'; i++)
	{
		if (format[i] == '-')
		{
			flags |= F_MINUS;
		}
		else if (format[i] == '+')
		{
			flags |= F_PLUS;
		}
		else if (format[i] == '0')
		{
			flags |= F_ZERO;
		}
		else if (format[i] == '#')
		{
			flags |= F_HASH;
		}
		else if (format[i] == ' ')
		{
			flags |= F_SPACE;
		}
		else
		{
			break;
		}
	}

	return (flags);
}
