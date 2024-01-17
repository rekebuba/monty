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
        printf("%s\n", data.word[0]);
        code_func(&(data.stack), data.line_count);
    }
}

void pall(stack_t **stack, unsigned int line)
{
    return;
}
void push(stack_t **stack, unsigned int line)
{
    data.value = convert(data.word[1]);
    printf("%d\n", data.value);

    return;
}

void removeWhiteSpace(char *str)
{
    char *p1 = str; /* pointer to iterate through the input string */
    char *p2 = str; /* pointer to write the non-space characters to */
    bool space = false;

    while (isspace(*p1))
    {
        p1++;
    }

    while (*p1 != '\0')
    {
        if (isspace(*p1))
        {
            if (!space)
            {
                *p2 = *p1;
                p2++;
                space = true;
            }
        }
        else
        {
            *p2 = *p1;
            p2++;
            space = false;
        }
        p1++;
    }

    if (isspace(*(p2 - 1)))
    {
        *(p2 - 1) = '\0';
    }

    *p2 = '\0';
}
