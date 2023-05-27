#include "shell.h"

/**
 * input_buf - linked commands buffers
 * @len: len address
 * @info: struct containing info
 * @buf: location of buffer
 * Return: bytes read
 */

ssize_t input_buf(data_t *info, char **buf, size_t *len)
{
	ssize_t n = 0;
	size_t size_n = 0;

	if (!*len)
	{
		/*ptr_free((void **)info->buff_command);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, process_sig);
#if GETLINE_UTILZE
		n = getline(buf, &size_n, stdin);
#else
		n = lin_Ret(info, buf, &size_n);
#endif
		if (n > 0)
		{
			if ((*buf)[n - 1] == '\n')
			{
				(*buf)[n - 1] = '\0';
				n--;
			}
			info->calcLin_flg = 1;
			com_del(*buf);
			createLs_hist(info, *buf, info->logHist++);

			{
				*len = n;
				info->buff_command = buf;
			}
		}
	}
	return (n);
}

/**
 * gStore - obtains a line
 * @data: struct containing info
 * Return: bytes read
 */

ssize_t gStore(data_t *data)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t n = 0;
	char **buf_p = &(data->arg), *p;

	putchar_s(RESET_BUFFER);
	n = input_buf(data, &buf, &len);
	if (n == -1) /* End Of File */
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		assess_link(data, buf, &j, i, len);
		while (j < len)
		{
			if (link_var(data, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0; /* Pos. and size reset */
			data->bClass_command = CHAIN_STD;
		}

		*buf_p = p;
		return (len_string(p));
	}

	*buf_p = buf;
	return (n);
}

/**
 * read_buf - buf will be read
 * @i: len
 * @info: para with info
 * @buf: the buffer
 * Return: n
 */

ssize_t read_buf(data_t *info, char *buf, size_t *i)
{
	ssize_t n = 0;

	if (*i)
		return (0);
	n = read(info->scan_fdesc, buf, SCAN_BUFFER_SIZE);
	if (n >= 0)
		*i = n;
	return (n);
}

/**
 * lin_Ret - Fetch next line from stdin
 * @data: struct containing info
 * @lptr: pointer to buffer
 * @size: size of lptr buf
 * Return: a
 */

int lin_Ret(data_t *data, char **lptr, size_t *size)
{
	static char buf[SCAN_BUFFER_SIZE];
	static size_t i, len;
	size_t j;
	ssize_t n = 0, a = 0;
	char *e = NULL, *new_p = NULL, *c;

	e = *lptr;
	if (p && size)
		a = *size;
	if (i == len)
		i = len = 0;

	n = read_buf(data, buf, &len);
	if (n == -1 || (n == 0 && len == 0))
		return (-1);

	c = char_string(buf + i, '\n');
	j = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = realloc_mem(e, a, a ? a + j : j + 1);
	if (!new_e) /* MALLOC FAILURE! */
		return (e ? free(e), -1 : -1);

	if (a)
		string_nop(new_p, buf + i, j - i);
	else
		string_ncopy(new_p, buf + i, j - i + 1);

	a += j - i;
	i = j;
	e = new_p;

	if (size)
		*size = a;
	*lptr = e;
	return (a);
}

/**
 * process_sig - the blocker for ctrl -c
 * @val_signal: the signal number
 *
 * Return: void
 */
void process_sig(__attribute__((unused))int val_signal)
{
	strPuts("\n");
	strPuts("$ ");
	putchar_s(RESET_BUFFER);
}
