#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell_header.h"
/**
 * parse_func - Tokenizes the string (splits words based on
 * space character) and sends to eval.
 * @a_command: command to be tokenized.
 * @env: global environment
 * @home: filename of executable
 * Return: no return
 */

void parse_func(char *a_command, char **env, char *home)
{
	command *cmd_struct = malloc(sizeof(command));
	char *tokenize;
	const char *deliminater = " ";

	cmd_struct->argc = 0;
	/* Tokenize command string */
	tokenize = strtok(a_command, deliminater);
	/* Add token to argv list for execve */
	(cmd_struct->argv)[cmd_struct->argc] = tokenize;
	while (tokenize != NULL)
	{
		cmd_struct->argc++;
		tokenize = strtok(NULL, deliminater);
		(cmd_struct->argv)[cmd_struct->argc] = tokenize;
	}
	cmd_struct->env = env;
	cmd_struct->home = home;
	/**
	 * Ensure Command is tokenized
	 * while (cmd_struct->argv[count] != NULL){
	 * printf("%s\n", cmd_struct->argv[count]);
	 * count++;}
	*/
	if (cmd_struct->argc)
	{
		eval_func(cmd_struct);
		free(cmd_struct);
	}
	else
	{
		exit(0);
	}
}
