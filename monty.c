#include "monty.h"

char *line = NULL;

/**
 * is_empty - checks if a line is empty
 * @wc: word count
 *
 * Return: 0 or 1
 */
int is_empty(ssize_t wc)
{
	size_t i = 0;

	if (wc == 0)
		return (1);

	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
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
	FILE *stream;
	size_t len = 0;
	ssize_t wc;
	unsigned int lc;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		write(2, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	stream = fopen(av[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	lc = 1;
	while ((wc = getline(&line, &len, stream)) != -1)
	{
		line[strcspn(line, "\n")] = '\0';
		if (is_empty(wc))
			continue;
		process_line(&stack, lc);
		lc++;
	}
	free(line);
	free_stack(stack);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
