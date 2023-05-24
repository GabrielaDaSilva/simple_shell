#ifndef _SHELL_H_
#define _SHELL_H_
#define MAXARGS 128

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

/**
 * struct cmd - contains arguments.
 * @argc: amount of args
 * @home: pointer to home
 * @env:  env variables
 * @argv: pointers to args
 * cmd: command
 * Description: The structure for the commands
 */
typedef struct cmd
{
	char *home;
	char **env;
	char *argv[MAXARGS];
	int argc;
} cmd;

/**
 * struct builtins - creates and defines builtins
 * @order: the orders/ instruc.
 * @func: the funct
 * Description: a struct for builtin cmds
 */
typedef struct builtins
{
	char *order;
	void (*func)(cmd *);
} log_Builtin;

void _changedir(cmd *cmd_struct);
void env_cust(cmd *cmd_struct);
void ext_out(cmd *cmd_struct);
void _npars(char *command, char **env, char *home);
void (*is_builtin(char *command))(cmd *cmd_struct);
void result_ev(cmd *cmd_struct);
void _run(struct cmd *cmd_struct, char *new_path);

int comp_string(char *s1, char *s2);
char *env_retrieve_var(char **environ, char *var);
char *validate_variable(char *env_var, char *var);
char *process_path(cmd *cmd_struct, char *checkpath);
char *concat_string(char *dest, char *src);

int file_validate(char *file);
size_t obt_length(char *s);

#endif
