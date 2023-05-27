#include "shell.h"

/**
 * main - entry point
 * @av: arg vector
 * @ac: count arg
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **av)
{
	int fileD = 2;
	data_t info[] = { SET_INF };

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fileD)
			: "r" (fileD));

	if (ac == 2)
	{
		fileD = open(av[1], O_RDONLY);
		if (fileD == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				str_puts(av[0]);
				str_puts(": 0: Cannot open ");
				str_puts(av[1]);
				sin_putchar('\n');
				sin_putchar(RESET_BUFFER);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->scan_fdesc = fileD;
	}
	envLs_occ(info);
	scan_hist(info);
	Shell_loop(info, av);
	return (EXIT_SUCCESS);
}
