#include "shell.h"
/**
* inter - returns true if shell is interactive mode
* @in: struct address
* Return: 1 if inter mode, 0 otherwise
*/
int inter(id_t *in)
{
return (isatty(STDIN_FILENO) && in->readfd <= 2);
}
/**
* i_de - checks if character is a delimeter
* @ch: char to check
* @d:  delimeter string
* Return: 1 if true, 0 if false
*/
int i_de(char ch, char *d)
{
while (*d)
if (*d++ == ch)
return (1);
return (0);
}
/**
* ialph - check  alphabetic character
* @ci:  character to input
* Return: 1 if ci is alphabetic, 0 otherwise
*/
int ialph(int ci)
{
if ((ci >= 'a' && ci <= 'z') || (ci >= 'A' && ci <= 'Z'))
return (1);
else
return (0);
}
/**
* at - convert a string to an integer
* @str: the string to be converted
* Return: 0 if no number in string,
* converte number otherwise
*/
int at(char *str)
{
int x, sig = 1, f = 0, op;
int r = 0;
for (x = 0; str[x] != '\0' && f != 2; x++)
{
if (str[x] == '-')
sig *= -1;
if (str[x] >= '0' && str[x] <= '9')
{
f = 1;
r *= 10;
r += (str[x] - '0');
}
else if (f == 1)
f = 2;
}
if (sig == -1)
op = -r;
else
op = r;
return (op);
}
