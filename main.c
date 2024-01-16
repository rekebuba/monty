#include "main.h"
#include "lists.h"

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
    FILE *file = fopen(args[1], "r");
    if (!file)
    {
        printf("Error: Can't open file %s\n", args[1]);
        exit(EXIT_FAILURE);
    }
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s\n", buffer);
    }
}
