#include "monty.h"

/**
 * op_push - push an item to the stack
 * @stack: pointer to head
 * @line_number: line number
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	char *item;
	char *err_msg = "L%d: usage: push integer\n";
	int n;

	item = strtok(NULL, " ");
	if (!item || is_number(item) == 0)
	{
		raise_operation_error(err_msg, line_number, *stack);
	}
	n = atoi(item);
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

/**
 * op_pint - print the first item in the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	int ret;
	char *err_msg = "L%d: can't pint, stack empty\n";

	ret = peek(*stack);
	if (ret != 0)
	{
		raise_operation_error(err_msg, line_number, *stack);
	}
}

/**
 * op_pop - remove the first item in the stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ret;
	char *err_msg = "L%d: can't pop an empty stack\n";

	ret = pop(stack);
	if (ret == NULL)
	{
		raise_operation_error(err_msg, line_number, *stack);
	}
	free(ret);
}

/**
 * op_swap - swap the first two items in stack
 * @stack: pointer to stack
 * @line_number: line number
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	char *err_msg = "L%d: can't swap, stack too short\n";

	temp = *stack;
	if (temp == NULL || temp->next == NULL)
	{
		raise_operation_error(err_msg, line_number, *stack);
	}
	*stack = temp->next;
	temp->prev = temp->next;
	temp->next = temp->next->next;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
}
