#include "monty.h"

/**
* execute - exec opcode
* @st: head of the linked list of the stack
* @count: ..
* @file: poiner to a monty fi
* @content: ..
* Return: 0 || 1
*/
int _execute(char *content, stack_t **st, unsigned int count, FILE *file)
{
	instruction_t opstack[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop}, {"swap", _swap}, {"add", _add},
				{"nop", _nop}, {"sub", _sub}, {"div", _div},
				{"mul", _mul},	{"mod", _mod}, {"pchar", _pchar},
				{"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
				{"queue", _queue}, {"st", _stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	alx.args = strtok(NULL, " \n\t");
	while (opstack[i].opcode && op)
	{
		if (strcmp(op, opstack[i].opcode) == 0)
		{	opstack[i].f(st, count);
			return (0);
		}
		i++;
	}
	if (op && opstack[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		_free_stack(*st);
		exit(EXIT_FAILURE); }
	return (1);
}
