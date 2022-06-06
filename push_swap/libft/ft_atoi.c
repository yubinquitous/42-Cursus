#include "libft.h"

static int is_space(char c)
{
    if (c == '\t' || c == '\f' || c == '\n' || c == '\r' || c == '\v' || c == ' ')
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    int i;
    long sign;
    long result;

    i = 0;
    while (is_space(str[i]))
        i++;
    sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    result = 0;
    while (ft_isdigit(str[i]))
        result = (result * 10) + (str[i++] - '0');
    if (result < 0)
        return ((sign + 1) / -2);
    return (result * sign);
}