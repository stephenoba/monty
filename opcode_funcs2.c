#include "monty.h"

/**
 * op_add - add the first two items in stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int total;

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		raise_add_error(line_number, *stack);
	}
	total = temp->n + temp->next->n;
	printf("%d\n", total);
}
