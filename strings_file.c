#include "shell_header.h"
/**
 * _strcmp - Compares 2 strings
 * @string1: String 1 pointer
 * @string2: String 2 pointer
 * Return: -15 - for string1 > string2, 15 for string2 > string1, 0 for string1 = string2
 */

int _strcmp(char *string1, char *string2)
{
	int i = 0, op = 0;

	while (op == 0)
	{
		if (!string1[i] && !string2[i])
		{
			break;
		}
		op = string1[i] - string2[i];
		i++;
	}

	return (op);
}

/**
 * get_env_varable - gets environment variable.
 * @environment: environment parameter.
 * @variable: variable parameter.
 * Return: environment variable.
 */

char *get_env_variable(char **environment, char *variable)
{
	int ncount = 0;
	char *env_variable, *ret_variable;

	while ((env_variable = environment[ncount]) != NULL)
	{
		ret_variable = check_variable(env_variable, variable);
		if (ret_variable)
			return (ret_variable);
		ncount++;
	}
	return (NULL);
}

/**
 * check_variable - checks environment variable.
 * @env_variable: environment variable parameter.
 * @variable: variable parameter.
 * Return: environmen variable
 */

char *check_variable(char *env_variable, char *variable)
{
	int a_letter = 0;

	while (variable[a_letter] != 0)
	{
		if (env_variable[a_letter] != variable[a_letter])
		{
			return (NULL);
		}
		a_letter++;
	}
	return (&env_variable[a_letter + 1]);
}

/**
 * path_handle - handles PATH.
 * @cmd_struct: command structure.
 * @pathcheck: filename for command
 * Return: void.
 */

char *path_handle(command *cmd_struct, char *pathcheck)
{
	int count_environ = 0, count_letter = 0;
	char *path_new, *path_environ;

	path_environ = get_env_variable(cmd_struct->env, "PATH");
	if (path_environ)
	{
		while (path_environ[count_environ] != 0 && cmd_struct->argv[0][0] != '.'
		&& cmd_struct->argv[0][0] != '/')
		{
			if (pathcheck[count_letter] == path_environ[count_environ])
			{
				count_letter++;
				if (count_letter == 4)
				{
					path_new = _strcat(pathcheck, cmd_struct->argv[0]);
					return (path_new);
				}
			}
			else
			{
				count_letter = 0;
			}
			count_environ++;
		}
	}
	return (cmd_struct->argv[0]);
}

/**
 * _strcat - Copies string from source
 * pointer and appends to destination pointer
 * @dest: String pointer for destination
 * @src: String pointer for source
 * Return: dest - string pointer to destination
 */

char *_strcat(char *dest, char *src)
{
	int len_dest = 0, len_src = 0;

	while (dest[len_dest] != 0)
	{
		len_dest++;
	}
	while (src[len_src] != 0)
	{
		dest[len_dest] = src[len_src];
		len_dest++;
		len_src++;
	}
	dest[len_dest] = 0;
	return (dest);
}
