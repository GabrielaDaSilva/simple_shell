#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell_header.h"

/**
 * parse - Tokenizes the string (splits words based on
 * space character) and sends to eval.
 * @command: command to be tokenized.
 * @env: global environment
 * @home: filename of executable
 * Return: no return
*/

void parse(char *command, char **env, char *home)
{
	cmd *cmd_struct = 0;
	char *token;
	const char *delim = " ";

	cmd_struct->argc = 0;
	token = strtok(command, delim);
	(cmd_struct->argv)[cmd_struct->argc] = token;

	while (token != NULL)
	{
		cmd_struct->argc++;
		token = strtok(NULL, delim);
		(cmd_struct->argv)[cmd_struct->argc] = token;
	}
	cmd_struct->env = env;
	cmd_struct->home = home;

	if (cmd_struct->argc)
	{
		eval(cmd_struct);
		free(cmd_struct);
	}
	else
	{
		exit(0);
	}
}
