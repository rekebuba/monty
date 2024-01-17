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
		free(ptr);
		*stack = NULL;
	}
	else
	{
		ptr2 = ptr2->next;
		ptr2->prev = NULL;
		*stack = ptr2;
		free(ptr);
	}
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: pointer to the node
 * @line: number of the line in the file
 */
void swap(stack_t **stack, unsigned int line)
{
	stack_t *ptr = *stack;
	stack_t *ptr2 = *stack;
	stack_t *temp;
	int count = 0;

	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free_stack(1);
		exit(EXIT_FAILURE);
	}
	ptr2 = ptr2->next;
	ptr = *stack;
	if (count == 2)
	{
		ptr2->next = ptr;
		ptr->prev = ptr2;
		ptr2->prev = NULL;
		ptr->next = NULL;
		*stack = ptr2;
	}
	else
	{
		temp = ptr2->next;
		ptr2->next = ptr;
		ptr2->prev = NULL;
		ptr->prev = ptr2;
		ptr->next = temp;
		*stack = ptr2;
	}
}
