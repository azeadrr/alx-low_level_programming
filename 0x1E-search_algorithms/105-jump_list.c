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
	size_t i, kv, re;
	listint_t *pv;

	if (list == NULL || size == 0)
		return (NULL);

	re = (size_t)sqrt((double)size);
	i = 0;
	kv = 0;

	do {
		pv = list;
		kv++;
		i = kv * re;
		while (list->next && list->i < i)
			list = list->next;

		if (list->next == NULL && i != list->i)
			i = list->i;

		printf("Value checked at index [%d] = [%d]\n", (int)i, list->n);

	} while (i < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)pv->i, (int)list->i);

	for (; pv && pv->i <= list->i; pv = pv->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)pv->i, pv->n);
		if (pv->n == value)
			return (pv);
	}

	return (NULL);
}
