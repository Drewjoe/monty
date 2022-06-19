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
		handle_err(4);
	if (isdigit(info.arg[1]) > 0)
		handle_err(5);
	n_node->n = atoi(info.arg[1]);
	if (info.type == STACK)
	{
		add_node_lifo(stack, n_node);
	}
	else
		add_node_fifo(stack, n_node);
}

/**
 * pall_m - print all values on `stack' starting from the top
 * @stack: double pointer to head of stack
 * @line_number: line number
 * Return: void
 */
void pall_m(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}
