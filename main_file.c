#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "shell_header.h"
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of pointers to arguments
 * Return: void.
 */

int main(int argc, char **argv)
{
	int read;
	char *a_command;
	const char *prompt = "myshell $ ";
	size_t num_bytes = sizeof(prompt), line_size = 1024;

	if (argc > 1)
	{
		exit(0);
	}
	while (1)
	{
		a_command = malloc(100);
		write(STDIN_FILENO, prompt, nbytes);
		read = getline(&a_command, &line_size, stdin);
		if (read == -1)
		{
			free(a_command);
			return (0);
		}
		else if (read > 1)
		{
			a_command[read - 1] = '\0';
			if (a_command)
				parse_func(a_command, environ, argv[0]);
			free(command);
		}
	}
}
