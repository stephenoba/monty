#include "monty.h"

/**
 * op_mod - compute remainder of the first two items in stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	int remainder;
	char *err_msg1 = "L%d: can't mod, stack too short\n";
	char *err_msg2 = "L%d: division by zero\n";
	
	if (*stack == NULL || (*stack)->next == NULL)
	{
		raise_operation_error(err_msg1, line_number, *stack);
	}
	if ((*stack)->n == 0 || (*stack)->next->n == 0)
	{
		raise_operation_error(err_msg2, line_number, *stack);
	}
	remainder = (*stack)->next->n % (*stack)->n;
	pop(stack);
	(*stack)->n = remainder;
}
