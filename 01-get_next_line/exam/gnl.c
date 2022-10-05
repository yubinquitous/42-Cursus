#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

int ft_strlen(char *str)
{
    int i;

    i = 0;
    // if (!str)
    //     return (0);
    while (str[i])
        ++i;
    return (i);
}

char *ft_strdup(char *str)
{
    char *ret;
    int len;
    int i;

    len = ft_strlen(str);
    ret = malloc(len + 1);
    i = -1;
    while (str[++i])
    {
        ret[i] = str[i];
    }
    ret[i] = 0;
    return (ret);
}

char *get_next_line(int fd)
{
    char buf[1000000];
    char c;
    int i;
    int read_size;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    i = 0;
    read_size = read(fd, &c, 1);
    while (read_size > 0)
    {
        buf[i++] = c;
        if (c == '\n')
            break;
        read_size = read(fd, &c, 1);
    }
    buf[i] = 0;
    if (read_size <= 0 && i <= 0)
        return (0);
    return (ft_strdup(buf));
}

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
    line = get_next_line(fd);
    printf("%s", line);
    return (0);
}