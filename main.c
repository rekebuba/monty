#include "main.h"
#include "lists.h"

data_t data = {NULL, NULL, NULL, NULL, 0, 0};

int main(int argc, char **args)
{
    requirement(argc, args);

    printf("%d\n", argc);
}

void requirement(int argc, char **args)
{
    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    data.file = fopen(args[1], "r");
    void (*code_func)(stack_t **, unsigned int);
    if (!data.file)
    {
        printf("Error: Can't open file %s\n", args[1]);
        exit(EXIT_FAILURE);
    }
    char buffer[100];
    data.word = malloc(1020 * sizeof(char *));

    instruction_t instruction[] = {
        {"push", push},
        {NULL, NULL}};
    while (fgets(buffer, sizeof(buffer), data.file) != NULL)
    {
        data.line_count++;
        data.word = tokenize(buffer);
        void (*functions(char **str))(stack_t **, unsigned int line_number);
        printf("%s\n", data.word[0]);
        for (int i = 0; instruction[i].opcode; i++)
        {
            if (strcmp(data.word[0], instruction[i].opcode) == 0)
            {
                data.value = convert(data.word[1]);
                printf("%d\n", data.value);
                instruction[i].f(&data.stack, data.line_count);
                printf("were in\n");
            }
            else
            {
                printf("L%d: unknown instruction %s\n", data.line_count, data.word[0]);
                exit(EXIT_FAILURE);
            }
        }
    }
}

void push(stack_t **stack, unsigned int line)
{
    return;
}
