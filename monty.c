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
	char line[200];
	unsigned int line_num = 0;
	stack_t *head = NULL; /* empty stack */

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
		if (strlen(line) == 0) /*skip empty lines*/
			continue;
		split_line_args(line); /*split line argument into variable args*/

		if (*args == NULL) /*skip empty lines having delimiters */
			continue;
		if (strcmp(args[0], "#") == 0)
			continue;
		if (op_func_select() == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_num, args[0]);
			exit(EXIT_FAILURE);
		}
		else
			op_func_select()(&head, line_num);
	}
	free_dlistint(head);
	fclose(file);
	return (0);
}

/**
 * split_line_args - split line arguments
 * @line: opcode line in file
 * Return: Nothing
 */
void split_line_args(char *line)
{
	int i;
	char *token;

	token = strtok(line, " \n\t\a\r;:");
	i = 0;
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " \n\t\a\r;:");
		i++;
	}
	args[i] = NULL;
}
