#include "main.h"

/**
 * _printf - Custom printf function to format and print output
 * @format: A format string containing characters and specifiers
 *
 * Description: This function calls get_print() to determine the
 * appropriate printing function based on conversion specifiers in 'format'.
 *
 * Return: The length of the formatted output string.
 * Authors: Ehoneah Obed & Abdulhakeem Badejo
 */
int _printf(const char *format, ...)
{
	int (*print_function)(va_list, flags_t *);
	const char *pointer;
	va_list args;
	flags_t flags = {0, 0, 0};
	register int char_count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (pointer = format; *pointer; pointer++)
	{
		if (*pointer == '%')
		{
			pointer++;
			if (*pointer == '%')
			{
				char_count += _putchar('%');
				continue;
			}
			while (get_flag(*pointer, &flags))
				pointer++;
			print_function = get_print(*pointer);
			char_count += (print_function)
				? print_function(args, &flags)
				: _printf("%%%c", *pointer);
		}
		else
			char_count += _putchar(*pointer);
	}
	_putchar(-1);
	va_end(args);
	return (char_count);
}
