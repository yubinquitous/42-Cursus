#include "../include/pipex.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void execve_exit(char *filename, char **argv, char **envp)
{
    if (execve(filename, argv, envp) == -1)
        error_exit("execve error", 1);
}

void close_exit(int fd)
{
    if (close(fd) == -1)
        error_exit("close failed", 1);
}

void dup2_exit(int fd, int fd2)
{
    if (dup2(fd, fd2) == -1)
        error_exit("dup2 failed", 1);
}

int open_exit(char *filename, int o_flag, int mode)
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
