#include "monty.h"

/**
 * functions - a function pointer
 * @str: double pointer as an argument to the function
 * Return: void
 */
void (*functions(char **str))(stack_t **, unsigned int)
{
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", division},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"nop", nop},
		{"stack", stack_flag},
		{"queue", queue_flag},
		{NULL, NULL}};

	int i;

	for (i = 0; instruction[i].opcode; i++)
	{
		if (strcmp(str[0], instruction[i].opcode) == 0)
		{
			return (instruction[i].f);
		}
	}
	return (NULL);
}

/**
 * stack_flag - to flag so that to know which argument passed
 * @stack: pointer to the node
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
 * @stack: pointer to the node
 * @line: number of the line in the file
 */
void queue_flag(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
	data.flag = 1;
}
