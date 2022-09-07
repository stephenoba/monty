#include "monty.h"
#include <string.h>

char *buf;

void push(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	write(1, "push", 4);
}

void pall(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
	write(1, "pallyyyyyy\n", 11);
}


/**
 * get_opcode - get opcode from line
 *  *
 */
char *get_opcode(void)
{
	return ("pall");
}

/**
 * process_file - process a monty byte code file
 * @fd: file descriptor
 * @size: size of line
 *
 * Return: 0 if successful or -1 if failure
 */
int process_file(int fd, size_t size)
{
	char c = ' ';
	unsigned int lc = 1;
	char *buffer = NULL, *opcode;
	size_t wc = 0;
	instruction_t instructions[] = {
		{ "push", push },
		{ "pall", pall },
		{ NULL, NULL }
	};
	stack_t *stack = NULL;
	int i;

	while (c != EOF)
	{
		if (!buffer)
		{
			buffer = malloc(sizeof(char) * size);
			if (buffer == NULL)
			{
				/* handle error */
				write(2, "Error: malloc failed\n", 21);
				exit(EXIT_FAILURE);
			}
		}
		read(fd, &c, 1);
		if (c != '\n')
		{
			buffer[wc] = c;
		}
		else
		{
			/* *lineptr = buffer; */
			/* get_opcode uses the lineptr to get opcode from line */
			opcode = get_opcode();
			for (i = 0; instructions[i].opcode != NULL; i++)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, lc);
				}
			}
			free(buffer);
		}
		wc++;
		lc++;
	}
	return (0);
}

/**
 * main - Entry point to`monty bytecode interprter`
 * @ac: argument count
 * @av: filepath
 *
 * Return: EXIT_SUCCESS on success of EXIT_FAILURE on failure
 */
int main(int ac, char *av[])
{
	int fd;
	char *filename;
	size_t buf_size = MAX_BUF_SIZE;


	if (ac != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	filename = av[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		/* 
		 * write error and file name in two lines
		 * or better create a function for errors
		 */
		write(2, "Error: Can't open file <file>\n", 30);
		exit(EXIT_FAILURE);
	}

	read(fd, buf, buf_size)
	process_file(fd, buf_size);
	close(fd);
	return (0);
}
