#include "monty.h"

/**
* pops - adds a node
* @stack: the new node
* @line: the line number
*
* Description: prints the whole stack
*/

void pops(stack_t **stack, unsigned int line)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	if (tmp->next == NULL)
	{
		free(tmp);
		*stack = NULL;
	}
	else
	{
		tmp->next->prev = NULL;
		*stack = tmp->next;
		free(tmp);
	}
}
