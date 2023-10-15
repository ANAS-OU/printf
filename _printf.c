#include "main.h"

/**
 * _printf - function that prints formated strings
 * @format: string format to print to the stdout
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int bytes;
	/* contains the number of characters printted by _printf */

	va_start(args, format);
	bytes = 0;
	while (*format) /* A loop that iterates through all characteres */
	{
		if (*format == '%')
			bytes += specifier_handler(*(++format), args);
		else
			bytes += _putchar(*format);
		format++;
	}
	va_end(args);
	return (bytes);
}
