#include "monty.h"
/**
 * _push - pushing a node to the stack
 * @head: stack head
 * @count: number of lines
*/
void _push(stack_t **head, unsigned int count)
{
	int n, j = 0, flag = 0;

	if (alx.args)
	{
		if (alx.args[0] == '-')
			j++;
		for (; alx.args[j] != '\0'; j++)
		{
			if (alx.args[j] > 57 || alx.args[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(alx.file);
			free(alx.buf);
			_free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(alx.file);
		free(alx.buf);
		_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(alx.args);
	if (alx.sc == 0)
	_addnode(head, n);
	else
	_addqueue(head, n);
}
