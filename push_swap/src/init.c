#include "../includes/push_swap.h"
#include "../libft/libft.h"

int *init_stack_a_data(int argc, char **argv, int size)
{
    int i;
    int j;
    int cnt;
    char **str;
    int *data;

    i = 0;
    cnt = 1;
    data = (int *)malloc(sizeof(int) * (size + 1));
    if (!data)
        error_exit();
    data[0] = 0;
    while (++i < argc)
    {
        j = 0;
        str = ft_split(argv[i], ' ');
        if (!str)
            error_exit();
        while (str[j] && !is_duplicate(data, ft_atoi(str[j]), cnt))
            data[cnt++] = ft_atoi(str[j++]);
        free(str);
        str = 0;
    }
    return (data);
}

t_stack init_stack_a(int argc, char **argv, int size)
{

    t_stack a;

    a.data = init_stack_a_data(argc, argv, size);
    a.head = 0;
    a.tail = size;
    a.size = size;
    return (a);
}

t_stack init_stack_b(int size)
{
    int i;
    t_stack b;

    i = -1;
    b.data = (int *)malloc(sizeof(int) * (size + 1));
    if (!b.data)
        error_exit();
    while (++i < size + 1)
        b.data[i] = 0;
    b.head = size;
    b.tail = size;
    b.size = size;
    return (b);
}

void bubble_sort(int *data, int size)
{
    int i;
    int j;
    int temp;

    i = size + 1;
    while (--i > 0)
    {
        j = 0;
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

    i = 0;
    ret = (int *)malloc(sizeof(int) * (size + 1));
    if (!ret)
        error_exit();
    ret[0] = -2147483648;
    while (++i < size + 1)
        ret[i] = data[i];
    return (ret);
}

void init_pivot(t_dual_stack *ds)
{
    int *sorted_data;

    sorted_data = data_cpy(ds->a.data, ds->a.size);
    bubble_sort(sorted_data, ds->a.size);
    ds->pivot_small = sorted_data[ds->a.size / 3 + 1];
    ds->pivot_large = sorted_data[ds->a.size * 2 / 3 + 1];
    // printf("ps : %d, pl : %d\n", ds->pivot_small, ds->pivot_large);
}

void init_stack(int argc, char **argv, int size, t_dual_stack *ds)
{
    ds->a = init_stack_a(argc, argv, size);
    ds->b = init_stack_b(size);
    test(ds->a);
    init_pivot(ds);
    ds->size = size;
}