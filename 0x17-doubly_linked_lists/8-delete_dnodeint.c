#include "lists.h"

/**
 * delete_dnodeint_at_index - Remove the node
 * at the given index in the linked list
 * @head: A pointer head of doubly linked list
 * @index:Index of the position to insert the new node
 * Return: 1 if it succeeded, -1 if it failed
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tp1, *tp2;
	unsigned int i;

	tp1 = *head;

	if (tp1 != NULL)
	{
		while (tp1->prev != NULL)
			tp1 = tp1->prev;
	}

	i = 0;

	while (tp1 != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = tp1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				tp2->next = tp1->next;

				if (tp1->next != NULL)
					tp1->next->prev = tp2;
			}
			free(tp1);
			return (1);
		}
		tp2 = tp1;
		tp1 = tp1->next;
		i++;
	}

	return (-1);
}
