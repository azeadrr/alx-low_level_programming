#include "lists.h"

/**
 * insert_dnodeint_at_index - Add a new node
 * at a specified index in the linked list
 * @h:  head of linked list
 * @idx: Index of the position to insert the new node
 * @n: Element at position n for the new node
 * Return: new node, NULL it it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tp, *tn;
	unsigned int position;

	if (h == NULL)
		return (NULL);
	tp = malloc(sizeof(dlistint_t));
	if (tp == NULL)
		return (NULL);
	tp->n = n;
	if (idx == 0)
	{
		tp->next = *h;
		tp->prev = NULL;
		if (tp->next != NULL)
			tp->next->prev = tp;
		*h = tp;
	}
	else
	{
		tn = *h;
		for (position = 0; tn != NULL && position < (idx - 1); position++)
			tn = tn->next;
		if (tn == NULL)
		{
			free(tp);
			return (NULL);
		}
		tp->next = tn->next;
		tp->prev = tn;
		if (tn->next != NULL)
			tn->next->prev = tp;
		tn->next = tp;
	}
	return (tp);
}
