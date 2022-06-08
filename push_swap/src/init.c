#include "../includes/push_swap.h"
#include "../libft/libft.h"

t_stack init_stack_a(int argc, char **argv, int size)
{
    int i;
    int j;
    int cnt;
    char **str;
    t_stack a;

    i = 0;
    cnt = 0;
    a.data = (int *)malloc(sizeof(int) * size);
    while (++i < argc)
    {
        j = 0;
        str = ft_split(argv[i], ' ');
        if (!str)
            error_exit();
        while (str[j] && !is_duplicate(a, ft_atoi(str[j]), cnt))
        {
            a.data[cnt] = ft_atoi(str[j]);
            ++cnt;
            ++j;
        }
        free(str);
        str = 0;
    }
    a.head = 0;
    a.tail = cnt - 1;
    return (a);
}

t_stack init_stack_b(int size)
{
    t_stack b;

    b.data = (int *)malloc(sizeof(int) * size);
    b.head = 0;
    b.tail = 0;
    return (b);
}

void init_stack(int argc, char **argv, int size, t_dual_stack *ds)
{

    ds->a = init_stack_a(argc, argv, size);
    ds->b = init_stack_b(size);
    ds->size = size;
    // printf("init_stack head : %d\n", ds->a.head);
    // printf("init_stack tail : %d\n", ds->a.tail);
}
