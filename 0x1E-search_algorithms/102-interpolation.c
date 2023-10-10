#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array of integers
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: If value is not present in array or if array is NULL
 * your function must return -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t x, a, b;

	if (array == NULL)
		return (-1);
	for (a = 0, b = size - 1; b >= a;)
	{
		x = a + (((double)(b - a) / (array[b] - array[a])) * (value - array[a]));
		if (x < size)
			printf("Value checked array[%ld] = [%d]\n", x, array[x]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", x);
			break;
		}
		if (array[x] == value)
			return (x);
		if (array[x] > value)
			b = x - 1;
		else
			a = x + 1;
	}
	return (-1);
}
