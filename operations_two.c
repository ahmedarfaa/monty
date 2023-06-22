#include "monty.h"
/**
 * _mod - gets the mod of stack elements
 * @head: head of the stack
 * @count: number of lines
*/
void _mod(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
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
	tot = h->next->n % h->n;
	h->next->n = tot;
	*head = h->next;
	free(h);
}
/**
 * _swap - swaps
 * @head: stack head
 * @count: number of lines
*/
void _swap(stack_t **head, unsigned int count)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(alx.file);
		free(alx.buf);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
