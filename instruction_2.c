#include "lists.h"
#include "main.h"

void pint(stack_t **stack, unsigned int line)
{
    stack_t *ptr = *stack;
    if (ptr == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty", line);
    }
    fprintf(stdout, "%d\n", ptr->n);
}
