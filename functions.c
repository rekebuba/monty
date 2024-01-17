#include "main.h"
#include "lists.h"

void (*functions(char **str))(stack_t **, unsigned int line_number)
{
    instruction_t instruction [] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };
    for (int i = 0; instruction[i].opcode; i++)
        {
            if (strcmp(str[0], instruction[i].opcode) == 0)
            {
                printf("were in\n");
                return (instruction[i].f);
            }
        }
    return (NULL);
}
