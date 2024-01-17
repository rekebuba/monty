#ifndef STACK_AND_QUEUE
#define STACK_AND_QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>

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
void pall(stack_t **stack, unsigned int line);
int convert(char *str);
char **tokenize(char *str);
int count_word(char *s);
void (*functions(char **str))(stack_t **, unsigned int);
void removeWhiteSpace(char *str);
void add_node_beg(stack_t **head, int value);
void free_stack(int value);
void free_list(stack_t *head);

#endif
