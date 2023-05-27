#include "shell.h"

/**
 * **token_string - str split in two
 * @ptr: entered str
 * @e: delim str
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **token_string(char *ptr, char *e)
{
	int n, l, c, a, amountwrds = 0;
	char **cs;

	if (ptr == NULL || ptr[0] == 0)
		return (NULL);
	if (!e)
		e = " ";
	for (n = 0; ptr[n] != '\0'; n++)
		if (!deli_Meter(ptr[n], e) && (deli_Meter(ptr[n + 1], e) || !ptr[n + 1]))
			amountwrds++;

	if (amountwrds == 0)
		return (NULL);
	cs = malloc((1 + amountwrds) * sizeof(char *));
	if (!cs)
		return (NULL);
	for (n = 0, l = 0; l < amountwrds; l++)
	{
		while (deli_Meter(ptr[n], e))
			n++;
		c = 0;
		while (!deli_Meter(ptr[n + c], e) && ptr[n + c])
			c++;
		cs[l] = malloc((c + 1) * sizeof(char));
		if (!cs[l])
		{
			for (c = 0; c < l; c++)
				free(cs[c]);
			free(cs);
			return (NULL);
		}
		for (a = 0; a < c; a++)
			cs[l][a] = ptr[n++];
		cs[l][a] = 0;
	}
	cs[l] = NULL;
	return (cs);
}

/**
 * **token2_string - puts str into words
 * @ptr: entered str
 * @r: delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **token2_string(char *ptr, char r)
{
	char **sc;
	int i, l, c, a, amountwrds = 0;

	if (ptr == NULL || ptr[0] == 0)
		return (NULL);
	for (i = 0; ptr[i] != '\0'; i++)
		if ((ptr[i] != r && ptr[i + 1] == r) ||
				    (ptr[i] != r && !ptr[i + 1]) || ptr[i + 1] == r)
			amountwrds++;
	if (amountwrds == 0)
		return (NULL);
	sc = malloc((1 + amountwrds) * sizeof(char *));
	if (!sc)
		return (NULL);
	for (i = 0, l = 0; l < amountwrds; l++)
	{
		while (ptr[i] == r && ptr[i] != r)
			i++;
		c = 0;
		while (ptr[i + c] != r && ptr[i + c] && ptr[i + c] != r)
			c++;
		sc[l] = malloc((c + 1) * sizeof(char));
		if (!sc[l])
		{
			for (c = 0; c < l; c++)
				free(sc[c]);
			free(sc);
			return (NULL);
		}
		for (a = 0; a < c; a++)
			sc[l][a] = ptr[i++];
		sc[l][a] = 0;
	}
	sc[l] = NULL;
	return (sc);
}
