#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#define _shell_h_
#ifndef _shell_h_
#define write_buf_size 1024
#define read_buf_size 1024
#define buf_flush -1
#define cmd_or	1
#define cmd_and	 2
#define cmd_norm 0
#define cmd_chain 3
#define convert_lowercase 1
#define convert_unsigned 2
#define use_getline 0
#define use_strtok 0
#define hist_file
#define hist_max 4096
extern char **environ;
/**
* struct lstr - singly linked list
* @number: number field
* @str: string
* @nextnode: refers to the next node
*/
typedef struct lstr
{
int number;
char *str;
struct lstr *nextnode;
} l_t;
/**
* struct pi - contains pseudo-arguements to pass into a function
* @arg: string created from getline containing arguements
* @argv:an array of strings created from arg
* @p: string path for the current command
* @argc: argument count
* @l_c: error count
* @e_n: error code for exits
* @lc_f: count this line of input
* @filename: program filename
* @env: linked list local copy of environ
* @environ: custom modified copy of environ from LL env
* @history: the history node
* @alias: the alias node
* @env_ch:if environ was changed
* @st: return status of the last execed command
* @cmd_b: pointer address to cmd_buf
* @cmd_b_t: CMD_type
* @readfd: fd from which to read line input
* @hc: history line number count
*/
typedef struct pi
{
char *arg;
char **argv;
char *p;
int argc;
unsigned int l_c;
int e_n;
int lc_f;
char *filename;
list_t *env;
list_t *history;
list_t *alias;
char **environ;
int env_ch;
int st;
char **cmd_b; 
int cmd_b_t;
int readfd;
int hc;
} i_t;
#define info_init \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \0, 0, 0}
/**
* struct bin - contains a builtin string and related function
* @ty: the builtin command flag
* @fun: the function
*/
typedef struct bin
{
char *ty;
int (*fun)(i_t *);
} bin_t;
int hisham(i_t *, char **);
int f_bin(i_t *);
void f_cmd(i_t *);
void fo_cmd(i_t *);
int i_cmd(i_t *, char *);
char *d_char(char *, int, int);
char *f_p(i_t *, char *, char *);
int loophsh(char **);
void ep(char *);
int epch(char);
int pfd(char c, int fd);
int psfd(char *str, int fd);
int strl(char *);
int strcm(char *, char *);
char *st_w(const char *, const char *);
char *strca(char *, char *);
char *strco(char *, char *);
char *strd(const char *);
void _p(char *);
int _pch(char);
char *strnc(char *, char *, int);
char *strnca(char *, char *, int);
char *strchr(char *, char);
char **strt(char *, char *);
char **strtt(char *, char);
char *mset(char *, char, unsigned int);
void ff(char **);
void *roc(void *, unsigned int, unsigned int);
int bf(void **);
int inter(i_t *);
int i_de(char, char *);
int ialph(int);
int at(char *);
int errat(char *);
void p_err(i_t *, char *);
int p_d(int, int);
char *con_num(long int, int, int);
void re_com(char *);
int mex(i_t *);
int mcd(i_t *);
int mhelp(i_t *);
int mhis(i_t *);
int mal(i_t *);
ssize_t g_in(i_t *);
int gl(i_t *, char **, size_t *);
void sigin(int);
void c_inf(i_t *);
void s_inf(i_t *, char **);
void f_inf(i_t *, int);
char *genv(i_t *, const char *);
int menv(i_t *);
int msenv(i_t *);
int munsenv(i_t *);
int pop_env_l(i_t *);
char **g_environ(i_t *);
int usenv(i_t *, char *);
int senv(i_t *, char *, char *);
char *g_his_f(i_t *in);
int w_his(i_t *in);
int re_his(i_t *in);
int bu_his_l(i_t *in, char *buf, int linecount);
int renum_his(i_t *in);
l_t *ad_no(l_t **, const char *, int);
l_t *ad_no_end(l_t **, const char *, int);
size_t p_l_str(const l_t *);
int d_no_at_in(l_t **, unsigned int);
void f_l(l_t **);
size_t l_l(const l_t *);
char **l_to_str(l_t *);
size_t p_l(const l_t *);
list_t *no_s_w(l_t *, char *, char);
ssize_t g_no_in(l_t *, l_t *);
int i_cha(info_t *, char *, size_t *);
void ch_cha(i_t *, char *, size_t *, size_t, size_t);
int rep_al(i_t *);
int rep_v(i_t *);
int rep_str(char **, char *);
#endif
