#include "../include/pipex.h"
#include <sys/wait.h>

void do_parent(int *pipe_fd, int i)
{
    if (i > 1)
    {
        ft_close(pipe_fd[1]);
        ft_close(pipe_fd[0]);
    }
}