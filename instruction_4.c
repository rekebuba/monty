#include "main.h"
#include "monty.h"

void pchar(stack_t **stack, unsigned int line)
{
    stack_t *ptr = *stack;
    char asci;
    if (ptr == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
        free_stack(1);
        exit(EXIT_FAILURE);
    }
    asci = ptr->n;
    if (asci < 'A' || asci > 'z')
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
        free_stack(1);
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "%c\n", asci);
}
