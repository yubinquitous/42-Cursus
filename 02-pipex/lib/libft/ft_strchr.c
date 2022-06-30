#include "libft.h"

char *ft_strchr(char *s, int c)
{
    if (!s)
        return (0);
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        ++s;
    }
    if (*s == (char)c)
        return ((char *)s);
    return (0);
}