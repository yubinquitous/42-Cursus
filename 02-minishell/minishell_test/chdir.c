#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *path;

    path = getcwd(NULL, 0);
    if (!path)
        return (1);
    printf("Before:\t%s\n", path);
    free(path);
    path = NULL;
    if (chdir("../") == -1)
        return (1);
    path = getcwd(NULL, 0);
    if (!path)
        return (1);
    printf("After:\t%s\n", path);
    free(path);
    path = NULL;
    return (0);
}