#include "main.h"

/**
 * print_number - function that prints an integer
 * to stdout.
 * @n: integer param.
 */

void print_number(int n)
{
	if (n == INT_MIN)
	{
		_putchar('-');
		_putchar('2');
		print_number(147483648);
		return;
	}

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10)
		print_number(n / 10);

	_putchar(n % 10 + '0');
}
