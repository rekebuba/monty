#include "monty.h"
#include "main.h"

/**
 * nop - ignores and doesn’t do anything.
 * @stack: pointer to the node
 * @line: number of the line in the file
 */
void nop(stack_t **stack, unsigned int line)
{
    (void)stack;
    (void)line;
    return;
}
