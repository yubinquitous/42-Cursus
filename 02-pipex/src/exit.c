#include "../include/pipex.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

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

int open_exit(char *filename, int mode)
{
    int file_fd;

    file_fd = open(filename, mode);
    if (file_fd == -1)
        error_exit("File not found", 1);
    return (file_fd);
}

void error_exit(char *msg, int status)
{
    ft_putendl_fd(msg, 2);
    exit(status);
}
