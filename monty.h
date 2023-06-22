#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct alx_s - variables -args, file, line content
 * @args: ..
 * @file: ..
 * @buf: ..
 * @sc: ..
 * Description: carries values
 */
typedef struct alx_s
{
	char *args;
	FILE *file;
	char *buf;
	int sc;
}  alx_t;
extern alx_t alx;


int _execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void _pop(stack_t **head, unsigned int counter);
void _swap(stack_t **head, unsigned int counter);
void _add(stack_t **head, unsigned int counter);
void _nop(stack_t **head, unsigned int counter);
void _sub(stack_t **head, unsigned int counter);
void _div(stack_t **head, unsigned int counter);
void _mul(stack_t **head, unsigned int counter);
void _mod(stack_t **head, unsigned int counter);
void _pchar(stack_t **head, unsigned int counter);
void _pstr(stack_t **head, unsigned int counter);
void _rotl(stack_t **head, unsigned int counter);
void _rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void _addnode(stack_t **head, int n);
void _addqueue(stack_t **head, int n);
void _queue(stack_t **head, unsigned int counter);
void _stack(stack_t **head, unsigned int counter);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void _push(stack_t **head, unsigned int number);
void _pall(stack_t **head, unsigned int number);
void _pint(stack_t **head, unsigned int number);
void _free_stack(stack_t *head);

#endif
