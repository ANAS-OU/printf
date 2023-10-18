#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - Produces output according to a given format string
 * @format: The format string containing characters and specifiers
 *
 * Description: This function calls the appropriate printing function
 * based on the conversion specifiers in the format string.
 * Return: The length of the formatted output string.
 */
int _printf(const char *format, ...)
{
	int (*print_func)(va_list, flags_t *);
	const char *fmt_ptr;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	register int char_count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (fmt_ptr = format; *fmt_ptr; fmt_ptr++)
	{
		if (*fmt_ptr == '%')
		{
			fmt_ptr++;
			if (*fmt_ptr == '%')
			{
				char_count += _putchar('%');
				continue;
			}
			while (get_flag(*fmt_ptr, &flags))
				fmt_ptr++;
			print_func = get_print(*fmt_ptr);
			char_count += (print_func)
				? print_func(arguments, &flags)
				: _printf("%%%c", *fmt_ptr);
		} else
			char_count += _putchar(*fmt_ptr);
	}
	_putchar(-1);
	va_end(arguments);
	return (char_count);
}
