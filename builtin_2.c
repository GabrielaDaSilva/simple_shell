#include "shell_header.h"
#include <stdio.h>
/**
 * is_a_builtin - checks if command is a built in command.
 * @a_command: command to be checked.
 * Return: function pointer
 */
void (*is_a_builtin(char *a_ommand))(command * cmd_struct)
{
	int ncount;
	char *built_in_command;

	builtins_table the_builtins[] = {
		{"exit", exit_func},
		{"env", env_func},
		{NULL, NULL}
	};
	for (ncount = 0; the_builtins[count].instruction; ncount++)
	{
		built_in_command = the_builtins[ncount].instruction;
		if (_strcmp(built_in_command, a_command) == 0)
		{
			return (the_builtins[ncount].func);
		}
	}
	return (NULL);
}
