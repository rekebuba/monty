#ifndef STACK_AND_QUEUE
#define STACK_AND_QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "main.h"

#define UP_INDEX -1
#define DO_INDEX -1

typedef struct data_s
{
    char *line;
    char **word;
    int line_count;
    int value;
}data_t;

data_t data = {NULL, NULL, 0, 0};

void requirement(int argc, char **args);
void push(stack_t **stack, unsigned int line);
int convert(char *str);

#endif
