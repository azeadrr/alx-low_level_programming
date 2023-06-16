#include "lists.h"

/**
 * free_dlistint - Dispose function for a doubly linked list
 * @head: pointer head of doubly linked list
 * Return: return
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *tp;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;
	}

	while ((tp = head) != NULL)
	{
		head = head->next;
		free(tp);
	}
}
