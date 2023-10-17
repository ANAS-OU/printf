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
	int (*handler)(va_list);
	int bytes; /* number of bytes printted to stdout */
	char spc[2];

	/* check if format not point to NULL */
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(args, format);
	bytes = 0;
	while (*format)
	/* A loop that iterates through all characteres */
	{
		if (*format != '%')
			bytes += _putchar(*format); /* format doesn't point to % sign */
		else
		{
			spc[0] = *(++format);
			handler = get_specifier_handler(spc);
			if (!handler)
				break;
			bytes += handler(args);
		}
		format++; /* increase by one byte */
	}
	va_end(args);
	return (bytes);
}
