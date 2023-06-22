#include "monty.h"

/**
 * _add - a function that adds stacks
 * @head: head of the list
 * @count:  counter for lines
 *
*/

void _add(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, tot;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(alx.file);
		free(alx.buf);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tot = h->n + h->next->n;
	h->next->n = tot;
	*head = h->next;
	free(h);
}

/**
 * _sub - a function that subs
 *@head: the stack head
 *@count: a counter for lines
 *
*/

void _sub(stack_t **head, unsigned int count)
{
	stack_t *tot;
	int sub, nodes;

	tot = *head;
	for (nodes = 0; tot != NULL; nodes++)
		tot = tot->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(alx.file);
		free(alx.buf);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tot = *head;
	sub = tot->next->n - tot->n;
	tot->next->n = sub;
	*head = tot->next;
	free(tot);
}

/**
 * _mul - multiplying elements in the stack
 * @head: head of the stack
 * @count: count line number
 *
*/

void _mul(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, tot;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(alx.file);
		free(alx.buf);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tot = h->next->n * h->n;
	h->next->n = tot;
	*head = h->next;
	free(h);
}
/**
 * _div - divides elements in the stack
 * @head: head of the stack
 * @count: count line number
 *
*/
void _div(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, tot;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(alx.file);
		free(alx.buf);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(alx.file);
		free(alx.buf);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tot = h->next->n / h->n;
	h->next->n = tot;
	*head = h->next;
	free(h);
}
