#include <stdlib.h>
#include <unistd.h>

void error_exit()
{
    write(1, "Error\n", 6);
    exit(1);
}