#include "monty.h"
#include "main.h"

/**
 * nop - ignores and doesn’t do anything.
 * @stack: pointer to the node
 * @line: number of the line in the file
 */
void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
	return;
}

/**
 * sub - subtracts the top two elements of the stack
 * @stack: pointer to the node
 * @line: number of the line in the file
 */
void sub(stack_t **stack, unsigned int line)
{
	stack_t *ptr = *stack;
	int count = nod_len(stack);
	int sub = 0;

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		free_stack(1);
		exit(EXIT_FAILURE);
	}

	sub = ptr->next->n - ptr->n;

	pop(stack, line);
	ptr = *stack;
	ptr->n = sub;
}


void division(stack_t **stack, unsigned int line)
{
	stack_t *ptr = *stack;
	int count = nod_len(stack);
	int div = 0;

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		free_stack(1);
		exit(EXIT_FAILURE);
	}

	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free_stack(1);
		exit(EXIT_FAILURE);
	}
	div = ptr->next->n / ptr->n;
	pop(stack, line);
	ptr = *stack;
	ptr->n = div;
}
