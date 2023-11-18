#include "monty.h"

/**
 * shfree - free
 * @str: a var
 *
 * Description: something
 * Return: 0
 */

void shfree(char **str)
{
	int i;

	for (i = 0; str[i] != NULL; i++)
		free(*(str + i));
	free(str);
}

/**
 * free_dlistint - frees list
 * @head: the head
 *
 * Description: frees a list
 */

void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

