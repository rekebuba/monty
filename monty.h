#ifndef STACK_AND_QUEUE
#define STACK_AND_QUEUE

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>


/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - struct used to follow the program
 * @line: a string used to read line from a file
 * @word: a double pointer to string used to create an array of string
 * @file: a pointer to a file to open the file
 * @stack: a double linked list used for stack and queue
 * @line_count: to count the number of line in a file
 * @value: the value needed to add to the stack or queue
 * @flag: a flag used to specify if the instruction is to implement stack or queue
 */
typedef struct data_s
{
	char *line;
	char **word;
	FILE *file;
	stack_t *stack;
	int line_count;
	int value;
	int flag;
}data_t;

extern data_t data;

/********** main.c **********/
void requirement(int argc, char **args);

/********** instruction_1.c **********/
void push(stack_t **stack, unsigned int line);
void pall(stack_t **stack, unsigned int line);
void pint(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);
void swap(stack_t **stack, unsigned int line);

/********** instruction_2.c **********/
void add(stack_t **stack, unsigned int line);
void sub(stack_t **stack, unsigned int line);
void division(stack_t **stack, unsigned int line);
void mul(stack_t **stack, unsigned int line);
void mod(stack_t **stack, unsigned int line);

/********** instruction_3.c **********/
void pchar(stack_t **stack, unsigned int line);
void pstr(stack_t **stack, unsigned int line);
void rotl(stack_t **stack, unsigned int line);
void rotr(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);

/********** functions.c **********/
void (*functions(char **str))(stack_t **, unsigned int);
void stack_flag(stack_t **stack, unsigned int line);
void queue_flag(stack_t **stack, unsigned int line);

/********** helper_1.c **********/
int nod_len(stack_t **stack);
char **tokenize(char *str);
int convert(char *str);
int count_word(char *s);

/********** helper_2.c **********/
void add_node_end(stack_t **head, int value);
void add_node_beg(stack_t **head, int value);
void free_stack(int value);
void free_list(stack_t *head);

#endif
