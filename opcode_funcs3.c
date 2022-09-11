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
	stack_t *first;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		raise_operation_error(err_msg1, line_number, *stack);
	}
	if ((*stack)->n == 0 || (*stack)->next->n == 0)
	{
		raise_operation_error(err_msg2, line_number, *stack);
	}
	remainder = (*stack)->next->n % (*stack)->n;
	first = pop(stack);
	free(first);
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
	stack_t *temp = *stack;

	UNUSED(line_number);
	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * op_rotl - moves the first item to the end
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	int n;

	UNUSED(line_number);
	if (*stack)
	{
		first = pop(stack);
		n = first->n;
		free(first);
		push_end(stack, n);
	}
}

/**
 * op_rotr - moves the last item to the front
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	int n;

	UNUSED(line_number);
	if (*stack)
	{
		first = pop_end(stack);
		n = first->n;
		free(first);
		push(stack, n);
	}
}

