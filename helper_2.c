#include "monty.h"

/**
 * add_node_end - adds node at the end
 * @head: pointer to the node
 * @value: the value that is added
 */
void add_node_end(stack_t **head, int value)
{
	stack_t *ptr = *head;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		exit(EXIT_FAILURE);

	if (ptr == NULL)
	{
		new_node->n = value;
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
		return;
	}

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	new_node->n = value;
	new_node->next = NULL;

	ptr->next = new_node;
	new_node->prev = ptr;
}

/**
 * add_node_beg - adds node at the beginning
 * @head: pointer to the node
 * @value: the value that is added
 */
void add_node_beg(stack_t **head, int value)
{
	stack_t *ptr = *head;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(1);
		exit(EXIT_FAILURE);
	}

	if (ptr == NULL)
	{
		new_node->n = value;
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		new_node->n = value;
		new_node->next = ptr;
		ptr->prev = new_node;
		new_node->prev = NULL;
		*head = new_node;
	}
}

/**
 * free_stack - free all the allocated memory
 * @value: 1 or 0
 * Return: void
 */
void free_stack(int value)
{
	int i;

	if (data.line)
	{
		free(data.line);
		data.line = NULL;
		if (!data.word)
			return;
		for (i = 0; data.word[i]; i++)
		{
			free(data.word[i]);
		}
		free(data.word);
		data.word = NULL;
	}

	if (value)
	{
		if (data.stack)
		{
			free_list(data.stack);
			data.stack = NULL;
		}
		if (data.file)
		{
			fclose(data.file);
			data.file = NULL;
		}
	}
}

/**
 * free_list - frees the allocated memory for the stack
 * @head: pointer to the node
 * Return: void
 */
void free_list(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
