#include "monty.h"

/**
 * push_m - push an integer onto the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: script line number
 * Return: void
 */
void push_m(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;
	
	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || isdigit(arg))
	{
		dprintf(STDOUT_FILENO,
				"L%u: usage: push integer\n",
				line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	if (!add_node(stack, n))
	{
		dprintf(STDOUT_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.stack_len++;
}
