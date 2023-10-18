#include "main.h"

/**
 * _printf - Custom implementation of printf
 * @format: A pointer to the format string
 *
 * Description: This function implements a subset of printf functionality.
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	const char *string;
	int count = 0;
	va_list args;

	if (!format)
		return (-1);

	va_start(args, format);
	string = format;

	count = loop_format(args, string);

	va_end(args);
	return (count);
}

/**
 * loop_format - Loop through the format string
 * @arg: The va_list argument
 * @string: A pointer to the format string
 *
 * Description: This function iterates through the format string and processes
 * format specifiers.
 * Return: The number of characters printed.
 */
int loop_format(va_list arg, const char *string)
{
	int i = 0, flag = 0, count_format = 0, count = 0, check_percent = 0;

	while (i < _strlen((char *)string) && *string != '\0')
	{
		char character = string[i];

		if (character == '%')
		{
			i++, flag++;
			character = string[i];
			if (character == '\0' && _strlen((char *)string) == 1)
				return (-1);
			if (character == '\0')
				return (count);
			if (character == '%')
			{
				flag++;
			}
			else
			{
				count_format = function_manager(character, arg);
				if (count_format >= 0 && count_format != -1)
				{
					i++;
					character = string[i];
					if (character == '%')
						flag--;
					count = count + count_format;
				}
				else if (count_format == -1 && character != '\n')
				{
					count += _putchar('%');
				}
			}
		}
		check_percent = check_percent(&flag, character);
		count += check_percent;
		if (check_percent == 0 && character != '\0' && character != '%')
			count += _putchar(character), i++;
		check_percent = 0;
	}
	return (count);
}

/**
 * check_percent - Print '%' character
 * @flag: A pointer to the flag
 * @character: The character to check
 *
 * Description: This function prints a '%' character and updates the flag.
 * Return: 1 if '%' is printed, 0 otherwise.
 */
int check_percent(int *flag, char character)
{
	int tmp_flag;
	int count = 0;

	tmp_flag = *flag;
	if (tmp_flag == 2 && character == '%')
	{
		_putchar('%');
		tmp_flag = 0;
		count = 1;
	}
	return (count);
}

/**
 * call_function_manager - Call function manager
 * @character: The character parameter
 * @arg: The va_list argument
 *
 * Description: This function calls the function manager.
 * Return: The number of characters printed.
 */
int call_function_manager(char character, va_list arg)
{
	int count = 0;

	count = function_manager(character, arg);
	return (count);
}
