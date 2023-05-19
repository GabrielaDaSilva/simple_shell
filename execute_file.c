#include "shell_header.h"
/**
 * execute - executes system calls.
 * @cmd_struct: command structure
 * @newpath: path of file
 * Return: no return
 */

void execute(cmd *cmd_struct, char *new_path)
{
	 struct stat st;
	pid_t child_pid;

	if (stat(new_path, &st) < 0)
	{
		perror(new_path);
		return;
	}
	if (!S_ISREG(st.st_mode))
	{
		fprintf(stderr, "The file %s is not a regular file\n", new_path);
		return;
	}

	if (check_file(new_path))
	{
		while ((child_pid = fork()) < 0)
		{
			perror("fork error");
			exit(1);
		}

		if (child_pid == 0)
		{
			if (execve(new_path, cmd_struct->argv, cmd_struct->env) < 0)
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
	else if (execve(new_path, cmd_struct->argv, cmd_struct->env) < 0)
	{
		perror(cmd_struct->home);
	}
}
