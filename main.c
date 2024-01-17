#include "main.h"
#include "lists.h"

data_t data = {NULL, NULL, NULL, NULL, 0, 0, 0};

/**
 * main - the main program
 * 
 * @argc: argument count 
 * @args: arguments passed
 * Return: int
 */
int main(int argc, char **args)
{
    requirement(argc, args);
    free_stack(1);
    return (EXIT_SUCCESS);
}

/**
 *  requirement - requirement needed to execute
 * 
 * @argc: argument count 
 * @args: arguments passed
 * Return: void
 */
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
        /*if (data.word[0] == NULL || data.word[0][0] == '#')
		{
			free_stack(0);
			continue;
		}*/
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
