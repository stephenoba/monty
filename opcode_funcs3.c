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

/**
 * op_pchar - prints the character at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Description: Prints the ASCII character that corresponds
 * to the integer held by the first node
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	char *err_msg1 = "L%d: can't pchar, value out of range\n";
	char *err_msg2 = "L%d: can't pchar, stack empty\n";

	if (!(*stack))
	{
		raise_operation_error(err_msg2, line_number, *stack);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		raise_operation_error(err_msg1, line_number, *stack);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * op_pstr - prints the string starting  at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	UNUSED(line_number);

	while (*stack)
	{
		if ((*stack)->n <= 0 || (*stack)->n > 127)
		{
			break;
		}
		printf("%c", (*stack)->n);
		*stack = (*stack)->next;
	}
	printf("\n");
}
