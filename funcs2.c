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
/**
* swaps - adds a node
* @stack: the new node
* @line: the line number
*
* Description: prints the whole stack
*/

void swaps(stack_t **stack, unsigned int line)
{
	stack_t *node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	node = (*stack)->next;
	(*stack)->next = node->next;
	if (node->next != NULL)
		node->next->prev = *stack;
	node->next = *stack;
	(*stack)->prev = node;
	node->prev = NULL;
	*stack = node;
}

/**
* adds - adds a node
* @stack: the new node
* @line: the line number
*
* Description: prints the whole stack
*/

void adds(stack_t **stack, unsigned int line)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - nothing
 * @stack: head
 * @line: line number
 *
 * Description: nothing
 */

void nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

/**
 * subs - subs two nodes
 * @stack: head
 * @line: line number
 *
 * Description: it subs two numbers
 */
void subs(stack_t **stack, unsigned int line)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
