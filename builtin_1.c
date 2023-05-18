#include "shell_header.h"
/**
 * my_exit - exits the shell
 * @cmd_struct: Structure containing args and env
 */

void my_exit(cmd *cmd_struct)
{
	int count = 0;

	while (cmd_struct->argv[count])
	{
		free(cmd_struct->argv[count]);
		count++;
	}
	free(cmd_struct);
	exit(0);
}

/**
 * my_env - prints environment variables
 * @cmd_struct: structure containing args and env
 */
void my_env(cmd *cmd_struct)
{
	int count = 0;
	size_t nbytes_environ, count_letters;
	char new_line = '\n';

	while (cmd_struct->env[count])
	{
		count_letters = 0;
		while (cmd_struct->env[count][count_letters])
		{
			count_letters++;
		}
		nbytes_environ = count_letters;
		write(STDOUT_FILENO, cmd_struct->env[count], nbytes_environ);
		count++;
		write(STDOUT_FILENO, &new_line, 1);
	}
}
