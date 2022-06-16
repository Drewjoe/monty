#ifndef MONTY_H
#define MONTY_H

#define STACK 1
#define QUEUE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct var_s - struct to contain the main variables of the Monty interpreter
 * @queue: flag to determine if in stack vs queue mode
 * @stack_len: length of the stack
 */
typedef struct var_s
{
	int queue;
	size_t stack_len;
} var_t;

/* global struct to hold flag for queue and stack length */
extern var_t var;

/**
 * struct error - print error to stderr
 * @out: error code
 * @error_type:function to handle error
 */
typedef struct error
{
	int out;
	void (*error_type)(void);
} error_t;

/**
 * struct info_s - data from monty file
 * @cmd: line from file
 * @arg: argument to excute
 * @l_number: line number
 * @fp: file descriptor
 * @fn: file name
 * @type: QUEUE STACK
 * Description: Information about the commands in the monty file
 */
typedef struct info_s
{
	char *cmd;
	char **arg;
	char *fn;
	int l_number;
	FILE *fp;
	int type;
} info_t;
extern info_t info;

/* Error-Handler */
void handle_err(int code);
void malloc_fail(void);
void monty_usage(void);
void push_use(void);
void unknown_command(void);
void file_perm(void);
void pint_err(void);
void pop_err(void);
void swap_err(void);
void add_err(void);
void sub_err(void);
void div_err(void);
void _zero(void);
void mul_err(void);
void mod_err(void);
void pchar_err(void);
void pchar_err_2(void);


void get_op(char *op, stack_t **stack, unsigned int line_number);
void push_m(stack_t **stack, unsigned int line_number);
void push2_m(stack_t **stack, int n);
void pall_m(stack_t **stack, unsigned int line_number);
void pint_m(stack_t **stack, unsigned int line_number);
void pop_m(stack_t **stack, unsigned int line_number);
void swap_m(stack_t **stack, unsigned int line_number);
void add_m(stack_t **stack, unsigned int line_number);
void nop_m(stack_t **stack, unsigned int line_number);
void sub_m(stack_t **stack, unsigned int line_number);
void mul_m(stack_t **stack, unsigned int line_number);
void div_m(stack_t **stack, unsigned int line_number);
void mod_m(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack_m(stack_t **stack, unsigned int line_number);
void queue_m(stack_t **stack, unsigned int line_number);
void pchar_m(stack_t **stack, unsigned int line_number);
void pstr_m(stack_t **stack, unsigned int line_number);
void free_stack(int status, void *arg);
void fs_close_m(int status, void *arg);
void free_lineptr(int status, void *arg);
stack_t *add_node(stack_t **stack, const int n);
void add_node_fifo(stack_t **stack, stack_t *n_node);

#endif /* MONTY_H */
