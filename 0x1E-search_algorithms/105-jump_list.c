#include <math.h>
#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted
 * list of integers using the Jump search algorithm
 * @list: is a pointer to the head of the list to search in
 * @size: is the number of nodes in list
 * @value: is the value to search for
 * Return: If value is not present in head or if head is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t index, kv, re;
	listint_t *prev;

	if (list == NULL || size == 0)
		return (NULL);
	re = (size_t)sqrt((double)size);
	index = 0;
	kv = 0;
	do {
		prev = list;
		kv++;
		index = kv * re;
		while (list->next && list->index < index)
			list = list->next;

		if (list->next == NULL && index != list->index)
			index = list->index;
		printf("Value checked at index [%d] = [%d]\n", (int)index, list->n);
	} while (index < size && list->next && list->n < value);
	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)prev->index, (int)list->index);
	for (; prev && prev->index <= list->index; prev = prev->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)prev->index, prev->n);
		if (prev->n == value)
			return (prev);
	}
	return (NULL);
}
