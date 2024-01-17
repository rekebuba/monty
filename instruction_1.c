#include "lists.h"
#include "main.h"

/**
 * pall - used to list the content on the stack/queue
 * 
 * @stack: pointer to the node
 * @line: number of the line in the file
 * Return: void
 */
void pall(stack_t **stack, unsigned int line)
{
    stack_t *ptr = *stack;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->n);
        ptr = ptr->next;
    }
}

/**
 * push - used to insert the content on the stack/queue
 * 
 * @head: pointer to the node
 * @line: number of the line in the file
 */
void push(stack_t **head, unsigned int line)
{
    stack_t *new;
    data.value = convert(data.word[1]);
    //add_node_beg(head, data.value);
    if (data.flag == 0)
		add_node_beg(head, data.value);
	else if (data.flag == 1)
		add_node_end(head, data.value);
}

/**
 * stack_flag - to flag so that to know which argument passed 
 * 
 * @head: pointer to the node
 * @line: number of the line in the file
 */
void stack_flag(stack_t **stack, unsigned int line)
{
    (void)stack;
	(void)line;
    data.flag = 0;
}

/**
 * queue_flag - to flag so that to know which argument passed 
 * 
 * @head: pointer to the node
 * @line: number of the line in the file
 */
void queue_flag(stack_t **stack, unsigned int line)
{
    (void)stack;
	(void)line;
    data.flag = 0;
}

/**
 * add_node_end - adds node at the end
 * 
 * @stack: pointer to the node
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
 * 
 * @stack: pointer to the node
 * @value: the value that is added
 */
void add_node_beg(stack_t **head, int value)
{
    stack_t *ptr = *head;
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error: malloc failed\n");
        free_stack(1);
        exit(EXIT_FAILURE);
    }

    if (ptr == NULL)
    {
        new_node->n = data.value;
        new_node->next = NULL;
        new_node->prev = NULL;
        *head = new_node;
    }
    else
    {
        new_node->n = data.value;
        new_node->next = ptr;
        ptr->prev = new_node;
        new_node->prev = NULL;
        *head = new_node;
    }
}

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}
