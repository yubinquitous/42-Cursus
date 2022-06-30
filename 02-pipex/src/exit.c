#include "../include/pipex.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void ft_execve(char *filename, char **argv, char **envp)
{
    if (!filename)
        error_exit("Command not found", 127);
    if (execve(filename, argv, envp) == -1)
        error_exit("execve failed", 1);
}

void ft_close(int fd)
{
    if (close(fd) == -1)
        error_exit("close failed", 1);
}

void ft_dup2(int fd, int fd2)
{
    if (dup2(fd, fd2) == -1)
        error_exit("dup2 failed", 1);
}

int ft_open(char *filename, int o_flag, int mode)
{
    int file_fd;

    if (mode == -1)
        file_fd = open(filename, o_flag);
    else
        file_fd = open(filename, o_flag, mode);
    if (file_fd == -1)
        error_exit("No such file or directory", 1);
    return (file_fd);
}

void error_exit(char *msg, int status)
{
    perror(msg);
    exit(status);
}
