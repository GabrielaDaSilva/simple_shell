#include "shell.h"

/**
 * retLog_hist - obtains history file
 * @info: struct with info
 * Return: allocated string containg history file
 */

char *retLog_hist(data_t *info)
{
	char *b, *d;

	d = ret_env(info, "HOME=");
	if (!d)
		return (NULL);
	b = malloc(sizeof(char) * (len_string(d) + len_string(FOLDER_HISTORY) + 2));
	if (!b)
		return (NULL);
	b[0] = 0;
	copy_string(b, d);
	cat_string(b, "/");
	cat_string(b, FOLDER_HISTORY);
	return (b);
}

/**
 * histWr - makes a file
 * @info: The struct
 * Return: 1 on success, else -1
 */

int histWr(data_t *info)
{
	ssize_t fileD;
	char *fil_name = retLog_hist(info);
	Log_t *node = NULL;

	if (!fil_name)
		return (-1);

	fileD = open(fil_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fil_name);
	if (fileD == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		puts_descrip(node->cStr, fileD);
		filedes_put('\n', fileD);
	}
	filedes_put(RESET_BUFFER, fileD);
	close(fileD);
	return (1);
}

/**
 * scan_hist - scans hist
 * @info: contains info
 * Return: logHist on success, 0 otherwise
 */

int scan_hist(data_t *info)
{
	int n, endL = 0, calLine = 0;
	ssize_t fd, scan_len, fsize = 0;
	struct stat st;
	char *scanBuf = NULL, *filename = retLog_hist(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	scanBuf = malloc(sizeof(char) * (fsize + 1));
	if (!scanBuf)
		return (0);
	scan_len = read(fd, scanBuf, fsize);
	scanBuf[fsize] = 0;
	if (scan_len <= 0)
		return (free(scanBuf), 0);
	close(fd);
	for (n = 0; n < fsize; n++)
		if (scanBuf[n] == '\n')
		{
			scanBuf[n] = 0;
			createLs_hist(info, scanBuf + endL, calLine++);
			endL = n + 1;
		}
	if (endL != n)
		createLs_hist(info, scanBuf + endL, calLine++);
	free(scanBuf);
	info->logHist = calLine;
	while (info->logHist-- >= FOLDERHIST_MAX)
		nodeRem_ind(&(info->history), 0);
	hist_reassign(info);
	return (info->logHist);
}

/**
 * createLs_hist - space made for hist in list
 * @info: holds info
 * @buf: buffer
 * @linecount: the history linecount, logHist
 *
 * Return: Always 0
 */
int createLs_hist(data_t *info, char *buf, int linecount)
{
	Log_t *clNode = NULL;

	if (info->history)
		clNode = info->history;
	affixFin_clNode(&clNode, buf, linecount);

	if (!info->history)
		info->history = clNode;
	return (0);
}

/**
 * hist_reassign - reassigns numbers
 * @info: contains info
 * Return: the new logHist
 */

int hist_reassign(data_t *info)
{
	Log_t *haNode = info->history;
	int n = 0;

	while (haNode)
	{
		haNode->number = n++;
		haNode = haNode->next;
	}
	return (info->logHist = n);
}
