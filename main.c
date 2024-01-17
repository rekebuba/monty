#include "main.h"
#include "lists.h"

data_t data = {NULL, NULL, NULL, NULL, 0, 0};

int main(int argc, char **args)
{
    requirement(argc, args);
}

void requirement(int argc, char **args)
{
    void (*code_func)(stack_t **, unsigned int);
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
    char buffer[100];
    data.word = malloc(1020 * sizeof(char *));

    while (fgets(buffer, sizeof(buffer), data.file) != NULL)
    {
        data.line_count++;
        removeWhiteSpace(buffer);
        data.word = tokenize(buffer);
        code_func = functions(data.word);
        if (!code_func)
        {
            printf("L%d: unknown instruction %s\n", data.line_count, data.word[0]);
            exit(EXIT_FAILURE);
        }
        code_func(&(data.stack), data.line_count);
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
    data.value = convert(data.word[1]);
    add_node_beg(head, data.value);
}

void add_node_beg(stack_t **head, int value)
{
    stack_t *ptr = *head;
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error: malloc failed\n");
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
