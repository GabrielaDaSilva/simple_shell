#include "shell.h"

/**
 * str_puts - writes an input string
 * @string: to be written
 * Return: Nothing
 */

void str_puts(char *string)
{
	int s = 0;

	if (!string)
		return;
	while (string[s] != '\0')
	{
		sin_putchar(string[s]);
		s++;
	}
}

/**
 * sin_putchar - writes the character c to stderr
 * @s: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int sin_putchar(char s)
{
	static int n;
	static char buf[OUTPUT_BUFFER_SIZE];

	if (s == RESET_BUFFER || n >= OUTPUT_BUFFER_SIZE)
	{
		write(2, buf, n);
		n = 0;
	}
	if (s != RESET_BUFFER)
		buf[n++] = s;
	return (1);
}

/**
 * filedes_put - prints char to file descriptor
 * @fd: filedescriptor 
 * @c: The char
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int filedes_put(char c, int fd)
{
	static int f;
	static char buf[OUTPUT_BUFFER_SIZE];

	if (c == RESET_BUFFER || f >= OUTPUT_BUFFER_SIZE)
	{
		write(fd, buf, f);
		f = 0;
	}
	if (c != RESET_BUFFER)
		buf[f++] = c;
	return (1);
}

/**
 * puts_descrip - writes input string
 * @string: str to be written
 * @fdes: filedescriptor to write to
 * Return: the number of chars put
 */

int puts_descrip(char *string, int fdes)
{
	int n = 0;

	if (!string)
		return (0);
	while (*string)
	{
		n += filedes_put(*string++, fdes);
	}
	return (n);
}
