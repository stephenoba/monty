#include "monty.h"

/**
 * op_push - push an item to the stack
 * @stack: pointer to head
 * @line_number: line number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	char *item;
	int n;

	UNUSED(line_number);
	item = strtok(NULL, " ");
	if (!item)
	{
		raise_opcode_error(line_number, "push", *stack);
	}
	n = atoi(item);
	if (n == 0)
	{
		raise_opcode_error(line_number, "push", *stack);
	}
	push(stack, n);
}

/**
 * op_pall - print the content in the stack
 * @stack: pointer to head
 * @line_number: line number
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	print_stack(*stack);
}

void op_pint(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);
	peek(*stack);
}
