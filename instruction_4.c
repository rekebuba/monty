#include "main.h"
#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the node
 * @line: number of the line in the file
 */
void pchar(stack_t **stack, unsigned int line)
{
	stack_t *ptr = *stack;
	char asci;

	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		free_stack(1);
		exit(EXIT_FAILURE);
	}
	asci = ptr->n;
	if (asci < 'A' || asci > 'z')
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		free_stack(1);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", asci);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the node
 * @line: number of the line in the file
 */
void pstr(stack_t **stack, unsigned int line)
{
	stack_t *ptr = *stack;
	char *result = malloc((nod_len(stack) + 1) * sizeof(char));
	int index = 0;
	char asci;
	(void)line;
	if (result == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(1);
		exit(EXIT_FAILURE);
	}
	if (ptr == NULL)
	{
		fprintf(stderr, "\n");
	}
	else
	{
		while (1)
		{
			if (ptr == NULL || ptr->n == 0 || (ptr->n < 'A' || ptr->n > 'z'))
			{
				break;
			}
			asci = ptr->n;
			result[index++] = asci;
			ptr = ptr->next;
		}
		result[index] = '\0';
		fprintf(stdout, "%s\n", result);
	}
	free(result);
}