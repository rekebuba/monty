#include "main.h"
#include "lists.h"

data_t data = {NULL, NULL, NULL, NULL, 0, 0};

int main(int argc, char **args)
{
    requirement(argc, args);
    return (EXIT_SUCCESS);
}

void requirement(int argc, char **args)
{
    void (*code_func)(stack_t **, unsigned int);
    size_t len = 0;
    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    data.file = fopen(args[1], "r");
    if (!data.file)
    {
        printf("Error: Can't open file %s\n", args[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&(data.line), &len, data.file) != EOF)
    {
        data.line_count++;
        removeWhiteSpace(data.line);
        data.word = tokenize(data.line);
        if (data.word[0] == NULL || data.word[0][0] == '#')
		{
			free_stack(0);
			continue;
		}
        code_func = functions(data.word);
        if (!code_func)
        {
            printf("L%d: unknown instruction %s\n", data.line_count, data.word[0]);
            free_stack(1);
            exit(EXIT_FAILURE);
        }
        code_func(&(data.stack), data.line_count);
        free_stack(0);
    }
    free_stack(1);
}
void free_stack(int value)
{
    if (data.line)
    {
        free(data.line);
        data.line = NULL;
        if (!data.word)
            return;
        for (int i = 0; data.word[i]; i++)
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

void pall(stack_t **stack, unsigned int line)
{
    stack_t *ptr = *stack;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->n);
        ptr = ptr->next;
    }
}
void push(stack_t **head, unsigned int line)
{
    stack_t *new;
    data.value = convert(data.word[1]);
    //add_node_beg(head, data.value);
    if (data.file == 0)
		add_node_beg(head, data.value);
	//else if (data.file == 1)
		//add_dnodeint_end(head, data.value);
        
}

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
