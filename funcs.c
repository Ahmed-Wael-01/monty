#include "monty.h"

/**
 *selector - selects the right function
 *@line: line number
 *@arg: the instruction
 *@lines: the value
 *
 *Description: it selects a function from the ops
 */

void selector(int line, char **arg, char **lines)
{
	int i, flag = 0;

	instruction_t funcs[] = {
		{"push", add_stack},
		{"pall", print_stack},
		{"pint", pints},
		{"pop", pops},
		{"swap", swaps},
		{"add", adds},
		{"nop", nop},
		{"sub", subs},
		{NULL, NULL}
	};
	for (i = 0; funcs[i].opcode != NULL; i++)
	{
		if (_strcmp(funcs[i].opcode, arg[0]) == 0)
		{
			flag = 1;
			func_call(line, funcs[i], arg, lines);
			break;
		}
	}
	if (flag == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, arg[0]);
		shfree(arg), shfree(lines);
		free_dlistint(head);
		exit(EXIT_FAILURE);
	}
}

/**
 *func_call - selects the right function
 *@line: line number
 *@operand: the instruction
 *@arg: the value
 *@lines: the whole lines
 *
 *Description: it selects a function from the ops
 */

void func_call(int line, instruction_t operand, char **arg, char **lines)
{
	int j;
	stack_t *node;

			if (_strcmp(operand.opcode, "push") == 0)
			{
				if (arg[1] == NULL || arg[2] != NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line);
					shfree(arg), shfree(lines);
					free_dlistint(head);
					exit(EXIT_FAILURE);
				}
				for (j = 0; arg[1][j] != '\0'; j++)
				{
					if (arg[1][0] == '-' && j == 0)
						continue;
					if (_isdigit(arg[1][j]) == 0)
					{
						fprintf(stderr, "L%d: usage: push integer\n", line);
						shfree(arg), shfree(lines);
						free_dlistint(head);
						exit(EXIT_FAILURE);
					}
				}
				node = malloc(sizeof(stack_t));
				node->n = _atoi(arg[1]);
				operand.f(&node, line);
			}
			else if (_strcmp(operand.opcode, "pint") == 0 && head == NULL)
			{
				shfree(arg), shfree(lines);
				free_dlistint(head);
				operand.f(&head, line);
			}
			else
				operand.f(&head, line);
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
	if (*stack == NULL)
		return;
	curr = *stack;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
* pints - adds a node
* @stack: the new node
* @line: the line number
*
* Description: prints the whole stack
*/

void pints(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

