#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a new node to the end of the linked list
 * @head: pointer head of doubly linked list
 * @n: Value to assign to the new node
 * Return: address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tp, *tn;

	if (head == NULL)
		return (NULL);

	tp = malloc(sizeof(dlistint_t));

	if (tp == NULL)
		return (NULL);

	tp->n = n;

	if (*head == NULL)
	{
		tp->next = *head;
		tp->prev = NULL;
		*head = tp;
	}
	else
	{
		tn = *head;
		while (tn->next != NULL)
			tn = tn->next;
		tp->prev = NULL;
		tp->prev = tn;
		tn->next = tp;
	}
	return (tp);
}
