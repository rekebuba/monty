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
		free_stack(1);
		fprintf(stderr, "L%d: can't pint, stack empty", line);
	}
	fprintf(stdout, "%d\n", ptr->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the node
 * @line: number of the line in the file
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *ptr = *stack;
	stack_t *ptr2 = *stack;
	if (ptr == NULL)
	{
		fprintf(stdout, "L%d: can't pop an empty stack\n", line);
		free_stack(1);
		exit(EXIT_FAILURE);
	}
	if (ptr->next == NULL)
	{
		*stack = NULL;
	}
	else
	{
		ptr2 = ptr2->next;
		ptr2->prev = NULL;
		*stack = ptr2;
		ptr = NULL;
	}
}

