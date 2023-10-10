#include "search_algos.h"

/**
 * rec_search - searches for a value in a sorted array of integers
 * @array: is a pointer to the first element of the array to search
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: If value is not present in array or if array is NULL
 * your function must return -1
 */
int rec_search(int *array, size_t size, int value)
{
	size_t x;
	size_t hlf = size / 2;

	if (array == NULL || size == 0)
		return (-1);
	printf("Searching in array");
	for (x = 0; x < size; x++)
		printf("%s %d", (x == 0) ? ":" : ",", array[x]);
	printf("\n");
	if (hlf && size % 2 == 0)
		hlf--;
	if (value == array[hlf])
	{
		if (hlf > 0)
			return (rec_search(array, hlf + 1, value));
		return ((int)hlf);
	}
	if (value < array[hlf])
		return (rec_search(array, hlf + 1, value));
	hlf++;
	return (rec_search(array + hlf, size - hlf, value) + hlf);
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: If value is not present in array or if array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	int i;

	i = rec_search(array, size, value);
	if (i >= 0 && array[i] != value)
		return (-1);

	return (i);
}
