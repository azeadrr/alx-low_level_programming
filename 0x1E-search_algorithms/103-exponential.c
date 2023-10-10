#include "search_algos.h"

/**
 * _binary_search - searches for a value in a sorted array of integers
 * @array: is a pointer to the first element of the array to search in
 * @value: is the value to search for
 * @rgh: The ending index of array to search
 * @lef: The starting index of array to search
 * Return: If value is not present in array or if array is NULL
 * your function must return -1
 */
int _binary_search(int *array, size_t lef, size_t rgh, int value)
{
	size_t x;

	if (array == NULL)
		return (-1);
	while (rgh >= lef)
	{
		printf("Searching in array: ");
		for (x = lef; x < rgh; x++)
			printf("%d, ", array[x]);
		printf("%d\n", array[x]);
		x = lef + (rgh - lef) / 2;
		if (array[x] == value)
			return (x);
		if (array[x] > value)
			rgh = x - 1;
		else
			lef = x + 1;
	}
	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array
 * @array: is a pointer to the first element of the array to search
 * @size: is the number of elements in array
 * @value: is the value to search
 * Return: If value is not present in array or if array is NULL
 * your function must return -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t x = 0, rgh;

	if (array == NULL)
		return (-1);
	if (array[0] != value)
	{
		for (x = 1; x < size && array[x] <= value; x = x * 2)
			printf("Value checked array[%ld] = [%d]\n", x, array[x]);
	}
	rgh = x < size ? x : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", x / 2, rgh);
	return (_binary_search(array, x / 2, rgh, value));
}
