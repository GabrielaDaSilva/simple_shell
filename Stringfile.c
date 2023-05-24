#include "Shell.h"

/**
 * comp_string - checks diff between str
 * @s1: pointer str 1
 * @s2: pointer str 2
 * Return: -15 - for s1 > s2, 15 for s2 > s1, 0 for s1 = s2
 */

int comp_string(char *s1, char *s2)
{
	int n = 0, sr = 0;

	while (sr == 0)
	{
		if (!s1[n] && !s2[n])
		{
			break;
		}
		sr = s1[n] - s2[n];
		n++;
	}

	return (sr);
}

/**
 * env_retrieve_var - obtains env var
 * @environ: para for env
 * @var: para for var
 * Return: environment variable
 */

char *env_retrieve_var(char **environ, char *var)
{
	int calculate = 0;
	char *variable_env, *variable_return;

	while ((variable_env = environ[calculate]) != NULL)
	{
		variable_return = validate_variable(variable_env, var);
		if (variable_return)
			return (variable_return);
		calculate++;
	}
	return (NULL);
}

/**
 * validate_variable - Validates enviro var
 * @var: Para for var
 * @env_var: Para enviro var
 * Return: environment variable
 */

char *validate_variable(char *env_var, char *var)
{
	int sWord = 0;

	while (var[sWord] != 0)
	{
		if (env_var[sWord] != var[sWord])
		{
			return (NULL);
		}
		sWord++;
	}
	return (&env_var[sWord + 1]);
}

/**
 * process_path - Processes PATH.
 * @checkpath: name of PATH file
 * @cmd_struct: The cmd Struct
 * Return: no return
 */

char *process_path(cmd *cmd_struct, char *checkpath)
{
	int calculate_env = 0, calculate_word = 0;
	char *nPath, *enPath;

	enPath = env_retrieve_var(cmd_struct->env, "PATH");
	if (enPath)
	{
		while (enPath[calculate_env] != 0 && cmd_struct->argv[0][0] != '.'
		&& cmd_struct->argv[0][0] != '/')
		{
			if (checkpath[calculate_word] == enPath[calculate_env])
			{
				calculate_word++;
				if (calculate_word == 4)
				{
					nPath = concat_string(checkpath, cmd_struct->argv[0]);
					return (nPath);
				}
			}
			else
			{
				calculate_word = 0;
			}
			calculate_env++;
		}
	}
	return (cmd_struct->argv[0]);
}

/**
 * concat_string - Duplicates str
 * @src: str pointer to source
 * @dest: str pointer to destination
 * Return: dest - string pointer to destination
 */

char *concat_string(char *dest, char *src)
{
	int size_destination = 0, size_src = 0;

	while (dest[size_destination] != 0)
	{
		size_destination++;
	}
	while (src[size_src] != 0)
	{
		dest[size_destination] = src[size_src];
		size_destination++;
		size_src++;
	}
	dest[size_destination] = 0;
	return (dest);
}
