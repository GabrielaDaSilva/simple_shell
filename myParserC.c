#include "shell.h"

/**
 * check_command - checks if exe.
 * @data: struct with info
 * @path: direction to file
 * Return: 1 if true, 0 otherwise
 */

int check_command(data_t *data, char *path)
{
	struct stat st;

	(void)data;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * duplicate_str - duplicates characters
 * @pathstr: the PATH string
 * @begin: starting index
 * @end: stopping index
 * Return: pointer to new buffer
 */

char *duplicate_str(char *pathstr, int begin, int end)
{
	static char buf[1024];
	int s = 0, n = 0;

	for (n = 0, s = begin; s < end; s++)
		if (pathstr[s] != ':')
			buf[n++] = pathstr[s];
	buf[n] = 0;
	return (buf);
}

/**
 * search_cmd_path - locates specific cmd
 * @pathstr: the PATH string
 * @command: cmd looking for
 * @data: holds info
 * Return: full path of cmd if found or NULL
 */

char *search_cmd_path(data_t *data, char *pathstr, char *command)
{
	int posiCurr = 0, s = 0;
	char *jpath;

	if (!pathstr)
		return (NULL);
	if ((len_string(command) > 2) && beginWith(command, "./"))
	{
		if (check_command(data, command))
			return (command);
	}
	while (1)
	{
		if (!pathstr[s] || pathstr[s] == ':')
		{
			jpath = duplicate_str(pathstr, s, s);
			if (!*jpath)
				cat_string(jpath, command);
			else
			{
				cat_string(jpath, "/");
				cat_string(jpath, command);
			}
			if (check_command(data, jpath))
				return (jpath);
			if (!pathstr[s])
				break;
			posiCurr = s;
		}
		s++;
	}
	return (NULL);
}
