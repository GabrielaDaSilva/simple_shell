#include "shell_header.h"

/**
 * file_checker - checks the file.
 * @the_file: file to be checked.
 * Return: 1 if file found, 0 otherwise
 */

int file_checker(char *the_file)
{
	struct stat st;

	if (stat(the_file, &st) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * get_the_length - get length of string
 * @string: string to be checked.
 * Return: length of string
 */
size_t get_the_length(char *string)
{
	size_t ncount = 0;

	while (string[ncount] != 0)
	{
		ncount++;
	}
	return (ncount);
}
