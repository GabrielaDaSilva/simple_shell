#include "shell_header.h"
/**
 * execute_command - Executes system calls
 * @cmd_struct: command structure
 * @path_new: path of file
 * Return: no return
 */

void execute_command(cmd *cmd_struct, char *path_new)
{
	pid_t child_pid;

	if (file_checker(path_new))
	{
		while ((child_pid = fork()) < 0)
		{
			perror("fork error");
			exit(1);
		}
		if (child_pid == 0)
		{
			if (execve(path_new, cmd_struct->argv, cmd_struct->env) < 0)
			{
				perror(cmd_struct->home);
				exit(1);
			}
		}
		else
		{
			wait(&child_pid);
		}
	}
	else if (execve(path_new, cmd_struct->argv, cmd_struct->env) < 0)
	{
		perror(cmd_struct->home);
	}
}
