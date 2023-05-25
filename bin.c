#include "shell.h"
/**
* mex - exits the shell
* @in: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: exits with a given exit status
* (0) if in.argv[0] != "exit"
*/
int mex(id_t *in)
{
int ech;
if (in->argv[1])
{
ech = errat(in->argv[1]);
if (ech == -1)
{
in->st = 2;
p_err(in, "Illegal number: ");
ep(in->argv[1]);
epch('\n');
return (1);
}
in->e_n = errat(in->argv[1]);
return (-2);
}
in->e_n = -1;
return (-2);
}
/**
* mcd - changes the current directory of the process
* @in: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: Always 0
*/
int mcd(id_t *in)
{
char *x, *di, buf[1024];
int chd_r;
x = getcwd(buffer, 1024);
if (!x)
_p("TODO: >>getcwd failure emsg here<<\n");
if (!in->argv[1])
{
di = genv(in, "HOME=");
if (!di)
chd_r = chdir((di = genv(in, "PWD=")) ? di : "/");
else
chd_r = chdir(di);
}
else if (strcm(in->argv[1], "-") == 0)
{
if (!genv(info, "OLDPWD="))
{
_p(x);
_pch('\n');
return (1);
}
_p(genv(in, "OLDPWD=")), pch('\n');
chd_r = chdir((di = genv(in, "OLDPWD=")) ? di : "/");
}
else
chd_r = chdir(in->argv[1]);
if (chd_r == -1)
{
p_err(in, "can't cd to ");
ep(in->argv[1]), epch('\n');
}
else
{
senv(in, "OLDPWD", genv(in, "PWD="));
senv(in, "PWD", getcwd(buf, 1024));
}
return (0);
}
/**
* mhelp - changes the current directory of the process
* @in: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: Always 0
*/
int mhelp(id_t *in)
{
char **arg_array;
arg_array = in->argv;
_p("help call works. Function not yet implemented \n");
if (0)
_p(*arg_array); /* temp att_unused workaround */
return (0);
}
