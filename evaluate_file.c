#include "shell_header.h"
/**
 * eval_func - Determines whether the command is builtin,
 * system or invalid and takes action.
 * @cmd_struct: command structure.
 * Return: void.
 */

void eval_func(command *cmd_struct)
{
	char pathcheck[20] = "/bin/", *path_new;

	void (*func)(command *cmd_struct) = is_built_in(cmd_struct->argv[0]);

	if (func)
	{
		func(cmd_struct);
	}
	else
	{
		path_new = path_handle(cmd_struct, pathcheck);
		execute(cmd_struct, path_new);
	}
}
