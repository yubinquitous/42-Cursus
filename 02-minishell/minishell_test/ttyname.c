#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void censor(int fd, const char *s)
{
    if (isatty(fd))
    {
        if (s)
            printf("%s is referring to a terminal\n", s);
        else
            printf("File Descriptor %d is referring to a terminal\n", fd);
    }
    else
    {
        if (s)
            printf("%s is not referring to a terminal\n", s);
        else
            printf("File Descriptor %d is not referring to a terminal\n", fd);
    }
    printf("TTYNAME:\t%s\n", ttyname(fd));
}

int main(void)
{
    int fd;

    fd = open("a.out", O_RDONLY);
    if (fd < 0)
        return (1);
    censor(STDIN_FILENO, "STDIN");
    censor(STDOUT_FILENO, "STDOUT");
    censor(STDERR_FILENO, "STDERR");
    censor(fd, NULL);
    censor(42, NULL);
    close(fd);
    return (0);
}