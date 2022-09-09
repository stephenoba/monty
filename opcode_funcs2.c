#include "monty.h"

/**
 * op_add - add the first two items in stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		raise_add_error(line_number, *stack);
	}
	total = (*stack)->n + (*stack)->next->n;
	pop(stack);
	(*stack)->n = total;
}

/**
 * op_nop - does nothing
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}
