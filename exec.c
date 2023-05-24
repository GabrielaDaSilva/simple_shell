#include "shell.h"

/**
 *  _run - runs sys call
 * @newpath: new path
 * @cmd_struct: The cmd Struct
 * Return: void
 */

void _run(cmd *cmd_struct, char *newpath)
{
	pid_t my_pid;

	if (file_validate(newpath))
	{
		while ((my_pid = fork()) < 0)
		{
			perror("fork err");
			exit(1);
		}
		if (my_pid == 0)
		{
			if (execve(newpath, cmd_struct->argv, cmd_struct->env) < 0)
			{
				perror(cmd_struct->home);
				exit(1);
			}
		}
		else
		{
			wait(&my_pid);
		}
	}
	else if (execve(newpath, cmd_struct->argv, cmd_struct->env) < 0)
	{
		perror(cmd_struct->home);
	}
}

