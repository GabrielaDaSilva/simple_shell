#include "shell_header.h"

/**
* execute – Executes system calls
* @cmd_struct: command structure
* @newpath: path of file
* Return: no return
*/

void execute(cmd *cmd_struct, char *newpath)
{
	pid_t child_pid;

	if (check_file(newpath))
	{
		while ((child_pid = fork()) < 0)
		{
			perror("fork error");
			exit(1);
		}

		if (child_pid == 0)
		{
			if (execve(newpath, cmd_struct->argv, cmd_struct->env) < 0)
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
	else if (execve(newpath, cmd_struct->argv, cmd_struct->env) < 0)
	{
		perror(cmd_struct->home);
	}
}
