#include "monty.h"

/**
 * push_m - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 * Return: void
 */
void push_m(stack_t **stack, unsigned int line_number)
{
	stack_t *n_node;
	(void)line_number;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
		handle_error(4);
	if (_isdigit(info.arg[1]) > 0)
		handle_error(5);
	n_node->n = atoi(info.arg[1]);
	if (info.type == STACK)
	{
		add_node(stack, n_node);
	}
}
