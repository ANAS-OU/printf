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
	char *str;

	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	return (_puts(str));
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

/**
 * print_int - function that use other functions
 * to counts an integer's digits and prints them
 * to the stdout.
 * @args: _printf argments list.
 *
 * Return: number of digits (length).
 */
int print_int(va_list args)
{
	int n, bytes;

	n = va_arg(args, int);
	print_number(n);
	bytes = digits_counter(n);

	return (bytes);
}
