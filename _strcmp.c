/**
 * _strcmp - function that compares two strings.
 * @s1: pointer param 1.
 * @s2: pointer param 2.
 *
 * Return: if s1 equal s2 it returns 0,
 * negative if s1 less than s2,
 * positive if s2 greater than s2.
 */

int _strcmp(char *s1, char *s2)
{
	unsigned char c1, c2;

	do {
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 == '\0')
			return (c1 - c2);
	} while (c1 == c2);

	return (c1 - c2);
}
