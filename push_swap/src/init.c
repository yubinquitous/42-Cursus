#include "../includes/push_swap.h"
#include "../libft/libft.h"

void init_stack_a(int argc, char **argv, t_stack *a)
{
    int i;
    int j;
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
        while (str[j] && !is_duplicate(a, ft_atoi(str[j]), cnt))
            a->data[cnt++] = ft_atoi(str[j++]);
        free(str);
    }
}

void init_stack(int argc, char **argv, int cnt, t_dual_stack *ds)
{
    t_stack a;
    t_stack b;

    a.data = malloc(sizeof(int) * (cnt));
    b.data = malloc(sizeof(int) * (cnt));
    if (!a.data || !b.data)
        error_exit();
    ft_bzero(a.data, cnt);
    ft_bzero(b.data, cnt);
    init_stack_a(argc, argv, &a);
    printf("cnt : %d\n", cnt); // 왜???
    ds->a = &a;
    ds->b = &b;
    ds->a->head = 0;
    ds->a->tail = cnt - 1;
    ds->b->head = 0;
    ds->b->tail = 0;
    ds->size = cnt;
}
