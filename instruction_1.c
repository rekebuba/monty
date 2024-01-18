#include "monty.h"

/**
 * push - used to insert the content on the stack/queue
 * @head: pointer to the node
 * @line: number of the line in the file
 */
void push(stack_t **head, unsigned int line)
{
	(void)line;
	data.value = convert(data.word[1]);
	if (data.flag == 0)
		add_node_beg(head, data.value);
	else if (data.flag == 1)
		add_node_end(head, data.value);
}

/**
 * pall - used to list the content on the stack/queue
 * @stack: pointer to the node
 * @line: number of the line in the file
 * Return: void
 */

void pall(stack_t **stack, unsigned int line)
{
	stack_t *ptr = *stack;
	(void)line;
	while (ptr != NULL)
	{
		fprintf(stdout, "%d\n", ptr->n);
		ptr = ptr->next;
	}
}

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
	printf("%d\n", ptr->n);
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
	int count = nod_len(stack);

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
