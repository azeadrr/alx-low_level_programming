#include "lists.h"
#include <stdio.h>

/**
 * dlistint_len - Element count function for a linked list
 * @h: pointer head of doubly linked list
 * Return: Return
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
