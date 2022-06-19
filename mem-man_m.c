#include "monty.h"
/**
 * free_info - free data
 */
void free_info(void)
{
	free(info.cmd);
	info.cmd = NULL;
	free(info.arg);
	info.arg = NULL;
	fclose(info.fp);
}

/**
 * free_list - free list
 * @stack: stack or queue
 */
void free_list(stack_t *stack)
{
	stack_t *node;

	while (stack)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}

/**
 * free_stack - frees the stack on exit
 * @status: exit status
 * @arg: double pointer to the stack
 * Return: void
 */
void free_stack(int status, void *arg)
{
	stack_t **stack;
	stack_t *next;

	(void)status;

	stack = (stack_t **)arg;
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	var.stack_len = 0;
}

/**
 * m_fs_close - close file stream
 * @status: status passed to exit
 * @arg: pointer to file stream
 * Return: void
 */
void fs_close_m(int status, void *arg)
{
	FILE *fs;

	(void)status;

	fs = (FILE *) arg;
	fclose(fs);
}
