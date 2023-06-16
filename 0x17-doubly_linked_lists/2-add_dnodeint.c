#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add_dnodeint - Add a new node to the head of the linked list
 * @head: pointer head of doubly linked list
 * @n: Value to assign to the new node
 * Return: address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *tp;

	if (head == NULL)
		return (NULL);

	tp = malloc(sizeof(dlistint_t));

	if (tp == NULL)
		return (NULL);

	tp->n = n;
	tp->prev = NULL;
	tp->next = *head;

	*head = tp;

	if (tp->next != NULL)
		tp->next->prev = tp;

	return (tp);
}
