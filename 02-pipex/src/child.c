#include "../include/pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void do_child1(t_arg arg, int *pipe_fd)
{
    int file_fd;

    close_exit(pipe_fd[0]);
    file_fd = open_exit(arg.file, O_RDONLY, -1);
    dup2_exit(file_fd, 0);
    dup2_exit(pipe_fd[1], 1);
    if (execve(arg.path, arg.option, NULL) == -1)
    {
        close_exit(pipe_fd[1]);
        close_exit(file_fd);
        exit(1);
    }
}

void do_child2(t_arg arg, int *pipe_fd)
{
    int file_fd;

    close_exit(pipe_fd[1]);
    file_fd = open_exit(arg.file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    dup2_exit(file_fd, 1);
    dup2_exit(pipe_fd[0], 0);
    execve_exit(arg.path, arg.option, NULL);
    close_exit(pipe_fd[0]);
    close_exit(file_fd);
}

void do_child(t_arg arg, int *pipe_fd, int i)
{
    if (i == 1)
        do_child1(arg, pipe_fd);
    else
        do_child2(arg, pipe_fd);
    exit(0);
}