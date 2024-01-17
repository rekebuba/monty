#include "monty.h"
#include "main.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the node
 * @line: number of the line in the file
 */
void pint(stack_t **stack, unsigned int line)
{
	stack_t *ptr = *stack;

	if (ptr == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line);
	}
	fprintf(stdout, "%d\n", ptr->n);
}
