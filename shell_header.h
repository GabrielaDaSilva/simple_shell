#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H
#define MAXARGS 128

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

/**
 * struct command - holds all arguments and is most important.
 * command: command.
 * @home: home.
 * @argc: number of args
 * @argv: array of pointers to args
 * @env: array of pointers to env vars
 * Description: structure for commands.
 */
typedef struct command
{
	int argc;
	char *argv[MAXARGS];
	char **env;
	char *home;
} cmd;

/**
 * struct built_ins - defines what our builtin functions
 * @instruction: instructions
 * @func: function.
 * Descriiption: structure or builtin commands.
 */
typedef struct built_ins
{
	char *instruction;
	void (*func)(command *);
} builtins_table;

void parse_func(char *a_command, char **env, char *home);
void execute_func(struct command *cmd_struct, char *new_path);
void (*is_builtin(char *a_command))(command *cmd_struct);
void cd_func(command *cmd_struct);
void exit_func(command *cmd_struct);
void env_func(command *cmd_struct);
void eval_func(command *cmd_struct);

/* String functions that we can write to assist us */
int _strcmp(char *string1, char *string2);
char *get_env_variable(char **environment, char *variable)
char *check_variable(char *env_variable, char *variable);
char *path_handle(command *command_struct, char *pathcheck);
char *_strcat(char *dest, char *src);

/* Helpers */
int file_check(char *file);
size_t get_len(char *s);

#endif
