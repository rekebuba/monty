#include "main.h"
#include "lists.h"

int main(int argc, char **args)
{
    requirement(argc, args);

    printf("%d\n", argc);
}

void requirement(int argc, char **args)
{
    stack_t *stack = NULL;
    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    FILE *file = fopen(args[1], "r");
    if (!file)
    {
        printf("Error: Can't open file %s\n", args[1]);
        exit(EXIT_FAILURE);
    }
    char buffer[100];
    data.word = malloc(1020 * sizeof(char *));
    int index = 0;
    unsigned int line = 1;
    instruction_t instruction[] = {
        {"push", push},
        {NULL, NULL}
        };
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        data.line_count++;
        buffer[strcspn(buffer, "\n")] = '\0';

        data.line = strtok(buffer, " ");
        while (data.line != NULL)
        {
            data.word[index++] = data.line;
            data.line = strtok(NULL, " ");
        }
        printf("%s\n", data.word[0]);
        for (int i = 0; instruction[i].opcode; i++)
        {
            if (strcmp(data.word[0], instruction[i].opcode) == 0)
            {
                data.value = convert(data.word[1]);
                printf("%d\n", data.value);
                instruction[i].f(&stack, line);
                printf("were in\n");
            }
            else
            {
                printf("L%d: unknown instruction %s\n", line, data.word[0]);
                exit(EXIT_FAILURE);
            }
        }
    }
}

int convert(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if (!isdigit(str[i]))
        {
            printf("L%d: usage: %s integer\n", data.line_count, data.word[0]);
            exit(EXIT_FAILURE);
        }
        i++;
    }

    return (atoi(str));
}

void push(stack_t **stack , unsigned int line)
{
    return;
}
