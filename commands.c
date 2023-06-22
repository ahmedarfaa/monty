#include "monty.h"
/**
 * _pall - a function that prints the stack
 * @head: stack head
 * @count: number of lines
*/
void _pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == 0)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
/**
 * _pint - a fucntion prints the top
 * @head: stack head
 * @count: number of lines
*/
void _pint(stack_t **head, unsigned int count)
{
	if (*head == 0)
		{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(alx.file);
		free(alx.buf);
		_free_stack(*head);
		exit(EXIT_FAILURE);
		}
	printf("%d\n", (*head)->n);
}

/**
 * _pop - a function that prints the top
 * @head: stack head
 * @count: number of lines
*/

void _pop(stack_t **head, unsigned int count)
{
	stack_t *h;

	if (*head == 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(alx.file);
		free(alx.buf);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
