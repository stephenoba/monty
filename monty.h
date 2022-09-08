#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_BUF_SIZE 1024
#define UNUSED(x) (void)(x)

extern char *line;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void process_line(stack_t **stack, unsigned int line_number);

/* ERROR HANDLING */
int handle_error(int error_code, stack_t *stack);
void malloc_failed(void);
void raise_opcode_error(unsigned int line_number, char *opcode, stack_t *stack);

/* STACK OPERATIONS */
void print_stack(stack_t *head);
stack_t *push(stack_t **head, int n);
void free_stack(stack_t *head);
void peek(stack_t *head);

/* OPCODE FUNCTIONS */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
