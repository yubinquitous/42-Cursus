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

void bubble_sort(int *data, int size)
{
    int i;
    int j;
    int temp;

    i = size;
    while (--i > 0)
    {
        j = -1;
        while (++j < i)
        {
            if (data[j] > data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int *data_cpy(int *data, int size)
{
    int i;
    int *ret;

    i = -1;
    ret = (int *)malloc(sizeof(int) * size);
    if (!ret)
        error_exit();
    while (++i < size)
        ret[i] = data[i];
    return (ret);
}

void init_pivot(t_dual_stack *ds)
{
    int *sorted_data;

    sorted_data = data_cpy(ds->a.data, ds->a.size);
    bubble_sort(sorted_data, ds->a.size);
    // test(ds->size, sorted_data);
    ds->pivot_small = sorted_data[ds->a.size / 3];
    ds->pivot_large = sorted_data[ds->a.size * 2 / 3];
}

void init_stack(int argc, char **argv, int size, t_dual_stack *ds)
{

    ds->a = init_stack_a(argc, argv, size);
    ds->b = init_stack_b(size);
    ds->a.size = size;
    ds->b.size = size;
    init_pivot(ds);
}
