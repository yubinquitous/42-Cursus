#ifndef PIPEX_H
#define PIPEX_H

typedef struct s_arg
{
    char *file;
    // char *cmd;
    char **option;
    char *path;
    struct s_arg *next;
} t_arg;

void error_exit(char *msg, int status);
void ft_close(int fd);
void ft_dup2(int fd, int fd2);
int ft_open(char *filename, int mode, int access);
void ft_execve(char *filename, char **argv, char **envp);
void do_child(t_arg arg, int *pipe_fd, int i);
void do_parent(int *pipe_fd, int i);

#endif