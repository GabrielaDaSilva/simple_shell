#include <stdio.h>
#include "Shell.h"

/**
 * is_builtin - validate to see if cmd is a builtin
 * @command: Cmd to be validated.
 * Return: Pointer(func)
 */
void (*is_builtin(char *command))(cmd * cmd_struct)
{
	int calculate;
	char *cmd_Inbuilt;

	log_Builtin my_builtins[] = {
		{"exit", ext_out},
		{"env", env_cust},
		{NULL, NULL}
	};
	for (calculate = 0; my_builtins[calculate].order; calculate++)
	{
		cmd_Inbuilt = my_builtins[calculate].order;
		if (comp_string(cmd_Inbuilt, command) == 0)
		{
			return (my_builtins[calculate].func);
		}
	}
	return (NULL);
}

