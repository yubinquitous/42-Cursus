#include "libft.h"
#include "../../include/pipex.h"
#include <stdlib.h>

char *ft_strdup(const char *s1)
{
    size_t len;
    size_t i;
    char *ret;

    len = ft_strlen(s1);
    ret = malloc(sizeof(char) * (len + 1));
    if (!ret)
        error_exit("malloc error", 1);
    i = 0;
    while (i < len)
    {
        ret[i] = s1[i];
        ++i;
    }
    ret[i] = '\0';
    return (ret);
}
