#include "monty.h"

/**
 * stack_m - sets the format of the data to a stack (LIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 * Return: void
 */
void stack_m(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.queue = STACK;
}

/**
 * queue_m - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 * Return: void
 */
void queue_m(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	var.queue = QUEUE;
}

/**
 * add_node_lifo - add lifo
 * @stack: head of stack
 * @n_node: the node to add
 */
void add_node_lifo(stack_t **stack, stack_t *n_node)
{
	n_node->prev = NULL;
	n_node->next = *stack;
	if (*stack)
		(*stack)->prev = n_node;
	*stack = n_node;
}

/**
 * add_node_fifo - add node fifo
 * @stack: head of stack
 * @n_node: the node to add
 */
void add_node_fifo(stack_t **stack, stack_t *n_node)
{
	stack_t *tmp = *stack;

	n_node->next = NULL;
	if (!*stack)
	{
		n_node->prev = NULL;
		*stack = n_node;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = n_node;
		n_node->prev = tmp;
	}
}
