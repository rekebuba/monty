#include "main.h"
#include "lists.h"

/**
 * free_stack - free all the allocated memory
 * 
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
 * 
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
