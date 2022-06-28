#ifndef PIPEX_H
#define PIPEX_H

typedef struct s_arg
{
    char *file;
    char *cmd;
    char *path;
    struct s_arg *next;
} t_arg;

void error_exit(char *msg, int status);

#endif