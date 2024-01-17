#include "main.h"
#include "lists.h"

/**
 * functions - a function pointer
 * 
 * @str: double pointer as an argument to the function
 * Return: void 
 */
void (*functions(char **str))(stack_t **, unsigned int)
{
    instruction_t instruction [] = {
        {"push", push},
        {"pall", pall},
        {"stack", stack_flag},
		{"queue", queue_flag},
        {NULL, NULL}
    };
    for (int i = 0; instruction[i].opcode; i++)
        {
            if (strcmp(str[0], instruction[i].opcode) == 0)
            {
                return (instruction[i].f);
            }
        }
    return (NULL);
}
