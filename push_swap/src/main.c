#include "../includes/push_swap.h"
#include "../libft/libft.h"

// void print_str(char **str)
// {
//     while (*str)
//     {
//         printf("%s\n", *str);
//         ++str;
//     }
// }
int count_argv(char *str)
{
    char **temp;
    char *num;
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

void count_args(int argc, char **argv, int *cnt)
{
    int i;
    char **str;

    i = 0;
    *cnt = 0;
    while (++i < argc)
        *cnt += count_argv(argv[i]);
}

void init_stack_a(int argc, char **argv, t_stack *a)
{
    int i;
    int j;
    int num;
    int cnt;
    char **str;

    i = 0;
    cnt = 0;
    while (++i < argc)
    {
        j = 0;
        str = ft_split(argv[i], ' ');
        if (!str)
            error_exit();
        // printf("str[0] : %s\n", str[0]);
        while (str[j])
        {
            // printf("str[%d] : %s\n", j, str[j]);
            // printf("%d\n", ft_atoi(str[j]));
            a->data[cnt++] = ft_atoi(str[j++]);
        }
        free(str);
    }
    a->data[cnt] = 0;
}

void init_stack(int argc, char **argv, int cnt, t_dual_stack *ds)
{
    t_stack a;
    t_stack b;

    a.data = malloc(sizeof(int) * (cnt + 1));
    b.data = malloc(sizeof(int) * (cnt + 1));
    if (!a.data || !b.data)
        error_exit();
    init_stack_a(argc, argv, &a);
    a.head = 0;
    a.tail = cnt - 1;
    b.head = 0;
    b.tail = 0;
    ds->a = &a;
    ds->b = &b;
    ds->size = cnt;
}

void test(t_dual_stack ds)
{
    int i = 0;
    while (ds.a->data[i])
    {
        printf("%d\n", ds.a->data[i++]);
    }
}

int main(int argc, char **argv)
{
    t_dual_stack ds;
    int cnt;

    if (argc < 2)
        error_exit();
    count_args(argc, argv, &cnt);
    // printf("cnt : %d\n", cnt); // test
    init_stack(argc, argv, cnt, &ds);
    // test(ds); // test
    return (0);
}