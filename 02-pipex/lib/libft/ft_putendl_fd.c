#include "libft.h"
#include <unistd.h>

static void ft_putchar_fd(char c, int fd)
{
    if (fd < 0)
        return;
    write(fd, &c, 1);
}

static void ft_putstr_fd(char *s, int fd)
{
    int len;

    if (fd < 0 || !s)
        return;
    len = ft_strlen(s);
    write(fd, s, len);
}

void ft_putendl_fd(char *s, int fd)
{
    if (!s || fd < 0)
        return;
    ft_putstr_fd(s, fd);
    ft_putchar_fd('\n', fd);
}
