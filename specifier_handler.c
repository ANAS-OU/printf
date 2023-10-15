#include "main.h"

/**
 * specifier_handler - function that handle
 * _printf conversion specifiers.
 * @spc: input of a given specifier
 * @args: list of _printf args
 *
 * Return: number of bytes printed to stdout
 */
int specifier_handler(char spc, va_list args)
{
	unsigned int bytes;
	char *str;

	bytes = 0;
	switch (spc)
	{
		case 'c':
			bytes += _putchar((char)va_arg(args, int));
			break;
		case 's':
			str = va_arg(args, char *);
			while (*str)
				bytes += _putchar(*str++);
			break;
		case '%':
			bytes += _putchar('%');
			break;
		case 'd':
		case 'i':
			print_number(va_arg(args, int));
			break;
		default:
			break;
	}
	return (bytes);
}
