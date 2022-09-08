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
 * peek - print first item in the stack
 * @stack: pointer to first item
 *
 * Return: 0 or -1
 */
int peek(stack_t *head)
{
	if (!head)
	{
		return (-1);
	}
	printf("%d\n", head->n);
	return (0);
}

/**
 * push - insert item to stack
 * @head: pointer to head
 * @n: node data
 *
 * Return: node
 */
stack_t *push(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		handle_error(1, *head);
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
 * pop - remove the first item in the stack
 * @head: pointer to head
 *
 * Return: 0 or -1
 */
int pop(stack_t **head)
{
	stack_t *current;

	if (!(*head))
		return (-1);

	current = *head;
	*head = current->next;
	if (current->next)
	{
		current->next->prev = NULL;
	}
	free(current);
	return (0);
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
