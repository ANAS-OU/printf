#include "main.h"

/**
 * get_specifier_handler - function that takes a char and
 * returns a pointer to a function that handle a specific
 * case and return an integer.
 * @spc: input specifier
 *
 * Return: integer
 */
int (*get_specifier_handler(char *spc))(va_list args)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_perc},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (specifiers[i].specifier)
	{
		if (!_strcmp(spc, specifiers[i].specifier))
			return (specifiers[i].f);
		i++;
	}
	return (NULL);
}
