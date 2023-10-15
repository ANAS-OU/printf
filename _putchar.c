#include "main.h"

/**
 * _putchar - function that writes a given
 * character to stdout.
 * @c: input char.
 *
 * Return: On success 1,
 * On error -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
