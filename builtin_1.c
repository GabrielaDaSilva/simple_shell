#include "shell_header.h"
/**
 * exit_func- exits the shell
 * @cmd_struct: Structure containing args and env
 */

void exit_func(cmd *cmd_struct)
{
	int ncount = 0;

	while (cmd_struct->argv[ncount])
	{
		free(cmd_struct->argv[ncount]);
		ncount++;
	}
	free(cmd_struct);
	exit(0);
}

/**
 * env_func - prints environment variables
 * @cmd_struct: structure containing args and env
 */
void env_func(cmd *cmd_struct)
{
	int ncount = 0;
	size_t environ_bytes, letter_count;
	char new_line = '\n';

	while (cmd_struct->env[ncount])
	{
		letter_count = 0;
		while (cmd_struct->env[ncount][letter_count])
		{
			letter_count++;
		}
		environ_bytes = letter_count;
		write(STDOUT_FILENO, cmd_struct->env[ncount], environ_bytes);
		ncount++;
		write(STDOUT_FILENO, &new_line, 1);
	}
}
