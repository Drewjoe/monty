#include "monty.h"

/**
 * pall_m - print all values on `stack' starting from the top
 * @stack: double pointer to head of stack
 * @line_number: line number
 * Return: void
 */
void pall_m(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	if (!node)
		return;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
