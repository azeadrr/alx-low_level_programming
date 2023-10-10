#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: is a pointer to the head of the skip list to search in
 * @value: is the value to search for
 * Return: If value is not present in list or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *gov;

	if (list == NULL)
		return (NULL);
	gov = list;
	do {
		list = gov;
		gov = gov->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)gov->index, gov->n);
	} while (gov->express && gov->n < value);
	if (gov->express == NULL)
	{
		list = gov;
		while (gov->next)
			gov = gov->next;
	}
	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)gov->index);
	while (list != gov->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}
