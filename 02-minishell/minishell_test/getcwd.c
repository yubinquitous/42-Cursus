#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *path;

    path = getcwd(NULL, 0);
    if (!path)
        return (1);
    printf("%s\n", path);
    free(path);
    path = NULL;
    return (0);
}