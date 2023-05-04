#include "main.h"

/**
 * set_bit - sets value of a bit to 1 at given index
 * @n: pointer of an unsigned long int
 * @in: index of the bit
 * Return: 1 if it worked, -1 if it didn't
 */

int set_bit(unsigned long int *n, unsigned int in)
{
	unsigned int m;

	if (in > 63)
		return (-1);

	m = 1 << in;
	*n = (*n | m);

	return (1);
}
