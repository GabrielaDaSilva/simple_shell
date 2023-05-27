#include "shell.h"

/**
 * link_var - test delim
 * @buffer: char buf
 * @p: current location add
 * @data: para for info struct
 * Return: 1 if chain delimeter, 0 otherwise
 */

int link_var(data_t *data, char *buffer, size_t *p)
{
	size_t n = *p;

	if (buffer[n] == '|' && buffer[n + 1] == '|')
	{
		buffer[n] = 0;
		n++;
		data->bClass_command = CHAIN_OR;
	}
	else if (buffer[n] == '&' && buffer[n + 1] == '&')
	{
		buffer[n] = 0;
		n++;
		data->bClass_command = CHAIN_AND;
	}
	else if (buffer[n] == ';') /* found end of this command */
	{
		buffer[n] = 0; /* replace semicolon with null */
		data->bClass_command = CHAIN_COMPLEX;
	}
	else
		return (0);
	*p = n;
	return (1);
}

/**
 * assess_link - check status to stop chaining
 * @data: struct with info
 * @buffer: Char buffer
 * @p: current pos in buf
 * @i: starting position in buf
 * @len: length of buf
 * Return: Void
 */

void assess_link(data_t *data, char *buffer, size_t *p, size_t i, size_t len)
{
	size_t n = *p;

	if (data->bClass_command == CHAIN_AND)
	{
		if (data->condition)
		{
			buffer[i] = 0;
			n = len;
		}
	}
	if (data->bClass_command == CHAIN_OR)
	{
		if (!data->condition)
		{
			buffer[i] = 0;
			n = len;
		}
	}

	*p = n;
}

/**
 * sub_alias - substitutes alias in token
 * @data: the parameter info
 * Return: 1 if replaced, 0 otherwise
 */

int sub_alias(data_t *data)
{
	int n;
	Log_t *node_sub;
	char *sp;

	for (n = 0; n < 10; n++)
	{
		node_sub = begNode_incl(data->alias, data->argv[0], '=');
		if (!node_sub)
			return (0);
		free(data->argv[0]);
		sp = char_string(node_sub->cStr, '=');
		if (!sp)
			return (0);
		sp = duplicate_str(sp + 1);
		if (!sp)
			return (0);
		data->argv[0] = sp;
	}
	return (1);
}

/**
 * sub_vars - substitutes vars in tok str
 * @data: the struct info
 * Return: 1 if replaced, 0 otherwise
 */

int sub_vars(data_t *data)
{
	int n = 0;
	Log_t *node_vars;

	for (n = 0; data->argv[n]; n++)
	{
		if (data->argv[n][0] != '$' || !data->argv[n][1])
			continue;

		if (!comp_string(data->argv[n], "$?"))
		{
			substi_str(&(data->argv[n]),
					duplicate_str(num_change(data->condition, 10, 0)));
			continue;
		}
		if (!comp_string(data->argv[n], "$$"))
		{
			substi_str(&(data->argv[n]),
					duplicate_str(num_change(getpid(), 10, 0)));
			continue;
		}
		node_vars = begNode_incl(data->env, &data->argv[n][1], '=');
		if (node_vars)
		{
			substi_str(&(data->argv[n]),
					duplicate_str(char_string(node_vars->cStr, '=') + 1));
			continue;
		}
		substi_str(&data->argv[n], duplicate_str(""));

	}
	return (0);
}

/**
 * substi_str - str replaced
 * @extinct: old str location
 * @fresh: new str
 * Return: 1 if replaced, 0 otherwise
 */

int substi_str(char **extinct, char *fresh)
{
	free(*extinct);
	*extinct = fresh;
	return (1);
}
