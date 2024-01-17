#include "monty.h"

char *args[3];

/**
 * main - main file for the monty program
 * @argc: size of arguments
 * @argv: pointer to array of arguments
 * Return: 0 - always successful
 */
int main(int argc, char **argv)
{
	FILE *file;
	char line[100];
	char *token;
	int i = 0;
	unsigned int line_num = 0;
	stack_t *head = malloc(sizeof(stack_t));

	if (head == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (argv[1] == NULL || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r"); /* attempt to open file */
	if (file == NULL) /* validate file */
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((fgets(line, sizeof(line), file)) != NULL)
	{
		line_num++;
		token = strtok(line, " \n\t\a\r;:");
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " \n\t\a\r;:");
		}
		args[i] = NULL;
		if (op_func_select() == NULL)
		{
			fprintf(stderr, "%u: unknown instruction %s\n", line_num, args[0]);
			exit(EXIT_FAILURE);
		}
		else
			op_func_select()(&head, line_num);
	}
	fclose(file);
	return (0);
}
