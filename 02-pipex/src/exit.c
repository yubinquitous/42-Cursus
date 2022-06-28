#include "../include/pipex.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>

void error_exit(char *msg, int status)
{
    ft_putendl_fd(msg, 2);
    exit(status);
}
