#include "lists.h"

/**
 * sum_dlistint - Calculate function for
 * finding the sum of data in a linked list
 * @head:pointer head of linked list
 * Return: if the list is empty, return 0
 */

int sum_dlistint(dlistint_t *head)
{
	int re = 0;

	if (head == NULL)
		return (0);

	while (head->prev != NULL)
		head = head->prev;

	while (head != NULL)
	{
		re += head->n;
		head = head->next;
	}

	return (re);
}
