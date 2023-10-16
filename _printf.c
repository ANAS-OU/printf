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
	int bytes = 0; /* number of bytes printted to stdout */
	char *str;

	/* check if format not point to NULL */
	if (!format || (*format == '%' && !*(format + 1)))
		return (-1);
	va_start(args, format);
	while (*format)
	/* A loop that iterates through all characteres */
	{
		if (*format != '%')
			bytes += _putchar(*format); /* format doesn't point to % sign */
		else
			switch (*(++format))
			/* then we check the character that comes after the % */
			{
				case 'c':
					bytes += _putchar(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char *);
					while (*str)
						bytes += _putchar(*str++);
					break;
				case '%':
					bytes += _putchar(*format);
					break;
				default:
					_printf("Error: %% is a special character");
			}
		format++; /* increase by one byte */
	}
	va_end(args);
	return (bytes);
}
