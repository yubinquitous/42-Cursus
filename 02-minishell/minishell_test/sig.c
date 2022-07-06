#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void handler(int signum)
{
    printf("this is sig\n");
    if (signum == SIGINT)
    {
        printf("ctrl + c\n");
    }
    else if (signum == SIGTERM)
    {
        printf("kill\n");
    }
    exit(0);
}

int main(void)
{
    int ret;
    char *line;

    int result1;
    if (signal(SIGINT, handler) == SIG_ERR)
    {
        printf("c error\n");
    }
    if (signal(SIGTERM, handler) == SIG_ERR)
    {
        printf("d error\n");
    }
    int i = 0;
    while (1)
    {
        i++;
    }
    return (0);
}