#include "main.h"

/**
 * _putchar - function that writes a given
 * character to stdout.
 * @c: input char.
 *
 * Return: On success 1,
 * On error -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - function that prints a given string
 * to the standard output (stdout).
 * @str: input string.
 *
 * Return: str length.
 */
int _puts(char *str)
{
	int len = 0;

	while (*str)
	{
		_putchar(*str++);
		len++;
	}
	return (len);
}
