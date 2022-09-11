#include "monty.h"

/**
 * push_end - add node to end of dlistint_t
 * @head: head of list
 * @n: element to add
 *
 * Return: new node
 */
stack_t *push_end(stack_t **head, const int n)
{
	stack_t *current, *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	current = *head;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;
	return (new);
}
