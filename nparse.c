#include "Shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _npars - Tokenizes str, then processes to eval
 * @home: The exec file
 * @env: The Global envir
 * @command: cmd that will be tokenized
 * Return: void
 */

void _npars(char *command, char **env, char *home)
{
	cmd *cmd_struct = malloc(sizeof(command));
	char *my_token;
	const char *pDelim = " ";

	cmd_struct->argc = 0;

	my_token = strtok(command, pDelim);

	(cmd_struct->argv)[cmd_struct->argc] =  my_token;
	while (my_token != NULL)
	{
		cmd_struct->argc++;
		my_token = strtok(NULL, pDelim);
		(cmd_struct->argv)[cmd_struct->argc] =  my_token;
	}
	cmd_struct->env = env;
	cmd_struct->home = home;

	if (cmd_struct->argc)
	{
		result_ev(cmd_struct);
		free(cmd_struct);
	}
	else
	{
		exit(0);
	}
}
