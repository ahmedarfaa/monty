#include "monty.h"

/**
* main - monty code interpreter
* @argc: n.f args
* @argv: file location
* Return: 0
*/
alx_t alx = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
	char *buffer;
	FILE *file;
	size_t size = 0;
	ssize_t read = 1;
	stack_t *st = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	alx.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read > 0)
	{
		buffer = NULL;
		read = getline(&buffer, &size, file);
		alx.buf = buffer;
		count++;
		if (read > 0)
		{	_execute(buffer, &st, count, file);	}
		free(buffer);
	}
	_free_stack(st);
	fclose(file);
	return (0);
}
