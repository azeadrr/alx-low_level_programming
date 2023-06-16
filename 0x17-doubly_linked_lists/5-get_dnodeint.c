#include "lists.h"

/**
 * get_dnodeint_at_index - Find the node
 * located at position n in the linked list
 * @index: Index of the node to retrieve in the linked list
 * @head: Pointer pointing to the beginning of the linked list
 * Return: if the node does not exist, return NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (count < index)
	{
		if (head == NULL)
			return (NULL);
		count++;
		head = head->next;
	}
	return (head);
}
