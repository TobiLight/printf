#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	_printf("Character:[%c]\n", 'h');
	printf("Character:[%c]\n", 'h');
	_printf("%s\n", "Hello world");
	printf("%s\n", "Hello world");

	return (0);
}