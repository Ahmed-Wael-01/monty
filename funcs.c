#include "monty.h"

/**
 *select - selects the right function
 *@line: line number
 *@ins: the instruction
 *@arg: the value
 *
 *Description: it selects a function from the ops
 */

void select(int line, char *ins, char *arg)
{
	int i, j, flag = 0;
	stack_t *node;

	instruction_t funcs[] = {
		{"push", add_stack},
		{"pall", print_stack},
		{NULL, NULL}
	};
	for (i = 0; funcs[i].opcode != NULL; i++)
	{
		if (_strcmp(funcs[i].opcode, ins) == 0)
		{
			flag = 1;
			if (i == 0)
			{
				for (j = 0; arg[j] != '\0'; j++)
				{
					if (arg[0] == '-' && j == 0)
						continue;
					if (_isdigit(arg[j]) == 0)
					{
						fprintf(stderr, "L%d: usage: push integer\n", line);
						exit(EXIT_FAILURE);
					}
				}
				node = malloc(sizeof(stack_t));
				node->n = _atoi(arg);
				funcs[i].f(&node, line);
			}
			else
				funcs[i].f(&head, line);
		}
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, ins);
		exit(EXIT_FAILURE);
	}
}

/**
* add_stack - adds a node
* @stack: the new node
* @line: the line number
*
* Description: adds a new node
*/

void add_stack(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (head == NULL && line > 0)
	{
		head = *stack;
		head->prev = NULL;
		head->next = NULL;
	}
	else
	{
		tmp = head;
		head = *stack;
		head->prev = NULL;
		head->next = tmp;
		tmp->prev = head;
	}
}

/**
* print_stack - adds a node
* @stack: the new node
* @line: the line number
*
* Description: prints the whole stack
*/

void print_stack(stack_t **stack, unsigned int line)
{
	stack_t *curr;

	(void)line;
	for (curr = *stack; curr != NULL; curr = curr->next)
		printf("%d\n", curr->n);
}
