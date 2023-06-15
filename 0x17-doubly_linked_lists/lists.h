#include <stdlib.h>
#include <stdio.h>
#ifndef LISTS_H
#define LISTS_H

/**
 * struct dlistint_s -Bidirectional of list linked
 * @n: integer
 * @next: Links to the next node
 * @prev: Links to the previous node
 * note: Node format for a doubly linked list
 */

typedef struct dlistint_s
{
	int n;
	struct dlistint_s *next;
	struct dlistint_s *prev;
}
dlistint_t;

size_t dlistint_len(const dlistint_t *h);
size_t print_dlistint(const dlistint_t *h);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
int sum_dlistint(dlistint_t *head);
void free_dlistint(dlistint_t *head);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);

#endif
