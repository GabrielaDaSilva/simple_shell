#include "shell_header.h"

/**
* check_file – checks the file.
* @file: file to be checked.
* Return: 1 if file found, 0 otherwise
*/

int check_file(char *file)
{
	struct stat st;

	if (stat(file, &st) == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
* get_len – get length of string
* @s: string to be checked.
* Return: length of string
*/

size_t get_len(char *s)
{
	size_t count = 0;

	while (s[count] != 0)
	{
		count++;
	}
	return (count);
}
