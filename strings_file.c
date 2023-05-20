#include "shell_header.h"
/**
 * _strcmp - Compares 2 strings
 * @s1: String 1 pointer
 * @s2: String 2 pointer
 * Return: -15 - for s1 > s2, 15 for s2 > s1, 0 for s1 = s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, op = 0;

	while (op == 0)
	{
		if (!s1[i] && !s2[i])
		{
			break;
		}
		op = s1[i] - s2[i];
		i++;
	}

	return (op);
}

/**
 * get_env_var - gets environment variable.
 * @environ: environment parameter.
 * @var: variable parameter.
 * Return: environment variable.
 */

char *get_env_var(char **environ, char *var)
{
	int count = 0;
	char *env_var, *ret_var;

	while ((env_var = environ[count]) != NULL)
	{
		ret_var = check_var(env_var, var);
		if (ret_var)
			return (ret_var);
		count++;
	}
	return (NULL);
}

/**
 * check_var - checks environment variable.
 * @env_var: environment variable parameter.
 * @var: variable parameter.
 * Return: environmen variable
 */

char *check_var(char *env_var, char *var)
{
	int letter = 0;

	while (var[letter] != 0)
	{
		if (env_var[letter] != var[letter])
		{
			return (NULL);
		}
		letter++;
	}
	return (&env_var[letter + 1]);
}

/**
 * handle_path - handles PATH.
 * @cmd_struct: command structure.
 * @checkpath: filename for command
 * Return: void.
 */

char *handle_path(cmd *cmd_struct, char *checkpath)
{
	int env_count = 0, letter_count = 0;
	char *new_path, *env_path;

	env_path = get_env_var(cmd_struct->env, "PATH");
	if (env_path)
	{
		while (env_path[env_count] != 0 && cmd_struct->argv[0][0] != '.'
		&& cmd_struct->argv[0][0] != '/')
		{
			if (checkpath[letter_count] == env_path[env_count])
			{
				letter_count++;
				if (letter_count == 4)
				{
					new_path = _strcat(checkpath, cmd_struct->argv[0]);
					return (new_path);
				}
			}
			else
			{
				letter_count = 0;
			}
			env_count++;
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
