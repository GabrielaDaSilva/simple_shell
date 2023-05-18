#include "shell_header.h"
#include <stdio.h>
/**
 * is_builtin - checks if command is a built in command.
 * @command: command to be checked.
 * Return: function pointer
 */
void (*is_builtin(char *command))(cmd * cmd_struct)
{
	int count;
	char *builtin_command;

	builtins_table my_builtins[] = {
		{"exit", my_exit},
		{"env", my_env},
		{NULL, NULL}
	};
	for (count = 0; my_builtins[count].instruction; count++)
	{
		builtin_command = my_builtins[count].instruction;
		if (_strcmp(builtin_command, command) == 0)
		{
			return (my_builtins[count].func);
		}
	}
	return (NULL);
}
