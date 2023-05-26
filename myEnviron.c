#include "shell.h"

/**
 * env_cust - Env will be printed
 * @data: Struct for info
 * Return: Always 0
 */

int env_cust(data_t *data)
{
	sPrint_lsString(data->env);
	return (0);
}

/**
 * ret_env - obtains value of env var
 * @name: env var name
 * @data: Holds arg
 * Return: the value
 */
char *ret_env(data_t *data, const char *name)
{
	Log_t *node = data->env;
	char *re;

	while (node)
	{
		re = beginWith(node->cStr, name);
		if (re && *re)
			return (re);
		node = node->next;
	}
	return (NULL);
}

/**
 * config_env - sets new env var
 * @data: Struct with arg
 *  Return: Always 0
 */

int config_env(data_t *data)
{
	if (data->argc != 3)
	{
		str_puts("Wrong number of arguments\n");
		return (1);
	}
	if (env_place(data, data->argv[1], data->argv[2]))
		return (0);
	return (1);
}

/**
 * unstow_env - delete env var
 * @data: Struct with arg
 * Return: Always 0
 */

int unstow_env(data_t *data)
{
	int n;

	if (data->argc == 1)
	{
		str_puts("Too less arguments.\n");
		return (1);
	}
	for (n = 1; n <= data->argc; n++)
		env_deact(data, data->argv[n]);

	return (0);
}

/**
 * envLs_occ - occupies env list
 * @data: Struct with arg
 * Return: Always 0
 */

int envLs_occ(data_t *data)
{
	Log_t *node = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		affixFin_node(&node, environ[j], 0);
	data->env = node;
	return (0);
}
