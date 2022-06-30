#include "../include/pipex.h"
#include <sys/wait.h>

void do_parent(int *pipe_fd, int i)
{
    if (i > 1)
    {
        close_exit(pipe_fd[1]);
        close_exit(pipe_fd[0]);
    }
}