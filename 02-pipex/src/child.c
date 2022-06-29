#include "../include/pipex.h"
#include <unistd.h>
#include <fcntl.h>

void open_and_close(t_arg arg, int *pipe_fd, int i)
{
    int file_fd;

    if (i == 1)
    {
        close_exit(pipe_fd[0]);
        file_fd = open_exit(arg.file, O_RDONLY);
        dup2_exit(pipe_fd[1], 1);
        close_exit(pipe_fd[1]);
        dup2_exit(file_fd, 0);
        close(file_fd);
    }
    else
    {
        close_exit(pipe_fd[1]);
        file_fd = open_exit(arg.file, O_WRONLY);
        dup2_exit(pipe_fd[0], 0);
        close_exit(pipe_fd[0]);
        dup2_exit(file_fd, 1);
        close(file_fd);
    }
}

void do_command1(t_arg arg)
{
    // execve(arg.file, arg.cmd, arg.path);
}

void do_child1(t_arg arg, int *pipe_fd, int i)
{
    open_and_close(arg, pipe_fd, i);
    do_command1(arg);
}

void do_child(t_arg arg, int *pipe_fd, int i)
{
    // if (i == 1)
    //     do_child1(arg, pipe_fd, i);
    // else
    //     do_child2();
}