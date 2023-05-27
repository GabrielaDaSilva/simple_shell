#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

/* Defines Buffers */
#define SCAN_BUFFER_SIZE 1024
#define RESET_BUFFER -1
#define OUTPUT_BUFFER_SIZE 1024

/* links commands */
#define CHAIN_STD	0
#define CHAIN_OR	1
#define CHAIN_AND	2
#define CHAIN_COMPLEX	3

#define LOWCASE_CHANGE	1
#define UNSIGNED_CHANGE	2

/* Sys getline() */
#define STRTOK_UTILZE 0
#define GETLINE_UTILZE 0

#define FOLDERHIST_MAX	4096
#define FOLDER_HISTORY	".simple_shell_history"

extern char **environ;


/**
 * struct liststr - The linked list
 * @cStr: the str
 * @number: num area
 * @next: directs to following node
 */

typedef struct liststr
{
	char *cStr;
	int number;
	struct liststr *next;
} Log_t;

/**
 * struct takeinfo - arg pass into a function,
 * @calcu_lin: the error count
 * @error_amount: the error code for exit()s
 * @calcLin_flg: if on count this line of input
 * @tagFlg: the program filename
 * @arg: a string generated from getline containing arguments
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @mod_env: on if environ was changed
 * @condition: the return condition of the last exec'd command
 * @buff_command: address of pointer to buff_command, on if chaining
 * @bClass_command: CMD_type ||, &&, ;
 * @scan_fdesc: the fd from which to read line input
 * @logHist: the history line number count
 */
typedef struct takeinfo
{
	char **environ;
	char **argv;
	char *path;
	int argc;
	unsigned int calcu_lin;
	int error_amount;
	int calcLin_flg;
	char *arg;
	char *tagFlg;
	Log_t *env;
	Log_t *history;
	Log_t *alias;
	int mod_env;
	int condition;

	int bClass_command;
	int scan_fdesc;
	int logHist;
	char **buff_command;
} data_t;

#define SET_INF \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - Holds a str and func.
 * @func: func
 * @class: Holds cmd flag
 */
typedef struct builtin
{
	int (*func)(data_t *);
	char *class;
} log_builtin;

void locateCmd(data_t *);
void forkCom(data_t *);
int Shell_loop(data_t *, char **);
int locBuiltin(data_t *);

char *duplicate_str(char *, int, int);
char *search_cmd_path(data_t *, char *, char *);
int check_command(data_t *, char *);

int hsh_cycle(char **);

int filedes_put(char c, int fd);
int puts_descrip(char *string, int fdes);
void str_puts(char *);
int sin_putchar(char);

int len_string(char *);
int comp_string(char *, char *);
char *beginWith(const char *, const char *);
char *cat_string(char *, char *);

char *copy_string(char *, char *);
char *dup_str(const char *);
void strPuts(char *);
int putchar_s(char);

char *string_ncopy(char *, char *, int);
char *string_nop(char *, char *, int);
char *char_string(char *, char);

char **token_string(char *, char *);
char **token2_string(char *, char);

char *init_Memory(char *, char, unsigned int);
int ptr_free(void **);
void mem_free(char **);
void *realloc_mem(void *, unsigned int, unsigned int);

int  inter_Mode(data_t *);
int deli_Meter(char, char *);
int valAlpha(int);
int nAtoi_cust(char *);

int atoi_Error(char *);
void list_Err(data_t *, char *);
void com_del(char *);
int dprint(int, int);
char *num_change(long int, int, int);

int shell_Exit(data_t *);
int ch_dir(data_t *);
int assist_s(data_t *);

int hist_info(data_t *);
int alias_info(data_t *);

ssize_t input_buf(data_t *info, char **buf, size_t *len)
ssize_t gStore(data_t *);
ssize_t read_buf(data_t *info, char *buf, size_t *i)
int lin_Ret(data_t *, char **, size_t *);
void process_sig(int);

void _emptyInf(data_t *);
void _configInf(data_t *, char **);
void _relinf(data_t *, int);

char *ret_env(data_t *, const char *);
int env_cust(data_t *);
int envLs_occ(data_t *);
int config_env(data_t *);
int unstow_env(data_t *);

char **enviro_ret(data_t *);
int env_deact(data_t *, char *);
int env_place(data_t *, char *, char *);

int histWr(data_t *info);
int scan_hist(data_t *info);
int createLs_hist(data_t *info, char *buf, int linecount);
int hist_reassign(data_t *info);
char *retLog_hist(data_t *info);

size_t sPrint_lsString(const Log_t *);
int nodeRem_ind(Log_t **, unsigned int);
Log_t *nodeAffix(Log_t **, const char *, int);
Log_t *affixFin_node(Log_t **, const char *, int);
void ls_release(Log_t **);

size_t sPrint_ls(const Log_t *);
size_t ls_size(const Log_t *);
char **ls_str(Log_t *);
Log_t *begNode_incl(Log_t *, char *, char);
ssize_t retInd_node(Log_t *, Log_t *);

int sub_alias(data_t *);
int sub_vars(data_t *);
int substi_str(char **, char *);
int link_var(data_t *, char *, size_t *);
void assess_link(data_t *, char *, size_t *, size_t, size_t);

#endif
