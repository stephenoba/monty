#include "monty.h"

/**
 * op_add - add the first two items in stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int total;
	char *err_msg = "L%d: can't add, stack too short\n";

	if (*stack == NULL || (*stack)->next == NULL)
	{
		raise_operation_error(err_msg, line_number, *stack);
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

/**
 * op_sub - compute difference of the first two items in stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	int diff;
	char *err_msg = "L%d: can't sub, stack too short\n";

	if (*stack == NULL || (*stack)->next == NULL)
	{
		raise_operation_error(err_msg, line_number, *stack);
	}
	diff = (*stack)->next->n - (*stack)->n;
	pop(stack);
	(*stack)->n = diff;
}

/**
 * op_div - compute quotient of the first two items in stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	int quotient;
	char *err_msg1 = "L%d: can't div, stack too short\n";
	char *err_msg2 = "L%d: division by zero\n";
	
	if (*stack == NULL || (*stack)->next == NULL)
	{
		raise_operation_error(err_msg1, line_number, *stack);
	}
	if ((*stack)->n == 0 || (*stack)->next->n == 0)
	{
		raise_operation_error(err_msg2, line_number, *stack);
	}
	quotient = (*stack)->next->n / (*stack)->n;
	pop(stack);
	(*stack)->n = quotient;
}
