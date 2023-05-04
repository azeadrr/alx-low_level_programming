#include "main.h"

/**
 * get_bit - returns the value of a bit at given index
 * @n: unsigned long int input
 * @in: index of the bit
 * Return: value of the bit
 */

int get_bit(unsigned long int n, unsigned int in)
{
	unsigned int i;

	if (n == 0 && in < 64)
		return (0);

	for (i = 0; i <= 63; n >>= 1, i++)
	{
		if (in == i)
		{
			return (n & 1);
		}
	}
	return (-1);
}
