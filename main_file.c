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
	int nread;
	char *command;
	const char *prompt = "myshell> ";
	size_t nbytes = sizeof(prompt), line_size = 1024;

	if (argc > 1)
	{
		exit(0);
	}
	while (1)
	{
		command = malloc(100);
		write(STDIN_FILENO, prompt, nbytes);
		nread = getline(&command, &line_size, stdin);
		if (nread == -1)
		{
			free(command);
			return (0);
		}
		else if (nread > 1)
		{
			command[nread - 1] = '\0';
			if (command)
				parse(command, environ, argv[0]);
			free(command);
		}
	}
}
