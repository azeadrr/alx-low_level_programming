#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search
 * Return: value is not present in array or if array is NULL
 * your function must return -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t x, jump, step;

	if (!array || !size)
		return (-1);

	step = sqrt(size);
	for (x = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		x = jump;
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", x, jump);
	jump = jump < size - 1 ? jump : size - 1;
	for (; x < jump && array[x] < value; x++)
		printf("Value checked array[%ld] = [%d]\n", x, array[x]);
	printf("Value checked array[%ld] = [%d]\n", x, array[x]);
	return (array[x] == value ? (int)x : -1);
}
