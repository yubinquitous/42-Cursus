#include "../includes/push_swap.h"
#include "../libft/libft.h"

int count_argv(char *str)
{
    char **temp;
    int cnt;

    temp = ft_split(str, ' ');
    if (!temp)
        error_exit();
    cnt = 0;
    while (temp && *temp) // 확인 필요
    {
        while (*temp && **temp) // 확인 필요
        {
            if (!ft_isdigit(**temp))
                error_exit();
            ++(*temp);
        }
        ++temp;
        ++cnt;
    }
    return cnt;
}

int count_args(int argc, char **argv)
{
    int i;
    int cnt;

    i = 0;
    cnt = 0;
    while (++i < argc)
        cnt += count_argv(argv[i]);
    return cnt;
}

int is_duplicate(int *data, int num, int cnt)
{
    int i;

    i = 0;
    while (++i < cnt)
    {
        if (data[i] == num)
            error_exit();
    }
    return 0;
}