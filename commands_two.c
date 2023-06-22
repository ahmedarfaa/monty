#include "monty.h"
/**
 * _pstr - a function that prints the string
 * @head: stack head
 * @count: line_number
*/
void _pstr(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	while (h)
	{
	if (h->n > 127 || h->n <= 0)
	{
		break;
	}
	printf("%c", h->n);
	h = h->next;
	}
	printf("\n");
}

/**
 * _pchar - a function that prints the char
 * @head: stack head
 * @count: number of lines
*/
void _pchar(stack_t **head, unsigned int count)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(alx.file);
		free(alx.buf);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(alx.file);
		free(alx.buf);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
