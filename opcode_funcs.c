#include "monty.h"

/**
 * op_push - push an item to the stack
 * @head: pointer to head
 * @line_number: line number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	int n;

	UNUSED(line_number);
	n = atoi(strtok(NULL, " "));
	push(stack, n);
}

/**
 * op_pall - print the content in the stack
 * @head: pointer to head
 * @ine_number: line number
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	print_stack(*stack);
}
