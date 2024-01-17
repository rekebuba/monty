#ifndef STACK_AND_QUEUE
#define STACK_AND_QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "main.h"


typedef struct data_s
{
    char *line;
    char **word;
    FILE *file;
    stack_t *stack;
    int line_count;
    int value;
}data_t;

extern data_t data;


void requirement(int argc, char **args);
void push(stack_t **stack, unsigned int line);
int convert(char *str);
char **tokenize(char *str);
int count_word(char *s);
void (*functions(char **str))(stack_t **, unsigned int line_number);
#endif
