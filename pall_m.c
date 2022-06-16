#include "monty.h"

/**
 * pall_m - print all values on `stack' starting from the top
 * @stack: double pointer to head of stack
 * @line_number: line number
 * Return: void
 */
void pall_m(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *node;
	(void)line_number;

	node = *stack;
	for (i = 0; node; i++)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}
