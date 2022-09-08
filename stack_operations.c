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
	int n;

	new_node = malloc(sizeof(stact_t));
	if (!new_node)
	{
		handle_error(1);
	}
	/*
	n = atoi(strtok(NULL, " "));
	*/
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		*stack->prev = new_node;
	return (new_node);
}
