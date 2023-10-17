#include "main.h"

/**
 * print_char - function that use _putchar
 * to wrrite on stdout a given character.
 * @args: _printf argments list
 *
 * Return: 1 on success, -1 on error
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	return (_putchar(c));
}

/**
 * print_str - function that prints to stdout
 * a given string and return its length.
 * @args: _printf argments list
 *
 * Return: string length
 */
int print_str(va_list args)
{
	int len;

	len = _puts(va_arg(args, char*));
	return (len);
}

/**
 * print_perc - function that handle the %
 * case.
 * @args: _printf argments list ase.
 *
 * Return: always 1.
 */
int print_perc(va_list args)
{
	(void)args;

	return (_putchar('%'));
}