#include "Shell.h"

/**
 * file_validate - Validates file.
 * @file: that will be checked.
 * Return: 0 if not found, 1 if found
 */

int file_validate(char *file)
{
	struct stat file_stats;

	if (stat(file, &file_stats) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * obt_length - obtain len of str
 * @s: str to validate.
 * Return: The string length
 */
size_t obt_length(char *s)
{
	size_t calculate = 0;

	while (s[calculate] != 0)
	{
		calculate++;
	}
	return (calculate);
}

