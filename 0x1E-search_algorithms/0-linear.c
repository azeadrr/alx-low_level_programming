#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "search_algos.h"

/**
 * linear_search - function that searches for a value in an array of integers
 * @array: search the value in array
 * @size: size of elements
 * @value: value for search
 * Return: first index of the found value
 */
int linear_search(int *array, size_t size, int value)
{
	size_t x;

	if (!array)
		return (-1);

	for (x = 0; x < size; x++)
	{
		printf("Value checked array[%ld] = [%d]\n", x, array[x]);
		if (array[x] == value)
			return (x);
	}

	return (-1);
}
