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
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(args, format);
	bytes = 0;
	while (*format)
	/* A loop that iterates through all characteres */
	{
		if (*format == '%' && !*(format + 1))
			return (-1);

		if (*format == '%')
		{
			format++; /* move to what follows '%' */
			(spc[0] = *format, spc[1] = '\0');
			handler = get_specifier_handler(spc);
			if (handler)
				bytes += handler(args);
			else
			{
				/* handle unknown format specifier case. */
				bytes += _putchar('%');
				bytes += _putchar(*format);
			}
		}
		else
			bytes += _putchar(*format); /* format doesn't point to % sign */

		format++; /* increase by one byte */
	}
	va_end(args);
	return (bytes);
}
