#include "../include/pipex.h"
#include <stdlib.h>
#include <stdio.h>

void error_exit(char *msg, int status)
{
    perror(msg);
    exit(status);
}
