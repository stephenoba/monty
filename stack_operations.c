#include "monty.h"

/**
 * print_stack - prints the data in a stack
 * @head: first item in stack
 *
 */
void print_stack(stack_t *head)
{
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 * push - insert item to stack
 * @head: pointer to head
 */
stack_t *push(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		handle_error(1);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
	return (new_node);
}

/**
 * free_stack - free nodes
 * @head: head of list
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (temp)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}