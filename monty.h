#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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

extern stack_t *head;

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

int _atoi(char *s);
int _isdigit(int c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int line_count(char *str);
int line_len(char *str);
char **line_breaker(char *str);
int word_cnt(char *str);
int word_len(char *str);
char **splice(char *str);
void selector(int line, char **arg, char **lines);
void func_call(int line, instruction_t operand, char **arg, char **lines);
void add_stack(stack_t **stack, unsigned int line);
void print_stack(stack_t **stack, unsigned int line);
void pints(stack_t **stack, unsigned int line);
void pops(stack_t **stack, unsigned int line);
void swaps(stack_t **stack, unsigned int line);
void adds(stack_t **stack, unsigned int line);
void nop(stack_t **stack, unsigned int line);
void subs(stack_t **stack, unsigned int line);
void shfree(char **str);
void free_dlistint(stack_t *head);

#endif
