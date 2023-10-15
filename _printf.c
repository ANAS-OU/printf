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
	unsigned int n = 0; /* number of bytes printted to stdout */
	char *str;

	/* check if format not point to NULL */
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	/* A loop that iterates through all characteres */
	{
		if (*format == '%') /* if format points to a % sign */
			switch (*(++format))
			/* then we check the character that comes after the % */
			{
				case 'c':
					n += _putchar(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char *);
					while (*str)
						n += _putchar(*str++);
					break;
				case '%':
					n += _putchar(*format);
					break;
				default:
					break;
			}
		else
			n += _putchar(*format);
		format++; /* increase by one byte */
	}
	va_end(args);
	return (n);
}
