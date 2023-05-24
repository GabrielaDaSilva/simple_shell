#include "Shell.h"
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point
 * @argv: pointer to arg in arr
 * @argc: num of argc
 * Return: void
 */

int main(int argc, char **argv)
{
	int num_read;
	char *cmmd;
	const char *prompt = "Shell> ";
	size_t num_bytes = sizeof(prompt), len_lin = 1024;

	if (argc > 1)
	{
		exit(0);
	}
	while (1)
	{
		cmmd = malloc(100);
		write(STDIN_FILENO, prompt, num_bytes);
		num_read = getline(&cmmd, &len_lin, stdin);
		if (num_read == -1)
		{
			free(cmmd);
			return (0);
		}
		else if (num_read > 1)
		{
			cmmd[num_read - 1] = '\0';
			if (cmmd)
				_npars(cmmd, environ, argv[0]);
			free(cmmd);
		}
	}
}
